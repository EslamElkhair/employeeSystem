//============================================================================
// Name        : employee management system
// Author      : Eslam Elkhair
// Version     : v2
// Copyright   : @Elkhair's
// Description : employee program using functions in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
/*
Practice: Employee Program (v2)
● Help our factory in managing his employees. Create a program that does the
following:
○ Display the following choices:
■ Enter your choice:
■ 1) Add new employee
■ 2) Print all employees
■ 3) Delete by age
■ 4) Update Salary by name
○ You will keep the program running forever.
Display the choices and user input from 1 to 4

● For choice 1: Allow the manager to enter information of an employee
○ Ask user to input: Name, Age, Salary and Gender letter
○ Add the information to your database
● For choice 2: Print all employees. Line per employee
● For choice 3: User enter to values, start age and end age
○ Find all employees with: start age <= age <= end age and remove them
● For choice 4: User enter name, then salary
○ Find the employee and update his salary
*/

const int MAX=100; //Max number of employees
string names[MAX];
int ages[MAX];
double salaries[MAX];
char genders[MAX];
int added = 0;

int menu() {

	int choice = -1;

	while (choice == -1) {

		cout << "\n1) Add new employee\n"
				"2) Print all employees\n"
				"3) Delete by age\n"
				"4) Update Salary by name\n"
				"5) Exit\n"
				"Enter your choice:";
		cin >> choice;

		if (!(1 <= choice && choice <= 5)) {
			cout << "invalid choice. try again\n";
			choice = -1;
		}
	}

	return choice;

}
void add_new() {

cout<<"\n";
	cout << "Enter name:";
	cin >> names[added];
	cout << "Enter age:";
	cin >> ages[added];
	cout << "Enter salary:";
	cin >> salaries[added];
	cout << "Enter gender:";
	cin >> genders[added];

	added++; /// for every employee added to the system we increase one
}

void print_all() {

    cout<<"\n";
	for (int i = 0; i < added; i++)
		if (ages[i] != -1)  /// related to the block of Delete by age --> if age of any employee = -1 , delete him from the system
			cout << "Name: " << names[i] << " " << " age: " << ages[i] << " "
					<< "Salary: " << salaries[i] << " " << "Gender: "
					<< genders[i] << "\n";

	if (added == 0 )
		cout << "\nno employees yet\n";

}
void delete_by_age() {
	int start, end;
	cout << "\nEnter start and end age:";
	cin >> start >> end;
	for (int i = 0; i < added; i++) {
		if (start <= ages[i] && ages[i] <= end)
			ages[i] = -1; // lazy delete
	}
}

void update_salary() {
	cout << "\nEnter name and new salary:";
	string name;
	double new_salary;
	cin >> name >> new_salary;

	bool is_found = false;

	for (int i = 0; i < added; i++) {
		if (ages[i] != -1 && names[i] == name) {
			is_found = true;
			salaries[i]=new_salary;
		}
	}

	if (is_found == false)
		cout << "\nNo such employee with that name\n";
}
void employee_system() {

	while (true) {

		int choice = menu();

		if (choice == 1)
			add_new();
		else if (choice == 2)
			print_all();
		else if (choice == 3)
			delete_by_age();
		else if (choice == 4)
			update_salary();
		else if (choice == 5)
			break;
	}
}

int main () {
	employee_system();
	return 0;

}
