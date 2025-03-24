/**     Pizza Delivery(Pizza, Clienti, Adrese)
Descrierea problemei
Utilizatorul este intampinat de o serie de meniuri.
Primul are optiunile de adaugrare/stergere/afisare clienti sau iesire
Se citeste numarul la tastatura corespunzator deciziei (asta se va
                                intampla la fiecare meniu intampinat)
La adaugarea unui client,se creeaza un element in vectorul clienti care este
obiect al clasei Client. Trebuie introduse numele si adresa
(strada, numar, bloc apartament, creandu-se obiectul clasa pentru clientul nostru).
Toate sunt siruri de caractere.
Apoi se creaza obiectul pizza pentru client, iarasi suntem intampinati de meniuri
de unde putem copia o pizza deja definita sau sa ne cream propria noastra pizza.
(marime, sos, branza, carne, legume).

La stergerea unui client, trebuie sa introducem codul (indexul) acestuia
si va fi scos din vectorul clienti

La afisarea clientilor, vor fi afisate informatiile tuturor clientilor
(index, nume, adresa (strada, numar, bloc apartament),
pizza (sos, branza, topping-uri, pret))
La iesire se termina programul.
**/

#include "functii.cpp"
int main()
{
    std::cout << R"(  ____  _                ____       _ _
 |  _ \(_)__________ _  |  _ \  ___| (_)_   _____ _ __ _   _
 | |_) | |_  /_  / _` | | | | |/ _ \ | \ \ / / _ \ '__| | | |
 |  __/| |/ / / / (_| | | |_| |  __/ | |\ V /  __/ |  | |_| |
 |_|   |_/___/___\__,_| |____/ \___|_|_| \_/ \___|_|   \__, |
                                                       |___/ )";

    init_pizza();//initializam meniul de pizza
    int optiune = 1;
    int nrclienti = 0;
    int bani = 0;
    std::vector<Client> clienti;
    Client client_temp;//client temporar
    while (optiune != 4)
    {
        std::cout << "\nPana acum am strans " << bani << " leuti\n";
        std::cout << "Ce doriti sa faceti?\n" << "1 - Adaugare client\n";
        std::cout << "2 - Stergere client\n" << "3 - Afisare clienti\n";
        std::cout << "4 - Iesire\n";
        std::cin >> optiune;
        std::cin.ignore();
        switch (optiune)
        {
            case 1:
                citire_date(client_temp);
                clienti.push_back(client_temp);
                nrclienti++;
                bani+=clienti[nrclienti - 1].getPizza().getPret();
                break;
            case 2:
                int cod_client;
                std::cout << "Introduceti codul clientului: ";
                std::cin >> cod_client;
                clienti.erase(clienti.begin() + cod_client);
                nrclienti--;
                break;
            case 3:
                for (int i = 0; i < nrclienti; i++)
                {
                    std::cout << "-------- " << i << " --------\n";
                    std::cout << clienti[i] << "\n";
                }
                break;
        }
    }
    return 0;
}
