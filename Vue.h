#ifndef PROJETUML_VUE_H
#define PROJETUML_VUE_H

#include "Capteur.h"

extern int droits;

void mainMenu();
void menuQualiteAir();
void menuConsulterCapteur(list<Capteur> listCapt);
void menuConsulterDetailsCapteur();
void menuQualiteAirPoint();
void menuQualiteAirZone();


void menuConsulterPurificateurs(list<Purificateur> listPuri);



#endif //PROJETUML_VUE_H
