#ifndef EXCEPTIONBANCNOTEINSUFICIENTE_H
#define EXCEPTIONBANCNOTEINSUFICIENTE_H
#include "Exception.h"


class ExceptionBancnoteInsuficiente: public Exception {
public:
    ExceptionBancnoteInsuficiente(): Exception("Automatul nu poate oferi restul necesar.") {}
};



#endif //EXCEPTIONBANCNOTEINSUFICIENTE_H
