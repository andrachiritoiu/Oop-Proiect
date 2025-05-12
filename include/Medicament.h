#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include<string>
#include<iostream>

//in .h
template<typename T>
class Medicament {
private:
  std::string nume;
  float pret{};
  T cantitate;

public:
  //constructors
  Medicament()=default;
  Medicament(const std::string& nume, float pret, T cantitate);

  //getters
  std::string getNume();
  float getPret();
  T getCantitate();

  //setters

  //methods

  //destructor
  ~Medicament()=default;
};


//constructor
template<typename T>
Medicament<T>::Medicament(const std::string& nume, float pret, T cantitate) {
  this->nume=nume;
  this->pret=pret;
  this->cantitate=cantitate;
}

//getters
template<typename T>
std::string Medicament<T>::getNume(){
  return this->nume;
}
template<typename T>
float Medicament<T>::getPret(){
  return this->pret;
}
template<typename T>
T Medicament<T>::getCantitate(){
  return this->cantitate;
}

//operators
template<typename T>
std::istream& operator>>(std::istream &in, Medicament<T> &m) {
  std::cout<<"Introduceti numele medicamentului: ";
  in>>m.nume;
  std::cout<< "Introduceti pretul medicamentului: ";
  in>>m.pret;
  std::cout<<"Introduceti cantitatea medicamentului: ";
  in>>m.cantitate;

  return in;
}
template<typename T>
std::ostream& operator<<(std::ostream &out, const Medicament<T> &m) {
  out<<"Medicament: "<< m.getNume() << "\n"
     <<"Pret: "<<m.getPret()<<"\n"
     <<"Cantitate: "<<m.getCantitate()<<"\n";
  return out;
}

//methods

#endif //MEDICAMENT_H
