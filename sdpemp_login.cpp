#include<iostream>
#include<conio.h>
#include<fstream>


using namespace std;


void emplogin();
void registration();

void start()
{
	p:
	system("cls");
	int ch;
	cout<<"\n\n\n\n";
	cout<<"\t\t\t------------------------------------";
	cout<<"\n\n\t\t\t\t Employee Management System";
	cout<<"\n\n\t\t\t\t Version : 1.1";
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\t\t **Employee Panel**";
	cout<<"\n\n\t\t\t-------------------------------------";
	
	cout<<"\n\n\n\t\t\t 1.Login \t 2.Register \t 3.Exit";
	//getch();

	cout<<"\n\n\n\t\t\t Enter ur preference:";
	cin>>ch;
	switch(ch)
	{
		case 1:emplogin();
			break;
		case 2:registration();
			goto p;
		case 3:exit(10);
		default:cout<<"\n\t\t\t\tInvalid...";
		
		goto p;
	}
	
	getch();
		
}
void emplogin()
{
	p:
	system("cls");
	char ch;
	int i;
	string uname,pass,username,password;
	fstream file;
	file.open("login.txt",ios::in);	
	
	cout<<"\n\n\n\n";
	cout<<"\t\t\t--------------------------------------";
	cout<<"\n\n\t\t\t\t   Login Process";
	cout<<"\n\n\t\t\t--------------------------------------";
 	cout<<"\n\n\t\t\t Enter Username : ";
	cin>>uname;
	cout<<"\n\n\t\t\t Enter Password : ";
	for(i=0;i<7; i++)
	{
		ch = getch();
		pass += ch;
		cout<<"*";	
	}
	file>>username>>password;
	while(!file.eof())
	{
		if(uname==username && pass==password)
		{
			cout<<"\n\n\n\t\t\t Congratulations..Login Successfully..";
			cout<<"\n\n\n\t\t\t\t\t Loading";
			for(int i=1; i<=6; i++)
			{
				Sleep(500); //1000 ms = 1sec
				cout<<".";
			}
			//emp::emp_menu(); // new vdo for atten
			return;
		}
		else 
			if(uname !=username && pass == password)
			{
				cout<<"\n\n\n\t\t\t **Invalid Username...";
				getch(); //to wait command
				goto p;
			}
			else if(uname ==username && pass != password)
				{
					cout<<"\n\n\n\t\t\t **Invalid Password...";
					getch(); //to wait command
					goto p;
				}
				 
			file>>username>>password;
	}
	file.close();
	cout<<"\n\n\t\t\t **Invalid Username and Password...";
	getch();
	//goto p;
	start();
}

bool validate_pass(string tocheck)
{
	int f=0,p=0,z=0;
	for(int i=0; i<tocheck.length(); i++)
	{
		if(tocheck[i] >= 48 && tocheck[i]<= 57)
		f++;
		if((tocheck[i] >= 65 && tocheck[i] <= 90) || (tocheck[i] >= 97 && tocheck[i] <= 122))
		p++;
		if(tocheck[i]=='@' || tocheck[i] =='$' || tocheck[i]=='#' || tocheck[i]=='&')
		z++;
	}
	if(f>0 && p>0 && z>0)
	return true;
	else
	return false;
	
}
void registration()
{
	system("cls");
	int empid, sal, grpid,eid,found=0;
    string name, address,dob;
    string mobno,aadharno;
	string gender,desig;
	string username,password;
	fstream file,empfile;
	
	empfile.open("emp.txt",ios::in);
	
	cout<<"\n\n\n\n";
	cout<<"\t\t\t--------------------------------------";
	cout<<"\n\n\t\t\t\t   Register Process";
	cout<<"\n\n\t\t\t--------------------------------------";
	cout<<"\n\n\n\t\t\t Enter Employee ID:";
	cin>>eid;

	empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
    while(!empfile.eof()) //end of file return 1 when end
    {
    	if(eid == empid)
    	{
    		found++;
			cout<<"\n\n\t\t\t\t Set username :";
			cin>>username;
			cout<<"\n\t\t\t\t Set password :";
			cin>>password;
			while(1)
			{
				if(!validate_pass(password))
				{
					cout<<"\n\tPassword must contains numbers, one special symbol, alphabets only..";
					cout<<"\n\t\t\t\t Set password :";
					cin>>password;
				}
				else
				break;
			}
	
			file.open("login.txt",ios::out | ios::app);	
			file<<" "<<username<<" "<<password<<"\n";
			file.close();
		
			cout<<"\n\n\t\t\t\t **Registration Successfully....";
			getch();
			return;
		}
		empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
	}
	empfile.close();
    if(found == 0)
	cout<<"\n\n\t\t\t Employee ID cannot found...";	
	getch();
	return;
}



