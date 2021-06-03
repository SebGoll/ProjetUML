#include <iostream>
#include "../Model.h"

/* Nous fixons une limite de 43 à 48.6 en latitude et de -2 à 6.3 en longitude */

void test0(); //Test qualité air point: Point normal
void test1(); //Test qualité air point: Point inexistant
void test2(); //Test qualité air Point: Date erronée: pas de valeurs entre début et fin
void test3(); //Test qualité air Point: Date erronée: date de debut pas atteint
void test4(); //Test qualité air Point: Date erronée: date fin avant date début
void test5(); //Test qualité air point: Date début et fin très éloignée
void test6(); //Test qualité air Point: Point sur un capteur
void test7(); //Test qualité air Point: Point sur la limite minimale
void test8(); //Test qualité air Point: Point sur la limite maximale
int droits=0;

int main(){
    //test0(); //ok : expecté: "qualité air = 7" | résultat: "qualité air = 7"
    //test1(); //ok : expecté: "point inexistant" | résultat: "mauvaises coordonnées en dehors du périmètre de mesure"
    //test2(); //ok : expecté: "pas de valeurs entre les deux dates" | résultat: "la période demandée en dehors de la période mesurée"
    //test3(); //ok : expecté: "erreur: date de début pas atteint" | résultat: "la période demandée en dehors de la période mesurée"
    //test4(); //ok : expecté: "erreur: date fin avant date début" | résultat: "les dates données pas dans le bon ordre"
    //test5(); //ok : expecté: "qualité air = 7" | résultat: "qualité air = 7"
    //test6(); //probleme :  expecté: "qualité air = 3" | résultat: "qualité air = 3 ET 5"
    //test7(); //ok : expecté: "qualité air = 5" | résultat: "qualité air = 5"
    //test8(); //probleme: expecté: "qualité air = 4" | résultat: "mauvaises coordonnées en dehors du périmètre de mesure" (longitude 6.3)
}

void test0(){ //Point normal
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest0.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest0.csv");
    QualiteAirPoint(45,5, "2020-01-01 12:00:00", "2021-02-20 12:00:00");
}

void test1(){ //Point inexistant
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest0.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest0.csv");
    QualiteAirPoint(49,8, "2019-01-01 12:00:00", "2021-02-20 12:00:00");
}

void test2(){ //Pas de valeurs entre date début et date fin
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest0.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest0.csv");
    QualiteAirPoint(45,5, "2021-01-01 12:00:00", "2021-02-20 12:00:00");
}

void test3(){ //Date debut pas encore atteint
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest0.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest0.csv");
    QualiteAirPoint(45,5, "2021-01-01 12:00:00", "2022-02-20 12:00:00");
}

void test4(){ //Date fin avant date début
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest0.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest0.csv");
    QualiteAirPoint(45,5, "2020-01-01 12:00:00", "2019-02-20 12:00:00");
}

void test5(){ //Dates debut fin éloignées
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest0.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest0.csv");
    QualiteAirPoint(45,5, "2018-01-01 12:00:00", "2021-02-20 12:00:00");
}

void test6(){ //Point sur un capteur
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest1.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest1.csv");
    QualiteAirPoint(45,5.4, "2019-01-01 12:00:00", "2021-02-20 12:00:00");
}

void test7(){ //Point sur la limite minimale
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest2.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest2.csv");
    QualiteAirPoint(43,-2, "2018-01-01 12:00:00", "2021-02-20 12:00:00");
}

void test8(){ //Point sur la limite maximale
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest2.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest2.csv");
    QualiteAirPoint(48.6,6.3, "2018-01-01 12:00:00", "2021-02-20 12:00:00");
}