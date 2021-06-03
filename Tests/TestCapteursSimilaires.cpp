
#include "../Model.h"
#include <iostream>
#include <time.h>

int droits;

void test0();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void testPerformance();

int main(){

    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    testPerformance();

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

void test4() {
    cout << "==================================\nTest 4 : capteur saisi inexistant" << endl;
    cout << "Resultat attendu:\nCapteur saisi incorrect" << endl;
    genererListeCapteurs("Data/DataSetTest-CapteursSimilaires/sensorsTest0.csv");
    genererListeMesures("Data/DataSetTest-CapteursSimilaires/measurementsTest0.csv");
    cout << "Resultat:" << endl;
    capteursSimilaires(7, "2019-01-01 12:00:00", "2019-01-06 12:00:00");
}
void test5() {
    cout << "==================================\nTest 5 : Dates sans mesures" << endl;
    cout << "Resultat attendu:\nDates saisies incorrectes" << endl;
    genererListeCapteurs("Data/DataSetTest-CapteursSimilaires/sensorsTest0.csv");
    genererListeMesures("Data/DataSetTest-CapteursSimilaires/measurementsTest0.csv");
    cout << "Resultat:" << endl;
    capteursSimilaires(2, "2019-02-01 12:00:00", "2019-02-06 12:00:00");
}

void test6() {
    cout << "==================================\nTest 6 : dates inversees" << endl;
    cout << "Resultat attendu:\nLes dates donnees ne sont pas dans le bon ordre" << endl;
    genererListeCapteurs("Data/DataSetTest-CapteursSimilaires/sensorsTest0.csv");
    genererListeMesures("Data/DataSetTest-CapteursSimilaires/measurementsTest0.csv");
    cout << "Resultat:" << endl;
    capteursSimilaires(2,  "2019-01-06 12:00:00","2019-01-01 12:00:00");
}

void testPerformance(){
    cout << "==================================\nTest de performance : temps d'execution" << endl;
    cout << "Resultat attendu:\nTemps pour le chargement des donnees < 3sec\nTemps d'execution de l'algorithme < 1sec" << endl;
    clock_t start,mid,end;
    start=clock();
    genererListeCapteurs("Data/sensors.csv");
    genererListeMesures("Data/measurements.csv");
    mid=clock();
    capteursSimilaires(50,  "2019-01-01 12:00:00","2019-12-31 12:00:00");
    end=clock();
    cout << "Resultat:" << endl;

    cout<< "Temps de chargement des donnees: "<<float(mid-start)/CLOCKS_PER_SEC<<"s"<<endl;
    cout<< "Temps d'execution de l'algorithme: "<< float(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
}
