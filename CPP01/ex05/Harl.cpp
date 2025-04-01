/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:19:35 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 10:19:40 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
    std::cout << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void Harl::complain(std::string level) {
    // Define an array of pointers to member functions
    void (Harl::*functionPointers[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    
    // Define the level strings for mapping
    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    
    // Find the matching level and call the appropriate function
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*functionPointers[i])();
            return;
        }
    }
    
    // If we get here, the level wasn't recognized
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}