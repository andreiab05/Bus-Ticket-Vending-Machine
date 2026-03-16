#ifndef EXCEPTIONFONDURIINSUFICIENTE_H
#define EXCEPTIONFONDURIINSUFICIENTE_H
#include "Exception.h"


class ExceptionFonduriInsuficiente : public Exception {
public:
    ExceptionFonduriInsuficiente(): Exception("Suma introdusa este insuficienta.") {}
};



#endif //EXCEPTIONFONDURIINSUFICIENTE_H
