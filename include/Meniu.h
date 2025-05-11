#ifndef MENIU_H
#define MENIU_H
#include"Pacient.h"
#include"Medic.h"
#include"Asistent.h"

#include<iostream>

//Singleton(design pattern)

class Meniu {
private:
    static Meniu *instanta; //Singleton - se poate crea un singur obiect din aceasta clasa
    std::vector<Pacient>pacienti;
    std::vector<Medic>medici;
    std::vector<Asistent>asistenti;
    //constructor privat - impiedica instantierea din exterior
    Meniu()= default;

public:
    //methods
    static Meniu* getInstanta();
    void ruleaza();
    void ruleazaMeniuPacient();
    void ruleazaMeniuPersonalMedical();
    void ruleazaMeniuMedic();
    void ruleazaMeniuAsistent();

    //destructor
    ~Meniu()= default;
};


#endif //MENIU_H
