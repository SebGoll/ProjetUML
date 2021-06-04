/**
 *  Interface de l'Objet Mesure qui sera associee a un capteur
 *  @file Mesure.h
 *  @author ABHAY Annie, GOLL Sebastien, HASENFRATZ Louis, NGOV Sophanna
 */

#ifndef PROJETUML_MESURE_H
#define PROJETUML_MESURE_H

//Interfaces itilisées
#include <ctime>
#include <string>
#include <iostream>

using namespace std;
//Constantes
//Types

//-------------
//Role de la classe <Mesure>
//Cette classe represente une mesure

class Mesure {
    //PUBLIC
public:
    //Getters/Setters
    tm getDate() const;

    void setDate(tm date);

    float getSo2() const;

    float getO3() const;

    float getNo2() const;

    float getPm10() const;

    void setO3(float o3);

    void setNo2(float no2);

    void setSo2(float so2);

    void setPm10(float pm10);

    //Surchages d'operateurs
    friend ostream &operator<<(ostream &flux, const Mesure &m);

    //Contructeurs/Destructeurs
    Mesure();

    Mesure(tm date, float o3, float no2, float so2, float pm10);

    Mesure(const string &date, float o3, float no2, float so2, float pm10);

    virtual ~Mesure();
    //PRIVE
protected:
    //Méthodes protégées

    //Attributs protégés
    tm date;
    float o3;
    float no2;
    float so2;
    float pm10;


};


#endif //PROJETUML_MESURE_H
