//6.1
//
#include <iostream>
using namespace std;
class Int
{
	private:
		int number;
	public:
		Int(){number=0;}
		Int(int n){ number = n;}
		
		void setdata(int nb){number=nb;}
		int get(){return number;}
		void showdata()
		{
			
			cout<<"Number is: "<<number<<endl;
		}
		Int add_number(Int, Int);
};

Int Int::add_number(Int b, Int c)
{
	number=b.number+c.number;
}
int main()
{
	Int a(5),b(4),c;
	a.showdata();
	b.showdata();
	c.add_number(a,b);
	c.showdata();
	system("pause");
	return 0;
}
