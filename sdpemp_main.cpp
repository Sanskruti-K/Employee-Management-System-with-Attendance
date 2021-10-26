#include<iostream>
#include "sdpemp.cpp"
using namespace std;


void intro()
{
	system("cls");

	cout<<"\n\n\n\n\t\t\t----------------------------------------";
	cout<<"\n\t\t\t****************************************";
	cout<<"\n\n\t\t\t\t Employee Management System";
	cout<<"\n\n\t\t\t\t Version : 1.1";
	cout<<"\n\n\t\t\t****************************************";
	cout<<"\n\t\t\t----------------------------------------";
	getch();

}

int main()
{
	emp e;
 	intro();
 	e.main_menu();

    return 0;
}
    











/*void start()
{
	p:
	system("cls");
	int ch;
	cout<<"\n\n\n\n";
	cout<<"\t\t\t------------------------------------";
	cout<<"\n\n\t\t\t\t Employee Management System";
	cout<<"\n\n\t\t\t\t Version : 1.1";
	cout<<"\n\n\t\t\t-------------------------------------";
	
	cout<<"\n\n\n\t\t\t 1.Login \t 2.Register";
	getch();
}
*/
