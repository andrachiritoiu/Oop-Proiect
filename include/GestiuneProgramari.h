#ifndef GESTIUNEPROGRAMARI_H
#define GESTIUNEPROGRAMARI_H
#include<memory>
#include<string>
#include<map>
#include<vector>
#include "Medic.h"
#include "Programare.h"

class GestiuneProgramari {
  private:
    std::map<std::shared_ptr<Medic>,std::map<std::string,std::vector<std::pair<int,int>>>> programari_facute;
    std::vector<Programare> programari;
  public:
    //methods
    bool adaugaProgramare(const Programare &programare);
    void afiseazaProgram(const std::shared_ptr<Medic>& medic, const std::string &zi);
    void afiseazaProgramariFacute(const std::shared_ptr<Medic>& medic);
};


#endif //GESTIUNEPROGRAMARI_H
