#ifndef CONSULTATIEENDOCRINOLOGICA_H
#define CONSULTATIEENDOCRINOLOGICA_H
#include"Consultatie.h"


class ConsultatieEndocrinologica:public Consultatie {
private:
    int glicemie;
public:
    //constructors
    ConsultatieEndocrinologica()=default;
    ConsultatieEndocrinologica(const std::string &nume_serviciu,std::shared_ptr<Pacient>pacient, int pret, bool urgenta, int glicemie);

    //getter
    std::string getTip()const override;

    //setter
    void setGlicemie(int glicemie);

    //methods
    void executa()override;

    //destructor
    ~ConsultatieEndocrinologica()override = default;
};



#endif //CONSULTATIEENDOCRINOLOGICA_H
