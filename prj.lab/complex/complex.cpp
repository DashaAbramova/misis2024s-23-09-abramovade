// 2022 by Polevoi Dmitry under Unlicense
#include <complex/complex.hpp>

Complex Complex::operator-() const noexcept { 
	double reNew = -re;
	double imNew = -im;
	return Complex(reNew, imNew); 
}

bool Complex::operator==(const Complex& rhs) const noexcept { return true; }
bool Complex::operator!=(const Complex& rhs) const noexcept { return true; }

Complex& Complex::operator+=(const Complex& rhs) noexcept { 
	*this = *this + rhs;
	return *this; 
}

Complex& Complex::operator+=(const double rhs) noexcept { 
	return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const Complex& rhs) noexcept {
	*this = *this - rhs;
	return *this; 
}
Complex& Complex::operator-=(const double rhs) noexcept { return operator-=(Complex(rhs)); }

Complex& Complex::operator*=(const Complex& rhs) noexcept {  
	*this = *this * rhs;
	return *this; 
}
Complex& Complex::operator*=(const double rhs) noexcept { return *this; }

Complex& Complex::operator/=(const Complex& rhs) { 
	*this = *this / rhs;
	return *this; 
}
Complex& Complex::operator/=(const double rhs) { return *this; }

std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept {
	ostrm = (re, im);
	return ostrm; 
}
std::istream& Complex::ReadFrom(std::istream& istrm) noexcept { return istrm; }


Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { 
	double reNew = lhs.re + rhs.re;
	double imNew = lhs.im + rhs.im;
	return Complex(reNew, imNew); 
}
Complex operator+(const Complex& lhs, const double rhs) noexcept { 
	double reNew = lhs.re + rhs;
	return Complex(reNew, lhs.im); 
}
Complex operator+(const double lhs, const Complex& rhs) noexcept { 
	double reNew = lhs + rhs.re;
	return Complex(reNew, rhs.im); 
}

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept { 
	double reNew = lhs.re - rhs.re;
	double imNew = lhs.im - rhs.im;
	return Complex(reNew, imNew); 
}
Complex operator-(const Complex& lhs, const double rhs) noexcept { 
	double reNew = lhs.re - rhs;
	return Complex(reNew, lhs.im); 
}
Complex operator-(const double lhs, const Complex& rhs) noexcept { 
	double reNew = lhs - rhs.re;
	return Complex(reNew, rhs.im); 
}

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept { 
	double reNew = lhs.re * rhs.re;
	double imNew = lhs.im * rhs.im + lhs.re * rhs.im + lhs.im * rhs.re;
	return Complex(reNew, imNew)
}
Complex operator*(const Complex& lhs, const double rhs) noexcept { 
	double reNew = lhs.re * rhs;
	double imNew = lhs.im * rhs;
	return Complex(reNew, imNew); 
}
Complex operator*(const double lhs, const Complex& rhs) noexcept { 
	double reNew = lhs * rhs.re;
	double imNew = lhs * rhs.im;
	return Complex(reNew, imNew); 
}

Complex operator/(const Complex& lhs, const Complex& rhs) { 
	double reNew = 
	return Complex(reNew, imNew);
}
Complex operator/(const Complex& lhs, const double rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const double lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }