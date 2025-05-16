#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include<string>
#include<iostream>

class Medicament {
private:
  std::string nume;
  float pret{};
  std::string cantitate;

public:
    //constructors
    Medicament()=default;
    Medicament(const std::string& nume, float pret,const std::string &cantitate);

    //getters
    std::string getNume()const;
    float getPret()const;
    std::string getCantitate()const;

    //setters

    //methods

    //operators
    friend std::istream& operator>>(std::istream &in, Medicament &m);
    friend std::ostream& operator<<(std::ostream &out, const Medicament &m);

    //destructor
    ~Medicament()=default;
};



#endif //MEDICAMENT_H
