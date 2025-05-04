#ifndef PERSOANA_H
#define PERSOANA_H
#include<string>

class Persoana {
protected:
    std::string nume;
    std::string prenume;
    std::string CNP;

    static bool isCNPvalid(const std::string &cnp);

public:
    //constructors
    Persoana()=default;
    Persoana(const std::string &nume, const std::string &prenume, const std::string &CNP);
    //copy constructor
    Persoana(const Persoana &p);

    //getters
    std::string getNume() const;
    std::string getPrenume() const;
    std::string getCNP() const;

    //setters
    void setNume(const std::string &nume);
    void setPrenume(const std::string &prenume);
    //void setCNP(const std::string &CNP);

    //operators
    Persoana& operator= (const Persoana &p);
    //supraincarcarea op == ca functie membra(cel putin un operand este membru al clasei => acces la memmbrii clasei)
    bool operator==(const Persoana &p) const;
    //&in - fluxul de intrare din care citim datele si i le atribuim persoanei
    friend std::istream& operator>>(std::istream &in, Persoana &p);
    friend std::ostream& operator<<(std::ostream &out, const Persoana &p);

    //methods
    //functie virtuala pura => face clasa abstracta
    //virtual void afiseazaDetalii()=0;

    //destructor
    virtual ~Persoana()=default;

};

#endif //PERSOANA_H
