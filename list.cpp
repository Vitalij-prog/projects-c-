#include "list.h"
//#include "student.h"
#include "file.h"
#include "binary_file.h"
template <class T>
List<T>::List()
{
	size = 0;
	begin = NULL;
	end = NULL;
}
template <class T>
List<T>::~List()
{
	while (begin != NULL)
	{
		element<T> *temp = begin;
		begin = begin->next;
		delete temp;
	}
	delete begin;
}

/*template <class T>
void List<T>::pushBegin(T value)
{
	element<T> *ptr = new element<T>;
	ptr->data = value;
	if (begin)
	{
		ptr->next = begin;
		begin->prev = ptr;
		ptr->prev = NULL;
		begin = ptr;
	}
	else
	{
		begin = end = ptr;
		begin->next = end->prev = NULL;
		begin = end = ptr;

	}
	++size;
	cout << "Количество обЪектов: " << size << endl;
}*/

template <class T>
void List<T>::pushEnd(T value)
{
	element<T> *ptr = new element<T>;
	ptr->data = value;
	if (end)
	{
		ptr->prev = end;
		end->next = ptr;
		ptr->next = NULL;
		end = ptr;
	}
	else
	{
		begin = end = ptr;
		begin->next = end->prev = NULL;
	}
	++size;
}
template <class T>
void List<T>::popBegin()
{
	popOnPosition(0);
}
template <class T>
void List<T>::popEnd()
{
	popOnPosition(size - 1);
}
template <class T>
void List<T>::popOnPosition(int position)
{
	if (!begin)
	{
		throw List<T>::exceptionList("Данные отсутствуют! Удаление невозможно.");
	}
	if (begin != NULL && position >= this->size)
	{
		throw List<T>::exceptionList("Удаление невозможно: данныx по вашему запросу не существует.");
	}
	element<T> *temp = getElement(position);
	if (temp == begin)
	{
		begin = begin->next;
		begin->prev = NULL;
	}
	else
	{
		if (temp == end)
		{
			end = end->prev;
			end->next = NULL;
		}
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
	}
	delete temp;
	--size;
}
// возвращает указатель на элемент структуры
template<class T>
element<T>* List<T>::getElement(int position)
{
	element<T>* temp;
	temp = begin;
	for (int i = 0; i < position; i++)
		temp = temp->next;
	return temp;
}
template<class T>						//протестировать
void List<T>::setOnPsition(T object, int position)
{
	element<T>* temp;
	temp = begin;
	for (int i = 0; i < position; i++)
		temp = temp->next;
	temp->data = object;

}
template<class T>
T& List<T>::getElementFromList(int position)
{
	element<T>* temp = getElement(position);
	return temp->data;
}
template<class T>
T& List<T>::operator[](int pos)
{
	if (!begin)
	{
		T empty;
		return empty;
	}
	return (getElement(pos))->data;
}

template <class T>
int List<T>::getSize()
{
	return size;
}

template <class T>
void List<T>::show()										//добавить исключение
{
	int i = 1;
	element<T>* temp = begin;
	if (temp == NULL)
	{
		cout << "Список пуст, данные отсутствуют!" << endl;
	}
	while (temp != NULL)
	{
		cout << i << ")  " << temp->data ;
		/*cout.setf(ios::showpos);
		cout << temp->data;
		cout.unsetf(ios::showpos);
		cout.setf(ios::hex | ios::uppercase);
		cout << "\t| hex = " << temp->data << endl;
		cout.unsetf(ios::hex | ios::uppercase);*/
		temp = temp->next;
		i++;
	}

}

template <class T>
void List<T>::showReverse()
{
	element<T>* temp = end;
	for (int i = 0; i < size; i++)
	{
		cout << temp->data << endl;
		temp = temp->prev;
	}
}

template <class T>
void List<T>::clearList()
{
	if (begin == NULL)
	{
		if (!begin)
		{
			throw List<T>::exceptionList("Удалить все данные невозможно: данные отсутствуют.");
		}
	}
	while (begin != NULL)
	{
		element<T> *temp = begin;
		begin = begin->next;
		delete temp;
	}
	begin = NULL;
	end = NULL;
	size = 0;

}
//------------------------------------------------------------------------

template<class T>
T List<T>::delWithReturnElement()
{
	T obj;
	if (begin == NULL)
	{
		cout << "Список пуст, удаление невозможно!" << endl;
		return obj;
	}
	element<T>*temp = begin;
	begin = begin->next;

	obj = temp->data;
	delete temp;
	return obj;
}

template <class T>
void List<T>::writeList(const string str)
{
	element<T> *temp;
	temp = begin;
	//Myfile<T> f(str);
	Bifile<T> f(str);
	f.delData();
	/*bool flag = true;*/
	while (temp != NULL)
	{
		/*if (temp->next == NULL)
		{
			flag = false;
		}*/
		f.write(temp->data/*,flag*/);			// запись данных самого объекта
		temp = temp->next;
	}
	//cout << "Данные успешно записаны в файл!!!" << endl;
}

//template <class T>
//void List<T>::readList(const string)
//{
//	element<T> *temp;
//	temp = begin;
//	while (temp != NULL)
//	{
//		temp->data.write(fout);			
//		temp = temp->next;
//	}
//}
template <class T>
void List<T>::sortListByMark()
{
	if (this->size < 2)
	{
		cout << "Сортировка данных не тербуется!" << endl;
		return;
	}
	element<T> *temp1;

	bool flag = 1;
	T buf;
	while (flag)
	{
		flag = 0;
		temp1 = begin;
		while (temp1->next != NULL)
		{
			if (temp1->data.getAverageMark() > temp1->next->data.getAverageMark())
			{
				buf = temp1->data;
				temp1->data = temp1->next->data;
				temp1->next->data = buf;
				flag = 1;
			}
			temp1 = temp1->next;
		}
	}
	cout << "Данные успешно отсортированы!" << endl;
}
template <class T>
void List<T>::sortListByIncome()
{
	if (this->size < 2)
	{
		cout << "Сортировка данных не тербуется!" << endl;
		return;
	}
	element<T> *temp1;

	bool flag = 1;
	T buf;
	while (flag)
	{
		flag = 0;
		temp1 = begin;
		while (temp1->next != NULL)
		{
			if (temp1->data.getIncome() > temp1->next->data.getIncome())
			{
				buf = temp1->data;
				temp1->data = temp1->next->data;
				temp1->next->data = buf;
				flag = 1;
			}
			temp1 = temp1->next;
		}
	}
	cout << "Данные успешно отсортированы!" << endl;
}
template <class T>
void List<T>::sortListByFIO()
{
	if (this->size < 2)
	{
		cout << "Сортировка данных не тербуется!" << endl;
		return;
	}
	element<T> *temp1;

	bool flag = 1;
	T buf;
	while (flag)
	{
		flag = 0;
		temp1 = begin;
		while (temp1->next != NULL)
		{
			if (strcmp(temp1->data.getFIO(), temp1->next->data.getFIO())>0)
			{
				buf = temp1->data;
				temp1->data = temp1->next->data;
				temp1->next->data = buf;
				flag = 1;
			}
			temp1 = temp1->next;
		}
	}
	cout << "Данные успешно отсортированы!" << endl;
}


template <class T>
void List<T>::sortInTask()
{
	if (this->size < 2)
	{
		cout << "Сортировка данных не требуется: записи отсутствуют или найдена только одна запись.." << endl;
		return;
	}
	element<T> *temp=begin;
	List<T> newlist;
	double twice_base_value = 51;
	while (temp)
	{
		if (temp->data.getIncome() < twice_base_value)
		{
			newlist.pushEnd(temp->data);
		}
		temp = temp->next;
	}
	bool flag = 1;
	T buf;
	while (flag)
	{
		flag = 0;
		temp = begin;
		while (temp->next != NULL)
		{
			if (temp->data.getAverageMark() < temp->next->data.getAverageMark())
			{
				buf = temp->data;
				temp->data = temp->next->data;
				temp->next->data = buf;
				flag = 1;
			}
			temp = temp->next;
		}
	}
	temp = begin;
	while (temp)
	{
		if (temp->data.getIncome() >= twice_base_value)
		{
			newlist.pushEnd(temp->data);

		}
	
		temp = temp->next;
	}
	cout << "Данные успешно отсортированы!" << endl;
	newlist.show();
	newlist.clearList();
}

template <class T>
void List<T>::searchData(T value)
{
	element<T> *temp = begin;
	int i = 1, num = 0;
	cout << "Данные по запросу:" << endl;
	while (temp)
	{
		if (temp->data == value)
		{
			cout << i << ") " << temp->data << endl;
			num++;
		}
		i++;
		temp = temp->next;
	}
	if (num == 0)
	{
		cout << "Не найдены!" << endl;
	}
}

//----------------------------------------------- exceptionList -------------------------------------------------------
template <class T>
List<T>::exceptionList::exceptionList(const char* msg)
{
	cout << "costructor of exceptionList!" << endl;
	strcpy_s(this->msg, strlen(msg) + 1, msg);
}

template <class T>
List<T>::exceptionList::~exceptionList()
{
	cout << "destructor of exceptionList!" << endl;
}

template <class T>
void List<T>::exceptionList::what()
{
	cout << this->msg << endl;
}


template <typename T>
void delMenu(List<T> &list)
{
	
	int position, option;
	bool exit = true;

	while (exit)
	{
		cout << "\tМеню удаления:" << endl;
		cout << "\t1.Удаление записи\n\t2.Удаление всех данных\n\t0.Выход из меню\n\t ";
		option = inputValue(0, 2);
		switch (option)
		{
		case 1:
			cout << "Введите номер строки, которую хотите удалить:" << endl;
			position = inputValue(1, list.getSize());
			list.popOnPosition(position - 1);
			cout << "Данные успешно удалены!" << endl;
			break;
		case 2:
			list.clearList();
			cout << "Данные успешно удалены!" << endl;
			break;
		case 0:
			exit = false;
			break;
		}
	}
	system("pause");
}

template <typename T>
T inputValue(T range1, T range2)
{
	cout << "\nВвод: ";
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
			cout << "Повторите ввод!" << endl;
		}
	}
	return num;
}