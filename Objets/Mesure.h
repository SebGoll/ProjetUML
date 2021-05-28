//Interface de la classe <Mesure> (fichier Mesure.h)
#ifndef PROJETUML_MESURE_H
#define PROJETUML_MESURE_H

//Interfaces itilisées
#include <ctime>
#include <string>

using namespace std;
//Constantes
//Types

//-------------
//Role de la classe <Mesure>
//Cette classe represente une mesure

class Mesure {
    //PUBLIC
public:

    Mesure();

    Mesure(tm *date, float o3, float no2, float so2, float pm10);

    Mesure(string date, float o3, float no2, float so2, float pm10);

    virtual ~Mesure();

    float getSo2() const;

    float getO3() const;

    float getNo2() const;

    float getPm10() const;
    //PRIVE
protected:
    //Méthodes protégées

    //Attributs protégés
    tm *date;
    float o3;
    float no2;
    float so2;
    float pm10;



};


#endif //PROJETUML_MESURE_H