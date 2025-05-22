#ifndef CONSULTATIECARDIOLOGICA_H
#define CONSULTATIECARDIOLOGICA_H
#include "Consultatie.h"

class ConsultatieCardiologica: public Consultatie {
private:
  int tensiune;
public:
    //constructors
    ConsultatieCardiologica()=default;
	ConsultatieCardiologica(const std::string &nume_serviciu,std::shared_ptr<Pacient>pacient, int pret, bool urgenta, int tensiune);

    //getter
    std::string getTip()const override;

    //setter
    void setTensiune(int tensiune);

    //methods
    void executa()override;

    //destructor
    ~ConsultatieCardiologica()override = default;
};



#endif //CONSULTATIECARDIOLOGICA_H
