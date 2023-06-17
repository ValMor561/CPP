#pragma once

template <typename T>
class Array
{
public:
	Array(int size);
	~Array();
	Array(const Array& other);
	Array(Array &&other) noexcept;

	Array<T>& operator=(const Array &other);
	Array<T>& operator=(Array&& other) noexcept;
	T operator[](int index) const;
	int capacity() const;
	int size();
	void push_back(T value);
	T* begin();
	const T* begin() const;
	T* end();
	const T* end() const;

private:
	T* _data;
	int _size;
	int _indexOfElement;
	void resize();
};

template<typename T>
inline Array<T>::Array(int size)
	:_size(size),_indexOfElement(0)
{
	_data = new T[_size];
}

template<typename T>
inline Array<T>::~Array()
{
	delete[] _data;
}

template<typename T>
inline Array<T>::Array(const Array & other)
	:_data(nullptr),_size(other._size),_indexOfElement(other._indexOfElement)
{
	_data = new T[_size];
	for (int i = 0; i < _size; ++i)
		_data[i] = other._data[i];
}

template<typename T>
inline Array<T>::Array(Array && other) noexcept
	:_data(other._data),_size(other._size)
{
	other._data = nullptr;
	other._size = 0;
}

template<typename T>
inline Array<T>& Array<T>::operator=(const Array & other)
{
	if (this == &other)
		return *this;
	delete[] _data;
	_data = new T[_size = other._size];
	_indexOfElement = other._indexOfElement;
	for (int i = 0; i < _size; ++i)
		_data[i] = other._data[i];
	return *this;
}

template<typename T>
inline Array<T>& Array<T>::operator=(Array&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}
	_size = other._size;
	_indexOfElement = other._indexOfElement;

	delete[] _data;
	_data = other._data;

	other._data = nullptr;
	other._size = 0;
	other._indexOfElement = 0;

	return *this;
	
}

template<typename T>
inline T Array<T>::operator[](int index) const
{
	if (index >= _size)
		throw std::runtime_error("Bad index");
	return _data[index];
}

template<typename T>
inline int Array<T>::capacity() const
{
	return _size;
}

template<typename T>
inline int Array<T>::size()
{
	return _indexOfElement;
}

template<typename T>
inline void Array<T>::push_back(T value)
{
	if (_indexOfElement > _size - 1)
		resize();
	_data[_indexOfElement] = value;
	++_indexOfElement;
}

template<typename T>
inline T* Array<T>::begin()
{
	return _data;
}

template<typename T>
inline const T* Array<T>::begin() const
{
	return _data;
}

template<typename T>
inline T* Array<T>::end()
{
	return &_data[_size];
}

template<typename T>
inline const T* Array<T>::end() const
{
	return &_data[_size];
}

template<typename T>
inline void Array<T>::resize()
{
	T* tempData;
	_size *= 2;
	tempData = new T[_size];
	for (int i = 0; i < _size / 2; ++i)
	{
		tempData[i] = _data[i];
	}
	delete[] _data;
	_data = new T[_size];
	for (int i = 0; i < _size / 2; ++i)
	{
		_data[i] = tempData[i];
	}
	delete[] tempData;
}

