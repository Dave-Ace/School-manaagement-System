#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <iomanip>
#include "payroll.h"
#include "Student.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void intro();
void write_account();
void modify_account(int);
void student_acc(int);
void create_fee_account(int);
void modify_fee(int);
void display_account();
void display_all();
void delete_student(int);
void Payfee(int);

int main(int argc, char** argv) {
	char ch;
	int reg;
	intro();
	do{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. NEW STUDENT";
		cout << "\n\n\t02. MODIFY STUDENT";
		cout << "\n\n\t03. CREATE STUDENT FEE ACCOUNT";
		cout << "\n\n\t04. MODIFY STUDENT FEE ACCOUNT";
		cout << "\n\n\t05. ALL STUDENT LIST";
		cout << "\n\n\t06. ALL STUDENT ACCOUNT LIST";
		cout << "\n\n\t07. DELETE STUDENT";
		cout << "\n\n\t08. CHECK STUDENT DETAILS";
		cout << "\n\n\t09. PAY SCHOOL FEE";
		cout << "\n\n\t00. EXIT";
		cout << "\n\n\tSelect Your Option(0-9): ";
		cin >> ch;
		system("cls");
		switch(ch){
			case '1': write_account();
				break;
				
			case '2': cout << "\n\n\tEnter Student Registration No.: "; cin >> reg;
				modify_account(reg);
				break;
				
//			case '3': cout << "\n\n\tEnter Student Registration No.: "; cin >> reg;
//				create_fee_account(reg);
//				break;
				
			case '4': cout << "\n\n\tEnter Student Registration No.: "; cin >> reg;
				modify_fee(reg);
				break; 
				
			case '5': display_all();
				break;
				
			case '6': display_account();
				break;
				
			case '7': cout << "\n\n\tEnter Student Registration No.: "; cin >> reg;
				delete_student(reg);
				break;

			case '8': cout << "\n\n\tEnter Student Registration No.: "; cin >> reg;
				student_acc(reg);
				break;
			
			case '9':  cout << "\n\n\tEnter Student Registration No.: "; cin >> reg;
				Payfee(reg);
				break;
			case '0': cout << "\n\n\tThanks for Using Daivy SChool Management System";
			default: cout <<"\a";
		}
		cin.ignore();
		cin.get();
	}while(ch!='0');
	return 0;
}

void write_account(){
	payroll ac;
	ofstream outFile;
	outFile.open("Student.dat", ios::binary|ios::app);
	ac.create_student();
	ac.create_payroll();
	cout <<"\n\nPayroll for "<<ac.get_regno()<<" Created Successfully..";
	outFile.write(reinterpret_cast<char*>(&ac), sizeof(payroll));
		outFile.close();
	
}

void create_fee_account(int reg){
	bool found=false;
	payroll ac;
	fstream File;
	File.open("Student.dat", ios::binary|ios::in|ios::out);
	if(!File){
			cout <<"File could not be open !! Press any key...";
			return;
		}
		while(!File.eof() && found ==false){
			File.read(reinterpret_cast<char*> (&ac), sizeof(payroll));		
			if(ac.get_regno()==reg){
				ac.show_student();
				ac.show_payroll();
				cout << "\n\n";
				cout <<"Add New Fee";
				ac.create_payroll();
				int pos=(-1)*static_cast<int>(sizeof(payroll));
				File.seekp(pos,ios::cur);		
				File.write(reinterpret_cast<char*>(&ac), sizeof(payroll));
				cout<<"\n\n\tRecord Updated";
				found=true;
			}
			
		}

		File.close();
		if(found==false)
		cout <<"\n\nRecord not Found";

}


void modify_account(int n){
	bool found=false;
	payroll ac;
	fstream File;
	File.open("Student.dat", ios::binary|ios::in|ios::out);
		if(!File){
			cout <<"File could not be open !! Press any key...";
			return;
		}
		while(!File.eof() && found==false){
			File.read(reinterpret_cast<char*> (&ac), sizeof(payroll));
			if(ac.get_regno()==n){
				ac.show_student();
				ac.setStudent();
				int pos=(-1)*static_cast<int>(sizeof(payroll));
				File.seekp(pos,ios::cur);
				File.write(reinterpret_cast<char*>(&ac), sizeof(payroll));
				
				found=true;
			}
		}
		File.close();
		if(found==false)
		cout <<"\n\nRecord not Found";
}

void display_all(){
	payroll ac;
	ifstream inFile;
	
	inFile.open("Student.dat", ios::binary);
	if(!inFile){
		cout <<"File could not be open !! Pres any key...";
		return;
	}
	cout <<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "======================================================\n";
	cout << "A/c no.     \t   NAME"<<setw(17)<<"  "<<"CLASS"<<setw(6)<<"  "<<"AGE\n"; 
	cout << "======================================================\n";
	while(inFile.read(reinterpret_cast<char*>(&ac), sizeof(payroll))){
			ac.report();
		}
		inFile.close();
}

void display_account(){
	payroll ac;
	ifstream inFile;
	
	inFile.open("Student.dat", ios::binary);
	if(!inFile){
		cout <<"File could not be open !! Press any key...";
		return;
	}
	cout <<"\n\n\t\tSTUDENT ACCOUNT LIST\n\n";
	cout << "===================================================================================================================\n";
	cout << "Reg no.  \t NAME"<<setw(17)<<"  "<<"CLASS" <<setw(6)<<"  "<<"AGE" <<setw(9)<<"  "<< "SESSION" << setw(10)<<"  "<<"FEE" <<setw(9)<<"  "<<"AMOUNT PAID" << setw(6)<<"  "<<"BALANCE\n";
	cout << "===================================================================================================================\n";
	while(inFile.read(reinterpret_cast<char*>(&ac), sizeof(payroll))){
			ac.payrollreport();
			ac.payroll_report();
			}
		inFile.close();
}

void student_acc(int reg){
	payroll ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("Student.dat", ios::binary);
	if(!inFile){
		cout << "File could not be open !! Press any key...";
			return;
	}
	cout << "\nPAYROLL DETAILS\n";
	while(inFile.read(reinterpret_cast<char*>(&ac), sizeof(payroll)))
	{
		if(ac.get_regno()==reg){
			ac.show_student();
			ac.show_payroll();
			
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
	cout << "\n\nStudent with Registration Number does not exist";
}

void delete_student(int reg){
	payroll ac;
	ifstream inFile;
	ofstream outFile;
	
	inFile.open("Student.dat", ios::binary);
	if(!inFile){
		cout<<"File could not be open !! Press any key...";
		return;
	}
	outFile.open("Temp.dat", ios::binary);
		inFile.seekg(0,ios::beg);
		while(inFile.read(reinterpret_cast<char*>(&ac), sizeof(payroll))){
			if(ac.get_regno()!=reg){
				outFile.write(reinterpret_cast<char*>(&ac), sizeof(payroll));
			}
		}
		inFile.close();
		outFile.close();
		remove("Student.dat");
		rename("Temp.dat", "Student.dat");
		cout<<"\n\n\tRecord Deleted..";
}

void modify_fee(int reg){
	bool found=false;
	payroll ac;
	fstream File;
	File.open("Student.dat", ios::binary|ios::in|ios::out);
		if(!File){
			cout <<"File could not be open !! Press any key...";
			return;
		}
		while(!File.eof() && found==false){
			File.read(reinterpret_cast<char*> (&ac), sizeof(payroll));
			if(ac.get_regno()==reg){
				ac.show_student();
				ac.show_payroll();
				ac.modify_payroll();
				int pos=(-1)*static_cast<int>(sizeof(payroll));
				File.seekp(pos,ios::cur);
				File.write(reinterpret_cast<char*>(&ac), sizeof(payroll));
				found=true;
			}
		}
		File.close();
		if(found==false)
		cout <<"\n\nRecord not Found";
}

void Payfee(int reg){
	bool found=false;
	int pay;
	payroll ac;
	fstream File;
	File.open("Student.dat", ios::binary|ios::in|ios::out);
		if(!File){
			cout <<"File could not be open !! Press any key...";
			return;
		}
		while(!File.eof() && found==false){
			File.read(reinterpret_cast<char*> (&ac), sizeof(payroll));
			if(ac.get_regno()==reg){
				ac.show_student();
				ac.show_payroll();
				cout << "\n\nEnter Amount to Pay: ";
				cin >> pay;
				ac.check_valid(pay);
				int pos=(-1)*static_cast<int>(sizeof(payroll));
				File.seekp(pos,ios::cur);
				File.write(reinterpret_cast<char*>(&ac), sizeof(payroll));
				found=true;
			}
		}
		File.close();
		if(found==false)
		cout <<"\n\nRecord not Found";
	
}

void intro(){
	cout<<"\n\n\n\t\t=========================================================";
	cout<<"\n\t\t***************\t     DAIVY   SCHOOL\t*****************";
	cout<<"\n\t\t****************       MANAGEMENT      ******************";
	cout<<"\n\t\t*****************\tSYSTEM\t      *******************";
	cout<<"\n\t\t=========================================================";
	cin.get();	
}


