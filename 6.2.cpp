#include <iostream>
using namespace std;
class tollBooth
{
	private:
		unsigned car_number;
		double amount;
	public:
		tollBooth
		{
			car_number(0);
			amount(0);
		}
		void payingCar()
		{
			++car_number;
			amount += 0.5f;
		}
		void nopayingCar()
		{
			++car_number;
		}
		void showdata()
		{
			cout<<"So xe da tra phi: "<<car_number<<endl;
			cout<<"So tien thu duoc: "<<amount<<endl;
			cout<<"So xe chua tra phi: "<<car_number<<endl;
		}
}
int main()
{
	do
	{
		getch
	}
	
	return 0;
}
