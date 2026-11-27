#include "model/Kategori.h"

Kategori::Kategori(int id, const std::string& ad, const std::string& tur)
    : id(id), ad(ad), tur(tur) {}

int Kategori::getId() const { return id; }
std::string Kategori::getAd() const { return ad; }
std::string Kategori::getTur() const { return tur; }
void Kategori::setAd(const std::string& yeniAd) { ad = yeniAd; }