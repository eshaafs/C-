#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Pelanggan {
	private:
		static int totalPelanggan;
		static float totalTerutang;
		unsigned int noPelanggan, penggunaanAir;
		float jumlahTagihan;
		string nama, alamat;
		
		void kalkulasi(int penggunaanAir){
			if (this->penggunaanAir <= 60){
				this->jumlahTagihan = this->penggunaanAir * 2;
			} else if (this->penggunaanAir > 60) {
				this->jumlahTagihan = (60 * 1.75) + ((this->penggunaanAir-60) * 1.5);
			}
			totalTerutang += this->jumlahTagihan;
		}
	
	public:
		Pelanggan (ifstream& dataPelanggan){
			string no, penggunaan;
			getline(dataPelanggan, no);
			getline(dataPelanggan, this->nama);
			getline(dataPelanggan, this->alamat);
			getline(dataPelanggan, penggunaan);
			// convert string to int
			stringstream obj;  
    		obj << penggunaan; 
     		obj >> this->penggunaanAir;  
     		stringstream obj2;  
    		obj2 << no; 
     		obj2 >> this->noPelanggan;
     		totalPelanggan++;
		}
		
		void display(){
			cout << "No. \t\t: " << this->noPelanggan << endl;
			cout << "Nama \t\t: " << this->nama << endl;
			cout << "Alamat \t\t: " << this->alamat << endl;
			cout << "Pengunaan Air \t: " << this->penggunaanAir << "m2" << endl;
			kalkulasi(this->penggunaanAir);
			cout << "Jumlah Tagihan \t: $" << this->jumlahTagihan << endl;
			cout << "\n---------------------------------------------------------------" << endl;
			cout << "\nTotal Pelanggan \t\t: " << totalPelanggan << endl;
			cout << "Total Terutang ke Perusahaan \t: $" << totalTerutang << endl;
		}
};

int Pelanggan::totalPelanggan = 0;
float Pelanggan::totalTerutang = 0;

int main(){
	ifstream dataPelanggan1("Data Pelanggan 1.txt");
	ifstream dataPelanggan2("Data Pelanggan 2.txt");
	ifstream dataPelanggan3("Data Pelanggan 3.txt");
	Pelanggan pelanggan1(dataPelanggan1);
	pelanggan1.display();
	cout << "\n";
	Pelanggan pelanggan2(dataPelanggan2);
	pelanggan2.display();
	cout << "\n";
	Pelanggan pelanggan3(dataPelanggan3);
	pelanggan3.display();
	return 0;
}
