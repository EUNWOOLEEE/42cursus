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
		~Array(void);

		Array& operator =(const Array& obj);

		unsigned int	size(void) const;
	
	private:
		T*		arr;
		size_t	len;
};


template <typename T>
Array<T>::Array(void) : arr(NULL), len(0) {
	std::cout << "[OCCF] Bureaucrat defalut constructor called\n";
}

template <typename T>
Array<T>::Array(unsigned int n) : arr(NULL), len(n) {
	std::cout << "[OCCF] Bureaucrat constructor called\n";

	if (len != 0)
		arr = new T[len];
}

template <typename T>
Array<T>::Array(const Array& obj) : arr(NULL), len(obj.len)  {
	std::cout << "[OCCF] Bureaucrat copy constructor called\n";

	for (size_t i = 0; i < len; i++)
		arr[i] = obj.arr[i];
}

template <typename T>
Array<T>::~Array(void) {
	if (arr != NULL)
		delete[] arr;
}

template <typename T>
Array<T>& Array<T>::operator =(const Array& obj) {
	std::cout << "[OCCF] Bureaucrat copy assignment operator called\n";

	if (this != &obj) {
		len = obj.len;

		if (arr != NULL)
			delete[] arr;
		
		if (len != 0){
			arr = new T[len];

			for (size_t i = 0; i < len; i++)
				arr[i] = obj.arr[i];
		}
	}

	return *this;
}

template <typename T>
unsigned int Array<T>::size(void) const { return len; }

#endif