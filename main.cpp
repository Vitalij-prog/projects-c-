//#include "list.cpp"
//#include "file.h"

#include "interface.cpp"

int main()
{
	setlocale(LC_ALL, "rus");
	Interface<Student> obj;
	obj.menuForStudent();
	system("pause");
}