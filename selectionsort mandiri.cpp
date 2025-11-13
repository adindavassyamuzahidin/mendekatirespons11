//selection sort caca
#include <iostream>
#include <algorithm>
using namespace std;

void sss(int data[], int n){
    int x, i, j;
    for (int i = 0; i < n - 1; i++){
        x = i;
        for (j = i + 1; j < n; j++){
            if (data[j] < data[x]) {
                x = j;
            }
        }
        swap(data[i], data[x]);
    }
}

int main (){
    int data [] = {5, 3, 43, 3, 0};
    int n = 5;

    cout << "data sebelum diurutkan : ";
    for (int i = 0; i < n; i++){
        cout << data [i] << " ";
    }

    sss(data, n);
    cout << "data setelah diurutkan : ";
    for (int i = 0; i < n; i++){
        cout << data [i] << " ";
    }

    cout << endl;
    system ("pause");
    return 0;

}