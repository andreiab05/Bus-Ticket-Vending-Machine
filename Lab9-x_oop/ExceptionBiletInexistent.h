#ifndef EXCEPTIONBILETINEXISTENT_H
#define EXCEPTIONBILETINEXISTENT_H
#include "Exception.h"


class ExceptionBiletInexistent : public Exception {
public:
    ExceptionBiletInexistent(): Exception("Biletul cerut nu exista. ") {}
};



#endif //EXCEPTIONBILETINEXISTENT_H
