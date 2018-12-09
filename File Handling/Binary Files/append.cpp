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

void append() {
	// we first open an output file stream.
	// as we need to append(add to the end) to a binary file,
	// we use the flags ios::app (for appending), ios::binary (for binary)
	ofstream fout("students.dat", ios::app|io::binary);

	Student student;
	student.input();

	// this is the signature of ofstream.write:
	// ofstream.write(char* data, int no_of_bytes);
	// but student is not a character pointer.
	// so we type-cast its reference to a character pointer
	fout.write((char*)&student, sizeof(Student));
	cout << "Appended: " << endl;
	student.output();
	fout.close();
}