#ifndef VALIDATORBILET_H
#define VALIDATORBILET_H



class ValidatorBilet {
public:
    bool validate(int cod, const std::string& denumire, int pret) {
        if (cod <= 0) return false;
        if (denumire.empty()) return false;
        if (pret <= 0) return false;
        return true;
    }
};



#endif //VALIDATORBILET_H
