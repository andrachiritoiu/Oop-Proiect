#include "Programare.h"

//constructors
Programare::Programare(const std::string& data, int ora, const std::shared_ptr<Pacient> &pacient, const std::shared_ptr<Medic> &medic){
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
const std::shared_ptr<Pacient>& Programare::getPacient() const {
  return this->pacient;
}
const std::shared_ptr<Medic>& Programare::getMedic() const {
  return this->medic;
}

//setters
void Programare::setData(const std::string &data) {
  this->data=data;
}
void Programare::setOra(int ora) {
  this->ora=ora;
}
void Programare::setPacient(const std::shared_ptr<Pacient> &pacient) {
  this->pacient=pacient;
}
void Programare::setMedic(const std::shared_ptr<Medic> &med) {
  this->medic=medic;
}