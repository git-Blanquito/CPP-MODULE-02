/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    Makefile                                           :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: aiblanco <marvin@42.fr>                    +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2024/09/20 23:05:13 by aiblanco          #+#    #+#              */
/*    Updated: 2024/09/20 23:05:21 by aiblanco         ###   ########.fr        */
/*                                                                              */
/* **************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called"
			<< std::endl;
	this->RawBits = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" 
			<< std::endl;
	this->RawBits = n << this->FractionalBits;
}

Fixed::Fixed(const float n)
{
	std::cout << "float constructor called" 
			<< std::endl;
	this->RawBits = (int)roundf(n * ( 1 << this->FractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called"
			<< std::endl;
	this->RawBits = other.getRawBits();
}

Fixed::Fixed(Fixed&& other) noexcept
{
    std::cout << "Builder by movement called" << std::endl;
	this->RawBits = other.getRawBits();
    other.setRawBits(0);
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->RawBits = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fi)
{
    os << fi.toFloat();
    return (os);
}

Fixed& Fixed::operator=(Fixed&& other) noexcept
{
	std::cout << "Assignment operator by movement called" << std::endl;
	if (this == &other)
		return (*this);
	this->RawBits = other.getRawBits();
    other.setRawBits(0);
	return (*this);
}

bool Fixed::operator>(Fixed const &other) const
{
	return (this->RawBits > other.getRawBits());
}

bool Fixed::operator<(Fixed const &other) const
{
	return (this->RawBits < other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other) const
{
	return (this->RawBits >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other) const
{
	return (this->RawBits <= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other) const
{
	return (this->RawBits == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other) const
{
	return (this->RawBits != other.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &other) const 
{
	Fixed	ret;
	ret.setRawBits(this->RawBits + other.getRawBits());
	return ret;
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	Fixed	ret;
	ret.setRawBits(this->RawBits - other.getRawBits());
	return ret;
}

Fixed	Fixed::operator*(Fixed const &other) const
{
	Fixed	ret;
	ret.setRawBits((this->RawBits * other.getRawBits()) >> FractionalBits);
	return ret;
}

Fixed	Fixed::operator/(Fixed const &other) const
{
	Fixed	ret;
	ret.setRawBits((this->RawBits << FractionalBits) / other.getRawBits());
	return ret;
}

Fixed& Fixed::operator++() 
{
    this->RawBits += (1 << FractionalBits);
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->RawBits += (1 << FractionalBits);
    return temp;
}

Fixed& Fixed::operator--() 
{
    this->RawBits -= (1 << FractionalBits);
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->RawBits -= (1 << FractionalBits);
    return temp;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor colled"
			<< std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->RawBits);
}

void Fixed::setRawBits(int const i)
{
	this->RawBits = i;
}

float Fixed::toFloat(void) const
{
	return ((float)((float)this->RawBits / (float)(1 << this->FractionalBits)));
}

int Fixed::toInt(void) const
{
	return (this->RawBits >> this->FractionalBits);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}
