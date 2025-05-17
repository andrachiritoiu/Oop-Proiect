#ifndef PACIENT_H
#define PACIENT_H
#include<string>
#include<vector>
#include<variant>
#include "Persoana.h"
#include "Reteta.h"

using RetetaVariant=std::variant<Reteta<int>,Reteta<std::string>>;

class Pacient: public Persoana{
private:
    int id_pacient{};
    static int next_id;
    std::string diagnostic;
    int severitate_boala{};
    std::string data_internare;
    std::string data_externare;
    bool asigurat{};
    std::vector<std::string> istoric_medical;
    std::vector<RetetaVariant> retete;

public:
    //constructors
    Pacient();
    Pacient(const std::string &nume, const std::string &prenume, const std::string &CNP, const std::string &diagnostic,
        int severitate_boala, const std::string &data_internare, const std::string &data_externare, bool asigurat,const std::vector<std::string> &istoric_medical);
    //copy constructor
    Pacient(const Pacient &p);

    //getters
    int getId() const;
    std::string getDiagnostic() const;
    int getSeveritatBoala() const;
    std::string getData_internare() const;
    std::string getData_externare() const;
    bool getAsigurat() const;
    const std::vector<std::string>& getIstoricMedical() const;
    const std::vector<RetetaVariant>& getRetete() const;

    //setters
    void setDiagnostic(const std::string &diagnostic);
    void setSeveritate(int severitate);
    void setData_internare(const std::string &data_internare);
    void setData_externare(const std::string &data_externare);
    void setIstoric(const std::vector<std::string>& istoric_medical);

    //operators
    Pacient& operator=(const Pacient &p);
    friend std::istream& operator>>(std::istream &in, Pacient &p);
    friend std::ostream& operator<<(std::ostream &out, const Pacient &p);

    //methods
    void adaugaIstoric(const std::string &noua_interventie);
    void adaugaReteta(RetetaVariant reteta);

    //destructor
    ~Pacient() override = default;
};


#endif //PACIENT_H
