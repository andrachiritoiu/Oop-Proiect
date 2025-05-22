#include "ConsultatieEndocrinologica.h"

ConsultatieEndocrinologica::ConsultatieEndocrinologica(const std::string &nume_serviciu,std::shared_ptr<Pacient>pacient, int pret, bool urgenta, int glicemie):Consultatie(nume_serviciu,pacient,pret,urgenta) {
    this->glicemie=glicemie;
}

//getter
std::string ConsultatieEndocrinologica::getTip() const{
    return "endocrinologica";
}

//setter
void ConsultatieEndocrinologica::setGlicemie(int glicemie) {
    this->glicemie=glicemie;
}

//methods
void ConsultatieEndocrinologica::executa() {
    std::string diagnostic;
    std::cout<<"Introduceti diagnosticul: ";
    std::cin>>diagnostic;
    this->pacient->setDiagnostic(diagnostic);

    int severitate;
    std::cout<<"Severitate: ";
    std::cin>>severitate;
    this->pacient->setSeveritate(severitate);

    std::string data_internare;
    std::cout<<"Data internare: ";
    std::cin>>data_internare;
    this->pacient->setData_internare(data_internare);

    std::string data_externare;
    std::cout<<"Data externare: ";
    std::cin>>data_externare;
    this->pacient->setData_externare(data_externare);

    std::string glicemie;
    std::cout<<"Glicemie: ";
    std::cin>>glicemie;

    this->pacient->adaugaIstoric("Evaluare: Diagnostic=" + diagnostic +", Severitate=" +
        std::to_string(severitate) + ", Internare=" + data_internare + ", Externare=" + data_externare + "Glicemie: " + glicemie);
    std::cout << "Evaluare endocrinologica cardiologica adaugata cu succes.\n";
}

