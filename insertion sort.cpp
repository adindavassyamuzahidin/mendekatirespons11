#include <iostream>
using namespace std;

void insertion_sort(int data[], int s) {
    int key, j;
    for (int i = 1; i < s; i++) {
        key = data[i];
        j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

int main() {
    int data[] = {5, 3, 8, 4, 2};
    int s = 5;

    insertion_sort(data, s);

    cout << "Setelah diurutkan: ";
    for (int i = 0; i < s; i++) cout << data[i] << " ";
    cout << endl;
    system ("pause");
    return 0;
}
