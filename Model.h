//
// Created by User on 07/05/2021.
//

#ifndef PROJETUML_MODEL_H
#define PROJETUML_MODEL_H

#include <string>
#include "Objets/Mesure.h"
#include "Objets/Capteur.h"
#include "Vue.h"
#include <ctime>
using namespace std;

void genererListeCapteurs(string dataPath);
void genererListeMesures(string dataPath);

void QualiteAirPoint(float latitude, float longitude, string dateDebut, string dateFin);

void capteursSimilaires(int idCapteur, string dateDebut, string dateFin);
void listerCapteurs();
void listerPurificateurs();
list<Capteur> determinerCapteursProches(double latitude, double longitude);
int determinerQualiteMoyenne(Capteur monCapteur, tm dated, tm datef);
int determinerQualite(Mesure maMesure);



#endif //PROJETUML_MODEL_H
