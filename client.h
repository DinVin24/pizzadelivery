#include "adresa.h"
class Client{
    char nume[100]={};
    Adresa adresa;

public:
    void set_adresa(){adresa.citire_adresa();}
    void get_adresa(){adresa.afisare_adresa();}

    void set_nume(){std::cin.getline(nume,100);}

    void get_nume();

    void citire_date();
    void afisare_informatii();

};
