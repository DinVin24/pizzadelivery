#include "adresa.h"
#include "pizza.h"
#include <string>

class Client
{
    std::string c_nume;
    Adresa c_adresa;
    Pizza c_pizza;

public:
    // Constructor cu parametri
    Client(const std::string& nume_input = "",
       const Adresa& adresa_input = Adresa(),
       const Pizza& pizza_input = Pizza())
    : c_nume(nume_input), c_adresa(adresa_input), c_pizza(pizza_input) {}
    //Constructor de copiere
    Client(const Client& aux)
        : c_nume(aux.c_nume), c_adresa(aux.c_adresa), c_pizza(aux.c_pizza) {}
    //operator de copiere
    Client& operator=(const Client& aux)
    {
            if (this != &aux){
            c_nume = aux.c_nume;
            c_adresa = aux.c_adresa;
            c_pizza = aux.c_pizza;
            }
        return *this;
    }
    //deconstructor
    ~Client() {}

    // Setterz si getterz de nume
    void setNume(const std::string& nume_input) { c_nume = nume_input; }
    const std::string& getNume() const { return c_nume; }

    // setz si getz de adresa
    void setAdresa(const Adresa& adresa_input) { c_adresa = adresa_input; }
    const Adresa& getAdresa() const { return c_adresa; }

    // setz si getz de pizz
    void setPizza(const Pizza& pizza_input) { c_pizza = pizza_input; }
    const Pizza& getPizza() const { return c_pizza; }

    friend std::ostream& operator<<(std::ostream& os, const Client& client)
    {
    //overload la <<
        os << "Client: " << client.c_nume << "\n" << client.c_adresa << client.c_pizza;
        return os;
    }

};


