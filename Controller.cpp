//
// Created by User on 07/05/2021.
//
#include <iostream>
#include <string>


using namespace std;
int main() {





    //lecture

    int val = -1;
    string lecture;
    double latitude;
    double longitude;
    double rayon;
    string idcapteur;
    string idpurificateur;
    while (val != 4) {
        cout <<"appel a view : menu principal"<<endl;

        cin >> lecture;
        while (lecture.length()!=1||!(lecture[0]>='1'&&lecture[0]<='4')){
            cout<<"appel a view : menu principal"<< endl;
            cin>>lecture;
        }
        val=stoi(lecture);
        if (val == 1) {


            cout <<"appel a view : sous menu qualite d'air"<<endl;
            cin>>lecture;
            while (lecture.length()!=1||!(lecture[0]>='1'&&lecture[0]<='4')){
                cout<<"appel a view : sous menu qualite d'air"<< endl;
                cin>>lecture;
            }
            val=stoi(lecture);
            if (val == 1) {

                cout <<"appel a view : sous menu choix coord point"<<endl;
                cin>>lecture;
                latitude=stod(lecture);
                cin>>lecture;
                longitude=stod(lecture);
                cout<<"appel a model : calcul point avec lat= "<< latitude<<" et long="<<longitude << endl;
                val = 1;


            } else if (val == 2) {

                cout <<"appel a view : sous menu choix coord zone"<<endl;
                cin>>lecture;
                latitude=stod(lecture);
                cin>>lecture;
                longitude=stod(lecture);
                cin>>lecture;
                rayon=stod(lecture);
                cout<<"appel a model : calcul zone avec lat= "<< latitude<<"  ,long= "<<longitude <<" et rayon= "<<rayon<< endl;
                val = 1;
            }

        } else if (val == 2) {
            cout <<"appel a model : liste des capteurs"<<endl;
            cout <<"appel a view : sous menu choix capteur"<<endl;
            cin>>lecture;
            idcapteur=lecture;
            cout <<"appel a view : sous menu analyse capteur"<<endl;
            cin>>lecture;
            while (lecture.length()!=1||!(lecture[0]>='1'&&lecture[0]<='2')){
                cout<<"appel a view : sous menu analyse capteur"<< endl;
                cin>>lecture;
            }
            val=stoi(lecture);
            if (val == 1) {


                cout<<"appel a model : calcul similarité avec idcapteur= "<< idcapteur << endl;
                val = 2;


            } else if (val == 2) {

                cout<<"appel a model : calcul defectueux avec idcapteur= "<< idcapteur << endl;
                val = 2;
            }

        } else if (val == 3) {
            cout <<"appel a model : liste des purificateurs"<<endl;
            cout <<"appel a view : sous menu choix purificateur"<<endl;
            cin>>lecture;
            idpurificateur=lecture;
            cout<<"appel a model :calcul rayon d'influence avec idpurificateur= "<< idpurificateur << endl;
        }
    }




    cout << "fin du programme" << endl;

    return 0;


}
