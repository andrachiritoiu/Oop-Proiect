#ifndef ASISTENT_H
#define ASISTENT_H
#include<string>
#include<vector>
#include "PersonalSpital.h"
#include "Pacient.h"

class Asistent: public PersonalSpital {
private:
   std::string sectie;
   std::vector<std::string> proceduri_efectuate;

public:
    //constructors
    Asistent();
    Asistent(const std::string &nume, const std::string &prenume, const std::string &CNP, int salariu, int experienta,
         const std::map<std::string, std::vector<std::pair<int,int>>> &program, const std::string &sectie, const std::vector<std::string> &proceduri_efectuate);
    //copy constructor
    Asistent(const Asistent &a);

    //getters
    std::string getSectie() const;
    std::vector<std::string> getProceduri() const;

    //setters

    //operators
    Asistent& operator=(const Asistent &a);
    friend std::istream& operator>>(std::istream &in, Asistent &a);
    friend std::ostream& operator<<(std::ostream &out,const Asistent &a);

    //methods
    void calclueazaBonus() const override;
    void addProcedura(const std::string &procedura);
    void efectueazaProcedura(Pacient *p, const std::string &procedura);
    // template<typename T>
    // void verificaStoc(const Medicament<T>& med);

    //destructor
    ~Asistent() override = default;
};


#endif //ASISTENT_H
