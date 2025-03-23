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
    std::cout << R"($$$$$$$\  $$\                                    $$$$$$$\            $$\ $$\
$$  __$$\ \__|                                   $$  __$$\           $$ |\__|
$$ |  $$ |$$\ $$$$$$$$\ $$$$$$$$\ $$$$$$\        $$ |  $$ | $$$$$$\  $$ |$$\ $$\    $$\  $$$$$$\   $$$$$$\  $$\   $$\
$$$$$$$  |$$ |\____$$  |\____$$  |\____$$\       $$ |  $$ |$$  __$$\ $$ |$$ |\$$\  $$  |$$  __$$\ $$  __$$\ $$ |  $$ |
$$  ____/ $$ |  $$$$ _/   $$$$ _/ $$$$$$$ |      $$ |  $$ |$$$$$$$$ |$$ |$$ | \$$\$$  / $$$$$$$$ |$$ |  \__|$$ |  $$ |
$$ |      $$ | $$  _/    $$  _/  $$  __$$ |      $$ |  $$ |$$   ____|$$ |$$ |  \$$$  /  $$   ____|$$ |      $$ |  $$ |
$$ |      $$ |$$$$$$$$\ $$$$$$$$\\$$$$$$$ |      $$$$$$$  |\$$$$$$$\ $$ |$$ |   \$  /   \$$$$$$$\ $$ |      \$$$$$$$ |
\__|      \__|\________|\________|\_______|      \_______/  \_______|\__|\__|    \_/     \_______|\__|       \____$$ |
                                                                                                            $$\   $$ |
                                                                                                            \$$$$$$  |
                                                                                                             \______/ )";


    //De aici fac un meniu frumos, poate-l bag dupa in functii.cpp
    int optiune=1;
    int nrclienti=0;
    Client clienti[1001];
    while (optiune!=4) {
        std::cout<<"\nCe doriti sa faceti?!!!?!?!!?!?!\n";
        std::cout<<"1 - Adaugare client\n";
        std::cout<<"2 - Stergere client\n";
        std::cout<<"3 - Afisare clienti\n";
        std::cout<<"4 - Iesire\n";
        std::cin>>optiune;
        fin.ignore();
        switch (optiune) {
            case 1:
                citire_date(clienti[nrclienti++]);
                break;
            case 2:
                std::cout<<"Programatorul nostru inca nu a adaugat aceasta functionalitate...\n";
                break;
            case 3:
                for (int i = 0; i < nrclienti; i++) {
                    afisare_informatii(clienti[i]);
                }
                break;
        }
    }



    // int nrclienti;
    // std::cout<<"INTRODUCETI NUMARUL DE CLIENTI: ";
    // fin>>nrclienti;
    // for (int i = 0; i < nrclienti; i++) {
    //     fin.ignore();
    //     citire_date(clienti[i]);
    // }
    // for (int i = 0; i < nrclienti; i++) {
    //     afisare_informatii(clienti[i]);
    // }
    return 0;
}
