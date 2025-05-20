#include "Medic.h"
#include "PersonalSpital.h"
#include<iostream>

//constructors
Medic::Medic() : PersonalSpital() {
    this->specializare="";
    this->numar_pacienti_tratati=0;
    this->numar_operatii=0;
    this->pacienti={};
}
Medic::Medic(const std::string &nume, const std::string &prenume, const std::string &CNP, int salariu, int experienta,
       const std::map<std::string, std::vector<std::pair<int,int>>> &program, const std::string &specializare, int numar_pacienti_tratati, int numar_operatii, std::map<int, std::shared_ptr<Pacient>> pacienti) : PersonalSpital(nume,
       prenume, CNP, salariu, experienta, program) {
    this->specializare=specializare;
    this->numar_pacienti_tratati=numar_pacienti_tratati;
    this->numar_operatii=numar_operatii;
    this->pacienti=pacienti;
}
//copy constructor
Medic::Medic(const Medic &m): PersonalSpital(m) {
    this->specializare=m.specializare;
    this->numar_pacienti_tratati=m.numar_pacienti_tratati;
    this->numar_operatii=m.numar_operatii;
    this->pacienti=m.pacienti;
}

//getters
std::string Medic :: getSpecializare() const {
    return this->specializare;
}
int Medic :: getNrPacientiTratati() const {
    return this->numar_pacienti_tratati;
}
int Medic :: getNrOperatii() const {
    return this->numar_operatii;
}
//ofera acces doar la citirea listei
const std::map<int, std::shared_ptr<Pacient>> Medic :: getPacienti()const {
    return this->pacienti;
}

//setters

//operators
Medic& Medic::operator=(const Medic &m) {
    if (this!=&m) {
        PersonalSpital::operator=(m);
        this->specializare=m.specializare;
        this->numar_pacienti_tratati=m.numar_pacienti_tratati;
        this->numar_operatii=m.numar_operatii;
        this->pacienti=m.pacienti;
    }
    return *this;
}
std::istream& operator>>(std::istream &in,  Medic &m) {
    in>>static_cast<PersonalSpital&>(m);
    std::cout<<"Specializare: ";
    in>>m.specializare;
    std::cout<<"Numar pacienti tratati: ";
    in>>m.numar_pacienti_tratati;
    std::cout<<"Numar operatii: ";
    in>>m.numar_operatii;

    // int nr_pacienti;
    // std::cout<<"Introduceti numarul de pacienti: ";
    // in>>nr_pacienti;
    // std::string temp;
    // std::getline(in,temp);//sa golsesca bufferul de nl
    // for (int i=0;i<nr_pacienti;i++) {
    //     std::cout<<"Cititi pacientul " << i + 1 << ":\n";
    //     Pacient p;
    //     in>>p;
    //     m.adaugaPacient(p);
    //}

    return in;

}
std::ostream& operator<<(std::ostream &out, const  Medic &m) {
    out<<static_cast<const PersonalSpital&>(m);
    out<<"Specializare: "<< m.specializare<< "\n";
    out<<"Numar pacienti tratati: "<< m.numar_pacienti_tratati<< "\n";
    out<<"Numar operatii: "<< m.numar_operatii<< "\n";
    out<<"Pacienti:\n";

   // for (const auto& [id,pacient]: m.pacienti) {
   //     out<<"Pacient ID"<< id<<":\n"<<pacient<<"\n";
   // }

    return out;
}

//methods
void Medic::adaugaPacient(std::shared_ptr<Pacient> p) {
    this->pacienti[p->getId()]=p;
}
void Medic::stergePacient(int id_pacient) {
    this->pacienti.erase(id_pacient);
}
void Medic :: calculeazaBonus() {
    int bonus=this->salariu*0.1*this->experienta/10;
    std::cout<<"Bonus pentru medicul "<<this->nume<< " " <<this->prenume<<": "<<bonus<<" RON\n";
    this->salariu+=bonus;
    std::cout<<"Salariu actualizat: "<<salariu<<" RON\n";
}
