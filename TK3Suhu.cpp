#include <iostream>

using namespace std;

double convert (double a){
    double x;
    x = (a - 32) * 5 / 9;
    cout << "Pemanggilan dengan tipe data double\n"
            "Proses dengan tipe data double\n" << a << " sama dengan " << x << endl;
    return x;
}

float convert (float b){
    float y;
    y = (b - 32) * 5 / 9;
    cout << "Pemanggilan dengan tipe data float\n"
            "Proses dengan tipe data float\n" << b << " sama dengan " << y << endl;
    return y;
}

int convert (int c){
    int z;
    z = (c - 32) * 5 / 9;
    cout << "Pemanggilan dengan tipe data integer\n"
            "Proses dengan tipe data integer\n" << c << " sama dengan " << z << endl;
    return z;
}

int main (){
    double a = 100;
    float b = 100;
    int c = 100;
    
    convert (a);
    convert (b);
    convert (c); 

    return 0;
}