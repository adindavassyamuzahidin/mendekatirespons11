/*
Diberikan sebuah array A dengan ukuran N. Tugas Anda adalah mengurutkan array A secara
menurun (descending).
Input:
Baris pertama memuat satu buah bilangan bulat N dengan 1 = N = 1000
Baris berikutnya terdiri atas N buah bilangan bulat Ai dengan 0 = A I = 1000
Output:
Outputkan array A yang telah terurut sesuai ketentuan. Pisahkan setiap bilangan dengan koma.
Tidak ada tambahan koma setelah bilangan terakhir.
*/
#include <iostream>

using namespace std;


void urutin(int data[], int n){
	for (int i = 0; i < n-1 ; i++){
		bool tukar = false;
		for (int j = n-1; j > i ; j--){
			if (data[j] < data[j-1]){
				int temp = data [j];
				data[j] = data[j-1];
				data [j-1] = temp;
				tukar = true;
			}
		}
		if (!tukar) break;
	}
}

int main (){
	const int max = 100;
	int data [max];
	int n = sizeof(data)/sizeof(data[0]);
	
	cout << "masukin jumlah data : ";
	cin >> n;
	cout << endl;
	
	cout << "masukin data : ";
	for (int i = 0; i < n; i++){
		cin >> data [i];
	}
	cout << endl;
	
	cout << "enter untuk melanjutkan...." << endl;
	system ("pause");
	
	cout << "jumlah data : " << n << endl;
	cout << "data yang kamu masukkan : ";
	cout << endl;
	for (int i = 0; i < n; i++){
		cout << data [i];
		for (int j = 0; j < n-i-1; j++){
			cout << ",";
		}
	cout << endl;
	urutin(data, n);
	cout << "data yang sudah diurutkan : ";
	cout << endl;
	for (int i = 0; i < n; i++){
		cout << data [i];
		for (int j = 0; j < n-i-1; j++){
			cout << ",";
		}
	
	cout << endl;
} 
