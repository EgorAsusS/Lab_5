#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct point {
	int x;
	int y;
	struct point* prev;
	struct point* next;
};

struct point* add_to_head(struct point** list, int x, int y);
struct point* add_to_tail(struct point** list, int x, int y);
struct point* add_befor_el(struct point** list, int x, int y, int x_add, int y_add);
struct point* add_after_el(struct point** list, int x, int y, int x_add, int y_add);
struct point* add_to_pos(struct point** list, size_t k, int x, int y);
struct point* find_el(struct point** list, int x, int y);
struct point* find_k(struct point** list, size_t k);
void del_head(struct point** list);
void del_tail(struct point** list);
void del_el(struct point** list, int x, int y);
void del_at_pos(struct point** list, size_t k);
void clear_list(struct point** list);
void print_list(struct point** list);


int main() {
	struct point* head = NULL;
	for (int i = 0; i < 10; i++) {
		add_to_tail(&head, i, i + 1);
	}
	printf("First\n");
	print_list(&head);
	printf("\n");

	//for (int i = 0; i < 10; i++) {
	//	del_at_pos(&head, (10 - i - 1));
	//}
	for (int i = 0; i < 10; i++) {
		del_el(&head, 10 - i - 1, 10 - i);
	}
	printf("Second\n");
	print_list(&head);
	printf("\n");


	for (int i = 0; i < 10; i++) {
		add_to_tail(&head, i, i + 1);
	}
	clear_list(&head);
	printf("Third\n");
	print_list(&head);
	printf("\n");

	add_to_pos(&head, 111, -1, -2);
	add_to_pos(&head, 111, -3, -4);
	// Просмотр списка
	printf("Fourth\n");
	print_list(&head);
	return 0;
}

struct point* find_el(struct point** list, int x, int y) {
	struct point* current = NULL;
	if (list) {
		for (current = *list; current && (current->x != x || current->y != y); current = current->next);
	}
	return current;
}

struct point* find_k(struct point** list, size_t k) {
	struct point* current = NULL;
	if (list) {
		current = *list;
		for (size_t i = 0; current && i < k; current = current->next, i++);
	}
	return current;
}


struct point* add_to_head(struct point** list, int x, int y) {
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

struct point* add_to_tail(struct point** list, int x, int y) {
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



struct point* add_befor_el(struct point** list, int x, int y, int x_add, int y_add) {
	struct point* PtrIx = (struct point*)malloc(sizeof(struct point));
	if (PtrIx && list)
	{
		PtrIx->x = x_add;
		PtrIx->y = y_add;
		PtrIx->next = NULL;
		PtrIx->prev = NULL;
		if (*list == NULL) //Если список пустой
			return NULL;
		else
		{
			//Если список не пустой, то устанавливаем указатель current на последний элемент.
			if ((*list)->x == x && (*list)->y == y) {
				PtrIx->next = *list;
				(*list)->prev = PtrIx;
				*list = PtrIx;
			}
			else {
				struct point* current = *list;
				for (current = *list; current && (current->x != x || current->y != y); current = current->next);
				if (current) {
					current->prev->next = PtrIx;
					PtrIx->prev = current->prev;
					PtrIx->next = current;
					current->prev = PtrIx;
				}
				else {
					return NULL;
				}
			}
		}
		return PtrIx;
	}
	return NULL;
}

struct point* add_after_el(struct point** list, int x, int y, int x_add, int y_add) {
	struct point* PtrIx = (struct point*)malloc(sizeof(struct point));
	if (PtrIx && list)
	{
		PtrIx->x = x_add;
		PtrIx->y = y_add;
		PtrIx->next = NULL;
		PtrIx->prev = NULL;
		if (*list == NULL) //Если список пустой
			return NULL;
		else
		{
			struct point* current = *list;
			for (current = *list; current && (current->x != x || current->y != y); current = current->next);
			if (current) {
				if (current->next) {
					PtrIx->next = current->next;
					PtrIx->prev = current;
					current->next->prev = PtrIx;
					current->next = PtrIx;
				}
				else {
					current->next = PtrIx;
					PtrIx->prev = current;
				}
			}
			else {
				return NULL;
			}
		}
		return PtrIx;
	}
	return NULL;
}

struct point* add_to_pos(struct point** list, size_t k, int x, int y) {
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
			struct point* current = *list;
			if (k) {
				for (size_t i = 0; current->next && i < k - 1; current = current->next, i++);
				if (current->next) {
					PtrIx->next = current->next;
					PtrIx->prev = current;
					current->next->prev = PtrIx;
					current->next = PtrIx;
				}
				else {
					current->next = PtrIx;
					PtrIx->prev = current;
				}
			}
			else {
				PtrIx->next = *list;
				(*list)->prev = PtrIx;
				*list = PtrIx;
			}
		}
		return PtrIx;
	}
	return NULL;
}

void del_head(struct point** list) {
	if (list && *list) {
		struct point* PtrIx = *list;
		*list = (*list)->next;
		free(PtrIx);
		PtrIx = NULL;
	}
}

void del_tail(struct point** list) {
	if (list && *list) {
		struct point* current = *list;
		for (current = *list; current->next; current = current->next);
		if (current->prev) {
			current->prev->next = NULL;
		}
		else {
			*list = (*list)->next;
		}
		free(current);
		current = NULL;
	}
}

void del_el(struct point** list, int x, int y) {
	if (list && *list) {
		struct point* current = *list;
		for (current = *list; current && (current->x != x || current->y != y); current = current->next);
		if (current) {
			if (current == *list) {
				*list = (*list)->next;
			}
			else {
				if (current->prev) {
					current->prev->next = current->next;
				}
				if (current->next) {
					current->next->prev = current->prev;
				}
			}
			free(current);
			current = NULL;
		}
	}
}

void del_at_pos(struct point** list, size_t k) {
	if (list && *list) {
		struct point* current = *list;
		if (k) {
			for (size_t i = 0; current && i < k; current = current->next, i++);
			if (current) {
				if (current->prev) {
					current->prev->next = current->next;
				}
				if (current->next) {
					current->next->prev = current->prev;
				}
				
			}
		}
		else {
			*list = (*list)->next;
		}
		free(current);
		current = NULL;
	}
}

void clear_list(struct point** list) {
	while (*list) {
		del_head(list);
	}
}

void print_list(struct point** list) {
	if (list && *list) {
		struct point* current = *list;
		for (size_t i = 0; current; current = current->next, i++) {
			printf("N = %2zu, x = %2d, y = %2d   ||   adress = %p, prev = %p, next = %p\n", i, current->x, current->y, current, current->prev, current->next);
		}
	}
}