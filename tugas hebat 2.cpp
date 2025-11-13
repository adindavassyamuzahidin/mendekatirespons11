#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
using namespace std;

// =====================
// Fungsi Cetak Array
// =====================
void tampil(int data[], int n) {
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;
}

// =====================
// Bubble Sort
// =====================
void bubble_sort(int data[], int n) {
    cout << "\n=== Proses Bubble Sort ===" << endl;
    for (int i = 0; i < n - 1; i++) {
        bool tukar = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                tukar = true;
            }
        }
        cout << "Setelah iterasi ke-" << i + 1 << ": ";
        tampil(data, n);
        if (!tukar) break;
    }
}

// =====================
// Insertion Sort
// =====================
void insertion_sort(int data[], int n) {
    cout << "\n=== Proses Insertion Sort ===" << endl;
    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;

        cout << "Setelah iterasi ke-" << i << ": ";
        tampil(data, n);
    }
}

// =====================
// Fungsi Utama (Main)
// =====================
int main() {
    int n, pilihan, tipe_data;

    cout << "=== Program Eksperimen Pengurutan ===\n";
    cout << "Masukkan jumlah data: ";
    cin >> n;

    int data[n];

    cout << "\nPilih cara inisialisasi data:\n";
    cout << "1. Input manual\n";
    cout << "2. Acak dengan rand()\n";
    cout << "Pilihan: ";
    cin >> tipe_data;

    if (tipe_data == 1) {
        cout << "Masukkan " << n << " data: ";
        for (int i = 0; i < n; i++)
            cin >> data[i];
    } else {
        srand(time(0)); // seed acak
        for (int i = 0; i < n; i++)
            data[i] = rand() % 100; // data acak 0–99
        cout << "Data acak yang dihasilkan: ";
        tampil(data, n);
    }

    cout << "\nPilih algoritma pengurutan:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "Pilihan: ";
    cin >> pilihan;

    cout << "\nData awal: ";
    tampil(data, n);

    if (pilihan == 1)
        bubble_sort(data, n);
    else if (pilihan == 2)
        insertion_sort(data, n);
    else
        cout << "Pilihan tidak valid!\n";

    cout << "\nHasil akhir (data terurut): ";
    tampil(data, n);

    return 0;
}
