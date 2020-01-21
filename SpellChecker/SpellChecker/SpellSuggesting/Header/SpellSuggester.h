//
//  SpellSuggester.h
//  SpellChecker
//
//  Created by Tom Coldenhoff on 19/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#ifndef SpellSuggester_h
#define SpellSuggester_h

#include <vector>
#include <string>

namespace spellchecker::spellsuggesting::interface {

class SpellSuggester {
public:
    // Returns possible spelling suggestions for the given misspelled word.
    virtual std::vector<std::string> SuggestSpelling(std::string word) = 0;
    
    virtual ~SpellSuggester() { };
};
}

#endif /* SpellSuggester_h */
