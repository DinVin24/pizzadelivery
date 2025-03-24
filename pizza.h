/*  Okay deci pe domino's cand intri, poti selecta intre mica/mare/medie
 *  Sosuri: rosii, iute, barbeque. La toate poti adauga optiunea de extra, un BOOL
 *  Branza: Telemea, cu mucegai, cheddar, parmezan, toate au iarasi optiunea extra
 *  CARNE: carnati, bacon, sunca, pepperoni, chorizo, vita, pui, ton
 *  LEGUME: muraturi, masline, porumb, rosii, paprika, ceapa, jalapeno, ciuperci
 *
 *  poti avea UN singur sos, la restul poti adauga cate vrei din optiuni, +extra
 *  poti sa nu pui nimic, sa ai 0 ingrediente, doar blat cu sos de rosii.
 *
 *  Pretul de baza este 23. medie + 13, mare + 25
 *  Sos diferit de rosii + 5
 *  FIECARE topping si fiecare extra + 5
 */

class Pizza
{
    int p_marime;//1-mica 2-medie 3-mare
    int p_sos; //  rosii/iute/barbeque
    int p_pret = 23;
    bool p_extra_sos;
    struct Branza
    {//"mozzarella","telemea","cu mucegai","cheddar","parmezan"
        bool selected = false;
        bool extra = false;
    }p_branza[6];
    struct Carne
    {
        //"carnati","bacon","sunca","pepperoni","chorizo","vita","pui","ton"
        bool selected = false;
        bool extra = false;
    }p_carne[9];
    struct Legume
    {
    //"muraturi","masline","porumb","rosii","paprika","ceapa","jalapeno","ciuperci"
        bool selected = false;
        bool extra = false;
    }p_legume[9];
public:
    // Constructor cu parametri
    Pizza(int m=1, int s=1,int b=0, int c=0, int l=0): p_marime(m), p_sos(s), p_extra_sos(false)
    {
//urmatoarele for-uri functioneaza mai bine pt pizza mai simple, cu cate un singur topping
//pentru celelalte, folosim functiile setter
        int i;
        for (i = 1; i <= 5; i++)
        {
            p_branza[i].selected = false;
            p_branza[i].extra = false;
            if (i == b) p_branza[i].selected = true;
        }
        for (i = 1; i <= 8; i++)
        {
            p_carne[i].selected = false;
            p_carne[i].extra = false;
            if (i == c) p_carne[i].selected = true;
            p_legume[i].selected = false;
            p_legume[i].extra = false;
            if (i == l) p_legume[i].selected = true;
        }
    }
    //Constructor de copiere
    Pizza(const Pizza& other)
    : p_marime(other.p_marime), p_sos(other.p_sos), p_pret(other.p_pret), p_extra_sos(other.p_extra_sos)
    {
        for (int i = 0; i < 6; i++)
        {
            p_branza[i] = other.p_branza[i];
        }
        for (int i = 0; i < 9; i++)
        {
            p_carne[i] = other.p_carne[i];
            p_legume[i] = other.p_legume[i];
        }
    }
    // Operator de copiere
    Pizza& operator=(const Pizza& other)
    {
        if (this != &other)
        {
            p_marime = other.p_marime;
            p_sos = other.p_sos;
            p_pret = other.p_pret;
            p_extra_sos = other.p_extra_sos;
            for (int i = 0; i < 6; i++)
            {
                p_branza[i] = other.p_branza[i];
            }
            for (int i = 0; i < 9; i++)
            {
                p_carne[i] = other.p_carne[i];
                p_legume[i] = other.p_legume[i];
            }
        }
        return *this;
    }
    //Deconstructor
    ~Pizza() {}

    //getteri si setteri, destul de specific denumiti...
    int getMarime() const { return p_marime; }
    void setMarime(int m) { p_marime=m; }

    void setSos(int s) { p_sos=s; }
    int getSos() const { return p_sos; }

    void setExtraSos(bool e) { p_extra_sos = e; }
    bool getExtraSos() const { return p_extra_sos; }

    void setBranza(const int index, bool extra=false);
    void selectieBranza()const;

    void setCarne(const int index, bool extra=false);
    void selectieCarne()const;

    void setLegume(const int index, bool extra=false);
    void selectieLegume()const;

    const int& getPret()const { return p_pret; }
    void setPret(int p) { p_pret = p; }
    void calculeazaPret();

    friend std::ostream& operator<<(std::ostream& os, const Pizza& pizza)
    {
    //overload la <<
        //Afisarea dimensiunii
        os << "Dimensiunea pizzei este: ";
        switch (pizza.getMarime())
        {
            case 1:
                os << "mica\n";
                break;
            case 2:
                os << "medie\n";
                break;
            case 3:
                os << "mare\n";
                break;
        }
        //Afisarea sosului
        os << "Sos: ";
        if (pizza.getExtraSos()) os << "EXTRA ";
        switch (pizza.getSos())
        {
            case 1:
                os << "Rosii\n";
            break;
            case 2:
                os << "Iute\n";
            break;
            case 3:
                os << "Barbeque\n";
            break;
        }
        //Afisare branza
        os << "Branza: \n";
        const std::string numeBranza[]={"", "mozzarella", "telemea", "cu mucegai",
            "cheddar", "parmezan"};
        for (int i = 1; i <= 5; i++)
        {
            if (pizza.p_branza[i].selected)
            {
                os << " - ";
                if (pizza.p_branza[i].extra) os << "extra ";
                os << numeBranza[i]<<'\n';
            }
        }
        //Afisare carne
        os << "Carne: \n";
        const std::string numeCarne[]={"", "carnati", "bacon", "sunca", "pepperoni",
            "chorizo", "vita", "pui", "ton"};
        for (int i = 1; i <= 8; i++)
        {
            if (pizza.p_carne[i].selected)
            {
                os << " - ";
                if (pizza.p_carne[i].extra) os << "extra ";
                os << numeCarne[i] << '\n';
            }
        }
        //Afisare legume
        os << "Legume: \n";
        const std::string numeLegume[]={"", "muraturi", "masline", "porumb", "rosii",
            "paprika", "ceapa", "jalapeno", "ciuperci"};
        for (int i = 1; i <= 8; i++)
        {
            if (pizza.p_legume[i].selected)
            {
                os << " - ";
                if (pizza.p_legume[i].extra) os << "extra ";
                os << numeLegume[i] << '\n';
            }
        }
        //Afisare pret
        os << "Pret: " << pizza.getPret() << '\n';
        return os;
    }

};
