/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:05:14 by hheng             #+#    #+#             */
/*   Updated: 2025/06/10 18:15:08 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

// to understang string searching using ifstream and ofstream

int main(int argc, char *argv[])
{
    if (argc != 4) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        std::cerr << "Usage: " << argv[0] << " <filename> <string_to_find> <string_to_replace>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    // Check for empty strings
    if (s1.empty()) {
        std::cerr << "Error: The string to find cannot be empty" << std::endl;
        return 1;
    }
    
    Replacer replacer(filename, s1, s2);
    if (!replacer.replace()) {
        return 1;
    }
    
    std::cout << "Replacement completed successfully. Result saved to " << filename << ".replace" << std::endl;
    return 0;
}