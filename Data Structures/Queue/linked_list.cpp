#include <iostream.h>

struct ComplexNode {
	float real, imag;
	ComplexNode* next;
};

void complex_input(ComplexNode* node) {
	cout << "Enter real part: ";
	cin >> node->real;
	cout << "Enter imaginary part: ";
	cin >> node->imag;
}

void complex_output(ComplexNode node) {
	cout << node.real << "+(" << node.imag << ")i" << endl;
}

class Queue {
	ComplexNode *front, *rear;

public:
	ComplexNode();
	void insert();
	void remove();
	void display();
};

ComplexNode::ComplexNode() {
	// rear is the pointer to the last element of the queue. it is from rear's 
	// side, elements enter
	// front is the pointer to the front element of the queue. it is from
	// front's side, elements exit
	/*
		{exit from here} << front << ... << rear << {enter from here}
	*/
	// initial condition:
	front = rear = NULL;
}

void ComplexNode::insert() {
	ComplexNode* temp = new ComplexNode(); // dont forget the new!
	complex_input(temp);
	temp->next = NULL;

	if(front == NULL) {
		// the queue is empty. therefore, this is the first element to be added
		// to the node (or) it is the first node to be linked to the list.
		// so we get front and rear both to point to the first node.
		/*
			front and rear are both NULL in the starting:
			
			front, rear[NULL]

			then we make a new node:
			
			NULL <- temp[node to be inserted]

			then we make front and rear equal to this node:

			NULL <- front, rear[first node]
		*/

		front = rear = NULL;
	} else {
		// the queue has some data. so now we need to insert from rear.
		/*
			temp:
			NULL <- temp[node to be inserted]
				
			queue:
			NULL <- rear[last node] <- ... <- front[front node]

			first, we get rear to point to temp:

			NULL <- temp[node to be inserted] <- rear[last node] ... <- front[front node]

			then, we move rear to temp:

			NULL <- rear, temp[node to be inserted] <- [last node] ... <- front[front node]
		*/

		rear->next = temp;
		rear = temp;
	}
}

void Queue::remove() {
	// as elements exit from from, we will initialize temp(node to be 
	// removed) to front
	ComplexNode *node = front;

	if(front == NULL) {
		// queue is empty, as front is still has its initial condition
		cout << "Queue empty." << endl;
	} else {
		if(front == rear) {
			// just like in a queue implemented as an array, when the front
			// equals rear, there is only one element in the queue.
			// we could have just moved front forward, but rear would still,
			// point to the element we just removed. hence we reset the queue
			// so that both front and rear are NULL
			front = rear = NULL;
		} else {
			// now we just move front forward
			/*
                queue:
				NULL <- rear <- ... <- [2nd node] <- front, temp[node to ne removed]
                
                now we just move front forward:

                NULL <- rear <- ... <- front[2nd node] <- temp[node to be removed]

                then we free temp:

                NULL <- rear <- ... <- front[2nd node]

			*/
            front = front->next;
		}

        complex_output(*temp);
        delete temp;
	}
}

void Queue::display() {
    if(front == NULL) {
        // queue is empty, front still has its initial condition
        cout << "Empty stack." << endl;
    } else {
        // to display the queue, we need to traverse it:
        /*
            NULL <- rear <- ... <- [second node] <- front[front node]

            we make a temp pointer and make it equal to front:

            NULL <- rear <- ... <- [second node] <- front, temp[front node]

            now we can display whatever temp points too.
            then we move temp to the next node:

            NULL <- ... <- temp[second node] <- front[front node]

            and then we display.
            we keep moving temp forward in a loop. the loop ends when temp is 
            NULL.
        */
        ComplexNode *temp = front;

        while(temp != NULL) {
            complex_output(*temp);
            temp = temp->next;
        }
    }
}