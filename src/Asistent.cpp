#include "Asistent.h"
#include "Pacient.h"
#include<iostream>

//constructors
Asistent::Asistent() : PersonalSpital() {
    this->sectie="";
    this->proceduri_efectuate={};
}
Asistent::Asistent(const std::string &nume, const std::string &prenume, const std::string &CNP, int salariu, int experienta,
        const std::string &program, const std::string &sectie, const std::vector<std::string> &proceduri_efectuate) : PersonalSpital(nume,
        prenume, CNP, salariu, experienta, program) {
    this->sectie=sectie;
    this->proceduri_efectuate=proceduri_efectuate;
}
//copy constructor
Asistent::Asistent(const Asistent &a): PersonalSpital(a) {
    this->sectie=a.sectie;
    this->proceduri_efectuate=a.proceduri_efectuate;
}

//getters
std::string Asistent::getSectie() const {
    return this->sectie;
}
std::vector<std::string> Asistent::getProceduri() const {
    return this->proceduri_efectuate;
}

//setters

//operators
Asistent& Asistent :: operator=(const Asistent &a) {
    if (this!=&a) {
        PersonalSpital::operator=(a);
        this->sectie=a.sectie;
        this->proceduri_efectuate=a.proceduri_efectuate;
    }
    return *this;
}
std::istream& operator>>(std::istream &in, Asistent &a) {
    in>>static_cast<PersonalSpital&>(a);
    std::cout<<"Sectie: ";
    in>>a.sectie;

    int nr_proceduri;
    std::cout<<"Numarul de proceduri : ";
    in>>nr_proceduri;
    std::string temp;
    std::getline(in,temp);//goleste buffer
    for (auto i=0;i<nr_proceduri;i++) {
        std::cout<<"Introduceti procedura "<<i+1<<" :";
        std::string procedura;
        in>>procedura;
        a.addProcedura(procedura);
    }
    return in;
}
std::ostream& operator<<(std::ostream &out,const Asistent &a) {
    out<<static_cast<const PersonalSpital&>(a);
    out<<"Sectie: "<<a.sectie<<"\n"
       <<"Proceduri efectuate: \n";
    int i=1;
    for (const auto &p:a.proceduri_efectuate){
        out<<" - Procedura "<<i<<": "<<p<<" \n";
        i++;
    }
    return out;
}

//methods
// void Asistent :: calclueazaBonus() const override {
//
// }
void Asistent :: addProcedura(const std::string &procedura) {
    this->proceduri_efectuate.push_back(procedura);
}
void Asistent :: efectueazaProcedura(Pacient *p, const std::string &procedura) {
    //*p - modificarea obiectului
    addProcedura(procedura);
    p->adaugaIstoric(procedura);
    std::cout<<"Procedură efectuată de asistentul " + getNume() + " " + getPrenume() + ": " + procedura;
}
template<typename T>
void Asistent::verificaStoc(const Medicament<T>& med) {
    std::cout<<"Verificare stoc:\n";
    std::cout<<"Cantitate in stoc: "<<med.getCantitate()<<"\n";
}
