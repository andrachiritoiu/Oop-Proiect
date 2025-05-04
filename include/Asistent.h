#ifndef ASISTENT_H
#define ASISTENT_H
#include<string>
#include "PersonalSpital.h"

class Asistent: public PersonalSpital {
private:
  std::string sectie;
  int proceduri_efectuate;

public:
    //constructors
    Asistent();
    Asistent(const std::string &nume, const std::string &prenume, const std::string &CNP, int salariu, int experienta,
        const std::string &program, const std::string &sectie, int proceduri_efectuate);

    //copy constructor

    //getters

    //setters

    //operators

    //methods

    //destructor

};



#endif //ASISTENT_H
