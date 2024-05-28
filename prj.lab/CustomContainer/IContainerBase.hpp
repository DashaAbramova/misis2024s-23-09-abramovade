#pragma once


#include <iostream>

class IContainerBase {
public:
	virtual void add(std::pair<int, int> value) = 0;

	virtual void remove(std::pair<int, int> valuee) = 0;

	virtual bool contains(std::pair<int, int> value) = 0;

	virtual ~IContainerBase() = default;

};
struct Node {
	std::pair<int, int> value; // значение в списке
	Node* prev = nullptr; // указатель на предыдущую ноду
	Node* next = nullptr; // указатель на следующую ноду
};





