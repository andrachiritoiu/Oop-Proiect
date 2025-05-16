#ifndef RETETA_H
#define RETETA_H
#include<string>
#include<vector>
#include<memory>
#include "Medicament.h"

template<typename T>
class Reteta{
    private:
        std::string nume_pacient;
        std::vector<std::pair<std::shared_ptr<Medicament>,T>> medicamente;

    public:
    Reteta(const std::string &nume_pacient, std::vector<std::pair<std::shared_ptr<Medicament>,T>> medicamente);

};

#endif //RETETA_H
