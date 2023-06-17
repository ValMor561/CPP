#pragma once
#include <iterator>

template <typename T>
struct ListNode
{
	ListNode(ListNode<T>* next = nullptr, T value = T())
		:_next(next), _value(value)
	{

	}
	ListNode(const ListNode<T>& other) = delete;
	ListNode(ListNode<T>&& other) = delete;
	ListNode<T>& operator=(const ListNode<T>& other) = delete;
	ListNode<T>& operator=(ListNode<T>&& other) = delete;
	ListNode<T>* _next;
	ListNode<T>* _prev;
	T _value;
};

template <typename T>
class Iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
public:
	Iterator(ListNode<T>* node)
		:_node(node)
	{

	}
	Iterator(const Iterator& other) = default;
	Iterator operator++()
	{
		_node = _node->_next;
		return *this;
	}
	Iterator operator++(int)
	{
		auto copy = *this
			_node = _node->_next;
		return copy;
	}
	Iterator operator--()
	{
		_node = _node->_prev;
		return *this;
	}
	Iterator operator--(int)
	{
		auto copy = *this
			_node = _node->_prev;
		return copy;
	}
	T* operator->()
	{
		return &(_node->_value);
	}
	T& operator*()
	{
		return _node->_value;
	}
	bool operator==(Iterator other)
	{
		if (_node->_value != other._node->_value || _node->_next != other._node->_next)
			return false;
		return true;
	}
	bool operator!=(Iterator other)
	{
		return !(_node == other._node);
	}
private:
	ListNode<T>* _node
};

template <typename T>
class LinkedList 
{
public:

	
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList<T>& other);
	LinkedList(LinkedList<T>&& other);
	LinkedList<T>& operator=(const LinkedList<T>& other);
	LinkedList<T>& operator=(LinkedList<T>&& other);
	bool empty();
	Iterator<T> insert(Iterator<T> where, T value);
	private:
	ListNode<T>* _head;
	ListNode<T>* _last;
};

template<typename T>
inline LinkedList<T>::LinkedList()
	:_head(nullptr), _last(nullptr)
{
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	ListNode<T>* temp;
	while (_head)
	{
		temp = _head;
		_head = _head->_next;
		delete temp;
	}
	_last = nullptr;
}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList& other)
	:_head(nullptr), _last(nullptr)
{
	ListNode<T>* temp = other._head;
	while (temp != nullptr)
	{
		push_back(temp->_value);
		temp = temp->_next;
	}
}

template<typename T>
inline LinkedList<T>::LinkedList(LinkedList<T>&& other)
{
	_head = other._head;
	_last = other._last;
	other._head = nullptr;
	other._last = nullptr;
}

template<typename T>
inline LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{

}

template<typename T>
inline LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& other)
{
	// TODO: вставьте здесь оператор return
}

template<typename T>
inline bool LinkedList<T>::empty()
{
	return (_head == nullptr);
}

template<typename T>
inline Iterator<T> LinkedList<T>::insert(Iterator<T> where, T value)
{
	
}

