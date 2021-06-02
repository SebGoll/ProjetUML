/**
 *  Gère l'affichage des menus du programme
 *  @file Vue.h
 *  @author ABHAY Annie, GOLL Sebastien, HASENFRATZ Louis, NGOV Sophanna (B3201-B3209)
 */

#ifndef PROJETUML_VUE_H
#define PROJETUML_VUE_H

#include "Objets/Capteur.h"
#include "Objets/Purificateur.h"

#include <list>
extern int droits;
//Methodes pour l'affichage des differents menus
void mainMenu();
void menuQualiteAir();
void menuConsulterCapteur();
void menuConsulterDetailsCapteur();
void menuQualiteAirPoint();
void menuQualiteAirZone();
void menuConsulterPurificateurs();
void menuDemandeDates();

//Methodes pour l'affichage des erreurs
void ErreurSaisie();
void MauvaisesDates();
void ErreurHorsMesure();
void retourPasDeCapteurs();

//Methodes pour afficher des valeurs liées aux données
void resultatQualiteEnPoint(int Qualite);
void resultatListeCapteur(list<Capteur*> tousCapteurs);
void resultatListePurificateur(list<Purificateur*> tousPurificateurs);
void resultatCapteursSimilaires( int *scores,int *ids,int taille);
#endif //PROJETUML_VUE_H
