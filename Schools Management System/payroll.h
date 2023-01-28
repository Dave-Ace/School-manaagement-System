#ifndef _PAYROLL_
#define _PAYROLL_
#include "student.h"
class payroll : public student{
	private:
		char session[10];	//Sessions
		int fee;		//Fee to be paid for the session
		int amtpd;	
		int dep;	//Amount paid for the session
		int balance;
	public:
		int get_fee() const;
		int get_balance() const;
		int get_amtpd() const;
		void show_payroll() const;
		void modify_payroll();
		void create_payroll();
		void pay(int);
		void payroll_report() const;
		void cal(int);
		void check_valid(int);
};

#endif
