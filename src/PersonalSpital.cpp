#include "PersonalSpital.h"
#include<iostream>

int PersonalSpital::next_id=1;
int PersonalSpital::salariu_mediu=0;
int PersonalSpital::suma_totala_salarii=0;
int PersonalSpital::nr_angajati=0;

//constructors
PersonalSpital::PersonalSpital():Persoana() {
    this->id_angajat=next_id++;
    this->salariu=0;
    this->experienta=0;
    this->program;
}
PersonalSpital::PersonalSpital(const std::string &nume, const std::string &prenume, const std::string &CNP, int salariu,
    int experienta,  std::map<std::string, std::vector<int>> &program) : Persoana(nume, prenume, CNP){
    this->id_angajat=next_id++;
    this->salariu=salariu;
    this->experienta=experienta;
    this->program=program;

    suma_totala_salarii+=this->salariu;
    nr_angajati++;
    salariu_mediu=suma_totala_salarii/nr_angajati;
}
//copy constructor
PersonalSpital::PersonalSpital(const PersonalSpital &p): Persoana(p){
    this->id_angajat=p.id_angajat;
    this->salariu=p.salariu;
    this->experienta=p.experienta;
    this->program=p.program;

    suma_totala_salarii+=this->salariu;
    nr_angajati++;
    salariu_mediu=suma_totala_salarii/nr_angajati;
}

//getters
int PersonalSpital :: getId() const {
    return this->id_angajat;
}
int PersonalSpital :: getSalariu() const {
    return this->salariu;
}
int PersonalSpital :: getExperienta() const {
    return this->experienta;
}


//setters
void PersonalSpital :: setSalariu(int salariu) {
    suma_totala_salarii = suma_totala_salarii - this->salariu + salariu;
    this->salariu=salariu;
    if (nr_angajati>0)
        salariu_mediu = suma_totala_salarii / nr_angajati;
}

//operators
PersonalSpital& PersonalSpital :: operator=(const PersonalSpital &p) {
    if (this!=&p) {
        Persoana::operator=(p);
        suma_totala_salarii=suma_totala_salarii - this->salariu + p.salariu;
        this->salariu=p.salariu;
        this->experienta=p.experienta;
        this->program=p.program;

        if (nr_angajati>0)
            salariu_mediu=suma_totala_salarii / nr_angajati;
    }
    return *this;
}
std::istream& operator>>(std::istream &in, PersonalSpital &p) {
    //static_cast - converteste
    in>>static_cast<Persoana&>(p); //upcasting
    std::cout<<"Salariu: ";
    in>>p.salariu;
    std::cout<<"Experienta: ";
    in>>p.experienta;

    int nr_zile;
    std::cout<<"Numar de zile cu program: ";
    in>>nr_zile;
    for (int i=0;i<nr_zile;i++) {
        std::string zi;
        std::cout<<"Ziua "<<i+1<<" (luni-duminica)"<<": ";
        in>>zi;

        int nr_intervale;
        std::cout<<"Numar de intervale orare pentru "<<zi<<": ";
        in>>nr_intervale;

        std::vector<int> ore;
        std::string interval;
        int ora_inceput,ora_sfarsit;
        for (int j=0;j<nr_intervale;j++) {
            std::cout << "Introduceti intervalul de ore "<<"(ora inceput - ora sfarsit): ";
            in>>interval;

            int poz=interval.find("-");
            ora_inceput=std::stoi(interval.substr(0,poz));
            ora_sfarsit=std::stoi(interval.substr(poz+1));

            if (ora_inceput<0 || ora_inceput>24 || ora_sfarsit<0 || ora_sfarsit>24 || ora_inceput>=ora_sfarsit){
                std::cout<<"Interval invalid. Reintroduceti intervalul.\n";
                --j;
            }

            ore.push_back(ora_inceput);
            ore.push_back(ora_sfarsit);
        }
        p.program[zi]=ore;
    }

    //recalculare daca este obiect nou
    PersonalSpital::suma_totala_salarii+=p.salariu;
    PersonalSpital::nr_angajati++;
    PersonalSpital::salariu_mediu=PersonalSpital::suma_totala_salarii/PersonalSpital::nr_angajati;
    return in;
}
std::ostream& operator<<(std::ostream &out, const PersonalSpital &p) {
    out<<static_cast<const Persoana&>(p);
    out<<"Id angajat: "<<p.id_angajat<<"\n"
       <<"Salariu: "<<p.salariu<<"\n"
       <<"Experienta: "<<p.experienta<<"\n"
       <<"Program: ";
    for (const auto& zi : p.program) {
        out << zi.first << ": ";
        for (int ora : zi.second)
            out << ora << " ";
    }
    return out;
}

//methods
int PersonalSpital :: calculeazaSalariuMediu(){
    return salariu_mediu;
}
//destructors
PersonalSpital::~PersonalSpital() {
    nr_angajati--;
}