
#include "../Model.h"
#include <iostream>

int droits;

void test0();
void test1();
void test2();
void test3();

int main(){

    test0();
    test1();
    test2();
    test3();

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
    cout<<"==================================\nTest 2 : un seul capteur"<<endl;
    cout<<"Resultat attendu:\nAucun capteur a comparer"<<endl;
    genererListeCapteurs("Data/DataSetTest-CapteursSimilaires/sensorsTest2.csv");
    genererListeMesures("Data/DataSetTest-CapteursSimilaires/measurementsTest2.csv");
    cout<<"Resultat:"<<endl;
    capteursSimilaires(2,"2019-01-01 12:00:00","2019-01-06 12:00:00");
}
void test3(){
    cout<<"==================================\nTest 2 : capteurs très different (valeurs extrèmes)"<<endl;
    cout<<"Resultat attendu:\nCapteur 0 -> 45\nCapteur 1 -> 0\nCapteur 2 -> 45\nCapteur 3 -> 45\nCapteur 4 -> 45"<<endl;
    genererListeCapteurs("Data/DataSetTest-CapteursSimilaires/sensorsTest3.csv");
    genererListeMesures("Data/DataSetTest-CapteursSimilaires/measurementsTest3.csv");
    cout<<"Resultat:"<<endl;
    capteursSimilaires(1,"2019-01-01 12:00:00","2019-01-06 12:00:00");
}


