#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Fleur{
public:
    int type;
    int nombre;
    char nom;
    double prix;

    Fleur (){
    }

     Fleur (int typ, int nombr, double pri){
         type=typ;
         nombre=nombr;
         prix=pri;

    }

    void afficherFleur(vector<Fleur>fleurss){
        int l;
        for(l=0;l<fleurss.size();l++){
        cout <<"Type "<<fleurss[l].prix << endl;
        cout <<"Disponible "<< fleurss[l].nombre<<endl;
        cout <<"Prix "<<fleurss[l].prix   <<endl;
        }
 }

    int getType(){
    return type;
    }

    void setType(int typ){
    type=typ;
    }

    int getNombre(){
    return nombre;
    }

    void setNombre(int nombr){
    nombre=nombr;
    }

    char getNom(){
    return nom;
    }

    void setNom(char noms){
    nom=noms;
    }


    double getPrix(){
    return prix;
    }

    void setPrix(double pri){
    prix=pri;
    }


};
