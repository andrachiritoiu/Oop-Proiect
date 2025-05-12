#include "Meniu.h"
#include "Pacient.h"
#include<iostream>
#include<vector>
// #include <windows.h>
Meniu* Meniu::instanta=nullptr;

Meniu* Meniu :: getInstanta(){
    if(!instanta)
        instanta= new Meniu();
    return instanta;
}

void Meniu::ruleaza(){
    int op;

    do{
        // system("cls");
        std::cout<<"\n---- Sistem Management Spital ----\n";
        std::cout<<"1. Acces Pacient\n";
        std::cout<<"2. Acces Personal Medical\n";
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

                default: {
                    std::cout<<"Optiune invalida\n";
                    break;
                }
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

                case 2: {
                    //programare noua
                    break;
                }

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

                case 4: {
                    //deconectare
                    autentificat=false;
                    idPacientCurent=-1;

                    std::cout<<"Deconectare reusita.\n";
                    break;
                }

                default: {
                    std::cout<<"Optiune invalida\n";
                    break;
                }
            }
        }
    }while (optiune!=4);
}

void Meniu::ruleazaMeniuPersonalMedical() {
    int optiune_tip;

    do {
        std::cout<<"\n---- Meniu Personal Medical ----\n";
        std::cout<<"1. Acces Medic\n";
        std::cout<<"2. Acces Asistent\n";
        std::cout<<"3. Inapoi\n";
        std::cout<<"Alege: ";
        std::cin>>optiune_tip;

        switch (optiune_tip) {
            case 1:
                //medic
                ruleazaMeniuMedic();
                break;

            case 2:
                //asistent
                ruleazaMeniuAsistent();
                break;

            case 3:
                break;

            default:
                std::cout<<"Optiune invalida\n";
                break;
        }
    }while (optiune_tip!=3);
}

void Meniu::ruleazaMeniuMedic() {
    int op;
    int idMedicCurent=-1;
    bool autentificat=false;

    do {
        if (!autentificat) {
            std::cout<<"\n---- Meniu Medic ----\n";
            std::cout<<"1. Inregistrare Medic nou\n";
            std::cout<<"2. Autentificare Medic existent\n";
            std::cout<<"3. Inapoi\n";
            std::cout<<"Alege: ";
            std::cin>>op;

            switch (op) {
                case 1: {
                    //medic nou
                    Medic medic;
                    std::cin>>medic;
                    idMedicCurent=medic.getId();
                    this->medici.push_back(medic);
                    autentificat=true;
                    std::cout<<"Medic inregistrat cu ID: "<<idMedicCurent<<"\n";
                    break;
                }

                case 2: {
                    //medic existent
                    int id;
                    std::cout<<"Introdu ID medic: ";
                    std::cin>>id;

                    bool gasit=false;
                    for (const auto &m:this->medici) {
                        if (m.getId()==id) {
                            gasit=true;
                            idMedicCurent=id;
                            autentificat=true;
                            std::cout<<"Autentificare reusita. Bine ai venit!\n";
                            break;
                        }
                    }

                    if (!gasit) {
                            std::cout<<"Medic inexistent.\n";
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
            //este conectat
            int opt;
            std::cout<<"\n---- Meniu Actiuni Medic (ID: "<<idMedicCurent<<") ----\n";
            std::cout<<"1. Vizualizare pacienti activi\n";
            std::cout<<"2. Evaluare pacient\n";
            std::cout<<"3. Prescriere reteta\n";
            std::cout<<"4. Programare operatie\n";
            std::cout<<"5. Externare pacient\n";
            std::cout<<"6. Deconectare\n";
            std::cout<<"Alege: ";
            std::cin>>opt;

            switch (opt) {
                case 1: {
                    //pacienti activi
                    if (pacienti.empty())
                        std::cout<<"Nu exista pacienti inregistrati.\n";
                    else {
                        for (const auto &p:pacienti) {
                            std::cout<<p<<"\n";
                        }
                    }
                    break;
                }

                case 2: {
                    //evaluare pacient
                    if (pacienti.empty()) {
                        std::cout << "Nu exista pacienti inregistrati.\n";
                    }
                    else {
                        int id;
                        std::cout<<"Introduceti ID-ul pacientului: ";
                        std::cin>>id;

                        bool gasit=false;
                        for (auto &p:pacienti) {
                            if (p.getId()==id) {
                                gasit=true;
                                std::string evaluare;
                                std::cout<<"Introduceti evaluarea: ";
                                std::string temp;
                                std::getline(std::cin,temp);//sa golsesca bufferul de nl
                                std::getline(std::cin, evaluare);
                                p.adaugaIstoric("Evaluarea: "+evaluare);
                                std::cout << "Evaluare adaugata cu succes.\n";
                                break;
                            }
                        }
                        if (!gasit) {
                            std::cout<<"Pacient inexistent.\n";
                        }
                    }
                    break;
                    }

                case 3: {
                    //prescriere tratament
                    if (pacienti.empty()) {
                        std::cout << "Nu exista pacienti inregistrati.\n";
                    }
                    else {
                        int idPacient;
                        std::cout<<"Introduceti ID-ul pacientului: ";
                        std::cin>>idPacient;

                        bool gasit=false;
                        for (auto &p:pacienti) {
                            if (p.getId()==idPacient) {
                                gasit=true;
                                std::string reteta;
                                std::cout<<"Introduceti medicamente: ";
                                std::string temp;
                                std::getline(std::cin,temp);
                                std::getline(std::cin, reteta);
                                p.adaugaIstoric("Reteta: "+reteta);
                                std::cout << "Reteta adaugata cu succes.\n";
                                break;
                            }
                        }
                        if (!gasit) {
                            std::cout<<"Pacient inexistent.\n";
                        }
                    }
                    break;
                }

                case 4: {
                    //programare operatie
                    break;
                }

                case 5: {
                    //externare pacient
                    if (pacienti.empty()) {
                        std::cout << "Nu exista pacienti inregistrati.\n";
                    }
                    else {
                        int idPacient;
                        std::cout<<"Introduceti ID-ul pacientului: ";
                        std::cin>>idPacient;

                        bool gasit=false;
                        for (auto &p:pacienti) {
                            if (p.getId()==idPacient) {
                                gasit=true;
                                std::string externare;
                                std::cout<<"Introduceti data externarii: ";
                                std::string temp;
                                std::getline(std::cin,temp);
                                std::getline(std::cin, externare);
                                p.setData_externare(externare);
                                p.adaugaIstoric("Externare programata: "+externare);
                                std::cout << "Externare programata cu succes.\n";
                                break;
                            }
                        }
                        if (!gasit) {
                            std::cout<<"Pacient inexistent.\n";
                        }
                    }
                    break;
                }

                case 6: {
                    //deconectare
                    idMedicCurent=-1;
                    autentificat=false;
                    break;
                }

                default: {
                    std::cout<<"Optiune invalida\n";
                    break;
                }
            }
        }
    }while (op!=3);
}

void Meniu::ruleazaMeniuAsistent() {
    int op;
    int idAsistentCurent=-1;
    bool autentificat=false;

    do {
        if (!autentificat) {
            std::cout<<"\n---- Meniu Asistent ----\n";
            std::cout<<"1. Inregistrare Asistent nou\n";
            std::cout<<"2. Autentificare Asistent existent\n";
            std::cout<<"3. Inapoi\n";
            std::cout<<"Alege: ";
            std::cin>>op;

            switch (op) {
                case 1: {
                    //asistent nou
                    Asistent asistent;
                    std::cin>>asistent;
                    idAsistentCurent=asistent.getId();
                    this->asistenti.push_back(asistent);
                    autentificat=true;
                    std::cout<<"Asistent inregistrat cu ID: "<<idAsistentCurent<<"\n";
                    break;
                }

                case 2: {
                    //asistent existent
                    int id;
                    std::cout<<"Introdu ID asistent: ";
                    std::cin>>id;

                    bool gasit=false;
                    for (const auto &m:this->asistenti) {
                        if (m.getId()==id) {
                            gasit=true;
                            idAsistentCurent=id;
                            autentificat=true;
                            std::cout<<"Autentificare reusita. Bine ai venit!\n";
                            break;
                        }
                    }

                    if (!gasit) {
                        std::cout<<"Asistent inexistent.\n";
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
            std::cout<<"\n---- Meniu Asistent (ID: " << idAsistentCurent<< ") ----\n";
            std::cout<<"1. Vizualizare pacienti activi\n";
            std::cout<<"2. Administrare tratament\n";
            std::cout<<"3. Verificare stoc medicamente.\n";
            std::cout<<"4. Deconectare\n";
            std::cout<<"Alege: ";
            std::cin >> op;

            switch (op) {
                case 1:

                    //vizualizare pacienti
                    if (pacienti.empty())
                        std::cout<<"Nu exista pacienti inregistrati.\n";
                    else {
                        for (const auto &p:pacienti) {
                            std::cout<<p<<"\n";
                        }
                    }
                    break;

                case 2:
                    //administrare tratament
                    std::cout<<"Administrare tratament";
                    break;

                case 3:
                    //verificare stoc medicamente
                    std::cout<<"Verificare stoc medicamnete";
                    break;

                case 4:
                    //deconectare
                    idAsistentCurent=-1;
                    autentificat=false;
                    break;

                default: {
                    std::cout<<"Optiune invalida\n";
                    break;
                }
            }
        }
    }while (op!=3);
}
