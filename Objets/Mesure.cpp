#include "Mesure.h"


Mesure::Mesure() {
    time_t t = time(nullptr);
    tm t2 = *localtime(&t);
    this->date = t2;
    this->o3 = 0;
    this->no2 = 0;
    this->so2 = 0;
    this->pm10 = 0;
}

Mesure::Mesure(tm date, float o3, float no2, float so2, float pm10) {
    this->date = date;
    this->o3 = o3;
    this->no2 = no2;
    this->so2 = so2;
    this->pm10 = pm10;
}

Mesure::Mesure(const string& dateString, float o3, float no2, float so2, float pm10) {

    this->o3 = o3;
    this->no2 = no2;
    this->so2 = so2;
    this->pm10 = pm10;

    time_t now = time(0);
    this->date = *localtime(&now);
    //seul les informations modifiées ici seront correcte, impossible d'utiliser tm_wday, tm_yday, tm_isdst
    this->date.tm_year = stoi(dateString.substr(0, 4)) - 1900;
    this->date.tm_mon = stoi(dateString.substr(5, 2)) - 1;
    this->date.tm_mday = stoi(dateString.substr(8, 2));
    this->date.tm_hour = stoi(dateString.substr(11, 2));
    this->date.tm_min = stoi(dateString.substr(14, 2));
    this->date.tm_sec = stoi(dateString.substr(17, 2));

}

Mesure::~Mesure() {

}

float Mesure::getO3() const {
    return o3;
}

void Mesure::setO3(float o3) {
    Mesure::o3 = o3;
}

void Mesure::setNo2(float no2) {
    Mesure::no2 = no2;
}

void Mesure::setSo2(float so2) {
    Mesure::so2 = so2;
}

void Mesure::setPm10(float pm10) {
    Mesure::pm10 = pm10;
}

float Mesure::getNo2() const {
    return no2;
}

float Mesure::getPm10() const {
    return pm10;
}

float Mesure::getSo2() const {
    return so2;
}

ostream &operator<<(ostream &flux, const Mesure &m) {
    tm dateMesure = m.getDate();
    flux <<  "Mesure prise le " << asctime(&dateMesure)<<"O3="<<m.getO3()<<"\tNo2="<<m.getNo2()<<"\tSo2="<<m.getSo2()<<"\tPm10="<<m.getPm10()<<endl;
    return flux;
}

tm Mesure::getDate() const {
    return date;
}

void Mesure::setDate(tm date) {
    Mesure::date = date;
}
