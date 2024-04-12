#include<iostream>
#include <cstddef>
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
    newNode = new T;
    newNode* = nullptr;
    if (empty()) {
        head_ = newNode;
        next = nullptr;
    }
    else {
        tail* = &newNode;
        next = *newNode;
    }
}

template <typename T>
StackLstT<T>::~StackLstT() {
}

template <typename T>
StackLstT<T>::

template <typename T>
StackLstT<T>::

template <typename T>
StackLstT<T>::

template <typename T>
void StackLstT<T>::push(const T& value){

}
template <typename T>
void StackLstT<T>::pop(){
    delete[]*tail;
    next = tail;
}

template <typename T>
T& StackLstT<T>::StackLst::top() const{
    return *tail;
}

template <typename T>
StackLstT<T>::

template <typename T>
StackLstT<T>::

template <typename T>
bool StackLstT<T>::empty() const {
    return head == nullptr;
}

template <typename T>
StackLstT<T>::

template <typename T>
StackLstT<T>::

template <typename T>
StackLstT<T>::

template <typename T>
StackLstT<T>::

template <typename T>
StackLstT<T>::


