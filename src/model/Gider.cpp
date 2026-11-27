#include "model/Gider.h"
#include <iostream>
#include <iomanip>

Gider::Gider(int id, double tutar, const std::string& tarih,
             const std::string& kategoriAdi, const std::string& aciklama,
             const std::string& odemeYontemi)
    : FinansalIslem(id, tutar, tarih, kategoriAdi, aciklama), odemeYontemi(odemeYontemi) {}

std::string Gider::getOdemeYontemi() const { return odemeYontemi; }
void Gider::setOdemeYontemi(const std::string& yontem) { odemeYontemi = yontem; }

std::string Gider::getTur() const { return "Gider"; }

void Gider::bilgiYazdir() const {
    std::cout << "[" << id << "] [GIDER]  Tarih: " << tarih
              << " | Kategori: " << kategoriAdi
              << " | Tutar: -" << std::fixed << std::setprecision(2) << tutar << " TL"
              << " | Odeme: " << odemeYontemi
              << " | Aciklama: " << aciklama << "\n";
}