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

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool	sign[3];

	Point a_b(b.getAxisX() - a.getAxisX(), b.getAxisY() - a.getAxisY());
	Point a_point(point.getAxisX() - a.getAxisX(), point.getAxisY() - a.getAxisY());

	Point b_c(c.getAxisX() - b.getAxisX(), c.getAxisY() - b.getAxisY());
	Point b_point(point.getAxisX() - b.getAxisX(), point.getAxisY() - b.getAxisY());

	Point c_a(a.getAxisX() - c.getAxisX(), a.getAxisY() - c.getAxisY());
	Point c_point(point.getAxisX() - c.getAxisX(), point.getAxisY() - c.getAxisY());

	sign [0] = ((a_b.getAxisX() * a_point.getAxisY()) - (a_b.getAxisY() * a_point.getAxisX()) > 0);
	sign [1] = ((b_c.getAxisX() * b_point.getAxisY()) - (b_c.getAxisY() * b_point.getAxisX()) > 0);
	sign [2] = ((c_a.getAxisX() * c_point.getAxisY()) - (c_a.getAxisY() * c_point.getAxisX()) > 0);
	if (sign [0] == sign [1] && sign [1] == sign [2] && sign [0] )
		return (true);
	
	sign [0] = ((a_b.getAxisX() * a_point.getAxisY()) - (a_b.getAxisY() * a_point.getAxisX()) < 0);
	sign [1] = ((b_c.getAxisX() * b_point.getAxisY()) - (b_c.getAxisY() * b_point.getAxisX()) < 0);
	sign [2] = ((c_a.getAxisX() * c_point.getAxisY()) - (c_a.getAxisY() * c_point.getAxisX()) < 0);
	if (sign [0] == sign [1] && sign [1] == sign [2] && sign [0])
		return (true);

	return (false);
}
