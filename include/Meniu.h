#ifndef MENIU_H
#define MENIU_H
#include"Pacient.h"
#include<iostream>

//Singleton(design pattern)

class Meniu {
private:
    static Meniu *instanta; //Singleton - se poate crea un singur obiect din aceasta clasa
    std::vector<Pacient>pacienti;
    //constructor privat - impiedica instantierea din exterior
    Meniu()= default;

public:
    //methods
    static Meniu* getInstanta();
    void ruleaza();
    void ruleazaMeniuPacient();
    void ruleazaMeniuPersonalMedical();

    //destructor
    ~Meniu()= default;
};


#endif //MENIU_H
