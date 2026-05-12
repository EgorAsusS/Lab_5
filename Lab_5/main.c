#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct point {
	int x;
	int y;
	struct point* prev;
	struct point* next;
};

struct point* addToHead(struct point** list, int x, int y);
struct point* addToTail(struct point** list, int x, int y);


int main() {
	struct point* head = NULL;
	int i = 0;
	for (i = 0; i < 10; i++) {
		addToTail(&head, i, i + 1);
	}

	// Проверка списка
	for (struct point* current = head; current; current = current->next){
		printf("adress = %zu, x = %d, y = %d, prev = %zu, next = %zu\n", current, current->x, current->y, current->prev, current->next);
	}
	return 0;
}

struct point* addToHead(struct point** list, int x, int y) {
	struct point* PtrIx = (struct point*)malloc(sizeof(struct point));
	if (PtrIx && list)
	{
		PtrIx->x = x;
		PtrIx->y = y;
		PtrIx->next = NULL;
		PtrIx->prev = NULL;
		if (*list == NULL)
			*list = PtrIx;
		else
		{
			PtrIx->next = *list;
			(*list)->prev = PtrIx;
			*list = PtrIx;
		}
		return PtrIx;
	}
	return NULL;
}

struct point* addToTail(struct point** list, int x, int y) {
	struct point* PtrIx = (struct point*)malloc(sizeof(struct point));
	if (PtrIx && list)
	{
		PtrIx->x = x;
		PtrIx->y = y;
		PtrIx->next = NULL;
		PtrIx->prev = NULL;
		if (*list == NULL) //Если список пустой
			*list = PtrIx;
		else
		{
			//Если список не пустой, то устанавливаем указатель current на последний элемент.
			struct point* current = *list;
			for (current = *list; current->next; current = current->next);
			current->next = PtrIx;
			PtrIx->prev = current;
		}
		return PtrIx;
	}
	return NULL;
}