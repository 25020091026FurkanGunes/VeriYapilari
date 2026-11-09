#include <iostream>
#include <queue> // Kütüphaneyi koda dahil etme

int main() {
    // Nesne oluşturma
    std::queue<int> myQueue;

    // Ekleme yapma: push(x)
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Veri okuma
    std::cout << "Ilk eleman (front): " << myQueue.front() << std::endl; // 10
    std::cout << "Son eleman (back): " << myQueue.back() << std::endl;   // 30

    // Silme yapma: pop()
    myQueue.pop(); // 10 elemanı çıkarılır (ilk giren ilk çıkar)

    std::cout << "Pop sonrası yeni ilk eleman: " << myQueue.front() << std::endl; // 20

    return 0;
}