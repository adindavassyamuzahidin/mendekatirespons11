#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
using namespace std;

// =========================
// Utility tampil array
// =========================
template <typename T>
void tampil(const vector<T>& data) {
    for (auto& d : data) cout << d << " ";
    cout << endl;
}

// =========================
// Bubble Sort
// =========================
template <typename T>
void bubbleSort(vector<T>& data, bool ascending, int& iter, int& swapCount) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            iter++;
            bool kondisi = ascending ? (data[j] > data[j + 1]) : (data[j] < data[j + 1]);
            if (kondisi) {
                swap(data[j], data[j + 1]);
                swapCount++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// =========================
// Selection Sort
// =========================
template <typename T>
void selectionSort(vector<T>& data, bool ascending, int& iter, int& swapCount) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            iter++;
            bool kondisi = ascending ? (data[j] < data[idx]) : (data[j] > data[idx]);
            if (kondisi)
                idx = j;
        }
        if (idx != i) {
            swap(data[i], data[idx]);
            swapCount++;
        }
    }
}

// =========================
// Insertion Sort
// =========================
template <typename T>
void insertionSort(vector<T>& data, bool ascending, int& iter, int& swapCount) {
    int n = data.size();
    for (int i = 1; i < n; i++) {
        T key = data[i];
        int j = i - 1;
        while (j >= 0 && (ascending ? (data[j] > key) : (data[j] < key))) {
            iter++;
            data[j + 1] = data[j];
            j--;
            swapCount++;
        }
        data[j + 1] = key;
    }
}

// =========================
// Merge Sort
// =========================
template <typename T>
void merge(vector<T>& data, int left, int mid, int right, bool ascending, int& iter) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<T> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = data[left + i];
    for (int j = 0; j < n2; j++) R[j] = data[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        iter++;
        bool kondisi = ascending ? (L[i] <= R[j]) : (L[i] >= R[j]);
        if (kondisi)
            data[k++] = L[i++];
        else
            data[k++] = R[j++];
    }
    while (i < n1) data[k++] = L[i++];
    while (j < n2) data[k++] = R[j++];
}

template <typename T>
void mergeSort(vector<T>& data, int left, int right, bool ascending, int& iter) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(data, left, mid, ascending, iter);
        mergeSort(data, mid + 1, right, ascending, iter);
        merge(data, left, mid, right, ascending, iter);
    }
}

// =========================
// Main Program
// =========================
int main() {
    srand(time(0));
    int n, modeData, algoritma;
    bool ascending = true;
    char tipe, urutan;

    cout << "=== PROGRAM EKSPERIMEN PENGURUTAN ===\n";
    cout << "Pilih tipe data (i = integer, s = string): ";
    cin >> tipe;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    cout << "Pilih cara isi data:\n1. Manual\n2. Acak (hanya untuk integer)\nPilihan: ";
    cin >> modeData;

    vector<int> dataInt;
    vector<string> dataStr;

    if (tipe == 'i') {
        if (modeData == 1) {
            cout << "Masukkan " << n << " data integer: ";
            for (int i = 0; i < n; i++) {
                int x; cin >> x;
                dataInt.push_back(x);
            }
        } else {
            for (int i = 0; i < n; i++)
                dataInt.push_back(rand() % 100);
            cout << "Data acak: ";
            tampil(dataInt);
        }
    } else {
        cout << "Masukkan " << n << " kata/string: ";
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            dataStr.push_back(s);
        }
    }

    cout << "\nUrutan pengurutan (a = ascending, d = descending): ";
    cin >> urutan;
    ascending = (urutan == 'a');

    cout << "\nPilih algoritma:\n";
    cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n";
    cout << "Pilihan: ";
    cin >> algoritma;

    int iter = 0, swapCount = 0;

    cout << "\nData awal: ";
    if (tipe == 'i') tampil(dataInt); else tampil(dataStr);

    if (tipe == 'i') {
        switch (algoritma) {
            case 1: bubbleSort(dataInt, ascending, iter, swapCount); break;
            case 2: selectionSort(dataInt, ascending, iter, swapCount); break;
            case 3: insertionSort(dataInt, ascending, iter, swapCount); break;
            case 4: mergeSort(dataInt, 0, n - 1, ascending, iter); break;
        }
        cout << "Data terurut: "; tampil(dataInt);
    } else {
        switch (algoritma) {
            case 1: bubbleSort(dataStr, ascending, iter, swapCount); break;
            case 2: selectionSort(dataStr, ascending, iter, swapCount); break;
            case 3: insertionSort(dataStr, ascending, iter, swapCount); break;
            case 4: mergeSort(dataStr, 0, n - 1, ascending, iter); break;
        }
        cout << "Data terurut: "; tampil(dataStr);
    }

    cout << "\nJumlah iterasi: " << iter << endl;
    cout << "Jumlah pertukaran: " << swapCount << endl;

    system ("pause");
    return 0;
}
