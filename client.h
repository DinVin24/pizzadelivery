#include "adresa.h"
#include <string>
#include "pizza.h"

class Client {
    std::string nume;  // Use std::string instead of char array
    Adresa adresa;

public:
    Pizza &pizza;
    // Constructor to initialize the name and address
    Client(const std::string& nume_input = "", const Adresa& adresa_input = Adresa())
        : nume(nume_input), adresa(adresa_input) {
    }

    // Setter and Getter functions for name
    void set_nume(const std::string& nume_input) { nume = nume_input; }
    const std::string& get_nume() const { return nume; }

    // Setter and Getter functions for address
    void set_adresa(const Adresa& adresa_input) { adresa = adresa_input; }
    const Adresa& get_adresa() const { return adresa; }

    const Pizza& get_pizza() const  { return pizza; }
};


