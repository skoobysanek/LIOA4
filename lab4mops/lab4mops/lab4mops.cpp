#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* CreateTree(struct Node* root, struct Node* r, int data);
void print_tree(struct Node* r, int l);
void search_elem(struct Node* r, int data);
int counter(Node* root, int E);

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int D, number;
	struct Node* root = NULL;

	cout << "Введите размер дерева: ";
	cin >> D;
	while (D) {
		root = CreateTree(root, root, rand() % 100);
		D--;
	}
	cout << "Построение дерева окончено" << endl << endl;

	print_tree(root, 0);
	cout << endl << "Введите элемент для поиска и подсчёта: ";
	cin >> D;
	search_elem(root, D);
	number = counter(root, D);
	if (number)
		cout << "Кол-во искомых элементов: " << number;
	else
		cout << "Ничего не найдено";
	getch();
	return 0;
}

struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			cout << "Ошибка выделения памяти";
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data)	root->right = r;
		else root->left = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->right, data);
	else
		CreateTree(r, r->left, data);

	return root;
}

void print_tree(struct Node* r, int l)
{
	if (r == NULL)
		return;

	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
		cout << ("   ");

	cout << r->data << endl;
	print_tree(r->left, l + 1);
}

void search_elem(struct Node* r, int data)	//поиск по заданному элементу
{
	if (r == NULL)
		return;

	if (r->data < data) {
		search_elem(r->right, data);
	}
	else if (r->data > data) {
		search_elem(r->left, data);
	}

	if (r->data == data) 
		cout << r->data << endl;
}

int counter(Node* root, int E)	//счётчик
{
	if (root == 0) return 0;
	return (root->data == E) + counter(root->left, E) + counter(root->right, E);
}