#include "client.h"
#include <iostream>
#include <fstream>
std::ifstream fin ("date.in");
//foloseste un fisier din care sa iti construiesti pizza
//si fa o sortare, poti sorta pizza alfabetic, clientii dupa pret
Pizza pizzas[9];
void init_pizza () {
    int i = 0;
    int x;
    bool extra;
    while (fin>>x) {
        pizzas[i].setMarime(x);
        fin>>x;
        pizzas[i].setSos(x);
        fin>>x;
        pizzas[i].setExtraSos(x);
        fin>>x;
        while (x!=6) {
            fin>>extra;
            pizzas[i].setBranza(x,extra);
            fin>>x;
        }
        fin>>x;
        while (x!=9) {
            fin>>extra;
            pizzas[i].setCarne(x,extra);
            fin>>x;
        }
        fin>>x;
        while (x!=9) {
            fin>>extra;
            pizzas[i].setLegume(x,extra);
            fin>>x;
        }
        i++;
    }

}
bool conditie_sortare(Client x, Client y) {
    return x.getPizza().getPret() > y.getPizza().getPret();
}

void citire_pizza(Pizza& pizza);
void citire_date(Client& client)
{
    //Citim numele clientului
    std::string nume_input;
    std::cout << "Nume: ";
    std::getline(std::cin, nume_input);
    client.setNume(nume_input);

    //Citim adresa clientului
    std::string strada, numar, bloc, apartament;
    std::cout << "Strada: ";
    std::getline(std::cin, strada);
    std::cout << "Numarul: ";
    std::getline(std::cin, numar);
    std::cout << "Blocul (Enter daca nu este cazul): ";
    std::getline(std::cin, bloc);
    std::cout << "Apartamentul (Enter daca nu este cazul): ";
    std::getline(std::cin, apartament);

    Adresa adresa(strada, numar, bloc, apartament);
    client.setAdresa(adresa);

    //Citim pizza clientului, mai intai alege dintr-un meniu apoi o modifica
    Pizza pizza; int option;
    std::cout << "Alegeti o pizza:\n1 - Clasica\n2 - Vegetariana\n3 - Pepperoni\n"
             << "4 - Quattro Stagioni\n5 - Mediteraneana\n6 - cu ton\n7 - Mexicana\n"
        << "8 - Carnivora\n9 - Preferata bucatarului <3\n0 - Creeaza propria pizza\n";
    std::cin >> option;
    if (option >= 1 && option <= 9)
    {
        pizza = pizzas[option - 1];
    }
    citire_pizza(pizza);
    client.setPizza(pizza);
}

void citire_pizza(Pizza& pizza)
{
    //Citire marime
    int size;
    std::cout << "Alege dimensiunea pizzei:\n1 - Mica\n2 - Medie\n3 - Mare\n ";
    std::cin >> size;

    // Daca utilizatorul este incapatanat...
    if (size >= 1 && size <= 3) pizza.setMarime(size);
    else
    {
        std::cout << "Dimensiune invalida, te alegi cu o pizza medie >:( \n";
        pizza.setMarime(2);
    }
    //Citire sos
    int sos_ales;
    std::cout << "Alegeti sosul:\n1 - Rosii\n2 - Iute\n3 - Barbeque\n";
    std::cin >> sos_ales;
    if (1 <= sos_ales && sos_ales <= 3)
        pizza.setSos(sos_ales);
    else
    {
        std::cout << "Alegere invalida, te alegi cu sos de rosii...\n";
        pizza.setSos(1);
    }
    std::string extra;
    std::cout << "Doriti sos extra? (y/n): ";
    std::cin >> extra;
    pizza.setExtraSos(extra == "y");
    //Citire branza...
    std::string numeBranza[] = {"", "mozzarella", "telemea", "cu mucegai",
        "cheddar", "parmezan"};
    bool exit = false;
    int option;
    while (!exit)
    {
        std::cout << "Alegeti branza (1-5):\n";
        pizza.selectieBranza();
        std::cin >> option;
        if (option == 6) exit = true;
        else if (1 > option || 6 < option)
        {
            std::cout << "Optiune invalida, mai incercati o data... \n";
            std::cin.ignore();
        }
        else
        {
            std::cout << "Doriti extra branza " << numeBranza[option] << "? (y/n)\n";
            std::cin >> extra;
            pizza.setBranza(option, (extra == "y"));
        }
    }
    //Citire carne....
    std::string numeCarne[] = {"", "carnati", "bacon", "sunca", "pepperoni", "chorizo",
        "vita", "pui", "ton"};
    exit = false;
    while (!exit)
    {
        std::cout << "Alegeti carne (1-8):\n";
        pizza.selectieCarne();
        std::cin >> option;
        if (option == 9) exit = true;
        else if (1 > option || 8 < option) std::cout << "Optiune invalida, mai incercati o data... \n";
        else
        {
            std::cout << "Doriti extra carne " << numeCarne[option] << "? (y/n)\n";
            std::cin >> extra;
            pizza.setCarne(option, (extra == "y"));
        }
    }
    //Citire legume...
    std::string numeLegume[] = {"", "muraturi", "masline", "porumb", "rosii", "paprika",
        "ceapa", "jalapeno", "ciuperci"};
    exit = false;
    while (!exit)
    {
        std::cout << "Alegeti legume (1-8):\n";
        pizza.selectieLegume();
        std::cin >> option;
        if (option == 9) exit = true;
        else if (1 > option || 8 < option) std::cout << "Optiune invalida, mai incercati o data... \n";
        else
        {
            std::cout << "Doriti extra " << numeLegume[option] << "? (y/n)\n";
            std::cin >> extra;
            pizza.setLegume(option, (extra == "y"));
        }
    }
    pizza.calculeazaPret();
}

void Pizza::selectieBranza() const
{
//Functia asta doar afiseaza meniul de branza,
//actualizat la alegerile facute
    std::string numeBranza[] = {"", "mozzarella", "telemea", "cu mucegai",
                            "cheddar", "parmezan"};
    for (int i = 1; i <= 5; i++)
    {
        std::cout << i << " - " << numeBranza[i] << " ";
        if (p_branza[i].extra) std::cout << "[+]";
        else if (p_branza[i].selected) std::cout << "[1]";
        else std::cout<<"[ ]";
        std::cout<<"\n";
    }
    std::cout<<"6 - Iesire\n";
}
void Pizza::selectieCarne() const
{
//Din nou, se afiseaza un meniu de carne, actualizat
    std::string numeCarne[] = {"", "carnati", "bacon", "sunca", "pepperoni", "chorizo",
                            "vita", "pui", "ton"};
    for (int i = 1; i <= 8; i++)
    {
        std::cout << i << " - " << numeCarne[i] << " ";
        if (p_carne[i].extra) std::cout << "[+]";
        else if (p_carne[i].selected) std::cout << "[1]";
        else std::cout << "[ ]";
        std::cout << "\n";
    }
    std::cout << "9 - Iesire\n";
}
void Pizza::selectieLegume() const
{
//Exact la fel ca la branza si carne, e oarecum copy-paste
//muraturi, masline, porumb, rosii, paprika, ceapa, jalapeno, ciuperci
    std::string numeLegume[] = {"", "muraturi", "masline", "porumb", "rosii", "paprika",
                            "ceapa", "jalapeno", "ciuperci"};
    for (int i = 1; i <= 8; i++)
    {
        std::cout << i << " - " << numeLegume[i] << " ";
        if (p_legume[i].extra) std::cout << "[+]";
        else if (p_legume[i].selected) std::cout << "[1]";
        else std::cout << "[ ]";
        std::cout << "\n";
    }
    std::cout << "9 - Iesire\n";
}

void Pizza::setBranza(const int index, bool extra)
{
    if (index >= 1 && index <= 5)
    {
        p_branza[index].extra = extra;
        p_branza[index].selected = true;
    }
}
void Pizza::setCarne(const int index, bool extra)
{
    if (index >=1 && index <= 8)
    {
        p_carne[index].extra = extra;
        p_carne[index].selected = true;
    }
}
void Pizza::setLegume(const int index, bool extra)
{
    if (index >=1 && index <= 8)
    {
        p_legume[index].extra = extra;
        p_legume[index].selected = true;
    }
}
void Pizza::calculeazaPret()
{
    // Pretul de baza este 23. medie + 13, mare + 25
    // Sos diferit de rosii + 5
    // FIECARE topping si fiecare extra + 5
    // desigur, preturile astea sunt foarte mari si ANPC-ul m-ar scoate din functiune
    // dar trebuie sa fac bani...
    p_pret = 23;
    if (p_marime == 2) p_pret += 13;
    else if (p_marime == 3) p_pret += 25;

    if (p_sos!=1) p_pret += 5;
    if (p_extra_sos) p_pret += 5;
    for (int i = 1; i <= 8; i++)
    {
        if (i <= 5 && p_branza[i].selected && i != 1) p_pret += 5;
        if (i <= 5 && p_branza[i].extra) p_pret += 5;
        if (p_carne[i].selected ) p_pret+=5;
        if (p_carne[i].extra) p_pret += 5;
        if (p_legume[i].selected) p_pret += 5;
        if (p_legume[i].extra) p_pret += 5;
    }
}


// Pizza clasica(1, 1, 1, 3, 8);
// Pizza vegetariana(1, 1, 1);
// Pizza pepperoni(1, 1);
// Pizza quattrostagioni(1, 1, 1);
// Pizza mediteraneana(1, 1, 1);
// Pizza cuTon(1, 1, 1, 8);
// Pizza mexicana(1, 1, 1, 2, 7);
// Pizza carnivora(1, 1, 1, 1);
// Pizza chefFav(1);
// void init_pizza()
// {
//     //Aici "gatim" meniul, pentru clientii fara mofturi
//     for (int i = 2; i <= 8; i++)
//     {
//         if (i == 7)continue;
//         vegetariana.setLegume(i);
//     }
//     pepperoni.setBranza(1, true);
//     pepperoni.setCarne(4, true);
//     quattrostagioni.setCarne(3); quattrostagioni.setCarne(5);
//     quattrostagioni.setLegume(8); quattrostagioni.setLegume(5);
//     cuTon.setLegume(2); cuTon.setLegume(3); cuTon.setLegume(6);
//     mediteraneana.setBranza(2);
//     mediteraneana.setLegume(3); mediteraneana.setLegume(4);
//     mediteraneana.setLegume(2); mediteraneana.setLegume(6);
//     mexicana.setCarne(5); mexicana.setCarne(3);
//     carnivora.setCarne(4); carnivora.setCarne(6); carnivora.setCarne(3);
// }
