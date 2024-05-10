#pragma once
#include"IStackBase.hpp"
#include<initializer_list>
#include<stdexcept>

template <typename T> class StackLst : public IStackBase<T>{
public:
    StackLst() {
        head_ = nullptr;
    };

    virtual ~StackLst() override{
        Node *table = head_;
        while (table != nullptr) {
            table = head_->next;
            delete head_;
            head_ = table;
        }
    };


    StackLst(const StackLst<T> &other) {
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

    StackLst(StackLst<T> &&other) {
        head_ = other.head_;
        other.head_ = nullptr;
    };


    StackLst(const std::initializer_list<T> &list){
        for (auto &i : list) {
            Node* new_node = new Node;
            new_node->value = i;
            new_node->next = head_;
            head_ = new_node;
        }
    };


    virtual void push(const T& value) override{
        Node* new_node = new Node;
        new_node->value = value;
        new_node->next = head_;
        head_ = new_node;
    };

    virtual void pop() override{
        if (empty()) {
            throw std::logic_error("StackLst is empty");
        }
        Node* tmp = head_->next;
        delete head_;
        head_ = tmp;
    };


    virtual T& top() const override{
        if (empty()) {
            throw std::logic_error("StackLst is empty");
        }
        return head_->value;
    };


    void swap(StackLst<T> &other) {
        std::swap(head_, other.head_);
    };



    void merge(StackLst<T>& other) {
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


    virtual bool empty() const override{
        return head_ == nullptr;
    };


    virtual std::ptrdiff_t size() const override{
        std::ptrdiff_t count = 0;
        Node* table = head_;
        while (table != nullptr) {
            count++;
            table = table->next;
        };
        return count;
    };


    bool operator==(const StackLst<T>& rhs) const{
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


    bool operator!=(const StackLst<T>& rhs) const{
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


    StackLst<T>& operator=(const StackLst<T>& rhs) noexcept{
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


    StackLst<T>& operator=(StackLst<T>&& other) {
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

    virtual void printToStream(std::ostream &os) const override {
        Node *ukaz = head_;
        os << '[';
        while (ukaz != nullptr) {
            std::string sep = ukaz->next != nullptr ? ", " : "";
            os << ukaz->value << sep;
            ukaz = ukaz->next;
        }
        os << ']';
    }
private:
    struct Node {
        T value;
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const StackLst<T> &wrt) noexcept {
    wrt.printToStream(os);
    return os;
}
