#ifndef PERSONALSPITAL_H
#define PERSONALSPITAL_H
#include<string>
#include<vector>
#include<map>
#include "Persoana.h"
#include"Medicament.h"

class PersonalSpital: public Persoana {
protected:
  int id_angajat;
  static int next_id;
  int salariu;
  int experienta;
  //{ziua:[(ora_inceput,ora_sfarsit),.....], ..... }
  std::map<std::string, std::vector<std::pair<int,int>>> program;
  static int salariu_mediu;
  static int suma_totala_salarii;
  static int nr_angajati;

public:
  //constructors
  PersonalSpital();
  PersonalSpital(const std::string &nume, const std::string &prenume, const std::string &CNP, int salariu,
      int experienta, const std::map<std::string, std::vector<std::pair<int,int>>> &program);
  //copy constructor
  PersonalSpital(const PersonalSpital &p);

  //getters
  int getId() const;
  int getSalariu() const;
  int getExperienta() const;
  std::map<std::string, std::vector<std::pair<int,int>>> getProgram() const;

  //setters
  void setSalariu(int salariu);

  //operators
  PersonalSpital& operator=(const PersonalSpital &p);
  friend std::istream& operator>>(std::istream &in, PersonalSpital &p);
  friend std::ostream& operator<<(std::ostream &out, const PersonalSpital &p);

  //methods
  virtual void calculeazaBonus() = 0 ;
  static int calculeazaSalariuMediu();

  //destructor
  ~PersonalSpital() override;
};



#endif //PERSONALSPITAL_H
