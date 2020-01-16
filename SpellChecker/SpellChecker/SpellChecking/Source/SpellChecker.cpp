//
//  SpellChecker.cpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 14/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#include "SpellChecker.hpp"

namespace spellchecker::spellchecking {

SpellChecker::SpellChecker(models::WordDictionaryNode* rootWordDictionaryNode) : rootWordDictionaryNode(rootWordDictionaryNode) {}

bool SpellChecker::CheckSpelling(std::string word) {
    
    models::WordDictionaryNode* currentNode = rootWordDictionaryNode;
    
    int wordSize = word.size();
    for (int i = 0; i < wordSize; ++i) {
        int charIndex = currentNode->GetCharIndex(word[i]);
        
        if (currentNode->Children[charIndex] == nullptr) {
            return false;
        }
        
        currentNode = currentNode->Children[charIndex];
        
        if (i == wordSize - 1) {
            return currentNode->IsWord;
        }
    }
     
    return false;
}
}
