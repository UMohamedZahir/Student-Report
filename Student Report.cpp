#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


class student
{
	int indexno;
	char name[50];
	double marks[3];
	char stream;
	double avg;
	double total;
	void calculate();	
public:
	void getdata();		
	void showdata() const;
	int retindexno() const;
};

void student::calculate()
{
	total = marks[0]+marks[1]+marks[2]; 
	avg = total/3.0;
	
}

void student::getdata()
{
	cout<<"\nEnter The Index number of student ";
	cin>>indexno;
	cout<<"\n\nEnter The Name of student ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\tSTREAM('C' FOR COMBINED MATHS OR 'B' FOR BIOLOGY): ";
    cin>>stream;
    cout<<"\n";
        if(stream=='C')
           {
              cout<<"\t\t\t  ------------------------------------------"<<"\n";
              cout<<"\t\t\t     ENTER THE SUBJECT MARKS"<<"\n";
              cout<<"\t\t\t  ------------------------------------------"<<"\n\n";
              cout<<"\t\t\t       PHYSICS     : ";
              cin>>marks[0];
              cout<<"\t\t\t       CHEMISTRY   : ";
              cin>>marks[1];
              cout<<"\t\t\t       MATHEMATICS : ";
              cin>>marks[2];
           }     
           else
           {
              cout<<"\t\t\t  ------------------------------------------"<<"\n";
              cout<<"\t\t\t     ENTER THE SUBJECT MARKS"<<"\n";
              cout<<"\t\t\t  ------------------------------------------"<<"\n\n";
              cout<<"\t\t\t       PHYSICS   : ";
              cin>>marks[0];
              cout<<"\t\t\t       CHEMISTRY : ";
              cin>>marks[1];
              cout<<"\t\t\t       BIOLOGY   : ";
              cin>>marks[2]; 
           }
	calculate();
}

void student::showdata() const
{
			cout<<"\nIndex number of student : "<<indexno<<"\n";
			cout<<"\nName of student : "<<name<<"\n";
			cout<<"\nStream :  "<<stream;
	if(stream=='C')
           {
            cout<<" - COMBINED MATHS"<<"\n";
			cout<<"\t\t\t  PHYSICS        : \t"<<marks[0]<<"\n";
            cout<<"\t\t\t  CHEMISTRY      : \t"<<marks[1]<<"\n";
     		cout<<"\t\t\t  COMBINED MATHS : \t"<<marks[2]<<"\n";
           }
           else if(stream=='B')
           {
            cout<<" - BIOLOGY"<<"\n";
			cout<<"\t\t\t  PHYSICS    : \t"<<marks[0]<<"\n";
            cout<<"\t\t\t  CHEMISTRY  : \t"<<marks[1]<<"\n";
            cout<<"\t\t\t  BIOLOGY    :\t"<<marks[2]<<"\n";
           }     
	 		 cout<<"\nTotal marks   :"<<total;
			 cout<<"\nAverage       :"<<avg;
			
}

int  student::retindexno() const
{
	return indexno;
}

void write_student();
void display_all();	
void display_sp(int);	
void intro();		
void entry_menu();	

int main()
{
	char ch;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); 
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\t\t\t\t\tMAIN MENU";
		cout<<"\n\n\t\t\t\t\t 1. STUDENT REPORT MENU";
		cout<<"\n\n\t\t\t\t\t 2. EXIT";
		cout<<"\n\n\t\t\t\t\tPlease Select Your Option  ";
		cin>>ch;
		switch(ch)
		{
			case '1': entry_menu();
			break;
			case '2':
			break;
			default :cout<<"\a";
		}
    }while(ch!='2');
	return 0;
}

void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("Report.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
	outFile.close();
    	cout<<"\n\n\t\t\tStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}


void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("Report.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tALL STUDENTS RECORDS !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}


void display_sp(int n)
{
	student st;
	ifstream inFile;
	inFile.open("Report.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
	{
		if(st.retindexno()==n)
		{
	  		 st.showdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}

void intro()
{
	cout<<"\n\n\n\t\t\t\t\tSTUDENT REPORT CARD PROJECT ";
	cout<<"\n\n\n\t\t\t\t\tCREATED BY : U MOHAMED ZAHIR";
	cout<<"\n\n\n\t\t\t\t\tPRESS ENTER TO START";
	cin.get();
}


void entry_menu()
{
	char ch;
	int num;
	system("cls");
	cout<<"\n\n\n\t\t\t\tSTUDENT REPORT MENU";
	cout<<"\n\n\t\t\t\t\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t\t\t\t\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t\t\t\t\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t\t\t\t\t4.BACK TO MAIN MENU";
	cout<<"\n\n\t\t\t\t\tPlease Enter Your Choice  ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\n\n\tPlease Enter The Index number "; cin>>num;
			display_sp(num); break;
	case '4':	break;
	default:	cout<<"\a"; entry_menu();
	}
}

