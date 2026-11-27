#include "model/Gelir.h"
#include <iostream>
#include <iomanip>

Gelir::Gelir(int id, double tutar, const std::string& tarih,
             const std::string& kategoriAdi, const std::string& aciklama,
             const std::string& gelirKaynagi)
    : FinansalIslem(id, tutar, tarih, kategoriAdi, aciklama), gelirKaynagi(gelirKaynagi) {}

std::string Gelir::getGelirKaynagi() const { return gelirKaynagi; }
void Gelir::setGelirKaynagi(const std::string& kaynak) { gelirKaynagi = kaynak; }

std::string Gelir::getTur() const { return "Gelir"; }

void Gelir::bilgiYazdir() const {
    std::cout << "[" << id << "] [GELIR]  Tarih: " << tarih
              << " | Kategori: " << kategoriAdi
              << " | Tutar: +" << std::fixed << std::setprecision(2) << tutar << " TL"
              << " | Kaynak: " << gelirKaynagi
              << " | Aciklama: " << aciklama << "\n";
}