#include <iostream>
#include <vector>

using namespace std;

// İkili Arama (Binary Search) Algoritması - O(log n)
bool ikiliArama(const vector<int>& A, int arananDeger) {
    int sol = 0;
    int sag = A.size() - 1;

    while (sol <= sag) {
        int orta = sol + (sag - sol) / 2; // (sol + sag) / 2 ile aynıdır

        if (A[orta] == arananDeger) {
            return true; // Bulundu
        }
        else if (A[orta] < arananDeger) {
            sol = orta + 1; // Sağ yarıda ara
        }
        else {
            sag = orta - 1; // Sol yarıda ara
        }
    }

    return false; // Bulunamadı
}

int main() {
    // Sıralı dizi
    vector<int> dizi = {3, 7, 12, 19, 25, 31, 42, 58, 64, 77};

    int aranan1 = 25;
    int aranan2 = 50;

    cout << aranan1 << " dizide var mı? "
         << (ikiliArama(dizi, aranan1) ? "Evet (true)" : "Hayır (false)") << endl;

    cout << aranan2 << " dizide var mı? "
         << (ikiliArama(dizi, aranan2) ? "Evet (true)" : "Hayır (false)") << endl;

    return 0;
}