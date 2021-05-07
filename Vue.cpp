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
                   "3-Consulter les purificateurs\n"
                   "4-Quitter"<<endl;
<<<<<<< Updated upstream
=======
            break;
>>>>>>> Stashed changes
        case 2:
            cout<< "1-Voir la qualite de l'air \n"
                   "2-Consulter son compte\n"
                   "3-Quitter"<<endl;
<<<<<<< Updated upstream
        case 3:
            cout<< "1-Voir la qualite de l'air \n"
                   "2-Consulter ses purificateurs\n"
                   "3-Quitter"<<endl;
=======

            break;
        case 3:
            cout<< "1-Voir la qualite de l'air \n"
                   "2-Consulter ses purificateurs\n"
                   "3-Quitter"<<endl;;
            break;
>>>>>>> Stashed changes

    }

}

void menuQualiteAir(){
    cout<<"1.1-Voir la qualite de l'air en un point\n"
          "2.2-Voir la qualite de l'air en une zone"<<endl;
}

void menuQualiteAirPoint(){
    cout<<"Inserer la longitude et la latitude, ainsi que la date de debut et la date de fin de la periode a moyenner:"<<endl;
}
void menuQualiteAirZone(){
    cout<<"Inserer la longitude, la latitude et le rayon de la zone (en ..), ainsi que la date de debut et la date de fin de la periode a moyenner:"<<endl;
}
void menuDemandeDates(){
    cout<<"Inserer la date de debut et la date de fin de la periode a moyenner:"<<endl;
}
void menuConsulterCapteur(){
    cout<<"Entrez le numero du capteur  a analyser:"<<endl;
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
    cout<<"Entrez le numero du purificateur dont la zone d'influence doit etre calculee \n(saisissez \"aucun\" pour retourner au menu):"<<endl;
}
/*
void menuConsulterDetailPurificateur(Purificateur p){
    cout<<"Rayon d'influence du capteur"<<endl;
    // cout<<p.calculRayon()<<endl;
}
*/