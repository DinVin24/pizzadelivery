/**     Pizza Delivery(Pizza, Clienti, Adrese)

Testoasele ninja au devenit infometate dupa lupte crancene cu inamicii New York-ului.
Astfel, doresc sa isi comande 10 pizza maaari cu branza si peperoni.
Ei isi introduc pe



Fiecare client are o adresa, si niste pizza, oricate
Mai multe tipuri de pizza

Pt fiecare client, citim adresa si tipul de pizza dorit

mica, medie, mare
si alte tipuri de pizza care-mi mai vin mie in minte mai
tarziu, pana atunci le denumesc 1,2,3 etcc... 2-10
**/
#include "functii.cpp"
using namespace std;

int main()
{
    Client daniel;
    daniel.citire_date();
    daniel.set_adresa();
    daniel.get_adresa();
    cout<<daniel.nume;
    return 0;
}
