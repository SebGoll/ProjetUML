//
// Created by User on 07/05/2021.
//

#include "Model.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

list<Capteur*> listCapteurs;
list<Purificateur*> listPurificateurs;
list<Mesure*> listMesures;

void genererListeCapteurs(){
    ifstream fileToRead;
    string id;
    string longitude;
    string latitude;
    string toErase = "Sensor";
    fileToRead.open("Data/sensors.csv");
    if (!fileToRead) {
        cerr <<"Echec de l'ouverture du fichier";
        exit(1);
    }
    while(fileToRead.peek()!=EOF){

        getline(fileToRead,id,';');
        getline(fileToRead,longitude,';');
        getline(fileToRead,latitude);
        Capteur * c = new Capteur(stoi(id.erase(0,toErase.length())),stoi(longitude), stoi(latitude));

        listCapteurs.push_back(c);
    }
    fileToRead.close();
}

void genererListeMesures(){
    ifstream fileToRead;
    string date;
    string id;
    string longitude;
    string mesureType;
    string mesure[4];
    int i = 0;
    string latitude;
    string toErase = "Sensor";
    Mesure *m;
    fileToRead.open("Data/cleaners.csv");
    if (!fileToRead) {
        cerr <<"Echec de l'ouverture du fichier";
        exit(1);
    }
    while(fileToRead.peek()!=EOF){
        getline(fileToRead,date,';');
        getline(fileToRead,id,';');
        getline(fileToRead,mesureType,';');
        getline(fileToRead,mesure[i]);
        i++;
        if (i == 4){
            m = new Mesure(date, stoi(mesure[0]),stoi(mesure[1]),stoi(mesure[2]),stoi(mesure[3]) );
        }

        listMesures.push_back(m);
        for (Capteur* c:listCapteurs){
            if (c->getId()== stoi(id.erase(0,toErase.length()))){
                c->ajouterMesure(m);
            }
        }
    }
    fileToRead.close();
}


void QualiteAirPoint(double latitude, double longitude, string dateDebut, string dateFin) {
    resultatQualiteEnPoint(0);

}


void listerCapteurs() {
    genererListeCapteurs();
    resultatListeCapteur(listCapteurs);
}

void listerPurificateurs() {

//    resultatListePurificateur(listPurificateurs);
}

int determinerQualiteMoyenne(Capteur monCapteur){
    list<Mesure*> mesmesures =monCapteur.getMesures();
    int moyenne =0 ;
    
    for(list<Mesure*>::iterator it=mesmesures.begin(); it!=mesmesures.end();it++){
        moyenne+= determinerQualite(**it);
    }
    moyenne/=mesmesures.size();


    return moyenne;
}


int determinerQualite(Mesure maMesure) {
    float no2 = maMesure.getNo2();
    float o3 = maMesure.getO3();
    float pm10 = maMesure.getPm10();
    float so2 = maMesure.getSo2();
    if( o3<=29 && so2<=39 && no2<=29 && pm10<=6){
        return 1;
    } else if( o3<=54 && so2<=79 && no2<=54 && pm10<=13){
        return 2;
    } else if( o3<=79 && so2<=119 && no2<=84 && pm10<=20){
        return 3;
    } else if( o3<=104 && so2<=159 && no2<=109 && pm10<=27){
        return 4;
    } else if( o3<=129 && so2<=199 && no2<=134 && pm10<=34){
        return 5;
    } else if( o3<=149 && so2<=249 && no2<=164 && pm10<=41){
        return 6;
    } else if( o3<=179 && so2<=299 && no2<=199 && pm10<=49){
        return 7;
    } else if( o3<=209 && so2<=399 && no2<=274 && pm10<=64){
        return 8;
    } else if( o3<=239 && so2<=499 && no2<=399 && pm10<=79){
        return 9;
    } else{
        return 10;
    }
}