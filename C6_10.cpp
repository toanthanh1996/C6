#include <iostream>
using namespace std;
class angle
{
	private:
		int degrees;
		float minutes;
		char direction;
	public:
		angle()
		{
			degrees=0;
			minutes=0.0f;
		}
		void set_longitude();
		void set_latitude();
		void set_angle();
		void show_angle();
};
class ship
{
	private:
		static unsigned int count;
		int ship_number;
		angle ship_longitude_pos;
		angle ship_latitude_pos;
	public:
		ship()
		{
			count++;
			ship_number=count;
		}
		void Input_Ship_pos();
		void Display_Ship_pos();
};
int main()
{
	ship s[3];
	for(int i=0; i<3; i++)
	{
		cout<<"Enter Ship's Info: "<<endl;
		s[i].Input_Ship_pos();
		cout<<"--------------------------"<<endl;
	}
	cout<<"Successful!"<<endl;
	cout<<"--------------------------"<<endl;
	for(int i=0; i<3; i++)
	{
		s[i].Display_Ship_pos();
		cout<<"--------------------------"<<endl;
	}
	return 0;
}
unsigned int ship::count=0;
void angle::set_longitude()
{
	bool check_direction=false;
	bool check_value=true;
	char c;
	do
	{
		check_value=true;
		cout<<"degrees: ";	cin>>degrees;	cout<<endl;
		cout<<"minutes: ";	cin>>minutes;	cout<<endl;
		for(;minutes>=60; minutes-=60)
		{
			degrees+=1;
		}
		if(degrees>180)
		{
			cout<<"The Longitude Angle is Wrong!"<<endl;
			cout<<"The degrees must be smaller than 180!"<<endl;
			check_value=false;
		}
	}while(check_value==false);
	do
	{
		cout<<"direction: ";cin>>c;	cout<<endl;
		switch(c)
		{
			case 'e':
				{
					direction='E';
					check_direction=true;
					break;
				}
			case 'w':
				{
					direction='W';
					check_direction=true;
					break;
				}
			default:
				{
					cout<<"The Longitude direction is Wrong!"<<endl;
					cout<<"<e>:<East>"<<endl;
					cout<<"<w>:<West>"<<endl;
					cout<<"Please enter again!"<<endl;
					break;
				}
		}
	}while(check_direction==false);
}
void angle::set_latitude()
{
	bool check_direction=false;
	bool check_value;
	char c;
	do
	{
		check_value=true;
		cout<<"degrees: ";	cin>>degrees;	cout<<endl;
		cout<<"minutes: ";	cin>>minutes;	cout<<endl;
		for(;minutes>=60; minutes-=60)
		{
			degrees+=1;
		}
		if(degrees>90)
		{
			cout<<"The Latitude Angle is Wrong!"<<endl;
			cout<<"The degrees must be smaller than 90!"<<endl;
			check_value=false;
		}
	}while(check_value==false);
	do
	{
		cout<<"direction: ";cin>>c;	cout<<endl;
		switch(c)
		{
			case 's':
				{
					direction='S';
					check_direction=true;
					break;
				}
			case 'n':
				{
					direction='N';
					check_direction=true;
					break;
				}
			default:
				{
					cout<<"The Latitude direction is Wrong!"<<endl;
					cout<<"<s>:<South>"<<endl;
					cout<<"<n>:<North>"<<endl;
					cout<<"Please enter again!"<<endl;
					break;
				}
		}
	}while(check_direction==false);
}
void angle::set_angle()
{
	bool check_direction=false;
	char c;
	cout<<"Enter Angle value: "<<endl;
	cout<<"degrees: ";	cin>>degrees;	cout<<endl;
	cout<<"minutes: ";	cin>>minutes;	cout<<endl;
	for(;minutes>=60; minutes-=60)
	{
		degrees+=1;
	}
	do
	{
		cout<<"direction: ";cin>>c;	cout<<endl;
		switch(c)
		{
			case 'e':
				{
					direction='E';
					check_direction=true;
					break;
				}
			case 'w':
				{
					direction='W';
					check_direction=true;
					break;
				}
			case 's':
				{
					direction='S';
					check_direction=true;
					break;
				}
			case 'n':
				{
					direction='N';
					check_direction=true;
					break;
				}
			default:
				{
					cout<<"The direction is Wrong!"<<endl;
					cout<<"<e>:<East>"<<endl;
					cout<<"<w>:<West>"<<endl;
					cout<<"<s>:<South>"<<endl;
					cout<<"<n>:<North>"<<endl;
					cout<<"Please enter again!"<<endl;
					break;
				}
		}
	}while(check_direction==false);
}
void angle::show_angle()
{
	cout<<degrees<<'\xF8'<<" "<<minutes<<"' "<<direction;
}
void ship::Input_Ship_pos()
{
	cout<<"Ship number "<<ship_number<<endl;
	cout<<"Ship's longitude: "<<endl;	ship_longitude_pos.set_longitude();
	cout<<"Ship's latitude: "<<endl;	ship_latitude_pos.set_latitude();
}
void ship::Display_Ship_pos()
{
	cout<<"Ship's number: "<<ship_number<<endl;
	cout<<"Ship's position: ";
	ship_longitude_pos.show_angle();
	cout<<"    ";
	ship_latitude_pos.show_angle();
	cout<<endl;
}
