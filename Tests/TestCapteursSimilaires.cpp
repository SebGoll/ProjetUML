
#include "../Model.h"
int droits;

void test0();
void test1();
void test2();

int main(){

//    test0();
//    test1();
    test2();

    return 0;
}

void test0(){
    genererListeCapteurs("Data/DataSetTest-CapteursSimilaires/sensorsTest0.csv");
    genererListeMesures("Data/DataSetTest-CapteursSimilaires/measurementsTest0.csv");
    capteursSimilaires(50,"2019-08-21 12:00:00","2019-11-10 12:00:00");
}

void test1(){
    genererListeCapteurs("Data/DataSetTest-CapteursSimilaires/sensorsTest1.csv");
    genererListeMesures("Data/DataSetTest-CapteursSimilaires/measurementsTest1.csv");
    capteursSimilaires(50,"2019-01-20 12:00:00","2019-11-10 12:00:00");
}
void test2(){
    genererListeCapteurs("Data/DataSetTest-CapteursSimilaires/sensorsTest2.csv");
    genererListeMesures("Data/DataSetTest-CapteursSimilaires/measurementsTest2.csv");
    capteursSimilaires(0,"2019-01-20 12:00:00","2019-11-10 12:00:00");
}

