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
#include <tuple>

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
    
    std::tuple<std::map<char, int>*, std::map<int, char>*>  mapTuple = CreateMaps(uniqueChars);
    int charAmount = uniqueChars.size();
    
    
    WordDictionaryNode* rootNode = new WordDictionaryNode(std::get<0>(mapTuple), std::get<1>(mapTuple), charAmount);
    
    // Fill the whole trie data structure by looping through all the words.
    for (std::string word : words) {
        WordDictionaryNode* currentNode = rootNode;

        int charsInWord = word.size();
        for (int i = 0; i < charsInWord; ++i) {
            
            int charIndex = currentNode->GetCharIndex(word[i]);
            if (currentNode->Children[charIndex] == nullptr) {
                currentNode->Children[charIndex] = new WordDictionaryNode(std::get<0>(mapTuple), std::get<1>(mapTuple), charAmount);
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
    
std::tuple<std::map<char, int>*, std::map<int, char>*> DictionaryLoader::CreateMaps(std::set<char> uniqueCharacters) {
    
    std::map<char, int>* charIndexMap = new std::map<char, int>();
    std::map<int, char>* indexCharMap = new std::map<int, char>();
    
    int i = 0;
    for (char ch : uniqueCharacters) {
        charIndexMap->insert( std::pair<char,int>(ch, i) );
        indexCharMap->insert(std::pair<int, char>(i, ch));
        i++;
    }
    
    return std::tuple<std::map<char, int>*, std::map<int, char>*>(charIndexMap, indexCharMap);
}
    
}
