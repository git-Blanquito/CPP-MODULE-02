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

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
	std::cout << "Point default constructor called"
			<< std::endl;
}

Point::Point(Fixed const xValue, Fixed const yValue) : x(xValue), y(yValue)
{
	std::cout << "Point constructor with value called"
			<< std::endl;
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
	std::cout << "Point copy constructor called"
			<< std::endl;
}

Point::~Point(void)
{
	std::cout << "Point Destructor colled"
			<< std::endl;
}

Fixed const& Point::getAxisX(void) const
{
	return (this->x);
}

Fixed const& Point::getAxisY(void) const
{
	return (this->y);
}
