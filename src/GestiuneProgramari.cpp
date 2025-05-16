#include "GestiuneProgramari.h"

//methods
bool GestiuneProgramari :: adaugaProgramare(const Programare &programare){
    std::string data_programare=programare.getData();
    std::pair<int,int> interval_programare=std::make_pair(programare.getOraInceput(),programare.getOraSfarsit());
    auto medic=programare.getMedic();

    for (const auto &interval:this->programari_facute[medic][data_programare]) {
        if (interval_programare.first<interval.second && interval_programare.second>interval.first)
            std::cout<<"Acest interval este deja ocupat. Alegeti alt interval.\n";
        return false;
    }

    this->programari_facute[medic][data_programare].push_back(interval_programare);
    this->programari.push_back(programare);
    return true;
}

void GestiuneProgramari :: afiseazaProgram(const std::shared_ptr<Medic>& medic, const std::string &zi) {
    std::cout<<"Programul medicului "<<medic->getNume()<<" "<<medic->getPrenume()<<" pentru "<<zi<<" este:\n";
    const auto &intervale=programari_facute[medic][zi];
    if (intervale.empty()) {
        std::cout<<"Nu exista programari.\n";
    }
    else {
        for (const auto &interval:intervale) {
            std::cout<<interval.first<<":00 - "<<interval.second<<":00\n";
        }
    }
}