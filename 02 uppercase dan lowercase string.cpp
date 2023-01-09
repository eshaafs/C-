#include <iostream>
#include <string>

using namespace std;

int main(){
	string nama;
	cout << "Masukkan nama = ";
	cin >> nama;
	cout << "Huruf kecil = ";
	for (int i = 0; i < nama.length(); i++){
		cout << (char) tolower(nama[i]);
	}
	cout << endl << "Huruf besar = ";
	for (int i = 0; i < nama.length(); i++){
		cout << (char) toupper(nama[i]);
	}
	return 0;
}
