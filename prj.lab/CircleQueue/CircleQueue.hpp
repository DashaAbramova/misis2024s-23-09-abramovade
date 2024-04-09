#include<iostream>
#include<vector>
#include<stdexcept>


class CircleQueue {
public:
	CircleQueue();
	~CircleQueue();


privite:
	std::vector<int>CircleQueue;
	CircleQueue.reserve(8);
	int capacity; //фиксированность размера
	int front = 0;//начало очереди
	int end = -1;//конец очереди
	int begin = 0;//начало выделенной памяти
	int* element;//указатель на элемент
};


CircleQueue<int>::CircleQueue() {
	element = new int;
};

CircleQueue<int>::~CircleQueue() {
	delete[] element;
};



void CircleQueue<int>::CircleQueue::top() const {
	return element[front];
	delete[]element[front];
	if (front == 7) {
		front = 0;
	}
	else {
		front++;
	}
};


void CircleQueue<int>::CircleQueue::push(const int& value) {
	if (getSize < 8) {
		(end + 1)[value];
		if (end < 7) {
			end++;
		}
		else {
			end = 0;
		}
	}
	else {
		throw std::invalid_argument("Memory full");
	}
};

bool CircleQueue<int>::CircleQueue::full() const {
	return ((front == begin) and (end == 7));
};

void CircleQueue<int>::CircleQueue::size() const {
	if (front == 0) {
		size = end - front + 1
	}
	else if (front != 0){
		size = end - front;
	}
	else if(end < front){


	}
};


