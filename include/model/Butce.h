#ifndef BUTCE_H
#define BUTCE_H

#include <string>

class Butce {
private:
    std::string donem;
    double hedefLimit;
    double mevcutHarcama;

public:
    Butce(const std::string& donem = "2026-11", double hedefLimit = 0.0);

    std::string getDonem() const;
    double getHedefLimit() const;
    double getMevcutHarcama() const;

    void setDonem(const std::string& yeniDonem);
    void setHedefLimit(double yeniLimit);
    void harcamaEkle(double tutar);
    bool limitAsildiMi() const;
    double kalanLimit() const;
};

#endif