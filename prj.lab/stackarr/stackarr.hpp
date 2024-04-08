#include<initializer_list>
#include<stdexcept>



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
	i_top_ = -1;
	size_ = 0;
};

template <typename T>
StackArrT<T>::~StackArrT() {
	size_ = 0;
	i_top_ = -1;
	delete[] data_;
	data_ = nullptr;
};

template <typename T>
StackArrT<T>::StackArrT(const StackArrT<T>& other) {
	if (other.empty()) {
		size_ = 0;
		i_top_ = -1;
		data_ = nullptr;
	}
	else {
		data_ = new T[other.size_];
		i_top_ = other.i_top_;
		size_ = other.size_;
		std::copy(other.data_, other.data_ + size_, data_);
	}
};
template <typename T>
StackArrT<T>::StackArrT(StackArrT<T>&& other) {
	data_ = other.data_;
	i_top_ = other.i_top_;
	size_ = other.size_;
	other.data_ = nullptr;
	other.i_top_ = -1;
	other.size_ = 0;
};

template <typename T>
StackArrT<T>::StackArrT(const std::initializer_list<T>& list) {
	size_ = list.size();
	i_top_ = size_ - 1;
	data_ = new T[size_];
	std::copy(list.begin(), list.end(), data_);
};


template <typename T>
void StackArrT<T>::StackArrT::push(const T& value) {
	if (data_ == nullptr) {
		size_ = 8;
		data_ = new T[size_];
	}
	else if (size_ == i_top_ + 1) {
		T* new_data_ = new T[size_ * 2];
		std::copy(data_, data_ + size_, new_data_);
		size_ *= 2;
		std::swap(new_data_, data_);
		delete[] new_data_;
	}
	i_top_++;
	data_[i_top_] = value;
};

template <typename T>
void StackArrT<T>::StackArrT::pop() {
	i_top_ -= 1;
};

template <typename T>
T& StackArrT<T>::StackArrT::top() const {
	return data_[i_top_ ];
};

template <typename T>
void StackArrT<T>::StackArrT::swap(StackArrT<T>& other) {
	std::swap(size_, other.size_);
	std::swap(i_top_, other.i_top_);
	std::swap(data_, other.data_);
};

template <typename T>
void StackArrT<T>::StackArrT::merge(StackArrT<T>& other) {
	if (empty()) {
		this->swap(other);
	}
	else {
		T* new_data_ = new T[size_ + other.size_];
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

template <typename T>
bool StackArrT<T>::StackArrT::empty() const {
	return i_top_ == -1;
};
template <typename T>
std::ptrdiff_t StackArrT<T>::size() const {
	return i_top_ + 1;
};

template <typename T>
bool StackArrT<T>::operator==(const StackArrT<T>& rhs) const {
	if (i_top_ != rhs.i_top_) {
		return false;
	}
	else {
		for (std::ptrdiff_t i = 0, i < (i_top_ + 1); i++) {
			if (data_[i] != rhs.data_[i]) {
				return false;
			}
		}
	}
	return true;
};

template <typename T>
bool StackArrT<T>::operator!=(const StackArrT<T>& rhs) const {
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

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT<T>& rhs) noexcept{
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
		std::copy(rhs.data_, rhs.data_ + size_, data_);
	}
	return *this;
};

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(StackArrT<T>&& other) {
	data = other.data_;
	i_top_ = other.i_top_;
	size_ = other.size_;
	other.data_ = nullptr;
	other.i_top_ = -1;
	other.size_ = 0;
	return *this;
};
	
