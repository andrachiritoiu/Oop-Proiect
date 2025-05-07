#include <iostream>
#include <array>
#include "Persoana.h"
#include "Pacient.h"
#include "PersonalSpital.h"
#include "Medic.h"
#include "Asistent.h"


int main() {
    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];

    // Persoana persoana("Ionescu","Maria","8174979702901");
    // std::cout<<persoana.getNume();


    Pacient pacient("Ionescu","Maria","2650101037813","raceala",5,"14.02","16.02",true,
        {"Internare pentru raceala 12.04.2022 - 14.04.2022","Consultatie cardiologie 20.09.2021","Tratament alergie 05.05.2020"});
    std::cout<<pacient;
    //
    // Pacient persoana;
    // std::cin>>persoana;
    // std::cout<<persoana;
    //
    // Pacient persoana2;
    // std::cin>>persoana2;
    // std::cout<<persoana2;

    // Medic medic;
    // std::cin>>medic;
    // std::cout<<medic;

    // Asistent asistent;
    // std::cin>>asistent;
    // std::cout<<asistent;

    return 0;
}
