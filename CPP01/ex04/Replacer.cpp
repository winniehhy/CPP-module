/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:07:22 by hheng             #+#    #+#             */
/*   Updated: 2025/05/16 14:57:06 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

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

    bool replacementFound = false;
    
    // Process the file line by line
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
            replacementFound = true; 
        }
        
        // Add any remaining content after the last occurrence
        modifiedLine.append(line, startPos, std::string::npos);
        
        // Write the modified line to the output file
        outFile << modifiedLine;
        
        // Add a newline if not at the end of the file
        if (!inFile.eof()) {
            outFile << std::endl;
        }
    }
    
    // Close the files
    inFile.close();
    outFile.close();

    if (!replacementFound) {
        std::cerr << "Error: String '" << _s1 << "' not found in " << _filename << std::endl;
        std::remove(outFilename.c_str());
        return false;
    }
    
    return true;
}