#ifndef STACK_HPP
#define STACK_HPP

#include "List.hpp"
template<class T>
class Stack{
	List<T> l;
	public:
		T top()const;
		void pop();
		void push(const T& data);
		bool isEmpty()const;
};

template<class T>
T Stack<T>::top()const{	
	if(isEmpty())
		throw "Hata : Stack::top() methodunda olustu (stack suanda bos)";
	return l.begin()->data;
}

template<class T>
void Stack<T>::pop(){
	if(isEmpty())
		throw "Hata : Stack::pop() methodunda olustu (stack suanda bos)";
	l.pop_front();
}

template<class T>
void Stack<T>::push(const T& data){
	l.push_front(data);
}

template<class T>
bool Stack<T>::isEmpty()const{
	return l.isEmpty();
}

#endif
