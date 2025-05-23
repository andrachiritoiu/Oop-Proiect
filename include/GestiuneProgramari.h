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
  //obj dirct - nu are mosteniri
    std::vector<Programare> programari;
  public:
    //getter
    const std::vector<Programare>& getProgramari()const;

    //methods
    bool adaugaProgramare(const Programare &programare);
    void afiseazaProgram(const std::shared_ptr<Medic>& medic, const std::string &zi);
    void afiseazaProgramariFacute(const std::shared_ptr<Medic>& medic);

};


#endif //GESTIUNEPROGRAMARI_H
