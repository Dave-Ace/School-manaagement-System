#include "Student.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

void student::create_student(){
	cout <<"\nEnter Student's Name: ";
	cin.ignore();
	cin.getline(name, 50);
	
	cout <<"\nEnter Student's Registration Number: ";
	cin>>regno;	

	cout <<"\nEnter Student's Class: ";
	cin.ignore();
	cin.getline(Class, 5);
	
	cout <<"\nEnter Student's Age': ";
	cin >> age;
	
	cout <<"\nEnter Student's Date of Birth: ";
	cin.ignore();
	cin.getline(DOB, 10);
	
	cout <<"\n\nAccount Created Successfully..";
}


void student::show_student()const{
	cout <<"\nReg No.: " << regno;
	cout <<"\nStudent's' Name: "<< name;
	cout <<"\nStudent's Age & Date of Birth': "<< age <<" ("<< DOB << ")";
	cout <<"\nStudent's Class': "<< Class;
}

void student::modify(){
	cout <<"\nEnter Student's Name: ";
	cin.ignore();
	cin.getline(name, 50);
	
	cout <<"\nEnter Student's Registration Number: ";
	cin>>regno;	

	cout <<"\nEnter Student's Class: ";
	cin.ignore();
	cin.getline(Class, 5);
	
	cout <<"\nEnter Student's Age': ";
	cin >> age;
	
	cout <<"\nEnter Student's Date of Birth: ";
	cin.ignore();
	cin.getline(DOB, 10);		
}

void student::report()const{
	cout <<regno<<setw(10)<<" "<<name<<setw(17)<<" "
	<<Class<<setw(10)<<age<<endl;
}

void student::payrollreport()const{
	cout <<regno<<setw(6)<<" "<<setw(10)<<name<<setw(14)<<" "
	<<Class<<setw(9)<<age;
}

char student::get_class() const{
	return Class[10];
}

int student::get_age() const{
	return age;
}

double student::get_regno() const{
	return regno;
}

char student::get_name() const{
	return name[50];
}

void student::setStudent(){
	char ch;
		cout << "\n\n\nPRESS THE NUMBER ASSIGNED TO THE DETAIL YOU WANT TO MAKE CHANGES TO ";
		cout << "\n\n\t01. NAME";
		cout << "\n\n\t02. REGISTRATION NUMBER";
		cout << "\n\n\t03. CLASS";
		cout << "\n\n\t04. DATE OF BIRTH";
		cout << "\n\n\t05. AGE";
		cout << "\n\n\t06. EXIT";
		cout << "\n\n\tSelect Your Option(1-6): ";
		cin >> ch;
		switch(ch){
			case '1': cout << "\n\nEnter New Name: ";
				cin.ignore();
				cin.getline(name, 50);
				cout<<"\n\n\tRecord Updated";
				break;
			case '2': cout << "\n\n\tEnter New Registration Number: "; cin >> regno;
				cout<<"\n\n\tRecord Updated";
				break;
			case '3': cout << "\n\n\tEnter New Class: ";
					cin.ignore();
					cin.getline(Class, 5);
					cout<<"\n\n\tRecord Updated";
				break;
			case '4': cout << "\n\n\tEnter New Date of Birth: ";
					cin.ignore();
					cin.getline(DOB, 10);
					cout<<"\n\n\tRecord Updated";
				break;
			case '5': cout <<"\n\n\tEnter New Age: "; cin >> age;
			cout<<"\n\n\tRecord Updated";
				break;
			case '6': cout << "Press Enter to continue";
			default: cout <<"\a";
		}
}
