//
//  InputValidator.cpp
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#include "InputValidator.h"
#include <iostream>

namespace spellchecker {

bool InputValidator::Validate(int argc, const char *argv[]) {
    
    if (!ValidateMinimumArgumentCount(argc)) {
        return false;
    }
    
    if (!ValidateArgumentCount(argc)) {
        return  false;
    }
    
    if (!ValidateFlagUsage(argc, argv)) {
        return false;
    }
    
    return true;
}

bool InputValidator::ValidateMinimumArgumentCount(int argc) {
    
    if (argc - 1 < 2) {
        std::cout << "Usage error: Expteced a minimum of 2 input arguments. Received " << argc - 1 << "." << std::endl;
        return false;
    }
    
    return  true;
}

bool InputValidator::ValidateArgumentCount(int argc) {
    
    if ((argc - 1) % 2 != 0) {
        std::cout << "Usage error: Expected " << argc << " input arguments. Received " << argc - 1 << "." << std::endl;
        return false;
    }
    
    return true;
}

bool InputValidator::ValidateFlagUsage(int argc, const char *argv[]) {
    
    for (int i = 1; i < argc; ++i) {
        if (i % 2 == 1) {
            if (argv[i][0] == '-') {
                continue;
            }
            
            std::cout << "Usage error: Expected a flag, but received: " << argv[i] << std::endl;
            return false;
        }
        
        if (argv[i][0] != '-') {
            continue;
        }
        
        std::cout << "Usage error: Expected a flag argument, but received: " << argv[i] << std::endl;
        return false;
    }
    
    return true;
}
}
