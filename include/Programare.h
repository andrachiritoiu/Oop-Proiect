#ifndef PROGRAMARE_H
#define PROGRAMARE_H
#include<string>
#include<memory>
#include "Pacient.h"
#include "Medic.h"

class Programare {
  private:
    std::string data;
    int ora{};
    //mai multe entitati(programari) acceseaza si folosesc acelasi obj(medic - fara sa se creeze duplicate)
    std::shared_ptr<Pacient> pacient;
    std::shared_ptr<Medic> medic;

  public:
    //constructors
    Programare()=default;
    Programare(const std::string &data, int ora, const std::shared_ptr<Pacient> &pacient, const std::shared_ptr<Medic> &medic);

    //getters
    std::string getData() const;
    int getOra() const;
    //const(1)-obj returnat nu poate fi modificat
    const std::shared_ptr<Pacient>& getPacient() const;
    const std::shared_ptr<Medic>& getMedic() const;

    //setters
    void setData(const std::string &data);
    void setOra(int ora);
    void setPacient(const std::shared_ptr<Pacient> &pacient);
    void setMedic(const std::shared_ptr<Medic> &med);

    //methods

    //destructor
    ~Programare()=default;

};

#endif //PROGRAMARE_H
