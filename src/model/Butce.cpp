#include "model/Butce.h"

Butce::Butce(const std::string& donem, double hedefLimit)
    : donem(donem), hedefLimit(hedefLimit), mevcutHarcama(0.0) {}

std::string Butce::getDonem() const { return donem; }
double Butce::getHedefLimit() const { return hedefLimit; }
double Butce::getMevcutHarcama() const { return mevcutHarcama; }

void Butce::setDonem(const std::string& yeniDonem) { donem = yeniDonem; }
void Butce::setHedefLimit(double yeniLimit) { hedefLimit = yeniLimit; }
void Butce::harcamaEkle(double tutar) { mevcutHarcama += tutar; }

bool Butce::limitAsildiMi() const {
    return (hedefLimit > 0.0) && (mevcutHarcama > hedefLimit);
}

double Butce::kalanLimit() const {
    return hedefLimit - mevcutHarcama;
}