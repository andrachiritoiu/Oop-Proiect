#ifndef CONSULTATIEURMARIRE_H
#define CONSULTATIEURMARIRE_H
#include"Consultatie.h"


class ConsultatieUrmarire:public Consultatie {
private:
    std::string evaluare_progres;
public:
    //constructors
    ConsultatieUrmarire()=default;
    ConsultatieUrmarire(const std::shared_ptr<Pacient> &pacient);
    ConsultatieUrmarire(const std::string &nume_serviciu, const std::shared_ptr<Pacient> &pacient, int pret, bool urgenta,const std::string &evaluare_progres);

    //getter
    [[nodiscard]] std::string getTip()const override;

    //setter
    void setEvaluareProgres(const std::string &evaluare_progres);

    //methods
    void executa()override;

    //destructor
    ~ConsultatieUrmarire()override = default;
};



#endif //CONSULTATIEURMARIRE_H
