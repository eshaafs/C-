// last update 16/05/2022 08:47 AM
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Class Karyawan
class karyawan {
private:
  string nama_pegawai;
  int jumlah_jamkerja;

public:
  void setData();
  string getName();
  int getJumlahJamKerja();
  long getHonor();
  long getHonorLembur();
  long getTotalHonor();
};

void tableLine() {
  for (int i = 0; i < 95; i++) {
    cout << "=";
  }
  cout << endl;
}

// function get data karyawan
void karyawan::setData() {
  cout << "Nama Pegawai (tanpa spasi) : ";
  cin >> this->nama_pegawai;
  cin.sync();
  cin.clear();
  cout << "Jumlah Jam Kerja : ";
  cin >> jumlah_jamkerja;
  cin.sync();
  cin.clear();
  cout << endl;
}

string karyawan::getName() { 
  return this->nama_pegawai; 
}

int karyawan::getJumlahJamKerja() { 
  return this->jumlah_jamkerja; 
}

long karyawan::getHonor() {
  return 200000; 
}

long karyawan::getHonorLembur() {
  if (this->getJumlahJamKerja() > 8) {
    return (this->getJumlahJamKerja() - 8) * 25000;
  } else
    return 0;
}

long karyawan::getTotalHonor() {
  return this->getHonor() + this->getHonorLembur();
}

int Menu() {
  int pilihan;
  cout << "Program Perhitungan Gaji" << endl;
  cout << "PT. Meriang Gembira" << endl;
  cout << "=========================\n" << endl;
  cout << "Menu: " << endl;
  cout << "  1. Input data karyawan" << endl;
  cout << "  2. Print data karyawan" << endl;
  cout << "  3. Keluar" << endl;
  cout << "\nMasukkan pilihan Anda: ";
  cin >> pilihan;
  cin.sync();
  cin.clear();
  return pilihan;
}

template<typename T> void printElement(T t, const int& width)
{
	const char separator    = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}

// main
int main() {
  int jumlah, pilihan;
  string tanggal_input;
  karyawan dataKaryawan[50];
  pilihan = Menu();
  while (pilihan > 3 || pilihan < 1) {
    cout << "Menu yang Anda pilih tidak tersedia!" << endl;
    cout << "Masukkan kembali pilihan Anda: " << endl;
    cin >> pilihan;
  }
  while (pilihan > 0 && pilihan < 3) {
    if (pilihan == 1) {
      cout << "\n\nInput data karyawan" << endl;
      cout << "PT. Meriang Gembira" << endl;
      cout << endl;
      cout << "Jumlah\t: ";
      cin >> jumlah;
      cin.sync();
      cin.clear();
      cout << "Tanggal (dd/mm/yyyy)\t: ";
      cin >> tanggal_input;
      cin.sync();
      cin.clear();
      cout << "-----------------------------------------------------------";
      cout << endl;
      for (int i = 0; i < jumlah; i++) {
        cout << "Data ke-" << i + 1 << endl;
        dataKaryawan[i].setData();
      }
      cout << "Input data selesai, tekan enter untuk kembali ke menu utama...";
      cin.get();
      cout << endl << endl;
      pilihan = Menu();
    } else if (pilihan == 2) {
  	  const int nameWidth     = 30;
  	  const int numWidth      = 17;
	  float totalHonorPegawai = 0;
      cout << "\n\nData Gaji Karyawan" << endl;
      cout << "PT Meriang Gembira" << endl << endl;
      cout << "Tanggal\t: " << tanggal_input << endl;
      tableLine();
      printElement("No", 3);
      printElement("Nama", nameWidth);
      printElement("Honor", numWidth);
      printElement("Jumlah", numWidth);
      printElement("Honor", numWidth);
      printElement("Total", numWidth);
      cout << endl;
      printElement("", 3);
      printElement("Pegawai", nameWidth);
      printElement("", numWidth);
      printElement("Jam Kerja", numWidth);
      printElement("Lembur", numWidth);
      printElement("Honor", numWidth);
      cout << endl;
	    tableLine();
      for (int i = 0; i < jumlah; i++) {
        printElement(i + 1, 3);
        printElement(dataKaryawan[i].getName(), nameWidth);
        printElement(dataKaryawan[i].getHonor(), numWidth);
        printElement(dataKaryawan[i].getJumlahJamKerja(), numWidth);
        printElement(dataKaryawan[i].getHonorLembur(), numWidth);
        printElement(dataKaryawan[i].getTotalHonor(), numWidth);
        cout << "\n";
        totalHonorPegawai += dataKaryawan[i].getTotalHonor();
      }
      tableLine();
      cout << "Total Honor Pegawai Sebesar : " << fixed << setprecision(0) << totalHonorPegawai;
      cout << "\n\nTekan enter untuk kembali ke menu utama...";
      cin.get();
      cout << endl << endl;
      pilihan = Menu();
    }
  }
}
