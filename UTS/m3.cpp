#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Deklarasi array 3 dimensi: [lapis][baris][kolom]
    int arr[2][3][4];

    int angka1 = 1;
    int angka5 = 5;

    for (int i = 0; i < 2; i++) {          // lapis (3 lapis)
        for (int j = 0; j < 3; j++) {      // baris (3 baris)
            for (int k = 0; k < 4; k++) {  // kolom (4 kolom)
                arr[i][j][k] = angka1;
                angka1 += 2;    
            }
        }
    }

    // Menampilkan array sebagai 2 lapis tabel berukuran 3x4
    for (int i = 0; i < 2; i++) {
        cout << "Lapis " << i + 1 << " (tabel 3x4):" << endl;
        cout << "+----+----+----+----+" << endl;
        for (int j = 0; j < 3; j++) {
            cout << "|";
            for (int k = 0; k < 4; k++) {
                arr[i][j][k] = angka1;
                angka5 += 5;    
                cout << setw(3) << arr[i][j][k] << " |";
            }
            cout << endl;
            cout << "+----+----+----+----+" << endl;
        }
        cout << endl;
    }

    return 0;
}