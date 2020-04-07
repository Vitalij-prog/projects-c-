#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Student
{
	char FIO[40];
	char num_group[7];
	double average_mark;
	double income;
public:
	Student();
	~Student() {} 
	Student(const Student&);
	char* getFIO();
	double getAverageMark();
	double getIncome();
	void setFIO();
	void setAverageMark();
	void setIncome();

	Student & operator=(const Student &ob);
	friend istream & operator>>(istream &, Student&);
	friend ostream & operator<<(ostream &, const Student &);
	friend ifstream & operator>>(ifstream &, Student&);
	friend ofstream & operator<<(ofstream &,  Student &);

};

template <typename T>
T input(T range1, T range2)
{
	T num;
	while (true)
	{
		cin >> num;
		if (num >= range1 && num <= range2 && cin.get() == '\n')
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Некоректные данные!" << endl;
			cout << "Значения данного поля должны находиться в пределах от " << range1 << " до " << range2 << endl;
			cout << "Повторите ввод: ";
		}
	}
	return num;
}