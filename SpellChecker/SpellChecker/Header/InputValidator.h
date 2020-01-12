//
//  InputValidator.h
//  SpellChecker
//
//  Created by Tom Coldenhoff on 12/01/2020.
//  Copyright © 2020 Tom Coldenhoff. All rights reserved.
//

#ifndef InputValidator_h
#define InputValidator_h

namespace spellchecker {

class InputValidator {
public:
    // Validates the input arguments passed to the application
    // Validate checks for the minimum argument count, the total argument count
    // and for the flag usage.
    // Returns true if the input is valid.
    static bool Validate(int argc, const char *argv[]);
    
private:
    static bool ValidateMinimumArgumentCount(int argc);
    static bool ValidateArgumentCount(int argc);
    static bool ValidateFlagUsage(int argc, const char *argv[]);
};

}


#endif /* InputValidator_h */
