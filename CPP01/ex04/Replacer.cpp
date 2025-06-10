/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:07:22 by hheng             #+#    #+#             */
/*   Updated: 2025/06/10 18:49:34 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

//chmod 755 reset
//chmod a-r file.txt ( remove read permission for all users )

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

    // write permission denied
    if (outFile.fail()) {
        std::cerr << "Error: Permission denied writing to " << outFilename << std::endl;
        inFile.close();
        outFile.close();
        return false;
    }

    bool replacementFound = false;
    
    //getline reads line by line until /n is found, and stores it in line
    std::string line;
    while (std::getline(inFile, line)) {
        std::string modifiedLine; // add text between last found and new found
        size_t startPos = 0;
        size_t foundPos;
        
        //npos = not found
        while ((foundPos = line.find(_s1, startPos)) != std::string::npos) {
            modifiedLine.append(line, startPos, foundPos - startPos); 
            modifiedLine.append(_s2);
            startPos = foundPos + _s1.length();
            replacementFound = true;
        }
        
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
        std::remove(outFilename.c_str());
        return false;
    }
    
    return true;
}