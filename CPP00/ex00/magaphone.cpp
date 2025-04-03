/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:45:13 by hheng             #+#    #+#             */
/*   Updated: 2025/03/14 18:51:22 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        for (int i = 1; i < ac; ++i)
        {
            for (char *p = av[i]; *p != '\0'; ++p)
            {
                std::cout <<(char) std::toupper(*p);
            }
        }
    }
    std::cout << "\n";
    return 0;
}
