#include "service/Kullanici.h"
#include <iostream>
#include <iomanip>

Kullanici::Kullanici(const std::string& adSoyad)
    : adSoyad(adSoyad), aktifButce("2026-11", 0.0), sonrakiIslemId(1) {
    varsayilanKategorileriYukle();
}

Kullanici::~Kullanici() {
    for (FinansalIslem* islem : islemler) {
        delete islem;
    }
    islemler.clear();
}

void Kullanici::varsayilanKategorileriYukle() {
    kategoriler.emplace_back(1, "Maas / Burs", "Gelir");
    kategoriler.emplace_back(2, "Ek Gelir", "Gelir");
    kategoriler.emplace_back(3, "Gida", "Gider");
    kategoriler.emplace_back(4, "Ulasim", "Gider");
    kategoriler.emplace_back(5, "Kira / Fatura", "Gider");
    kategoriler.emplace_back(6, "Egitim / Kitap", "Gider");
}

std::string Kullanici::getAdSoyad() const { return adSoyad; }
const std::vector<Kategori>& Kullanici::getKategoriler() const { return kategoriler; }

void Kullanici::gelirEkle(double tutar, const std::string& tarih,
                          const std::string& kategoriAdi, const std::string& aciklama,
                          const std::string& kaynak) {
    islemler.push_back(new Gelir(sonrakiIslemId++, tutar, tarih, kategoriAdi, aciklama, kaynak));
}

void Kullanici::giderEkle(double tutar, const std::string& tarih,
                          const std::string& kategoriAdi, const std::string& aciklama,
                          const std::string& odemeYontemi) {
    islemler.push_back(new Gider(sonrakiIslemId++, tutar, tarih, kategoriAdi, aciklama, odemeYontemi));
    aktifButce.harcamaEkle(tutar);
}

double Kullanici::toplamGelirHesapla() const {
    double toplam = 0.0;
    for (const FinansalIslem* islem : islemler) {
        if (islem->getTur() == "Gelir") {
            toplam += islem->getTutar();
        }
    }
    return toplam;
}

double Kullanici::toplamGiderHesapla() const {
    double toplam = 0.0;
    for (const FinansalIslem* islem : islemler) {
        if (islem->getTur() == "Gider") {
            toplam += islem->getTutar();
        }
    }
    return toplam;
}

double Kullanici::netBakiyeHesapla() const {
    return toplamGelirHesapla() - toplamGiderHesapla();
}

void Kullanici::islemleriListele() const {
    std::cout << "\n--- KAYITLI FINANSAL ISLEMLER ---\n";
    if (islemler.empty()) {
        std::cout << "Henuz kayitli bir gelir veya gider islemi bulunmamaktadir.\n";
        return;
    }
    for (const FinansalIslem* islem : islemler) {
        islem->bilgiYazdir();
    }
}

void Kullanici::finansalOzetGoster() const {
    double gelir = toplamGelirHesapla();
    double gider = toplamGiderHesapla();
    double bakiye = netBakiyeHesapla();

    std::cout << "\n=========================================\n";
    std::cout << "  GENEL FINANSAL DURUM OZETI (" << adSoyad << ")\n";
    std::cout << "=========================================\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Toplam Gelir : +" << gelir << " TL\n";
    std::cout << "Toplam Gider : -" << gider << " TL\n";
    std::cout << "Net Bakiye   :  " << bakiye << " TL\n";
    std::cout << "=========================================\n";
}