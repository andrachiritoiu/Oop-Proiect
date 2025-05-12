#ifndef PERSONALSPITAL_H
#define PERSONALSPITAL_H
#include<string>
#include "Persoana.h"
#include"Medicament.h"

class PersonalSpital: public Persoana {
protected:
  int id_angajat;
  static int next_id;
  int salariu;
  int experienta;
  std::string program;
  static int salariu_mediu;
  static int suma_totala_salarii;
  static int nr_angajati;

public:
  //constructors
  PersonalSpital();

  PersonalSpital(const std::string &nume, const std::string &prenume, const std::string &CNP, int salariu, int experienta, const std::string &program);
  //copy constructor
  PersonalSpital(const PersonalSpital &p);

  //getters
  int getId() const;
  int getSalariu() const;
  int getExperienta() const;
  std::string getProgram() const;

  //setters
  void setSalariu(int salariu);
  void setProgram(const std::string &program);

  //operators
  PersonalSpital& operator=(const PersonalSpital &p);
  friend std::istream& operator>>(std::istream &in, PersonalSpital &p);
  friend std::ostream& operator<<(std::ostream &out, const PersonalSpital &p);

  //methods
  //virtual void calclueazaBonus() const = 0 ;
  static int calculeazaSalariuMediu();

  //destructor
  ~PersonalSpital() override = default;
};



#endif //PERSONALSPITAL_H
