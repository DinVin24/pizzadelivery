/**     Pizza Delivery(Pizza, Clienti, Adrese)

Date de intrare:
Numele clientulu, Adresa (strada, numar, oras, bloc, apartament),
pizza (mare/mica/medie, sos, branza, topping-uri)

Date de iesire:
Confirmarea comenzii (client, adresa, pizza),
Pret
**/

#include "functii.cpp"
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



    init_pizza();
    int optiune=1;
    int nrclienti=0;
    std::vector<Client> clienti;
    Client client_temp;
    while (optiune!=4) {
        std::cout<<"\nCe doriti sa faceti?!!!?!?!!?!?!\n";
        std::cout<<"1 - Adaugare client\n";
        std::cout<<"2 - Stergere client\n";
        std::cout<<"3 - Afisare clienti\n";
        std::cout<<"4 - Iesire\n";
        std::cin>>optiune;
        std::cin.ignore();
        switch (optiune) {
            case 1:
                citire_date(client_temp);
                clienti.push_back(client_temp);
                nrclienti++;
                break;
            case 2:
                int cod_client;
                std::cout<<"Introduceti codul clientului: ";
                std::cin>>cod_client;
                clienti.erase(clienti.begin()+cod_client);
                nrclienti--;
                break;
            case 3:
                for (int i = 0; i < nrclienti; i++) {
                    std::cout<<"-------- "<<i<<" --------\n";
                    std::cout<<clienti[i]<<"\n";
                }
                break;
        }
    }
    return 0;
}
