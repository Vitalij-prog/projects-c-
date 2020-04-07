#include "student.h"

Student::Student()
{
	average_mark = 0;
	income = 0;
}

Student::Student(const Student& st)
{
	strcpy_s(this->FIO, strlen(st.FIO) + 1, st.FIO);
	strcpy_s(this->num_group, strlen(st.num_group) + 1, st.num_group);
	this->average_mark = st.average_mark;
	this->income = st.income;
}

istream & operator>>(istream & in, Student &ob)
{
	cout << "Введите ФИО: ";
	in.getline(ob.FIO,40);
	cout << "Введите номер группы: ";
	in >> ob.num_group;
	cout << "Введите средний бал: ";
	ob.average_mark=input(4.0,10.0);
	cout << "Введите ср. доход на одного члена семьи: ";
	ob.income=input(0.0,10000.0);
	return in;
}

ostream & operator<<(ostream & out, const Student &ob)
{
	out.fill(' ');
	out << setw(40) << left << ob.FIO << "|"
		<< setw(7) << left << ob.num_group << "|"
		<< setw(5) << left << ob.average_mark << "|"
		<< setw(5) << left << ob.income << "|" << endl;
	return out;
}

//ifstream & operator>>(ifstream &in, Student& ob)
//{
//	in >> ob.FIO;
//	in >> ob.num_group;
//	in >> ob.average_mark;
//	in >> ob.income;
//	return in;
//}
//ofstream & operator<<(ofstream &out, const Student & ob)
//{
//	out << ob.FIO << " " << ob.num_group << " " << ob.average_mark << " " << ob.income;
//	return out;
//}

ifstream & operator>>(ifstream &in, Student& ob)
{
	/*in.read(ob.FIO, sizeof(ob.FIO));
	in.read(ob.num_group, sizeof(ob.num_group));
	in.read(reinterpret_cast<char*>(&ob.average_mark), sizeof(ob.average_mark));
	in.read(reinterpret_cast<char*>(&ob.income), sizeof(ob.income));*/
	in.read(reinterpret_cast<char*>(&ob), sizeof(Student)); 
	return in;
}
ofstream & operator<<(ofstream &out, Student & ob)						//убрал константность обекта
{
	/*out.write(ob.FIO, sizeof(ob.FIO));
	out.write(ob.num_group, sizeof(ob.num_group));
	out.write(reinterpret_cast<char*>(&ob.average_mark), sizeof(ob.average_mark));
	out.write(reinterpret_cast<char*>(&ob.income), sizeof(ob.income));*/
	out.write(reinterpret_cast<char*>(&ob), sizeof(Student));
	return out;
}

char* Student::getFIO()
{
	return this->FIO;
}

double Student::getAverageMark()
{
	return this->average_mark;
}
double Student::getIncome()
{
	return this->income;
}

Student & Student::operator=(const Student &ob)
{
	strcpy_s(this->FIO, strlen(ob.FIO) + 1, ob.FIO);
	strcpy_s(this->num_group, strlen(ob.num_group) + 1, ob.num_group);
	this->average_mark = ob.average_mark;
	this->income = ob.income;
	return *this;
}

void Student::setFIO()

{
	char str[40]; 
	cout << "Введите новое значение поля ФИО: ";
	cin.getline(str,40);
	strcpy_s(this->FIO, strlen(str) + 1, str);
	cout << "Поле успешно изменено!" << endl;
}
void Student::setAverageMark()
{
	cout << "Введите новое значение поля Cр. бал: ";
	this->average_mark = input(4.0, 10.0);
	cout << "Поле успешно изменено!" << endl;
}
void Student::setIncome()
{
	cout << "Введите новое значение поля Доход: ";
	this->income = input(0.0, 10000.0);
	cout << "Поле успешно изменено!" << endl;
}
