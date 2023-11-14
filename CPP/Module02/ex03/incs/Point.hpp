/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:41:46 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/14 16:45:20 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>

class Point{

public:
	Point();
	Point(const float _x, const float _y);
	Point(const Point& obj);
	Point(const Point& p1, const Point& p2);
	~Point();
	Point& operator =(const Point& src);

	float get_x() const;
	float get_y() const;

	
private:
	const float x;
	const float y;

};

Point minus(const Point &start, const Point &end);
float cross(const Point &vertex, const Point &point);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif