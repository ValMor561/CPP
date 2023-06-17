#pragma once
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
	T _value;
};

template <typename T>
class ForwardList
{
public:

	ForwardList();
	ForwardList(const ForwardList<T>& other);
	ForwardList(ForwardList<T>&& other);
	~ForwardList();
	void clear() noexcept;
	ListNode<T>* insert_after(ListNode<T>* where, const T& value);
	void push_back(const T& value);
	void push_front(const T& value);
	void remove(const T& value);
	ListNode<T>* first();
	ListNode<T>* last();
	T get(size_t position) const;
	bool empty() const noexcept;
	void reverse() noexcept;
	size_t size() const;
	friend bool operator==(const ForwardList<T>& left, const ForwardList<T>& right)
	{
		if (left.size() != right.size())
			return false;
		double eps = 0.000001;
		size_t size = left.size();
		for (int i = 1; i <= size; ++i)
		{
			if (left.get(i) != right.get(i)) 
				return false;
		}
		return true;
	}
	friend bool operator!=(const ForwardList<T>& left, const ForwardList<T>& right)
	{

		return !(left == right);
	}
private:
	ListNode<T>* _head;
	ListNode<T>* _last;
};

template<typename T>
inline ForwardList<T>::ForwardList()
	:_head(nullptr), _last(nullptr)
{

}

template<typename T>
inline ForwardList<T>::ForwardList(const ForwardList<T>& other)
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
inline ForwardList<T>::ForwardList(ForwardList<T>&& other)
{
	_head = other._head;
	_last = other._last;
	other._head = nullptr;
	other._last = nullptr;
}

template<typename T>
inline ForwardList<T>::~ForwardList()
{
	if (_head)
	{
		clear();
	}
}

template<typename T>
inline void ForwardList<T>::clear() noexcept
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
inline ListNode<T>* ForwardList<T>::insert_after(ListNode<T>* where, const T& value)
{
	if (where == nullptr)
	{
		ListNode<T>* temp = new(std::nothrow) ListNode<T>(_head, value);
		_head = temp;
		if (_last == nullptr)
		{
			_last = _head;
		}
		return _head;
	}
	ListNode<T>* temp = new(std::nothrow) ListNode<T>(where->_next, value);
	if (where->_next == nullptr)
	{
		_last = temp;
	}
	where->_next = temp;
	return temp;
}

template<typename T>
inline void ForwardList<T>::push_back(const T& value)
{
	insert_after(_last, value);
}

template<typename T>
inline void ForwardList<T>::push_front(const T& value)
{
	insert_after(nullptr, value);
}

template<typename T>
inline void ForwardList<T>::remove(const T& value)
{
	ListNode<T>* temp;
	ListNode<T>* newHead = _head;
	while (newHead->_next)
	{
		if (newHead->_next->_value == value)
		{
			temp = newHead->_next;
			newHead->_next = temp->_next;
			delete temp;
		}
		else
		{
			newHead = newHead->_next;
		}
	}
}

template<typename T>
inline ListNode<T>* ForwardList<T>::first()
{
	if (this->empty())
	{
		throw std::runtime_error("It's empty");
	}
	return _head;
}

template<typename T>
inline ListNode<T>* ForwardList<T>::last()
{
	if (this->empty())
	{
		throw std::runtime_error("It's empty");
	}
	return _last;
}

template<typename T>
inline T ForwardList<T>::get(size_t position) const
{
	if (position > this->size())
	{
		throw std::runtime_error("Out of list");
	}
	ListNode<T>* temp = _head;
	while (position - 1)
	{
		temp = temp->_next;
		--position;
	}
	return temp->_value;
}

template<typename T>
inline bool ForwardList<T>::empty() const noexcept
{
	return (_head == nullptr);
}

template<typename T>
inline void ForwardList<T>::reverse() noexcept
{
	if (this->empty())
	{
		throw std::runtime_error("It's empty");
	}
	ListNode<T>* previous = nullptr;
	ListNode<T>* now = _head;
	ListNode<T>* next = _head->_next;
	_last = _head;
	while (next != nullptr)
	{
		now->_next = previous;
		previous = now;
		now = next;
		next = now->_next;
	}
	_head = now;
	now->_next = previous;
}

template<typename T>
inline size_t ForwardList<T>::size() const
{
	ListNode<T>* temp = _head;
	size_t size = 0;
	while (temp)
	{
		temp = temp->_next;
		++size;
	}
	return size;
}


