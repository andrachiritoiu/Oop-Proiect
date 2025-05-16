#ifndef MEDICAMENTFACTORY_H
#define MEDICAMENTFACTORY_H
#include<memory>
#include<stdexcept>
#include<string>
#include "Medicament.h"

//design patern Factory(creational)
class MedicamentFactory {
  public:
    template<typename T>
    static std::shared_ptr<Medicament<T>> creeazaMedicament(const std::string &categorie, const std::string &forma);
};

template<typename T>
std::shared_ptr<Medicament<T>> MedicamentFactory :: creeazaMedicament(const std::string &categorie, const std::string &forma){
  if (categorie=="antibiotic") {
    if (forma=="pastila")return std::make_shared<Medicament<T>>("Amoxicilina",35,static_cast<T>("20mg"));
    else if (forma=="injectabil")return std::make_shared<Medicament<T>>("Augumentin",50,static_cast<T>("1doza"));
  }
  else if (categorie=="analgezic") {
    if (forma=="pastila")return std::make_shared<Medicament<T>>("Paracetamol",10,static_cast<T>(1));
    else if (forma=="sirop")return std::make_shared<Medicament<T>>("Panadol",30,static_cast<T>("1lingura"));
    else if (forma=="injectabil")return std::make_shared<Medicament<T>>("Algocalmin",20,static_cast<T>("1doza"));
  }
  else if (categorie=="antiinflamator") {
    if (forma=="pastila")return std::make_shared<Medicament<T>>("Ibuprofen",12,static_cast<T>(1));
    else if (forma=="crema")return std::make_shared<Medicament<T>>("Voltaren",45,static_cast<T>("1tub"));
  }

  throw std::invalid_argument("Combinatie necunoscuta de medicamente");
  }


#endif //MEDICAMENTFACTORY_H
