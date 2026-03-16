#ifndef UI_H
#define UI_H
#include "Service.h"


class UI {
private:
    Service serv;
    void adaugareBilet();
    void cautareBilet();
    void actualizareBilet();
    void stergereBilet();
    void cumparareBilet();
public:
    UI() = default;
    explicit UI(const Service&);
    void showMenu();
    ~UI() = default;
};



#endif //UI_H
