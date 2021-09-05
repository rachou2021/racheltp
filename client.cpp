#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>

using namespace std;

struct Panier{
        int  idclient;
        int typefleur;
        int quantite;
        double prix;
};


class Fleurs{
public:
    int type;
    int nombre;
    char nom;
    double prix;

    Fleurs (){
    }

     Fleurs (int typ, int nombr, double pri){
         type=typ;
         nombre=nombr;
         prix=pri;

    }

    void afficherFleur(vector<Fleurs>fleurss){
        int l;
        for(l=0;l<fleurss.size();l++){
        cout <<"Type "<<fleurss[l].type << endl;
        cout <<"Disponible "<< fleurss[l].nombre<<endl;
        cout <<"Prix "<<fleurss[l].prix   <<endl;
        }
        cout <<" "<<endl;
 }

 bool isdisponible(int a,vector<Fleurs>fleur, int type){

  for(int l6=0;l6<fleur.size();l6++){
        if(fleur[l6].type==type||fleur[l6].nombre>=a)return 1;
        else return 0;
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

class Personnes{
public:
    char *nom[20];
   Personnes (){
        }


    Personnes (char no[20]){
                 *nom=no;
}

 char *getNom(){
    return *nom;
    }

    void setNom(char noms[20]){
    *nom=noms;
    }
};



class Client :public Personnes{
public:
    int age;
    int idclient;
    char *motpass[20];
    char *adressmail[20];



    Client (){
        }

    Client (int ag,char motpas[20],char adressmai[20]){
        age=ag;
        *motpass=motpas;
        *adressmail=adressmai;
        }
    Client (int ag,int idclients,char motpas[20],char adressmai[20]){
        age=ag;
        idclient=idclients;
        *motpass=motpas;
        *adressmail=adressmai;
        }
  Client (int ag,int idclients,char motpas[20],char adressmai[20],char no[20]){
        age=ag;
        idclient=idclients;
        *motpass=motpas;
        *adressmail=adressmai;
        *nom=no;
        }
vector<Client>Singup(vector<Client>clients){
            int age=0;
            char nom[20],motpass[20],emaill[20];
            Client clientss(2,0,"1234","q@gmail","Gauss");
            vector<Client>clientssd;
            cout <<"Quel est ton age "<< endl;
            cin>>age;
            clientss.age=age;
            clientss.idclient=clients.size();
            cout <<"Quel est ton nom"<< endl;
            cin>>nom;
            *clientss.nom=nom;
            cout <<"Quel est ton mot de passe"<< endl;
            cin>>motpass;
            *clientss.motpass= motpass;
            cout <<"Quel est ton email"<< endl;
            cin>>emaill;
            *clientss.adressmail=emaill;
            cout <<""<< endl;
            clientssd.push_back(clientss);

    return clientssd;

}

int Login(vector<Client>clients){
            char nom1[20],motpass1[20];
            cout <<"Quel est ton nom"<< endl;
            cin>>nom1;
            cout <<"Quel est ton mot de passe"<< endl;
            cin>>motpass1;
            cout <<clients.size()<< endl;
            cout <<*clients[1].nom<< endl;
            cout <<*clients[1].motpass<< endl;
            int i1,k1;
            bool j1=0;
            for (i1 = 0; i1 < clients.size(); i1++){
            if ((strcmp(nom1,*clients[i1].nom) == 0) && (strcmp(motpass1,*clients[i1].motpass)==0))
                j1=1;
                k1=i1;}
            if (j1==0) {
            cout <<"LE LOGIN OU LE MOT DE PASSE EST INCORECTE RECONNECTEZ-VOUS SVP!"<< endl;
            return 1;
            }
            else {  std::system("cls");
                    cout <<""<< endl;
                    cout <<"xxxxxxxxx BIENVENU CHEZ NOUS Mr ou Mme  "<< *clients[k1].nom<<"  xxxxxxxxx"<<endl;}

            return 0;
}

double filtrePrix(int a,vector<Fleurs>fleur, int type){
      for(int l=0;l<fleur.size();l++){
           if(fleur[l].type==type) ;
            return a*fleur[l].prix;
        }

}

Panier AjoutAupanier(int idclient,int nb,int type,Panier paniers,vector<Panier>panier,vector<Fleurs>fleurs){
                    char ae;
                    int l,l2;
                    double prix=filtrePrix(nb,fleurs, type);
                    std::system("cls");
                    cout <<"CELA VA TE COUTER "<< prix << " $ "<< " VOULEZ-VOUS ajouter au panier O/N ?"<<endl;
                    cin>>ae;
                    if(ae=='O'){
                    paniers.idclient=idclient;
                    paniers.prix=prix;
                    paniers.quantite=nb;
                    paniers.typefleur=(char)(type);
                    panier.push_back(paniers);
                    for(l=0;l<panier.size();l++){
                    cout <<"Tu vient d'ajouter la fleur ci-dessous au panier "<< endl;
                    cout <<"Type     "<<panier[l].typefleur << endl;
                    cout <<"QuantitE "<< panier[l].quantite<<endl;
                    cout <<"Prix     "<<panier[l].prix   <<endl;}
                    cout <<"Tapez n'importe quel nombre pour retourner au menu"<<endl;
                    cin>>l2;
                    std::system("cls");

}
return paniers;
}


void facture(vector<Panier>panier){
        double prixtotal;
        int d;
        for(int l3=0;l3<panier.size();l3++){
        prixtotal+= (panier[l3].quantite * panier[l3].prix);}
        std::system("cls");
        cout <<""<<endl;
        cout <<""<<endl;
        cout <<"*********FACTURE***********"<<endl;
        cout <<"Le montant total est: "<< prixtotal<<endl;
        cout <<"***************************"<<endl;
        cout <<""<<endl;
        cout <<""<<endl;
        cout <<"Tapez n'importe quel nombre pour retourner au menu"<<endl;
        cin>>d;
        std::system("cls");
}

vector<Panier> payement(vector<Panier>panier){
            vector<Panier>panierss;
            for(int l4=0;l4<panier.size();l4++){
            panierss.push_back(panier[l4]);
}
return panierss;
}


Panier ClientAchat(int idclient,Panier paniers,vector<Panier>panier,vector<Fleurs>fleurs){
            int l;
            int type;
            int nb;
            char ae;
            Fleurs fleurss;
            Panier panierss;
            //fleurss.afficherFleur(fleurs);
            cout <<"QUELLE EST LE NOM DE LA FLEUR"<< endl;
            cin>>type;
            cout <<"COMBIEN DE FLEUR VOULEZ-VOUS ACHETER"<< endl;
            cin>>nb;
            if(fleurss.isdisponible(nb,fleurs, type)==1){
            panierss=AjoutAupanier(idclient,nb,type,paniers,panier,fleurs);
            }
            else if(fleurss.isdisponible(nb,fleurs, type)==1)cout <<"Le nombre n'est pas disponible"<<endl;

return panierss;
            }

int Deconnexion(int idclient,Panier paniers,vector<Panier>panier){
paniers.idclient=0;
paniers.prix=0;
paniers.typefleur=0;
paniers.quantite=0;
panier.clear();
idclient=-1;
return 0;
}


 int getIdclient(){
    return idclient;
    }

    void setIdclient(int idcli){
    idclient=idcli;
    }

};


class Admini :public Personnes{
public:
    int nombre;

    Admini (){
    }



vector<Fleurs> ajouterFleur(){
            int nbr,typ;
                char nomb;
                double pri;
                vector<Fleurs>fleurss;
                    cout <<"VOULEZ-VOUS AJOUTER COMBIEN DE TYPES DE FLEURS"<< endl;
                    cin>>nbr;
                    Fleurs fleur1;
                    for(int l=0;l<nbr;l++){
                        cout <<"Entrer les types de fleurs"<<endl;
                        cin>>typ;
                        fleur1.setType(typ);
                        cout <<"Entrer nombre de fleurs disponibles"<<endl;
                        cin>>nomb;
                        fleur1.setNombre(nomb);
                        cout <<"Entrer le prix de ce type de fleur"<<endl;
                        cin>>pri;
                        fleur1.setPrix(pri);
                        fleurss.push_back(fleur1);
            }

return fleurss;
    }


void RapportVente(vector<Panier>achats){
                        for(int l41=0;l41<achats.size();l41++){
                        cout << "Type de fleur "<<achats[l41].typefleur<<endl;
                        cout << "Quantite      "<<achats[l41].quantite<<endl;
                        cout << "Prix          " <<achats[l41].prix<<endl;}
}

void stat(vector<Panier>achats){
                        int  prixtotal1;
                        int  quantites;
                        int  varianc;
                        for(int l41=0;l41<achats.size();l41++){
                        cout << achats[l41].typefleur<<endl;
                        cout << achats[l41].quantite<<endl;
                        cout << achats[l41].prix<<endl;
                        prixtotal1+=achats[l41].quantite*achats[l41].prix;
                        quantites+=achats[l41].quantite;
                        varianc+=achats[l41].quantite*achats[l41].quantite;
                            }
                        double moy=quantites/achats.size();
                        cout <<"Moyenne de vente "<<prixtotal1/achats.size()<<"$"<<endl;
                        cout <<"Moyenne de fleur vendu "<<moy<<"fleurs"<<endl;
                        cout <<"Variance de fleur vendu "<<varianc/achats.size()-moy*moy<<"fleurs"<<endl;
}


};



