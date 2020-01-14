//
//  SpellChecker.hpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 14/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#ifndef SpellChecker_hpp
#define SpellChecker_hpp

#include "SpellChecker.h"
#include <string>

namespace spellchecker::spellchecking {
    
class SpellChecker : public spellchecker::spellchecking::interface::SpellChecker {
public:
    bool CheckSpelling(std::string word) override;
};
}

#endif /* SpellChecker_hpp */
