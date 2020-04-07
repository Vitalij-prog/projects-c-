#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template<class T>

class Myfile
{
	string puth;
public:
	Myfile(const string);
	~Myfile() {};
	void read(T &);
	void write(T, bool flag = true);
	void delData();
};


template<class T>
Myfile<T>::Myfile(const string puth)
{
	this->puth = puth;
}

template<class T>
void Myfile<T>::write(T ob, bool flag)
{
	ofstream outfile(this->puth, ios::out|ios::app);
	outfile << ob;
	if (flag)
	{
		outfile << endl;
	}
}

template<class T>
void Myfile<T>::delData()
{
	ofstream fout;
	fout.open(this->puth);
	fout.close();
}

//template<class T>
//void Myfile<T>::read(T & list)
//{
//	ifstream infile(this->puth, ios::in);
//	while (!infile.eof())			
//	{
//		infile>>list;	
//		cout << buffer << endl;			
//	}
//
//	infile >> ob;
//	cout << "data read succsesful!!" << endl;
//}
