#include<iostream>
#include<vector>
#include<stdexcept>


class CircleQueue {
public:
	CircleQueue();
	~CircleQueue();
	T& top() const;
	void push(const int& value);
	bool full() const;
	void size() const;
	CircleQueue::operator+=() const;
	CircleQueue::operator-=() const;

privite:
	std::vector<int>CircleQueue;
	CircleQueue.reserve(8);
	int capacity; //фиксированность размера
	int front = 0;//начало очереди
	int end = -1;//конец очереди
	int begin = 0;//начало выделенной памяти
	int getSize = 0;//кол-во элементов
};


CircleQueue<int>::CircleQueue() {
	if (getSize <= 7) {
		end + 1 = new int;
		getSize += 1;
	}
	else {
		throw std::invalid_argument("Memory full");
	}
};

CircleQueue<int>::~CircleQueue() {
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
	return *front;
	delete[]*front;
	if (front == 7) {
		front = 0;
	}
	else {
		front++;
	}
	getSize += 1;
};


void CircleQueue<int>::CircleQueue::push(const int& value) {
	if (getSize < 8) {
		if (end < 7) {
			end++;
			*end = value;
			getSize += 1;
		}
		else {
			end = 0;
			*end = value
			getSize += 1;
		}
	}
	else {
		throw std::invalid_argument("Memory full");
	}
};

bool CircleQueue<int>::CircleQueue::full() const {
	return (getSize == 8);
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

CircleQueue& CircleQueue::operator+=() const{
	//складываем первый и последний элемент
	//добавляем новый элемент в конец(без удаления)
	if ((getSize < 8) && (getSize >= 2)) {
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
CircleQueue& CircleQueue::operator-=() const{
	//вычитает из последего элемента первый
	//добавляет новый элемент в конец(без удаления)
	if ((getSize < 8) && (getSize >= 2)) {
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


