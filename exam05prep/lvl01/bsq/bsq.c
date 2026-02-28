#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct info {
    int line;
    int width;
    char empty;
    char obstacle;
    char full;
    char** map;
} Map;

int ft_strlen(char *s) {
    int count = 0;
    while (s[count])
        count++;
    
    return count;
}

int dp_min(int a, int b, int c) {
    int min = a;

    if (b < min) 
        min = b;
    if (c < min)
        min = c;

    return min;
}

int execute_bsq(FILE* file, Map* map) {
   char *header = NULL;
   size_t hbuf = 0;
   int hlen = getline(&header, &hbuf, file);
   if (hlen == -1 || header[hlen - 1] != '\n')
    {
        free(header);
        return (-1);
    }

    map->line = 0;
    map->empty = header[hlen - 4];
    map->obstacle = header[hlen - 3];
    map->full = header[hlen - 2];
    
    for (int i = 0; i < hlen -4 ; i++)
    {
        map->line = map->line * 10 + (header[i] - '0');
    }

    if (map->line < 1 || map->full == map->obstacle || map->empty == map->full || map->full == map->obstacle) {
        printf("check info\n");
        free(header);
        return (-1);
    }

    free(header);

    map->map = malloc(map->line * sizeof(char*));
    map->width = 0;
    for (int i = 0; i < map->line; i++) {
        char* line = NULL;
        size_t buf = 0;
        int len;

        len = getline(&line, &buf, file);
        if (len == -1 || line[len - 1] != '\n') {
            printf("check1\n");
            free(line);
            for (int k = 0; k < i; k++)
                free(map->map[i]);
            free(map->map);
            return (-1);
        }

        line[len - 1] = '\0';
        int line_len = ft_strlen(line);

        if (i == 0)
            map->width = line_len;
        else {
            if (line_len != map->width) {
                printf("check2\n");
                free(line);
                for (int k = 0; k < i; k++)
                    free(map->map[i]);
                free(map->map);
                return (-1);
            }
        }

        for (int j = 0; j < map->width; j++) {
            if (line[j] != map->empty && line[j] != map->obstacle) {
                printf("check3\n");
                free(line);
                for (int k = 0; k < i; k++)
                    free(map->map[i]);
                free(map->map);
                return (-1);
            }
        }

        map->map[i] = line;
        // printf("%s\n", map->map[i]);
    }

    int** dp = malloc(map->line * sizeof(int*));
    int best_size = 0, best_i = 0, best_j = 0;
    for (int i = 0; i < map->line; i++) {
        dp[i] = calloc(map->width, sizeof(int));

        for (int j = 0; j < map->width; j++) {
            if (map->map[i][j] == map->obstacle)
                dp[i][j] = 0;
            else if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 1 + dp_min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);

            
            if (dp[i][j] > best_size) {
                best_size = dp[i][j];
                best_i = i;
                best_j = j;
            }
        }
    }

    int start_i = best_i - best_size + 1;
    int start_j = best_j - best_size + 1;
    for (int i = start_i; i < start_i + best_size; i++) {
        for (int j = start_j; j < start_j + best_size; j++) {
            map->map[i][j] = map->full;
        }
    }

    for (int i = 0; i < map->line; i++)
        printf("%s\n", map->map[i]);

    for (int i = 0; i < map->line; i++) {
        free(dp[i]);
        free(map->map[i]);
    }

    free(dp);
    free(map->map);

    return (0);
}

int main(int argc, char **argv) {
    Map map;

    if (argc == 1) {
        if (execute_bsq(stdin, &map) == -1)
            fprintf(stderr, "Error: Invalid Map\n");
    } else {
        for (int i = 1; i < argc; i++) {
            FILE* file = fopen(argv[i], "r");
            if (!file) {
                fprintf(stderr, "Error: File Fail to Open\n");
                continue;
            }

            if (execute_bsq(file, &map) == -1)
                fprintf(stderr, "Error: Invalid Map\n");
            fclose(file);
        }
    }

    return (0);
}