#include "Analize.h"

Analize::Analize(const std::string &nume_serviciu,std::shared_ptr<Pacient>pacient, const std::string &tip_analiza, const std::string &rezulatat):
        Servicii(nume_serviciu, pacient) {
        this->tip_analiza=tip_analiza;
        this->rezulatat=rezulatat;

}

void Analize::executa() {
        std::cout<<"analize";
}