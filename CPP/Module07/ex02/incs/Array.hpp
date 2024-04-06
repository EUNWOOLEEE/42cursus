#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& obj);

		Array& operator =(const Array& obj);

		unsigned int getArrSize(void) const { return len; }

		T getArrElement(unsigned int idx) const {
			if (idx >= n)
				throw std::exception;
			return arr[idx];
		}

		void setArrElement(unsigned int idx, T src) {
			if (idx >= n)
				throw std::exception;
			arr[idx] = src;
		}
	
	private:
		T*		arr;
		size_t	len;
};

#endif