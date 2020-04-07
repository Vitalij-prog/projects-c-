#include "interface.h"

//template <class T>
//void Interface<T>::menuChoiceType()
//{
//	int choise;
//	bool exit = true;
//	do
//	{
//		system("cls");
//		cout << "�������� ������ ��� ������:" << endl;
//		cout << "1.����������� ��� int" << endl;
//		cout << "2.����" << endl;
//		cout << "0.�����" << endl;
//		choise = inputValue(0, 2);
//		switch (choise)
//		{
//		case 1:
//		{
//			Interface <int> obj;
//			obj.menuForInt();
//		}
//		break;
//		case 2:
//		{
//			Interface <Human> obj;
//			obj.menuForHuman();
//		}
//		case 0:
//			exit = false;
//			break;
//		}
//	} while (exit);
//}

template <class T>
void Interface<T>::menuForStudent()
{
	List<T> list;
	T object;
	ifstream infile;
	Bifile<T> bifile("Student1.txt");
	int option;
	bool exit = true;
	do
	{
		system("cls");
		cout << "\t���� ��� ������ � ������� � ���������:" << endl;
		cout << "1.����������" << endl;
		cout << "2.��������" << endl;
		cout << "3.��������" << endl;
		cout << "4.����������" << endl;
		/*cout << "5.������" << endl;*/
		cout << "5.��������������" << endl;
		cout << "0.�����" << endl;
		option = inputValue(0, 5);
		switch (option)
		{
		case 1:
		{
			cout << "\t���������� ������:" << endl;
			cin >> ob;
			bifile.write(ob);
			system("pause");
		}
		break;
		case 2:
			{
				Bifile<T> infile("student1.txt");
				infile.read(object);						
				system("pause");
			}
			break;
		case 3:
			
			infile.open("student1.txt", ios::in | ios::binary);
			while (infile.good())
			{
				infile >> object;
				if (infile.eof()) break;
				list.pushEnd(object);									
			}
			list.show();
			try
			{
				delMenu(list);
				list.writeList("student1.txt");		
				list.clearList();
			}
			catch (List<Student>::exceptionList &ex)
			{
				ex.what();
				system("pause");
			}
			break;
		case 4:
		{
			/*Interface ob;
			ob.sortMenu(list);*/
			/*cout << "������� ������� ��� ������ �����: " << endl;
			list.searchDataByAge(inputValue(0, 100));*/
			Interface ob;
			ob.sortMenuInBiFile();
			system("pause");
		}
		break;
		/*case 5:
			if (list.getSize() == 0)
			{
				cout << "������ ������ �� ���������: ����������� ������ ��� ������!" << endl;
			}
			else
			{
				list.writeList("student1.txt");
			}
			system("pause");
			break;*/
		case 5:
			bifile.read(object);
			bifile.editData();
			break;
		case 0:
			exit = false;
			break;
		}
	} while (exit);
	
}

//template <class T>
//void Interface<T>::sortMenu(List<T> & list)
//{
//	int option;
//	bool exit = true;
//	do
//	{
//		system("cls");
//		cout << "\t���� ����������:" << endl;
//		cout << "1.�� ���" << endl;
//		cout << "2.�� ��. ����" << endl;
//		cout << "3.�� ������" << endl;
//		cout << "4.���. �������" << endl;
//		cout << "0.�����" << endl;
//		option = inputValue(0, 4);
//		switch (option)
//		{
//		case 1:
//			{
//				cout << "\t���������� �� ���:" << endl;
//				list.sortListByFIO();
//				list.show();
//				system("pause");
//			}
//			break;
//		case 2:
//			cout << "\t���������� �� ��. ����:" << endl;
//			//list.sortListByMark();
//			//list.show();
//			system("pause");
//			break;
//		case 3:
//			cout << "\t���������� �� ������:" << endl;
//			list.sortListByIncome();
//			list.show();
//			system("pause");
//			break;
//		case 4:
//			cout << "\t�������������� �������:" << endl;
//			list.sortInTask();
//			
//			system("pause");
//			break;
//		case 0:
//			exit = false;
//			break;
//		}
//	} while (exit);
//}

template <class T>
void Interface<T>::sortMenuInBiFile()
{
	Bifile<T> bifile("student1.txt");
	T object;
	int option;
	bool exit = true;
	do
	{
		system("cls");
		cout << "\t���� ����������:" << endl;
		cout << "1.�� ���" << endl;
		cout << "2.�� ��. ����" << endl;
		cout << "3.�� ������" << endl;
		cout << "4.�������" << endl;
		cout << "0.�����" << endl;
		option = inputValue(0, 4);
		switch (option)
		{
		case 1:
			cout << "\t���������� �� ���:" << endl;
			bifile.sortByFIO();
			bifile.read(object);
			system("pause");
			break;
		case 2:
			cout << "\t���������� �� ��. ����:" << endl;
			bifile.sortByMark();
			bifile.read(object);
			system("pause");
			break;
		case 3:
			cout << "\t���������� �� ������:" << endl;
			bifile.sortByIncome();
			bifile.read(object);
			system("pause");
			break;
		case 4:
			cout << "\t�������������� �������:" << endl;
			bifile.sortAsInTask();
			bifile.read(object);
			system("pause");
			break;
		case 0:
			exit = false;
			break;
		}
	} while (exit);
}

template <class T>
void Interface<T>::editMenu(List<T> & list)
{
	
	int index, option;
	T object, buf;
	Bifile<T> infile("student1.txt");
	infile.read(object);

	ifstream fin("student1.txt", ios::in | ios::binary);
	fin.seekg(0, ios::end);
	long int sizefile = fin.tellg();
	sizefile /= sizeof(T);
	cout << "�������� ������ ��� ��������������: ";
	index = inputValue(0, (int)sizefile);
	fin.seekg((index - 1) * sizeof(T),ios::beg);
	fin >> buf;
	fin.close();
	bool exit = true;
	do
	{
		system("cls");
		cout << "\t���� ��������������:" << endl;
		cout << "1.���" << endl;
		cout << "2.��. ���" << endl;
		cout << "3.�����" << endl;
		cout << "0.�����" << endl;
		option = inputValue(0, 3);
		switch (option)
		{														
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
	ofstream fout("student1.txt",ios::in | ios::out | ios::binary);				
	fout.seekp(pos, ios::beg);
	fout << buf;
	fout.close();
}

