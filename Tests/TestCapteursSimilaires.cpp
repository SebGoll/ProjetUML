
#include "../Model.h"
#include <iostream>

int droits;

void test0();
void test1();
void test2();

int main(){

    test0();
    test1();
//    test2();

    return 0;
}

void test0(){
    cout<<"==================================\nTest 0 : fonctionnement normal"<<endl;
    cout<<"Resultat attendu:\nCapteur 0 -> 12\nCapteur 1 -> 20\nCapteur 2 -> 0\nCapteur 3 -> 5\nCapteur 4 -> 24"<<endl;
    genererListeCapteurs("Data/DataSetTest-CapteursSimilaires/sensorsTest0.csv");
    genererListeMesures("Data/DataSetTest-CapteursSimilaires/measurementsTest0.csv");
    cout<<"Resultat:"<<endl;
    capteursSimilaires(2,"2019-01-01 12:00:00","2019-01-06 12:00:00");

}

void test1(){
    cout<<"==================================\nTest 1 : capteurs identiques"<<endl;
    cout<<"Resultat attendu:\nCapteur 0 -> 0\nCapteur 1 -> 0\nCapteur 2 -> 0\nCapteur 3 -> 0\nCapteur 4 -> 0"<<endl;
    genererListeCapteurs("Data/DataSetTest-CapteursSimilaires/sensorsTest1.csv");
    genererListeMesures("Data/DataSetTest-CapteursSimilaires/measurementsTest1.csv");
    cout<<"Resultat:"<<endl;
    capteursSimilaires(2,"2019-01-01 12:00:00","2019-01-06 12:00:00");
}
void test2(){
    genererListeCapteurs("Data/DataSetTest-CapteursSimilaires/sensorsTest.csv");
    genererListeMesures("Data/DataSetTest-CapteursSimilaires/measurementsTest.csv");
    capteursSimilaires(2,"2019-01-01 12:00:00","2019-01-06 12:00:00");
}

