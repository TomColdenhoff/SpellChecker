//
//  WordDictionaryNode.cpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 14/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#include "WordDictionaryNode.h"

namespace spellchecker::models {

int WordDictionaryNode::GetCharIndex(char ch) {
    
    std::map<char, int>::iterator it = charIndexMap->find(ch);
    
    if (it != charIndexMap->end()) {
        return it->second;
    }
    
    return INT_MIN;
}
    
char WordDictionaryNode::GetIndexChar(int index) {
    
    std::map<int, char>::iterator it = indexCharMap->find(index);
    
    if (it != indexCharMap->end()) {
        return it->second;
    }
    
    return '\0';
}
    
}
