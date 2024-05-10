#pragma once

#include"IStackBase.hpp"
#include<initializer_list>
#include<stdexcept>


template <typename T> class StackArr : public IStackBase<T>{
public:
StackArr() {
	data_ = new T;
	i_top_ = -1;
	size_ = 0;
};

virtual ~StackArr() override{
	size_ = 0;
	i_top_ = -1;
	delete[] data_;
	data_ = nullptr;
};

StackArr(const StackArr& other) {
	if (other.empty()) {
		size_ = 0;
		i_top_ = -1;
		data_ = nullptr;
	}
	else {
		data_ = new T[other.size_];
		i_top_ = other.i_top_;
		size_ = other.size_;
		std::copy(other.data_, other.data_ + i_top_ + 1, data_);
	}
};

StackArr(StackArr&& other) {
	data_ = other.data_;
	i_top_ = other.i_top_;
	size_ = other.size_;
	other.data_ = nullptr;
	other.i_top_ = -1;
	other.size_ = 0;
};


StackArr(const std::initializer_list<T>& list) {
	size_ = list.size();
	i_top_ = size_ - 1;
	data_ = new T[size_];
	std::copy(list.begin(), list.end(), data_);
};



virtual void push(const T& value) override{
	if (empty()) {
		size_ = 8;
		data_ = new T[size_];
	}
	else if (size_ == i_top_ + 1) {
		T* new_data_ = new T[size_ * 2];
		std::copy(data_, data_ + i_top_ + 1, new_data_);
		size_ *= 2;
		std::swap(new_data_, data_);
		delete[] new_data_;
		new_data_ = nullptr;
	}
	i_top_++;
	data_[i_top_] = value;
};


virtual void pop() override{
	if (i_top_ < 0) {
		throw std::logic_error("Empty stack.");
	}
	i_top_ -= 1;
};


virtual T& top() const override {
	if (i_top_ < 0) {
		throw std::logic_error("Empty stack.");
	}
	return data_[i_top_];
};


void swap(StackArr& other) {
	std::swap(size_, other.size_);
	std::swap(i_top_, other.i_top_);
	std::swap(data_, other.data_);
};


void merge(StackArr& other) {
	if (empty()) {
		this->swap(other);
	}
	else {
		T *new_data_ = new T[size_ + other.size_];
		for (int i = 0; i < i_top_ + 1; i++) {
			new_data_[i] = data_[i];
		}
		for (int i = 0; i < other.i_top_ + 1; i++) {
			new_data_[i_top_ + 1 + i] = other.data_[i];
		}
		size_ += other.size_;
		i_top_ += other.i_top_ + 1;
		delete[] other.data_;
		other.data_ = nullptr;
		other.i_top_ = -1;
		other.size_ = 0;
		delete[] data_;
		data_ = new_data_;
	}
};

virtual bool empty() const override{
	return i_top_ == -1;
};

virtual std::ptrdiff_t size() const override{
	return i_top_ + 1;
};


bool operator==(const StackArr<T>& rhs) const {
	if (i_top_ != rhs.i_top_) {
		return false;
	}
	else {
		for (std::ptrdiff_t i = 0; i < (i_top_ + 1); i++) {
			if (data_[i] != rhs.data_[i]) {
				return false;
			}
		}
	}
	return true;
};


bool operator!=(const StackArr& rhs) const {
	if (i_top_ != rhs.i_top_) {
		return true;
	}
	for (int i = 0; i < (i_top_ + 1); i++) {
		if (data_[i] != rhs.data_[i]) {
			return true;
		}
	}
	return false;
};


StackArr& operator=(const StackArr& rhs) noexcept{
	if (rhs.empty()) {
		delete[] data_;
		size_ = 0;
		i_top_ = -1;
		data_ = nullptr;
	}
	else if (&rhs != this) {
		delete[] data_;
		size_ = rhs.size_;
		i_top_ = rhs.i_top_;
		data_ = new T[size_];
		std::copy(rhs.data_, rhs.data_ + i_top_ + 1, data_);
	}
	return *this;
};


StackArr<T>& operator=(StackArr&& other) {
	data_ = other.data_;
	i_top_ = other.i_top_;
	size_ = other.size_;
	other.data_ = nullptr;
	other.i_top_ = -1;
	other.size_ = 0;
	return *this;
};

virtual void printToStream(std::ostream &os) const override {
	os << '[';
	for (std::ptrdiff_t i = i_top_; i >= 0; --i) {
		std::string sep = i != 0 ? ", " : "";
		os << data_[i] << sep;
	}
	os << ']';
}
private:
	std::ptrdiff_t size_ = 0;   //!< число элементов в буфере
	std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
	T* data_ = nullptr;   //!< элементы стека
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const StackArr<T> &wrt) noexcept {
	wrt.printToStream(os);
	return os;
}