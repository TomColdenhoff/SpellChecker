//
//  WordDictionaryNode.h
//  SpellChecker
//
//  Created by Tom Coldenhoff on 14/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#ifndef WordDictionaryNode_h
#define WordDictionaryNode_h

#include <vector>
#include <map>

namespace spellchecker::models {
class WordDictionaryNode {
public:
    WordDictionaryNode(std::map<char, int>* charIndexMap, int size) : charIndexMap(charIndexMap) { children.resize(size);}
    
    int GetCharIndex(char ch);
    std::map<char, int>* GetIndexMap() { return charIndexMap; }
    
    bool IsWord = false;
    std::vector<WordDictionaryNode*> children;
private:
    std::map<char, int>* charIndexMap;
};
}

#endif /* WordDictionaryNode_h */
