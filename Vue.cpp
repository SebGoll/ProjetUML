/**
    Gère l'affichage des menus du programme
    @file Vue.cpp
    @author ABHAY Annie, GOLL Sebastien, HASENFRATZ Louis, NGOV Sophanna (B3201-B3209)
*/
#include <iostream>
using namespace std;

#include "Vue.h"
#include <list>
#include <String>
#include "Capteur.h"
//#include "Purificateur.h"



void mainMenu(){

    cout<< "Menu"<<endl;
    switch (droits) {
        case 1:
            cout<< "1-Voir la qualite de l'air \n"
                   "2-Consulter les capteurs\n"
                   "3-Consulter les purificateurs"<<endl;
        case 2:
            cout<< "1-Voir la qualite de l'air \n"
                   "2-Consulter son compte"<<endl;
        case 3:
            cout<< "1-Voir la qualite de l'air \n"
                   "2-Consulter ses purificateurs"<<endl;

    }

}

void menuQualiteAir(){
    cout<<"1.1-Voir la qualité de l'air en un point\n"
          "2.2-Voir la qualité de l'air en une zone"<<endl;
}

void menuQualiteAirPoint(){
    cout<<"Inserer la longitude, la latitude, la date de debut et la date de fin:"<<endl;
}
void menuQualiteAirZone(){
    cout<<"Inserer la longitude, la latitude, le rayon de la zone (en ..), la date de debut et la date de fin:"<<endl;
}

void menuConsulterCapteur(){
    cout<<"Entrez le numero du capteur:"<<endl;
}



void menuConsulterDetailsCapteur(){
    cout<<"Menu"<<endl;
    cout<<"2.1-Consulter les capteurs similaires\n"
          "2.2-Voir si un capteur est défectueux"<<endl;
}

void menuConsulterCapteursSimilaires(Capteur c){
    /*Algo capteur similaires*/
}

void menuConsulterPurificateurs(){
    cout<<"Entrez le numero du purificateur:"<<endl;
}
/*
void menuConsulterDetailPurificateur(Purificateur p){
    cout<<"Rayon d'influence du capteur"<<endl;
    // cout<<p.calculRayon()<<endl;
}
*/