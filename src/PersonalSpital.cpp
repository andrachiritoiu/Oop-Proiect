#include "PersonalSpital.h"
#include<iostream>

int PersonalSpital::next_id=1;
int PersonalSpital::salariu_mediu=0;

//constructors
PersonalSpital::PersonalSpital():Persoana() {
    this->id_angajat=next_id++;
    this->salariu=0;
    this->experienta=0;
    this->program="";
}
PersonalSpital::PersonalSpital(const std::string &nume, const std::string &prenume, const std::string &CNP, int salariu,
    int experienta, const std::string &program) : Persoana(nume, prenume, CNP){
    this->id_angajat=next_id++;
    this->salariu=salariu;
    this->experienta=experienta;
    this->program=program;
    salariu_mediu=(salariu_mediu*(next_id-1)+this->salariu)/next_id;
}
//copy constructor
PersonalSpital::PersonalSpital(const PersonalSpital &p): Persoana(p){
    this->id_angajat=next_id++;
    this->salariu=p.salariu;
    this->experienta=p.experienta;
    this->program=p.program;
    salariu_mediu=(salariu_mediu*(next_id-1)+this->salariu)/next_id;
}

//getters
int PersonalSpital :: getId() const {
    return this->id_angajat;
}
int PersonalSpital :: getSalariu() const {
    return this->salariu;
}
int PersonalSpital :: getExperienta() const {
    return this->experienta;
}
std::string PersonalSpital :: getProgram() const {
    return this->program;
}

//setters
void PersonalSpital :: setSalariu(int salariu) {
    salariu_mediu=(salariu_mediu*(next_id-1)-this->salariu+salariu)/next_id;
    this->salariu=salariu;
}
void PersonalSpital :: setProgram(const std::string &program) {
    this->program=program;
}

//operators
PersonalSpital& PersonalSpital :: operator=(const PersonalSpital &p) {
    if (this!=&p) {
        Persoana::operator=(p);
        this->salariu=p.salariu;
        this->experienta=p.experienta;
        this->program=p.program;
    }
    return *this;
}
std::istream& operator>>(std::istream &in, PersonalSpital &p) {
    //static_cast - converteste
    in>>static_cast<Persoana&>(p); //upcasting
    std::cout<<"Salariu: ";
    in>>p.salariu;
    std::cout<<"Experienta: ";
    in>>p.experienta;
    std::cout<<"Program: ";
    in>>p.program;
    return in;
}
std::ostream& operator<<(std::ostream &out, const PersonalSpital &p) {
    out<<static_cast<const Persoana&>(p);
    out<<"Id angajat: "<<p.id_angajat<<"\n"
       <<"Salariu: "<<p.salariu<<"\n"
       <<"Experienta: "<<p.experienta<<"\n"
       <<"Program: "<<p.program<<"\n";
    return out;
}

//methods
int PersonalSpital :: calculeazaSalariuMediu() {
    return salariu_mediu;
}