#include "ConsultatieCardiologica.h"

ConsultatieCardiologica::ConsultatieCardiologica(const std::string &nume_serviciu,std::shared_ptr<Pacient>pacient, int pret, bool urgenta, int tensiune):Consultatie(nume_serviciu,pacient,pret,urgenta) {
    this->tensiune=tensiune;
}

//getter
std::string ConsultatieCardiologica::getTip() const{
    return "cardiologica";
}

//setter
void ConsultatieCardiologica::setTensiune(int tensiune) {
    this->tensiune=tensiune;
}

//methods
void ConsultatieCardiologica::executa(){
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

    std::string tensiune;
    std::cout<<"Tensiune: ";
    std::cin>>tensiune;

    this->pacient->adaugaIstoric("Evaluare: Diagnostic=" + diagnostic +", Severitate=" +
        std::to_string(severitate) + ", Internare=" + data_internare + ", Externare=" + data_externare + "Tensiune: " + tensiune);
    std::cout << "Evaluare cardiologica adaugata cu succes.\n";
}

