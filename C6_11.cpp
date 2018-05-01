#include <iostream>
#include <cmath>
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
		void lowterms();
		void show_fraction();
};
int main()
{
	fraction f;
	cout<<"Enter fraction: ";	
	f.set_fraction();
	f.lowterms();
	cout<<"Lowest term fraction result: "; f.show_fraction();
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
void fraction::lowterms()
{
	long tnum, tden, temp, gcd;
	tnum=abs(numerator);
	tden=abs(denominator);
	if(tden==0)
	{
		cout<<"Illegal fraction: division by 0; exit(1);";
	}
	else
	{
		if(tnum==0)
		{
			numerator=0;
			denominator=1;
			return;
		}
	}
	while(tnum!=0)
	{
		if(tnum<tden)
		{
			temp=tnum;
			tnum=tden;
			tden=temp;
		}
		tnum=tnum-tden;
	}
	gcd=tden;
	numerator=numerator/gcd;
	denominator=denominator/gcd;
}
