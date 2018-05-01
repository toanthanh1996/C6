#include <iostream>
using namespace std;
struct sfraction
{
	int numerator;
	int denominator;
};
class fraction
{
	private:
			int numerator;
			int denominator;
	public:
		fraction()
		{
			numerator=0;
			denominator=1;
		};
		~fraction(){};
		void get_fraction(sfraction f)
		{
			this->numerator=f.numerator;
			this->denominator=f.denominator;
		}
		int get_numerator()
		{
			return numerator;
		}
		int get_denominator()
		{
			return denominator;
		}
		void set_fraction();
		fraction add_fraction(fraction, fraction);
		void show_fraction();
};
int main()
{
	int choice;
	fraction f1, f2, f3;
	bool exit_program=false;
	do
	{
		cout<<"Enter first fraction: ";	f1.set_fraction();	cout<<endl;
		cout<<"Enter second fraction: ";f2.set_fraction();	cout<<endl;
		f3.add_fraction(f1,f2);
		cout<<"Fraction 1 + Fraction 2: ";	f3.show_fraction();	cout<<endl;
		cout<<"Do you want to continue: "<<endl;
		cout<<"1.yes"<<endl;
		cout<<"2.no"<<endl;
		cout<<"Your choice: ";	cin>>choice;
		switch(choice)
		{
			case 1:
				{
					exit_program=false;
					break;
				}
			default:
				{
					exit_program=true;
				}
		}	
	}while(exit_program==false);
	return 0;
}
void fraction::set_fraction()
{
	char c;	
	cin>>numerator>>c>>denominator;
}
void fraction::show_fraction()
{
	cout<<numerator<<"/"<<denominator;
}
fraction fraction::add_fraction(fraction a, fraction b)
{
	numerator=(a.get_numerator()*b.get_denominator()+b.get_numerator()*a.get_denominator());
	denominator=a.get_denominator()*b.get_denominator();
}
