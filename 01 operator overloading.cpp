#include <iostream>

using namespace std;

class time{
	private:
		unsigned int hour, minute;
	public:
		time(unsigned int hour, unsigned int minute){
			this->hour = hour;
			this->minute = minute;
		}
		
		// pre increment operator overloading
		time operator ++ (){
			if(this->minute < 59){
				++this->minute;
			} else if(this->minute == 59){
				if(this->hour < 23){
					this->minute = 0;
					++this->hour;
				} else {
					this->hour = 0;
					this->minute = 0;
				}
			} 
		}
		
		// post increment operator overloading
		time operator ++ (int){
			if(this->minute < 59){
				this->minute++;
			} else if(this->minute == 59){
				if(this->hour < 23){
					this->minute = 0;
					this->hour++;
				} else {
					this->hour = 0;
					this->minute = 0;
				}
			} 
		}
		
		// pre decrement operator overloading
		time operator -- (){
			if(this->minute > 0){
				--this->minute;
			} else if(this->minute == 0){
				if(this->hour > 0){
					this->minute = 59;
					--this->hour;
				} else {
					this->hour = 23;
					this->minute = 59;
				}
				
			} 
		}
		
		// post decrement operator overloading
		time operator -- (int){
			if(this->minute > 0){
				this->minute--;
			} else if(this->minute == 0){
				if(this->hour > 0){
					this->minute = 59;
					this->hour--;
				} else {
					this->hour = 23;
					this->minute = 59;
				}
				
			} 
		}
		
		unsigned int getHour(){
			return this->hour;
		}
		
		unsigned int getMinute(){
			return this->minute;
		}
};


int main(){
	time time1 = time(12, 0);
	cout << "H: " << time1.getHour() << "\tM: " << time1.getMinute() << endl;
	++time1;
	cout << "H: " << time1.getHour() << "\tM: " << time1.getMinute() << endl;
	
	time time2 = time(10,41);
	cout << "H: " << time2.getHour() << "\tM: " << time2.getMinute() << endl;
	time2--;
	cout << "H: " << time2.getHour() << "\tM: " << time2.getMinute() << endl;
	
	return 0;
}
