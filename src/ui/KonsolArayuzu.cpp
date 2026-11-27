#include "ui/KonsolArayuzu.h"
#include <iostream>
#include <limits>
#include <string>

KonsolArayuzu::KonsolArayuzu(Kullanici& kullanici) : kullanici(kullanici) {}

void KonsolArayuzu::tamponTemizle() const {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void KonsolArayuzu::menuyuYazdir() const {
    std::cout << "\n=============================================\n";
    std::cout << "     BUTCE VE FINANS DANISMANI (PROTOTIP)    \n";
    std::cout << "=============================================\n";
    std::cout << "1. Gelir Ekle\n";
    std::cout << "2. Gider Ekle\n";
    std::cout << "3. Genel Finansal Durum Ozeti\n";
    std::cout << "4. Kayitli Islemleri Listele\n";
    std::cout << "5. Islem Guncelle / Sil [IP5]\n";
    std::cout << "6. Aylik Butce Hedefi Belirle [IP5]\n";
    std::cout << "7. Kategori Bazli Harcama Analizi [IP5]\n";
    std::cout << "8. Verileri Dosyaya Kaydet (CSV) [IP5]\n";
    std::cout << "0. Cikis\n";
    std::cout << "Seciminiz: ";
}

void KonsolArayuzu::gelirEkleEkrani() {
    double tutar = 0.0;
    std::string tarih, kategori, kaynak, aciklama;

    std::cout << "\n--- YENI GELIR EKLE ---\n";
    std::cout << "Tutar (TL): ";
    if (!(std::cin >> tutar) || tutar <= 0.0) {
        tamponTemizle();
        std::cout << "[Hata] Gecersiz tutar girdiniz!\n";
        return;
    }
    tamponTemizle();

    std::cout << "Tarih (GG.AA.YYYY): ";
    std::getline(std::cin, tarih);

    std::cout << "Kategori (orn. Maas / Burs, Ek Gelir): ";
    std::getline(std::cin, kategori);

    std::cout << "Gelir Kaynagi: ";
    std::getline(std::cin, kaynak);

    std::cout << "Aciklama: ";
    std::getline(std::cin, aciklama);

    kullanici.gelirEkle(tutar, tarih, kategori, aciklama, kaynak);
    std::cout << "[Bilgi] Gelir kaydi basariyla eklendi.\n";
}

void KonsolArayuzu::giderEkleEkrani() {
    double tutar = 0.0;
    std::string tarih, kategori, odemeYontemi, aciklama;

    std::cout << "\n--- YENI GIDER EKLE ---\n";
    std::cout << "Tutar (TL): ";
    if (!(std::cin >> tutar) || tutar <= 0.0) {
        tamponTemizle();
        std::cout << "[Hata] Gecersiz tutar girdiniz!\n";
        return;
    }
    tamponTemizle();

    std::cout << "Tarih (GG.AA.YYYY): ";
    std::getline(std::cin, tarih);

    std::cout << "Kategori (orn. Gida, Ulasim, Kira / Fatura): ";
    std::getline(std::cin, kategori);

    std::cout << "Odeme Yontemi (Nakit / Kart): ";
    std::getline(std::cin, odemeYontemi);

    std::cout << "Aciklama: ";
    std::getline(std::cin, aciklama);

    kullanici.giderEkle(tutar, tarih, kategori, aciklama, odemeYontemi);
    std::cout << "[Bilgi] Gider kaydi basariyla eklendi.\n";
}

void KonsolArayuzu::calistir() {
    int secim = -1;
    while (secim != 0) {
        menuyuYazdir();
        if (!(std::cin >> secim)) {
            tamponTemizle();
            std::cout << "[Hata] Lutfen gecerli bir menu numarasi giriniz.\n";
            continue;
        }
        tamponTemizle();

        switch (secim) {
            case 1:
                gelirEkleEkrani();
                break;
            case 2:
                giderEkleEkrani();
                break;
            case 3:
                kullanici.finansalOzetGoster();
                break;
            case 4:
                kullanici.islemleriListele();
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                std::cout << "[Bilgi] Bu modul IP5 is paketi kapsaminda (9-12. haftalar) gelistirilecektir.\n";
                break;
            case 0:
                std::cout << "Programdan cikiliyor. Bellek kaynaklari temizlendi.\n";
                break;
            default:
                std::cout << "[Uyari] Gecersiz secim yaptiniz.\n";
                break;
        }
    }
}