/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:07:22 by hheng             #+#    #+#             */
/*   Updated: 2025/04/01 10:10:05 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <iostream>
#include <sstream>

Replacer::Replacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : _filename(filename), _s1(s1), _s2(s2) {
}

Replacer::~Replacer() {
}

bool Replacer::replace() {
    // Open the input file
    std::ifstream inFile(_filename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file " << _filename << std::endl;
        return false;
    }
    
    // Open the output file
    std::string outFilename = _filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create output file " << outFilename << std::endl;
        inFile.close();
        return false;
    }
    
    // Process the file line by line
    std::string line;
    while (std::getline(inFile, line)) {
        std::string modifiedLine;
        size_t startPos = 0;
        size_t foundPos;
        
        // Find each occurrence of s1 in the current line and build the modified line
        while ((foundPos = line.find(_s1, startPos)) != std::string::npos) {
            // Add everything from the last position to the found position
            modifiedLine.append(line, startPos, foundPos - startPos);
            // Add the replacement string
            modifiedLine.append(_s2);
            // Move past this occurrence
            startPos = foundPos + _s1.length();
        }
        
        // Add any remaining content after the last occurrence
        modifiedLine.append(line, startPos, std::string::npos);
        
        // Write the modified line to the output file
        outFile << modifiedLine;
        
        // Add a newline if we're not at the end of the file
        if (!inFile.eof()) {
            outFile << std::endl;
        }
    }
    
    // Close the files
    inFile.close();
    outFile.close();
    
    return true;
}