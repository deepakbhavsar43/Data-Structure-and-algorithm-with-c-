#include<iostream>
#include<cstring>
using namespace std;
class car{
    private:
        int price;
    public:
        int model_no;
        char * name;
    ///constructor
    car(){
        ///override the default constructor
        name=NULL;
        cout<<"making a car"<<endl;
    }
    ///Deep copy constructor
    car(car &X){
        price=X.price;
        model_no=X.model_no;
        int l=strlen(X.name);
        name=new char[l+1];
        strcpy(name,X.name);
    }
    void operator=(car &X){
        cout<<"IN Copy Assignments operator"<<endl;
        price=X.price;
        model_no=X.model_no;
        int l=strlen(X.name);
        name=new char[l+1];
        strcpy(name,X.name);
    }
    ///constructor with parameter-parametrised onstructor
    car(int p,int mn,char *n){
        price=p;
        model_no=mn;
        int l=strlen(n);
        name=new char[l+1];
        strcpy(name,n);
    }
    void setName(char *n){
         if(name==NULL){
             name=new char [strlen(n)+1];
             strcpy(name,n);
         }
         else{
         ///later......
         ///Delete the oldname array and allocate a new one
         }
    }
    void start(){
         cout<<"Grrr..starting the car"<<name<<endl;
    }
    void setprice(int p){
        if(p>1000){
             price=p;
        }
        else{
             price=1000;
        }

    }
    int getprice(){
         return price;
    }
    void print(){
         cout<<name<<endl;
         cout<<model_no<<endl;
         cout<<price<<endl;
         cout<<endl;
    }
};
int main(){
    car c;
    ///initialisation
    ///c.price=-500;
    c.setprice(1500);
    c.setName("Nano");
    c.model_no=1001;
    ///c.start();
    c.print();
    car D(100,200,"BMW");
    car E(200,400,"Audi");
    D=E;
    D.name[0]='o';
    D.print();
    E.print();
    return 0;
}
