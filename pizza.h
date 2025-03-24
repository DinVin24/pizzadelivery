/*  Okay deci pe domion's cand intri, poti selecta intre mica/mare/medie
 *  Poti selecta si tipul de blat dar bucataria noastra nu dispune de astfel de tehnologii...
 *  Topping-uri default sunt sos de pizza si mozzarella
 *  Sosuri quirky: iute, barbeque. La toate poti adauga optiunea de extra, un BOOL
 *  Branza quirky: Telemea, cu mucegai, cheddar, parmezan, toate au iarasi optiunea extra
 *  CARNE: carnati, bacon, sunca, pepperoni, chorizo, vita, pui, ton
 *  LEGUME: muraturi, masline, porumb, rosii, paprika, ceapa, jalapeno, ciuperci
 *
 *  poti avea UN singur sos, la restul poti sa adaugi cate chestii vrei din optiunile alea, plus extra, evident
 *  totodata, poti sa nu pui nimic, sa ai 0 ingrediente, doar blat
 *
 *  la final ar fi cool sa calculezi pretul
 *  Pretul de baza este 23. medie + 13, mare + 25
 *  Sos diferit de rosii + 5
 *  FIECARE EXTRA + 5
 *  Branza + 5
 *  Carne + 5
 *  Legume + 5
 *  totodata, ar trebui sa poti selecta intre pizza deja facute sau sa-ti creezi propria ta pizza.
 */

class Pizza {
    int marime;//1-mica 2-medie 3-mare
    int sos; //  rosii/iute/barbeque
    int pret=23;
    bool extra_sos;
public:
    struct Branza {//"mozzarella","telemea","cu mucegai","cheddar","parmezan"
        bool selected = false;
        bool extra = false;
    }branza[6];
    struct Carne {//"carnati","bacon","sunca","pepperoni","chorizo","vita","pui","ton"
        bool selected = false;
        bool extra = false;
    }carne[9];
    struct Legume {//"muraturi","masline","porumb","rosii","paprika","ceapa","jalapeno","ciuperci"
        bool selected = false;
        bool extra = false;
    }legume[9];

    // Constructor cu parametri
    Pizza(int m=1, int s=1,int b=0, int c=0, int l=0): marime(m),sos(s),extra_sos(false) {
        int i;
        for (i=1;i<=5;i++) {
            branza[i].selected = false;
            branza[i].extra = false;
            if (i==b) branza[i].selected = true;
        }
        for (i=1;i<=8;i++) {
            carne[i].selected = false;
            carne[i].extra = false;
            if (i==c) carne[i].selected = true;
            legume[i].selected = false;
            legume[i].extra = false;
            if (i==l) legume[i].selected = true;
        }
    }
    //Constructor de copiere
    Pizza(const Pizza& other)
    : marime(other.marime), sos(other.sos), pret(other.pret), extra_sos(other.extra_sos) {
        for (int i = 0; i < 6; i++) {
            branza[i] = other.branza[i];
        }
        for (int i = 0; i < 9; i++) {
            carne[i] = other.carne[i];
            legume[i] = other.legume[i];
        }
    }
    // Operator de copiere
    Pizza& operator=(const Pizza& other) {
        if (this != &other) {  // Avoid self-assignment
            marime = other.marime;
            sos = other.sos;
            pret = other.pret;
            extra_sos = other.extra_sos;
            for (int i = 0; i < 6; i++) {
                branza[i] = other.branza[i];
            }
            for (int i = 0; i < 9; i++) {
                carne[i] = other.carne[i];
                legume[i] = other.legume[i];
            }
        }
        return *this;
    }
    //Deconstructor
    ~Pizza() {}

    //getteri si setteri, destul de specific denumiti...
    int get_marime() const {return marime;}
    void set_marime(int m) {marime=m;}

    void set_sos(int s) {sos=s;}
    int get_sos() const {return sos;}

    void set_extra_sos(bool e) {extra_sos=e;}
    bool get_extra_sos() const {return extra_sos;}

    void set_branza(int index, bool extra);
    void selectie_branza()const;

    void set_carne(int index, bool extra);
    void selectie_carne()const;

    void set_legume(int index, bool extra);
    void selectie_legume()const;

    int get_pret()const {return pret;}
    void set_pret(int p) {pret=p;}

    friend std::ostream& operator<<(std::ostream& os, const Pizza& pizza) {
        //Afisarea dimensiunii
        os << "Dimensiunea pizzei este: ";
        switch (pizza.get_marime()) {
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
        if (pizza.get_extra_sos()) os<<"EXTRA ";
        switch (pizza.get_sos()) {
            case 1:
                os<<"Rosii\n";
            break;
            case 2:
                os<<"Iute\n";
            break;
            case 3:
                os<<"Barbeque\n";
            break;
        }
        //Afisare branza
        os << "Branza: \n";
        std::string numeBranza[]={"","mozzarella","telemea","cu mucegai","cheddar","parmezan"};
        for (int i=1;i<=5;i++) {
            if (pizza.branza[i].selected) {
                os << " - ";
                if (pizza.branza[i].extra) os<<"extra ";
                os<<numeBranza[i]<<'\n';
            }
        }
        //Afisare carne
        os<<"Carne: \n";
        std::string numeCarne[]={"","carnati","bacon","sunca","pepperoni","chorizo","vita","pui","ton"};
        for (int i=1;i<=8;i++) {
            if (pizza.carne[i].selected) {
                os<<" - ";
                if (pizza.carne[i].extra) os<<"extra ";
                os<<numeCarne[i]<<'\n';
            }
        }
        //Afisare legume
        os<<"Legume: \n";
        std::string numeLegume[]={"","muraturi","masline","porumb","rosii","paprika","ceapa","jalapeno","ciuperci"};
        for (int i=1;i<=8;i++) {
            if (pizza.legume[i].selected) {
                os<<" - ";
                if (pizza.legume[i].extra) os<<"extra ";
                os<<numeLegume[i]<<'\n';
            }
        }
        //Afisare pret
        os << "Pret: "<<pizza.get_pret()<<'\n';
        return os;
    }

};
