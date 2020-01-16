//
//  InputReader.h
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#ifndef InputReader_h
#define InputReader_h

#include <vector>
#include <string>

namespace spellchecker::input {

class InputReader {
public:
    // Gets all the words from the given input
    // Returns a vector<string> that contains all the words from the input.
    // If a word had a punctuation mark at the end of the word, it will be deleted.
    virtual std::vector<std::string> GetInput(std::string input) = 0;
    
    virtual ~InputReader() = 0;
    
protected:
    // Processes the word and tries changing it to a acceptable word for the dictionary.
    std::string ProcessWord(std::string originalWord);
};
}

#endif /* InputReader_h */
