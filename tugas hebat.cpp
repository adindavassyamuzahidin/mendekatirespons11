#include <iostream>
#include <cstdlib>  // untuk rand(), srand()
#include <ctime>    // untuk time()
using namespace std;

// =========================
// FUNGSI CETAK DATA
// =========================
void tampilData(int data[], int n) {
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << endl;
}

// =========================
// BUBBLE SORT
// =========================
void bubbleSort(int data[], int n) {
    cout << "\n=== Proses Bubble Sort ===\n";
    for (int i = 0; i < n - 1; i++) {
        bool tukar = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                tukar = true;
            }
        }
        cout << "Setelah putaran ke-" << i + 1 << ": ";
        tampilData(data, n);

        if (!tukar) break;
    }
}

// =========================
// SELECTION SORT
// =========================
void selectionSort(int data[], int n) {
    cout << "\n=== Proses Selection Sort ===\n";
    for (int i = 0; i < n - 1; i++) {
        int lok = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[lok]) {
                lok = j;
            }
        }
        swap(data[i], data[lok]);

        cout << "Setelah putaran ke-" << i + 1 << ": ";
        tampilData(data, n);
    }
}

// =========================
// INSERTION SORT
// =========================
void insertionSort(int data[], int n) {
    cout << "\n=== Proses Insertion Sort ===\n";
    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;

        cout << "Setelah putaran ke-" << i << ": ";
        tampilData(data, n);
    }
}

// =========================
// PROGRAM UTAMA
// =========================
int main() {
    int n, pilihan;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    int data[n];
    srand(time(0)); // inisialisasi bilangan acak

    // isi array dengan data acak 0–99
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 100;
    }

    cout << "\nData awal: ";
    tampilData(data, n);

    cout << "\nPilih algoritma pengurutan:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "Masukkan pilihan (1-3): ";
    cin >> pilihan;

    // salin array agar data asli tidak berubah
    int dataUrut[n];
    for (int i = 0; i < n; i++) dataUrut[i] = data[i];

    switch (pilihan) {
        case 1:
            bubbleSort(dataUrut, n);
            break;
        case 2:
            selectionSort(dataUrut, n);
            break;
        case 3:
            insertionSort(dataUrut, n);
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            return 0;
    }

    cout << "\nData setelah diurutkan: ";
    tampilData(dataUrut, n);

    system("pause");
    return 0;
}
