#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include<string>
#include<iostream>

class Medicament {
private:
  std::string nume;
  int pret{};
  std::string substanta_activa;

public:
    //constructors
    Medicament()=default;
    Medicament(const std::string& nume, int pret,const std::string &substanta_activa);

    //getters
    std::string getNume()const;
    int getPret()const;
    std::string getSubstantaActiva()const;

    //setters

    //methods

    //operators
    friend std::istream& operator>>(std::istream &in, Medicament &m);
    friend std::ostream& operator<<(std::ostream &out, const Medicament &m);

    //destructor
    ~Medicament()=default;
};



#endif //MEDICAMENT_H
