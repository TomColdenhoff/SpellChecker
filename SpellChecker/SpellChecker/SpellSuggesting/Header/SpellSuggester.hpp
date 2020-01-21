//
//  SpellSuggester.hpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 19/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#ifndef SpellSuggester_hpp
#define SpellSuggester_hpp

#include "SpellSuggester.h"
#include "WordDictionaryNode.h"

namespace spellchecker::spellsuggesting {

class SpellSuggester : public interface::SpellSuggester {
public:
    SpellSuggester(models::WordDictionaryNode* rootWordDictionaryNode);
    
    std::vector<std::string> SuggestSpelling(std::string word) override;
    
private:
    models::WordDictionaryNode* rootWordDictionaryNode = nullptr;
    
    std::vector<std::string> FindSuggestion(std::vector<char> trace, std::string remainingChars, int currentOffset, models::WordDictionaryNode* currentNode);
};

}

#endif /* SpellSuggester_hpp */
