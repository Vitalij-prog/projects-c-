#include "interface.h"

//template <class T>
//void Interface<T>::menuChoiceType()
//{
//	int choise;
//	bool exit = true;
//	do
//	{
//		system("cls");
//		cout << "Выберите данные для работы:" << endl;
//		cout << "1.Стандартный тип int" << endl;
//		cout << "2.Люди" << endl;
//		cout << "0.Выход" << endl;
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
		cout << "\tМеню для работы с данными о студентах:" << endl;
		cout << "1.Добавление" << endl;
		cout << "2.Просмотр" << endl;
		cout << "3.Удаление" << endl;
		cout << "4.Сортировка" << endl;
		/*cout << "5.Запись" << endl;*/
		cout << "5.Редактирование" << endl;
		cout << "0.Выход" << endl;
		option = inputValue(0, 5);
		switch (option)
		{
		case 1:
		{
			cout << "\tДобавление данных:" << endl;
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
			/*cout << "Введите возраст для поиска людей: " << endl;
			list.searchDataByAge(inputValue(0, 100));*/
			Interface ob;
			ob.sortMenuInBiFile();
			system("pause");
		}
		break;
		/*case 5:
			if (list.getSize() == 0)
			{
				cout << "Запись данных не выполнена: Отсутствуют данные для записи!" << endl;
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
//		cout << "\tМеню сортировки:" << endl;
//		cout << "1.По ФИО" << endl;
//		cout << "2.По ср. балу" << endl;
//		cout << "3.По доходу" << endl;
//		cout << "4.Доп. задание" << endl;
//		cout << "0.Выход" << endl;
//		option = inputValue(0, 4);
//		switch (option)
//		{
//		case 1:
//			{
//				cout << "\tСортировка по ФИО:" << endl;
//				list.sortListByFIO();
//				list.show();
//				system("pause");
//			}
//			break;
//		case 2:
//			cout << "\tСортировка по ср. балу:" << endl;
//			//list.sortListByMark();
//			//list.show();
//			system("pause");
//			break;
//		case 3:
//			cout << "\tСортировка по доходу:" << endl;
//			list.sortListByIncome();
//			list.show();
//			system("pause");
//			break;
//		case 4:
//			cout << "\tИндивидуальное задание:" << endl;
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
		cout << "\tМеню сортировки:" << endl;
		cout << "1.По ФИО" << endl;
		cout << "2.По ср. балу" << endl;
		cout << "3.По доходу" << endl;
		cout << "4.Задание" << endl;
		cout << "0.Выход" << endl;
		option = inputValue(0, 4);
		switch (option)
		{
		case 1:
			cout << "\tСортировка по ФИО:" << endl;
			bifile.sortByFIO();
			bifile.read(object);
			system("pause");
			break;
		case 2:
			cout << "\tСортировка по ср. балу:" << endl;
			bifile.sortByMark();
			bifile.read(object);
			system("pause");
			break;
		case 3:
			cout << "\tСортировка по доходу:" << endl;
			bifile.sortByIncome();
			bifile.read(object);
			system("pause");
			break;
		case 4:
			cout << "\tИндивидуальное задание:" << endl;
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
	cout << "Выберите данные для редактирования: ";
	index = inputValue(0, (int)sizefile);
	fin.seekg((index - 1) * sizeof(T),ios::beg);
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

