//
//  TextInputReader.cpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#include "TextInputReader.hpp"
#include <sstream>

namespace spellchecker::input {
    
std::vector<std::string> TextInputReader::GetInput(std::string input) {
    
    std::stringstream ss(input);
    std::vector<std::string> inputStringsVector;
    do {
        std::string currentWord;
        ss >> currentWord;
        
        if (currentWord == "")
            continue;
        
        if (ispunct(currentWord.back())) {
            currentWord.pop_back();
        }
        
        inputStringsVector.push_back(currentWord);
    }
    while(ss);
    
    return inputStringsVector;
}
    
}
