#include <rational/rational.hpp>
#include <cmath>
#include <iostream>

Rational& Rational::Reduce() noexcept {
    int64_t n1{ std::abs(num_) }, n2{ std::abs(den_) };
    while (n1 != n2) {
        if (n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    n1 = (den_ >= 0) ? n1 : -n1;
    num_ /= n1;
    den_ /= n1;
    return *this;
}

Rational::Rational(const std::int64_t num, const std::int64_t den)
  : num_(num), den_(den) {
  if (0 == den_) {
    throw std::invalid_argument("Zero denumenator in Rational ctor");
  }
  Reduce();
}

bool Rational::operator==(const Rational &rhs) const noexcept { 
    return (den_ == rhs.den() && num_ == rhs.num());
}
bool Rational::operator!=(const Rational &rhs) const noexcept { 
    return (den_ != rhs.den() || num_ == rhs.num()); 
}
bool Rational::operator<(const Rational &rhs) const noexcept { 
    return (num_ * rhs.den() < rhs.num() * den_); 
}
bool Rational::operator<=(const Rational &rhs) const noexcept { 
    return (num_ * rhs.den() <= rhs.num() * den_);
}
bool Rational::operator>(const Rational &rhs) const noexcept { 
    return (num_ * rhs.den() > rhs.num() * den_); 
}
bool Rational::operator>=(const Rational &rhs) const noexcept { 
    return (num_ * rhs.den() >= rhs.num() * den_); 
}

Rational &Rational::operator+=(const Rational &rhs) noexcept { 
    num_ = num_ * rhs.den() + rhs.num() * den_;
    den_ *= rhs.den_;
    Reduce();
    return *this; 
};
Rational &Rational::operator-=(const Rational &rhs) noexcept { 
    num_ = num_ * rhs.den() - rhs.num() * den_;
    den_ *= rhs.den();
    Reduce();
    return *this; 
};
Rational &Rational::operator*=(const Rational &rhs) noexcept {
    num_ *= rhs.num();
    den_ *= rhs.den();
    Reduce();
    return *this; 
};
Rational &Rational::operator/=(const Rational &rhs) { 
    num_ *= rhs.den();
    den_ *= rhs.num();
    Reduce();
    return *this; 
};

Rational &Rational::operator+=(const int64_t rhs) noexcept {
    return operator+=(Rational(rhs)); 
};
Rational &Rational::operator-=(const int64_t rhs) noexcept { 
    return operator-=(Rational(rhs)); 
};
Rational &Rational::operator*=(const int64_t rhs) noexcept {
    return operator*=(Rational(rhs)); 
};
Rational &Rational::operator/=(const int64_t rhs) { 
    return operator/=(Rational(rhs));
};

Rational &Rational::operator++() noexcept {
    num_ += den_;
    return *this;
};

Rational Rational::operator++(int) noexcept {
    Rational tmp{ num_, den_ };
    num_ += den_;
    return tmp;
};

Rational &Rational::operator--() noexcept {
    num_ -= den_;
    return *this;
};

Rational Rational::operator--(int) noexcept {
    Rational tmp{ num_, den_ };
    num_ -= den_;
    return tmp;
};

Rational operator+(const Rational &lhs, const Rational &rhs) noexcept { 
    return Rational{ lhs } += rhs; 
}
Rational operator-(const Rational &lhs, const Rational &rhs) noexcept { 
    return Rational{ lhs } -= rhs; 
}
Rational operator*(const Rational &lhs, const Rational &rhs) noexcept { 
    return Rational{ lhs } *= rhs; 
}
Rational operator/(const Rational &lhs, const Rational &rhs) { 
    return Rational{lhs} /= rhs; 
}

Rational operator+(const Rational &lhs, const int64_t rhs) noexcept { 
    return Rational{ lhs } += rhs; 
}
Rational operator-(const Rational &lhs, const int64_t rhs) noexcept { 
    return Rational{ lhs } -= rhs; 
};
Rational operator*(const Rational &lhs, const int64_t rhs) noexcept { 
    return Rational{ lhs } *= rhs; 
};
Rational operator/(const Rational &lhs, const int64_t rhs) { 
    return Rational{ lhs } /= rhs; 
}

Rational operator+(const int64_t lhs, const Rational &rhs) noexcept { 
    return operator+(rhs, lhs); 
}
Rational operator-(const int64_t lhs, const Rational &rhs) noexcept { 
    return operator+(rhs, lhs); 
}
Rational operator*(const int64_t lhs, const Rational &rhs) noexcept { 
    return operator+(rhs, lhs); 
}
Rational operator/(const int64_t lhs, const Rational &rhs) { 
    return operator+(rhs, lhs); 
}


std::ostream &Rational::WriteTo(std::ostream &ostrm) const noexcept { 
    return ostrm << num_ << '/' << den_;;
}

std::istream &Rational::ReadFrom(std::istream& istrm) noexcept { 
    int64_t numIn, denIn;
    char buf;
    istrm >> numIn >> buf >> denIn;
    if (!istrm.good()) {
        return istrm;
    }
    if (buf == '/') {
        num_ = numIn;
        den_ = denIn;
        Reduce();
    }
    else {
        istrm.setstate(std::ios_base::failbit);
    }
    return istrm; 
}

std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs) noexcept {
    return rhs.WriteTo(ostrm);
}
std::istream &operator>>(std::istream &istrm, Rational &rhs) noexcept {
    return rhs.ReadFrom(istrm);
}
