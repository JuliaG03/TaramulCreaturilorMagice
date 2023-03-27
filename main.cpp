#include<iostream>
#include<cstring>
using namespace std;

class Creatura{

private:
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
    Creatura(string nume = "necunoscut", int varsta = 0, float sanatate = 100 , float fericire = 100, float hrana = 100){}
//constructor cu nume, varsta
    Creatura(string nume, int varsta);
//copy constructor
    Creatura( const Creatura& obj);
// operatorul =
    Creatura& operator=(const Creatura& obj);
//operatorul ++
    Creatura& operator++();
//operatorul --
    Creatura& operator--();
// afisare si citire
    friend istream& operator >>(istream& in, Creatura& obj);
    friend ostream& operator <<(ostream& out, const Creatura& obj);

    };
//constructor nume varsta
Creatura::Creatura(string nume, int varsta)
    {this->nume = nume;
    this->varsta = varsta;}
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
//citire
istream& operator >>(istream& in, Creatura& obj){
    cout<<"\nNume: ";
    in>>obj.nume;
    cout<<"\nVarsta: ";
    in>>obj.varsta;
    obj.sanatate = 70;
    obj.fericire = 70;
    obj.hrana = 30;
    return in;}
//afisare
ostream& operator <<(ostream& out, const Creatura& obj)
    {out<<"\nNume: "<<obj.nume;
    out<<"\nVarsta: "<<obj.varsta;
    out<<"\nSanatate: "<<obj.sanatate;
    out<<"\nFericire: "<<obj.fericire;
    out<<"\nHrana: "<<obj.hrana;
    return out;}




int main(){

Creatura a;
cin>>a;
cout<<a;
return 0;}





