#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

// Base class
class Barang{
	protected:
		string idBarang;
		string namaBarang;
		unsigned long hargaBarang;
		int stokBarang;
	
	public:
		virtual string getJenisBarang() = 0;
		
		string getIdBarang(){
			return this->idBarang;
		}
		
		string getNamaBarang(){
			return this->namaBarang;
		}
		
		unsigned long getHargaBarang(){
			return this->hargaBarang;
		}
		
		int getStokBarang(){
			return this->stokBarang;
		}
		
		void setIdBarang(string newId){
			this->idBarang = newId;
		}
		
		void setNamaBarang(string newNamaBarang){
			this->namaBarang = newNamaBarang;
		}
		
		void setHargaBarang(unsigned long newHargaBarang){
			this->hargaBarang = newHargaBarang;
		}
		
		void setStokBarang(int newStokBarang){
			this->stokBarang = newStokBarang;
		}
		
		void reduceStokBarang(int reduceStok){
			this->stokBarang -= reduceStok;
		}
};

// Derived class
class BarangNonElectronic : public Barang{
	private:
		string jenisBarang = "Non Electronic";
	
	public:
		string getJenisBarang(){
			return this->jenisBarang;
		}
};

// Derived class
class BarangElectronic : public Barang{
	private:
		string jenisBarang = "Electronic";
		unsigned long biayaPemasangan = 300000;
	
	public:
		string getJenisBarang(){
			return this->jenisBarang;
		}
		
		unsigned long getBiayaPemasangan(){
			return this->biayaPemasangan;
		}
		
		void setBiayaPemasangan(unsigned long biayaPemasangan){
			this->biayaPemasangan = biayaPemasangan;
		}
		
};

// Derived class
class BarangDigital : public Barang{
	private:
		string jenisBarang = "Digital";
	
	public:
		string getJenisBarang(){
			return this->jenisBarang;
		}
};


class Order{
	private:
		string idBarangDiOrder;
		int jumlahOrderan = 0;
	
	public:
		void setIdBarangDiOrder(string idBarang){
			this->idBarangDiOrder = idBarang;
		}
		
		void setJumlahOrderan(int newJumlahOrderan){
			this->jumlahOrderan = newJumlahOrderan;
		}
		
		string getIdBarang(){
			return this->idBarangDiOrder;
		}
		
		int getJumlahOrderan(){
			return this->jumlahOrderan;
		}
};

// Class utama atau wrapper class
class Store{
	private:
		// Item related attributes
		BarangNonElectronic myBarangNonElectronic[20];
		BarangElectronic myBarangElectronic[20];
		BarangDigital myBarangDigital[20];
		static int counterBNE, counterBE, counterBD;
		
		// Order related attributes
		char namaPelanggan[50];
		int jarakPengiriman = 0;
		Order myOrder[20];
		
	public:
		// Function Overloading
		// Calc biaya untuk barang non electronic
		unsigned long calcBiaya(unsigned long harga, int jarakPengiriman){
			return harga + (jarakPengiriman*2000); 
		}
			
		// Calc biaya untuk barang electronic
		unsigned long calcBiaya(unsigned long harga, int jarakPengiriman, unsigned long biayaPemasangan){
			return harga + (jarakPengiriman*2000) + biayaPemasangan;
		}
		
		// Function Overloading
		// Membuat item baru untuk setiap jenis - tanpa mengatur biaya pemasangan untuk object barang electronic, default value 300.000.
		void setNewItem(string jenisBarang, string newNamaBarang, unsigned long newHargaBarang, int jumlahBarang){
			if(jenisBarang == "Non Electronic"){
				stringstream stream;
				stream << counterBNE;
				string str1;
				stream >> str1;
				myBarangNonElectronic[counterBNE].setIdBarang("BNE"+str1);
				myBarangNonElectronic[counterBNE].setNamaBarang(newNamaBarang);
				myBarangNonElectronic[counterBNE].setHargaBarang(newHargaBarang);
				myBarangNonElectronic[counterBNE].setStokBarang(jumlahBarang);
				counterBNE++;
			} else if(jenisBarang == "Electronic"){
				stringstream stream;
				stream << counterBE;
				string str1;
				stream >> str1;
				myBarangElectronic[counterBE].setIdBarang("BEL"+str1);
				myBarangElectronic[counterBE].setNamaBarang(newNamaBarang);
				myBarangElectronic[counterBE].setHargaBarang(newHargaBarang);
				myBarangElectronic[counterBE].setStokBarang(jumlahBarang);
				counterBE++;
			} else if(jenisBarang == "Digital"){
				stringstream stream;
				stream << counterBD;
				string str1;
				stream >> str1;
				myBarangDigital[counterBD].setIdBarang("BDI"+str1);
				myBarangDigital[counterBD].setNamaBarang(newNamaBarang);
				myBarangDigital[counterBD].setHargaBarang(newHargaBarang);
				myBarangDigital[counterBD].setStokBarang(jumlahBarang);
				counterBD++;
			} else cout << "Jenis Barang Salah!" << endl;
		}
		
		// Function Overloading
		// Membuat item baru khusus barang electronic dimana biaya pemasangan bisa diatur.
		void setNewItem(string jenisBarang, string newNamaBarang, unsigned long newHargaBarang, int jumlahBarang, unsigned long newBiayaPemasangan){
			if(jenisBarang == "Electronic"){
				stringstream stream;
				stream << counterBE;
				string str1;
				stream >> str1;
				myBarangElectronic[counterBE].setIdBarang("BEL"+str1);
				myBarangElectronic[counterBE].setNamaBarang(newNamaBarang);
				myBarangElectronic[counterBE].setHargaBarang(newHargaBarang);
				myBarangElectronic[counterBE].setStokBarang(jumlahBarang);
				myBarangElectronic[counterBE].setBiayaPemasangan(newBiayaPemasangan);
				counterBE++;
			} else cout << "Selain barang electronic tidak ada biaya pemasangan!" << endl;
		}
		
		// Fungsi untuk membuat pesanan baru
		void setOrder(){
			for(int i = 0; i < 20; i++){
				myOrder[i].setIdBarangDiOrder("");
			}
			cout << "\nInput data pelanggan :\n";
			cout << setw(25) << "Masukkan nama Anda" << " : ";
			cin.ignore();
			cin.getline(namaPelanggan, 50);
			cout << setw(25) << "Estimasi jarak pengiriman" << " : ";
			cin.sync();
			cin.clear();
			cin >> jarakPengiriman;
			cout << "\nInput barang yang ingin dibeli: ";
			for(int i = 0; i < 20; i++){
				string tmpId;
				int tmpJumlahBarang;
				string pilihan;
				cout << endl;
				cout << setw(15) << "ID Barang" << " : ";
				cin >> tmpId;
				string cutId = tmpId.substr(0,3);
				
				// Pengecekan ID barang yang diinput
				while(cutId != "BNE" && cutId != "BEL" && cutId != "BDI") {
					cout << "Id yang anda masukkan salah!\n";
					cout << setw(15) << "ID Barang" << " : ";
					cin >> tmpId;
					cutId = tmpId.substr(0,3);
				}
				myOrder[i].setIdBarangDiOrder(tmpId);
				cout << setw(15) << "Jumlah Barang" << " : ";
				cin >> tmpJumlahBarang;
				
				// Reduce stok barang
				if(cutId == "BNE"){
					for(int j = 0; j < 20; j++){
						if(myBarangNonElectronic[j].getIdBarang() == tmpId){
							if(tmpJumlahBarang <= myBarangNonElectronic[j].getStokBarang()){
								myBarangNonElectronic[j].reduceStokBarang(tmpJumlahBarang);
								myOrder[i].setJumlahOrderan(tmpJumlahBarang);
								break;
							} else cout << "Stok barang tidak mencukupi!\n";
						}
					}
				} else if(cutId == "BEL"){
					for(int j = 0; j < 20; j++){
						if(myBarangElectronic[j].getIdBarang() == tmpId){
							if(tmpJumlahBarang <= myBarangElectronic[j].getStokBarang()){
								myBarangElectronic[j].reduceStokBarang(tmpJumlahBarang);
								myOrder[i].setJumlahOrderan(tmpJumlahBarang);
								break;
							} else cout << "Stok barang tidak mencukupi!\n";
						}
					}
				} else if(cutId == "BDI"){
					for(int j = 0; j < 20; j++){
						if(myBarangDigital[j].getIdBarang() == tmpId){
							if(tmpJumlahBarang <= myBarangDigital[j].getStokBarang()){
								myBarangDigital[j].reduceStokBarang(tmpJumlahBarang);
								myOrder[i].setJumlahOrderan(tmpJumlahBarang);
								break;
							} else cout << "Stok barang tidak mencukupi!\n";
						}
					}
				} 
				
				cout << "Tambah barang lainnya? (y/n) ";
				cin >> pilihan;
				while(pilihan != "y" && pilihan != "n"){
					cout << "Pilihan yang Anda masukkan salah!" << endl;
					cout << "Tambah barang lainnya? (y/n) ";
					cin >> pilihan;
				}
				if(pilihan == "n") break;
			}
		}
		
		// Fungsi untuk menampilkan semua pesanan
		void showOrder(){
			int number = 1;
			unsigned long totalBiaya = 0;
			cout << "\nDetail Pesanan:\n";
			cout << "\nNama : " << namaPelanggan << endl;
			for(int i = 0; i < 126; i++) cout << "=";
			cout << endl;
			cout << "| ";
			cout << left << setw(2) << "No" << " | ";
			cout << left << setw(30) << "Nama Barang" << " | ";
			cout << left << setw(10) << "Jumlah" << " | ";
			cout << left << setw(14) << "Harga Barang" << " | ";
			cout << left << setw(14) << "Ongkos Kirim" << " | " ;
			cout << left << setw(15) << "Biaya Pemasangan" << " | ";
			cout << left << setw(18) << "Sub Total Biaya" << " | "<< endl;
			for(int i = 0; i < 126; i++) cout << "=";
			cout << endl;
			for(int i = 0; i < 20; i++){
				string fullId = myOrder[i].getIdBarang();
				int jumlahOrderan = myOrder[i].getJumlahOrderan();
				if(fullId.empty() && fullId != ""){
					continue;
				} else{
					string cutId = fullId.substr(0,3);
					if(cutId == "BNE"){
						for(int j=0; j < 20; j++){
							if(myBarangNonElectronic[j].getIdBarang() == fullId){
								cout << "| ";
								cout << left << setw(2) << number << " | ";
								cout << left << setw(30) << myBarangNonElectronic[j].getNamaBarang() << " | ";
								cout << left << setw(10) << jumlahOrderan << " | ";
								unsigned long subTotal = calcBiaya((myBarangNonElectronic[j].getHargaBarang() * jumlahOrderan),jarakPengiriman);
								totalBiaya += subTotal;
								cout << left << "Rp" << setw(12) << myBarangNonElectronic[j].getHargaBarang() * jumlahOrderan << " | ";
								cout << left << "Rp" << setw(12) << (jarakPengiriman*2000) << " | ";
								cout << left << "Rp" << setw(14) << "0" << " | ";
								cout << left << "Rp" << setw(16) << subTotal << " | " << endl;
								number++;
							}
						}
					} else if(cutId == "BEL"){
						for(int j=0; j < 20; j++){
							if(myBarangElectronic[j].getIdBarang() == fullId){
								cout << "| ";
								cout << left << setw(2) << number << " | ";
								cout << left << setw(30) << myBarangElectronic[j].getNamaBarang() << " | ";
								cout << left << setw(10) << jumlahOrderan << " | ";
								unsigned long subTotal = calcBiaya((myBarangElectronic[j].getHargaBarang() * jumlahOrderan) ,jarakPengiriman, myBarangElectronic[j].getBiayaPemasangan());
								totalBiaya += subTotal;
								cout << left << "Rp" << setw(12) << myBarangElectronic[j].getHargaBarang() * jumlahOrderan<< " | ";
								cout << left << "Rp" << setw(12) << (jarakPengiriman*2000) << " | ";
								cout << left << "Rp" << setw(14) << myBarangElectronic[j].getBiayaPemasangan() << " | ";
								cout << left << "Rp" << setw(16) << subTotal << " | " << endl;
								number++;
							}
						}
					} else if(cutId == "BDI"){
						for(int j=0; j < 20; j++){
							if(myBarangDigital[j].getIdBarang() == fullId){
								cout << "| ";
								cout << left << setw(2) << number << " | ";
								cout << left << setw(30) << myBarangDigital[j].getNamaBarang() << " | ";
								cout << left << setw(10) << myOrder[i].getJumlahOrderan() << " | ";
								unsigned long subTotal = myBarangDigital[j].getHargaBarang() * jumlahOrderan;
								totalBiaya += subTotal;
								cout << left << "Rp" << setw(12) << myBarangDigital[j].getHargaBarang() * jumlahOrderan << " | ";
								cout << left << "Rp" << setw(12) << "0" << " | ";
								cout << left << "Rp" << setw(14) << "0" << " | ";
								cout << left << "Rp" << setw(16) << subTotal << " | " << endl;
								number++;
							}
						}
					}
				}
			}
			for(int i = 0; i < 126; i++) cout << "=";
			cout << "\n| ";
			cout << left << setw(10) << "Total Biaya : " ;
			stringstream stream;
			stream << totalBiaya;
			string str1;
			stream >> str1;
			cout << left << setw(90) << " " << left << setw(18) << "Rp"+str1 << " | " << endl;
			for(int i = 0; i < 126; i++) cout << "=";
			cout << endl;
		}
		
		
		// Fungsi untuk menampilkan barang yang dijual
		void showStore(){
			cout << right << setw(48) << "Toko Online Esha Sajaka" << endl;
			int number = 1;
			for(int i = 0; i < 74; i++) cout << "=";
			cout << endl;
			cout << "| ";
			cout << left << setw(2) << "No" << " | ";
			cout << left << setw(10) << "ID Barang" << " | ";
			cout << left << setw(30) << "Nama Barang" << " | ";
			cout << left << setw(10) << "Harga Barang" << " | ";
			cout << left << setw(4) << "Stok" << " | " << endl;
			for(int i = 0; i < 74; i++) cout << "=";
			cout << endl;
			for(int i = 0; i < counterBNE; i++){
				string nama = this->myBarangNonElectronic[i].getNamaBarang();
				if(nama.size() != 0){
					cout << "| ";
					cout << left << setw(2) << number << " | ";
					number++;
					cout << left << setw(10) << this->myBarangNonElectronic[i].getIdBarang() << " | ";
					cout << left << setw(30) << this->myBarangNonElectronic[i].getNamaBarang() << " | ";
					cout << left << "Rp" << setw(10) << this->myBarangNonElectronic[i].getHargaBarang() << " | ";
					cout << left << setw(4) << this->myBarangNonElectronic[i].getStokBarang() << " | ";
					cout << endl;
				}
			}
			for(int i = 0; i < counterBE; i++){
				string nama = this->myBarangElectronic[i].getNamaBarang();
				if(nama.size() != 0){
					cout << "| ";
					cout << left << setw(2) << number << " | ";
					number++;
					cout << left << setw(10) << this->myBarangElectronic[i].getIdBarang() << " | ";
					cout << left << setw(30) << this->myBarangElectronic[i].getNamaBarang() << " | ";
					cout << left << "Rp" << setw(10) << this->myBarangElectronic[i].getHargaBarang() << " | ";
					cout << left << setw(4) << this->myBarangElectronic[i].getStokBarang() << " | ";
					cout << endl;
				}
			}
			for(int i = 0; i < counterBD; i++){
				string nama = this->myBarangDigital[i].getNamaBarang();
				if(nama.size() != 0){
					cout << "| ";
					cout << left << setw(2) << number << " | ";
					number++;
					cout << left << setw(10) << this->myBarangDigital[i].getIdBarang() << " | ";
					cout << left << setw(30) << this->myBarangDigital[i].getNamaBarang() << " | ";
					cout << left << "Rp" << setw(10) << this->myBarangDigital[i].getHargaBarang() << " | ";
					cout << left << setw(4) << this->myBarangDigital[i].getStokBarang() << " | ";
					cout << endl;
				}
			}
			for(int i = 0; i < 74; i++) cout << "=";
			cout << endl;
		}
};

// Static variable
int Store::counterBNE = 0;
int Store::counterBE = 0;
int Store::counterBD = 0;

int menu(){
	int pilihan;
	cout << "\nMenu: " << endl;
	cout << "1. Pesan Barang" << endl;
	cout << "2. Cetak Struk" << endl;
	cout << "3. Keluar" << endl;
	cout << "\nMasukkan pilihan Anda : ";
	cin >> pilihan;
	
	// Pengecekan input user
	while(1) {
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Menu yang Anda pilih tidak tersedia!\n" << endl;
			cout << "Masukkan kembali pilihan Anda : ";
			cin >> pilihan;
		} else if(pilihan < 1 || pilihan > 3) {
			cout << "Menu yang Anda pilih tidak tersedia!\n" << endl;
			cout << "Masukkan kembali pilihan Anda : ";
			cin >> pilihan;
		} else break;	
	}
	return pilihan;
}


int main(){
	// Inisialisasi toko
	Store myStore; 
	myStore.setNewItem("Non Electronic", "Baju Koko", 100000, 5);
	myStore.setNewItem("Electronic", "Kulkas Dua Pintu", 20000000, 3);
	myStore.setNewItem("Digital", "Pulsa 50.000", 52000, 10);
	myStore.setNewItem("Digital", "Top Up 300 Genesis Crystal GI", 80000, 5);
	myStore.showStore();
	
	int pilihan = 0, flag;
	pilihan = menu();
	while(pilihan <= 2 && pilihan >= 0){
		if(pilihan == 1){
			myStore.setOrder();
			cout << "\nPesanan berhasil dibuat...";
			flag = cin.get();
			cin.ignore();
			cout << string(50, '\n');
			myStore.showStore();
			pilihan = menu();
		} else if(pilihan == 2){
			myStore.showOrder();
			cout << "\nTekan enter untuk kembali ke menu utama...";
			flag = cin.get();
			cin.ignore();
			cout << string(50, '\n');
			myStore.showStore();
			pilihan = menu();
		}
	}
	
	return 0;
}

