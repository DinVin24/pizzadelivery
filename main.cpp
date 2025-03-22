/**     Pizza Delivery(Pizza, Clienti, Adrese)

Date de intrare:
Numele clientulu, Adresa (strada, numar, oras, bloc, apartament),
pizza (mare/mica/medie, sos, branza, topping-uri)

Date de iesire:
Confirmarea comenzii (client, adresa, pizza),
Pret
**/
#include <iostream>
#include "functii.cpp"  // Include the function definitions

int main() {
    // Client daniel;
    // citire_date(daniel);
    //
    // afisare_informatii(daniel);

    Pizza gigel;
    citire_pizza(gigel);
    afisare_pizza(gigel);
    return 0;
}
