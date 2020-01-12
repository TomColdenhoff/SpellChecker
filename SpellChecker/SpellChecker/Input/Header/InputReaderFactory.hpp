//
//  InputReaderFactory.hpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#ifndef InputReaderFactory_hpp
#define InputReaderFactory_hpp

#include "InputTypes.h"
#include "InputReader.h"

namespace spellchecker::input {
class InputReaderFactory {
public:
    // Returns the correct InputReader pointer for the input type.
    // The caller should later delete the pointer because we instantiate the InputReader
    // on the heap.
    InputReader* GetInputReader(InputTypes inputType);
};
}

#endif /* InputReaderFactory_hpp */
