/**     Pizza Delivery(Pizza, Clienti, Adrese)
Descrierea problemei
Utilizatorul este intampinat de o serie de meniuri.
Primul are optiunile de adaugrare/stergere/afisare clienti sau iesire
Se citeste numarul la tastatura corespunzator deciziei (asta se va
                                intampla la fiecare meniu intampinat)
La adaugarea unui client, trebuie introduse numele si adresa
(strada, numar, bloc apartament), toate sunt siruri de caractere
Apoi trebuie aleasa pizza, din nou apare un meniu cu mai multe pizza,
dupa ce este aleasa una, poate fi modificata iarasi, printr-un meniu
(marime, sos, topping-uri). La fiecare alegere pretul pizzei este actualizat

La stergerea unui client, trebuie sa introducem codul (indexul) acestuia

La afisarea clientilor, vor fi afisate informatiile tuturor clientilor
(index, nume, adresa (strada, numar, bloc apartament), pizza (sos, branza, topping-uri, pret))

La iesire se termina programul.
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



    init_pizza();//initializam meniul de pizza
    int optiune=1;
    int nrclienti=0;
    std::vector<Client> clienti;
    Client client_temp;//client temporar
    while (optiune!=4) {
        std::cout<<"\nCe doriti sa faceti?\n"<<"1 - Adaugare client\n";
        std::cout<<"2 - Stergere client\n"<<"3 - Afisare clienti\n";
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
