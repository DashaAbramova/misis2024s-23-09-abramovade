#pragma once
#include<iostream>

template <typename T>
class IStackBase{
public:
      virtual void push(const T& value) = 0;
      virtual void pop() = 0;
      virtual T& top() const = 0;
      virtual bool empty() const = 0;
      virtual std::ptrdiff_t size() const = 0;
      virtual void printToStream(std::ostream& os) const{
            os << "123";
      };
      virtual ~IStackBase(){};
};
