#ifndef PROGRAMARE_H
#define PROGRAMARE_H
#include<string>
#include<memory>
#include "Pacient.h"
#include "Medic.h"
#include "Consultatie.h"

class Programare {
  private:
    std::string data;
    int ora_inceput{};
    int ora_sfarsit{};
    std::shared_ptr<Pacient> pacient;
    std::shared_ptr<Medic> medic;
    std::shared_ptr<Consultatie> consultatie;

  public:
    //constructors
    Programare()=default;
    Programare(const std::string &data,  int ora_inceput, int ora_sfarsit, const std::shared_ptr<Pacient> &pacient, const std::shared_ptr<Medic> &medic,const std::shared_ptr<Consultatie> &consultatie);

    //getters
    std::string getData() const;
    int getOraInceput() const;
    int getOraSfarsit() const;
    //const(1)-obj returnat nu poate fi modificat
    const std::shared_ptr<Pacient>& getPacient() const;
    const std::shared_ptr<Medic>& getMedic() const;
    const std::shared_ptr<Consultatie>& getConsultatie() const;

    //setters
    void setData(const std::string &data);
    void setOraInceput(int ora_inceput);
    void setOraSfarsit(int ora_sfarsit);
    void setPacient(const std::shared_ptr<Pacient> &pacient);
    void setMedic(const std::shared_ptr<Medic> &med);

    //methods
    //upcast
    void adaugaServiciu();
    //downcast
    void afiseazaServiciu();

    //destructor
    ~Programare()=default;

};

#endif //PROGRAMARE_H
