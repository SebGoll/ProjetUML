//
// Created by User on 07/05/2021.
//
#include <iostream>
#include <string>
#include "Vue.h"

using namespace std;
int droits;

int main() {





    //lecture
    cout << "1: droits du gouv \n2: droit d'un utilisateur lambda\n3: droits fournisseur" << endl;
    cin >> droits;
    int val = -1;
    string lecture;
    double latitude;
    double longitude;
    double rayon;
    string idcapteur;
    string idpurificateur;
    string datedebut, datefin;
    int optionquitter = (droits == 1) ? 4 : 3;
    while (val != optionquitter) {
        mainMenu();
        cin >> lecture;
        while (lecture.length() != 1 || !(lecture[0] >= '1' && lecture[0] <= '4')) {
            mainMenu();
            cin >> lecture;
        }
        val = stoi(lecture);
        if (val == 1) {

            menuQualiteAir();
            cin >> lecture;
            while (lecture.length() != 1 || !(lecture[0] >= '1' && lecture[0] <= '4')) {
                menuQualiteAir();
                cin >> lecture;
            }
            val = stoi(lecture);
            if (val == 1) {

                menuQualiteAirPoint();
                cin >> lecture;
                latitude = stod(lecture);
                cin >> lecture;
                longitude = stod(lecture);
                cin >> lecture;
                datedebut = lecture;
                cin >> lecture;
                datefin = lecture;
                cout << "appel a model : calcul point avec lat= " << latitude << " et long=" << longitude << " de "
                     << datedebut << " a " << datefin << endl;
                val = 1;


            } else if (val == 2) {

                menuQualiteAirZone();
                cin >> lecture;
                latitude = stod(lecture);
                cin >> lecture;
                longitude = stod(lecture);
                cin >> lecture;
                rayon = stod(lecture);
                cin >> lecture;
                datedebut = lecture;
                cin >> lecture;
                datefin = lecture;
                cout << "appel a model : calcul zone avec lat= " << latitude << "  ,long= " << longitude
                     << " et rayon= " << rayon << " de " << datedebut << " a " << datefin << endl;
                val = 1;
            }

        } else if (val == 2 && droits == 1) {
            cout << "appel a model : liste des capteurs" << endl;
            menuConsulterCapteur(/*Liste des Capteurs*/);
            cin >> lecture;
            if (lecture == "aucun") {
                continue;
            }
            idcapteur = lecture;
            menuConsulterDetailsCapteur();

            cin >> lecture;
            while (lecture.length() != 1 || !(lecture[0] >= '1' && lecture[0] <= '2')) {
                menuConsulterDetailsCapteur();
                cin >> lecture;
            }
            val = stoi(lecture);
            if (val == 1) {
                menuDemandeDates();
                cin >> lecture;
                datedebut = lecture;
                cin >> lecture;
                datefin = lecture;
                cout << "appel a model : calcul similarité avec idcapteur= " << idcapteur << " de " << datedebut
                     << " a " << datefin << endl;
                val = 2;


            } else if (val == 2) {

                cout << "appel a model : calcul defectueux avec idcapteur= " << idcapteur << endl;
                val = 2;
            }
        } else if (val == 2 && droits == 2) {
            cout << "appel a view : consulter son compte (pas du tout implementer)" << endl;

        } else if (val == 2 && droits == 3) {

            cout << "appel a view : consulter ses purificateurs (pas du tout implementer)" << endl;


        } else if (val == 3 && droits == 1) {
            cout << "appel a model : liste des purificateurs" << endl;
            menuConsulterPurificateurs(/*Liste Des Purificateurs*/);
            cin >> lecture;
            if (lecture == "aucun") {
                continue;
            }
            idpurificateur = lecture;
            cout << "appel a model :calcul rayon d'influence avec idpurificateur= " << idpurificateur << endl;
        }
    }


    cout << "fin du programme" << endl;

    return 0;


}
