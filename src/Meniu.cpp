#include "Meniu.h"
#include "Pacient.h"
#include<iostream>
#include<vector>

Meniu* Meniu::instanta=nullptr;

Meniu* Meniu :: getInstanta(){
    if(!instanta)
        instanta= new Meniu();
    return instanta;
}

void Meniu::ruleaza(){
    int op;

    do{
        std::cout<<"\n---- Sistem Management Spital ----\n";
        std::cout<<"1. Acces Pacient\n";
        std::cout<<"2. Acces Personal medical\n";
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
    int optiune;
    int idPacientCurent=-1;
    bool autentificat=false;

    do {
        if (!autentificat) {
            std::cout<<"\n---- Meniu Pacient ----\n";
            std::cout<<"1. Inregistrare pacient nou\n";
            std::cout<<"2. Autentificare pacient existent\n";
            std::cout<<"3. Inapoi\n";
            std::cout<<"Alege: ";
            std::cin>>optiune;

            switch (optiune) {
                case 1: {
                    //pacient nou
                    Pacient pacient;
                    std::cin>>pacient;
                    idPacientCurent=pacient.getId();
                    this->pacienti.push_back(pacient);

                    for (const auto& p : pacienti) {
                        std::cout << p << std::endl;
                    }

                    autentificat=true;
                    std::cout<<"Pacient inregistrat cu ID: "<<idPacientCurent<<"\n";
                    break;

                }

                case 2:{
                    //pacient existent
                    int id;
                    std::cout<<"Introdu ID pacient: ";
                    std::cin>>id;

                    bool gasit=false;
                    for (const auto &p:this->pacienti) {
                       if (p.getId()==id) {
                        gasit=true;
                        idPacientCurent=id;
                        autentificat=true;
                        std::cout<<"Autentificare reusita. Bine ai venit!\n";
                        break;
                        }
                    }

                   if (!gasit) {
                    std::cout<<"Pacient inexistent.\n";
                }
                break;
            }

                case 3:
                    break;

                default:
                    std::cout<<"Optiune invalida\n";
                    break;
            }
        }

        else {
            //pacient autentificat
            std::cout << "\n---- Meniu Pacient (ID: " << idPacientCurent << ") ----\n";
            std::cout << "1. Vizualizare istoric medical\n";
            std::cout << "2. Programare noua\n";
            std::cout << "3. Solicitare externare\n";
            std::cout << "4. Deconectare\n";
            std::cout << "Alege: ";
            std::cin >> optiune;

            switch (optiune) {
                case 1:{
                    //vizualizare istoric medical
                    bool gasit=false;

                    for (const auto &p:this->pacienti) {
                        if (p.getId()==idPacientCurent) {
                            gasit=true;
                            if (p.getIstoricMedical().empty()){
                                std::cout<<"Nu exista proceduri in istoric.\n";
                            }
                            else {
                                std::cout<<"Istoric medical: ";
                                for (const auto &proced:p.getIstoricMedical())
                                    std::cout<<"-"<<proced<<"\n";
                            }
                            break;
                        }

                    }
                    if (!gasit) {
                        std::cout<<"ID pacient invalid.\n";
                        autentificat=false;
                    }
                    break;
                }

                case 2:
                    //programare noua
                    break;

                case 3:{
                    //solicitare externare
                    bool gasit=false;
                    for (auto &p:this->pacienti) {
                        if (p.getId()==idPacientCurent) {
                            gasit=true;
                            std::string data;
                            std::cout<<"Introdu data externarii: ";
                            std::cin>>data;
                            p.setData_externare(data);
                            std::cout<<"Cerere externare inregistrata.\n";
                            break;
                        }
                    }

                    if (!gasit) std::cout<<"Pacientul nu a fost gasit.\n";
                    break;
                }

                case 4:
                    //deconectare
                    autentificat=false;
                    idPacientCurent=-1;

                    std::cout<<"Deconectare reusita.\n";
                    break;

                default:
                    std::cout<<"Optiune invalida\n";
                    break;
            }
        }
    }while (optiune!=4);
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