#include "Medic.h"

//constructors
Medic::Medic() : PersonalSpital() {
    this->specializare="";
    this->numar_pacienti=0;
    this->numar_pacienti=0;
}
Medic::Medic(const std::string &nume, const std::string &prenume, const std::string &CNP, int salariu, int experienta,
       const std::string &program, const std::string &specializare, int numar_pacienti, int numar_operatii) : PersonalSpital(nume,
       prenume, CNP, salariu, experienta, program) {
    this->specializare=specializare;
    this->numar_pacienti=numar_pacienti;
    this->numar_pacienti=numar_pacienti;
}
//copy constructor

//getters

//setters

//operators

//methods

