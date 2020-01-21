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
    WordDictionaryNode(std::map<char, int>* charIndexMap, std::map<int, char>* indexCharMap, int size) : charIndexMap(charIndexMap), indexCharMap(indexCharMap) { Children.resize(size);}
    
    // Returns the index of the given character in the children vector.
    // Returns INT_MIN if the character is not part of the used alphabet.
    int GetCharIndex(char ch);
    
    // Retuns the char of the given index in the children vector.
    // Returns '\0' if the index can not be found.
    char GetIndexChar(int index);
    
    std::map<char, int>* GetIndexMap() { return charIndexMap; }
    std::map<int, char>* GetCharMap() { return indexCharMap; }
    
    bool IsWord = false;
    std::vector<WordDictionaryNode*> Children;
private:
    std::map<char, int>* charIndexMap;
    std::map<int, char>* indexCharMap;
};
}

#endif /* WordDictionaryNode_h */
