#include "Medicament.h"

//constructors
Medicament::Medicament(const std::string& nume, float pret,const  std::string &cantitate) {
    this->nume=nume;
    this->pret=pret;
    this->cantitate=cantitate;
}

//getters
std::string Medicament::getNume()const{
    return this->nume;
}
float Medicament::getPret()const{
    return this->pret;
}
std::string Medicament::getCantitate()const{
    return this->cantitate;
}

//operators
std::istream& operator>>(std::istream &in, Medicament &m) {
    std::cout<<"Introduceti numele medicamentului: ";
    in>>m.nume;
    std::cout<< "Introduceti pretul medicamentului: ";
    in>>m.pret;
    std::cout<<"Introduceti cantitatea medicamentului: ";
    in>>m.cantitate;

    return in;
}
std::ostream& operator<<(std::ostream &out, const Medicament &m) {
    out<<"Medicament: "<< m.getNume() << "\n"
       <<"Pret: "<<m.getPret()<<"\n"
       <<"Cantitate: "<<m.getCantitate()<<"\n";
    return out;
}

//methods


