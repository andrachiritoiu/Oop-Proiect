#ifndef MEDIC_H
#define MEDIC_H
#include<string>
#include "PersonalSpital.h"


class Medic: public PersonalSpital {
private:
  std::string specializare;
  int numar_pacienti{};
  int numar_operatii{};

public:
    //constructors
    Medic();
    Medic(const std::string &nume, const std::string &prenume, const std::string &CNP, int salariu, int experienta,
        const std::string &program, const std::string &specializare, int numar_pacienti, int numar_operatii);

    //copy constructor

    //getters

    //setters

    //operators

    //methods

    //destructor

};



#endif //MEDIC_H
