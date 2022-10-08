#pragma once
#include <iostream>

struct Client {
	char* name; // Имя клиента
	char city[30]; // Адрес клиента
	int phone; // Телефон клиента
	double age; // Возраст клиента
	int input();
	void output();
	int cmp(const Client& b);
	int equal(const Client& b);
};

typedef Client* T;
