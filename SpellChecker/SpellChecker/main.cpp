//
//  main.cpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#include <iostream>
#include "InputValidator.h"
#include "SpellingChecker.hpp"

int main(int argc, const char * argv[]) {
    
    if (!spellchecker::InputValidator::Validate(argc, argv)) {
        return 1;
    }
    
    spellchecker::SpellingChecker spellingChecker;
    spellingChecker.Initialize("EnglishWords.txt");
    
    for (int i = 1; i < argc; i += 2) {
        switch (argv[i][1]) {
            case 's':
                spellingChecker.SpellCheck((spellchecker::input::InputTypes)0, argv[i + 1]);
                break;
            case 'f':
                spellingChecker.SpellCheck((spellchecker::input::InputTypes)1, argv[i + 1]);
                break;
            case 'a':
                break;
                
            default:
                std::cout << "Usage error: Invalid flag, you can use the following flags: " << std::endl << "-s" << std::endl << "-f" << std::endl << "-a" << std::endl;
                return 2;
        }
    }
    
    return 0;
}
