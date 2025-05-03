#include "Pacient.h"
#include<iostream>

//constructors
Pacient :: Pacient (const std::string &nume, const std::string &prenume, const std::string &CNP, const std::string &diagnostic,
        int severitate_boala, const std::string &data_internare, const std::string &data_externare, bool asigurat):
        Persoana(nume, prenume, CNP){
  this->id_pacient=next_id++;
  this->diagnostic=diagnostic;
  this->severitate_boala=severitate_boala;
  this->data_internare=data_internare;
  this->data_externare=data_externare;
  this->asigurat=asigurat;
}
//copy constructor
Pacient::Pacient(const Pacient &p):Persoana(p){
    this->id_pacient=next_id++;
    this->diagnostic=p.diagnostic;
    this->severitate_boala=p.severitate_boala;
    this->data_internare=p.data_internare;
    this->data_externare=p.data_externare;
    this->asigurat=p.asigurat;
}

//getters
int Pacient :: getId() const {
    return this->id_pacient;
}
std::string Pacient :: getDiagnostic() const {
    return this->diagnostic;
}
int Pacient :: getSeveritatBoala() const {
    return this->severitate_boala;
}
std::string Pacient :: getData_internare() const {
    return this->data_internare;
}
std::string Pacient :: getData_externare() const {
    return this->data_externare;
}
bool Pacient :: getAsigurat() const {
    return this->asigurat;
}


//setters
void Pacient :: setDiagnostic(const std::string &diagnostic) {
    this->diagnostic=diagnostic;
}
void Pacient :: setSeveritate(int severitate) {
    this->severitate_boala=severitate;
}
void Pacient :: setData_internare(const std::string &data_internare) {
    this->data_internare=data_internare;
}
void Pacient :: setData_externare(const std::string &data_externare) {
    this->data_externare=data_externare;
}

//operators
Pacient& Pacient :: operator=(const Pacient &p) {
    if (this!=&p) {
        Persoana::operator=(p);
        id_pacient = p.id_pacient;
        diagnostic = p.diagnostic;
        severitate_boala = p.severitate_boala;
        data_internare = p.data_internare;
        data_externare = p.data_externare;
        asigurat = p.asigurat;
    }
    return *this;
}
std::istream& operator>>(std::istream &in, Pacient &p) {
    //static_cast - converteste
    in>>static_cast<Persoana&>(p); //upcasting
    std::cout<<"Diagnostic: ";
    in>>p.diagnostic;
    std::cout<<"Severitate boala: ";
    in>>p.severitate_boala;
    std::cout<<"Data internare: ";
    in>>p.data_internare;
    std::cout<<"Data externare: ";
    in>>p.data_externare;
    std::cout<<"Asigurat: ";
    in>>p.asigurat;
    return in;
}
std::ostream& operator<<(std::ostream &out, const Pacient &p) {
    out<<static_cast<const Persoana&>(p);
    out<<"Id pacient: "<<p.id_pacient<<"\n"
       <<"Diagnostic: "<<p.diagnostic<<"\n"
       <<"Severitate boala: "<<p.severitate_boala<<"\n"
       <<"Data internare: "<<p.data_internare<<"\n"
       <<"Data externare: "<<p.data_externare<<"\n"
       <<"Asigurat: "<<(p.asigurat?"Da" : "Nu")<<"\n"; //accepta 1 si 0
    return out;
}

//methods


