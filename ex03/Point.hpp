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

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	public:
		Point(void);
		Point(Fixed const xValue, Fixed const yValue);
		Point(const Point& other);
		Point& operator=(const Point &other) = delete;
		~Point(void);
		Fixed const& getAxisX(void) const;
		Fixed const& getAxisY(void) const;

	private:
		Fixed const x;
		Fixed const y;
};

#endif
