#include <iostream>
#include "../Model.h"

/* Nous fixons une limite de 43 à 48.6 en latitude et de -2 à 6.3 en longitude */

void test0();
int droits=0;

int main(){
    test0();
}

void test0(){
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest0.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest0.csv");
    QualiteAirPoint(45,5, "2019-01-01 12:00:00", "2021-02-20 12:00:00");
}