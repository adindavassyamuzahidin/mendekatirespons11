#include <iostream>
#include <algorithm>
using namespace std;

void selection_sort(int data[], int s) {
    int lok, i, j;
    for (i = 0; i < s - 1; i++) {
        lok = i;
        for (j = i + 1; j < s; j++) {
            if (data[j] < data[lok]) {
                lok = j;
            }
        }
        swap(data[i], data[lok]);
    }
}

int main() {
    int data[] = {5, 3, 8, 4, 2};
    int s = 5;

    selection_sort(data, s);

    cout << "Setelah diurutkan: ";
    for (int i = 0; i < s; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    system ("pause");
    return 0;
}
