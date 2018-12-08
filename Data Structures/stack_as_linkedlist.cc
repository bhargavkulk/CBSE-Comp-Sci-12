#include <iostream.h>
#include <stdio.h>

struct BookNode {
	char name[20];
	float price;
	BookNode* next;
};

void book_input(BookNode& book) {
	cout << "Enter name: ";
	gets(book.name);

	cout << "Enter price: ";
	cin >> book.price;
}

void book_output(BookNode book) {
	cout << "Name: " << book.name << endl;
	cout << "Price: " << book.price << endl;
}

class Stack {
	BookNode* top;
public:
	Stack();
	void push();
	void pop();
	void display();
};

Stack::Stack() {
	top = NULL;
}

void Stack::push() {
	BookNode* temp = new BookNode; // dont forget your new!
	book_input(temp);
	temp->next = NULL;

	if(top == NULL) {
		// this is the first push.
		// so we need to get top to point to the first node
		/*
			top[NULL]

			then we get make a new node temp:

			NULL <- temp[first book]

			then we make top equal to temp

			NULL <- top, temp[first book]
		*/
		top = temp;
	} else {
		// now the stack isn't empty.
		// so we now have to change top, so that it points to the new node
		/*
			NULL <- ... <- top[top most book]

			we get temp's next to point to the top most element:

			NULL <- ... <- top[top most book] <- temp[new book]

			and then we move top to temp:

			NULL <- ... <- [prev top most book] <- top[new top most book]
		*/
		temp->next = top;
		top = temp;
	}
}

void Stack::pop() {
	if(top == NULL) {
		// stack is empty, so we can't pop anymore
		cout << "Stack underflow." << endl;
	} else {
		// we make a temp node that also points to the topmost node
		// it is this node we need to pop off the stack
		BookNode* temp = top;
		/*
			NULL <- ... <- top[top most book]

			we make temp equal to top:

			NULL <- ... <- top, temp[top most book]

			then we move top forward (towards the NULL):

			NULL <- ... <- top[2nd book] <- temp[top most book]

			then we free temp:

			NULL <- .. <- top[2md book]
		*/
		top = top->next;
		cout << "Popped: " << endl;
		book_output(*temp); // book_input is call by value, so we derefence temp
						   // to expose what its pointing to.
		cout << endl;
		delete temp; //dont forget your delete!
	}
}

void Stack::display() {
	if(top == NULL) {
		// stack is empty, because top is NULL
		cout << "Empty stack." << endl;
	} else {
		// to display the stack, we need to traverse it:
		/*
			NULL <- ... <- [second book] <- top[top most book]

			we make a temp pointer and make it equal to top:

			NULL <- ... <- [second book] <- top, temp[top most book]

			now we can display whatever temp points too.
			then we move temp to the next book:

			NULL <- ... <- temp[second book] <- top[top most book]

			and then we display.
			we keep moving temp forward in a loop. the loop ends when temp is 
			NULL.
		*/
		BookNode *temp = top;

		while(temp != NULL) {
			book_output(*temp);
			temp = temp->next;
		}
	}
}