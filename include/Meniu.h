#ifndef MENIU_H
#define MENIU_H


class Meniu {
private:
    static Meniu *instanta; //Singleton(design pattern) - se poate crea un singur obiect din aceasta clasa
    //constructor privat - impiedica instantierea din exterior
    Meniu()= default;

public:
    //methods
    static Meniu* getInstanta();
    void ruleaza();
    void ruleazaMeniuPacient();
    void ruleazaMeniuPersonalMedical();

    //destrctor
    ~Meniu()= default;
};


#endif //MENIU_H
