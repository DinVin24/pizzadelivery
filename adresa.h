#include <string>
#include <iostream>

class Adresa {
    std::string strada;
    std::string numarul;
    std::string bloc;
    std::string apartament;

public:
    // Constructor to initialize the address fields
    Adresa(const std::string& strada_input = "", const std::string& numar_input = "",
           const std::string& bloc_input = "", const std::string& apartament_input = "")
        : strada(strada_input), numarul(numar_input), bloc(bloc_input), apartament(apartament_input) {}

    // Getter functions
    const std::string& get_strada() const { return strada; }
    const std::string& get_numarul() const { return numarul; }
    const std::string& get_bloc() const { return bloc; }
    const std::string& get_apartament() const { return apartament; }

    // Setter functions
    void set_strada(const std::string& strada_input) { strada = strada_input; }
    void set_numarul(const std::string& numar_input) { numarul = numar_input; }
    void set_bloc(const std::string& bloc_input) { bloc = bloc_input; }
    void set_apartament(const std::string& apartament_input) { apartament = apartament_input; }

    // Function to display the address
    friend void afisare_adresa(const Adresa& adresa);
};