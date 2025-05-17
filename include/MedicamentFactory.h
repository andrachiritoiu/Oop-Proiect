#ifndef MEDICAMENTFACTORY_H
#define MEDICAMENTFACTORY_H
#include<memory>
#include<stdexcept>
#include<string>
#include "Medicament.h"

//design pattern Factory(creational)
class MedicamentFactory {
  public:
    static std::shared_ptr<Medicament> creeazaMedicament(const std::string &categorie, const std::string &forma);
};

#endif //MEDICAMENTFACTORY_H
