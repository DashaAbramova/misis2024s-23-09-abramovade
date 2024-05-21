//
// Created by DariA on 21.05.2024.
//

#pragma once
#include<iostream>

class IContainerBase<int>{
public:
	virtual ~IContainerBase(){};
	virtual void add(const& value) = 0;
	virtual void remove(const& value) = 0;
	virtual bool contains(const& value) = 0;
	virtual ~IContainerBase() = default;

	struct Node {
		int* data; // массив
		size_t size; // Текущий размер массива
		Node* next; // Указатель на следующий узел
		Node* prev; // Указатель на предыдущий узел
	};
	Node(int capacity) {
		size = 0;
		next = nullptr;
		prev = nullptr;
		data = new int[capacity];
	}
};
