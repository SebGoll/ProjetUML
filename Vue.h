/**
    Gère l'affichage des menus du programme
    @file Vue.h
    @author ABHAY Annie, GOLL Sebastien, HASENFRATZ Louis, NGOV Sophanna (B3201-B3209)
*/


#ifndef PROJETUML_VUE_H
#define PROJETUML_VUE_H

#include "Objets/Capteur.h"
#include "Objets/Purificateur.h"

#include <list>
extern int droits;

void mainMenu();
void menuQualiteAir();
void menuConsulterCapteur();
void menuConsulterDetailsCapteur();
void menuQualiteAirPoint();
void menuQualiteAirZone();
void menuConsulterPurificateurs();
void menuDemandeDates();


void resultatQualiteEnPoint(int Qualite);
void resultatListeCapteur(list<Capteur> tousCapteurs);
void resultatListePurificateur(list<Purificateur> tousPurificateurs);
#endif //PROJETUML_VUE_H
