#include <iostream>

using namespace std;

class Shape{
	protected:
		int lebar, tinggi;
	public:
		virtual int getLebar(){
			return this->lebar;
		}
		
		virtual int getTinggi(){
			return this->tinggi;
		}
};

class Rectangle : public Shape{
	public:
		Rectangle(int lebar, int tinggi){
			this->lebar = lebar;
			this->tinggi = tinggi;
		}
		
		int Area(){
			return lebar * tinggi;
		}
		
		void display(){
			cout << "Jenis shape\t: Rectangle" << endl;
			cout << "Lebar\t\t: " << this->lebar << endl;
			cout << "Tinggi\t\t: " << this->tinggi << endl;
			cout << "Luas\t\t: " << "Lebar x Tinggi = " << this->getLebar() << " x " << this->getTinggi() << " = " << this->Area() << endl;
		}
};

int main(){
	Rectangle rectangle1 = Rectangle(7, 5);
	rectangle1.display();
	return 0;
}
