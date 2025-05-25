#ifndef GESTIUNEPROGRAMARI_H
#define GESTIUNEPROGRAMARI_H
#include<memory>
#include<string>
#include<vector>
#include "Medic.h"
#include "Programare.h"

class GestiuneProgramari {
  private:
  //obj direct - nu are mosteniri
    std::vector<Programare> programari;
  public:
    //getter
    [[nodiscard]] const std::vector<Programare>& getProgramari()const;

    //methods
    bool adaugaProgramare(const Programare &programare);
    void afiseazaProgram(const std::shared_ptr<Medic>& medic, const std::string &zi) const;
    void afiseazaProgramariFacute(const std::shared_ptr<Medic>& medic) const;

};


#endif //GESTIUNEPROGRAMARI_H
