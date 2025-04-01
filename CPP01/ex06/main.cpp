/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:23:46 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 10:23:47 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./harlFilter <LEVEL>" << std::endl;
        std::cout << "Where <LEVEL> is one of: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }
    
    Harl harl;
    harl.filterComplain(argv[1]);
    
    return 0;
}