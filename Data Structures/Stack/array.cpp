#include <iostream.h>

class Stack {
    // Here the stack is implemented as an array
	int stack[20];
	int top;

public:
	Stack();
	void push();
	void pop();
	void display();
};

Stack::Stack() {
    // top is the constrol variable that indicates the index of the current
    // top-most element 
    // initial condition:
	top = -1;
}

void Stack::push() {
    if (top == 20 - 1) {
        // top is equal to the maximum index (which in this case is 20 - 1 = 19) 
        // i.e. the current element occupies the last index.
        // no more elements can be pushed onto the stack.
        cout << "Stack overflow." << endl;
    } else {
        // as there is space in the stack, we can push an element
        // so we increment the top, so that is is equal to the next available 
        // index in the array.

        // the statement below is equivalent to:
        // top++;
        // cin >> stack[top];
        cout << "Enter number: ";
        cin >> stack[++top];
    }
}

void Stack::pop() {
    if(top == -1) {
        // if top is -1, then the stack is empty
        // so we can't pop any more
        cout << "Stack underflow." << endl;
    } else {
        // We can pop an element. So, we just decrement top i.e. we "forget" 
        // about the current top most element.

        // the statement below is equivalent to:
        // cout << stack[top];
        // top--;
        cout << stack[top--];
    }
}

void Stack::display() {
    if(top == -1) {
        // top is -1 so stack is empty
        cout << "Empty stack.";
    } else {
        // loop only till top, but include top in the count
        // as top has the last element
        for(int i = 0; i <= top; i++) {
            cout << stack[i] << ' ';
        }
        cout << endl;
    }
}

int main() {
    // menu driven program is left as an exercise to the reader
    return 0;
}