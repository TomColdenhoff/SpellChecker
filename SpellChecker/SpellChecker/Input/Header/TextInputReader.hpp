//
//  TextInputReader.hpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#ifndef TextInputReader_hpp
#define TextInputReader_hpp

#include "InputReader.h"

namespace spellchecker::input {
class TextInputReader : public InputReader {
public:
    std::vector<std::string> GetInput(std::string input) override;
};
}
#endif /* TextInputReader_hpp */
