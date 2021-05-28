//
// Created by User on 07/05/2021.
//

#include "Model.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

list<Capteur*> listCapteurs;
list<Mesure*> listMesures;

void QualiteAirPoint(float latitude, float longitude, string dateDebut, string dateFin) {


    dateDebut.append(" 12:00:00");
    dateFin.append(" 12:00:00");
    time_t now = time(0);
    tm dated = *localtime(&now);
    dated.tm_year = stoi(dateDebut.substr(0, 4)) - 1900;
    dated.tm_mon = stoi(dateDebut.substr(5, 2)) - 1;
    dated.tm_mday = stoi(dateDebut.substr(8, 2));
    dated.tm_hour = stoi(dateDebut.substr(11, 2));
    dated.tm_min = stoi(dateDebut.substr(14, 2));
    dated.tm_sec = stoi(dateDebut.substr(17, 2));


    tm datef = *localtime(&now);
    datef.tm_year = stoi(dateFin.substr(0, 4)) - 1900;
    datef.tm_mon = stoi(dateFin.substr(5, 2)) - 1;
    datef.tm_mday = stoi(dateFin.substr(8, 2));
    datef.tm_hour = stoi(dateFin.substr(11, 2));
    datef.tm_min = stoi(dateFin.substr(14, 2));
    datef.tm_sec = stoi(dateFin.substr(17, 2));



    Capteur* troiscapteursproches[3];
    troiscapteursproches[0]= new Capteur();
    troiscapteursproches[1]= new Capteur();
    troiscapteursproches[2]= new Capteur();
    float d1=1000,d2=1000,d3=1000;
    float dactuel;

    for(list<Capteur*>::iterator it=listCapteurs.begin(); it!=listCapteurs.end();it++){

        dactuel= (*it)->distance(latitude,longitude);
        if (dactuel<max(max(d1,d2),d3)) {
            if (max(max(d1, d2), d3) == d1) {
                d1 = dactuel;
                troiscapteursproches[0] = (*it);
                cout <<" d1 " << (**it).getId() << " " << dactuel<<endl;
            } else if (max(max(d1, d2), d3) == d2) {
                d2 = dactuel;
                troiscapteursproches[1] = (*it);
                cout << " d2 "<<(**it).getId() << " " << dactuel<<endl;
            } else {
                d3 = dactuel;
                troiscapteursproches[2] = (*it);
                cout << " d3 "<<(**it).getId() << " " << dactuel<<endl;
            }
        }
    }
    int v1,v2,v3;
    v1= determinerQualiteMoyenne(*troiscapteursproches[0],dated,datef);
    v2= determinerQualiteMoyenne(*troiscapteursproches[1],dated,datef);
    v3= determinerQualiteMoyenne(*troiscapteursproches[2],dated,datef);
    float vfinal = d1*v1 +d2*v2 +d3*v3;
    vfinal/=d1+d2+d3;
    resultatQualiteEnPoint(vfinal);

}

void capteursSimilaires(int idCapteur, string dateDebut, string dateFin){
    Capteur capteuracomparer;
    for(list<Capteur*>::iterator it=listCapteurs.begin(); it!=listCapteurs.end();it++){
        if((*it)->getId()==idCapteur){
            capteuracomparer=*(*it);
        }
    }
    list<Mesure*> mesurescapteurPrincipal =capteuracomparer.getMesures();
    int *qualitesenchaquemesure=new int[mesurescapteurPrincipal.size()];
    int i=0;
    for(list<Mesure*>::iterator it=mesurescapteurPrincipal.begin(); it!=mesurescapteurPrincipal.end();it++){
        qualitesenchaquemesure[i]= determinerQualite(**it);
        i++;
    }
    int score;
    int *scores= new int[listCapteurs.size()];
    int j=0;
    for(list<Capteur*>::iterator it=listCapteurs.begin(); it!=listCapteurs.end();it++){
        score=0;
        i=0;

        if((*it)->getId()!=idCapteur){
            list<Mesure*> mesmesures =(**it).getMesures();

            for(list<Mesure*>::iterator m=mesmesures.begin(); m!=mesmesures.end();m++){
                score+= abs(qualitesenchaquemesure[i]-determinerQualite(**m));
                i++;
            }
        }
        scores[j]=score;
        j++;
    }

}

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
        getline(fileToRead,latitude, ';');
        fileToRead.ignore();
        Capteur * c = new Capteur(stoi(id.erase(0,toErase.length())),stof(longitude), stof(latitude));

        listCapteurs.push_back(c);
    }
    fileToRead.close();
}

void genererListeMesures(){
    ifstream fileToRead;
    string date;
    string id;
    string mesureType;
    string mesure[4];
    int i = 0;
    string toErase = "Sensor";
    Mesure *m;
    fileToRead.open("Data/measurements.csv");
    if (!fileToRead) {
        cerr <<"Echec de l'ouverture du fichier";
        exit(1);
    }
    while(fileToRead.peek()!=EOF){
        getline(fileToRead,date,';');
        getline(fileToRead,id,';');
        getline(fileToRead,mesureType,';');
        getline(fileToRead,mesure[i],';');
        fileToRead.ignore();
        i++;
        if (i == 4){
            m = new Mesure(date, stof(mesure[0]),stof(mesure[1]),stof(mesure[2]),stof(mesure[3]) );
            listMesures.push_back(m);
            int idCapteur = stoi(id.erase(0,toErase.length()));
            for (list<Capteur*>::iterator it=listCapteurs.begin();it!=listCapteurs.end();it++){
                if ((*it)->getId() == idCapteur){
                    (*it)->ajouterMesure(m);
                }
            }
            i=0;
        }
    }
    fileToRead.close();
}

void QualiteAirPoint(double latitude, double longitude, string dateDebut, string dateFin) {
    resultatQualiteEnPoint(0);

}


void listerCapteurs() {



    resultatListeCapteur(listCapteurs);

//    list<Capteur*>::iterator it = listCapteurs.begin();
//    list<Mesure*> mm = (*it)->getMesures();
//    cout << "Capteur" << (*it)->getId() << endl;
//    int i = 0;
//    for (Mesure *lol : mm) {
//        i++;
////        cout << "Mesures" << mm->getSo2() <<";"<< mm->getPm10() <<";" << mm->getO3() <<";"<< mm->getNo2() <<endl;
//    }
//    cout<<i<<endl;
//    cout<< mm.size() <<endl;
}

void listerPurificateurs() {

//    resultatListePurificateur(listPurificateurs);
}

int determinerQualiteMoyenne(Capteur monCapteur, tm dated, tm datef){
    list<Mesure*> mesmesures =monCapteur.getMesures();
    int moyenne =0 ;
    int nbmesure=0;
    for(list<Mesure*>::iterator it=mesmesures.begin(); it!=mesmesures.end();it++){
        tm datemesure = (**it).getDate();
        if(difftime(mktime(&datemesure),mktime(&dated))>=0 && (difftime(mktime(&datef),mktime(&datemesure))>=0)) {
            moyenne += determinerQualite(**it);
            nbmesure++;
        }
    }
    if(nbmesure!=0){
        moyenne/=nbmesure;
    }



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