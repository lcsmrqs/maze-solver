#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class T>
class Stack
{
private:
	class Node
	{
	public:
		Node(T data)
		{
			next = nullptr;
			this->data = data;
		}
		~Node() { next = nullptr; }

		Node *next;
		T data;
	};

	Node *_top;

public:
	Stack() { _top = nullptr; }
	~Stack()
	{
		while(!this->empty())
			this->pop();
	}

	void push(T data)
	{
		Node *newNode = new Node(data);

		newNode->next = this->_top;
		this->_top = newNode;
	}

	void pop()
	{
		if(!this->empty())
		{
			Node *n = this->_top;
			this->_top = this->_top->next;
			delete n;
		}
	}

	T top()
	{
		if(!this->empty())
			return this->_top->data;

		std::cerr << "Empty stack!" << std::endl;
		exit(1);
	}
	
	bool empty()
	{
		return (this->_top == nullptr);
	}
};

#endif
