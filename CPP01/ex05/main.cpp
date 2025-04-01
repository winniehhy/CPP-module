/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:19:50 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 10:19:52 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;
    
    std::cout << "Testing Harl with various complaint levels:" << std::endl;
    std::cout << "----------------------------------------" << std::endl << std::endl;
    
    std::cout << "Calling complain(\"DEBUG\"):" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "Calling complain(\"INFO\"):" << std::endl;
    harl.complain("INFO");
    
    std::cout << "Calling complain(\"WARNING\"):" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "Calling complain(\"ERROR\"):" << std::endl;
    harl.complain("ERROR");
    
    std::cout << "Calling complain with an invalid level:" << std::endl;
    harl.complain("CRITICAL");
    
    return 0;
}