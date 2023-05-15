#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

int size = 3;


typedef struct Info {
	char authorName[20];
	int date;

}info;

typedef struct Book {
	char name[20];
	int id;
	struct Info info;
}Book;
Book book[100], temp;





int Input(int size) {
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < size; i++) {
		printf("Введите id: ");
		scanf_s("%d", &book[i].id);
		printf("Введите название книги: ");
		scanf("%s", &book[i].name);
		printf("Введите имя автора: ");
		scanf("%s", &book[i].info.authorName);
		printf("Введите дата выхода книги: ");
		scanf_s("%d", &book[i].info.date);
	}
	return 0;
}

int Output(int size) {
	setlocale(LC_ALL, "Russian");
	printf("+---------------+--------+---------------+\n");
	printf("| --Номер П/П---|Название|Доп. сведения -|\n");
	printf("|               |        |Скор.|Мощность |\n");
	for (int i = 0; i < size; i++) {
		printf("|% -15d|% -8s|% -5s|% -9d|\n",
			book[i].id, book[i].name, book[i].info.authorName, book[i].info.date);
	}
	return 0;
}

int main() {
	Input(size);
	Output(size);
	temp = book[0];
	book[0] = book[2];
	book[2] = temp;
	Output(size);
	return 0;
}