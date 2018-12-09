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

void insert() {
	// this function will be inserting into a sorted file. we can safely assume
	// that the file is sorted. if it is not we simply sort it before inserting
	// (see sort.cpp for sorting). for inserting we need two files: the target
	// file in which we want to insert, and a temporary file.
	ifstream fin("students,dat", ios::binary);
	ofstream fout("temp.dat", ios::binary);   

	// we are going to keep a flag to check whether a record has been inserted
	// or not.
	int flag = 1;
	Student temp, student;

	cout << "Enter details of student to be inserted: " << endl;
	student.input();
	// whenever data is read in a loop from a binary file, and the read
	// condition is kept inside the loop, there is a chance that the last file
	// is read again. to fix this we use our read statement as the condition
	// for the loop.
	while(fin.read((char*)&temp, sizeof(Student))) {
		if(temp.roll_no > student.roll_no && flag) {
			// so there are two conditions, both have to be true for a record to
			// be inserted.
			//1: the roll no. of the student to be inserted is less than the
			//   roll no. of the current "read" student. 
			/*
				+-----+-----+-----+-----+-----+-----+-----+
		        |  0  |  1  |  2  |  4  |  6  |  7  |  8  |
		        +-----+-----+-----+-----+-----+-----+-----+

		        5 is to be inserted. 5 is less than 6, so we insert it before 6
			*/

			//2: a file is already inserted. we do not need to insert anymore
			//   records. so we simply make the flag false after an insertion is
			//   done, and fail the insertion condition.
			fout.write((char*)&student, sizeof(Student));
			flag = 0;
 		}

 		fout.write((char*)&temp, sizeof(Student));
	}

	fin.close();
	fout.close();

	// now we need to replace the old file with the new file
	// we do this by deleting(removing) the old file and then renaming the new
	// file
	remove("students.dat");
	rename("temp.dat", "students.dat");
}