#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
FILE* file;
//Создание структуры данных для хранения информации
typedef struct Team {
	char cape[15];
	int all;
	int win;
	int lose;
	int point;
	int bonus;
	float NNR;
	char winlose[6];
} Tm;
//Описание функций, используемых в программе
int compare(struct Team* pA, int i, int j, int base);
void sort(struct Team* pA, int N, int b, int(*fun)(struct Team*, int, int, int));
int read(struct Team* pA, char name[]);
void randauto(struct Team* pA, int N);
int search(struct Team* pA, int i, char name4[20]);
int point(struct Team* pA, int i);
void print1(struct Team* pA, int N, int j);
void print2(struct Team* pA, int i);
void change(struct Team* pA, int i);
int main()
{
	setlocale(LC_ALL, "Rus");
	printf("\t\t\t\t\t************************************************************************\n");
	printf("\t\t\t\t\t* Курсовой проект.                                                     *\n");
	printf("\t\t\t\t\t* Выполнил: Недиков Егор Александрович Группа: бИСТ-224                *\n");
	printf("\t\t\t\t\t*                                                                      *\n");
	printf("\t\t\t\t\t* Данная программа предназначена для работы с данными,                 *\n");
	printf("\t\t\t\t\t* сортировкой, поиском значений по критериям,                          *\n");
	printf("\t\t\t\t\t* выводом измененной таблицы                                           *\n");
	printf("\t\t\t\t\t*                                                                      *\n");
	printf("\t\t\t\t\t************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	char name4[15], fname[20], txt[5] = ".txt";
	int flag = 0;
	int sw = 0, n = 0, num = 0, num2 = 0, N = 0, count2 = 0, k = 0, b = 0;
	Tm commande[100];
	// Cоздание указателя на массив структуры
	Tm* com = commande;
	int count = 0;
	//Реализация меню програмы
	while (flag == 0) {
		int m = 0;
		printf("Выберите пункт из меню \n");
		printf("1. Чтение данных из файла\n");
		printf("2. Вывод таблицы результатов \n");
		printf("3. Сортировка данных\n");
		printf("4. Поиск команды по названию\n");
		printf("5. Расчет суммы очков \n");
		printf("6. Поиск команд по условию: очки > заданное число\n");
		printf("7. Редактирование данных \n");
		printf("8. Изменение данных\n");
		printf("9. Очистка консоли \n");
		printf("10. Выход из программы\n");
		printf("-->");
		scanf_s("%d", &sw);
		switch (sw) {
		case 1: {
			printf("Введите название файла > ");
			scanf("%s", fname);
			strcat(fname, txt);
			N = read(com, fname);
			if (N > 0) printf("\nФайл успешно открыт и прочитан\n\n");
			break;
		}
		case 2: {
			print1(com, N, 0, 0, 0);
			break;
		}
		case 3: {
			int xa, xy, xa1, xa2;
			printf("Выберите вид сортировки:\n");
			printf("1.Сортировка по очкам\n");
			printf("2.Сортировка по названиям команд\n");
			printf("-->");
			scanf("%d", &xy);
			if (xy == 1) {
				printf("1. По возрастанию \n");
				printf("2. По убыванию \n");
				printf("-->");
				scanf_s("%d", &xa1);
				if (xa1 == 1) {
					sort(com, N, 1, compare);
				}
				if (xa1 == 2) sort(com, N, 2, compare);
				if (xa1 > 2) printf("Введено некорректное значение.\n");
				printf("Данные успешно отсортированы\n");

			}
			if (xy == 2) {
				printf("1. По возрастанию \n");
				printf("2. По убыванию \n");
				printf("-->");
				scanf_s("%d", &xa2);
				printf("1. По возрастанию \n");
				printf("2. По убыванию \n");
				printf("-->");
				if (xa2 == 1) {
					sort(com, N, 4, compare);
				}
				if (xa2 == 2) sort(com, N, 3, compare);
				if (xa2 > 2) printf("Введено некорректное значение.\n");
				printf("Данные успешно отсортированы\n");
			}
			if (xy > 2) printf("Введено некорректное значение.\n");
		}
			  break;
		case 4: {
			int num = 0, num2 = 0, l;
			char name4[20];
			printf("Введите название команды: \n");
			fflush(stdin);
			scanf("%s", &name4);
			l = search(com, N, name4) - 1;
			if (l >= -1) {
				print1(com, l + 1, l, 0, 0);
			}
			if (l < -1) printf("Команда не найдена, повторите поиск \n\n");
			break;
		}
		case 5: {
			for (int i = 0; i < N; i++) {
				com[i].point = point(com, i);
			}
			printf("Количество очков рассчитано\n");
			break;
		}
		case 6: {
			int o = 0;
			printf("Введите число:\n");
			scanf("%d", &count2);
			print1(com, N, 0, 1, count2);
			break;
		}
		case 7: {
			printf("Введите количество команд:\n");
			scanf("%d", &N);
			randauto(com, N);
			break;
		}
		case 9: {
			system("cls");
			break;
		}
		case 10: {
			printf("Желаете завершить программу?\n");
			printf("1.Да\n");
			printf("2.Нет\n");
			int nyt;
			scanf("%d", &nyt);
			if (nyt == 1) return(0);
			break;
		}
		case 8: {
			int m;
			printf("Введите номер команды, который следует изменить\n");
			printf("-->");
			scanf("%d", &m);
			m = m - 1;
			change(com, m);
			break;
		}
		default:
			printf("Введено некорректное значение. Измените его\n");
			break;
		}
	}
}
int compare(struct Team* pA, int i, int j, int base)
{
	if (base == 1) return pA[i].point - pA[j].point;
	if (base == 2) return pA[j].point - pA[i].point;
	if (base == 3) return strcmp(pA[i].cape, pA[j].cape);
	if (base == 3) return strcmp(pA[j].cape, pA[i].cape);
}
void sort(struct Team* pA, int N, int b, int(*fun)(struct Team*, int, int, int)) {
	for (int i = N - 1; i; i--)
		for (int j = 0; j < i; j++) {
			//int a = compare(pA, i, j,4);
			int a = fun(pA, i, j, b);
			if (a < 0)
			{
				struct Team q;
				q = pA[j];
				pA[j] = pA[i];
				pA[i] = q;
			}
		}
}
//Функция считывания из файла
int read(struct Team* pA, char name[20]) {
	int count = 0, N = 0;
	file = fopen(name, "r");
	if ((file = fopen(name, "r")) == NULL)
	{
		getchar();
		printf("Не удалось открыть файл");
	}

	while (fscanf(file, "%s%d%d%d%d%f%s", pA[count].cape, &pA[count].all, &pA[count].win, &pA[count].lose, &pA[count].bonus, &pA[count].NNR, pA[count].winlose) != EOF)
	{
		pA[count].point = 0;
		count++;
		N++;
	}
	return(N);
	fclose(file);
}
//Функция автозаполнения данных
void randauto(struct Team* pA, int N) {
	srand(time(NULL));
	char* names[] = { "Tujh","Liquid","Faze","Nip","Winners","Pugna","Oracle","Ozperd","Items","Iron","Brums","Colts","Blink","Tomorrow","Yesterday" };
	int l = 0, l2 = 0, n = 0, num, k = 0;
	int a[10], k2, k3 = 0;

	for (int i = 0; i < N; i++) {
		l = (1 + rand() % 10);
		a[i] = l;
		strncpy(pA[i].cape, names[l], 15);
		while (n < 0) {
			k3 = 0;
			for (int k = 0; k < N; k++) {
				if (a[k] == l) k3++;
			}
			if (k3 < 2) n++;
			else {
				l = (1 + rand() % 10);
				a[i] = l;
				strncpy(pA[i].cape, names[l], 15);
			}
		}
		pA[i].all = 30 + rand() % 40;
		pA[i].win = 10 + rand() % 20;
		pA[i].lose = pA[i].all - pA[i].win;
		pA[i].bonus = 1 + rand() % 2;
		pA[i].NNR = 0.1 + rand() % 5;
		pA[i].NNR = (pA[i].NNR / 10);
		k3 = point(pA, i);
		pA[i].point = k3;
		for (int j = 0; j < 5; j++) {
			l = 1 + rand() % 2;
			if (l == 1) { pA[i].winlose[j] = 'В'; }
			if (l == 2) { pA[i].winlose[j] = 'П'; }
		}
		pA[i].winlose[5] = 0;
	}
}
//Функция поиска команды по названию
int search(struct Team* pA, int N, char name4[20]) {
	int k3 = 0, a = -1;
	for (int j = 0; j < N; j++) {
		k3++;
		if (strcmp(name4, pA[j].cape) == 0) {
			a++;
			break;
		}
	}
	if (a > -1) return(k3);
	else return(-1);
}
//Функция расчета количества очков
int point(struct Team* pA, int i) {
	int p = (pA[i].win * 2) + pA[i].bonus;
	return (p);
}
//Функция печати
void print1(struct Team* pA, int N, int j, int a, int z) {
	printf("-----------------------------------------------------------------------------------\n");
	printf("|%3s|%14s|%10s|%6s|%6s|%6s|%6s|%6s|%13s|\n", "№", "Имя команды", "Игр всего", "Побед", "Поражений", "Бонусы", "Очки", "NNR", "Текущая серия");
	printf("-----------------------------------------------------------------------------------");
	for (; j < N; j++) {
		if (a == 0) {
			print2(pA, j);
		}
		if (a == 1) {
			if (pA[j].point > z) {
				print2(pA, j);
			}
		}
	}
	printf("\n");
	printf("-----------------------------------------------------------------------------------\n");
}
//Вспомогательная функция печати
void print2(struct Team* pA, int i)
{
	printf("\n");
	printf("|%2d|", i + 1);
	printf("|%14s|", pA[i].cape);
	printf("|%8d|", pA[i].all);
	printf("|%6d|", pA[i].win);
	printf("|%8d|", pA[i].lose);
	printf("|%5d|", pA[i].bonus);
	printf("|%5d|", pA[i].point);
	printf("|%6.3f|", pA[i].NNR);
	printf("|%9s  |", pA[i].winlose);
}
//Функция изменения данных
void change(struct Team* pA, int i) {
	printf("Введите название команды:\n");
	scanf("%s", &pA[i].cape);
	printf("Введите количество игр команды:\n");
	scanf("%d", &pA[i].all);
	printf("Введите количество побед команды:\n");
	scanf("%d", &pA[i].win);
	pA[i].lose = pA[i].all - pA[i].win;
	printf("Введите количество бонусов:\n");
	scanf("%d", &pA[i].bonus);
	pA[i].bonus = (pA[i].win * 2) + pA[i].bonus;
	printf("Введите NNR команды:\n");
	scanf("%f", &pA[i].NNR);
}