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
    WordDictionaryNode* LoadWordDictionary(std::string dictionaryPath);
    void UnloadWordDictionary(WordDictionaryNode* rootWordDictionareNode);
private:
    void DeleteNode(WordDictionaryNode* node);
    std::map<char, int>* CreateCharacterIndexMap(std::set<char> uniqueCharacters);
};
}

#endif /* DictionaryLoader_hpp */
