#include "Persoana.h"
#include<stdexcept>
#include<iostream>

//constructors
Persoana::Persoana(const std::string &nume, const std::string &prenume, const std::string &CNP) {
    if (CNP.length() != 13) {
        //std::invalid_argument - exceptie din biblioteca standard C++
        throw std::invalid_argument("CNP trebuie sa aiba exact 13 cifre");
    }
    for (const char c: CNP)
        {if (!isdigit(c)) {
            throw std::invalid_argument("CNP trebuie sa contina doar cifre");
        }
    }

    this->nume=nume;
    this->prenume=prenume;
    this->CNP=CNP;
}

//copy constructor
Persoana::Persoana(const Persoana &p) {
    this->nume=p.nume;
    this->prenume=p.prenume;
    this->CNP=p.CNP;
}

//getters
std::string Persoana :: getNume() const {
    return this->nume;
}
std::string Persoana :: getPrenume() const {
    return this->prenume;
}
std::string Persoana :: getCNP() const {
    return this->CNP;
}


//setters
void Persoana :: setNume(const std::string &nume) {
    this->nume=nume;
}
void Persoana :: setPrenume(const std::string &prenume) {
    this->prenume=prenume;
}
void Persoana :: setCNP(const std::string &CNP) {
    this->CNP=CNP;
}

//operators
Persoana& Persoana::operator= (const Persoana &p) {
    if (this != &p) {
        this->nume=p.nume;
        this->prenume=p.prenume;
        this->CNP=p.CNP;
    }
    return *this;
}
bool Persoana::operator== (const Persoana &p) const {
    return this->CNP==p.CNP;
}
std::istream& operator>>(std::istream &in, Persoana &p) {
    std::cout<<"Numele: ";
    in>>p.nume;
    std::cout<<"Prenumele: ";
    in>>p.prenume;
    std::cout<<"CNP: ";
    in>>p.CNP;
    return in;
}
std::ostream& operator<<(std::ostream &out, const Persoana &p) {
    out <<"Nume "<<p.nume<<"\n"
        <<"Prenume "<<p.prenume<<"\n"
        <<"CNP "<<p.CNP<<"\n";
    return out;
}



