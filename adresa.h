class Adresa{
    char strada[100]={};
    char numarul[100]={};
    char bloc[50]={};
    char apartament[50]={};

public:

    void citire_adresa();
    void afisare_adresa();

    void set_numarul(){std::cin.getline(numarul,100);}
    void set_strada(){std::cin.getline(strada,100);}
    void set_apartament(){std::cin.getline(apartament,50);}
    void set_bloc(){std::cin.getline(bloc,50);}

    char* get_strada(){return strada;}
    char* get_numarul(){return numarul;}
    char* get_bloc(){return bloc;}
    char* get_apartament(){return apartament;}

};

