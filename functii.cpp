#include <iostream>
#include "client.h"
#include <fstream>
std::ifstream fin ("input.txt");

// Function to read client data
void citire_pizza(Pizza& pizza);
void citire_date(Client& client) {
    std::string nume_input;
    std::cout << "Nume: ";
    std::getline(std::cin, nume_input);
    client.set_nume(nume_input);

    // Now, reading the address
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
    client.set_adresa(adresa);
    Pizza pizza;
    citire_pizza(pizza);
    client.set_pizza(pizza);

}

void citire_pizza(Pizza& pizza) {
    //Citire marime
    int size;
    std::cout << "Alege dimensiunea pizzei:\n1 - Mica\n2 - Medie\n3 - Mare\n ";
    std::cin >> size;

    // Daca utilizatorul este incapatanat...
    if (size >= 1 && size <= 3) {
        pizza.set_marime(size);
        if (size == 2) pizza.set_pret(pizza.get_pret() + 13);
        else if (size == 3) pizza.set_pret(pizza.get_pret() + 25);
    } else {
        std::cout << "Dimensiune invalida, te alegi cu o pizza medie >:( \n";
        pizza.set_marime(2);
        pizza.set_pret(pizza.get_pret() + 13);
    }
    //Citire sos
    int sos_ales;
    std::cout << "Alegeti sosul:\n1 - Rosii\n2 - Iute\n3 - Barbeque\n";
    std::cin >> sos_ales;
    if (1<=sos_ales && sos_ales<=3)
        pizza.set_sos(sos_ales);
    else {
        std::cout<<"Alegere invalida, te alegi cu sos de rosii...\n";
        pizza.set_sos(1);
    }
    std::string extra;
    std::cout<<"Doriti sos extra? (y/n): ";
    std::cin>>extra;
    pizza.set_extra_sos(extra == "y");
    //Actualizare pret
    if (sos_ales != 1)pizza.set_pret(pizza.get_pret() + 5);
    if (extra=="y")pizza.set_pret(pizza.get_pret() + 5);
    //Citire branza...
    std::string numeBranza[]={"","mozzarella","telemea","cu mucegai","cheddar","parmezan"};
    bool exit = false;
    int option;
    while (!exit) {
        std::cout<<"Alegeti branza (1-5):\n";
        pizza.selectie_branza();
        std::cin>>option;
        if (option == 6) exit = true;
        else if (1>option || 6<option) std::cout<<"Optiune invalida, mai incercati o data... \n";
        else {
            pizza.branza[option].selected = true;
            std::cout<<"Doriti extra branza "<< numeBranza[option] <<"? (y/n)\n";
            std::cin>>extra;
            pizza.branza[option].extra = (extra == "y");
        }
    }
    //Citire carne....
    std::string numeCarne[]={"","carnati","bacon","sunca","pepperoni","chorizo","vita","pui","ton"};
    exit = false;
    while (!exit) {
        std::cout<<"Alegeti carne (1-8):\n";
        pizza.selectie_carne();
        std::cin>>option;
        if (option == 9) exit = true;
        else if (1>option || 8<option) std::cout<<"Optiune invalida, mai incercati o data... \n";
        else {
            pizza.carne[option].selected = true;
            std::cout<<"Doriti extra carne "<<numeCarne[option] <<"? (y/n)\n";
            std::cin>>extra;
            pizza.carne[option].extra = (extra == "y");
        }
    }
    //Citire legume...
    std::string numeLegume[]={"","muraturi","masline","porumb","rosii","paprika","ceapa","jalapeno","ciuperci"};
    exit = false;
    while (!exit) {
        std::cout<<"Alegeti legume (1-8):\n";
        pizza.selectie_legume();
        std::cin>>option;
        if (option == 9) exit = true;
        else if (1>option || 8 < option) std::cout<<"Optiune invalida, mai incercati o data... \n";
        else {
            pizza.legume[option].selected = true;
            std::cout<<"Doriti extra "<<numeLegume[option]<<"? (y/n)\n";
            std::cin>>extra;
            pizza.legume[option].extra = (extra == "y");
        }
    }
}

void Pizza::selectie_branza() const{
    std::string numeBranza[]={"","mozzarella","telemea","cu mucegai","cheddar","parmezan"};
    for (int i=1;i<=5;i++) {
        std::cout<<i<<" - "<<numeBranza[i]<<" ";
        if (branza[i].extra) std::cout<<"[+]";
        else if (branza[i].selected) std::cout<<"[1]";
        else std::cout<<"[ ]";
        std::cout<<"\n";
    }
    std::cout<<"6 - Iesire\n";
}
void Pizza::selectie_carne() const {
    //carnati, bacon, sunca, pepperoni, chorizo, vita, pui, ton
    std::string numeCarne[]={"","carnati","bacon","sunca","pepperoni","chorizo","vita","pui","ton"};
    for (int i=1;i<=8;i++) {
        std::cout<<i<<" - "<<numeCarne[i]<<" ";
        if (carne[i].extra) std::cout<<"[+]";
        else if (carne[i].selected) std::cout<<"[1]";
        else std::cout<<"[ ]";
        std::cout<<"\n";
    }
    std::cout<<"9 - Iesire\n";
}
void Pizza::selectie_legume() const {
    //muraturi, masline, porumb, rosii, paprika, ceapa, jalapeno, ciuperci
    std::string numeLegume[]={"","muraturi","masline","porumb","rosii","paprika","ceapa","jalapeno","ciuperci"};
    for (int i=1;i<=8;i++) {
        std::cout<<i<<" - "<<numeLegume[i]<<" ";
        if (legume[i].extra) std::cout<<"[+]";
        else if (legume[i].selected) std::cout<<"[1]";
        else std::cout<<"[ ]";
        std::cout<<"\n";
    }
    std::cout<<"9 - Iesire\n";
}

void Pizza::set_branza(int index, bool extra) {
    if (index >=1 && index <= 6) {
        branza[index].extra = extra;
        branza[index].selected = true;
        if (index != 1)pret+=5;
        if (extra) pret+=5;
    }
}
void Pizza::set_carne(int index, bool extra) {
    if (index >=1 && index <= 8) {
        carne[index].extra = extra;
        carne[index].selected = true;
        pret+=5;
        if (extra) pret+=5;
    }
}
void Pizza::set_legume(int index, bool extra) {
    if (index >=1 && index <= 8) {
        legume[index].extra = extra;
        legume[index].selected = true;
        pret+=5;
        if (extra) pret+=5;
    }
}

