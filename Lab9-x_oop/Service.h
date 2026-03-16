#ifndef SERVICE_H
#define SERVICE_H
#include "Repository.h"


class Service {
private:
    Repository* repo;
public:
    Service() = default;
    explicit Service(Repository*);
    ~Service() = default;
    bool addItemServ(int, string, int);
    bool findItemServ(int, string, int);
    bool updateItemServ(int, string, int, int, string, int);
    bool deleteItemServ(int, string, int);
    bool payItemServ(double, double);
    void addBancnotaServ(double);
    vector<Bilet> getAllServ(); //trb test
    vector<double> getAllBancnotaServ(); //trb test
};



#endif //SERVICE_H
