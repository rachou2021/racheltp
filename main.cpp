#include <iostream>
#include <cstdlib>
#include <vector>
#include <string.h>
#include "fleur.cpp";
#include "client.cpp";
using namespace std;


struct Paniers{
        int  idclient;
        int typefleur;
        int quantite;
        double prix;
};


void menu(){
    cout <<"-----------PAGE D'ACCUEIL----------- "<< endl;
    cout <<" "<< endl;
    cout <<"1. Client"<< endl;
    cout <<"2. Super Admin"<< endl;
    cout <<"3. QUITTER"<< endl;
}
void menu2(){
    cout <<"-----------MENU 2----------- "<< endl;
    cout <<" "<< endl;
    cout <<"1. Singup"<< endl;
    cout <<"2. Sigin"<< endl;
    cout <<"3. Faire des achats"<< endl;
}

void menu3(){
    cout <<"-----------MENU 3----------- "<< endl;
    cout <<" "<< endl;
    cout <<"1. Ajout au panier"<< endl;
    cout <<"2. Voir facture"<< endl;
    cout <<"3. Payer"<< endl;
    cout <<"4. Deconnexion"<< endl;
    cout <<"5. Quitter"<< endl;
}



int main()
{
    Fleurs fleur(2,4,6);
    vector<Fleurs>fleurs;
    fleurs.push_back(fleur);

    Client client(2,0,"1234","q@gmail","Gauss");
    vector<Client>clients;
    clients.push_back(client);

    Client clientss(2,0,"1234","q@gmail","Gauss");
    Panier paniers;
    vector<Panier> panier;

    Panier achat;
    vector<Panier> achats ;

    Admini admin;

    int idclient=-1;
    int k=0,k21=0,k211=0;


    do{


accuiel:
        menu();
        cin>>k;
        if(k==1){
                do{
            menu2();
            cin>>k21;
            if(k21==1){
                Singup:
                        clientss=client.Singup(clients)[0];
                        clients.push_back(clientss);
                        idclient=client.getIdclient();
                        cout <<"SingIn"<< endl;
                        cout <<clients[1].getNom()<< endl;
                        cout <<*clients[1].motpass<< endl;
                        goto sing;
            }
            if(k21==2){
            sing:
                client.Login(clients);
                //fleur.afficherFleur(fleurs);
                continue;
                        }

            if((k21==3&&idclient!=-1)==1){
                            do{
                                cout <<"+++++++++++++++++++++++++++++++++"<< endl;
                                cout <<"++++++++++++ACHAT++++++++++++++++"<< endl;
                                cout <<"+++++++++++++++++++++++++++++++++"<< endl;
                                fleur.afficherFleur(fleurs);
                                cout <<""<< endl;
                                cout <<""<< endl;
                                menu3();
                                cin>>k211;
                                if(k211==1){
                                panier.push_back(client.ClientAchat(client.getIdclient(),paniers,panier,fleurs));
                                }

                                if(k211==2){
                                client.facture(panier);
                                }

                                if(k211==3){
                                        for(int l4=0;l4<client.payement(panier).size();l4++){
                                            if(client.payement(panier)[l4].typefleur==fleurs[l4].type){
                                            fleurs[l4].nombre=fleurs[l4].nombre-client.payement(panier)[l4].quantite;
                                            achats.push_back(client.payement(panier)[l4]) ;
                                            }
                                    }               int h;
                                                    cout <<"********************"<<endl;
                                                    cout <<"PAYEMENT fini"<<endl;
                                                    cout <<"*******************"<<endl;
                                                    cout <<"Tapez n'importe quel nombre pour retourner au menu"<<endl;
                                                    cin>>h;
                                                    std::system("cls");
                                                                            }

                                if(k211==4){
                                    client.Deconnexion(idclient,paniers,panier);
                                    goto accuiel;
                                }
                                }while(k211!=5);

                                }
                                else if((k21==3&&idclient==-1)==1){
                                    cout <<"----------------------------"<< endl;
                                    cout <<"Veuillez vous connecter svp"<< endl;
                                    cout <<"----------------------------"<< endl;
                                }

                }while(k21!=4);
        }

        if(k==2){
            int df;
            do{
            cout <<"1. Voir le rapport de vente"<< endl;
            cout <<"2. Voir le rapport de stock"<< endl;
            cout <<"3. Statistiques de vente"<< endl;
            cout <<"4. Ajout de fleur"<< endl;
            cin>>df;
            cout <<df<< endl;
            if(df==1){
                cout <<"Vous avez vendu"<< endl;
                Admini admin;
                admin.RapportVente(achats);
            }
            if(df==2){
                cout <<"Votre stocker "<< endl;
                Fleurs fleurss;
                fleurss.afficherFleur(fleurs);
            }
            if(df==3){
               stat(achats) ;
            }
            if(df==4){
                vector<Fleurs>fleurss;
                fleurss=admin.ajouterFleur();
                for(int l41=0;l41<fleurss.size();l41++){
                fleurs.push_back(fleurss[l41]);
                }
            }

}
while(df!=5);

        }
        }while(k!=3);

    return 0;
}
