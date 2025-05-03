#ifndef PACIENT_H
#define PACIENT_H
#include<string>
#include "Persoana.h"

class Pacient: public Persoana{
private:
    int id_pacient{};
    static int next_id;
    std::string diagnostic;
    int severitate_boala{};
    std::string data_internare;
    std::string data_externare;
    bool asigurat;
    int varsta{};

public:
    //constructors
    Pacient(const std::string &nume, const std::string &prenume, const std::string &CNP, const std::string &diagnostic,
        int severitate_boala, const std::string &data_internare, const std::string &data_externare, bool asigurat, int varsta);
    //copy constructor

    //getters

    //setters

    //operators

    //methods

    //destructor


};


#endif //PACIENT_H
