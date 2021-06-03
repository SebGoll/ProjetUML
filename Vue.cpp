/**
 *   Gère l'affichage des menus du programme
 *   @file Vue.cpp
 *   @author ABHAY Annie, GOLL Sebastien, HASENFRATZ Louis, NGOV Sophanna (B3201-B3209)
*/

#include <iostream>

using namespace std;

#include "Vue.h"
#include <list>



void mainMenu() {

    cout << "\nMenu" << endl;
    switch (droits) {
        case 1:

            cout << "1-Voir la qualite de l'air \n"
                    "2-Consulter les capteurs\n"
                    "3-Consulter les purificateurs(pas implemente)\n"
                    "4-Quitter" << endl;
            break;

        case 2:

            cout << "1-Voir la qualite de l'air \n"
                    "2-Consulter son compte(pas implemente)\n"
                    "3-Quitter" << endl;
            break;

        case 3:

            cout << "1-Voir la qualite de l'air \n"
                    "2-Consulter ses purificateurs(pas implemente)\n"
                    "3-Quitter" << endl;
            break;


    }

}

void ErreurSaisie(){
    cout << "\nErreur lors de la saisie\n"
         << "Retour au menu principal \n" << endl;

}

void ErreurHorsMesure(){
    cout << "\nErreur, la periode demandee est en dehors de la periode mesuree\n"
         << "Retour au menu principal \n" << endl;
}

void MauvaisesDates(){
    cout << "\nLes dates donnees ne sont pas dans le bon ordre\n"
         << "Retour au menu principal \n" << endl;
}
void menuQualiteAir() {
    cout << "\n1.1-Voir la qualite de l'air en un point\n"
            "1.2-Voir la qualite de l'air en une zone(pas implemente)\n"
            "1.3-Retour au menu"<< endl;
}

void menuQualiteAirPoint() {
    cout
            << "\nInserer la longitude (entre 40 et 47) et la latitude (entre -3 et 6), ainsi que la date de debut et la date de fin de la periode a moyenner (aaaa-mm-jj):"
            << endl;
}

void menuQualiteAirZone() {
    cout
            << "\nInserer la longitude, la latitude et le rayon de la zone (en ..), ainsi que la date de debut et la date de fin de la periode a moyenner:"
            << endl;
}

void menuDemandeDates() {
    cout << "\nInserer la date de debut et la date de fin de la periode a moyenner (aaaa-mm-jj):" << endl;
}

void menuConsulterCapteur() {
    cout << "\nEntrez le numero du capteur  a analyser\n(saisissez \"aucun\" pour retourner au menu):" << endl;
}


void menuConsulterDetailsCapteur() {
    cout << "\nMenu" << endl;
    cout << "2.1-Consulter les capteurs similaires\n"
            "2.2-Voir si un capteur est défectueux(pas implemente)" << endl;
}



void menuConsulterPurificateurs() {
    cout << "\nEntrez le numero du purificateur dont la zone d'influence doit etre calculee \n(saisissez \"aucun\" pour retourner au menu):"
            << endl;
}

void resultatQualiteEnPoint(int Qualite) {
    cout << "\nLa qualite de l'air en ce point est de : " << Qualite << endl;

}

void resultatListeCapteur(list<Capteur*> tousCapteurs){
    cout << "\nListe des capteurs :" << endl;
    for (list<Capteur*>::iterator it=tousCapteurs.begin();it!=tousCapteurs.end();it++){
        cout << (*(*it)) <<  endl;
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
    delete[] ids;
    delete[] scores;

}


void retourPasDeCapteurs(){
    cout << "\nAucun Capteur a comparer\n"
         << "Retour au menu principal " << endl;
}

void retourMauvaisesCoordonnees(){
    cout << "\nMauvaises coordonnees, en dehors du perimetre mesure\n"
         << "Retour au menu principal " << endl;
}

void retourCapteurInexistant(){
    cout << "\nL'id renseigne ne correspond a aucun capteur\n"
         << "Retour au menu principal " << endl;
}

