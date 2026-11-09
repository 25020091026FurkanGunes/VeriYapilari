#include <iostream>

struct Musteri {
    int id;
    int gelisZamani;
    int islemSuresi;
};

// Sıfırdan Dizi Tabanlı Kuyruk Yapısı (STL olmadan)
class OzelKuyrukMusteri {
private:
    Musteri dizi[100];
    int bas;
    int son;
    int elemanSayisi;

public:
    OzelKuyrukMusteri() {
        bas = 0;
        son = -1;
        elemanSayisi = 0;
    }

    bool bosMu() {
        return elemanSayisi == 0;
    }

    // Push (Ekleme) - O(1)
    void push(Musteri m) {
        if (elemanSayisi < 100) {
            son = (son + 1) % 100;
            dizi[son] = m;
            elemanSayisi++;
        }
    }

    // Pop (Çıkarma) - O(1)
    void pop() {
        if (!bosMu()) {
            bas = (bas + 1) % 100;
            elemanSayisi--;
        }
    }

    // Front (İlk Elemanı Okuma) - O(1)
    Musteri front() {
        return dizi[bas];
    }

    int size() {
        return elemanSayisi;
    }
};

int main() {
    OzelKuyrukMusteri bankaKuyrugu;

    // Müşterileri ekle[cite: 34]
    bankaKuyrugu.push({1, 0, 5}); // ID: 1, Gelis: 0. dk, Islem: 5 dk
    bankaKuyrugu.push({2, 2, 3}); // ID: 2, Gelis: 2. dk, Islem: 3 dk
    bankaKuyrugu.push({3, 4, 4}); // ID: 3, Gelis: 4. dk, Islem: 4 dk

    int mevcutZaman = 0;
    double toplamBeklemeSuresi = 0;
    int toplamMusteri = bankaKuyrugu.size();

    while (!bankaKuyrugu.bosMu()) {
        Musteri m = bankaKuyrugu.front();
        bankaKuyrugu.pop();

        if (mevcutZaman < m.gelisZamani) {
            mevcutZaman = m.gelisZamani;
        }

        int beklemeSuresi = mevcutZaman - m.gelisZamani;
        toplamBeklemeSuresi += beklemeSuresi;

        std::cout << "Musteri " << m.id
                  << " -> Bekleme Suresi: " << beklemeSuresi << " dk, "
                  << "Islem Bitis: " << (mevcutZaman + m.islemSuresi) << ". dk\n";

        mevcutZaman += m.islemSuresi;
    }

    std::cout << "Ortalama Bekleme Suresi: "
              << (toplamBeklemeSuresi / toplamMusteri) << " dk\n";

    return 0;
}