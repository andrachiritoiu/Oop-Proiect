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
    [[nodiscard]] std::string getData() const;
    [[nodiscard]] int getOraInceput() const;
    [[nodiscard]] int getOraSfarsit() const;
    //const(1)-obj returnat nu poate fi modificat
    [[nodiscard]] const std::shared_ptr<Pacient>& getPacient() const;
    [[nodiscard]] const std::shared_ptr<Medic>& getMedic() const;
    [[nodiscard]] const std::shared_ptr<Consultatie>& getConsultatie() const;

    //setters
    void setData(const std::string &data_n);
    void setOraInceput(int ora_inceput_n);
    void setOraSfarsit(int ora_sfarsit_n);

    //methods
    //upcast
    void adaugaServiciu();
    //downcastin programare am asa

    void afiseazaServiciu();

    //destructor
    ~Programare()=default;

};

#endif //PROGRAMARE_H
