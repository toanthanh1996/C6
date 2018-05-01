#include <iostream>
using namespace std;
enum etype
{
	laborer,	//l
	secretary,	//s
	manager,	//m
	accountant,	//a
	executive,	//e
	researcher	//r
};
bool check_date(int, int, int);
struct sdate
{
	int day;
	int month;
	int year;
};
class date
{
	private:
		unsigned int day;
		unsigned int month;
		unsigned int year;
	public:
		date()
		{
		day=0;
		month=0;
		year=0;
		}
		date(unsigned int m, unsigned int d, unsigned int y)
		{
			this->day=d;
			this->month=m;
			this->year=y;
		};
		void getdate(sdate d)
		{
			this->day=d.day;
			this->month=d.month;
			this->year=d.year;
		}
		void setdate();
		void showdate()
		{
			cout<<"(mm/dd/yyyy) :"<<month<<"/"<<day<<"/"<<year<<endl;
		}
};
class employee
{
	private:
		int employ_numb;
		float employ_comp;
		date employ_date;
		etype employ_job;
	public:
		employee()
		{
			employ_numb=0;
			employ_comp=0.0;
		}
		employee(int numb, float comp)
		{
			this->employ_numb=numb;
			this->employ_comp=comp;
		}
		~employee(){};
		void Input_employee();
		void display_employee_data();
};
int main()
{
	employee emp[3];
	for(int i=0; i<3; i++)
	{
		emp[i].Input_employee();
	}
	cout<<"Correct!"<<endl;
	for(int i=0; i<3; i++)
	{
		emp[i].display_employee_data();
	}
	return 0;
}
bool check_date(int d,int m,int y)
{
	bool accepable=true;
	switch(m)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			{
				if(d>31)
				{
					accepable=false;
				}
				break;
			}
		case 4: case 6: case 9: case 11:
			{
				if(d>30)
				{
					accepable=false;
				}
				break;
			}
		case 2:
			{
				if(y%4==0 && d>29)
				{
					accepable=false;
				}
				if(y%4!=0 && d>28)
				{
					accepable=false;
				}
				break;
			}
		default:
			accepable=false;
			break;
	}
	return accepable;
}
void date::setdate()
{
	bool checkdate=false;
	char c;
	do
	{
		cout<<"Enter your date (mm/dd/yyyy): ";
		cin>>month>>c>>day>>c>>year;
		checkdate=check_date(day, month, year);
		if(checkdate==false)
		{
			cout<<"Your date is Wrong!"<<endl;
			cout<<"Please Enter your date again!"<<endl;
		}
	}while(checkdate==false);	
}

void employee::Input_employee()
{
	cout<<"Enter Employee's Info"<<endl;
	cout<<"Employee's number: ";	cin>>employ_numb;	cout<<endl;
	cout<<"Employee's compensation: ";	cin>>employ_comp;	cout<<endl;
	cout<<"Employee's hired date: ";
	employ_date.setdate();	cout<<endl;
	char key=0;
	bool checkjob=false;
	do
	{
		cout<<"Employee's job: ";	cin>>key;
		//fflush(stdin);
		switch(key)
		{
			case 'l':
			{
				employ_job=laborer;
				checkjob=true;
				break;
			}
			case 's':
			{
				employ_job=secretary;
				checkjob=true;
				break;
			}	
			case 'm':
			{
				employ_job=manager;
				checkjob=true;
				break;
			}
			case 'a':
			{
				employ_job=accountant;
				checkjob=true;		
				break;
			}
			case 'e':
			{
				employ_job=executive;
				checkjob=true;
				break;
			}
			case 'r':
			{
				employ_job=researcher;
				checkjob=true;	
				break;
			}
			default:
				{
				cout<<"Acceptable Letters is:"<<endl;
				cout<<"<l>:<laborer>."<<endl;
				cout<<"<s>:<secretary>."<<endl;
				cout<<"<m>:<manager>."<<endl;
				cout<<"<a>:<accountance>."<<endl;
				cout<<"<e>:<executive>."<<endl;
				cout<<"<r>:<researcher>."<<endl;
				cout<<"Please enter again!"<<endl;
				checkjob=false;
				break;
				}
		}
	} while(checkjob==false);
}
void employee::display_employee_data()
{
	cout<<"-----------------------------------"<<endl;
	cout<<"Employee's Information"<<endl;
	cout<<"Employee's number: "<<employ_numb<<endl;
	cout<<"Employee's compensation: "<<employ_comp<<endl;
	cout<<"Employee's hired date: ";employ_date.showdate();
	cout<<"Employee's job: ";
	switch(employ_job)
	{
		case laborer:
		{
			cout<<"Laborer"<<endl;
			break;
		}
		case secretary:
		{
			cout<<"Secretary"<<endl;
			break;
		}	
		case manager:
		{
			cout<<"Manager"<<endl;
			break;
		}
		case accountant:
		{
			cout<<"Accountant"<<endl;	
			break;
		}
		case executive:
		{
			cout<<"Executive"<<endl;
			break;
		}
		case researcher:
		{
			cout<<"Researcher"<<endl;
			break;
		}
	}
}

