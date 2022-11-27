#include <algorithm>
#include "Table.h"

const int size = 3;
T m[size];

// Ввод таблицы
int Input() {
	for (int i = 0; i < size; i++) {
		m[i] = new Client;
		m[i]->input();
	}
	return !std::cin.eof();
}

// Вывод таблицы
void Output() {
	bool flag = false;
	for (int i = 0; i < size; i++) {
		if (m[i] != NULL) {
			m[i]->output();
			flag = true;
		}
	}
	if (!flag)
		std::cout << "There is no to output!" << std::endl;
}

// Сортировка таблицы
void Sort() {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((m[i] != NULL) && (m[j] != NULL) && (m[i]->cmp(*m[j]) > 0))
				std::swap(m[i], m[j]);
		}
	}
}

// Поиск клиента в таблице, возвращает индекс найденного клиента или -1 если клиент не найден
int Search(const Client& tempClient) {
	for (int i = 0; i < size; i++) {
		if (m[i] != NULL && m[i]->equal(tempClient))
			return i;
	}
	return -1;
}

// Замена клиента в таблице
void Replace() {
	// Запрос старого клиента
	std::cout << std::endl << "Enter old client: " << std::endl;
	Client oldClient;
	oldClient.input();

	// Запрос нового клиента
	std::cout << std::endl << "Enter new client: " << std::endl;
	Client newClient;
	newClient.input();

	// Поиск и замена
	int index = Search(oldClient);
	while (index != -1) {
		m[index]->name = newClient.name;
		strcpy_s(m[index]->city, 30, newClient.city);
		m[index]->phone = newClient.phone;
		m[index]->age = newClient.age;
		index = Search(oldClient);
	}
}

// Удаление всех вхождений
void Remove(Client& badClient) {
	int index = Search(badClient);
	while (index != -1) {
		delete m[index];
		for (int i = index; i < size - 1; i++) {
			m[i] = m[i + 1];
		}
		m[size - 1] = NULL;
		index = Search(badClient);
	}
}
