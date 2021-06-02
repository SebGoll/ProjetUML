/** @file Model.cpp
 *
 *  Classe Modele de l'architecture MVC qui
 *  s'occupe des donnees a stocker et afficher.
 *
 *  @author ABHAY Annie, GOLL Sebastien, HASENFRATZ Louis, NGOV Sophanna
 *  @date 07/05/2021
 */

#ifndef PROJETUML_MODEL_H
#define PROJETUML_MODEL_H
#include <string>
#include "Objets/Mesure.h"
#include "Objets/Capteur.h"
#include "Vue.h"
#include <ctime>
using namespace std;

<<<<<<< Updated upstream
void genererListeCapteurs(string dataPath);
void genererListeMesures(string dataPath);
=======
/** Generer la liste des capteurs */
void genererListeCapteurs();

/** Gnerer la liste des mesures */
void genererListeMesures();
>>>>>>> Stashed changes

/** Calcul de qualité de l'air en un point
 *
 * @param latitude
 * @param longitude
 * @param dateDebut
 * @param dateFin
 */
void QualiteAirPoint(float latitude, float longitude, string dateDebut, string dateFin);

/** Détermination des capteurs similaires
 *
 * @param idCapteur
 * @param dateDebut
 * @param dateFin
 */
void capteursSimilaires(int idCapteur, string dateDebut, string dateFin);

/** Envoie la liste des capteurs a la vue */
void listerCapteurs();
/** Envoie la liste des purificateurs a la vue */
void listerPurificateurs();

/**
 *
 * @param latitude du capteur
 * @param longitude du capteur
 * @return la liste des capteurs les plus proches
 */
list<Capteur> determinerCapteursProches(double latitude, double longitude); //la fonction est utilisée ou pas?

/** Qualité de l'air moyenne
 *
 * @param monCapteur : le capteur associé
 * @param dated : la date de début des mesures
 * @param datef : la date de fin des mesures
 * @return qualite d'air moyenne
 */
int determinerQualiteMoyenne(Capteur monCapteur, tm dated, tm datef);

/** Qualité de l'air à partir d'une mesure
 *
 * @param maMesure : Mesure d'un capteur
 * @return qualite de l'air
 */
int determinerQualite(Mesure maMesure);



#endif //PROJETUML_MODEL_H
