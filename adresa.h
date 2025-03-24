#include <string>
#include <iostream>

class Adresa
{
    std::string a_strada;
    std::string a_numarul;
    std::string a_bloc;
    std::string a_apartament;

public:
    // Constructor cu parametri
    Adresa(const std::string& strada_input = "", const std::string& numar_input = "",
           const std::string& bloc_input = "", const std::string& apartament_input = "")
        : a_strada(strada_input), a_numarul(numar_input),
        a_bloc(bloc_input), a_apartament(apartament_input) {}

    // Constructor de copiere
    Adresa(const Adresa& other)
        : a_strada(other.a_strada), a_numarul(other.a_numarul),
        a_bloc(other.a_bloc), a_apartament(other.a_apartament) {}

    // Operator de copiere
    Adresa& operator=(const Adresa& other)
    {
        if (this != &other)
        {
            a_strada = other.a_strada;
            a_numarul = other.a_numarul;
            a_bloc = other.a_bloc;
            a_apartament = other.a_apartament;
        }
        return *this;
    }

    // Destructor
    ~Adresa() {}

    // Getterz
    const std::string& getStrada() const { return a_strada; }
    const std::string& getNumarul() const { return a_numarul; }
    const std::string& getBloc() const { return a_bloc; }
    const std::string& getApartament() const { return a_apartament; }

    // Setterz
    void setStrada(const std::string& strada_input) { a_strada = strada_input; }
    void setNumarul(const std::string& numar_input) { a_numarul = numar_input; }
    void setBloc(const std::string& bloc_input) { a_bloc = bloc_input; }
    void setApartament(const std::string& apartament_input)
    {
        a_apartament = apartament_input;
    }

    // << overload
    friend std::ostream& operator<<(std::ostream& os, const Adresa& adresa)
    {
        os << "Strada: " << adresa.a_strada << "\nNumarul: " << adresa.a_numarul << "\n";
        if (!adresa.a_bloc.empty())
            os << "Blocul: " << adresa.a_bloc << "\nApartament: " << adresa.a_apartament <<'\n';
        return os;
    }
};
