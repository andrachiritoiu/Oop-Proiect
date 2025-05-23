#include "ConsultatieUrmarire.h"

//cosntructors
ConsultatieUrmarire::ConsultatieUrmarire(std::shared_ptr<Pacient>pacient) {
    this->pacient=pacient;
}
ConsultatieUrmarire::ConsultatieUrmarire(const std::string &nume_serviciu,std::shared_ptr<Pacient>pacient, int pret, bool urgenta, const std::string &evaluare_progres):Consultatie(nume_serviciu,pacient,pret,urgenta) {
    this->evaluare_progres=evaluare_progres;
}

//getter
std::string ConsultatieUrmarire::getTip() const{
    return "endocrinologica";
}

//setter
void ConsultatieUrmarire::setEvaluareProgres(std::string evaluare_progres) {
    this->evaluare_progres=evaluare_progres;
}

//methods
void ConsultatieUrmarire::executa() {
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

    std::string evaluare_progres;
    std::cout<<"Evaluare progres: ";
    std::cin>>evaluare_progres;

    this->pacient->adaugaIstoric("Evaluare: Diagnostic:" + diagnostic +", Severitate:" +
        std::to_string(severitate) + ", Internare:" + data_internare + ", Externare:" + data_externare + ", Progres: " + evaluare_progres);
    std::cout << "Evaluare endocrinologica cardiologica adaugata cu succes.\n";
}

