#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

typedef struct Item {
	int val;
	int val2;
	int id;
	struct Item* prev;
	struct Item* next;
}Item;

void Push(int, int);
void PrintList();
struct Item* Pop();

Item* head, * tail;
int ID_COUNTER = 1;
int main()
{
	Item* item;
	Push(2, 4);
	item = Pop();
	printf("The %d id has been deleted\n", item->id);
	free(item);
	PrintList();
}

void Push(int val, int val2)
{
	Item* temp = (struct Item*)malloc(sizeof(struct Item));
	if (!temp)
	{
		printf("Allocation Error");
		exit(1);
	}
	temp->val = val;
	temp->val2 = val2;
	temp->id = ID_COUNTER;
	ID_COUNTER++;
	temp->next = temp->prev = NULL;
	if (!head)
	{
		head = tail = temp;
		head->prev = tail->next = NULL;
	}
	else {
		head->prev = temp;
		temp->next = head;
		temp->prev = NULL;
		head = temp;
	}
}

void PrintList()
{
	if (!tail)
	{
		printf("The list is empty \n");
		return;
	}
	Item* curr = tail;
	printf("The list is: \n");
	while (curr)
	{
		printf("First value is: %d, Second value is: %d, Id is: %d\n", curr->val, curr->val2, curr->id);
		curr = curr->prev;
	}
}

struct Item* Pop()
{
	int count = 1;
	if (!tail)
	{
		return NULL;
	}
	Item* temp = (Item*)malloc(sizeof(Item));
	temp = tail;
	if (!tail->prev)
	{
		tail = head = NULL;
		return temp;
	}
	tail = tail->prev;
	tail->next = NULL;
	return temp;
}