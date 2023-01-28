#ifndef _STUDENT_
#define _STUDENT_

class student{
	private:
		char name[50]; 	//Student name
		double regno;		//Student Registration number
		char Class[5];		//Student Class
		int age;		//Student Age
		char DOB[10];		// Student Date of Birth
	public:
		void create_student();
		void setName(char n[50]);
		void setReg(int r);
		void setClass(char c);
		void setAge(int A);
		void setDOB(char D);
		void show_student() const;
		void modify();
		char get_class() const;
		double get_regno() const;
		char get_name() const;
		void report() const;
		int get_age() const;
		void setStudent();
		void payrollreport()const;
};
#endif
