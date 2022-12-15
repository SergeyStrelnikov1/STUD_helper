#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class Student {
private:
	char* mark, * lssnName;
public:
	Student() {
		mark = new char[20];
		lssnName = new char[20];
	}
	void addData();
	void editdata();
	void showdata();
	int search(char[], char[]);

};

void Student::addData() {
	cin.ignore();
	cout << "\nВведите Название предмета: ";      cin.getline(mark, 20);
	cout << "Введите оценку: ";       cin.getline(lssnName, 20);

}

void Student::editdata() {

	cout << "\nВведите новое Название предмета: ";      cin.getline(mark, 20);
	cout << "Введите новую оценку: ";       cin.getline(lssnName, 20);

}

void Student::showdata() {
	NULL;
}

int Student::search(char o_mark[20], char o_lssnName[20]) {
	if (strcmp(o_mark, mark) == 0 && strcmp(o_lssnName, lssnName) == 0)
		return 1;
	else return 0;

}

int main() {
	setlocale(LC_ALL, "Russian");

	Student* S[20];
	int i = 0, t, choice;
	char old_mark[20], old_lssnName[20];

	while (1) {
		cout << "\nMENU:"
			<< "\n1. Добавить предмет"
			<< "\n2. Изменить предмет и его оценку"
			<< "\n3. Вывести информацию"
			<< "\n4. Выход"
			<< "\n\nEnter your Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:	S[i] = new Student;
			S[i]->addData();
			i++;	break;

		case 2: cin.ignore();
			cout << "\nВведите старое название предмета: "; cin.getline(old_lssnName, 20);
			cout << "Введите старую оценку по этому предмету: ";  cin.getline(old_mark, 20);

			for (t = 0; t < i; t++) {
				if (S[t]->search(old_mark, old_lssnName)) {
					cout << "\nBook Found Successfully";
					S[t]->editdata();
					break;
				}
			}
			if (t == i)
				cout << "\nThis Book is Not in Stock";
			break;
		case 3:
			NULL;

		case 4: exit(0);

		default: cout << "\nInvalid Choice Entered";

		}
	}



	return 0;
}
