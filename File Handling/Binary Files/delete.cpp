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

// remember delete is an operator, it can not be used as an identifier name
void remove_record() {
	// to delete a record, we need to open two files: the file we need to delete
	// from and a temporary file, we will push data into
	ifstream fin("students.dat", ios::binary);
	ofstream fout("temp.dat", ios::binary);

	Student temp;
	cout << "Enter roll no. of record to be deleted: ";
	cin >> rno;

	// whenever data is read in a loop from a binary file, and the read
	// condition is kept inside the loop, there is a chance that the last file
	// is read again. to fix this we use our read statement as the condition
	// for the loop.
	while(fin.read((char*)&temp, sizeof(Student))) {
		// now we have a record. if the record isn't the one to be deleted, we
		// just push it into the temporary file. if it is, we simply don't
		// do anything with it i.e. it is not added to temporary file.
		if(temp.roll_no != rno) {
			fout.write((char*)&temp, sizeof(Student));
		}
	}

	fin.close();
	fout.close();

	// now we need to replace the old file with the new file
	// we do this by deleting(removing) the old file and then renaming the new
	// file
	remove("students.dat");
	rename("temp.dat", "students.dat");
}