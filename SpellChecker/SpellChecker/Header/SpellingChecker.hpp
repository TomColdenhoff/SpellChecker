//
//  SpellingChecker.hpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#ifndef SpellingChecker_hpp
#define SpellingChecker_hpp

#include "InputTypes.h"
#include <vector>
#include <string>

namespace spellchecker {
class SpellingChecker {
public:
    // Checks if the spelling is correct for all the words in the given input.
    // Returns a vector<string> that contains all the misspelled words.
    std::vector<std::string> SpellCheck(spellchecker::input::InputTypes inputType, std::string input);
};
}

#endif /* SpellingChecker_hpp */
