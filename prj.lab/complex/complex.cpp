#include <cmath>
#include <complex/complex.hpp>
#include <iostream>
#include <limits>
Complex Complex::operator-() const noexcept { 
	return Complex(-re, -im); 
}

bool Complex::operator==(const Complex& rhs) const noexcept { 
	double eps = 2 * std::numeric_limits<double>::epsilon();
	return (std::abs(re - rhs.re) <= eps && std::abs(im - rhs.im) <= eps); 
}
bool Complex::operator!=(const Complex& rhs) const noexcept { 
	double eps = 2 * std::numeric_limits<double>::epsilon();
	return (std::abs(re - rhs.re) > eps || std::abs(im - rhs.im) > eps); 
}

Complex& Complex::operator+=(const Complex& rhs) noexcept { 
	re += rhs.re;
	im += rhs.im;
	return *this; 
}

Complex& Complex::operator+=(const double rhs) noexcept { 
	return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const Complex& rhs) noexcept {
	re -= rhs.re;
	im -= rhs.im;
	return *this; 
}
Complex& Complex::operator-=(const double rhs) noexcept {
	return operator-=(Complex(rhs)); 
}

Complex& Complex::operator*=(const Complex& rhs) noexcept {  
	double copyRe = re;
	double copyIm = im;
	re = (copyRe * rhs.re) - (copyIm * rhs.im);
	im = (copyRe * rhs.im) + (copyIm + rhs.re);
	return *this; 
}
Complex& Complex::operator*=(const double rhs) noexcept {
	re *= rhs;
	im *= rhs;
	return *this; 
}

Complex& Complex::operator/=(const Complex& rhs) { 
	double vv = (rhs.re * rhs.re + rhs.im * rhs.im);
	re = (re * rhs.re + im * rhs.im) / (vv);
	im = (im * rhs.re - re * rhs.im) / (vv);
	return *this; 
}
Complex& Complex::operator/=(const double rhs) { 
	re /= rhs;
	im /= rhs;
	return *this; 
}

std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept {
	return ostrm << '{' << re << ',' << im << '}';
}
std::istream& Complex::ReadFrom(std::istream& istrm) noexcept {
	char leftBrace, rightBrace, separator;
	double reInp, imInp;
	istrm >> leftBrace >> reInp >> separator >> imInp >> rightBrace;
	if (!istrm.good()) {
		return istrm;
	}
	if ((leftBrace == Complex::leftBrace) && (rightBrace == Complex::rightBrace) && (separator == Complex::separator)) {
		re = reInp;
		im = imInp;
	}
	else {
		istrm.setstate(std::ios_base::failbit);
	}
	return istrm;
}


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
	double reNew = (lhs.re * rhs.re) - (lhs.im * rhs.im);
	double imNew = (lhs.im * rhs.im) + (lhs.im * rhs.re);
	return Complex(reNew, imNew);
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
	return Complex((lhs.re * rhs.re + lhs.im * rhs.im) /
		(rhs.re * rhs.re + rhs.im * rhs.im),
		(rhs.re * lhs.im - lhs.re * rhs.im) /
		(rhs.re * rhs.re + rhs.im * rhs.im));
}
Complex operator/(const Complex& lhs, const double rhs) { 
	double reNew = lhs.re / rhs;
	double imNew = lhs.im / rhs;
	return Complex(reNew, imNew); 
}
Complex operator/(const double lhs, const Complex& rhs) { 
	Complex newLhs(lhs);
	return newLhs / rhs; 
}