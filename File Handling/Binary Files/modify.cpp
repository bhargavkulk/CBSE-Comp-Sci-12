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
	// to search a file we need to extract data from the file and push data onto
	// the file. so we are going to open a fstream which is both in input and
	// output mode.
	fstream file("students.dat", ios::in|ios::out|ios::binary);

	Student temp, student;
	cout << "Enter student no. to be modified: ";
	student.input()

	// whenever data is read in a loop from a binary file, and the read
	// condition is kept inside the loop, there is a chance that the last file
	// is read again. to fix this we use our read statement as the condition
	// for the loop.
	while(file.read((char*)&temp, sizeof(Student))) {
		if(temp.roll_no == student.roll_no) {
			// we found our record
			// but we already read it i.e. the file pointer is beyond the
			// student we need. so we need to roll back the file pointer, to the
			// student we need to modify. this can be done by seekg/seekp. 
			// we simply set seekp's mode to ios::cur, so that it moves the file
			// pointer relative to the file pointer's current position, and we
			// move it behind by the object's size
			file.seekp(ios::cur, -1 * sizeof(Student));
			temp
			file.write((char*)&student, sizeof(Student));

			// assuming all roll nos are unique, we can break out of the loop
			// now.
			break;
		}
	}

	file.close();
}