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

void sort() {
	// for sorting we first need to move all records into an array. but we don't
	// know how many records there are in the array. the array we make may not
	// be big enough for the file. so we make a dynamic array(pointer). we will
	// first need to know how many records are there in the file.
	ifstream fin("students.dat", ios::binary);
	// 1: move the file pointer to the end of the file. this is acheived by a
	//    calling seekg with the ios::end flag
	fin.seekg(ios::end, 0);
	// 2: the current position of the file pointer is the number of bytes. we
	// can get the no. of records, by simply dividing the current position(total
	// no. of bytes) with the no. of bytes of the object.
	int len = fin.tellg() / sizeof(Student);

	// now we initialize a pointer to Student with "len" no. of cells allocated
	Student* arr = new Student[len];
	Student temp;
	int i = 0; // index of array 

	// the file pointer is at the end of the file. to push records from the file
	// to the array, we first need to move the file pointer to the beginning.
	// then we simply read all records into the array.

	// whenever data is read in a loop from a binary file, and the read
	// condition is kept inside the loop, there is a chance that the last file
	// is read again. to fix this we use our read statement as the condition
	// for the loop.
	while(fin.read((char*)&temp, sizeof(Student))) {
		arr[i] = temp;
		i++;
	}

	fin.close();

	// now we sort it with a aorting algorithm of our choice. i will be using
	// bubble sort (as it takes the least effort to type out).

	for(i = 0; i < len - 1; i++) {
		for(int j = 0; len - i - 1; j++) {
			if(arr[j].roll_no > arr[j+1].roll_no) {
				Student temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	// now we need to put the sorted records back into the file. this can be
	// done by simply making a new ofstream in truncate mode.
	// ios::trunc tells the stream to be in truncate mode i.e. all existing
	// data is overwritten with any new data you insert.

	ofstream fout("students.dat", ios::binary|ios::trunc);
	for(i = 0; i < len; i++) {
		fout.write((char*)&arr[i], sizeof(Student));
	}

	fout.close();
}