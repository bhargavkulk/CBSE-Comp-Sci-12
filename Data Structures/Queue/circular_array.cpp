#include <iostream.h>

class Queue {
	int queue[20];
	int front, rear;

public:
	Queue();
	void insert();
	void remove();
	void display();
};

Queue::Queue() {
	// rear is the index to which new elements get added to.
	// front is the index from which elements are removed from.
	// initial condition:
	front = rear = -1;
}

void Queue::insert() {
	// we first check if the queue is full
	// there are two ways in which the queue can be full.
	// and that is why there are 2 conditions separated by an "or" to check if the
	// queue is full or not
	/* 
		1:
                                        rear  front
		+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
		|  0  |  1  |  2  | ... |  14 |  15 |  16 |  17 |  18 |  19 |
		+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
		
		as this is a circular array, rear can loop back to the front of the array. 
		so when rear and fron are side to side, with rear just behind front, 
		the queue is full. Therefore the condition is:

		front == rear + 1

		2:

		 front                               rear  
		+-----+-----+-----+-----+-----+-----+-----+
		|  0  |  1  |  2  | ... |  17 |  18 |  19 |
		+-----+-----+-----+-----+-----+-----+-----+

		so now front is at the very front of the array, and rear is at the very
		end of the array. Therefore the condition is:

		front == 0 && rear == SIZE - 1

		SIZE in this case is 20
	*/
	if((front == rear + 1) || (front == 0 && rear == 20 - 1)) {
		cout << "Queue full." << endl;
	} else {
		// if the queue is empty(when front == -1), we need to initialize front
		// to 0. 
		if(front == -1) front++;

		// now we need to push the new data onto the queue:
		// so we move rear to the next cell. but what if rear is at the last
		// cell? therefore, we need to check if rear is at the end (this can 
		// done by checking if rear = SIZE - 1), and if it is make it zero (we 
		// need to loop it around, this queue is circular)
		/*
			rear is at the end:
			             front                   rear  
			+-----+-----+-----+-----+-----+-----+-----+
			|  0  |  1  |  2  | ... |  17 |  18 |  19 |
			+-----+-----+-----+-----+-----+-----+-----+

			so we make rear = 0:
			 rear        front
			+-----+-----+-----+-----+-----+-----+-----+
			|  0  |  1  |  2  | ... |  17 |  18 |  19 |
			+-----+-----+-----+-----+-----+-----+-----+
		*/

		if(rear == 20 - 1) 
			rear = 0;
		else 
			rear++;
		/*
			this if-statement can be shortened to:
			rear = (rear + 1) % SIZE

			SIZE in this case is 20
		*/

		int num;
		cout << "Enter no.: ";
		cin >> queue[rear];
	}
}

void Queue::remove() {
	if(front = -1) {
		// the queue is empty, because front stil has its initial condition.
		cout << "Queue empty." << endl;
	} else {
		int data = queue[front] // this is the data to be removed
		cout << "Removed: " << data << endl;

		// front and rear can be the same, even if the queue is not empty.
		// this only happens when the queue has only one element e.g: when we
		// first insert an element onto the queue, front and rear are both 0.
		// so after we remove the only element, the queue will be empty. but,
		// the condition for a queue being empty was that front == -1. Hence we
		// have to reset the values of front and rear to 0 when the queue is
		// empty. and because we make front and rear both to -1, the remaining
		// element is automatically removed.
		if(front == rear) {
			front = rear = -1;
		} else {
			// now we have to move front forward. the logic is the same as
			// moving rear, when we wanted to insert an element.
			if(front == 20 - 1) 
				front = 0;
			else 
				front ++;
			/*
				this if-statement can be shortened to:
				front = (front + 1) % SIZE

				SIZE in this case is 20
			*/
		}
	}
}

void Queue::display() {
	// displaying a circular queue is not as easy as just running a loop from
	// front to rear because rear can be behind front. so we need to check if
	// rear is less than front, then we display it using to loops: one from 
	// front to end of the array, and the other from the front of the array
	// to rear
	if(front == -1) {
		// the queue is empty, because front stil has its initial condition.
		cout << "Queue is empty." << endl;
	} else if(rear < front) {
		for(int i = front; i < 20; i++) {
			cout << queue[i] << ' ';
		}

		for (i = 0; i <= rear; i++){
			cout << queue[i] << ' ';
		}
	} else {
		for(int i = front; i <= rear; i++) {
			cout << queue[i] << ' ';
		}
	}

	cout << endl;
}
