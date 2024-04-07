#include<iostream>
#include<array>

template <int T>
class StackArrT {
public:
	StackArrT() {
		data_ = new T;
		i_top_++;
	}

	~StackArrT() {
		delete[];
		data_ = nullptr;
	}

	StackArrT(const StackArrT<T>& other);
	StackArrT(StackArrT<T>&& other);
	StackArrT(const std::initializer_list<T>& list);

	void StackArrT::push(const T& value) {
		i_top_ += 1;
		*i_top_ = value;
	};
	void StackArrT::pop(int T) {
		std::cout << *i_top_;
		i_top_ -= 1;
		i_top_ = *i_top_;
	};
	T& StackArrT::top(int T) const {
		std::cout << *i_top_;
	};
	void StackArrT::swap(StackArrT<T>& other);
	void StackArrT::merge(StackArrT<T>& other);

	bool StackArrT::empty(int T) const {
		if (size_ == 0) {
			std::cout << "true";
		}
		else {
			std::cout << "false";
		}
	};
	std::ptrdiff_t size() const {
		n = 0;
		for (int i = 0; i < i_top_; i++) {
			n += 1;
		}
		std::cout << n;
	};

	bool operator==(const StackArrT<T>& rhs) const;
	bool operator!=(const StackArrT<T>& rhs) const;

	StackArrT<T>& operator=(const StackArrT<T>& rhs) noexcept;
	StackArrT<T>& operator=(StackArrT<T>&& other);
private:
	std::ptrdiff_t size_ = 0;   //!< число элементов в буфере
	std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
	T* data_ = nullptr;   //!< элементы стека
};
	


TEST_CASE("array") {
	int* arr = new int[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = i;
	}
}



















// 2024 by Polevoi Dmitry under Unlicense

/*#pragma once
#ifndef STACKARR_STACKARR_HPP_20240203
#define STACKARR_STACKARR_HPP_20240203

#include <cstddef>

struct Complex;

class StackArr {
public:
  [[nodiscard]] StackArr() = default;

  [[nodiscard]] StackArr(const StackArr&) = default;
  
  ~StackArr() = default;
  
  [[nodiscard]] StackArr& operator=(const StackArr&) = default;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);
  
  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

private:
  std::ptrdiff_t size_ = 0;   //!< число элементов в буфере
  std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
  Complex* data_ = nullptr;   //!< элементы стека
};

#endif // !STACKARR_STACKARR_HPP_20240203
*/