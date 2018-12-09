#include <fstream.h>
#include <stdio.h>

struct Student {
	int roll_no;
	char name[20];

	void input();
	void output();
};

void Student::input() {
	cout << "Enter name: ";
	gets(name);

	cout << "Enter roll no.: ";
	cin >> roll_no;
}

void Student::output() {
	cout << "Name: " << name << endl;
	cout << "Roll no.: " << roll_no << endl;
}

void modify() {
	// to search a file we need to extract data from the file. so we are going
	// to open a ifstream in binary mode.
	ifstream fin("students.dat", ios::in|ios::binary);

	Student temp;
	cout << "Enter roll no. of student: ";
	cin >> rno;

	// whenever data is read in a loop from a binary file, and the read
	// condition is kept inside the loop, there is a chance that the last file
	// is read again. to fix this we use our read statement as the condition
	// for the loop.
	while(fin.read((char*)&temp, sizeof(Student))) {
		if(temp.roll_no == rno) {
			// we found our record
			temp.output();

			// assuming all roll nos are unique, we can break out of the loop
			// now.
			break;
		}
	}

	fin.close();
}