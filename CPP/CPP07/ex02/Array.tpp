/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edugonza <edugonza@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:47:51 by edugonza          #+#    #+#             */
/*   Updated: 2026/03/16 21:44:35 by edugonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <stdexcept>

template <typename T>
Array<T>::Array() {
	_size = 0;
	_data = NULL;
	std::cout << "\033[32m[Array]\033[0m Constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	_size = n;
	_data = new T[n]();
	std::cout << "\033[32m[Array]\033[0m Constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other) {
	this->_size = other._size;
	this->_data = new T[this->_size]();
	for (size_t i = 0; i < this->_size; i++)
		this->_data[i] = other._data[i];
	std::cout << "\033[32m[Array]\033[0m Copy Constructor called" << std::endl;

}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (&other != this)
	{
		delete[] this->_data;
		this->_size = other._size;
		this->_data = new T[this->_size]();
		for (size_t i = 0; i < this->_size; i++)
			_data[i] = other._data[i];
	};
	std::cout << "\033[32m[Array]\033[0m Assignment operator called" << std::endl;
	return *this;

}

template <typename T>
T& Array<T>::operator[](const unsigned int index) {
	if (static_cast<size_t>(index) >= this->_size)
		throw std::out_of_range("Index out of bounds");
	return this->_data[index];
	/*
	  std::exception          ← base class (what the subject says to throw)
  ├── std::runtime_error
  │   ├── std::overflow_error
  │   └── std::range_error
  ├── std::logic_error
  │   ├── std::out_of_range
  │   ├── std::invalid_argument
  │   └── std::length_error
  └── std::bad_alloc
  └── std::bad_cast

	Every class in that tree is a std::exception through inheritance.
	So throwing std::out_of_range satisfies the subject's requirement of "an std::exception is thrown"
	— because std::out_of_range inherits from std::exception.
	*/
}

template <typename T>
Array<T>::~Array() {
	delete[] this->_data;
	std::cout << "\033[32m[Array]\033[0m Destructor called" << std::endl;
}

template <typename T>
size_t Array<T>::size() const {
	return this->_size;
}
