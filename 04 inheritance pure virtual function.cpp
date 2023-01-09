#include <iostream>

using namespace std;

class Binatang{
	protected:
		string namaBinatang, suaraBinatang;
	public:
		virtual void display() = 0;
		
		string getNamaBinatang(){
			return this->namaBinatang;
		}
		
		string getSuaraBinatang(){
			return this->suaraBinatang;
		}
};

class Kucing : public Binatang{
	public:
		Kucing(string nama, string suara){
			this->namaBinatang = nama;
			this->suaraBinatang = suara;
		}
		
		void display(){
			cout << "Informasi Binatang" << endl;
			cout << "Nama\t: " << this->getNamaBinatang() << endl;
			cout << "Suara\t: \"" << this->getSuaraBinatang() << "\"" << endl;
		}
};

class Bebek : public Binatang{
	public:
		Bebek(string nama, string suara){
			this->namaBinatang = nama;
			this->suaraBinatang = suara;
		}
		
		void display(){
			cout << "Informasi Binatang" << endl;
			cout << "Nama\t: " << this->getNamaBinatang() << endl;
			cout << "Suara\t: \"" << this->getSuaraBinatang() << "\"" << endl;
		}
};


int main(){
	cout << "POLIMORFISME 2" << endl;
	cout << "--------------" << endl;
	Kucing kucing1("Kucing", "meow meow");
	kucing1.display();
	cout << endl;
	Bebek bebek1("Bebek", "kukuruyuk");
	bebek1.display();
	return 0;
}
