#include "payroll.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

void payroll::create_payroll(){
	cout <<"\n\nEnter Session: ";
	cin.ignore();
	cin.getline(session, 10);
	cout <<"\nEnter Session Fee: ";
	cin >> fee;
	cout <<"\nEnter Amount Paid: ";
	cin >> amtpd;
	cal(amtpd);
}

void payroll::cal(int n){
	balance = fee - amtpd;
}

void payroll::check_valid(int n){
	if (n <= balance){
		pay(n);
	}
	else{
		if (balance == 0){
			cout <<"\n\nTransaction Error...Student has no outstanding debt";
		}
		else{
			cout << "\n\nTransaction Error...Payments is more than fee";	
		}
	}
}

void payroll::pay(int n){
		amtpd += n;
		balance = fee - amtpd;
		if (balance == 0){
			cout << "\n\nTransaction Successful...No outstanding debt";
			}
			else{
				cout <<"\n\nTrasaction Successful... ";				
				cout <<"\n\nBalance: " << balance;
		}
}

int payroll::get_fee() const{
	return fee;
}

int payroll::get_amtpd() const{
	return amtpd;
}

int payroll::get_balance()const{
	return balance;
}

void payroll::show_payroll()const{
	cout <<"\nSession': "<< session;
	cout <<"\n\nSession Fee': "<< fee;
	cout <<"\n\nTotal Amount Paid "<< amtpd;
	cout <<"\n\nBalance: "<< balance;
}

void payroll::payroll_report()const{
	cout <<setw(10)<<"  "<< session << setw(10)<<"  "<<fee <<setw(10)<<"  "<<amtpd << setw(13)<<"  "<<balance<<endl;
}

void payroll::modify_payroll(){
	char ch;
		cout << "\n\n\nPRESS THE NUMBER ASSIGNED TO THE DETAIL YOU WANT TO MAKE CHANGES TO ";
		cout << "\n\n\t01. SESSION";
		cout << "\n\n\t02. SCHOOL FEES";
		cout << "\n\n\t03. AMOUNT PAID";
		cout << "\n\n\t04. EXIT";
		cout << "\n\n\tSelect Your Option(1-6): ";
		cin >> ch;
		switch(ch){
			case '1': 	cout <<"\n\nEnter Session: ";
				cin.ignore();
				cin.getline(session, 10);
				cout<<"\n\n\tRecord Updated";
				break;
			case '2':cout <<"\nEnter Session Fee: ";
				cin >> fee;
				cout<<"\n\n\tRecord Updated";
				break;
			case '3': cout <<"\nEnter Amount Paid: ";
				cin >> amtpd;
				cal(amtpd);
				cout<<"\n\n\tRecord Updated";
				break;
			case '4': cout<<"\n\n\tPress enter to continue...";break;
			default: cout <<"\a";
		}
		
}
