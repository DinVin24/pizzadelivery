#include "adresa.h"
#include <string>
#include "pizza.h"

class Client {
    std::string nume;
    Adresa adresa;
    Pizza pizza;

public:
    // Constructor cu parametri
    Client(const std::string& nume_input = "",
       const Adresa& adresa_input = Adresa(),
       const Pizza& pizza_input = Pizza())
    : nume(nume_input), adresa(adresa_input), pizza(pizza_input) {}
    //Constructor de copiere
    Client(const Client& aux)
        : nume(aux.nume), adresa(aux.adresa), pizza(aux.pizza) {}
    //operator de copiere
    Client& operator=(const Client& aux) {
            if (this != &aux){
            nume = aux.nume;
            adresa = aux.adresa;
            pizza = aux.pizza;
            }
        return *this;
    }
    //deconstructor
    ~Client() {}

    // Setterz si getterz de nume
    void set_nume(const std::string& nume_input) { nume = nume_input; }
    const std::string& get_nume() const { return nume; }

    // setz si getz de adresa
    void set_adresa(const Adresa& adresa_input) { adresa = adresa_input; }
    const Adresa& get_adresa() const { return adresa; }

    // setz si getz de pizz
    void set_pizza(const Pizza& pizza_input) { pizza = pizza_input; }
    const Pizza& get_pizza() const { return pizza; }

    friend std::ostream& operator<<(std::ostream& os, const Client& client) {
    //overload la <<
        os << "Client: " << client.nume << "\n" << client.adresa << client.pizza;
        return os;
    }

};


