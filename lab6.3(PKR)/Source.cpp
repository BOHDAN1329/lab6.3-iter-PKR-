#include <iostream>
typedef int Info;
using namespace std;
struct Elem
{
	Elem* next,
		* prev;
	Info info;
};
void Enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->next = NULL;
	if (last != NULL)
		last->next = tmp;
	tmp->prev = last;
	last = tmp;
	if (first == NULL)
		first = tmp;
}
void Dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->next;
	delete first;
	first = tmp;
	if (first == NULL)
		last = NULL;
	else
		first->prev = NULL;
}
void Print(Elem* first)
{
	while (first != NULL)
	{
		cout << first->info << " ";
		first = first->next;
	}
}
void task(Elem* elem, const int value)
{
	while (elem != NULL)
	{
		elem->info += value;
		elem = elem->next;
	}
}
int main()
{
	Elem* first = NULL,
		* last = NULL;
	int N, a, k;
	Info x;
	cout << "Enter quantity: "; cin >> N;
	cout << "Values of elements: " << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << "a" << i << "="; cin >> a;
		Enqueue(first, last, a);
	}
	Print(first);
	cout << "\nEnter value : "; cin >> k;
	task(first, k);
	Print(first);
	for (int i = 0; i < N; i++)
	{
		Dequeue(first, last);
	}

	return 0;
}