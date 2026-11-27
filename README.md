# Bütçe ve Finans Danışmanı (C++ / OOP)

Bireysel kullanıcıların gelir-gider hareketlerini takip edebilmeleri, harcamalarını kategorize edebilmeleri ve aylık bütçe hedefleri belirleyebilmeleri için C++ ve Nesne Yönelimli Programlama (OOP) prensipleriyle geliştirilen konsol tabanlı finans takip uygulamasıdır.

## Katmanlı Mimari
- **Model (`include/model`, `src/model`):** `FinansalIslem` (soyut temel sınıf), `Gelir`, `Gider`, `Kategori`, `Butce`
- **Service (`include/service`, `src/service`):** `Kullanici`
- **UI (`include/ui`, `src/ui`):** `KonsolArayuzu`

## Derleme ve Çalıştırma
```bash
g++ -std=c++17 -Wall -Iinclude src/model/*.cpp src/service/*.cpp src/ui/*.cpp src/main.cpp -o butce_danismani.exe
./butce_danismani.exe