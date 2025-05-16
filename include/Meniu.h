#ifndef MENIU_H
#define MENIU_H
#include"Pacient.h"
#include"Medic.h"
#include"Asistent.h"
#include"GestiuneProgramari.h"
#include<memory>

//Singleton(design pattern)

class Meniu {
private:
    static Meniu *instanta; //Singleton - se poate crea un singur obiect din aceasta clasa
    std::vector<std::shared_ptr<Pacient>> pacienti;
    std::vector<std::shared_ptr<Medic>> medici;
    std::vector<std::shared_ptr<Asistent>> asistenti;
    GestiuneProgramari gestiuneProgramari;
    //constructor privat - impiedica instantierea din exterior
    Meniu()= default;
    //destructor
    ~Meniu()= default;

public:
    //methods
    static Meniu* getInstanta();
    void ruleaza();
    void ruleazaMeniuPacient();
    void ruleazaMeniuPersonalMedical();
    void ruleazaMeniuMedic();
    void ruleazaMeniuAsistent();

    //getters
    //&-sa nu copiem obj
    // std::vector<std::shared_ptr<Medic>>& getPacienti()const;
    // std::vector<std::shared_ptr<Medic>>& getMedici()const;
    // std::vector<std::shared_ptr<Medic>>& getAsistenti()const;
};


#endif //MENIU_H
