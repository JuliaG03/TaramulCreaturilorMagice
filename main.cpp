#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
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
//constructor nume varsta
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
    bool getEPericulos(){return this->ePericulos;}
    void setMarimeAripi(bool marimeAripi){this->marimeAripi= marimeAripi;}
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


};


class Zana:virtual public Creatura{
protected:
    string culoare;
    bool abilitateVindecare;
public:
    bool getAblitateVindecare(){return this->abilitateVindecare;}
    void setAbilitateVindecare(){this->abilitateVindecare = abilitateVindecare;}

//constructor default
Zana():Creatura(){
    this->abilitateVindecare = 1;
    this->culoare = "rosu";}
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


};


class Fantastic: public Dragon, public Zana{
private:
    string puteri[3] = { "foc", "apa", "gheata" };
    string putereMagica;
public:
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
        in>>this->putereMagica;
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
        return procent; }

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
//constructor default
JocNou(){this->creatura= creatura;}
//copyconstructor
JocNou(const JocNou &obj){
    this->creatura = obj.creatura;}

//op=
JocNou& operator=(const JocNou &obj) {
        if (this != &obj) {
        this->creatura = obj.creatura;

        }
        return *this;
    }


friend istream& operator>>(istream& in , JocNou& obj){
        cout<< "\n1. Dragon\n";
        cout<< "2. Zana\n";
        int k;
        cin>>k;
        if( k==1)obj.creatura = new Dragon();
        if( k==2)obj.creatura = new Zana();
        in>> *obj.creatura;
        return in;
        }
friend ostream& operator<<(ostream& out, const JocNou& obj){
        out<<"\nCreatura: \n"<< *obj.creatura<<endl;
        return out;}

void setCreatura(Creatura* creatura){this-> creatura = creatura;}

Creatura* getCreatura(){return this->creatura;}

 virtual ~JocNou() {delete creatura;}
};


class Jocuri{

vector<Creatura*> listaJocuri;

public:
    vector<Creatura*> getListaJocuri() {
        return listaJocuri;}


void addJoc() {
    JocNou* jocNouu = new JocNou();
    cin >> *jocNouu;

    listaJocuri.push_back(jocNouu->getCreatura());

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

~Jocuri() {
    for (int i = 0; i < listaJocuri.size(); i++) {
        delete listaJocuri[i];
    }
}

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

void Exit(){
    system("cls");
    Antet();
    cout<<endl<<endl;
    Center("Te mai asteptam pe la noi!",45);
    cout<<endl<<endl<<endl<<endl;}

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

switch(dificultate){
        case 1:   //usor
            {system("cls");
            Antet();
            cout<<endl<<endl;
            Animal();
            cout<<endl<<endl;
            DragonDesen();
            cout<<endl<<endl;
            system("pause");
            ///                  SAU ZANA
            system("cls");
            welcome(jucator);
            cout<<endl<<endl;
            Animal();
            cout<<endl<<endl;
            ZanaDesen();
int ok = 1;
            system("pause");
            system("cls");
do{
            cout<<endl;
            welcome(jucator);
            cout<<endl;
            Animal();
            cout<<endl<<endl<<endl;

if(jocuri.getListaJocuri().empty()){
            jocuri.addJoc();
            }
else{
    cout<<"\nDoriti inceperea unui joc nou sau continuarea unuia trecut? 1- joc nou , 2 - alegerea altui joc, 0 - pentru a parasi jocul: ";
        int alegerejoc;
        do{
        cin>>alegerejoc;

            switch(alegerejoc){
                case 1: //joc nou:
                    {
                    jocuri.addJoc();

                    break;}

                case 2: // alegerea unui joc vechi:
                    {jocuri.afisareJocuri();
                    if (jocuri.getListaJocuri().empty()){
                        jocuri.addJoc();
                        cout<<"\n\n AICI E JOCU:   "<<*jocuri.getListaJocuri()[0];}

                    else{
                        cout << "\nSelectati numarul jocului dorit: ";
                        int x;
                        cin >> x;
                        while (x < 1 || x > jocuri.getListaJocuri().size()) {
                            cout << "Index invalid. Selectati un index valid.\n";
                            cin>>x;}

                        Creatura* animalx = jocuri.getListaJocuri()[x-1];
                        JocNou jocnou;
                        jocnou.setCreatura(animalx);
                       }

                    break;}
                default: {Exit();}
            }

cout<<"a iesit din switchul alegerejoc , astepta continuarea";
       ///NU uita de alegere joc ==0
} while( alegerejoc != 0);

}


       ///NU UITA SA FACI OK=0

           break;
           }while(ok == 1);

            }
                case 2:   //normal
                     {
                    break;}


                case 3:    //greu
                    {
                    break;}

                default: Exit();}







return 0;}




