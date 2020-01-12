//
//  InputReaderFactory.cpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#include "InputReaderFactory.hpp"
#include "TextInputReader.hpp"
#include "TextFileInputReader.hpp"
#include <iostream>

namespace spellchecker::input {
    
InputReader* InputReaderFactory::GetInputReader(InputTypes inputType) {
    InputReader* inputReader;
    
    switch (inputType) {
        case String:
            inputReader = new TextInputReader();
            break;
        case File:
            inputReader = new TextFileInputReader();
            break;
        default:
            std::cout << "Unsupported input type" << std::endl;
            return nullptr;
            break;
    }
    
    return inputReader;
}
    
}
