#include "Pacient.h"

//eroare
Pacient :: Pacient (const std::string &nume, const std::string &prenume, const std::string &CNP, const std::string &diagnostic,
        int severitate_boala, const std::string &data_internare, const std::string &data_externare, bool asigurat, int varsta):
        Persoana(nume,prenume,CNP),id_pacient(next_id++){
  this->id_pacient=next_id++;
  this->diagnostic=diagnostic;
  this->severitate_boala=severitate_boala;
  this->data_internare=data_internare;
  this->data_externare=data_externare;
  this->asigurat=asigurat;
  this->varsta=varsta;
}
