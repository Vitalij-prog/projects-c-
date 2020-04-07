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
	//void deleteMenu(List<T>& list); //меню удаления данных
	//void searchMenu(List<T>& list); //меню поиска данных
	//void sortMenu(List<T>& list); // меню сортировки данных
	
};