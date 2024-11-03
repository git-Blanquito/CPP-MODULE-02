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

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main( void )
{
	Point x(1,1);
	Point y(3,3);
	Point z(6,1);
	Point point(3,3);

	if (bsp(x, y, z, point))
		std::cout << 1 << std::endl;
	else
		std::cout << 0 << std::endl;
	return (0);
}
