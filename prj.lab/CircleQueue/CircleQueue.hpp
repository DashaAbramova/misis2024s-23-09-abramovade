#ifndef CIRCLEQUEUE_H
#define CIRCLEQUEUE_H

#include<iostream>
#include<stdexcept>

class CircleQueue {
public:
	CircleQueue();
	~CircleQueue();
	int top();
	void push(const int& value);
	bool empty();
	int getSize();
	int getFront();
	int getBack();
	int operator+=();
	int operator-=();


private:
	int capacity;
	int* begin = nullptr;
	int* front = nullptr;
	int* end = nullptr;
};


 CircleQueue::CircleQueue() {
 	capacity = 20;
 	begin = new int[capacity];
 	front = begin;
 	end = begin;
};

CircleQueue::CircleQueue(int _capacity) {
	capacity = _capacity + 1;
	begin = new int[capacity];
	front = begin;
	end = begin;
};
CircleQueue::~CircleQueue() {
	delete[] begin;
	begin = nullptr;
	front = nullptr;
	end = nullptr;
};

int CircleQueue::top() {
	if(getSize() == 0) {
		throw std::invalid_argument("Memory empty");
	}
	return *front;
	if (front == (capacity-1)) {
		delete *front;
		front = 0;
	}
	else {
		int temp = front + 1;
		delete *front;
		front = temp;
	}
};


void CircleQueue::push(const int& value) {
	if (getSize() < capacity) {
		if (end < (capacity-1)) {
			end++;
		}
		else {
			end = 0;
		}
		*end = value;
	}
	else {
		throw std::invalid_argument("Memory full");
	}
};

bool CircleQueue::empty() {
	return (getSize() == 0);
};

int CircleQueue::getSize() {
	if (front < end) {
		return (end - front + 1);
	}
	else if(front == end) {
		return 1;
	}
	else if(end < front){
		return (capacity - front + end + 1);
	}
};
int CircleQueue::getFront() {
	return *front;
}
int CircleQueue::getBack() {
	return *end;
}

int CircleQueue::operator+=(){
	//оператор складывает первый и последний элемент
	//добавляет его в конец(без удаления)
	if ((getSize() < capacity) && (getSize() >= 2)) {
		int newend = *front + *end;
		if (end == (capacity-1)){
			end = 0;
		}
		else {
			end += 1;
		}
		*end = newend;
		return *end;
	}
	else {
		throw std::invalid_argument("Error memory");
	}
}
int CircleQueue::operator-=(){
	//оператор вычитает из последнего элемента первый
	//добавляет его в конец(без удаления)
	if ((getSize() < capacity) && (getSize() >= 2)) {
		int newend = *end - *front;
		if (end == (capacity-1)) {
			end = 0;
		}
		else {
			end += 1;
		}
		*end = newend;
		return *end;
	}
	else {
		throw std::invalid_argument("Error memory");
	}
}
#endif

