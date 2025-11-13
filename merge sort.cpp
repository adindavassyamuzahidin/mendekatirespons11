#include <iostream>
using namespace std;

void array_merge(int data[], int first, int mid, int last) {
    int n1 = mid - first + 1;
    int n2 = last - mid;

    int tmp_left[n1], tmp_right[n2];

    // salin data ke array sementara
    for (int i = 0; i < n1; i++)
        tmp_left[i] = data[first + i];
    for (int i = 0; i < n2; i++)
        tmp_right[i] = data[mid + 1 + i];

    int i = 0; // indeks untuk tmp_left
    int j = 0; // indeks untuk tmp_right
    int k = first; // indeks untuk data[]

    // gabungkan kedua array sementara ke data[]
    while (i < n1 && j < n2) {
        if (tmp_left[i] <= tmp_right[j]) {
            data[k] = tmp_left[i];
            i++;
        } else {
            data[k] = tmp_right[j];
            j++;
        }
        k++;
    }

    // salin sisa elemen (jika ada)
    while (i < n1) {
        data[k] = tmp_left[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = tmp_right[j];
        j++;
        k++;
    }
}

void merge_sort(int data[], int first, int last) {
    if (first < last) {
        // indeks tengah larik
        int mid = (first + last) / 2;

        // urutkan sublarik kiri
        merge_sort(data, first, mid);
        // urutkan sublarik kanan
        merge_sort(data, mid + 1, last);

        // gabungkan sublarik kiri dan kanan
        array_merge(data, first, mid, last);
    }
}

int main() {
    int data[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Data sebelum diurutkan: ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << endl;

    merge_sort(data, 0, n - 1);

    cout << "Data setelah diurutkan: ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << endl;
    system ("pause");
    return 0;
}
