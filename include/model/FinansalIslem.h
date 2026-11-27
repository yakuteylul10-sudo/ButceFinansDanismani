#ifndef FINANSAL_ISLEM_H
#define FINANSAL_ISLEM_H

#include <string>

class FinansalIslem {
protected:
    int id;
    double tutar;
    std::string tarih;
    std::string kategoriAdi;
    std::string aciklama;

public:
    FinansalIslem(int id, double tutar, const std::string& tarih,
                  const std::string& kategoriAdi, const std::string& aciklama);
    virtual ~FinansalIslem() = default;

    int getId() const;
    double getTutar() const;
    std::string getTarih() const;
    std::string getKategoriAdi() const;
    std::string getAciklama() const;

    void setTutar(double yeniTutar);
    void setTarih(const std::string& yeniTarih);
    void setKategoriAdi(const std::string& yeniKategori);
    void setAciklama(const std::string& yeniAciklama);

    virtual std::string getTur() const = 0;
    virtual void bilgiYazdir() const = 0;
};

#endif