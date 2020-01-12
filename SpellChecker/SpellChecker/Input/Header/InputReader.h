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
    virtual std::vector<std::string> GetInput(std::string input) = 0;
    virtual ~InputReader() = 0;
};
}

#endif /* InputReader_h */
