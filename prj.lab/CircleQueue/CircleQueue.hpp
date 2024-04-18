#ifndef CIRCLEQUEUE_H
#define CIRCLEQUEUE_H

#include<iostream>
#include<vector>
#include<stdexcept>

class CircleQueue {
public:
	CircleQueue();
	~CircleQueue();
	int& top() const;
	void push(const int& value);
	bool full() const;
	void size() const;
	CircleQueue operator+=() const;
	CircleQueue operator-=() const;

privite:
	std::vector<int>CircleQueue(8);
	int front = 0;
	int end = -1;
	int begin = 0;
	int getSize = 0;
};


CircleQueue<int>::CircleQueue() {
	if(size() == 0) {
		*front = new int;
		end += 1;
	}
	else if (size() <= 7) {
		if(end==7) {
			end = 0;
		}
		end += 1;
		end = new int;
		getSize += 1;
	}
	else {
		throw std::invalid_argument("Memory full");
	}
};

CircleQueue<int>::~CircleQueue() {
	if(size() == 0) {
		throw std::invalid_argument("Memory empty");
	}
	delete[] *end;
	if (end <= 7) {
		end -= 1;
	}
	else if (end == 0) {
		end = 7;
	}
	getSize += 1;
};

void CircleQueue<int>::CircleQueue::top() const {
	if(size() == 0) {
		throw std::invalid_argument("Memory empty");
	}
	return *front;
	delete[]*front;
	if (front == 7) {
		front = 0;
	}
	else {
		front++;
	}
	getSize -= 1;
};


void CircleQueue<int>::CircleQueue::push(const int& value) {
	if (size() < 8) {
		if (end < 7) {
			end++;
		}
		else {
			end = 0;
		}
		*end = value;
		getSize += 1;
	}
	else {
		throw std::invalid_argument("Memory full");
	}
};

bool CircleQueue<int>::CircleQueue::full() const {
	return (size() == 8);
};

void CircleQueue<int>::CircleQueue::size() const {
	size = getSize;
};

void CircleQueue<int>::CircleQueue::getFront() const {
	getFront = *front;
}
void CircleQueue<int>::CircleQueue::getBack() const {
	getFront = *end;
}

CircleQueue CircleQueue::operator+=() const{
	//оператор складывает первый и последний элемент
	//добавляет его в конец(без удаления)
	if ((size() < 8) && (size() >= 2)) {
		newend = *front + *end;
		if (end == 7){
			end = 0;
		}
		else {
			end += 1;
		}
		*end = newend;
		getSize += 1;
		return *end;
	}
	else {
		throw std::invalid_argument("Error memory");
	}
}
CircleQueue CircleQueue::operator-=() const{
	//оператор вычитает из последнего элемента первый
	//добавляет его в конец(без удаления)
	if ((size() < 8) && (size() >= 2)) {
		newend = *end - *front;
		if (end == 7) {
			end = 0;
		}
		else {
			end += 1;
		}
		*end = newend;
		getSize += 1;
		return *end;
	}
	else {
		throw std::invalid_argument("Error memory");
	}
}
#endif

