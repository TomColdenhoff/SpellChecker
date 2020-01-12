//
//  TextFileInputReader.cpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#include "TextFileInputReader.hpp"
#include <iostream>
#include <fstream>

namespace spellchecker::input {

std::vector<std::string> TextFileInputReader::GetInput(std::string input) {
    
    std::ifstream file;
    file.open(input);
    
    if (!file.is_open()) {
        std::cout << "Couldn't open file: " << input << ". Check if the file exists" << std::endl;
        
        return std::vector<std::string>();
    }
    
    std::vector<std::string> inputStringsVector;
    
    std::string word;
    while (file >> word) {
        inputStringsVector.push_back(word);
    }
    
    return inputStringsVector;
}
    
}
