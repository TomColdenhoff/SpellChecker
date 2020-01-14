//
//  ISpellChecker.h
//  SpellChecker
//
//  Created by Tom Coldenhoff on 14/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#ifndef ISpellChecker_h
#define ISpellChecker_h

#include <string>

namespace spellchecker::spellchecking::interface {

class SpellChecker {
public:
    // Check if the given word is spelled correctly. Returns true if spelled correctly.
    virtual bool CheckSpelling(std::string word) = 0;
    
    virtual ~SpellChecker() { };
};
}

#endif /* ISpellChecker_h */
