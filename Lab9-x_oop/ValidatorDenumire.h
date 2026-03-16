#ifndef VALIDATORDENUMIRE_H
#define VALIDATORDENUMIRE_H


#include <string>
#include <cctype>

class ValidatorDenumire {
public:
    bool validate(const std::string& denumire) {
        if (denumire.empty())
            return false;

        for (char c : denumire) {
            if (!std::isalpha(c) && c != ' ')
                return false;
        }
        return true;
    }
};



#endif //VALIDATORDENUMIRE_H
