#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class IOinterface{
public:
    virtual istream& citire(istream&) = 0;
    virtual ostream& afisare(ostream&) const = 0;
};

class Creatura:public IOinterface{

protected:
    string nume;
    int varsta;
    float sanatate; // de la 0 pana la 100
    float fericire; // de la 0 pana la 100
    float hrana;    // de la 0 pana la 100, dar cu cat este mai mare, cu atat mai rau

public:
//getteri
    string getNume(){return this->nume;}
    int getVarsta(){return this->varsta;}
    float getSanatate(){return this->sanatate;}
    float getFericire(){return this->fericire;}
    float getHrana(){return this->hrana;}
//setteri
    void setNume(string nume){this->nume = nume;}
    void setVarsta(int varsta){this->varsta = varsta;}
    void setSanatate(float sanatate){this->sanatate = sanatate;}
    void setFericire(float fericire){this->fericire = fericire;}
    void setHrana(float hrana){this->hrana = hrana;}

//constructor default
    Creatura(string nume, int varsta, float sanatate, float fericire, float hrana);
//constructor fara parametrii
    Creatura();
//copy constructor
    Creatura( const Creatura& obj);
// operatorul =
    Creatura& operator=(const Creatura& obj);
//operatorul ++
    Creatura& operator++();
//operatorul --
    Creatura& operator--();

virtual string getTip(){return "creatura";}
virtual float staredeBine() const = 0;

virtual istream& citire(istream& in) {
    cout<<"\nNume: ";
    in>>this->nume;
    cout<<"\nVarsta: ";
    in>>this->varsta;
    sanatate = 70;
    fericire = 70;
    hrana = 30;
    return in;}

 virtual ostream& afisare(ostream& out) const {
     out<<"\nNume: "<<this->nume;
    out<<"\nVarsta: "<<this->varsta;
    out<<"\nSanatate: "<<this->sanatate;
    out<<"\nFericire: "<<this->fericire;
    out<<"\nHrana: "<<this->hrana;
    return out;}

//op>>
friend istream& operator >>(istream& in, Creatura& c){
    return c.citire(in);}
//op<<
friend ostream& operator <<(ostream& out, const Creatura& c)
    {return c.afisare(out);}

  ~Creatura(){}


    };

//constructor cu toti parametrii:
Creatura::Creatura(string nume, int varsta, float sanatate, float fericire, float hrana){
    this->nume = nume;
    this->varsta = varsta;
    this->sanatate = sanatate;
    this->fericire = fericire;
    this->hrana = hrana;}
//constructor fara parametrii
Creatura::Creatura()
    {this->nume = "Anonim";
    this->varsta = 10;
    this->sanatate = 70;
    this->fericire = 70;
    this->hrana = 30;}
//copyconstructor
Creatura::Creatura(const Creatura& obj)
    {this->nume = obj.nume;
    this->varsta = obj.varsta;
    this->sanatate = obj.sanatate;
    this->fericire = obj.fericire;
    this->hrana = obj.hrana;}
//op =
Creatura& Creatura::operator=(const Creatura& obj)
    {if (this!= &obj){
        this->nume = obj.nume;
    this->varsta = obj.varsta;
    this->sanatate = obj.sanatate;
    this->fericire = obj.fericire;
    this->hrana = obj.hrana;}
    return *this;}
//op ++
Creatura& Creatura::operator++()
    {this->hrana++;
    return *this;}
//op--
Creatura& Creatura::operator--()
    {this->hrana--;
    return *this;}


//--------------------------------------------------------------------------

class Dragon: virtual public Creatura{
protected:
    float marimeAripi;  //in cm ( min 0, max 500)
    bool ePericulos;  // 0 - prietenos, 1 - periculos

public:
    string getTip(){return "dragon";}
    bool getEPericulos(){return this->ePericulos;}
    void setMarimeAripi(bool marimeAripi){this->marimeAripi= marimeAripi;}

//constructor cu toti parametrii
Dragon(string nume, int varsta, float sanatate, float fericire, float hrana, float marimeAripi, bool ePericulos):
    Creatura(nume, varsta, sanatate, fericire, hrana){this->marimeAripi = marimeAripi;
                                                    this->ePericulos = ePericulos;}

//constructor default
Dragon():Creatura(){
        this->marimeAripi = 0;
        this->ePericulos = 0;}

//copyconstructor
Dragon(const Dragon& obj):Creatura(obj){
    this->marimeAripi = obj.marimeAripi;
    this->ePericulos = obj.ePericulos;}

//op=
Dragon& operator=(const Dragon& obj){
    if( this!=&obj){
        Creatura::operator=(obj);
        this->marimeAripi = obj.marimeAripi;
        this->ePericulos = obj.ePericulos;}
    return *this;}

virtual istream& citire(istream& in){
    Creatura::citire(in);
    cout<<"\nMarime Aripi =";
    in>>this->marimeAripi;
    cout<<"\nE periculos? 1/0 :";
    in>>this->ePericulos;
    return in;}


virtual ostream& afisare(ostream& out) const{
    Creatura::afisare(out);
    out<<"\nMarime aripi: "<<this->marimeAripi;
    out<<"\n E periculos? "<<(this->ePericulos ? "Da" : "Nu");
    return out;}

virtual float staredeBine() const{
    float procent = 0.0;
    procent = fericire + sanatate + fabs(100-hrana);
    procent = procent/3;
    return procent; }

~Dragon(){}
};


class Zana:virtual public Creatura{
protected:
    string culoare;
    bool abilitateVindecare;
public:
    string getTip(){return "zana";}
    bool getAblitateVindecare(){return this->abilitateVindecare;}
    void setAbilitateVindecare(){this->abilitateVindecare = abilitateVindecare;}

//constructor default
Zana():Creatura(){
    this->abilitateVindecare = 1;
    this->culoare = "rosu";}

//constructor cu toti parametrii
Zana(string nume, int varsta, float sanatate, float fericire, float hrana, string culoare, bool abilitateVindecare):
    Creatura(nume, varsta,sanatate,fericire,hrana){this->culoare = culoare;
                                                    this->abilitateVindecare = abilitateVindecare;}
//copyconstructor
Zana(const Zana& obj):Creatura(obj){
    this->abilitateVindecare = obj.abilitateVindecare;
    this->culoare = culoare;}
//op=
Zana& operator=(const Zana& obj){
    if (this!=&obj){
        Creatura::operator=(obj);
        this->abilitateVindecare = obj.abilitateVindecare;
        this->culoare = obj.culoare;}
        return *this;}


virtual istream& citire(istream& in){
    Creatura::citire(in);
    cout<<"\nCuloare: ";
    in>>this->culoare;
    cout<<"\nAbilitate vindecare : 1/0 :";
    in>>this->abilitateVindecare;
    return in;}

virtual ostream& afisare(ostream& out) const{
    Creatura::afisare(out);
    out<<"\nCuloare : "<<this->culoare;
    out<<"\nAbilitate Vindecare : "<<(this->abilitateVindecare ? "Da" : "Nu");
    return out;}

virtual float staredeBine() const{
    float procent = 0.0;
    procent = fericire + sanatate + fabs(100-hrana);
    procent = procent/3;
    return procent; }

~Zana(){}
};


class Fantastic: public Dragon, public Zana{
private:
    string puteri[3] = { "foc", "apa", "gheata" };
    string putereMagica;
public:
    string getTip(){return "animal fantastic";}
    //constructor cu toti parametrii
    Fantastic(string nume, int varsta, float sanatate, float fericire, float hrana, float marimeAripi,
            bool ePericulos, string culoare, bool abilitateVindecare):
                Creatura(nume, varsta,sanatate,fericire,hrana),
                Dragon(nume, varsta, sanatate, fericire,hrana,marimeAripi,ePericulos),
                Zana(nume, varsta,sanatate,fericire,hrana,culoare,abilitateVindecare){
                    this->puteri[0] = puteri[0];
                    this->puteri[1] = puteri[1];
                    this->puteri[2] = puteri[2];
                    srand(time(NULL));
                    this->putereMagica = puteri[rand()%3];}
    //constructor fara parametrii
    Fantastic():Dragon(),Zana(){
        srand(time(NULL));
        this->putereMagica = puteri[rand()%3];}
    //copyconstructor
    Fantastic(const Fantastic& obj):Dragon(obj),Zana(obj){
        this->puteri[0] = obj.puteri[0];
        this->puteri[1] = obj.puteri[1];
        this->puteri[2] = obj.puteri[2];
        this->putereMagica = obj.putereMagica;}
    //op=
    Fantastic& operator=(const Fantastic& obj){
        if(this!=&obj){
            Dragon::operator=(obj);
            Zana::operator=(obj);
            this->puteri[0] = obj.puteri[0];
            this->puteri[1] = obj.puteri[1];
            this->puteri[2] = obj.puteri[2];
            this->putereMagica = obj.putereMagica;}
        return *this;}
    //citire afisare

    istream& citire(istream& in){
        Creatura::citire(in);
        cout<<"\nCuloare: ";
        in>>this->culoare;
        cout<<"\nAbilitate vindecare : 1/0 :";
        in>>this->abilitateVindecare;
        cout<<"\nMarime Aripi =";
        in>>this->marimeAripi;
        cout<<"\nE periculos? 1/0 :";
        in>>this->ePericulos;

        return in; }

    ostream& afisare( ostream& out)const{
        Creatura::afisare(out);
        out<<"\nCuloare : "<<this->culoare;
        out<<"\nAbilitate Vindecare : "<<(this->abilitateVindecare ? "Da" : "Nu");
        out<<"\nMarime aripi: "<<this->marimeAripi;
        out<<"\nE periculos? "<<(this->ePericulos ? "Da" : "Nu");
        out<<"\nPutere Magica : "<<this->putereMagica;
        return out;}

    virtual float staredeBine() const{
        float procent = 0.0;
        procent = fericire + sanatate + abs(100-hrana);
        procent = procent/3;
        return procent+5; }

    virtual ~Fantastic() {}


    };


//----------------

class JucarieMancare{
private:

    float happy;
    float health;
    float hunger;

public:

    float getHappy(){return this->happy;}
    float getHealth(){return this->health;}
    float getHunger(){return this->health;}

    //constructor:
    JucarieMancare( float happy, float health, float hunger){
        this->happy = happy;
        this->health = health;
        this->hunger = hunger;}

    };






class JocNou{
private:
    Creatura* creatura;
public:

friend istream& operator>>(istream& in , JocNou& obj){
        cout<< "\n1. Dragon\n";
        cout<< "2. Zana\n";
        cout<<" 3. Dragon Zanatic\n";
        int k;
        cin>>k;
        if( k==1) obj.creatura = new Dragon();
        else if( k==2) obj.creatura = new Zana();
        else if (k==3) obj.creatura = new Fantastic();
        in>> *obj.creatura;
        return in;
        }
friend ostream& operator<<(ostream& out, const JocNou& obj){
        out<<"\nCreatura: \n"<< *obj.creatura<<endl;
        return out;}


Creatura* getCreatura(){return this->creatura;}

/*
 ~JocNou() {if (creatura != NULL) {
            delete creatura;
            creatura = NULL;}}

*/

};


class Jocuri{

vector<Creatura*> listaJocuri;

public:
   Jocuri(){ listaJocuri = {};}

    vector<Creatura*> getListaJocuri() {
        return listaJocuri;}


void addJoc() {
    JocNou jocNouu;
    cin >> jocNouu;

   Creatura* creaturaa = jocNouu.getCreatura();
    listaJocuri.push_back(creaturaa);
}

    void afisareJocuri(){
        if(listaJocuri.empty()) {
            cout << "Nu exista jocuri in lista.\n";
            return;
        }
        cout << "Jocuri disponibile: \n";
        for(int i = 0; i < listaJocuri.size(); i++) {
            cout << i+1 << ". " << *listaJocuri[i] << endl;
        }
        }

    void stergereJoc(int k) {
    if(k < 1 || k > listaJocuri.size()) {
        cout << "Index invalid. Selectati un index valid.\n";
        return;
    }
    delete listaJocuri[k-1];
    listaJocuri.erase(listaJocuri.begin() + k-1);
    cout << "Jocul a fost sters cu succes.\n";
}
/*
~Jocuri() {

    for (auto it = listaJocuri.begin(); it != listaJocuri.end(); ++it) {
        delete (*it);}

    listaJocuri.clear();
}
*/

};

//-----------------------------------------



void CenterSteluta( const string &str,const int padding)
    {for (int i = 0; i < padding; ++i) cout <<"* ";
    cout << str;
    for (int i = 0; i < padding; ++i) cout <<"* ";}

void CenterLiniuta( const string &str,const int padding)
    {for (int i = 0; i < padding; ++i) cout <<"~";
    cout << str;
    for (int i = 0; i < padding; ++i) cout <<"~";}

void Center(const string &str, const int padding)
    {for( int i = 0; i< padding; ++i) cout<<" ";
    cout<<str;
    for(int i = 0; i< padding; ++i) cout<< " ";}

void Antet(){ CenterSteluta("", 33);
cout<<endl;
CenterSteluta("", 66);
CenterLiniuta("TARAMUL CREATURILOR MAGICE",52);
cout<<endl;
CenterSteluta("", 66);
cout<<endl<<endl;}

void PrimaPagina(){
    Antet();
    cout<<"  ***";
    Center("Bine ati venit!", 55);
    cout<< "***";

Center("Pentru a avea grija de animalutul dumneavoastra, trebuie sa stiti cateva detalii!",22);
cout<<endl;
Center("Nivelul satisfactiei animalutului este inregistrata in 3 mari zone: Sanatate , Fericire si Hrana.",14);
cout<<endl<<endl;
Center("Cu cat sanatatea este mai mare, cu atat animalul este mai strasnic si energic. Aceasta poate fi sustinuta si crescuta prin joaca,     miscare si hrana sanatoasa.",3);
cout<<endl<<endl;
Center("Cu cat fericirea este mai mare, cu atat animalul este mai bucuros. Aceasta poate fi sustinuta prin joaca si mancare gustoasa,           dar nesanatoasa. Aveti grija insa la sanatatea sa!",3);
cout<<endl<<endl;
Center("Atentie! Cu cat nivelul de hrana este mai mare, animalutul este mai flamand! Aveti grija insa la mancarea delicioasa, dar              nesanatoasa, poate afecta starea de sanatate!",3);
}


void welcome(string jucator){
Antet();
cout<<"                                                             Bine te-am gasit, "<<jucator<<"!";}

void Animal(){
CenterSteluta("Alege-ti Personajul!",28);}

void DragonDesen(){
cout<<R"(                \||/
                |  @___oo
      /\  /\   / (__,,,,|
     ) /^\) ^\/ _)
     )   /^\/   _)
     )   _ /  / _)
 /\  )/\/ ||  | )_)
<  >      |(,,) )__)
 ||      /    \)___)\
 | \____(      )___) )___
  \______(_______;;; __;;;))"<<endl;
  cout<<"      Dragonul";
  }

void ZanaDesen(){
cout<<R"( __       __          .--.
(  ""--__(  ""-_    ,' .-.\        *
 "-_ __  ""--__ "-_(  (^_^))      /
    (  """--___""--__" )-'(      /
     "-__      ""---/ ,(., )__o-/,
         """----___(.'.   /--"--'
                   ("-_"/(    /
                    \   \ \
                     `.  \ |
                       \  \/
                       ||  \
                     ,-'/`. \
                     ) /   ) \
                     |/    `-.\
                              `\)"<<endl;
cout<<"      Zana";}

void DragonZanaticDesen(){
cout<<R"(
                          ___====-_  _-====___
           _--^^^#####//      \\#####^^^--_
        _-^##########// (    ) \\##########^-_
       -############//  |\^^/|  \\############-
     _/############//   (@::@)   \\############\_
    /#############((     \\//     ))#############\
   -###############\\    (oo)    //###############-
  -#################\\  / VV \  //#################-
 -###################\\/      \//###################-
_#/|##########/\######(   /\   )######/\##########|\#_
|/ |#/\#/\#/\/  \#/\##\  |  |  /##/\#/  \/\#/\#/\#| \|
`  |/  V  V  `   V  \#\| |  | |/#/  V   '  V  V  \|  '
   `   `  `      `   / | |  | | \   '      '  '   '
                    (  | |  | |  )
                   __\ | |  | | /__
                  (vvv(VVV)(VVV)vvv))"<<endl;
cout<< "       Dragon Zanatic";}

void Exit(){
    system("cls");
    Antet();
    cout<<endl<<endl;
    Center("Te mai asteptam pe la noi!",45);
    cout<<endl<<endl<<endl<<endl;}

void Status(Creatura* animal){
  cout<<"_______________________________";
  cout<<"| Nume : "<<animal->getNume();
  cout<<"| Sanatate : "<<animal->getSanatate();
  cout<<"| Fericire : "<<animal->getFericire();
  cout<<"| Hrana :"<<animal->getHrana();
  cout<<"_______________________________";}


Creatura* animal;

int main(){

JucarieMancare Sport(2,10,10);
JucarieMancare Minge(5,7,5);
JucarieMancare BaghetaMagica(10,2,3);

JucarieMancare Salata(0,7,-5);
JucarieMancare Hamburger(7,-6,-10);
JucarieMancare CartofiPrajiti(5,-4,-6);
JucarieMancare Friptura(4,1.5,-10);
JucarieMancare Gogoasa(10,-4,-2);

Jocuri jocuri;


string jucator;
int alegere;
//opening page
PrimaPagina();
cout<<endl<<endl<<endl<<endl;
cout<<"Pentru a incepe, va rugam introduceti-va numele:   \n";
cin>>jucator;


system("cls");
welcome(jucator);



cout<<" \n\n\nAlegeti dificultatea jocului:  \n     1.Usor\n     2.Normal\n     3.Greu\n     4.Parasiti jocul\n";
int dificultate;
cin>>dificultate;
 int alegerejoc;
switch(dificultate){
        case 1:   //usor
            {  {system("cls");
            Antet();
            cout<<endl<<endl;
            Animal();
            cout<<endl<<endl;
            DragonDesen();
            cout<<endl<<endl;
            system("pause");
            ///         SAU ZANA
            system("cls");
            welcome(jucator);
            cout<<endl<<endl;
            Animal();
            cout<<endl<<endl;
            ZanaDesen();
            system("pause");     //dragon zanatic
            system("cls");
            welcome(jucator);
            cout<<endl<<endl;
            Animal();
            cout<<endl<<endl;
            DragonZanaticDesen();
            system("pause");

            system("cls");
                cout<<endl;
                welcome(jucator);
                cout<<endl;
                Animal();
                cout<<endl<<endl<<endl;
                //_____________________________________________________________-


                do {

    cout << "\nDoriti inceperea unui joc nou sau continuarea unuia trecut? 1- joc nou, 2 - alegerea altui joc, alta tasta pentru a parasi jocul: ";
    cin >> alegerejoc;
int okiesire=0;
    switch (alegerejoc) {
        case 1:
           {

            jocuri.addJoc();
            animal = jocuri.getListaJocuri().back();
            cout << "\nAcesta este animalul cu care va veti juca: " << *animal;
            break;}

        case 2:
         {if (jocuri.getListaJocuri().empty()) {
                jocuri.addJoc();
            }
            else {
                jocuri.afisareJocuri();
                cout << "\nSelectati numarul jocului dorit: ";
                int x;
                cin >> x;
                while (x < 1 || x > jocuri.getListaJocuri().size()) {
                    cout << "Index invalid. Selectati un index valid.\n";
                    cin >> x;
                }
                animal = jocuri.getListaJocuri()[x-1];
                cout << "\nAcesta este animalul cu care va veti juca: " << *animal;
            }
            break;}

        default:
           {okiesire =1;
           Exit();
            break;
            }
    }//end of switch alegere joc


while(okiesire!=1){
bool playing = true;
while (playing) {
        system("cls");
        Antet();
        cout<<"Jucator : "<<jucator<<endl;
        if (animal->getSanatate() <= 0)
            {cout << "Nu ati oferit destula grija animalutul dumneavoastra. Ca urmare, Game over!" << endl;
            break;}




         cout<<endl;
        Status(animal);
        if (animal->getTip() == "dragon") DragonDesen();
        else if (animal->getTip() == "zana"){ ZanaDesen();
                                            }
        else if(animal->getTip()== "animal fantastic"){ DragonZanaticDesen();
                                                        }
       int choice;
           do {
        cout << "\nCe doriti sa faceti?   1 - hraneste animalutul   |   2 - joaca-te cu animalutul   |   alta tasta - exit\n";
        cin >> choice;

       switch(choice){
        case 1: //mancare
            {cout<<"\nCe doriti sa manance animalutul?\n  1.Salata 2.Hamburger 3. Cartofi Prajiti 4. Friptura 5. Gogoasa ";
                int mancare;
                cin>>mancare;
                switch(mancare){
                  case 1: //salata
                      {if (animal->getSanatate() + Salata.getHealth()<=100)
                        animal->setSanatate(animal->getSanatate() + Salata.getHealth());
                    if(animal->getHrana()+ Salata.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Salata.getHunger());
                    if (animal->getFericire() + Salata.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Salata.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  case 2://hamburger
                      {if( animal->getSanatate() + Hamburger.getHealth()<=100)
                          animal->setSanatate(animal->getSanatate() + Hamburger.getHealth());
                    if(animal->getHrana()+ Hamburger.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Hamburger.getHunger());
                    if(animal->getFericire() + Hamburger.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Hamburger.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  case 3://cartofiprajiti
                      {if (animal->getSanatate() + CartofiPrajiti.getHealth()<=100)
                          animal->setSanatate(animal->getSanatate() + CartofiPrajiti.getHealth());
                    if (animal->getHrana()+ CartofiPrajiti.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ CartofiPrajiti.getHunger());
                    if(animal->getFericire() + CartofiPrajiti.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + CartofiPrajiti.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  case 4://friptura
                      {if (animal->getSanatate() + Friptura.getHealth()<=100)
                          animal->setSanatate(animal->getSanatate() + Friptura.getHealth());
                    if(animal->getHrana()+ Friptura.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Friptura.getHunger());
                    if(animal->getFericire() + Friptura.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Friptura.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  case 5://gogoasa
                      {if(animal->getSanatate() + Gogoasa.getHealth()<=100)
                          animal->setSanatate(animal->getSanatate() + Gogoasa.getHealth());
                    if(animal->getHrana()+ Gogoasa.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Gogoasa.getHunger());
                    if(animal->getFericire() + Gogoasa.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Gogoasa.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  default:{cout<<"\nNe pare rau. Alegere invalida";
                    break;}
                            }

         break;   }

        case 2: //joaca
            {cout<<"Cu ce doriti sa va jucati cu animalutul? 1 - SPORT  |   2- Minge   |   3- Bagheta Magica\n";
            int joaca;
            cin>>joaca;

            switch(joaca){

            case 1: // sport
                     {if (animal->getSanatate() + Sport.getHealth()<=100)
                        animal->setSanatate(animal->getSanatate() + Sport.getHealth());
                    if(animal->getHrana()+ Sport.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Sport.getHunger());
                    if (animal->getFericire() + Sport.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Sport.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}

            case 2: //minge
                {if (animal->getSanatate() + Minge.getHealth()<=100)
                        animal->setSanatate(animal->getSanatate() + Minge.getHealth());
                    if(animal->getHrana()+ Minge.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Minge.getHunger());
                    if (animal->getFericire() + Minge.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Minge.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}

            case 3: //BaghetaMagica
                {if (animal->getSanatate() + BaghetaMagica.getHealth()<=100)
                        animal->setSanatate(animal->getSanatate() + BaghetaMagica.getHealth());
                    if(animal->getHrana()+ BaghetaMagica.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ BaghetaMagica.getHunger());
                    if (animal->getFericire() + BaghetaMagica.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + BaghetaMagica.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
            default:{cout<<"\nNe pare rau. Alegere invalida";
                    break;}


                    }  // end switch joaca
           break; }//case 2ul lui joaca din switchul dintre mancare si joaca


        default: { playing = false;
                okiesire = 1;
                Exit();
                break;}


            } //end of switchchoice for mancare vs jaoca


    }while(choice==1 ||choice == 2); //  end do while de la mancare si joaca
}}

} while (alegerejoc == 1 || alegerejoc == 2);



//---------------------------------------------------------------------


break;}


                break;}


             case 2:   //normal
            {  {system("cls");
            Antet();
            cout<<endl<<endl;
            Animal();
            cout<<endl<<endl;
            DragonDesen();
            cout<<endl<<endl;
            system("pause");
            ///         SAU ZANA
            system("cls");
            welcome(jucator);
            cout<<endl<<endl;
            Animal();
            cout<<endl<<endl;
            ZanaDesen();
            system("pause");     //dragon zanatic
            system("cls");
            welcome(jucator);
            cout<<endl<<endl;
            Animal();
            cout<<endl<<endl;
            DragonZanaticDesen();
            system("pause");

            system("cls");
                cout<<endl;
                welcome(jucator);
                cout<<endl;
                Animal();
                cout<<endl<<endl<<endl;
                //_____________________________________________________________-


                do {

    cout << "\nDoriti inceperea unui joc nou sau continuarea unuia trecut? 1- joc nou, 2 - alegerea altui joc, alta tasta pentru a parasi jocul: ";
    cin >> alegerejoc;
int okiesire=0;
    switch (alegerejoc) {
        case 1:
           {

            jocuri.addJoc();
            animal = jocuri.getListaJocuri().back();
            cout << "\nAcesta este animalul cu care va veti juca: " << *animal;
            break;}

        case 2:
         {if (jocuri.getListaJocuri().empty()) {
                jocuri.addJoc();
            }
            else {
                jocuri.afisareJocuri();
                cout << "\nSelectati numarul jocului dorit: ";
                int x;
                cin >> x;
                while (x < 1 || x > jocuri.getListaJocuri().size()) {
                    cout << "Index invalid. Selectati un index valid.\n";
                    cin >> x;
                }
                animal = jocuri.getListaJocuri()[x-1];
                cout << "\nAcesta este animalul cu care va veti juca: " << *animal;
            }
            break;}

        default:
           {okiesire =1;
           Exit();
            break;
            }
    }//end of switch alegere joc


while(okiesire!=1){
bool playing = true;
while (playing) {
        system("cls");
        Antet();
        cout<<"Jucator : "<<jucator<<endl;
        if (animal->getSanatate() <= 0)
            {cout << "Nu ati oferit destula grija animalutul dumneavoastra. Ca urmare, Game over!" << endl;
            break;}




         cout<<endl;
        Status(animal);
        if (animal->getTip() == "dragon") DragonDesen();
        else if (animal->getTip() == "zana"){ ZanaDesen();
                                            }
        else if(animal->getTip()== "animal fantastic"){ DragonZanaticDesen();
                                                        }
       int choice;
           do {
        cout << "\n\n\nCe doriti sa faceti?   1 - hraneste animalutul   |   2 - joaca-te cu animalutul   |   alta tasta - exit\n";
        cin >> choice;

       switch(choice){
        case 1: //mancare
            {cout<<"\nCe doriti sa manance animalutul?\n  1.Salata 2.Hamburger 3. Cartofi Prajiti 4. Friptura 5. Gogoasa ";
                int mancare;
                cin>>mancare;
                switch(mancare){
                  case 1: //salata
                      {if (animal->getSanatate() + Salata.getHealth()<=100)
                        animal->setSanatate(animal->getSanatate() + Salata.getHealth());
                    if(animal->getHrana()+ Salata.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Salata.getHunger());
                    if (animal->getFericire() + Salata.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Salata.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  case 2://hamburger
                      {if( animal->getSanatate() + Hamburger.getHealth()<=100)
                          animal->setSanatate(animal->getSanatate() + Hamburger.getHealth());
                    if(animal->getHrana()+ Hamburger.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Hamburger.getHunger());
                    if(animal->getFericire() + Hamburger.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Hamburger.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  case 3://cartofiprajiti
                      {if (animal->getSanatate() + CartofiPrajiti.getHealth()<=100)
                          animal->setSanatate(animal->getSanatate() + CartofiPrajiti.getHealth());
                    if (animal->getHrana()+ CartofiPrajiti.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ CartofiPrajiti.getHunger());
                    if(animal->getFericire() + CartofiPrajiti.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + CartofiPrajiti.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  case 4://friptura
                      {if (animal->getSanatate() + Friptura.getHealth()<=100)
                          animal->setSanatate(animal->getSanatate() + Friptura.getHealth());
                    if(animal->getHrana()+ Friptura.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Friptura.getHunger());
                    if(animal->getFericire() + Friptura.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Friptura.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  case 5://gogoasa
                      {if(animal->getSanatate() + Gogoasa.getHealth()<=100)
                          animal->setSanatate(animal->getSanatate() + Gogoasa.getHealth());
                    if(animal->getHrana()+ Gogoasa.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Gogoasa.getHunger());
                    if(animal->getFericire() + Gogoasa.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Gogoasa.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  default:{cout<<"\nNe pare rau. Alegere invalida";
                    break;}
                            }

         break;   }

        case 2: //joaca
            {cout<<"Cu ce doriti sa va jucati cu animalutul? 1 - SPORT  |   2- Minge   |   3- Bagheta Magica\n";
            int joaca;
            cin>>joaca;

            switch(joaca){

            case 1: // sport
                     {if (animal->getSanatate() + Sport.getHealth()<=100) animal->setSanatate(animal->getSanatate() + Sport.getHealth());
                    if(animal->getHrana()+ Sport.getHunger()<=100) animal->setHrana(animal->getHrana()+ Sport.getHunger());
                    if (animal->getFericire() + Sport.getHappy()<=100) animal->setFericire(animal->getFericire() + Sport.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}

            case 2: //minge
                {if (animal->getSanatate() + Minge.getHealth()<=100)
                        animal->setSanatate(animal->getSanatate() + Minge.getHealth());
                    if(animal->getHrana()+ Minge.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Minge.getHunger());
                    if (animal->getFericire() + Minge.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Minge.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}

            case 3: //BaghetaMagica
                {if (animal->getSanatate() + BaghetaMagica.getHealth()<=100)
                        animal->setSanatate(animal->getSanatate() + BaghetaMagica.getHealth());
                    if(animal->getHrana()+ BaghetaMagica.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ BaghetaMagica.getHunger());
                    if (animal->getFericire() + BaghetaMagica.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + BaghetaMagica.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
            default:{cout<<"\nNe pare rau. Alegere invalida";
                    break;}


                    }  // end switch joaca
           break; }//case 2ul lui joaca din switchul dintre mancare si joaca


        default: { playing = false;
                okiesire = 1;
                Exit();
                break;}


            } //end of switchchoice for mancare vs jaoca


    }while(choice==1 ||choice == 2); //  end do while de la mancare si joaca
}}

} while (alegerejoc == 1 || alegerejoc == 2);



//---------------------------------------------------------------------


break;}


                break;}


            case 3:    //greu
                {  {system("cls");
            Antet();
            cout<<endl<<endl;
            Animal();
            cout<<endl<<endl;
            DragonDesen();
            cout<<endl<<endl;
            system("pause");
            ///         SAU ZANA
            system("cls");
            welcome(jucator);
            cout<<endl<<endl;
            Animal();
            cout<<endl<<endl;
            ZanaDesen();
            system("pause");     //dragon zanatic
            system("cls");
            welcome(jucator);
            cout<<endl<<endl;
            Animal();
            cout<<endl<<endl;
            DragonZanaticDesen();
            system("pause");

            system("cls");
                cout<<endl;
                welcome(jucator);
                cout<<endl;
                Animal();
                cout<<endl<<endl<<endl;
                //_____________________________________________________________-


                do {

    cout << "\nDoriti inceperea unui joc nou sau continuarea unuia trecut? 1- joc nou, 2 - alegerea altui joc, alta tasta pentru a parasi jocul: ";
    cin >> alegerejoc;
int okiesire=0;
    switch (alegerejoc) {
        case 1:
           {

            jocuri.addJoc();
            animal = jocuri.getListaJocuri().back();
            cout << "\nAcesta este animalul cu care va veti juca: " << *animal;
            break;}

        case 2:
         {if (jocuri.getListaJocuri().empty()) {
                jocuri.addJoc();
            }
            else {
                jocuri.afisareJocuri();
                cout << "\nSelectati numarul jocului dorit: ";
                int x;
                cin >> x;
                while (x < 1 || x > jocuri.getListaJocuri().size()) {
                    cout << "Index invalid. Selectati un index valid.\n";
                    cin >> x;
                }
                animal = jocuri.getListaJocuri()[x-1];
                cout << "\nAcesta este animalul cu care va veti juca: " << *animal;
            }
            break;}

        default:
           {okiesire =1;
           Exit();
            break;
            }
    }//end of switch alegere joc


while(okiesire!=1){
bool playing = true;
while (playing) {
        system("cls");
        Antet();
        cout<<"Jucator : "<<jucator<<endl;
        if (animal->getSanatate() <= 0)
            {cout << "Nu ati oferit destula grija animalutul dumneavoastra. Ca urmare, Game over!" << endl;
            break;}




         cout<<endl;
        Status(animal);
        if (animal->getTip() == "dragon") DragonDesen();
        else if (animal->getTip() == "zana"){ ZanaDesen();
                                            }
        else if(animal->getTip()== "animal fantastic"){ DragonZanaticDesen();
                                                        }
       int choice;
           do {
        cout << "\nCe doriti sa faceti?   1 - hraneste animalutul   |   2 - joaca-te cu animalutul   |   alta tasta - exit\n";
        cin >> choice;

       switch(choice){
        case 1: //mancare
            {cout<<"\nCe doriti sa manance animalutul?\n  1.Salata 2.Hamburger 3. Cartofi Prajiti 4. Friptura 5. Gogoasa ";
                int mancare;
                cin>>mancare;
                switch(mancare){
                  case 1: //salata
                      {if (animal->getSanatate() + Salata.getHealth()<=100)
                        animal->setSanatate(animal->getSanatate() + Salata.getHealth());
                    if(animal->getHrana()+ Salata.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Salata.getHunger());
                    if (animal->getFericire() + Salata.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Salata.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  case 2://hamburger
                      {if( animal->getSanatate() + Hamburger.getHealth()<=100)
                          animal->setSanatate(animal->getSanatate() + Hamburger.getHealth());
                    if(animal->getHrana()+ Hamburger.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Hamburger.getHunger());
                    if(animal->getFericire() + Hamburger.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Hamburger.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  case 3://cartofiprajiti
                      {if (animal->getSanatate() + CartofiPrajiti.getHealth()<=100)
                          animal->setSanatate(animal->getSanatate() + CartofiPrajiti.getHealth());
                    if (animal->getHrana()+ CartofiPrajiti.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ CartofiPrajiti.getHunger());
                    if(animal->getFericire() + CartofiPrajiti.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + CartofiPrajiti.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  case 4://friptura
                      {if (animal->getSanatate() + Friptura.getHealth()<=100)
                          animal->setSanatate(animal->getSanatate() + Friptura.getHealth());
                    if(animal->getHrana()+ Friptura.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Friptura.getHunger());
                    if(animal->getFericire() + Friptura.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Friptura.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  case 5://gogoasa
                      {if(animal->getSanatate() + Gogoasa.getHealth()<=100)
                          animal->setSanatate(animal->getSanatate() + Gogoasa.getHealth());
                    if(animal->getHrana()+ Gogoasa.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Gogoasa.getHunger());
                    if(animal->getFericire() + Gogoasa.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Gogoasa.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
                  default:{cout<<"\nNe pare rau. Alegere invalida";
                    break;}
                            }

         break;   }

        case 2: //joaca
            {cout<<"Cu ce doriti sa va jucati cu animalutul? 1 - SPORT  |   2- Minge   |   3- Bagheta Magica\n";
            int joaca;
            cin>>joaca;

            switch(joaca){

            case 1: // sport
                     {if (animal->getSanatate() + Sport.getHealth()<=100)
                        animal->setSanatate(animal->getSanatate() + Sport.getHealth());
                    if(animal->getHrana()+ Sport.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Sport.getHunger());
                    if (animal->getFericire() + Sport.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Sport.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}

            case 2: //minge
                {if (animal->getSanatate() + Minge.getHealth()<=100)
                        animal->setSanatate(animal->getSanatate() + Minge.getHealth());
                    if(animal->getHrana()+ Minge.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ Minge.getHunger());
                    if (animal->getFericire() + Minge.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + Minge.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}

            case 3: //BaghetaMagica
                {if (animal->getSanatate() + BaghetaMagica.getHealth()<=100)
                        animal->setSanatate(animal->getSanatate() + BaghetaMagica.getHealth());
                    if(animal->getHrana()+ BaghetaMagica.getHunger()<=100)
                      animal->setHrana(animal->getHrana()+ BaghetaMagica.getHunger());
                    if (animal->getFericire() + BaghetaMagica.getHappy()<=100)
                      animal->setFericire(animal->getFericire() + BaghetaMagica.getHappy());
                      system("cls");
                      Antet();
                      cout<<"Jucator : "<<jucator<<endl;
                      Status(animal);
                      break;}
            default:{cout<<"\nNe pare rau. Alegere invalida";
                    break;}


                    }  // end switch joaca
           break; }//case 2ul lui joaca din switchul dintre mancare si joaca


        default: { playing = false;
                okiesire = 1;
                Exit();
                break;}


            } //end of switchchoice for mancare vs jaoca


    }while(choice==1 ||choice == 2); //  end do while de la mancare si joaca
}}

} while (alegerejoc == 1 || alegerejoc == 2);



//---------------------------------------------------------------------


break;}


                break;}



            default:{ Exit();
                    break;}


}




system("cls");
Exit();


return 0;}




