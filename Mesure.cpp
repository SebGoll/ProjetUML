#include "Mesure.h"

Mesure::Mesure() {}

Mesure::Mesure(tm *date, float o3, float no2, float so2, float pm10){
    this->date = date;
    this->o3 = o3;
    this->no2 = no2;
    this->so2 = so2;
    this->pm10 = pm10;
}

Mesure::Mesure(string date, float o3, float no2, float so2, float pm10) {

    this->o3 = o3;
    this->no2 = no2;
    this->so2 = so2;
    this->pm10 = pm10;

    time_t now = time(0);
    this->date = localtime(&now);

    //seul les informations modifiées ici seront correcte, impossible d'utiliser tm_wday, tm_yday, tm_isdst
    this->date->tm_year=stoi(date.substr(0,4))-1900;
    this->date->tm_mon=stoi(date.substr(5,2))-1;
    this->date->tm_mday=stoi(date.substr(8,2));
    this->date->tm_hour=stoi(date.substr(11,2));
    this->date->tm_min=stoi(date.substr(14,2));
    this->date->tm_hour=stoi(date.substr(17,2));


}

Mesure::~Mesure() {

}
