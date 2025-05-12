#ifndef MEDIC_H
#define MEDIC_H
#include<string>
#include<map>
#include "PersonalSpital.h"
#include "Pacient.h"

class Medic: public PersonalSpital {
private:
  std::string specializare;
  int numar_pacienti_tratati{};
  int numar_operatii{};
  std::map<int, Pacient>pacienti;//dictionar cu cheia id_pacient

public:
    //constructors
    Medic();
    Medic(const std::string &nume, const std::string &prenume, const std::string &CNP, int salariu, int experienta, const std::string &program,
        const std::string &specializare, int numar_pacienti_tratati, int numar_operatii, const std::map<int, Pacient>& pacienti);
    //copy constructor
    Medic(const Medic &m);

    //getters
    std::string getSpecialziare() const;
    int getNrPacientiTratati() const;
    int getNrOperatii() const;
    const std::map<int, Pacient>& getPacienti()const;

    //setters

    //operators
    Medic& operator=(const Medic &m);
    friend std::istream& operator>>(std::istream &in,  Medic &m);
    friend std::ostream& operator<<(std::ostream &out, const  Medic &m);

    //methods
    void adaugaPacient(const Pacient& p);
    void stergePacient(int id_pacient);
    template<typename T>
    void prescrieTratament(const Medicament<T>& med);

    //destructor
    ~Medic() override = default;

};

#endif //MEDIC_H
