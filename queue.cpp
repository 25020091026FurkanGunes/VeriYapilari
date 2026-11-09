#include <iostream>
using namespace std;

#define KAPASITE 5

class Queue {
private:
    int dizi[KAPASITE];
    int bas;          // Kuyruğun başındaki elemanın indeksi (front)
    int son;          // Kuyruğun sonundaki elemanın indeksi (rear)
    int elemanSayisi; // Kuyruktaki mevcut eleman sayısı

public:
    Queue() {
        bas = 0;
        son = -1;
        elemanSayisi = 0;
    }

    // Kuyruğun boş olup olmadığını kontrol eder
    bool bosMu() {
        return elemanSayisi == 0;
    }

    // Kuyruğun dolu olup olmadığını kontrol eder
    bool doluMu() {
        return elemanSayisi == KAPASITE;
    }

    // Kuyruğa eleman ekleme (Enqueue) - O(1)
    void enqueue(int eleman) {
        if (doluMu()) {
            cout << "Kuyruk Dolu! (" << eleman << " eklenemedi)\n";
            return;
        }
        // Döngüsel indeks güncellemesi (Dizinin sonuna gelince başa döner)
        son = (son + 1) % KAPASITE;
        dizi[son] = eleman;
        elemanSayisi++;
        cout << eleman << " kuyruğa eklendi.\n";
    }

    // Kuyruktan eleman çıkarma (Dequeue) - O(1)
    void dequeue() {
        if (bosMu()) {
            cout << "Kuyruk Boş! Çıkarılacak eleman yok.\n";
            return;
        }
        cout << dizi[bas] << " kuyruktan çıkarıldı.\n";
        bas = (bas + 1) % KAPASITE;
        elemanSayisi--;
    }

    // En baştaki elemanı görme (Front/Peek) - O(1)
    int getFront() {
        if (bosMu()) {
            cout << "Kuyruk Boş!\n";
            return -1;
        }
        return dizi[bas];
    }
};

int main() {
    Queue q;

    // Eleman ekleme işlemleri
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // En baştaki elemanı görme
    cout << "Kuyruğun başındaki eleman: " << q.getFront() << endl; // 10

    // Eleman çıkarma işlemleri (İlk giren ilk çıkar)
    q.dequeue(); // 10 çıkar
    cout << "Yeni baştaki eleman: " << q.getFront() << endl; // 20

    q.dequeue(); // 20 çıkar

    return 0;
}