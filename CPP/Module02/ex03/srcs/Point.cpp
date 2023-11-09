/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:44:42 by eunwolee          #+#    #+#             */
/*   Updated: 2023/11/09 18:21:10 by eunwolee         ###   ########.fr       */
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

float Point::get_len() const {
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

Point Point::normalization() const {
	float len = get_len();
	return Point(len != 0.0 ? x / len : 0.0 , \
				len != 0.0 ? y / len : 0.0);
}


float Point::dot(const Point &p1, const Point &p2){
	return (p1.get_x() * p2.get_x() + p1.get_y() * p2.get_y());
}

bool bsp(Point const a, Point const b, Point const c, Point const point){

	std::cout << a.get_x() << " " << a.get_y() << std::endl;
	std::cout << b.get_x() << " " << b.get_y() << std::endl;
	std::cout << c.get_x() << " " << c.get_y() << std::endl;
	std::cout << std::endl;
	
	Point _a = a.normalization();
	Point _b = b.normalization();
	Point _c = c.normalization();
	Point _p = point.normalization();

	std::cout << _a.get_x() << " " << _a.get_y() << std::endl;
	std::cout << _b.get_x() << " " << _b.get_y() << std::endl;
	std::cout << _c.get_x() << " " << _c.get_y() << std::endl;
	std::cout << std::endl;
	
	Point ab(_b, _a), bc(_c, _b), ca(_c, _a), ap(_a, _p);

	float abc = Point::dot(ab, bc);
	float bca = Point::dot(bc, ca);
	float pab = Point::dot(ap, ab);

	std::cout << "abc " << abc << std::endl;
	std::cout << "bca " << bca << std::endl;
	std::cout << "pab " << pab << std::endl;

	if (180 - abc - bca < pab)
		return true;
	return false;
}
