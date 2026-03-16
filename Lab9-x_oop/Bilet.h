#ifndef BILET_H
#define BILET_H
#include <string>
#include <iostream>
using namespace std;

class Bilet {
private:
      int cod, pret;
      string denumire;
public:
      Bilet();
      Bilet(int, string, int);
      ~Bilet() = default;
      bool operator==(const Bilet&) const;
      string toString() const;
      friend ostream& operator<<(ostream& os, const Bilet& b);
      int getCod() const;
      string getDenumire() const;
      int getPret() const;
};



#endif //BILET_H
