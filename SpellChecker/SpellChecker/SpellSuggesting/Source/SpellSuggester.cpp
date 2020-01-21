//
//  SpellSuggester.cpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 19/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#include "SpellSuggester.hpp"

namespace spellchecker::spellsuggesting {

    SpellSuggester::SpellSuggester(models::WordDictionaryNode* rootWordDictionaryNode) : rootWordDictionaryNode(rootWordDictionaryNode) { }
    
std::vector<std::string> SpellSuggester::SuggestSpelling(std::string word) {
    std::vector<std::string> suggestions = FindSuggestion(std::vector<char>(), word, 0, rootWordDictionaryNode);
    
    //TECHNICAL DEBT
    //The suggestion algorithm needs rethinking/redisigning because it returns duplicates
    //This was the easiest solution at the moment of working at this code.
    std::sort(suggestions.begin(), suggestions.end());
    suggestions.erase(std::unique(suggestions.begin(), suggestions.end()), suggestions.end());
    
    return suggestions;
}
    
std::vector<std::string> SpellSuggester::FindSuggestion(std::vector<char> trace, std::string remainingChars, int currentOffset, models::WordDictionaryNode* currentNode) {
    
    std::vector<std::string> words;
    
    models::WordDictionaryNode* initalNode = currentNode;
    
    if (currentOffset > 2) {
        return words;
    }
    
    for (int i = 0; i < currentNode->Children.size(); ++i) {
        
        int currentNodeChar = currentNode->GetIndexChar(i);
        
        if (currentNodeChar == remainingChars[0]) {
            
            for (int charIndex = 0; charIndex < remainingChars.size(); ++charIndex) {
                
                if (currentNode->Children[currentNode->GetCharIndex(remainingChars[charIndex])] != nullptr) {
                    
                    currentNode = currentNode->Children[currentNode->GetCharIndex(remainingChars[charIndex])];
                    trace.push_back(remainingChars[charIndex]);
                    
                    continue;
                }
                else if (currentOffset <= 2 && charIndex != remainingChars.size() - 1) {
                    std::vector newWords = FindSuggestion(trace, remainingChars.substr(charIndex + 1, remainingChars.size()), currentOffset + 1, currentNode);
                    
                    if (newWords.size() > 1) {
                        
                    }
                    
                    words.insert(words.end(), newWords.begin(), newWords.end());
                }
            }
        }
        else {
            if (currentOffset <= 2 && remainingChars.size() != 0) {
                std::vector newWords = FindSuggestion(trace, remainingChars.substr(1, remainingChars.size()), currentOffset + 1, currentNode);
                
                if (newWords.size() > 1) {
                    
                }
                
                words.insert(words.end(), newWords.begin(), newWords.end());
            }
        }
    }
    
    if (currentNode->IsWord && currentOffset <= 2 && initalNode == currentNode) {
        words.emplace_back(trace.begin(), trace.end());
    }
    
    return words;
}
    
}
