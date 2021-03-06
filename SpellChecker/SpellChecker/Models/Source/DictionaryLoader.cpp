//
//  DictionaryLoader.cpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 14/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#include "DictionaryLoader.hpp"
#include <vector>
#include <fstream>
#include <iostream>

namespace spellchecker::models {
    
WordDictionaryNode* DictionaryLoader::LoadWordDictionary(std::string dictionaryPath) {
    std::set<char> uniqueChars;
    std::vector<std::string> words;
    
    std::ifstream file;
    file.open(dictionaryPath);
    
    if (!file.is_open()) {
        std::cout << "Couldn't open word file: " << dictionaryPath << ". Check if the file exists" << std::endl;
        
        return nullptr;
    }
    
    std::string word;
    while (file >> word) {
        
        for (char ch : word) {
            uniqueChars.insert(ch);
        }
        words.push_back(word);
    }
    
    std::map<char, int>* charIndexMap = CreateCharacterIndexMap(uniqueChars);
    int charAmount = uniqueChars.size();
    
    
    WordDictionaryNode* rootNode = new WordDictionaryNode(charIndexMap, charAmount);
    
    // Fill the whole trie data structure by looping through all the words.
    for (std::string word : words) {
        WordDictionaryNode* currentNode = rootNode;

        int charsInWord = word.size();
        for (int i = 0; i < charsInWord; ++i) {
            
            int charIndex = currentNode->GetCharIndex(word[i]);
            if (currentNode->Children[charIndex] == nullptr) {
                currentNode->Children[charIndex] = new WordDictionaryNode(charIndexMap, charAmount);
            }
            
            currentNode = currentNode->Children[charIndex];
            
            if (i == charsInWord - 1) {
                currentNode->IsWord = true;
            }
        }
    }
    
    return rootNode;
}
    
void DictionaryLoader::UnloadWordDictionary(WordDictionaryNode* rootWordDictionaryNode) {
    
    delete rootWordDictionaryNode->GetIndexMap();
    
    DeleteNode(rootWordDictionaryNode);
    
}
    
void DictionaryLoader::DeleteNode(WordDictionaryNode* node) {
    
    for (WordDictionaryNode* childNode : node->Children) {
        
        if (childNode == nullptr) {
            continue;
        }
        
        DeleteNode(childNode);
        delete childNode;
    }
}
    
std::map<char, int>* DictionaryLoader::CreateCharacterIndexMap(std::set<char> uniqueCharacters) {
    
    std::map<char, int>* map = new std::map<char, int>();
    
    int i = 0;
    for (char ch : uniqueCharacters) {
        map->insert( std::pair<char,int>(ch, i) );
        i++;
    }
    
    return map;
}
    
}
