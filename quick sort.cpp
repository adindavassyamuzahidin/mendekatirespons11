#include <iostream>
using namespace std;

void quick_sort(int data[], int first, int last) {
    int a = first, b = last;
    int pivot;

    // tentukan pivot: elemen di tengah larik
    pivot = data[(first + last) / 2];

    // atur sublarik kiri dan kanan supaya nilainya
    // kurang untuk sublarik kiri dan lebih atau sama untuk sublarik kanan dari pivot
    do {
        // cari elemen di sisi kiri pivot yang lebih dari pivot
        while (data[a] < pivot) a++;
        // cari elemen di sisi kanan pivot yang kurang dari pivot
        while (data[b] > pivot) b--;

        // tukar posisi supaya posisi data[a] dan data[b] benar: data[a] < pivot < data[b]
        if (a <= b) {
            swap(data[a], data[b]);
            a++;
            b--;
        }
    } while (a <= b); // pakai <= supaya tidak infinite loop

    // urutkan sublarik kiri d
