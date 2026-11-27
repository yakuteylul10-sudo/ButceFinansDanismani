#ifndef KATEGORI_H
#define KATEGORI_H

#include <string>

class Kategori {
private:
    int id;
    std::string ad;
    std::string tur;

public:
    Kategori(int id, const std::string& ad, const std::string& tur);

    int getId() const;
    std::string getAd() const;
    std::string getTur() const;

    void setAd(const std::string& yeniAd);
};

#endif