#include <iostream>
#include <vector>
#include <string.h>
class Personne{
public:
    char *nom[20];
   Personne (){
        }


    Personne (char no[20]){
                 *nom=no;
}

 char *getNom(){
    return *nom;
    }

    void setNom(char noms[20]){
    *nom=noms;
    }
};
