#pragma once
#include"IContainerBase.hpp"
#include <iostream>


class CustomContainer : public IContainerBase {
private:
    Node* head;
    Node* tail;
    size_t size;

public:
    CustomContainer() : head(nullptr), tail(nullptr), size(0) {}

    void add(std::pair<int, int> value) override {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) { // Если список пуст
            head = tail = newNode;
        } else {
            Node* current = head;
            while (current && current->value < value) {
                current = current->next;
            }
            if (!current) { // Если дошли до конца списка
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev = newNode;
                if (newNode->prev) {
                    newNode->prev->next = newNode;
                } else {
                    head = newNode;
                }
            }
        }

        size++;
    }

    void remove(std::pair<int, int> value) override {
        Node* current = head;
        while (current && current->value != value) {
            current = current->next;
        }

        if (!current) {
            return; // Элемент не найден
        }

        if (current == head) {
            head = current->next;
        } else {
            current->prev->next = current->next;
        }

        if (current == tail) {
            tail = current->prev;
        } else {
            current->next->prev = current->prev;
        }

        delete current;
        size--;
    }

    bool contains(std::pair<int, int> value) override {
        Node* current = head;
        while (current) {
            if (current->value == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    ~CustomContainer() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
