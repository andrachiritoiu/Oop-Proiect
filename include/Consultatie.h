#ifndef CONSULTATIE_H
#define CONSULTATIE_H
#include "Servicii.h"
#include "Pacient.h"
#include<memory>


class Consultatie: public Servicii {
  private:
    int pret;
    bool urgenta;

  public:
  //constructor
  Consultatie(const std::string &nume_serviciu,std::shared_ptr<Pacient>pacient, int pret, bool urgenta);

  //methods
  void executa()override;

  //destructor
  ~Consultatie()override = default;
};



#endif //CONSULTATIE_H
