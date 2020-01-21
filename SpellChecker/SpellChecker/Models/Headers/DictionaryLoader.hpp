//
//  DictionaryLoader.hpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 14/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#ifndef DictionaryLoader_hpp
#define DictionaryLoader_hpp

#include "WordDictionaryNode.h"
#include <string>
#include <map>
#include <set>

namespace spellchecker::models {
    
class DictionaryLoader {
public:
    // Loads the given dictionary(.txt file with all the words) into memory (as a trie data structure)
    // and returns a pointer to the first node of the dictionary.
    WordDictionaryNode* LoadWordDictionary(std::string dictionaryPath);
    
    // Unloads the whole dictionary(that's connected to the root node) from memory.
    void UnloadWordDictionary(WordDictionaryNode* rootWordDictionareNode);
private:
    void DeleteNode(WordDictionaryNode* node);
    
    std::tuple<std::map<char, int>*, std::map<int, char>*> CreateMaps(std::set<char> uniqueCharacters);
};
}

#endif /* DictionaryLoader_hpp */
