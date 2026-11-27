#ifndef GIDER_H
#define GIDER_H

#include "model/FinansalIslem.h"

class Gider : public FinansalIslem {
private:
    std::string odemeYontemi;

public:
    Gider(int id, double tutar, const std::string& tarih,
          const std::string& kategoriAdi, const std::string& aciklama,
          const std::string& odemeYontemi);

    std::string getOdemeYontemi() const;
    void setOdemeYontemi(const std::string& yontem);

    std::string getTur() const override;
    void bilgiYazdir() const override;
};

#endif