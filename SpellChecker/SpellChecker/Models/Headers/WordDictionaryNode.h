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
    WordDictionaryNode(std::map<char, int>* charIndexMap, int size) : charIndexMap(charIndexMap) { Children.resize(size);}
    
    // Returns the index of the given character in the children vector.
    // Returns INT_MIN if the character is not part of the used alphabet.
    int GetCharIndex(char ch);
    
    std::map<char, int>* GetIndexMap() { return charIndexMap; }
    
    bool IsWord = false;
    std::vector<WordDictionaryNode*> Children;
private:
    std::map<char, int>* charIndexMap;
};
}

#endif /* WordDictionaryNode_h */
