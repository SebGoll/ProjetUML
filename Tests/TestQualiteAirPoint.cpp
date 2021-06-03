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
void testPerformance();
int droits=0;

int main(){
    test0(); //ok
    test1(); //ok
    test2(); //ok
    test3(); //ok
    test4(); //ok
    test5(); //ok
    test6(); //ok
    test7(); //ok
    test8(); //ok
    testPerformance(); //ok
}

void test0(){ //Point normal
    cout<<"\n==================================\nTest 0 : Point normal"<<endl;
    cout<<"Resultat attendu: Qualite air en ce point: 7"<<endl;
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest0.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest0.csv");
    cout<<"Resultat:";
    QualiteAirPoint(45,5, "2020-01-01 12:00:00", "2021-02-20 12:00:00");
}

void test1(){ //Point inexistant
    cout<<"\n==================================\nTest 1 : Point inexistant (dehors de la limite)"<<endl;
    cout<<"Resultat attendu: Ce point n'appartient pas a la zone de mesure"<<endl;
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest0.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest0.csv");
    cout<<"Resultat:";
    QualiteAirPoint(49,8, "2019-01-01 12:00:00", "2021-02-20 12:00:00");
}

void test2(){ //Pas de valeurs entre date début et date fin
    cout<<"\n==================================\nTest 2 : Pas de mesures entre date debut et date fin"<<endl;
    cout<<"Resultat attendu: Pas de mesures entre ces deux dates"<<endl;
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest0.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest0.csv");
    cout<<"Resultat:";
    QualiteAirPoint(45,5, "2021-01-01 12:00:00", "2021-02-20 12:00:00");
}

void test3(){ //Date debut pas encore atteint
    cout<<"\n==================================\nTest 3 : Date debut pas encore atteint"<<endl;
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest0.csv");
    cout<<"Resultat attendu: Erreur, date de debut non atteint"<<endl;
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest0.csv");
    cout<<"Resultat:";
    QualiteAirPoint(45,5, "2021-01-01 12:00:00", "2022-02-20 12:00:00");
}

void test4(){ //Date fin avant date début
    cout<<"\n==================================\nTest 4 : Date fin avant date debut"<<endl;
    cout<<"Resultat attendu: Erreur, date fin avant date debut"<<endl;
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest0.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest0.csv");
    cout<<"Resultat:";
    QualiteAirPoint(45,5, "2020-01-01 12:00:00", "2019-02-20 12:00:00");
}

void test5(){ //Dates debut fin éloignées
    cout<<"\n==================================\nTest 5 : Date debut et fin tres eloignees"<<endl;
    cout<<"Resultat attendu: Qualite air en ce point: 7"<<endl;
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest0.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest0.csv");
    cout<<"Resultat:";
    QualiteAirPoint(45,5, "2018-01-01 12:00:00", "2021-02-20 12:00:00");
}

void test6(){ //Point sur un capteur
    cout<<"\n==================================\nTest 6 : Point sur un capteur"<<endl;
    cout<<"Resultat attendu: Qualite air en ce point: 3"<<endl;
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest1.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest1.csv");
    cout<<"Resultat:";
    QualiteAirPoint(45,5.4, "2019-01-01 12:00:00", "2021-02-20 12:00:00");
}

void test7(){ //Point sur la limite minimale
    cout<<"\n==================================\nTest 7 : Point sur la limite minimale"<<endl;
    cout<<"Resultat attendu: Qualite air en ce point: 5"<<endl;
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest2.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest2.csv");
    cout<<"Resultat:";
    QualiteAirPoint(43,-2, "2018-01-01 12:00:00", "2021-02-20 12:00:00");
}

void test8(){ //Point sur la limite maximale
    cout<<"\n==================================\nTest 8 : Point sur la limite maximale"<<endl;
    cout<<"Resultat attendu: Qualite air en ce point: 4"<<endl;
    genererListeCapteurs("Data/DataSetTest-QualiteAirPoint/sensorTest2.csv");
    genererListeMesures("Data/DataSetTest-QualiteAirPoint/measureTest2.csv");
    cout<<"Resultat:";
    QualiteAirPoint(48.6,6.3, "2018-01-01 12:00:00", "2021-02-20 12:00:00");
}

void testPerformance(){
    cout << "\n==================================\nTest de performance : temps d'execution" << endl;
    cout << "Resultat attendu:\nTemps pour le chargement des donnees < 3sec\nTemps d'execution de l'algorithme < 1sec" << endl;
    clock_t start,mid,end;
    start=clock();
    genererListeCapteurs("Data/sensors.csv");
    genererListeMesures("Data/measurements.csv");
    mid=clock();
    QualiteAirPoint(45,5,  "2019-01-01 12:00:00","2020-12-31 12:00:00");
    end=clock();
    cout << "Resultat:" << endl;

    cout<< "Temps de chargement des donnees: "<<float(mid-start)/CLOCKS_PER_SEC<<"s"<<endl;
    cout<< "Temps d'execution de l'algorithme: "<< float(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
}