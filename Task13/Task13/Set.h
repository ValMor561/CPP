#pragma once
#include "Task13Api.hpp"
#include <iostream>

template <typename T>
class Set
{
public:
	Set();
	Set(size_t capacity);
	Set(const Set& other);
	Set(Set&& other) noexcept;
	~Set();
	void AddElement(T value);
	void RemoveElement(T value);

	Set<T>& operator=(const Set<T>& other);
	Set<T>& operator=(Set<T>&& other) noexcept;
	Set<T> operator+(const Set<T>& other) const;
	Set<T> operator*(const Set<T>& other) const;
	Set<T> operator-(const Set<T>& other) const;

	template <typename K, typename F>
	bool FindElement(K value, F functor) const;

	T* GetData() const; // для тестов
	size_t GetSize() const; // для тестов
	friend std::istream& operator>>(std::istream& stream, Set<T>& c)
	{
		for (int i = 0; i < c._capacity; ++i)
		{
			stream >> c._dataPtr[i];
			++c._size;
		}
		return stream;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Set<T>& c)
	{
		for (int i = 0; i < c._capacity; ++i)
		{
			stream << c._dataPtr[i] << ' ';
		}
		return stream;
	}



private:
	T* _dataPtr;
	size_t _capacity;
	size_t _size;
};

template<typename T>
inline Set<T>::Set()
	:_size(0), _capacity(0), _dataPtr(nullptr)
{

}

template<typename T>
inline Set<T>::Set(size_t capacity)
	:_capacity(capacity), _size(0)
{
	_dataPtr = new T[_capacity];

}

template<typename T>
inline Set<T>::Set(const Set& other)
	:_dataPtr(nullptr), _capacity(other._capacity), _size(other._size)
{
	_dataPtr = new T[_capacity];
	for (int i = 0; i < _capacity; ++i)
		_dataPtr[i] = other._dataPtr[i];
}

template<typename T>
inline Set<T>::Set(Set&& other) noexcept
	:_dataPtr(other._dataPtr), _capacity(other._capacity), _size(other._size)
{
	other._dataPtr = nullptr;
	other._capacity = 0;
	other._size = 0;
}

template<typename T>
inline Set<T>::~Set()
{
	delete[] _dataPtr;
}

template<typename T>
inline void Set<T>::AddElement(T value)
{
	if (_capacity < _size)
		throw std::runtime_error("Out of set");
	bool inSet = false;
	for (int i = 0; i < _size; ++i)
	{
		if (_dataPtr[i] == value)
			inSet = true;
	}
	if (!inSet)
	{
		_dataPtr[_size] = value;
		++_size;
	}
}

template<typename T>
inline void Set<T>::RemoveElement(T value)
{
	for (int i = 0; i < _size; ++i)
	{
		if (_dataPtr[i] == value)
			for (i; i < _size; ++i)
				_dataPtr[i] = _dataPtr[i + 1];
	}
	--_size;
}

template<typename T>
inline Set<T>& Set<T>::operator=(const Set<T>& other)
{
	delete[] _dataPtr;
	_dataPtr = new T[_capacity = other._capacity];
	_size = other._size;
	for (int i = 0; i < _capacity; ++i)
		_dataPtr[i] = other._dataPtr[i];
	return *this;
}

template<typename T>
inline Set<T>& Set<T>::operator=(Set<T>&& other) noexcept
{
	_capacity = other._capacity;
	_size = other._size;

	delete[] _dataPtr;
	_dataPtr = other._dataPtr;

	other._dataPtr = nullptr;
	other._capacity = 0;
	other._size = 0;

	return *this;
}

template<typename T>
inline Set<T> Set<T>::operator+(const Set<T>& other) const
{
	Set<T>newSet(_capacity + other._capacity);
	for (int i = 0; i < _size; ++i)
	{
		newSet.AddElement(_dataPtr[i]);
	}
	for (int i = 0; i < other._size; ++i)
	{
		newSet.AddElement(other._dataPtr[i]);
	}
	// Если пересечение было не пустое?
	//addelement не допустит
	return newSet;
}

template<typename T>
inline Set<T> Set<T>::operator*(const Set<T>& other) const
{
	size_t mincapacity = 0;
	if (_capacity < other._capacity)
		mincapacity = _capacity;
	else
		mincapacity = other._capacity;
	Set<T>newSet(mincapacity);
	for (int i = 0; i < _size; ++i)
	{
		// У вас этот цикл дублируется во многих местах, вынести его
		// это как да и используется всего два раза
		for (int j = 0; j < other._size; ++j)
			if (_dataPtr[i] == other._dataPtr[j])
				newSet.AddElement(_dataPtr[i]);
	}
	return newSet;
}

template<typename T>
inline Set<T> Set<T>::operator-(const Set<T>& other) const
{
	Set<T>newSet(*this);
	for (int i = 0; i < _size; ++i)
	{
		for (int j = 0; j < other._size; ++j)
		{
			if (_dataPtr[i] == other._dataPtr[j])
				newSet.RemoveElement(_dataPtr[i]);
		}
	}
	return newSet;
}

template<typename T>
inline T* Set<T>::GetData() const
{
	return _dataPtr;
}

template<typename T>
inline size_t Set<T>::GetSize() const
{
	return _size;
}


template<typename T>
template<typename K, typename F>
inline bool Set<T>::FindElement(K value, F functor) const
{
	for (int i = 0; i < _size; ++i)
	{
		if (functor(_dataPtr[i], value))
			return true;
	}
	return false;
}
