#include "Programare.h"

//constructors
Programare::Programare(const std::string& data, int ora, const Pacient &pacient, const Medic &medic){
  this->data = data;
  this->ora = ora;
  this->pacient = pacient;
  this->medic = medic;
}

//getters
std::string Programare::getData() const {
  return this->data;
}
int Programare::getOra() const {
  return this->ora;
}
const Pacient&Programare::getPacient() const {
  return this->pacient;
}
const Medic&Programare::getMedic() const {
  return this->medic;
}

//setters
void Programare::setData(const std::string &data) {
  this->data=data;
}
void Programare::setOra(int ora) {
  this->ora=ora;
}
void Programare::setPacient(const Pacient &pacient) {
  this->pacient=pacient;
}
void Programare::setMedic(const Medic &med) {
  this->medic=medic;
}