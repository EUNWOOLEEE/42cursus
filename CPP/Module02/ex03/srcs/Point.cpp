/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:44:42 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/14 16:45:16 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float _x, const float _y) : x(_x), y(_y) {}

Point::Point(const Point& obj) : x(obj.x), y(obj.y) {
	*this = obj;
}

Point::Point(const Point& p1, const Point& p2) \
			: x(p1.x - p2.x), y(p1.y - p2.y) {}

Point::~Point(){}

Point& Point::operator =(const Point& src){
	(void)src;
	return *this;
}

float Point::get_x() const { return x; }

float Point::get_y() const { return y; }

Point minus(const Point &start, const Point &end){
	Point p(end.get_x() - start.get_x(), end.get_y() - start.get_y());
	return p;
}

float cross(const Point &vertex, const Point &point){
	return (vertex.get_x() * point.get_y() - vertex.get_y() * point.get_x());
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	float _a = cross(minus(a, b), minus(a, point));
	float _b = cross(minus(b, c), minus(b, point));
	float _c = cross(minus(c, a), minus(c, point));
	
	if ((_a < 0.0 && _b < 0.0 && _c < 0.0) \
		|| (_a >= 0.0 && _b >= 0.0 && _c >= 0.0))
		return true;
	return false;
}
