#include <string>
#include <iostream>

class Adresa {
    std::string strada;
    std::string numarul;
    std::string bloc;
    std::string apartament;

public:
    // Constructor cu parametri
    Adresa(const std::string& strada_input = "", const std::string& numar_input = "",
           const std::string& bloc_input = "", const std::string& apartament_input = "")
        : strada(strada_input), numarul(numar_input), bloc(bloc_input), apartament(apartament_input) {}

    // Constructor de copiere
    Adresa(const Adresa& other)
        : strada(other.strada), numarul(other.numarul), bloc(other.bloc), apartament(other.apartament) {}

    // Operator de copiere
    Adresa& operator=(const Adresa& other) {
        if (this != &other) {  // Handle self-assignment
            strada = other.strada;
            numarul = other.numarul;
            bloc = other.bloc;
            apartament = other.apartament;
        }
        return *this;
    }

    // Destructor
    ~Adresa() {}

    // Getterz
    const std::string& get_strada() const { return strada; }
    const std::string& get_numarul() const { return numarul; }
    const std::string& get_bloc() const { return bloc; }
    const std::string& get_apartament() const { return apartament; }

    // Setterz
    void set_strada(const std::string& strada_input) { strada = strada_input; }
    void set_numarul(const std::string& numar_input) { numarul = numar_input; }
    void set_bloc(const std::string& bloc_input) { bloc = bloc_input; }
    void set_apartament(const std::string& apartament_input) { apartament = apartament_input; }

    // << overload
    friend std::ostream& operator<<(std::ostream& os, const Adresa& adresa) {
        os << "Strada: " << adresa.strada << "\nNumarul: " << adresa.numarul << "\n";
        if (!adresa.bloc.empty())
            os << "Blocul: " << adresa.bloc << "\nApartament: " << adresa.apartament <<'\n';
        return os;
    }
};
