// TASk 1
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream file1("C:\\Users\\l1f24bscs0717\\desktop\\data.csv");
	if (!file1)
	{
		cout << "file not created." << endl;
	}

	string name;
	int contact;
	float gpa;
	string reg_no;
	char choice;
	string search_id;

	do
	{

		cout << "Enter a name:";
		cin >> name;
		cout << "Enter a reg no:";
		cin >> reg_no;
		cout << "Enter a gpa:";
		cin >> gpa;
		cout << "Enter a contact number:";
		cin >> contact;

		file1 << name << " " << reg_no << " " << gpa << " " << contact;
		cout << "Add any student: ";
		cin >> choice;

	} while (choice == 'y');

	ifstream file2("C:\\Users\\l1f24bscs0717\\desktop\\data.csv");
	cout << "Enter registration number to search: ";
	cin >> search_id;
	while (file2 >> name >> reg_no >> gpa >> contact)
	{
		if (search_id == reg_no)
		{
			cout << "Student Found" << endl;
			cout << "Name: " << name << endl;
			cout << "Reg No: " << reg_no << endl;
			cout << "GPA: " << gpa << endl;
			cout << "Contact: " << contact << endl;


		}
		else
		{
			cout << "student not found.";
		}
	}
	file1.close();
	cout << "Data saved.";
	return 0;
}

//____________________________________________________________________

// TASk 2

#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
	ofstream file1("C:\\Users\\l1f24bscs0717\\desktop\\data.csv", ios::app);

	if (!file1)
	{
		cout << " File could not be opened." << endl;
		return 1;
	}

	string reg_no, name, program, contact;
	float gpa;
	cout << "Enter Registration Number: "; 
	cin >> reg_no;
	cout << "Enter Name: ";
	cin >> name;
	cout << "Enter Program: "; 
	cin >> program;
	cout << "Enter CGPA: ";
	cin >> gpa;
	cout << "Enter Contact Number: "; 
	cin >> contact;
	file1 << reg_no << "," << name << "," << program << "," << gpa << "," << contact << endl;

	file1.close();
	cout << "Record added successfully." << endl;

	return 0;
}

//___________________________________________________________________

// TASK 3

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	string reg_no, name, program, contact;
	float gpa;
	string search_id;
	float updated_cgpa;

	cout << "Enter Registration Number to update CGPA: ";
	cin >> search_id;
	cout << "Enter Updated CGPA: ";
	cin >> updated_cgpa;

	ifstream file1("C:\\Users\\l1f24bscs0717\\desktop\\data.csv");
	if (!file1)
	{
		cout << "File not opened." << endl;
		return 1;
	}

	ofstream file2("C:\\Users\\l1f24bscs0717\\desktop\\temp.csv");
	if (!file2)
	{
		cout << "Temp file not created." << endl;
		return 1;
	}

	int found = 0;

	while (file1 >> reg_no >> name >> program >> gpa >> contact)
	{
		if (reg_no == search_id)
		{
			file2 << reg_no << " " << name << " " << program << " " << updated_cgpa << " " << contact << "\n";
			cout << "CGPA updated successfully!" << endl;
			found = 1;
		}
		else
		{
			file2 << reg_no << " " << name << " " << program << " " << gpa << " " << contact << "\n";
		}
	}

	if (found == 0)
	{
		cout << "Student not found." << endl;
	}

	file1.close();
	file2.close();
	cout << "Data saved." << endl;

	return 0;
}


//_______________________________________________________________________

// TASK 4

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	string reg_no, name, program, contact;
	float gpa;
	string search_id;

	cout << "Enter Registration Number to delete: ";
	cin >> search_id;

	ifstream file1("C:\\Users\\l1f24bscs0717\\desktop\\data.csv");
	if (!file1)
	{
		cout << "File not opened." << endl;
		return 1;
	}

	ofstream file2("C:\\Users\\l1f24bscs0717\\desktop\\temp.csv");
	if (!file2)
	{
		cout << "Temp file not created." << endl;
		return 1;
	}

	int found = 0;

	while (file1 >> reg_no >> name >> program >> gpa >> contact)
	{
		if (reg_no == search_id)
		{
			cout << "Student deleted successfully!" << endl;
			found = 1;
		}
		else
		{
			file2 << reg_no << " " << name << " " << program << " " << gpa << " " << contact << "\n";
		}
	}

	if (found == 0)
	{
		cout << "Student not found." << endl;
	}

	file1.close();
	file2.close();

	cout << "Data saved." << endl;

	return 0;
}