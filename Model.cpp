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

list<Capteur*> listetotal;

void QualiteAirPoint(float latitude, float longitude, string dateDebut, string dateFin) {
    Capteur* troiscapteursproches[3];
    troiscapteursproches[0]= new Capteur();
    troiscapteursproches[1]= new Capteur();
    troiscapteursproches[2]= new Capteur();
    float d1=1000,d2=1000,d3=1000;

    float dactuel;
    for(list<Capteur*>::iterator it=listetotal.begin(); it!=listetotal.end();it++){
        dactuel= (*it)->distance(latitude,longitude);
        if (dactuel<max(d1,d2,d3)){
            if(max(d1,d2,d3)==d1) {
                d1=dactuel;
                troiscapteursproches[0]=(*it);
            }
            } else  if(max(d1,d2,d3)==d2){
                d2=dactuel;
                troiscapteursproches[1]=(*it);
            } else {
                d3=dactuel;
                troiscapteursproches[2]=(*it);

            }


    }

    int v1,v2,v3;
    v1= determinerQualiteMoyenne(*troiscapteursproches[0]);
    v2= determinerQualiteMoyenne(*troiscapteursproches[1]);
    v3= determinerQualiteMoyenne(*troiscapteursproches[2]);
    float vfinal = d1*v1 +d2*v2 +d3*v3;
    vfinal/=d1+d2+d3;
    resultatQualiteEnPoint(vfinal);

}

void capteursSimilaires(int idCapteur, string dateDebut, string dateFin){
    Capteur capteuracomparer;
    for(list<Capteur*>::iterator it=listetotal.begin(); it!=listetotal.end();it++){
        if((*it)->getId()==idCapteur){
            capteuracomparer=*(*it);
        } else {
            

        }
    }




}



void listerCapteurs() {
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
    resultatListeCapteur(listCapteurs);
}

void listerPurificateurs() {
    list<Purificateur> listPurificateurs;
    

    resultatListePurificateur(listPurificateurs);
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