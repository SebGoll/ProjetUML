/**
    Gère l'affichage des menus du programme
    @file Vue.cpp
    @author ABHAY Annie, GOLL Sebastien, HASENFRATZ Louis, NGOV Sophanna (B3201-B3209)
*/


#ifndef PROJETUML_VUE_H
#define PROJETUML_VUE_H

#include "Capteur.h"
#include "Purificateur.h"

extern int droits;

void mainMenu();
void menuQualiteAir();
void menuConsulterCapteur();
void menuConsulterDetailsCapteur();
void menuQualiteAirPoint();
void menuQualiteAirZone();
void menuConsulterPurificateurs();
void menuDemandeDates();



#endif //PROJETUML_VUE_H
