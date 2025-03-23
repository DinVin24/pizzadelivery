#include "adresa.h"
#include <string>
#include "pizza.h"

class Client {
    std::string nume;  // Use std::string instead of char array
    Adresa adresa;
    Pizza pizza;

public:
    // Constructor to initialize the name and address
    Client(const std::string& nume_input = "",
           const Adresa& adresa_input = Adresa(),
           const Pizza& pizza_input = Pizza())
        : nume(nume_input), adresa(adresa_input), pizza(pizza_input) {}

    // Setter and Getter functions for name
    void set_nume(const std::string& nume_input) { nume = nume_input; }
    const std::string& get_nume() const { return nume; }

    // Setter and Getter functions for address
    void set_adresa(const Adresa& adresa_input) { adresa = adresa_input; }
    const Adresa& get_adresa() const { return adresa; }

    void set_pizza(const Pizza& pizza_input) { pizza = pizza_input; }
    const Pizza& get_pizza() const { return pizza; }
};


