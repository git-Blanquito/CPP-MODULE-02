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

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath> 

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		Fixed(Fixed&& other) noexcept;
		Fixed& operator=(Fixed&& other) noexcept;
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int i);
		float toFloat( void ) const;
		int toInt(void) const;
	private:
		int RawBits;
		static const int FractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fi);

#endif
