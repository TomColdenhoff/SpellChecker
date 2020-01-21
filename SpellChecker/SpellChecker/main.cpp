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
    
    std::vector<std::string> misspelledWords;
    
    for (int i = 1; i < argc; i += 2) {
        switch (argv[i][1]) {
            case 's':
                misspelledWords = spellingChecker.SpellCheck((spellchecker::input::InputTypes)0, argv[i + 1]);
                break;
            case 'f':
                misspelledWords = spellingChecker.SpellCheck((spellchecker::input::InputTypes)1, argv[i + 1]);
                break;
            case 'a':
                break;
                
            default:
                std::cout << "Usage error: Invalid flag, you can use the following flags: " << std::endl << "-s" << std::endl << "-f" << std::endl << "-a" << std::endl;
                return 2;
        }
    }
    
    std::cout << "Found a total of " << misspelledWords.size() << " misspelled words." << std::endl;
    
    if (misspelledWords.size() == 0) {
        return 0;
    }
    
    std::cout << "The misspelled words are:" << std::endl << std::endl;
    for (std::string word : misspelledWords) {
        std::cout << word << std::endl;
        std::cout << "Did you mean:" << std::endl;
        
        std::vector<std::string> suggestions = spellingChecker.SuggestSpelling(word);
        for (std::string suggestion : suggestions) {
            std::cout << suggestion << std::endl;
        }
    }
    
    
    
    return 0;
}
