#include "Meniu.h"
#include<iostream>

Meniu* Meniu::instanta=nullptr;

Meniu* Meniu :: getInstanta(){
    if(!instanta)
        instanta= new Meniu();
    return instanta;
}

void Meniu::ruleaza(){
  int op;
  do{
      std::cout<<"\n===== Sistem Management Spital =====\n";
      std::cout<<"1. Pacient\n";
      std::cout<<"2. Personal medical\n";
      std::cout<<"3. Iesire\n";
      std::cout<<"Alege optiune: ";
      std::cin>>op;

      switch (op) {
          case 1:
              ruleazaMeniuPacient();
            break;

          case 2:
              ruleazaMeniuPersonalMedical();
              break;
          case 3:
              std::cout<<"La revedere";
              break;
          default:
              std::cout<<"Optiune invalida\n";
              break;
      }
  }while(op!=3);

}

void Meniu::ruleazaMeniuPacient() {
    int op;
    do {
        std::cout<<"\n--- Meniu Pacient ---\n";
        std::cout<<"1. Inregistrare pacient\n";
        std::cout<<"2. Vizualizare istoric medical\n";
        std::cout<<"3. Solicitare externare\n";
        std::cout<<"4. Inapoi\n";
        std::cout<<"Alege: ";
        std::cin>>op;

        switch (op) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                std::cout<<"Optiune invalida\n";
                break;
        }
    }while (op!=4);

}

void Meniu::ruleazaMeniuPersonalMedical() {
    int op;

    do {
        std::cout<<"\n--- Meniu Personal Medical ---\n";
        std::cout<<"1. Lista pacienti activi\n";
        std::cout<<"2. Evaluare pacient\n";
        std::cout<<"3. Prescriere reteta\n";
        std::cout<<"4. Administrare tratament\n";
        std::cout<<"5. Inapoi\n";
        std::cout<<"Alege: ";
        std::cin>>op;

        switch (op) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                std::cout<<"Optiune invalida\n";
                break;
        }
    }while (op!=5);

}