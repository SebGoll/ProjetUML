#include <iostream>
using namespace std;
#include "Utilisateur.h"

int main(){

    Utilisateur *u = new Utilisateur(1,"Roy","David","a@m.com","mdp555");
    cout<<(*u)<<endl;

    return 0;
}