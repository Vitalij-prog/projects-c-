#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "student.h"
using namespace std;

template<class T>

class Bifile
{
	string puth;
public:
	Bifile(const string);
	~Bifile() {};
	void read(T &);
	void write(T/*, bool flag = true*/);
	void delData();
	void sortByMark();
	void sortByFIO();
	void sortByIncome();
	void sortAsInTask();
	void editData();
};


template<class T>
Bifile<T>::Bifile(const string puth)
{
	this->puth = puth;
}

template<class T>
void Bifile<T>::write(T ob/*, bool flag*/)
{
	ofstream outfile;
	outfile.open(this->puth, ios::app | ios::binary); //добавляем по одному объекту в конец файла
	outfile << ob;
	outfile.close();
}

template<class T>
void Bifile<T>::delData()
{
	ofstream fout;
	fout.open(this->puth,ios::binary);
	fout.close();
}

template<class T>
void Bifile<T>::read(T &obj)															//пока только для просмотра
{
	ifstream infile(this->puth, ios::binary | ios::in);
	int i = 1;
	while (infile)			
	{
		infile >> obj;
		if (infile.eof()) break;
		cout << setfill(' ') << setw(3) << left << i << ")" << obj;
		i++;
	}
	infile.close();
	//cout << "data read succsesful!!" << endl;
}

template<class T>
void Bifile<T>::editData()
{
	int index, option;
	T object, buf;
	/*Bifile<T> infile("student1.txt");*/
	/*infile.read(object);*/

	ifstream fin("student1.txt", ios::in | ios::binary);
	fin.seekg(0, ios::end);
	long int sizefile = fin.tellg();
	sizefile /= sizeof(T);
	cout << "Выберите данные для редактирования: ";
	index = inputValue(0, (int)sizefile);
	fin.seekg((index - 1) * sizeof(T), ios::beg);
	fin >> buf;
	fin.close();
	bool exit = true;
	do
	{
		system("cls");
		cout << "\tМеню редактирования:" << endl;
		cout << "1.ФИО" << endl;
		cout << "2.Ср. бал" << endl;
		cout << "3.Доход" << endl;
		cout << "0.Выход" << endl;
		option = inputValue(0, 3);
		switch (option)
		{														//менять все и делать на редактирование
		case 1:
			buf.setFIO();
			system("pause");
			break;
		case 2:
			buf.setAverageMark();
			system("pause");
			break;
		case 3:
			buf.setIncome();
			system("pause");
			break;
		case 0:
			exit = false;
			break;
		}
	} while (exit);
	int pos = (index - 1) * sizeof(T);
	ofstream fout("student1.txt", ios::in | ios::out | ios::binary);				//проблемы  с записью обратно в файл
	fout.seekp(pos, ios::beg);
	fout << buf;
	fout.close();
}

template <class T>
void Bifile<T>::sortByMark()
{
	ifstream fin;
	fin.open(this->puth, ios::in | ios::binary);
	
	fin.seekg(0, ios::end);
	long int sizefile = fin.tellg();
	sizefile /= sizeof(T);
	fin.close();
	ofstream fout;
	T ob1, ob2, buf;
	if (sizefile < 2)
	{
		cout << "Сортировка данных не тербуется!" << endl;
		return;
	}

	bool flag = 1;
	for (int i = 0; i < sizefile - 1; i++) {
		for (int j = 0; j < sizefile - i - 1; j++) {
			fin.open(this->puth, ios::in | ios::binary);
			fin.seekg(j * sizeof(T), ios::beg);
			fin >> ob1;
			fin.seekg((j+1) * sizeof(T), ios::beg);
			fin >> ob2;
			fin.close();
			if (ob1.getAverageMark() > ob2.getAverageMark()) {

				fout.open(this->puth, ios::in | ios::out | ios::binary);
				fout.seekp(j * sizeof(T), ios::beg);
				fout << ob2;
				fout.seekp((j+1) * sizeof(T), ios::beg);
				fout << ob1;
				fout.close();
			}
		}
	}
	cout << "Данные успешно отсортированы!" << endl;
}


template <class T>
void Bifile<T>::sortByFIO()
{
	ifstream fin;
	fin.open(this->puth, ios::in | ios::binary);

	fin.seekg(0, ios::end);
	long int sizefile = fin.tellg();
	sizefile /= sizeof(T);
	fin.close();
	ofstream fout;
	T ob1, ob2, buf;
	if (sizefile < 2)
	{
		cout << "Сортировка данных не тербуется!" << endl;
		return;
	}
	bool flag = 1;
	for (int i = 0; i < sizefile - 1; i++) {
		for (int j = 0; j < sizefile - i - 1; j++) {
			fin.open(this->puth, ios::in | ios::binary);
			fin.seekg(j * sizeof(T), ios::beg);
			fin >> ob1;
			fin.seekg((j + 1) * sizeof(T), ios::beg);
			fin >> ob2;
			fin.close();
			if (strcmp(ob1.getFIO(), ob2.getFIO()) > 0) {

				fout.open(this->puth, ios::in | ios::out | ios::binary);
				fout.seekp(j * sizeof(T), ios::beg);
				fout << ob2;
				fout.seekp((j + 1) * sizeof(T), ios::beg);
				fout << ob1;
				fout.close();
			}
		}
	}
	cout << "Данные успешно отсортированы!" << endl;
}

template <class T>
void Bifile<T>::sortByIncome()
{
	ifstream fin;
	fin.open(this->puth, ios::in | ios::binary);

	fin.seekg(0, ios::end);
	long int sizefile = fin.tellg();
	sizefile /= sizeof(T);
	fin.close();
	ofstream fout;
	T ob1, ob2, buf;
	if (sizefile < 2)
	{
		cout << "Сортировка данных не тербуется!" << endl;
		return;
	}
	bool flag = 1;
	for (int i = 0; i < sizefile - 1; i++) {
		for (int j = 0; j < sizefile - i - 1; j++) {
			fin.open(this->puth, ios::in | ios::binary);
			fin.seekg(j * sizeof(T), ios::beg);
			fin >> ob1;
			fin.seekg((j + 1) * sizeof(T), ios::beg);
			fin >> ob2;
			fin.close();
			if (ob1.getIncome() > ob2.getIncome()) {

				fout.open(this->puth, ios::in | ios::out | ios::binary);
				fout.seekp(j * sizeof(T), ios::beg);
				fout << ob2;
				fout.seekp((j + 1) * sizeof(T), ios::beg);
				fout << ob1;
				fout.close();
			}
		}
	}
	cout << "Данные успешно отсортированы!" << endl;
}

template <class T>
void Bifile<T>::sortAsInTask()
{
	ifstream fin;
	fin.open(this->puth, ios::in | ios::binary);

	fin.seekg(0, ios::end);
	long int sizefile = fin.tellg();
	sizefile /= sizeof(T);
	fin.close();
	ofstream fout;
	T ob1, ob2, buf;
	if (sizefile < 2)
	{
		cout << "Сортировка данных не тербуется!" << endl;
		return;
	}
	int count = 0;
	int base_value = 55;
	for (int i = 0; i < sizefile; i++) {
		fin.open(this->puth, ios::in | ios::binary);
		fin.seekg(i * sizeof(T), ios::beg);
		fin >> ob1;
		fin.close();
		if (ob1.getIncome() < base_value)
		{
			fin.open(this->puth, ios::in | ios::binary);
			fin.seekg(count * sizeof(T), ios::beg);
			fin >> ob2;
			fin.close();

			fout.open(this->puth, ios::in | ios::out | ios::binary);
			fout.seekp(count * sizeof(T), ios::beg);
			fout << ob1;
			fout.seekp(i * sizeof(T), ios::beg);
			fout << ob2;
			fout.close();
			count++;
		}
	}

	for (int i = count, k = 0; i < sizefile - 1; k++, i++) {
		for (int j = count; j < sizefile - k - 1; j++) {
			fin.open(this->puth, ios::in | ios::binary);
			fin.seekg(j * sizeof(T), ios::beg);
			fin >> ob1;
			fin.seekg((j + 1) * sizeof(T), ios::beg);
			fin >> ob2;
			fin.close();
			if (ob1.getIncome() < ob2.getIncome()) {

				fout.open(this->puth, ios::in | ios::out | ios::binary);
				fout.seekp(j * sizeof(T), ios::beg);
				fout << ob2;
				fout.seekp((j + 1) * sizeof(T), ios::beg);
				fout << ob1;
				fout.close();
			}
		}
	}
	cout << "Данные успешно отсортированы!" << endl;
}