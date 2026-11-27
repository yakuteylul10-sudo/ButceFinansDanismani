#include "model/FinansalIslem.h"

FinansalIslem::FinansalIslem(int id, double tutar, const std::string& tarih,
                             const std::string& kategoriAdi, const std::string& aciklama)
    : id(id), tutar(tutar), tarih(tarih), kategoriAdi(kategoriAdi), aciklama(aciklama) {}

int FinansalIslem::getId() const { return id; }
double FinansalIslem::getTutar() const { return tutar; }
std::string FinansalIslem::getTarih() const { return tarih; }
std::string FinansalIslem::getKategoriAdi() const { return kategoriAdi; }
std::string FinansalIslem::getAciklama() const { return aciklama; }

void FinansalIslem::setTutar(double yeniTutar) { tutar = yeniTutar; }
void FinansalIslem::setTarih(const std::string& yeniTarih) { tarih = yeniTarih; }
void FinansalIslem::setKategoriAdi(const std::string& yeniKategori) { kategoriAdi = yeniKategori; }
void FinansalIslem::setAciklama(const std::string& yeniAciklama) { aciklama = yeniAciklama; }