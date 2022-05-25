// ConsoleApplication14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;
struct Student {
	char* name;
	size_t nMarks;
	int* marks;
}myStruct;
void student_init(Student& st) {
	st.name = nullptr;
	st.marks = nullptr;
	st.nMarks = 0;
}
void student_init(Student& st, const char* name, int* marks={nullptr}, size_t nMarks = {0}) {
	size_t namelen = strlen(name);
	st.name = new char[namelen+1];
	strcpy(st.name, name);

	st.marks = nullptr;
	st.nMarks = nMarks;
	if (nMarks > 0) {
		st.marks = new int[nMarks];
		for (size_t i = 0;i < nMarks;i++) {
			st.marks[i] = marks[i];
		}
	}
}
void student_release(Student& st) {
	if (st.name != nullptr)
		delete[] st.name;
	if (st.marks != nullptr)
		delete[] st.marks;
	student_init(st);
}

bool student_is_null(const Student& st) {
	return st.name == nullptr && st.marks == nullptr;
}
void student_set_name( Student& st,const char* name) {
	if (st.name != nullptr) {
		delete[]st.name;
		st.name = nullptr;
	}
	size_t namlen = strlen(name);
	st.name = new char[namlen + 1];
	strcpy(st.name, name);
}
void student_add_mark(Student& st, int mark) {
	rsize_t nMarks = st.nMarks;
	int* marks = st.marks;
	st.marks = new int[nMarks + 1];
	if (st.marks != nullptr) {
		for (size_t i = 0;i < st.nMarks;i++) {
			st.marks[i] = marks[i];
		}
		delete[] marks;
	}
	st.marks[nMarks] = mark;
	st.nMarks++;
}
double student_srzn(Student& st) {
	if (student_is_null(st)) {
		return 0.0;
	}
	double avg = 0;
	for (size_t i = 0;i < st.nMarks;i++) {
		avg += st.marks[i];
	}
	return avg / st.nMarks;
}

ostream& operator <<(ostream & os, const Student & st) {
	if (student_is_null(st)) {
		 os<<"Student(null)";
	}
	else {
		os << "Student(" << st.name << ", [";
		for (size_t i= 0;i < st.nMarks;i++) {
			if (i > 0)cout << ", ";
			cout << st.marks[i];
		}
		os << "])";
	}
	return os;
}
int main()
{	
	Student st;
	//student_init(st);
	//student_set_name(st, "Dima");
	student_init(st, "Dima");
	student_add_mark(st, 4);
	student_add_mark(st, 5);
	student_add_mark(st, 5);
	student_add_mark(st, 4);
	cout << st << endl;
	cout << "AVG= " << student_srzn(st) << endl;
	student_release(st);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
