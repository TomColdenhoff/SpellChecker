//
//  TextFileInputReader.hpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#ifndef TextFileInputReader_hpp
#define TextFileInputReader_hpp

#include "InputReader.h"

namespace spellchecker::input {
class TextFileInputReader : public InputReader {
public:
    std::vector<std::string> GetInput(std::string input) override;
};
}

#endif /* TextFileInputReader_hpp */
