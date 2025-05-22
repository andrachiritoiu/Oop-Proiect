#ifndef CONSULTATIE_H
#define CONSULTATIE_H
#include "Servicii.h"
#include "Pacient.h"
#include<memory>


class Consultatie: public Servicii {
  protected:
    int pret;
    bool urgenta;

  public:
  //constructors
  Consultatie()=default;
  Consultatie(std::shared_ptr<Pacient>pacient);
  Consultatie(const std::string nume_serviciu,std::shared_ptr<Pacient>pacient, int pret, bool urgenta);

  //methods
  void executa()override;
  virtual std::string getTip()const =0;

  //destructor
  ~Consultatie()override = default;
};



#endif //CONSULTATIE_H
