#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//class obat
class obat {
private:
	string kode_barang, nama_barang, status;
	int harga, stok;

public:
	//Friend Function
	friend void persediaan_obat(obat obt);
	obat() {
		kode_barang = "";
		nama_barang = "";
		harga = 0;
		stok = 0;
		status = "";
	}

	obat(string kodeBarang, string namaBarang, int hargaBarang, int totalStok) {
		this->kode_barang = kodeBarang;
		this->nama_barang = namaBarang;
		this->harga = hargaBarang;
		this->stok = totalStok;
	}
	
	void reduceStock(int jumlahPengurangan){
		this->stok -= jumlahPengurangan;
	}
	
	int getStock(){
		return this->stok;
	}
	
	string getKodeBarang(){
		return this->kode_barang;
	}
	
	int getHarga(){
		return this->harga;
	}
	
	string getNama(){
		return this->nama_barang;
	}
	
	string getStatus(){
		int threshold = 5;
		if (this->stok > threshold){
			this->status = "Tersedia";
		} else if (this->stok <= threshold && this->stok > 0){
			this->status = "Hampir Habis";
		} else if (this->stok == 0){
			this->status = "Habis";
		}
		
		return this->status;
	}
};

//Function persedian_obat
void persediaan_obat(obat obt) {
	cout << "\nKode Barang\t: " << obt.kode_barang << endl;
	cout << "Nama Barang\t: " << obt.nama_barang << endl;
	cout << "Harga\t\t: " << obt.harga << endl;
	cout << "Stok\t\t: " << obt.stok << endl;
	cout << "================================" << endl;
}

class Transaksi{
  protected:
    static int totalTransaksi;
    static unsigned int totalSemuaHarga;
    string idTransaksi, idObat, namaObat;
    int jumlahObat, hargaObat;
    unsigned int totalHarga;
  public:
    void newTransaksi(obat& passedObat, int jumlahObat){
      this->idObat = passedObat.getKodeBarang();
      this->namaObat = passedObat.getNama();
      this->hargaObat = passedObat.getHarga();
      this->jumlahObat = jumlahObat;
      Transaksi::totalTransaksi++;
      string str;
	  stringstream temp;
	  temp << this->totalTransaksi;
	  temp >> str;
      this->idTransaksi = "TRX" + str;
      passedObat.reduceStock(jumlahObat);
      this->totalHarga = passedObat.getHarga()*this->jumlahObat;
      Transaksi::totalSemuaHarga += this->totalHarga;
    }
    
    static unsigned int getTotalSemuaHarga(){
		return Transaksi::totalSemuaHarga;
	}
	
	static int getTotalTransaksi(){
		return Transaksi::totalTransaksi;
	}
	
	string getIdTransaksi(){
		return this->idTransaksi;
	}
	
	int getTotalHarga(){
		return this->totalHarga;
	}
	
	string getIdObat(){
		return this->idObat;
	}
	
	string getNamaObat(){
		return this->namaObat;
	}
	
	int getHargaObat(){
		return this->hargaObat;
	}
	
	int getJumlahObat(){
		return this->jumlahObat;
	}
};

class transaksiResep : public Transaksi{
	private:
		string nama, alamat;
	public:
		void newTransaksi(string newName, string newAlamat, obat& passedObat, int jumlahObat){
	      	this->idObat = passedObat.getKodeBarang();
	      	this->nama = newName;
	      	this->alamat = newAlamat;
      		this->namaObat = passedObat.getNama();
      		this->hargaObat = passedObat.getHarga();
	      	this->jumlahObat = jumlahObat;
	      	Transaksi::totalTransaksi++;
	      	string str;
			stringstream temp;
			temp << this->totalTransaksi;
			temp >> str;
	      	this->idTransaksi = "TRXRSP" + str;
	      	passedObat.reduceStock(jumlahObat);
	      	this->totalHarga = passedObat.getHarga()*this->jumlahObat;
      		Transaksi::totalSemuaHarga += this->totalHarga;
    	}
    	
    	string getNama(){
    		return this->nama;
		}
		
		string getAlamat(){
			return this->alamat;
		}
};

int Transaksi::totalTransaksi = 0;
unsigned int Transaksi::totalSemuaHarga = 0;

  //menu
int menu(){
  	cout << "================================" << endl;
	cout << "APOTEK BOL" << endl;
	cout << "Created by: Team 2 TPCA" << endl;
	cout << "================================\n" << endl;
	cout << " 1. Lihat Semua Stok Barang" << endl;
	cout << " 2. Membeli Obat" << endl;
	cout << " 3. Input Resep Dokter" << endl;
	cout << " 4. Cetak Struk" << endl;
	cout << " 5. Laporan Harian" << endl;
	cout << " 6. Keluar.." << endl;
	cout << "\nPilihan : ";
  	int pil;
	cin >> pil;
	cin.sync();
  return pil;
}


//main program

int main() {
	int pil, jumlahPembelian;
	string kodeobat, nama, alamat;
	bool status = false;

  //list barang
	obat obt1("OBT001", "Panadol", 10000, 13), obt2("OBT002", "Sanmol", 15000, 18), obt3("OBT003", "Bodrex", 11000, 25);

	Transaksi myTransaksi[100];
	transaksiResep myTransaksiResep[100];
	int transaksiCounter = 0;
	pil = menu();
  
	while (pil <= 5){
    	//options
		switch (pil){
  	
		  	case 1:
		  		persediaan_obat(obt1);
		  		persediaan_obat(obt2);
		  		persediaan_obat(obt3);
		      	cout << endl << endl;
		      	cout << "Tekan enter untuk kembali ke menu..." << endl;
				cin.get();
		      	pil = menu();
		  		break;
		    
		    case 2:
		    	cout << "\nMasukkan kode obat : ";
		    	cin.sync();
				cin >> kodeobat;	
				if(kodeobat == "OBT001") persediaan_obat(obt1);
				else if(kodeobat == "OBT002") persediaan_obat(obt2);
				else if(kodeobat == "OBT003") persediaan_obat(obt3);  	 
				else {
					cout << "Tekan enter untuk kembali ke menu..." << endl;
					cin.sync();
					cin.get();
					cout << "Kode yang Anda masukkan salah!" << endl;
					pil = menu();
					break;
				}
		    	transaksiCounter++;
		    	cout << "\nMasukkan jumlah pembelian obat : ";
		    	cin >> jumlahPembelian;
		    	cin.sync();
		    	if(kodeobat == "OBT001") {
		    		if(obt1.getStock() == 0) {
		    			cout << "Stok obat habis..." << endl;
					} else if(jumlahPembelian > obt1.getStock()){
						cout << "Stok tidak mencukupi untuk transaksi tersebut..." << endl;
					} else {
						myTransaksi[transaksiCounter].newTransaksi(obt1, jumlahPembelian);
						cout << "Transaksi berhasil...\n" << endl;
					}
				}
				else if(kodeobat == "OBT002") {
					if(obt2.getStock() == 0) {
		    			cout << "Stok obat habis..." << endl;
					} else if(jumlahPembelian > obt2.getStock()){
						cout << "Stok tidak mencukupi untuk transaksi tersebut..." << endl;
					} else {
						myTransaksi[transaksiCounter].newTransaksi(obt2, jumlahPembelian);
						cout << "Transaksi berhasil...\n" << endl;
					}
				}
				
				else if(kodeobat == "OBT003"){
					if(obt3.getStock() == 0) {
		    			cout << "Stok obat habis..." << endl;
					} else if(jumlahPembelian > obt3.getStock()){
						cout << "Stok tidak mencukupi untuk transaksi tersebut..." << endl;
					} else {
						myTransaksi[transaksiCounter].newTransaksi(obt3, jumlahPembelian);
						cout << "Transaksi berhasil...\n" << endl;
					}
				}
				cout << "Tekan enter untuk kembali ke menu..." << endl;
				cin.sync();
				cin.get();
				pil = menu();
		     	break;
		    
		    case 3:
		     	cout << "\nMasukkan nama pembeli : ";
		     	getline(cin, nama);
		     	cout << "Masukkan alamat pembeli : ";
		     	getline(cin, alamat);
		    	cout << "Masukkan kode obat : ";
				cin >> kodeobat;	
				cin.sync();
				if(kodeobat == "OBT001") persediaan_obat(obt1);
				else if(kodeobat == "OBT002") persediaan_obat(obt2);
				else if(kodeobat == "OBT003") persediaan_obat(obt3);  	 
				else {
					cout << "Kode yang Anda masukkan salah!" << endl;
					cout << "Tekan enter untuk kembali ke menu..." << endl;
					cin.get();
					pil = menu();
					break;
				}
		    	transaksiCounter++;
		    	cout << "\nMasukkan jumlah pembelian obat : ";
		    	cin.clear();
		    	cin >> jumlahPembelian;
		    	if(kodeobat == "OBT001") {
		    		if(obt1.getStock() == 0) {
		    			cout << "Stok obat habis..." << endl;
					} else if(jumlahPembelian > obt1.getStock()){
						cout << "Stok tidak mencukupi untuk transaksi tersebut..." << endl;
					} else {
						myTransaksiResep[transaksiCounter].newTransaksi(nama, alamat, obt1, jumlahPembelian);
						cout << "Transaksi berhasil...\n" << endl;
					}
				}
				else if(kodeobat == "OBT002") {
					if(obt2.getStock() == 0) {
		    			cout << "Stok obat habis..." << endl;
					} else if(jumlahPembelian > obt2.getStock()){
						cout << "Stok tidak mencukupi untuk transaksi tersebut..." << endl;
					} else {
						myTransaksiResep[transaksiCounter].newTransaksi(nama, alamat, obt2, jumlahPembelian);
						cout << "Transaksi berhasil...\n" << endl;
					}
				}
				
				else if(kodeobat == "OBT003"){
					if(obt3.getStock() == 0) {
		    			cout << "Stok obat habis..." << endl;
					} else if(jumlahPembelian > obt3.getStock()){
						cout << "Stok tidak mencukupi untuk transaksi tersebut..." << endl;
					} else {
						myTransaksiResep[transaksiCounter].newTransaksi(nama, alamat, obt3, jumlahPembelian);
						cout << "Transaksi berhasil...\n" << endl;
					}
				}
				cin.sync();
				cout << "Tekan enter untuk kembali ke menu..." << endl;
				cin.sync();
				cin.get();
				pil = menu();
		     	break;
		  
		    case 4:
		    	cout << "Masukkan kode obat : ";
		    	cin >> kodeobat;
		    	for(int i = 0; i <= 100; i++){
		    		if(myTransaksi[i].getIdObat() == kodeobat){
		    			cout << "\n================================" << endl;
		    			cout << "ID Transaksi\t: " << myTransaksi[i].getIdTransaksi() <<endl;
		    			cout << "Kode Obat\t: " << myTransaksi[i].getIdObat() << endl;
		    			cout << "Nama Obat\t: " << myTransaksi[i].getNamaObat() << endl;
		    			cout << "Harga Obat\t: " << myTransaksi[i].getHargaObat() << endl;
		    			cout << "Total Pembelian\t: " << myTransaksi[i].getJumlahObat() << endl;
		    			cout << "Total Harga\t: " << myTransaksi[i].getTotalHarga() << endl;
		    			status = true;
					}
					
					if(myTransaksiResep[i].getIdObat() == kodeobat){
		    			cout << "\n================================" << endl;
		    			cout << "ID Transaksi\t: " << myTransaksiResep[i].getIdTransaksi() << endl;
		    			cout << "Nama\t\t: " << myTransaksiResep[i].getNama() << endl;
		    			cout << "Alamat\t\t: " << myTransaksiResep[i].getAlamat() << endl; 
		    			cout << "Kode Obat\t: " << myTransaksiResep[i].getIdObat() << endl;
		    			cout << "Nama Obat\t: " << myTransaksiResep[i].getNamaObat() << endl;
		    			cout << "Harga Obat\t: " << myTransaksiResep[i].getHargaObat() << endl;
		    			cout << "Total Pembelian\t: " << myTransaksiResep[i].getJumlahObat() << endl;
		    			cout << "Total Harga\t: " << myTransaksiResep[i].getTotalHarga() << endl;
		    			status = true;
					}
				}
				
				if(status == false) cout << "Tidak ada transaksi hari ini" << endl;
				cin.sync();
				cout << "\nTekan enter untuk kembali ke menu..." << endl;
				cin.get();
		    	pil = menu();
		     	break;
		    
		    case 5:
		    	cout << "\n================================" << endl;
		    	cout << "Laporan Harian\n" << endl;
		    	cout << "================================\n" << endl;
		    	cout << "Laporan penjualan" << endl;
		    	cout << "================================" << endl;
		    	cout << "Jumlah transaksi hari ini : " << Transaksi::getTotalTransaksi() << endl;
		    	cout << "Total penjualan hari ini : " << Transaksi::getTotalSemuaHarga() << endl;
		    	cout << "================================\n" << endl;
		    	cout << "Status stok obat-obatan" << endl;
		    	cout << "================================" << endl;
		    	cout << "Nama obat\t: " << obt1.getNama() << endl;
		    	cout << "Sisa stok\t: " << obt1.getStock() << endl; 
				cout << "Status stok\t: " << obt1.getStatus() << endl << endl;
					
		    	cout << "Nama obat\t: " << obt2.getNama() << endl;
		    	cout << "Sisa stok\t: " << obt2.getStock() << endl; 
				cout << "Status stok\t: " << obt2.getStatus() << endl << endl;
					
		    	cout << "Nama obat\t: " << obt3.getNama() << endl;
		    	cout << "Sisa stok\t: " << obt3.getStock() << endl; 
				cout << "Status stok\t: " << obt3.getStatus() << endl << endl;
					
				cin.sync();
				cout << "\nTekan enter untuk kembali ke menu..." << endl;
				cin.get();
		    	pil = menu();
		     	break;
		     	
		    default:
		    	break;
  	}
  }
  return 0;
}
