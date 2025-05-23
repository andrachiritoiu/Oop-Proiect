#ifndef CONSULTATIEURMARIRE_H
#define CONSULTATIEURMARIRE_H
#include"Consultatie.h"


class ConsultatieUrmarire:public Consultatie {
private:
    std::string evaluare_progres;
public:
    //constructors
    ConsultatieUrmarire()=default;
    ConsultatieUrmarire(std::shared_ptr<Pacient>pacient);
    ConsultatieUrmarire(const std::string &nume_serviciu,std::shared_ptr<Pacient>pacient, int pret, bool urgenta,const std::string &evaluare_progres);

    //getter
    std::string getTip()const override;

    //setter
    void setEvaluareProgres(std::string evaluare_progres);

    //methods
    void executa()override;

    //destructor
    ~ConsultatieUrmarire()override = default;
};



#endif //CONSULTATIEURMARIRE_H
