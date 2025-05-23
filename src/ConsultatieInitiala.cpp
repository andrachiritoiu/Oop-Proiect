#include "ConsultatieInitiala.h"

//constructors
ConsultatieInitiala::ConsultatieInitiala(const std::shared_ptr<Pacient> &pacient) {
    this->pacient=pacient;
}
ConsultatieInitiala::ConsultatieInitiala(const std::string &nume_serviciu, const std::shared_ptr<Pacient> &pacient, int pret, bool urgenta, const std::string &simptome_initiale):Consultatie(nume_serviciu,pacient,pret,urgenta) {
    this->simptome_initiale=simptome_initiale;
}

//getter
std::string ConsultatieInitiala::getTip() const{
    return "cardiologica";
}

//setter
void ConsultatieInitiala::setSimptome(const std::string &simptome_initiale) {
    this->simptome_initiale=simptome_initiale;
}

//methods
void ConsultatieInitiala::executa(){
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

    int pret;
    std::cout<<"Introduceti pretul consultatiei: ";
    std::cin>>pret;
    this->pret=pret;

    bool urgenta;
    std::cout<<"Este urgenta? (1-da, 0-nu): ";
    std::cin>>urgenta;
    this->urgenta=urgenta;

    std::string simptome_initiale;
    std::cout<<"Simptome initiale: ";
    std::cin>>simptome_initiale;
    this->simptome_initiale=simptome_initiale;

    this->pacient->adaugaIstoric("Evaluare: Diagnostic:" + diagnostic +", Severitate:" +
        std::to_string(severitate) + ", Internare:" + data_internare + ", Externare:" + data_externare + ", Simptome initiale:" + simptome_initiale);
    std::cout << "Evaluare initiala adaugata cu succes.\n";
}

