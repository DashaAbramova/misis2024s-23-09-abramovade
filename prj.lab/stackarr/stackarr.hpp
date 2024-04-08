#include<iostream>
#include<array>
#include<stack>


template <typename T>
class StackArrT {
public:
	StackArrT();
	~StackArrT();
	StackArrT(const StackArrT<T>& other);
	StackArrT(StackArrT<T>&& other);
	StackArrT(const std::initializer_list<T>& list);

	void push(const T& value);
	void pop();
	T& top() const;
	void swap(StackArrT<T>& other);
	void merge(StackArrT<T>& other);

	bool empty() const;
	std::ptrdiff_t size() const;

	bool operator==(const StackArrT<T>& rhs) const;
	bool operator!=(const StackArrT<T>& rhs) const;

	StackArrT<T>& operator=(const StackArrT<T>& rhs) noexcept;
	StackArrT<T>& operator=(StackArrT<T>&& other);
private:
	std::ptrdiff_t size_ = 0;   //!< число элементов в буфере
	std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
	T* data_ = nullptr;   //!< элементы стека
};




template <typename T>
StackArrT<T>::StackArrT() {
	data_ = new T;
	i_top_++;
	size_ = 0;
}

template <typename T>
StackArrT<T>::~StackArrT() {
	delete[];
	data_ = nullptr;
}

template <typename T>
StackArrT<T>::StackArrT(const StackArrT<T>& other);
template <typename T>
StackArrT<T>::StackArrT(StackArrT<T>&& other);
template <typename T>
StackArrT<T>::StackArrT(const std::initializer_list<T>& list);


template <typename T>
void StackArrT<T>::StackArrT::push(const T& value) {
	i_top_ += 1;
	*i_top_ = value;
	size_ += 1;
};

template <typename T>
void StackArrT<T>::StackArrT::pop() {
	std::cout << *i_top_;
	i_top_ -= 1;
	i_top_ = *i_top_;
	size_ -= 1;
};

template <typename T>
T& StackArrT<T>::StackArrT::top() const {
	std::cout << *i_top_;
};

template <typename T>
void StackArrT<T>::StackArrT::swap(StackArrT<T>& other) {
	std::swap(StackArrT, other);
};

template <typename T>
void StackArrT<T>::StackArrT::merge(StackArrT<T>& other) {

};

template <typename T>
bool StackArrT<T>::StackArrT::empty() const {
	if (size_ == 0) {
		std::cout << "true";
	}
	else {
		std::cout << "false";
	}
};
template <typename T>
std::ptrdiff_t StackArrT<T>::size() const {
	std::cout << i_top_ + 1;
};

template <typename T>
bool StackArrT<T>::operator==(const StackArrT<T>& rhs) const;

template <typename T>
bool StackArrT<T>::operator!=(const StackArrT<T>& rhs) const;

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT<T>& rhs) noexcept;

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(StackArrT<T>&& other);
	
