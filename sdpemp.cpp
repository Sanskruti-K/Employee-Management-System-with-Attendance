/* Employeee Management System with File Handling C++*/

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cstdlib>
#include<fstream>
#include<string.h>
#include<windows.h>
#include "sdpemp_login.cpp"
using namespace std;



class Employee
{
protected:
    int empid, sal, grpid;
    string name, address,dob;
    string mobno,aadharno;
	string gender,desig;

public:
    void menu();
    void insert();
    void display();
    void search();
    void update();
    void deleterecord();
    void grouprecord();
    void search_group();
    void showAll_group();
    void check_attendance();
    void search_attendance();
    bool validate_empid(int);
 
};

class emp :public Employee
{
	public:
		void admin_login();
		void main_menu(); //main menu at start
		void emp_menu();
		void attendance();
}obj;

bool validate_name(string toCheck)
{
	for (int i = 0; i < toCheck.length(); i++)
		if (isalpha(toCheck[i]) == false)
  		return false;
      
	return true;
}
bool validate_number(string toCheck)
{
  for (int i = 0; i < toCheck.length(); i++)
	if (isdigit(toCheck[i]) == false)
  	return false;
  
  return true;
}

bool Employee :: validate_empid(int eid)
{
	//bool correct;
	int f=0;
	fstream file;
	file.open("emp.txt",ios::in);
	
		file>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
		while(!file.eof())
		{
			if(eid == empid)
			{
				file.close();
				return false;
			}
			file>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
		}
		file.close();
		return true;
	file.close();
} 

void Employee ::menu()
{
    p:
    system("cls"); //system clear screen
    int ch;

    cout<<"\n\n\t\t************* Control Panel *****************";
    cout<<"\n\n\n\t\t\t 1. Insert Record";
    cout<<"\n\t\t\t 2. Display Record";
    cout<<"\n\t\t\t 3. Check Attendance";
    cout<<"\n\t\t\t 4. Search Attendance";
    cout<<"\n\t\t\t 5. Search Record";
    cout<<"\n\t\t\t 6. Update Record";
    cout<<"\n\t\t\t 7. Delete Record";
    cout<<"\n\t\t\t 8. Group Record";  //which emp from which grp ka hai
    cout<<"\n\t\t\t 9. Search Group";
    cout<<"\n\t\t\t 10. Show All Groups";
    cout<<"\n\t\t\t 11. Go Back";
    cout<<"\n\n\t\t\t Enter your choice :";
    cin>>ch;

    switch(ch)
    {
        case 1: insert();
                break;
        case 2: display();
                break;
        case 3: check_attendance();
                break;
        case 4: search_attendance();
                break;
        case 5: search();
                break;
        case 6: update();
                break;
        case 7: deleterecord();
                break;
        case 8: grouprecord();
                break;
        case 9: search_group();
                break;
        case 10: showAll_group();
                break;
        case 11: obj.main_menu();
        		//start();
                //exit(10);  //0 after how many time it takes exit (milisec)
        default :
            cout<<"\n\nInvalid value...Please try again...";
    }
    getch();
    goto p;  //if choice is invalid again to come on this page
}

void Employee ::insert()
{
    system("cls");
    int found=0, testid;
   
    fstream empfile,grpfile,filegid,file1;  //2 files one for emp record one for group record

    cout<<"\n\n\t------------Insert Record--------------";
    cout<<"\n\n\n\t\tEnter Employee ID :";
    cin>>empid;
    int id = empid;
    while(1)
	{
		if(!validate_empid(id))
   		{
			cout<<"\n\t\t\tEmployee ID should be unique..";    
			cout<<"\n\n\t\tEnter Employee ID :";	
        	cin>>id;
		}
   	    else
   	    	break;
	}
	empid=id;
    //cout<<empid;
    cout<<"\n\t\tEnter Employee Name :";
    cin>>name;
    while(1)
	{
		if(!validate_name(name))
   	 	{
    	  cout<<"\n\t\t\tName must contains alphabets only... ";
	   	  cout<<"\n\t\tEnter Employee name :";
    	  cin>>name;
		}
		else	//if(validate_name(name))
	  	break;
	}
    
    cout<<"\n\t\tEnter Employee's Designation :";
    cin>>desig;
    cout<<"\n\t\tEnter Employee Salary :";
    cin>>sal;
    cout<<"\n\t\tEnter Employee Address :";
    cin>>address;
    cout<<"\n\t\tEnter Date of Birth(dd/mm/yyyy) :";
    cin>>dob;
    cout<<"\n\t\tEnter Employee Gender(M/F) :";
    cin>>gender;
    cout<<"\n\t\tEnter Employee Group ID :";
    cin>>grpid;
    cout<<"\n\t\tEnter Employee's Mobile No.(10 digit) :";
    cin>>mobno;
    while(1)
	{
		if(!validate_number(mobno))
   	 	{
    		cout<<"\n\t\t\tMobile number must contains numbers only... ";
			cout<<"\n\t\tEnter Employee Mobile No. :";
    		cin>>mobno;
		}
		else//if(validate_mobno(mobno))
		break;
	}
    cout<<"\n\t\tEnter Employee's AAdhar No. :";
    cin>>aadharno;
    while(1)
	{
		if(!validate_number(aadharno))
   	 	{
    		cout<<"\n\t\t\tAadhar number must contains numbers only...";
			cout<<"\n\t\tEnter Employee's AAdhar No. :";
    		cin>>aadharno;
		}
		else//if(validate_mobno(mobno))
		break;
	}
    
    empfile.open("emp.txt",ios::out|ios::app); //out -write file
    empfile<<" "<<empid<<" "<<name<<" "<<desig<<" "<<sal<<" "<<address<<" "<<dob<<" "<<gender<<" "<<grpid<<" "<<mobno<<" "<<aadharno<<"\n"; //to enter record in emp file
    empfile.close();

    grpfile.open("grpemp.txt",ios::out|ios::app);
    grpfile<<" "<<grpid<<" "<<empid<<" "<<name<<" "<<desig<<" "<<sal<<" "<<mobno<<"\n";    //to enter record in grpemp file
    grpfile.close();
	
	filegid.open("groupid.txt",ios::in);
	if(!filegid)
	{
		file1.open("groupid.txt",ios::app | ios::out);
		file1<<" "<<grpid<<"\n";
		file1.close();
	}
	else
	{
		filegid>>testid;
		while(!filegid.eof())
		{
			if(testid == grpid)
			found++;
			filegid>>testid;
		}
		filegid.close();
		if(found==0)
		{
			file1.open("groupid.txt",ios::app | ios::out);
			file1<<" "<<grpid<<"\n";
			file1.close();
		}
	}
	
    cout<<"\n\n\t\t\t\t**New Record inserted Successfully....";
}

void Employee ::display()
{
    system("cls");
    fstream empfile;
    cout<<"\n\n\t\t-------------------------------------------------Display Record--------------------------------------------------------";
    cout<<"\n\n\n\t\tEmp_ID\t Name\t Designation  Salary\t  Address\t DOB\t    Gender     Group_ID   Mobile_No.\t Aadhar_No.\n\n";

    empfile.open("emp.txt",ios::in);  //in -read file
    if(!empfile)
    {
        cout<<"\n\n\t\t\t File Opening error...";
        getch();
        menu();
    }
    empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;

    while(!empfile.eof()) //end of file return 1 when end
    {
        cout<<"\n\t\t"<<empid<<"\t"<<name<<"\t"<<desig<<"\t\t"<<sal<<"\t"<<address<<"\t\t"<<dob<<"\t"<<gender<<"\t"<<grpid<<"\t"<<mobno<<"\t"<<aadharno<<endl;

        empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
    }
    empfile.close();
    
}

void Employee ::search()
{
	system("cls");
	fstream empfile;
	int eid, found=0; //found = 0,1 to get record or not 
	cout<<"\n\n\t-----------------Search Record---------------------";
	
	empfile.open("emp.txt", ios::in);
	if(!empfile)
	{
		cout<<"\n\n\n\t\t\tFile opening Error...";
		//getch(); //to wait for my cmd
		//menu();
	}
	else
	{
	cout<<"\n\n\t\tEnter Employee ID for search :";
	cin>>eid;
	
	empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
    while(!empfile.eof()) //end of file return 1 when end
    {
    	if(empid == eid)
    	{
    		system("cls");
    		cout<<"\n\n\t---------------------Search Record---------------------";
    		cout<<"\n\n\t\tEMployee ID :"<<empid;
        	cout<<"\n\t\tEMployee Name :"<<name;
        	cout<<"\n\t\tEmployee Designation :"<<desig;
        	cout<<"\n\t\tEMployee Salary :"<<sal;
        	cout<<"\n\t\tEMployee Adress :"<<address;
        	cout<<"\n\t\tEMployee DOB :"<<dob;
        	cout<<"\n\t\tEmployee Gender :"<<gender;
        	cout<<"\n\t\tEMployee Group ID :"<<grpid;
        	cout<<"\n\t\tEMployee Mobile No. :"<<mobno;
			cout<<"\n\t\tEMployee Aadhar No. :"<<aadharno;
        	
        	found++;
		}
        empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
    }
    empfile.close();
    if(found == 0)
	cout<<"\n\n\t\t\t Employee ID cannot found...";
	}
}

void Employee :: update()
{
	system("cls");
	fstream empfile, grpfile,file1,file2; //file1 file2 for new file to put old record their
	int eid,s,found=0;
	string n, add,mob,des;
	
	cout<<"\n\n\t-------------------Update Record-------------------";
	empfile.open("emp.txt",ios::in);
	grpfile.open("grpemp.txt", ios::in);
	if(!empfile || !grpfile)
	{
		cout<<"\n\n\t\tFile opening error...";
		getch();
		menu();
	}
	cout<<"\n\n\t\tEnter Employee ID for Update Record :";
	cin>>eid;
	
	file1.open("newemp.txt",ios::app |ios::out);
	empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
	
	while(!empfile.eof())
	{
		if(eid==empid)
		{
			system("cls");
			cout<<"\n\n\t------------------Modify Record-------------------";
    		cout<<"\n\n\n\t\tEnter Employee Name :";
    		cin>>n;
    		while(1)
			{
				if(!validate_name(n))
   	 			{
    				cout<<"\n\t\t\tName must contains alphabets only... ";
					cout<<"\n\t\tEnter Employee name :";
    				cin>>n;
				}
				else
				break;
			}
			cout<<"\n\t\tEnter Employee Designation :";
			cin>>des;
    		cout<<"\n\t\tEnter Employee Salary :";
    		cin>>s;
    		cout<<"\n\t\tEnter Employee Address :";
    		cin>>add;
    		cout<<"\n\t\tEnter Employee Mobile No. :";
    		cin>>mob;
    		while(1)
			{
				if(!validate_number(mob))
   	 			{
    				cout<<"\n\t\t\tMobile number must contains numbers only... ";
					cout<<"\n\t\tEnter Employee Mobile No. :";
   					cin>>mob;
				}
				else//if(validate_mobno(mob))
				break;
			}
    		
    		file1<<" "<<empid<<" "<<n<<" "<<des<<" "<<s<<" "<<add<<" "<<dob<<" "<<gender<<" "<<grpid<<" "<<mob<<" "<<aadharno<<"\n";
    		found++;
		}
		else
			file1<<" "<<empid<<" "<<name<<" "<<desig<<" "<<sal<<" "<<address<<" "<<dob<<" "<<gender<<" "<<grpid<<" "<<mobno<<" "<<aadharno<<"\n";
			
		empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
	}
	empfile.close();
	file1.close();
	remove("emp.txt");
	rename("newemp.txt","emp.txt");
	
	file2.open("newgrp.txt",ios::app|ios::out);
	grpfile>>grpid>>empid>>name>>desig>>sal>>mobno;
	while(!grpfile.eof())
	{
		if(eid==empid)
		file2<<" "<<grpid<<" "<<empid<<" "<<n<<" "<<des<<" "<<s<<" "<<mob<<"\n";
		else
		file2<<" "<<grpid<<" "<<empid<<" "<<name<<" "<<desig<<" "<<sal<<" "<<mobno<<"\n";
		
		grpfile>>grpid>>empid>>name>>desig>>sal>>mobno;
	}
	grpfile.close();
	file2.close();
	remove("grpemp.txt");
	rename("newgrp.txt","grpemp.txt");
	
	if(found==0)
	cout<<"\n\n\t\tEmpoyee ID cannot found...";
	else
	cout<<"\n\n\t\t\t**Record Updated Successfully....";
}

void Employee ::deleterecord()
{	
	system("cls");
	int eid,found=0;
	char ch;
	fstream empfile, grpfile, file1, file2;
	
	cout<<"\n\n\t-------------------Delete Record-------------------";
	empfile.open("emp.txt",ios::in);
	grpfile.open("grpemp.txt",ios::in);
	
	if(!empfile || !grpfile)
	{
		cout<<"\n\n\t\t\t File opening error....";
		getch();
		menu();
	}
	cout<<"\n\n\t\t Enter Employee ID to delete Record :";
	cin>>eid;
	
	file1.open("newemp.txt",ios::out | ios::app);
	empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
	while(!empfile.eof())
	{
		if(eid==empid)
		{
			system("cls");
			cout<<"\n\n\t\tEMployee ID :"<<empid;
        	cout<<"\n\t\tEMployee Name :"<<name;
        	cout<<"\n\t\tEmployee Designation :"<<desig;
        	cout<<"\n\t\tEMployee Adress :"<<address;
        	cout<<"\n\t\tEmployee Gender :"<<gender;
        	cout<<"\n\t\tEMployee Group ID :"<<grpid;
        	cout<<"\n\t\tEMployee Mobile No. :"<<mobno;
        	cout<<"\n\n\t\tConfirm Do you want to delete (y/n):";
        	cin>>ch;
        	
        	if(ch=='y' || ch=='Y'){
        		cout<<"\n\n\t\t\t**Record deleted successfully....";
				found++;
			}	
			if(ch=='n' || ch=='N'){
        		cout<<"\n\n\t\t\t**Record Not deleted....";	
				found++;
				goto S;			
			}		
		}
		else
		S: file1<<" "<<empid<<" "<<name<<" "<<desig<<" "<<sal<<" "<<address<<" "<<dob<<" "<<gender<<" "<<grpid<<" "<<mobno<<" "<<aadharno<<"\n";
		
		empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
	}
	empfile.close();
	file1.close();
	remove("emp.txt");
	rename("newemp.txt","emp.txt");
	
	file2.open("newgrp.txt",ios::out |ios::app);
	grpfile>>grpid>>empid>>name>>desig>>sal>>mobno;
	while(!grpfile.eof())
	{
		if(eid==empid && ch =='n'|| ch == 'N')
		file2<<" "<<grpid<<" "<<empid<<" "<<name<<" "<<desig<<" "<<sal<<" "<<mobno<<"\n";
		
		if(eid != empid)
		file2<<" "<<grpid<<" "<<empid<<" "<<name<<" "<<desig<<" "<<sal<<" "<<mobno<<"\n";
		
		grpfile>>grpid>>empid>>name>>desig>>sal>>mobno;
	}
	grpfile.close();
	file2.close();
	remove("grpemp.txt");
	rename("newgrp.txt","grpemp.txt");
	
	if(found==0)
	cout<<"\n\n\t\tEmpoyee ID cannot found...";
}

void Employee ::grouprecord()
{
	system("cls");
	fstream grpfile;
	
	cout<<"\n\n\t\t------------------------Group Record---------------------------";
	cout<<"\n\n\n\t\tGroup_ID Emp_ID Name   Designation   Salary   Mobile_No.\n\n";
	grpfile.open("grpemp.txt",ios::in);
	if(!grpfile)
	{
		cout<<"\n\n\t\t\tFile opening error...";
		getch();
		menu();
	}
	
	grpfile>>grpid>>empid>>name>>desig>>sal>>mobno;
	while(!grpfile.eof())
	{
		cout<<"\n\t\t"<<grpid<<"\t"<<empid<<"\t"<<name<<"\t"<<desig<<"\t\t"<<sal<<"\t"<<mobno;
		
		grpfile>>grpid>>empid>>name>>desig>>sal>>mobno;
	}	
	grpfile.close();
}

void Employee ::search_group()
{
	system("cls");
	int gid,found=0,emp_count=0, sal_count=0;
	fstream grpfile;
	
	cout<<"\n\n\t\t---------------------Search Group Record---------------------";
	grpfile.open("grpemp.txt",ios::in);
	if(!grpfile)
	{
		cout<<"\n\n\t\t\tFile opening error...";
		getch();
		menu();
	}
	cout<<"\n\n\t\t\t Enter Group_ID for search : ";
	cin>>gid;
	system("cls");
	cout<<"\n\n\t\t---------------------Search Group Record----------------------";
	
	grpfile>>grpid>>empid>>name>>desig>>sal>>mobno;
	while(!grpfile.eof())
	{
		if(gid==grpid)
		{
			cout<<"\n\n\t\tGroup ID :"<<gid;
			cout<<"\n\t\tEmployee ID :"<<empid;
			cout<<"\n\t\tName :"<<name;
			cout<<"\n\t\tDesignation :"<<desig;
			cout<<"\n\t\tSalary :"<<sal;
			cout<<"\n\t\tMobile No. :"<<mobno;
			found++;			
			emp_count++;
			sal_count = sal_count+sal;	
		}
		grpfile>>grpid>>empid>>name>>desig>>sal>>mobno;	
	}
	grpfile.close();
	if(found != 0)
	{
		cout<<"\n\n\t\tGroupID :"<<gid;
		cout<<"\n\t\tTotal Employees in group :"<<emp_count;
		cout<<"\n\t\tTotal Salary : "<<sal_count;
	}
	else
	cout<<"\n\n\t\t\tGroup_ID is not found...";
}

void Employee::showAll_group()
{
	system("cls");
	int gid, emp_count=0, sal_count=0, total_emp=0, total_sal=0;
	fstream grpfile, file;
	cout<<"\n\n\t\t----------------Show All Groups------------------";
	
	file.open("groupid.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n\t\t\t File Opening error...";
		getch();
		menu();
	}
	file>>gid;
	while(!file.eof())
	{
		grpfile.open("grpemp.txt",ios::in);
		grpfile>>grpid>>empid>>name>>desig>>sal>>mobno;
		while(!grpfile.eof())
		{
			if(gid==grpid)
			{
				emp_count++;
				sal_count += sal;
				total_emp++;
				total_sal +=sal;
				
			}
			grpfile>>grpid>>empid>>name>>desig>>sal>>mobno;	
		}
		grpfile.close();
		cout<<"\n\n\n\t\tGroup ID : "<<gid;
		cout<<"\n\t\tTotal Employee : "<<emp_count;
		cout<<"\n\t\tTotal Salary : "<<sal_count;
		emp_count =0;
		sal_count =0;
		
		file>>gid;
	}
	file.close();
	cout<<"\n\n\n\t\tOver All Employee in organaization :"<<total_emp;
	cout<<"\n\t\tOver All salary of all employee :"<<total_sal;
}

void Employee::check_attendance()
	{
		system("cls");
		fstream file,empfile;
		int d,m,y,a_date,a_month,a_year,eid,count=0;
		cout<<"\n\n\t\t---------------------Check Employee Attendence--------------------------";
		empfile.open("emp.txt",ios::in);
		file.open("emp_attendance.txt",ios::in);
		if(!empfile || !file)
		{
			cout<<"\n\n\t\t **File Opening Error...";
		}
		else
		{
			cout<<"\n\n\t\t\t Date : ";
			cin>>d;
			cout<<"\n\t\t\t Month : ";
			cin>>m;
			cout<<"\n\t\t\t Year : ";
			cin>>y;
			file.close();
			system("cls");
			cout<<"\n\n\t\t--------------Check Employee Attendance-------------------";
			cout<<"\n\n\t\t\t Employee ID\t Presents   Date";//\tAbsents";
			
			empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
			while(!empfile.eof())
			{
				file.open("emp_attendance.txt",ios::in);
				file>>eid>>a_date>>a_month>>a_year;
				while(!file.eof())
				{
					if(empid == eid && d <= a_date && m == a_month && y == a_year)
					{
						count++;    //no. of present emp
						cout<<"\n\n\t\t\t   "<<empid<<"\t\t"<<count<<"\t\t"<<a_date<<"-"<<a_month<<"-"<<a_year<<"\n";//count<<"\t\t";//<<30-count;
					}
					count=0;
					file>>eid>>a_date>>a_month>>a_year;
				}
				file.close();
				//cout<<"\n\n\t\t\t   "<<empid<<"\t\t\t"<<count<<"\t\t";//<<30-count;   //30-count fr no. of absent emp
				//count=0;
				empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
			}
			empfile.close();
		}
	}

void Employee::search_attendance()
{
		system("cls");
		fstream file,empfile;
		int d,m,y,a_id,a_date,a_month,a_year,count=0,eid;
		cout<<"\n\n\t\t-------------------Search Employee Attendence---------------------------";
		empfile.open("emp.txt",ios::in);
		file.open("emp_attendance.txt",ios::in);
		if(!file || !empfile)
			cout<<"\n\n\t\t **File Opening Error...";
		else
		{
			cout<<"\n\n\t\t\t Employee ID : ";
			cin>>eid;
			cout<<"\n\t\t\t Date : ";
			cin>>d;
			cout<<"\n\t\t\t Month : ";
			cin>>m;
			cout<<"\n\t\t\t Year : ";
			cin>>y;
			//empfile.close();
			system("cls");
			cout<<"\n\n\t\t----------------------Check Employee Attendence----------------------";
			cout<<"\n\n\t\t\t Employee ID \tPresent";
			file>>a_id>>a_date>>a_month>>a_year;
			while(!file.eof())
			{
				if(a_id == eid && d == a_date && m == a_month && y == a_year)
				{
					count++;    //no. of present emp
					cout<<"\n\n\t\t\t   "<<eid<<"\t\t"<<count<<"\t\t"<<a_date<<"-"<<a_month<<"-"<<a_year<<"\n";
				}
		
				file>>a_id>>a_date>>a_month>>a_year;
			}
			file.close();
			if(count == 0)
				cout<<"\n\n\t\t\t\t **Employee ID Not found for attendance...";
		}
}



void emp ::main_menu()
{
	p:	
	int ch;
	system("cls");
	
	cout<<"\n\n\t\t******************************";
	cout<<"\n\n\t\t\t       Menu";
	cout<<"\n\n\t\t******************************";
	cout<<"\n\n\t\t1. Admin";
	cout<<"\n\t\t2. Employee";
	cout<<"\n\t\t3. Exit";
	
	cout<<"\n\n\t\t\t Enter your choice :";
    cin>>ch;

    switch(ch)
    {
        case 1: admin_login();
                break;
        case 2: start(); // for emplogin
				emp_menu();
                break;
        case 3: exit(10);
        default :
			cout<<"\n\n\t\tInvalid choice...Please try again...";
	}
	getch();
	goto p;
}

void emp::admin_login()
{
	p:
	system("cls");
	string uname,pass;
	cout<<"\n\n\n\n";
	cout<<"\t\t\t--------------------------------------";
	cout<<"\n\n\t\t\t\t   Login Process";
	cout<<"\n\n\t\t\t--------------------------------------";
	cout<<"\n\n\n\t\t\t Enter Username : ";
	cin>>uname;
	cout<<"\n\n\t\t\t Enter Password : ";
	
	for(int i=0;i<5; i++)
	{
		char ch = getch();
		pass += ch;
		cout<<"*";	
	}
	if(uname=="admin" && pass=="admin")
	{
		cout<<"\n\n\n\t\t\t Congratulations..Login Successfully..";
		cout<<"\n\n\n\t\t\t\t\t Loading";
		for(int i=1; i<=6; i++)
		{
			Sleep(500); //1000 ms = 1sec
			cout<<".";
		}
		Employee::menu(); //  admin menu
	}
	else if(uname!="admin" && pass=="admin")
			{
				cout<<"\n\n\n\t\t\t **Invalid Username...";
				getch(); //to wait command
				goto p;
			}
			else if(uname =="admin" && pass != "admin")
				{
					cout<<"\n\n\n\t\t\t **Invalid Password...";
					getch(); //to wait command
					goto p;
				}
				else
					cout<<"\n\n\t\t\t **Invalid username and password...";
	
	getch();
	goto p;
}

void emp::emp_menu()
{
	p:	
	int ch;
	system("cls");
	
	cout<<"\n\n\t\t******************************";
	cout<<"\n\n\t\t\t Employee Menu";
	cout<<"\n\n\t\t******************************";
	cout<<"\n\n\t\t1. Attendance";
	cout<<"\n\t\t2. Employee's Check detail'";
	cout<<"\n\t\t3. Employee's Update profile";
	cout<<"\n\t\t4. Go Back";
	
	cout<<"\n\n\t\t\t Enter your choice :";
    cin>>ch;

    switch(ch)
    {
        case 1: attendance();
                break;
        case 2: Employee::search();
                break;
        case 3: Employee::update();
        		break;
        case 4: main_menu(); 
        default :
			cout<<"\n\n\t\tInvalid choice...Please try again...";
	}
	getch();
	goto p;
}

void emp::attendance()
{
	system("cls");
	fstream empfile,file;
	int eid,found=0,count=0; 
	int atten_date,atten_month,atten_year,atten_id; //atten_id for getting value from emp_attend file
	SYSTEMTIME time; //current time of system
	cout<<"\n\n\t\t\t-------------------Employee Attendance------------------------";
	empfile.open("emp.txt",ios::in);  //in -read file
    if(!empfile)
   		cout<<"\n\n\t\t\t File Opening error...";
    else
    {
    	cout<<"\n\n\t\t\t Employee ID :";
    	cin>>eid;
    	
    	empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
    	while(!empfile.eof())
    	{
    		if(eid==empid)
    		found++;
    		
    		empfile>>empid>>name>>desig>>sal>>address>>dob>>gender>>grpid>>mobno>>aadharno;
		}
		empfile.close();
		if(found != 0)
		{
			GetSystemTime(&time); //get the system current time
			file.open("emp_attendance.txt",ios::in);
			if(!file) //!file
			{
				file.open("emp_attendance.txt",ios::app|ios::out);
				file<<" "<<eid<<" "<<time.wDay<<" "<<time.wMonth<<" "<<time.wYear<<"\n";
				file.close();
				cout<<"\n\n\t\t\t\t Your attendance Added Successfully";
			}
			else
			{
				//check here that emp doesn't mark attendace for same day many times
				file>>atten_id>>atten_date>>atten_month>>atten_year; 
				while(!file.eof())
				{
					if(eid==atten_id && atten_date == time.wDay && atten_month == time.wMonth && atten_year == time.wYear)
					{ 
					  cout<<"\n\n\t\t\t\t Your Attendance already Added...";
					  count++;
					}
					file>>atten_id>>atten_date>>atten_month>>atten_year;
				}
				file.close();
				if(count == 0) //if he mark 1st time attendance when file exist
				{	
					file.open("emp_attendance.txt",ios::app|ios::out);
					file<<" "<<eid<<" "<<time.wDay<<" "<<time.wMonth<<" "<<time.wYear<<"\n";
					file.close();
					cout<<"\n\n\t\t\t\t Your attendance Added Successfully";
				}
			}
		}
		else
			cout<<"\n\n \t\t\t **Invalid Employee ID...";
	}
}
