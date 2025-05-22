#ifndef CONSULTATIEINITIALA_H
#define CONSULTATIEINITIALA_H
#include "Consultatie.h"
#include<string>

class ConsultatieInitiala: public Consultatie {
private:
    std::string motiv_programare;
public:
    //constructors
    ConsultatieInitiala()=default;
    ConsultatieInitiala(std::shared_ptr<Pacient>pacient);
    ConsultatieInitiala(const std::string &nume_serviciu,std::shared_ptr<Pacient>pacient, int pret, bool urgenta, const std::string &motiv_programare);

    //getter
    std::string getTip()const override;

    //setter
    void setMotiv(int tensiune);

    //methods
    void executa()override;

    //destructor
    ~ConsultatieInitiala()override = default;
};


#endif //CONSULTATIEINITIALA_H
