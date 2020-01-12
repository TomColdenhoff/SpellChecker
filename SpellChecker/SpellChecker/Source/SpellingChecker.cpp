//
//  SpellingChecker.cpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#include "SpellingChecker.hpp"
#include "InputReaderFactory.hpp"

namespace spellchecker {

std::vector<std::string> SpellingChecker::SpellCheck(spellchecker::input::InputTypes inputType, std::string input) {
    
    spellchecker::input::InputReaderFactory inputReaderFactory;
    spellchecker::input::InputReader* inputReader = inputReaderFactory.GetInputReader(inputType);
    
    std::vector<std::string> misspelledWordsVector = inputReader->GetInput(input);
    
    delete inputReader;
    
    return std::vector<std::string>();
}

}
