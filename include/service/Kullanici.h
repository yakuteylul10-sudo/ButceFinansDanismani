#ifndef KULLANICI_H
#define KULLANICI_H

#include <string>
#include <vector>
#include "model/FinansalIslem.h"
#include "model/Gelir.h"
#include "model/Gider.h"
#include "model/Kategori.h"
#include "model/Butce.h"

class Kullanici {
private:
    std::string adSoyad;
    std::vector<FinansalIslem*> islemler;
    std::vector<Kategori> kategoriler;
    Butce aktifButce;
    int sonrakiIslemId;

    void varsayilanKategorileriYukle();

public:
    explicit Kullanici(const std::string& adSoyad);
    ~Kullanici();

    Kullanici(const Kullanici&) = delete;
    Kullanici& operator=(const Kullanici&) = delete;

    std::string getAdSoyad() const;
    const std::vector<Kategori>& getKategoriler() const;

    void gelirEkle(double tutar, const std::string& tarih,
                   const std::string& kategoriAdi, const std::string& aciklama,
                   const std::string& kaynak);

    void giderEkle(double tutar, const std::string& tarih,
                   const std::string& kategoriAdi, const std::string& aciklama,
                   const std::string& odemeYontemi);

    double toplamGelirHesapla() const;
    double toplamGiderHesapla() const;
    double netBakiyeHesapla() const;

    void islemleriListele() const;
    void finansalOzetGoster() const;
};

#endif