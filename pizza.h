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
 *
 *  totodata, ar trebui sa poti selecta intre pizza deja facute sau sa-ti creezi propria ta pizza.
 */

//char branza[1001]={};
//char carne[1001]={};
//char legume[1001]={};


class Pizza {
    int marime;//1-mica 2-medie 3-mare
    int sos; //  rosii/iute/barbeque
    bool extra_sos;
public:
    struct Branza {
        bool selected = false;
        bool extra = false;
    }branza[6];
    Pizza(int m=2): marime(m),sos(1),extra_sos(false) {}

    int get_marime() const {return marime;}
    void set_marime(int m) {marime=m;}

    void set_sos(int s) {sos=s;}
    int get_sos() const {return sos;}

    void set_extra_sos(bool e) {extra_sos=e;}
    bool get_extra_sos() const {return extra_sos;}

    void set_branza(int index, bool extra);
    void selectie_branza()const;

};
