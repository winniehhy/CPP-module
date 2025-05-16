/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:07:22 by hheng             #+#    #+#             */
/*   Updated: 2025/05/16 15:42:16 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : _filename(filename), _s1(s1), _s2(s2) {
}

Replacer::~Replacer() {
}

bool Replacer::replace() {
    // Check if strings are empty
    if (_s1.empty()) {
        std::cerr << "Error: Search string cannot be empty" << std::endl;
        return false;
    }
    
    // Open the input file
    std::ifstream inFile(_filename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file " << _filename << std::endl;
        return false;
    }

    // permission handle
    if (inFile.fail()) {
        std::cerr << "Error: Permission denied reading from " << _filename << std::endl;
        inFile.close();
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

    // Check if we can write to the output file
    if (outFile.fail()) {
        std::cerr << "Error: Permission denied writing to " << outFilename << std::endl;
        inFile.close();
        outFile.close();
        return false;
    }

    bool replacementFound = false;
    
    std::string line;
    while (std::getline(inFile, line)) {
        std::string modifiedLine;
        size_t startPos = 0;
        size_t foundPos;
        
        // Find each occurrence of s1 in the current line and build the modified line
        while ((foundPos = line.find(_s1, startPos)) != std::string::npos) {
            modifiedLine.append(line, startPos, foundPos - startPos);
            modifiedLine.append(_s2);
            startPos = foundPos + _s1.length();
            replacementFound = true; // Mark that a replacement was found
        }
        
        // Add any remaining content after the last occurrence
        modifiedLine.append(line, startPos, std::string::npos);
        outFile << modifiedLine;
        
        // Add a newline if not at the end of the file
        if (!inFile.eof()) {
            outFile << std::endl;
        }
    }
    
    inFile.close();
    outFile.close();

    if (!replacementFound) {
        std::cerr << "Error: String '" << _s1 << "' not found in " << _filename << std::endl;
        std::remove(outFilename.c_str()); // Remove the output file since no changes were made
        return false;
    }
    
    return true;
}