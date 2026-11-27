#ifndef KONSOL_ARAYUZU_H
#define KONSOL_ARAYUZU_H

#include "service/Kullanici.h"

class KonsolArayuzu {
private:
    Kullanici& kullanici;

    void tamponTemizle() const;
    void menuyuYazdir() const;
    void gelirEkleEkrani();
    void giderEkleEkrani();

public:
    explicit KonsolArayuzu(Kullanici& kullanici);
    void calistir();
};

#endif