/**
    Gère les entrées utilisateurs du programme
    @file Controller.cpp
    @author ABHAY Annie, GOLL Sebastien, HASENFRATZ Louis, NGOV Sophanna (B3201-B3209)
*/
#include <iostream>
#include <string>
#include "Vue.h"
#include "Model.h"
#include <sstream>
using namespace std;
int droits;





bool isFloat( const string& s ) {
    std::istringstream iss(s);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

bool isInteger(const string & s)
{
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char * p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}

bool isDate(const string & s){
    if(s.empty() || s.size()!=10) return false;
    string a = s.substr(0,4);
    string m = s.substr(5,2);
    string j = s.substr(8,2);
    char * p;
    char * p2;
    char * p3;
    strtol(a.c_str(), &p, 10);
    strtol(m.c_str(), &p2, 10);
    strtol(a.c_str(), &p3, 10);
    if (!(*p == 0 && *p2 == 0 && *p3 == 0)) return false;
    int ai,mi,ji;
    ai=stoi(a);
    mi=stoi(m);
    ji=stoi(j);

    return (2000<ai && ai<2500 && 0<mi && mi<13 && 0<ji && ji<32 );
}


int main() {




    genererListeCapteurs("Data/sensors.csv");
    genererListeMesures("Data/measurements.csv");
    //lecture
    cout << "1: droits du gouv \n2: droit d'un utilisateur lambda\n3: droits fournisseur" << endl;
    cin >> droits;
    int val = -1;
    string lecture;
    float latitude;
    float longitude;
    float rayon;
    int idcapteur;
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

                if(isFloat(lecture)==1){
                    latitude = stof(lecture);

                } else {
                    ErreurSaisie();
                    continue;
                }
                cin >> lecture;
                if(isFloat(lecture)==1){
                    longitude = stof(lecture);

                } else {
                    ErreurSaisie();
                    continue;
                }
                cin >> lecture;

                if(isDate(lecture)==1) {
                    datedebut = lecture;
                }else{

                    ErreurSaisie();
                    continue;
                }
                cin >> lecture;
                if(isDate(lecture)==1) {
                    datefin = lecture;
                }else{

                    ErreurSaisie();
                    continue;
                }
                QualiteAirPoint(latitude,longitude,datedebut,datefin);
                val = 1;


            } else if (val == 2) {

                menuQualiteAirZone();
                cin >> lecture;

                if(isFloat(lecture)==1){
                    latitude = stof(lecture);

                } else {
                    ErreurSaisie();
                    continue;
                }
                cin >> lecture;
                if(isFloat(lecture)==1){
                    longitude = stof(lecture);

                } else {
                    ErreurSaisie();
                    continue;
                }

                cin >> lecture;
                if(isFloat(lecture)==1){
                    rayon = stof(lecture);

                } else {
                    ErreurSaisie();
                    continue;
                }
                cin >> lecture;
                if(isDate(lecture)==1) {
                    datedebut = lecture;
                }else{

                    ErreurSaisie();
                    continue;
                }
                cin >> lecture;
                if(isDate(lecture)==1) {
                    datefin = lecture;
                }else{

                    ErreurSaisie();
                    continue;
                }
                cout << "appel a model : calcul zone avec lat= " << latitude << "  ,long= " << longitude
                     << " et rayon= " << rayon << " de " << datedebut << " a " << datefin << endl;
                val = 1;
            }

        } else if (val == 2 && droits == 1) {
            listerCapteurs();
            menuConsulterCapteur();
            cin >> lecture;
            if (lecture == "aucun") {
                continue;
            }
            if(isInteger(lecture)==0){
                ErreurSaisie();
                continue;
            }
            idcapteur = stoi(lecture);
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

                if(isDate(lecture)==1) {
                    datedebut = lecture;
                }else{

                    ErreurSaisie();
                    continue;
                }
                cin >> lecture;
                if(isDate(lecture)==1) {
                    datefin = lecture;
                }else{

                    ErreurSaisie();
                    continue;
                }
                capteursSimilaires(idcapteur,datedebut,datefin);

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
            listerPurificateurs();
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



