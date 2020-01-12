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
    InputReader* GetInputReader(InputTypes inputType);
};
}

#endif /* InputReaderFactory_hpp */
