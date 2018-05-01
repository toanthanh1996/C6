#include <iostream>
using namespace std;
class employee
{
	private:
		int employ_numb;
		float employ_comp;
	public:
		employee()
		{
			emp_numb=0;
			emp_comp=0.0;
		}
		employee(int numb, float comp)
		{
			this->emp_numb=numb;
			this->emp_comp=comp;
		}
		~employee(){};
		void Input_employee();
		void display_employee_data()
		{
			cout<<"Employee's number: "<<employ_numb<<endl;
			cout<<"Employee's compentation: "<<employ_comp<<endl;
		}
};
int main ()
{
	employee e[3];
	int i=1;
	cout<<"Input Employee's information: "<<endl;
	do
	{
		e[i].Input_employee();
		i++;
	}while(i<=3);
	cout<<"Display Employee's information: "<<endl;
	for(int i=1; i<=3; i++)
	{
		e[i].display_employee_data();
	}
	
	return 0;
}
void employee::Input_employee()
{
	cout<<"Employee's Number: ";	cin>>employ_numb;	cout<<endl;
	cout<<"Employee's Compensation: ";	cin>>employ_comp;	cout<<endl;
}
