//
//  SpellingChecker.cpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#include "DictionaryLoader.hpp"
#include "SpellingChecker.hpp"
#include "InputReaderFactory.hpp"
#include "SpellChecker.hpp"
#include "SpellSuggester.hpp"

namespace spellchecker {

void SpellingChecker::Initialize(std::string dictionary) {
    models::DictionaryLoader dictionaryLoader;
    rootWordDictionaryNode = dictionaryLoader.LoadWordDictionary(dictionary);
}

std::vector<std::string> SpellingChecker::SpellCheck(spellchecker::input::InputTypes inputType, std::string input) {
    
    spellchecker::input::InputReaderFactory inputReaderFactory;
    spellchecker::input::InputReader* inputReader = inputReaderFactory.GetInputReader(inputType);
    
    std::vector<std::string> wordsInputVector = inputReader->GetInput(input);
    spellchecker::spellchecking::interface::SpellChecker *spellChecker = new spellchecker::spellchecking::SpellChecker(rootWordDictionaryNode);
    
    std::vector<std::string> misspelledWordsVector;
    
    for(std::string word : wordsInputVector) {
        if (!spellChecker->CheckSpelling(word)) {
            misspelledWordsVector.push_back(word);
        }
    }
    
    delete inputReader;
    delete spellChecker;
    
    return misspelledWordsVector;
}

std::vector<std::string> SpellingChecker::SuggestSpelling(std::string misspelledWord) {
    
    spellchecker::spellsuggesting::interface::SpellSuggester *spellingSuggester = new spellchecker::spellsuggesting::SpellSuggester(rootWordDictionaryNode);
    
    std::vector<std::string> suggestions = spellingSuggester->SuggestSpelling(misspelledWord);
    
    delete spellingSuggester;
    
    return suggestions;
}

SpellingChecker::~SpellingChecker() {
    models::DictionaryLoader dictionaryLoader;
    dictionaryLoader.UnloadWordDictionary(rootWordDictionaryNode);
}

}
