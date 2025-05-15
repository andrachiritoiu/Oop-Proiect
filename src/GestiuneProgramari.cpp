#include "GestiuneProgramari.h"

//methods
bool GestiuneProgramari :: adaugaProgramare(const Programare& programare){
    std::string data=programare.getData();
    int ora=programare.getOra();
    auto medic=programare.getMedic();
    //implementare
    return false;
}

void GestiuneProgramari :: afiseazaProgram(const std::shared_ptr<Medic>& medic, const std::string &zi) {
    std::cout<<"Programul medicului "<<medic->getNume()<<" "<<medic->getPrenume()<<" pentru "<<zi<<" este:\n";
    for (auto ora:programari[medic][zi]){
                std::cout<<ora<<"\n";
    }
}