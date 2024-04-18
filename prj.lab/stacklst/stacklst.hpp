#ifndef STACKLST_H
#define STACKLST_H

#include<iostream>
#include<initializer_list>
#include<cstddef>
#include<stdexcept>

template <typename T>
class StackLstT {
public:
    StackLstT();
    ~StackLstT();
    StackLstT(const StackLstT<T>& other);
    StackLstT(StackLstT<T>&& other);
    StackLstT(const std::initializer_list<T>& list);

    void push(const T& value);
    void pop();
    T& top() const;
    void swap(StackLstT<T>& other);
    void merge(StackLstT<T>& other);

    bool empty() const;
    std::ptrdiff_t size() const;

    bool operator==(const StackLstT<T>& rhs) const;
    bool operator!=(const StackLstT<T>& rhs) const;

    StackLstT<T>& operator=(const StackLstT<T>& rhs) noexcept;
    StackLstT<T>& operator=(StackLstT<T>&& other);

private:
    struct Node {
        T value;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
};

template <typename T>
StackLstT<T>::StackLstT() {
    head_ = nullptr;
};

template <typename T>
StackLstT<T>::~StackLstT() {
    Node *table = head_;
    while (table != nullptr) {
        table = head_->next;
        delete head_;
        head_ = table;
    }
};

template <typename T>
StackLstT<T>::StackLstT(const StackLstT<T> &other) {
    if (!other.empty()) {
        Node *ukaz = other.head_;
        Node *tail = head_;
        while (ukaz != nullptr) {
            if (head_ == nullptr) {
                head_ = new Node;
                head_->value = ukaz->value;
                head_->next = nullptr;
                tail = head_;
            } else {
                tail->next = new Node;
                tail = tail->next;
                tail->value = ukaz->value;
                tail->next = nullptr;
            }
            ukaz = ukaz->next;
        }
    }
    else {
        head_ = nullptr;
    }
};
template <typename T>
StackLstT<T>::StackLstT(StackLstT<T> &&other) {
    head_ = other.head_;
    other.head_ = nullptr;
};

template <typename T>
StackLstT<T>::StackLstT(const std::initializer_list<T> &list){
    for (auto &i : list) {
        Node* new_node = new Node;
        new_node->value = i;
        new_node->next = head_;
        head_ = new_node;
    }
};

template <typename T>
void StackLstT<T>::push(const T& value) {
    Node* new_node = new Node;
    new_node->value = value;
    new_node->next = head_;
    head_ = new_node;
};
template <typename T>
void StackLstT<T>::pop() {
    if (empty()) {
        throw std::logic_error("StackLst is empty");
    }
    Node* tmp = head_->next;
    delete head_;
    head_ = tmp;
};

template <typename T>
T& StackLstT<T>::top() const {
    if (empty()) {
        throw std::logic_error("StackLst is empty");
    }
    return head_->value;
};

template<typename T>
void StackLstT<T>::swap(StackLstT<T> &other) {
    std::swap(head_, other.head_);
};


template <typename T>
void StackLstT<T>::merge(StackLstT<T>& other) {
    if (empty()) {
        head_ = other.head_;
        other.head_ = nullptr;
        return;
    }
    else if (!other.empty()) {
        Node *table = other.head_;
        while (table->next != nullptr) {
            table = table->next;
        }
        table->next = head_;
        head_ = other.head_;
        other.head_ = nullptr;
    }
};

template <typename T>
bool StackLstT<T>::empty() const {
    return head_ == nullptr;
};

template<typename T>
std::ptrdiff_t StackLstT<T>::size() const {
    std::ptrdiff_t count = 0;
    Node* table = head_;
    while (table != nullptr) {
        count++;
        table = table->next;
    };
    return count;
};


template <typename T>
bool StackLstT<T>::operator==(const StackLstT<T>& rhs) const{
    Node* lhsP = head_;
    Node* rhsP = rhs.head_;
    while ((lhsP != nullptr) && (rhsP != nullptr)) {
        if (lhsP->value != rhsP->value) {
            return false;
        };
        lhsP = lhsP->next;
        rhsP = rhsP->next;
    }
    if (lhsP == nullptr && rhsP == nullptr) {
        return true;
    };
    return false;
};

template <typename T>
bool StackLstT<T>::operator!=(const StackLstT<T>& rhs) const{
    Node* lhsP = head_;
    Node* rhsP = rhs.head_;
    while (lhsP != nullptr || rhsP != nullptr) {
        if ((lhsP == nullptr) || (rhsP == nullptr)) {
            return true;
        }
        if (lhsP->value != rhsP->value) {
            return true;
        };
        lhsP = lhsP->next;
        rhsP = rhsP->next;
    }
    return false;
};

template <typename T>
StackLstT<T>& StackLstT<T>::operator=(const StackLstT<T>& rhs) noexcept{
    Node* table = head_;
    while (table != nullptr) {
        head_ = head_->next;
        delete table;
        table = head_;
    }
    if (!rhs.empty()) {
        Node *ukaz = rhs.head_;
        Node *tail = head_;
        while (ukaz != nullptr) {
            if (head_ == nullptr) {
                head_ = new Node;
                head_->value = ukaz->value;
                head_->next = nullptr;
                tail = head_;
            } else {
                tail->next = new Node;
                tail = tail->next;
                tail->value = ukaz->value;
                tail->next = nullptr;
            }
            ukaz = ukaz->next;
        }
    } else {
        head_ = nullptr;
    }
    return *this;
};

template <typename T>
StackLstT<T>& StackLstT<T>::operator=(StackLstT<T>&& other) {
    Node* tmp = head_;
    while (tmp != nullptr) {
        head_ = head_->next;
        delete tmp;
        tmp = head_;
    }
    head_ = other.head_;
    other.head_ = nullptr;
    return *this;
};


#endif