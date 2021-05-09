//
// Created by User on 07/05/2021.
//

#ifndef PROJETUML_MODEL_H
#define PROJETUML_MODEL_H

#include <string>
#include <list>
#include "Mesure.h"
#include "Capteur.h"
#include "Vue.h"
using namespace std;
void QualiteAirPoint(double latitude, double longitude, string dateDebut, string dateFin);
void capteursSimilaires(int idCapteur, string dateDebut, string dateFin);
void listerCapteurs();
void listerPurificateurs();
void determinerCapteursProches(double latitude, double longitude);
void determinerQualiteMoyenne(Capteur monCapteur);
void determinerQualite(Mesure maMesure);

#endif //PROJETUML_MODEL_H
