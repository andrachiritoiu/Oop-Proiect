#include "ConsultatieInitiala.h"

//constructors
ConsultatieInitiala::ConsultatieInitiala(std::shared_ptr<Pacient>pacient) {
    this->pacient=pacient;
}
ConsultatieInitiala::ConsultatieInitiala(const std::string &nume_serviciu,std::shared_ptr<Pacient>pacient, int pret, bool urgenta, const std::string &motiv_programare):Consultatie(nume_serviciu,pacient,pret,urgenta) {
    this->motiv_programare=motiv_programare;
}

//getter
std::string ConsultatieInitiala::getTip() const{
    return "cardiologica";
}

//setter
void ConsultatieInitiala::setMotiv(int tensiune) {
    this->motiv_programare=motiv_programare;
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

    std::string motiv_programare;
    std::cout<<"MOtiv programare: ";
    std::cin>>motiv_programare;
    this->motiv_programare=motiv_programare;

    this->pacient->adaugaIstoric("Evaluare: Diagnostic:" + diagnostic +", Severitate:" +
        std::to_string(severitate) + ", Internare:" + data_internare + ", Externare:" + data_externare + ", Motiv programare:" + motiv_programare);
    std::cout << "Evaluare initiala adaugata cu succes.\n";
}

