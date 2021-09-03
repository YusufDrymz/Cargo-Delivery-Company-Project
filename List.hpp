#ifndef LIST_HPP
#define LIST_HPP
#include "Node.hpp"

template<typename T>
class List{
	Node<T>* dummyHead;
	public:
		List();
		List(const List<T>& obj);
		~List();
		bool isEmpty()const;
		const Node<T>* begin()const;
		Node<T>* begin();
		void push_front(const T& data);
		void push_back(const T& data);
		void erase(Node<T>* node);
		void pop_front();
		void pop_back();
		List<T>& operator=(const List<T>& obj);
};


template<class T>
List<T>::List() : dummyHead(NULL){	dummyHead = new Node<T>();	}

template<class T>
List<T>::List(const List<T>& obj) : List<T>(){
	*this = obj;
}

template<class T>
List<T>::~List(){
	while(!isEmpty()){
		pop_front();
	}
	delete dummyHead;
}

template<class T>
bool List<T>::isEmpty()const{	return dummyHead->next == NULL;	}

template<class T>
const Node<T>* List<T>::begin()const{	return dummyHead->next; }

template<class T>
Node<T>* List<T>::begin(){	return dummyHead->next; }

template<class T>
void List<T>::push_front(const T& data){
	dummyHead->next = new Node<T>(data,dummyHead->next);
}

template<class T>
void List<T>::push_back(const T& data){
	Node<T>* temp = dummyHead;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = new Node<T>(data);
}

template<class T>
void List<T>::erase(Node<T>* node){
	Node<T>* temp = dummyHead;
	
	while(temp->next != NULL && temp->next != node){
		temp = temp->next;
	}
	
	if (temp->next == node) {
		temp->next = temp->next->next;
		delete node;
	}
		
}

template<class T>
void List<T>::pop_front(){
	if(isEmpty())
		throw "Hata : List::pop_front() liste zaten bos";
	Node<T>* temp = dummyHead->next;
	dummyHead->next = dummyHead->next->next;
	delete temp;
}

template<class T>
void List<T>::pop_back(){
	if(isEmpty())
		throw "Hata : List::pop_back() liste zaten bos";
	Node<T>* temp = dummyHead;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	delete temp->next;
	temp->next = NULL;
}

template<class T>
List<T>& List<T>::operator=(const List<T>& obj){
	if(this != &obj){
		while(!isEmpty()){
			pop_front();
		}
		Node<T>* iterator = dummyHead;
		Node<T>* obj_iterator = obj.dummyHead;
		while(obj_iterator->next != NULL){
			iterator->next = new Node<T>(obj_iterator->next->data);
			iterator = iterator->next;
			obj_iterator = obj_iterator->next;
		}
	}
	return *this;
}



#endif 
