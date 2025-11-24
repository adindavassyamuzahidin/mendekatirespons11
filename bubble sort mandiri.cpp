//bubble sort caca
#include <iostream>
using namespace std;

void urutin(int data [], int n){
    for (int i = 0; i < n - 1; i++){
        bool tukar = false;
        for (int j = n - 1; j > i; j--){
            if (data [j] < data [j - 1]){
                int temp = data [j];
                data[j] = data[j - 1];
                data [j - 1] = temp;
                tukar = true;
            }
        }
        if (!tukar) break;
    }
}

int main (){
    int arr[] = {2, 43, 9, 0, 999};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "data awal : ";
    for (int i = 0; i < n; i++){
        cout << arr [i] << " ";
        cout << endl;
    }

    urutin (arr, n);

    cout << "data urut : ";
    for (int i = 0; i < n; i++){
        cout << arr [i] << " ";
        cout << endl;
    }
    system ("pause");
    
    return 0;

}
