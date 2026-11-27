#ifndef GELIR_H
#define GELIR_H

#include "model/FinansalIslem.h"

class Gelir : public FinansalIslem {
private:
    std::string gelirKaynagi;

public:
    Gelir(int id, double tutar, const std::string& tarih,
          const std::string& kategoriAdi, const std::string& aciklama,
          const std::string& gelirKaynagi);

    std::string getGelirKaynagi() const;
    void setGelirKaynagi(const std::string& kaynak);

    std::string getTur() const override;
    void bilgiYazdir() const override;
};

#endif