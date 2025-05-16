#ifndef TRATAMENTMANAGER_H
#define TRATAMENTMANAGER_H
#include<iostream>
#include<memory>
#include "Pacient.h"
#include "MedicamentFactory.h"

class TratamentManager{
  public:
    template<typename T>
    static void prescrieTratament(std::vector<std::shared_ptr<Pacient>>&pacienti);
};

template<typename T>
void TratamentManager :: prescrieTratament(std::vector<std::shared_ptr<Pacient>>&pacienti){
    if (pacienti.empty()) {
        std::cout << "Nu exista pacienti inregistrati.\n";
        return;
    }
    else {
        int idPacient;
        std::cout<<"Introduceti ID-ul pacientului: ";
        std::cin>>idPacient;

        bool gasit=false;
        for (auto &p:pacienti) {
            if (p->getId()==idPacient) {
                gasit=true;
                std::string categorie, forma;

                std::cout<<"Categorie(antibiotic / analgezic / antiinflamator): ";
                std::cin>>categorie;
                std::cout<<"Forma (pastila / injectabil / etc): ";
                std::cin>>forma;

                auto medicament=MedicamentFactory::creeazaMedicament<T>(categorie,forma);

                std::cout<<"Reteta adaugata cu succes.\n";
                return;
            }
        }
        if (!gasit) {
            std::cout<<"Pacient inexistent.\n";
        }
    }
}

#endif //TRATAMENTMANAGER_H