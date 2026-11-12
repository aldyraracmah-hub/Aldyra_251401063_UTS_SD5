#include <iostream>
#include <string>
using namespace std;

// Node linked list untuk data pendaftar
struct Node {
    string nama;
    int harga;
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

void tampil(string nama, int harga) {
    cout << "\nIsi Nama: ";
    cout << "\nIsi Harga: ";
    if (head == NULL) {
        cout << "(kosong)" << endl;
        return;
    }
    Node* bantu = head;
    while (bantu != NULL) {
        cout << bantu->nilai;
        if (bantu->next != NULL) cout << " -> ";
        bantu = bantu->next;
    }
    cout << " -> NULL" << endl;
}

// Tampilkan hanya barang yang harganya lebih dr 100.000
void tampilHarga(Node* head) {
    int no = 1;
    bool ada = false;

    cout << "\nBarang yang lolos (harga >= 100000)" << endl;
    for (Node* p = head; p != NULL; p = p->next) {
        if (p->harga >= 100000) {
            cout << no++ << ". " << p->nama << " - Harga: " << p->harga << endl;
            ada = true;
        }
    }
    if (!ada) cout << "Tidak ada harga yang lebih dari RP100.000." << endl;

}

// Tambah node di akhir
void tambahAkhir(Node*& head, string nama, int harga) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->harga = harga;
    baru->next = NULL;
    if (head == NULL) {          // list kosong
        head = baru;
    } else {
        Node* bantu = head;
        while (bantu->next != NULL)   // cari tail
            bantu = bantu->next;
        bantu->next = baru;
    }
    cout << "Nama : " << nama << "\nHarga : " << harga << " ditambahkan di akhir." << endl;
}

//1. Delete Fisrt
void deleteFirst(Node*& head) {
    if(head == NULL) {
        cout << "Barang Kosong!" << endl;
        return;
    }

    node *bantu = head;
    head = head -> next;
    if (head == NULL) tail = NULL;
    delete bantu;
}

//2. Delete Last
void deleteLast(Node*& head) {
    if (head == NULL) {
        cout << "Barang kosong!" << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    node *p = head;
    while (p -> next != tail) {
        p = p -> next;
    }

    delete tail;
    tail = p;
    tail -> next = NULL;
}

void hapusSemua(Node*& head) {
    while (head != NULL) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }
}

int main() {
    int pilihan, nama, harga, target;

    do {
        cout << "1. Tambah di akhir" << endl;
        cout << "2. Hapus di awal" << endl;
        cout << "3. Hapus di akhir" << endl;
        cout << "4. Tampilkan Barang Mewah" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                tambahAkhir(nama, harga);
                tampil();
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahAkhir(nilai);
                tampil();
                break;
            case 3:
                cout << "Tambah setelah nilai: ";
                cin >> target;
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                tambahSetelah(target, nilai);
                tampil();
                break;
            case 4:
                cout << "Masukkan nilai yang dihapus: ";
                cin >> nilai;
                hapus(nilai);
                tampil();
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    // Bebaskan memori
    while (head != NULL) {
        Node* hapusNode = head;
        head = head->next;
        delete hapusNode;
    }
    return 0;
}
    Node* head = NULL;
    int n, harga;
    string nama;

    cout << "List belanja: ";
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