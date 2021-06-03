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
int droits=0;

int main(){
    //test0(); //ok
    //test1(); //il faut pas afficher 'qualite air de ce point est 7'
    //test2(); //ok
    //test3(); //ok (affiche la même chose que pour test2)
    //test4(); //ok
    //test5(); //ok
    test6();
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

void test6(){ //Point normal
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest1.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest1.csv");
    QualiteAirPoint(45,5.4, "2019-01-01 12:00:00", "2021-02-20 12:00:00");
}