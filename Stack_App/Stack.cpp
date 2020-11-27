#include <iostream>


class Stack {
private:
	unsigned int _size;
	unsigned int _capacity;
	int* _arr;
public:
	Stack(unsigned int capacity)
		:_size(0),
		_capacity(capacity),
		_arr(new int[capacity])
	{
		std::cout << "Constructor\n";
	}

	Stack(const Stack& s)
	{
		std::cout << "Copy constructor\n";
		_size = s._size;
		_capacity = s._capacity;
		_arr = new int[_capacity];
		for (int i = 0; i < _size; i++)
		{
			_arr[i] = s._arr[i];
		}
	}

	bool empty()
	{
		return _size == 0;
	}

	void push(int element)
	{
		if (_size == _capacity) {
			return;
		}
		_arr[_size] = element;
		_size++;
	}

	void pop()
	{
		if (empty()) {
			return;
		}
		_size--;
	}

	int top()
	{
		if (empty()) {
			return -1;
		}
		return _arr[_size - 1];
	}

	~Stack()
	{
		std::cout << "Destructor\n";
		delete[] _arr;
	}
};

int main() {

	Stack st(5);
	Stack st1 = st;
	st.push(1);
	st.push(2);
	st.push(3);
	std::cout << st.top() << std::endl;
	st.pop();
	std::cout << st.top() << std::endl;
}