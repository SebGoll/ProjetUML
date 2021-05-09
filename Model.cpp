//
// Created by User on 07/05/2021.
//

#include "Model.h"



void QualiteAirPoint(double latitude, double longitude, string dateDebut, string dateFin){

    resultatQualiteEnPoint(0);

}


void listerCapteurs(){
    list<Capteur> listetotal;

    resultatListeCapteur(listetotal);
}

void listerPurificateurs(){
    list<Purificateur> listetotal;
    resultatListePurificateur(listetotal);
}