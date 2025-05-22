#include "GestiuneProgramari.h"

//getter
const std::vector<Programare>& GestiuneProgramari :: getProgramari()const {
    return this->programari;
}

//methods
bool GestiuneProgramari :: adaugaProgramare(const Programare &programare){
    std::string data_programare=programare.getData();
    std::pair<int,int> interval_programare=std::make_pair(programare.getOraInceput(),programare.getOraSfarsit());
    auto medic=programare.getMedic();

    for (const auto &p:this->programari) {
        if (p.getMedic()==medic && p.getData()==data_programare) {
            std::pair<int,int> interval=std::make_pair(p.getOraInceput(),p.getOraSfarsit());
            if (interval_programare.first<interval.second && interval_programare.second>interval.first)
                std::cout<<"Acest interval este deja ocupat. Alegeti alt interval.\n";
            return false;
        }
    }

    this->programari.push_back(programare);
    return true;
}

void GestiuneProgramari :: afiseazaProgram(const std::shared_ptr<Medic>& medic, const std::string &zi) {
    std::cout<<"Programul medicului "<<medic->getNume()<<" "<<medic->getPrenume()<<" pentru "<<zi<<" este:\n";

    bool gasit=false;
    for (const auto &p:this->programari) {
        if (p.getMedic()==medic && p.getData()==zi) {
            gasit=true;
            std::cout<<p.getOraInceput()<<"-"<<p.getOraSfarsit();
        }
    }
    if (!gasit) {
        std::cout<<"Medicul nu are programari";
    }

}
void GestiuneProgramari::afiseazaProgramariFacute(const std::shared_ptr<Medic>& medic) {
    std::cout<<"Programul medicului "<<medic->getNume()<<" "<<medic->getPrenume()<<":\n";
    bool gasit=false;

    for (const auto &programare:this->programari) {
        if (programare.getMedic()==medic) {
            gasit=true;
            std::cout<<"Data: "<<programare.getData()<<"\n";
            std::cout<<"Interval: "<<programare.getOraInceput()<<":00-"<<programare.getOraSfarsit()<<":00\n";
            std::cout<<"Pacient: "<<programare.getPacient()->getNume()<<" "<<programare.getPacient()->getPrenume()<<"\n";
        }
    }

    if (!gasit) {
        std::cout<<"Nu exista programari.";
    }
}