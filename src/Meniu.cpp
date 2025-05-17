#include "Meniu.h"
#include "Pacient.h"
#include "Medicament.h"
#include "MedicamentFactory.h"
#include "Reteta.h"
#include<iostream>
#include<vector>
#include<memory>

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
                    auto pacient=std::make_shared<Pacient>();
                    //*pacient-referrinta la obiectul real
                    std::cin>>*pacient;
                    idPacientCurent=pacient->getId();
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
                       if (p->getId()==id) {
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
            std::cout << "4. Vizualizare retete\n";
            std::cout << "5. Deconectare\n";
            std::cout << "Alege: ";
            std::cin >> optiune;

            switch (optiune) {
                case 1:{
                    //vizualizare istoric medical
                    bool gasit=false;

                    for (const auto &p:this->pacienti) {
                        if (p->getId()==idPacientCurent) {
                            gasit=true;
                            if (p->getIstoricMedical().empty()){
                                std::cout<<"Nu exista proceduri in istoric.\n";
                            }
                            else {
                                std::cout<<"Istoric medical: ";
                                for (const auto &proced:p->getIstoricMedical())
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
                    std::string specializare;
                    std::cout<<"Introduceti specializarea dorita: ";
                    std::cin>>specializare;
                    std::vector<std::shared_ptr<Medic>>medici_specializare;

                    for (const auto &medic:this->medici) {
                        if (medic->getSpecializare() == specializare)
                            medici_specializare.push_back(medic);
                    }

                    if (medici_specializare.empty()) {
                        std::cout<<"Nu exista medici cu specializarea aleasa.\n";
                        break;
                    }

                    std::cout<<"Medici disponibili: \n";
                    for (auto i=0;i<medici_specializare.size();i++) {
                        std::cout<<i+1<<"."<<medici_specializare[i]->getNume()<<" "<<medici_specializare[i]->getPrenume()<<"\n";
                    }

                    int index;
                    std::cout<<"Alege un medic(index): ";
                    std::cin>>index;

                    if(index<1 || index>medici_specializare.size()){
                        std::cout<<"Index invalid.\n";
                        break;
                    }

                    std::shared_ptr<Medic> medic_selectat=medici_specializare[index-1];

                    std::cout<<"Zile disponibile: \n";
                    for (const auto &zi:medic_selectat->getProgram()) {
                        std::cout<<zi.first<<"\n";
                    }

                    std::string zi_aleasa;
                    std::cout<<"alege o zi din cele disponibile: ";
                    std::cin>>zi_aleasa;

                    bool gasit=false;
                    for (const auto &zi:medic_selectat->getProgram()) {
                        if (zi.first==zi_aleasa)gasit=true;
                    }
                    if (gasit==false) {
                        std::cout<<"Zi invalida! Medicul nu lucreaza in acea zi.\n";
                        break;
                    }

                    std::cout<<"Intervale disponibile in "<<zi_aleasa<<": ";
                    for (auto interval:medic_selectat->getProgram()[zi_aleasa])
                        std::cout<<interval.first<<":00 - "<<interval.second<<":00 \n";

                    int ora_start, ora_sfarsit;
                    std::cout<<"Introdu ora de inceput: ";
                    std::cin>>ora_start;
                    std::cout<<"Introdu ora de sfarsit: ";
                    std::cin>>ora_sfarsit;

                    bool interval_valid=false;
                    for (const auto &interval:medic_selectat->getProgram()[zi_aleasa]) {
                        if (ora_start>=interval.first && ora_sfarsit<=interval.second)
                            interval_valid=true;
                    }
                    if (!interval_valid) {
                        std::cout<<"Interval invalid. Nu se incadreaza in programul medicului.\n";
                        break;
                    }

                    std::shared_ptr<Pacient>pacient_curent=nullptr;
                    for (const auto &p:pacienti) {
                        if (p->getId()==idPacientCurent)
                            pacient_curent=p;
                    }

                    Programare prog(zi_aleasa, ora_start, ora_sfarsit,pacient_curent, medic_selectat);

                    if(gestiuneProgramari.adaugaProgramare(prog)==true) {
                        std::cout<<"Programare adaugata cu succes!\n";
                    }
                    else{
                        std::cout<<"Programarea nu a putut fi efectuata.\n";
                    }

                    break;
            }

                case 3:{
                    //solicitare externare
                    bool gasit=false;
                    for (auto &p:this->pacienti) {
                        if (p->getId()==idPacientCurent) {
                            gasit=true;
                            std::string data;
                            std::cout<<"Introdu data externarii: ";
                            std::cin>>data;
                            p->setData_externare(data);
                            std::cout<<"Cerere externare inregistrata.\n";
                            break;
                        }
                    }

                    if (!gasit) std::cout<<"Pacientul nu a fost gasit.\n";
                    break;
                }

                case 4: {
                    //retete
                    bool gasit=false;
                    for (auto &p:this->pacienti) {
                        if (p->getId()==idPacientCurent) {
                            gasit=true;
                            for (const auto &reteta_var:p->getRetete()) {
                                //std::visit - este din std::variant si apeleaza functia corecta pentru tipul actual tinut de variant
                                std::visit([](const auto &reteta) {
                                    std::cout<<reteta<<"\n";
                                },reteta_var);
                            }
                            break;
                        }
                    }

                    if (!gasit) std::cout<<"Pacientul nu a fost gasit.\n";
                    break;
                }

                case 5: {
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
    }while (autentificat || optiune!=3);
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
                    auto medic=std::make_shared<Medic>();
                    std::cin>>*medic;
                    idMedicCurent=medic->getId();
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
                        if (m->getId()==id) {
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
            std::cout<<"3. Prescriere tratament\n";
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
                            std::cout<<*p<<"\n";
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
                            if (p->getId()==id) {
                                gasit=true;
                                std::string evaluare;
                                std::cout<<"Introduceti evaluarea: ";
                                std::string temp;
                                std::getline(std::cin,temp);//sa golsesca bufferul de nl
                                std::getline(std::cin, evaluare);
                                p->adaugaIstoric("Evaluarea: "+evaluare);
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
                            if (p->getId()==idPacient) {
                                gasit=true;

                                std::cout<<"Numar de medicamente recomandate: ";
                                int numar_med;
                                std::cin>>numar_med;

                                Reteta<int> reteta_int;
                                Reteta<std::string> reteta_string;
                                for (int i=0;i<numar_med;i++) {
                                    std::string categorie, forma;
                                    std::cout<<"Introduceti categoria medicamentului(antibiotic / analgezic / antiinflamator): ";
                                    std::cin>>categorie;
                                    std::cout<<"Introduceti forma medicamentului(pastila / sirop / injectabil / crema): ";
                                    std::cin>>forma;

                                    std::shared_ptr<Medicament>med=MedicamentFactory::creeazaMedicament(categorie, forma);

                                    std::cout<<"Medicament: " + med->getNume() + ", Pret: " + std::to_string(med->getPret()) + ", Substanta activa: " + med->getSubstantaActiva() + "\n";

                                    std::cout<<"Doza recoamndata: \n";
                                    std::cout<<"1. Numar de pastile/zi\n";
                                    std::cout<<"2. Alta doza/zi\n";

                                    int var;
                                    std::cout<<"Alege tipul de doza: \n";
                                    std::cin>>var;

                                    switch (var) {
                                        case 1: {
                                            int info;
                                            std::cout<<"Doza: ";
                                            std::cin>>info;
                                            reteta_int.adaugaMedicament(med,info);
                                            break;
                                        }
                                        case 2: {
                                            std::string info;
                                            std::cout<<"Doza: ";
                                            std::cin>>info;
                                            reteta_string.adaugaMedicament(med,info);
                                            break;
                                        }
                                        default:
                                            std::cout<<"Optiune invalida\n";
                                        break;
                                    }
                                }

                                p->adaugaReteta(reteta_int);
                                p->adaugaReteta(reteta_string);
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
                            if (p->getId()==idPacient) {
                                gasit=true;
                                std::string externare;
                                std::cout<<"Introduceti data externarii: ";
                                std::string temp;
                                std::getline(std::cin,temp);
                                std::getline(std::cin, externare);
                                p->setData_externare(externare);
                                p->adaugaIstoric("Externare programata: "+externare);
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
                    auto asistent=std::make_shared<Asistent>();
                    std::cin>>*asistent;
                    idAsistentCurent=asistent->getId();
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
                        if (m->getId()==id) {
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
                            std::cout<<*p<<"\n";
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
