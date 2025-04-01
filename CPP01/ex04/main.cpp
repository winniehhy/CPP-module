/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:05:14 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 10:09:47 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    // Check if we have the correct number of arguments
    if (argc != 4) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        std::cerr << "Usage: " << argv[0] << " <filename> <string_to_find> <string_to_replace>" << std::endl;
        return 1;
    }

    // Get the arguments
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    // Check for empty strings
    if (s1.empty()) {
        std::cerr << "Error: The string to find cannot be empty" << std::endl;
        return 1;
    }
    
    // Create a replacer object
    Replacer replacer(filename, s1, s2);
    
    // Perform the replacement
    if (!replacer.replace()) {
        return 1; // Error message already printed by replace()
    }
    
    std::cout << "Replacement completed successfully. Result saved to " << filename << ".replace" << std::endl;
    return 0;
}