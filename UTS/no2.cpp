#include <iostream>
#include <string>
using namespace std;

// Node linked list untuk data pendaftar
struct Node {
    string nama;
    int skor;
    Node* next;
};

// Insert di belakang (akhir list)
void insert(Node*& head, string nama, int harga) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->harga = harga;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

// Tampilkan hanya pendaftar yang lolos (skor >= 75)
void tampilHarga(Node* head, string nama, int harga) {
    int no = 1;
    bool ada = false;

    cout << "\n Barang Lolos (harga >= 100000) " << endl;
    for (Node* p = head; p != NULL; p = p->next) {
        if (p->harga >= 100000) {
            cout << no++ << ". " << p->nama << "Harga: " << p->harga << endl;
            ada = true;
        }
    }
    if (!ada) cout << "Tidak ada barang yang lebih dari 100.000" << endl;
}

void hapusSemua(Node*& head) {
    while (head != NULL) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }
}

int main() {
    Node* head = NULL;
    int n, harga;
    string nama;

    cout << "Jumlah barang: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "\nBarang ke-" << i << endl;
        cout << "Nama : ";
        cin >> nama;
        cout << "Harga : ";
        cin >> harga;
        insert(head, nama, harga);
    }

    tampilHarga(head);
    hapusSemua(head);
    return 0;
}