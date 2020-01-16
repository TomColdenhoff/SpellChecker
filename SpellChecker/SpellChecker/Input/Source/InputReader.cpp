//
//  InputReader.cpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#include "InputReader.h"

namespace spellchecker::input {
InputReader::~InputReader() {
    
}
    
std::string InputReader::ProcessWord(std::string originalWord) {
    
    int wordSize = originalWord.size();
    
    int punctuationCount = 0;
    int upperCount = 0;
    for (char ch : originalWord) {
        if (ispunct(ch)) {
            punctuationCount++;
        }
        else if (isupper(ch)) {
            upperCount++;
        }
    }
    
    if (punctuationCount == 0 && upperCount == 0) {
        return  originalWord;
    }
    
    if (punctuationCount == 1 && ispunct(originalWord.back())) {
        originalWord.pop_back();
    }
    
    if (upperCount == 1 && isupper(originalWord.front())) {
        originalWord[0] = tolower(originalWord[0]);
    }
    
    return originalWord;
}
}
