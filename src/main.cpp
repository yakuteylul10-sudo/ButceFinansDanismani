#include "service/Kullanici.h"
#include "ui/KonsolArayuzu.h"

int main() {
    Kullanici aktifKullanici("Bireysel Kullanici");
    KonsolArayuzu arayuz(aktifKullanici);
    arayuz.calistir();
    return 0;
}