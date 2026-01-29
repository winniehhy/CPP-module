#include "life.h"


char **create_map(int width, int height)
{
    char **map = calloc(height + 1, sizeof(char *));
    for (int i = 0; i < height; i++)
    {
        map[i]= calloc(width + 1, sizeof(char));
        for (int j = 0; j < width; j++)
            map[i][j] = ' ';
    }
    return (map);
}

char **populate (char ** map, int width, int height )
{
    char buf = 0;
    int i = 0;
    int j = 0;
    bool writing = false;

    while (read(0, &buf, 1))
    {
        if (buf == 's' &&  i < height - 1)
            i++;
        else if (buf == 'w' && i > 0)
            i--;
        else if (buf == 'a' && j > 0)
            j--;
        else if (buf == 'd' && j < width - 1)
            j++;
        else if (buf == 'x')
            writing = writing ? false : true;
        
        if (writing)
            map[i][j] = '0';
    }
    return (map);
} 


char **game_of_life (char **map, int width, int height)
{
    char **new_map = create_map (width, height);
    int count;

    for (int i = 0; i < height ; i++)
    {
        for (int j = 0; j < width; j++)
        {
            count = 0;
            if(map[i][j] ='0')
            {
                if (i > 0 && map [i - 1][j] == '0')
                    count++;
                
            }
        }
    }
}

void life (char **av)
{
    int width = atoi(av[1]);
    int height = atoi (av[2]);
    int iterations = atoi (av[3]);

    char **map = create_map(width, height);
    map = populate_map(map, width, height);
    for (int i = 0; i < iterations; i++)
        map = game_of_life(map, width, height);
    print_map(map);
    free_map(map);
}


int main (int ac, char **av)
{
    if (ac != 4)
        return (1);
    life(av);

    return (0);
}