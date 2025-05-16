#include "MedicamentFactory.h"

std::shared_ptr<Medicament> MedicamentFactory :: creeazaMedicament(const std::string &categorie, const std::string &forma){
    if (categorie=="antibiotic") {
        if (forma=="pastila")return std::make_shared<Medicament>("Amoxicilina",35,"20mg");
        else if (forma=="injectabil")return std::make_shared<Medicament>("Augumentin",50,"1doza");
    }
    else if (categorie=="analgezic") {
        if (forma=="pastila")return std::make_shared<Medicament>("Paracetamol",10,"1");
        else if (forma=="sirop")return std::make_shared<Medicament>("Panadol",30,"1lingura");
        else if (forma=="injectabil")return std::make_shared<Medicament>("Algocalmin",20,"1doza");
    }
    else if (categorie=="antiinflamator") {
        if (forma=="pastila")return std::make_shared<Medicament>("Ibuprofen",12,"1");
        else if (forma=="crema")return std::make_shared<Medicament>("Voltaren",45,"1tub");
    }

    throw std::invalid_argument("Combinatie necunoscuta de medicamente");
}