#pragma once
#include "list.cpp"
#include "binary_file.h"
using namespace std;
template <class T>
class Interface
{
	T ob;
public:
	//void menuChoiceType();
	void menuForStudent();
	//void sortMenu(List<T> & list);
	void sortMenuInBiFile();
	void editMenu(List<T> & list);
	//void editMenu(List<T>& list); 
	//void deleteMenu(List<T>& list); //���� �������� ������
	//void searchMenu(List<T>& list); //���� ������ ������
	//void sortMenu(List<T>& list); // ���� ���������� ������
	
};