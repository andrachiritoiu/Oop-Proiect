#ifndef PROGRAMARE_H
#define PROGRAMARE_H
#include<string>
#include "Pacient.h"
#include "Medic.h"

class Programare {
  private:
    std::string data;
    int ora{};
    Pacient pacient;
    Medic medic;
  public:
    //constructors
    Programare()=default;
    Programare(const std::string &data, int ora, const Pacient &pacient, const Medic &medic);

    //getters
    std::string getData() const;
    int getOra() const;
    //const(1)-obj returnat nu poate fi modificat
    const Pacient& getPacient() const;
    const Medic& getMedic() const;

    //setters
    void setData(const std::string &data);
    void setOra(int ora);
    void setPacient(const Pacient &pacient);
    void setMedic(const Medic &med);

    //methods

    //destructor

};

#endif //PROGRAMARE_H
