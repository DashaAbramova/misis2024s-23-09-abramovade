//
// Created by DariA on 21.05.2024.
//
#pragma once

#include<iostream>
#include"IContainerBase.hpp"
#include<stdexcept>
#include <vector>
#include <memory>
#include <algorithm>


class CustomContainer : public IContainerBase{
public:
CustomContainer(size_t nodeCapacity_){
	head = nullptr;
	tail = nullptr;
	nodeCapacity = nodeCapacity_;
};

virtual ~CustomContainer override{
	for (Node *main = head; main != nullptr;) {
		Node *next = main->next;
		delete[] main->data;
		delete main;
		main = next;
	}
};

virtual void add(const& value) override{
	if (tail % nodeCapacity == 0){
		head = tail;
	}
};

virtual void remove() override{};
virtual bool contains() const override{};

};






