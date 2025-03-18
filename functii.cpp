#include <iostream>
#include <string.h>
#include "pizza.h"
#include "client.h"
using namespace std;
void Client::citire_date() {
    cout<<"----------Informatii Client:----------\n";
    cout<<"Nume si Prenume: ";
    cin.getline(nume,100);
}
void Adresa::citire_adresa(){
    cout<<"------------ADRESA------------\n";
    cout<<"Strada: ";
    set_strada();
    cout<<"Numar: ";
    set_numarul();
    cout<<"Blocul: ";
    set_bloc();
    cout<<"Apartamentul: ";
    set_apartament();
    cout<<"\n";
}
void Adresa::afisare_adresa(){
    if (strlen(strada)==0)
        cout<<"NU ATI INTRODUS NICIO ADRESA!";
    else{
        cout<<"------------ADRESA------------\n";
        cout<<"Strada: "<<strada<<"\nNumarul: ";
        cout<<numarul<<"\n";
        if(strlen(bloc)!=0){
            cout<<"Blocul: "<<bloc<<"\nApartamentul: ";
            cout<<apartament<<'\n';
        }
    }
}
