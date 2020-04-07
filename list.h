#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
template <class T>
struct element
{
	T data;
	element<T> *next;
	element<T> *prev;
};
template <class T>
class List
{
	int size;
	element<T> *begin;
	element<T> *end;
	element<T>* getElement(int position); //возвращает указатель на элемент списка
public:
	class exceptionList
	{
		char msg[80];
	public:
		exceptionList(const char*);
		~exceptionList();
		void what();
	};


	List();
	~List();
	//void pushBegin(T);
	void pushEnd(T);
	void popBegin();
	void popEnd();
	void popOnPosition(int position);
	int getSize();
	//T returnPop();
	void show();
	void showReverse();
	void clearList();
	T delWithReturnElement();		// в примере этот метод в private
	T& getElementFromList(int position);
	void setOnPsition(T ob, int position);
	void writeList(const string);					
	void readList(const string);

	T& operator[](int pos);
	void sortListByMark();
	void sortListByIncome();
	void sortListByFIO();
	void sortInTask();

	void searchData(T value);

};

template <typename T>
T inputValue(T range1, T range2);