#include "Asistent.h"

//constructors
Asistent::Asistent() : PersonalSpital() {
    this->sectie="";
    this->proceduri_efectuate=0;
}
Asistent::Asistent(const std::string &nume, const std::string &prenume, const std::string &CNP, int salariu, int experienta,
        const std::string &program, const std::string &sectie, int proceduri_efectuate) : PersonalSpital(nume,
        prenume, CNP, salariu, experienta, program) {
    this->sectie=sectie;
    this->proceduri_efectuate=proceduri_efectuate;
}
//copy constructor

//getters

//setters

//operators

//methods