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
#include "Objets/Capteur.h"
//#include "Purificateur.h"



void mainMenu() {

    cout << "Menu" << endl;
    switch (droits) {
        case 1:

            cout << "1-Voir la qualite de l'air \n"
                    "2-Consulter les capteurs\n"
                    "3-Consulter les purificateurs\n"
                    "4-Quitter" << endl;
            break;

        case 2:

            cout << "1-Voir la qualite de l'air \n"
                    "2-Consulter son compte\n"
                    "3-Quitter" << endl;
            break;

        case 3:

            cout << "1-Voir la qualite de l'air \n"
                    "2-Consulter ses purificateurs\n"
                    "3-Quitter" << endl;
            break;


    }

}

void ErreurSaisie(){
    cout << "Erreur lors de la saisie\n"
         << "Retour au menu principal " << endl;

}

void ErreurHorsMesure(){
    cout << "Erreur, la période demandée est en dehors de la période mesurée\n"
         << "Retour au menu principal " << endl;
}

void MauvaisesDates(){
    cout << "Les dates données ne sont pas dans le bon ordre\n"
         << "Retour au menu principal " << endl;
}
void menuQualiteAir() {
    cout << "1.1-Voir la qualite de l'air en un point\n"
            "1.2-Voir la qualite de l'air en une zone\n"
            "1.3-Retour au menu"<< endl;
}

void menuQualiteAirPoint() {
    cout
            << "Inserer la longitude et la latitude, ainsi que la date de debut et la date de fin de la periode a moyenner (aaaa-mm-jj):"
            << endl;
}

void menuQualiteAirZone() {
    cout
            << "Inserer la longitude, la latitude et le rayon de la zone (en ..), ainsi que la date de debut et la date de fin de la periode a moyenner:"
            << endl;
}

void menuDemandeDates() {
    cout << "Inserer la date de debut et la date de fin de la periode a moyenner (aaaa-mm-jj):" << endl;
}

void menuConsulterCapteur() {
    cout << "Entrez le numero du capteur  a analyser\n(saisissez \"aucun\" pour retourner au menu):" << endl;
}


void menuConsulterDetailsCapteur() {
    cout << "Menu" << endl;
    cout << "2.1-Consulter les capteurs similaires\n"
            "2.2-Voir si un capteur est défectueux" << endl;
}



void menuConsulterPurificateurs() {
    cout << "Entrez le numero du purificateur dont la zone d'influence doit etre calculee \n(saisissez \"aucun\" pour retourner au menu):"
            << endl;
}

/*
void menuConsulterDetailPurificateur(Purificateur p){
    cout<<"Rayon d'influence du capteur"<<endl;
    // cout<<p.calculRayon()<<endl;
}
*/


void resultatQualiteEnPoint(int Qualite) {
    cout << "La qualite de l'air en ce point est de : " << Qualite << endl;

}

void resultatListeCapteur(list<Capteur*> tousCapteurs){
    cout << "Liste des capteurs :" << endl;
    for (list<Capteur*>::iterator it=tousCapteurs.begin();it!=tousCapteurs.end();it++){
        cout << (*(*it)) <<  endl;
    }
    cout << endl <<endl;
}
void resultatListePurificateur(list<Purificateur*> tousPurificateurs){
    cout << "Liste des purificateurs :" << endl;
    for (list<Purificateur*>::iterator it=tousPurificateurs.begin();it!=tousPurificateurs.end();it++){
        cout << **it <<  endl;

    }
    cout << endl <<endl;
}

void resultatCapteursSimilaires( int * scores,int *ids,int taille){
    cout << "id | score de difference"  << endl;
    for(int i =0;i< taille;i++){
        if(ids[i]/10==0){
            cout<<" ";
        }
        cout << ids[i] <<"            " << scores[i] << endl;
    }

}

