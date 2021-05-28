//
// Created by User on 07/05/2021.
//

#ifndef PROJETUML_MODEL_H
#define PROJETUML_MODEL_H

#include <string>
#include "Objets/Mesure.h"
#include "Objets/Capteur.h"
#include "Vue.h"
using namespace std;
void QualiteAirPoint(double latitude, double longitude, string dateDebut, string dateFin);
void capteursSimilaires(int idCapteur, string dateDebut, string dateFin);
void listerCapteurs();
void listerPurificateurs();
list<Capteur> determinerCapteursProches(double latitude, double longitude);
int determinerQualiteMoyenne(Capteur monCapteur);
int determinerQualite(Mesure maMesure);

#endif //PROJETUML_MODEL_H
