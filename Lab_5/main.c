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
struct point* add_before_el(struct point** list, int x, int y, int x_add, int y_add);
struct point* add_after_el(struct point** list, int x, int y, int x_add, int y_add);
struct point* add_to_pos(struct point** list, size_t k, int x, int y);
struct point* find_el(struct point* list, int x, int y);
void del_head(struct point** list);
void del_tail(struct point** list);
void del_el(struct point** list, int x, int y);
void del_at_pos(struct point** list, size_t k);
void clear_list(struct point** list);
void print_list(struct point* list);


int main() {
	// Тесты
	
	// Add/Del Head/Tail
	//struct point* head = NULL;
	//printf("ADD\n");
	//for (int i = 0; i < 3; i++) {
	//	add_to_head(&head, i, i + 1); // Добавление в голову с пустого списка начиная
	//	//add_to_tail(&head, i, i + 1); // Добавление в хвост с пустого списка начиная
	//	printf("%d\n", i);
	//	print_list(head);
	//	printf("\n");
	//}
	//printf("DEL\n");
	//size_t i = 0;
	//printf("\nhead = %p\n", head);
	//while(head){
	//	del_head(&head); // Удаление головы пока не пустой список
	//	//del_tail(&head); // Удаление хвоста пока не пустой список
	//	printf("%zu\n", i++);
	//	print_list(head);
	//	printf("\nhead = %p\n", head);
	//}


	// Before
	//struct point* head = NULL;
	//printf("ADD\n");

	//add_before_el(&head, 0, 1, -1, -2); // Пустой список
	//print_list(head);
	//printf("\n");

	//printf("\n");
	//for (int i = 0; i < 3; i++) { // Создание списка
	//	add_to_tail(&head, i, i + 1);
	//	printf("%d\n", i);
	//	print_list(head);
	//	printf("\n");
	//}
	//add_before_el(&head, 0, 1, -1, -2); // Перед головой
	//add_before_el(&head, 0, 1, -3, -4); // Есть элемент в списке
	//add_before_el(&head, 10, 11, -1, -2); // Нет элемента в списке
	//print_list(head);
	

	// After
	//struct point* head = NULL;
	//printf("ADD\n");

	////add_after_el(&head, 0, 1, -1, -2); // Пустой список
	////print_list(head);
	////printf("\n");

	//printf("\n");
	//for (int i = 0; i < 3; i++) { // Создание списка
	//	add_to_tail(&head, i, i + 1);
	//	printf("%d\n", i);
	//	print_list(head);
	//	printf("\n");
	//}
	////add_after_el(&head, 1, 2, -1, -2); // Есть элемент в списке
	////add_after_el(&head, 2, 3, -3, -4); // После хвоста
	////add_after_el(&head, 10, 11, -1, -2); // Нет элемента в списке
	////print_list(head);


	// To position
	//struct point* head = NULL;
	//printf("ADD\n");

	//printf("\n");
	//for (int i = 0; i < 3; i++) { // Создание списка с пустого и дальше за хвост
	//	add_to_pos(&head, i, i, i + 1);
	//	printf("%d\n", i);
	//	print_list(head);
	//	printf("\n");
	//}
	//add_to_pos(&head, 2, -3, -4); // В хвост
	//add_to_pos(&head, 0, -1, -2); // В голову
	//add_to_pos(&head, 2, -5, -6); // В середину
	//print_list(head);

	//printf("DEL\n");
	//size_t i = 0;
	//del_at_pos(&head, 0); // Удаление головы
	////del_at_pos(&head, 1); // Удаление в середине
	//printf("%zu\n", i++);
	//print_list(head);
	//printf("\n");
	//del_at_pos(&head, 10); // Удаление за пределами списка
	//printf("%zu\n", i++);
	//print_list(head);
	//printf("\n");
	//del_at_pos(&head, 1); // Удаление хвоста
	//printf("%zu\n", i++);
	//print_list(head);
	//printf("\n");
	//del_at_pos(&head, 0); // Удаление единственного элемента в списке
	//printf("%zu\n", i++);
	//print_list(head);
	//printf("\n");
	//del_at_pos(&head, 0); // Удаление в пустом списке
	//printf("%zu\n", i++);
	//print_list(head);
	//printf("\nhead = %p\n", head);


	// Find element
	//struct point* head = NULL;
	//printf("ADD\n");
	////printf("Adress of point(1, 2) %p\n", find_el(head, 1, 2)); // В пустом списке
	////printf("\n");
	//for (int i = 0; i < 3; i++) { // Создание списка
	//	add_to_pos(&head, i, i, i + 1);
	//	printf("%d\n", i);
	//	print_list(head);
	//	printf("\n");
	//}
	//printf("Adress of point(1, 2) %p\n", find_el(head, 1, 2)); // Есть элемент
	//printf("Adress of point(100, 200) %p\n", find_el(head, 100, 200)); // Нет элемента

	//printf("DEL\n");
	//size_t i = 0;
	//del_el(&head, 0, 1); // Удаление головы
	////del_el(&head, 1, 2); // Удаление в середине
	//printf("%zu\n", i++);
	//print_list(head);
	//printf("\n");
	//del_el(&head, 100, 200); // Удаление за пределами списка
	//printf("%zu\n", i++);
	//print_list(head);
	//printf("\n");
	//del_el(&head, 2, 3); // Удаление хвоста
	//printf("%zu\n", i++);
	//print_list(head);
	//printf("\n");
	//del_el(&head, 1, 2); // Удаление единственного элемента в списке
	//printf("%zu\n", i++);
	//print_list(head);
	//printf("\n");
	//del_el(&head, 0, 1); // Удаление в пустом списке
	//printf("%zu\n", i++);
	//print_list(head);
	//printf("\nhead = %p\n", head);
	

	// Clear list
	//struct point* head = NULL;
	//for (int i = 0; i < 3; i++) { // Создание списка
	//	add_to_pos(&head, i, i, i + 1);
	//	printf("%d\n", i);
	//	print_list(head);
	//	printf("\n");
	//}
	//printf("\nhead = %p\n", head);
	//clear_list(&head);
	//print_list(head);
	//printf("\nhead = %p\n", head);
	return 0;
}

struct point* find_el(struct point* list, int x, int y) {
	struct point* current = NULL;
	for (current = list; current && (current->x != x || current->y != y); current = current->next); // Поиск элемента
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
		if (*list == NULL) //Если список пустой
			*list = PtrIx;
		else { // Обновление головы
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
			struct point* current = *list;
			for (current = *list; current->next; current = current->next); // Поиск хвоста
			current->next = PtrIx; // Обновление хвоста
			PtrIx->prev = current;
		}
		return PtrIx;
	}
	return NULL;
}



struct point* add_before_el(struct point** list, int x, int y, int x_add, int y_add) {
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
			if ((*list)->x == x && (*list)->y == y) { // Если голова, то обновление головы
				PtrIx->next = *list;
				(*list)->prev = PtrIx;
				*list = PtrIx;
			}
			else {
				struct point* current = *list;
				for (current = *list; current && (current->x != x || current->y != y); current = current->next); // Поиск нужного элемента
				if (current) { // Если нашли, обновление предыдущего и PtrIx на текущий
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
			for (current = *list; current && (current->x != x || current->y != y); current = current->next); // Поиск нужного элемента
			if (current) { // Если нашли
				if (current->next) { // Обновление следующего и предыдущего, если не хвост
					PtrIx->next = current->next;
					PtrIx->prev = current;
					current->next->prev = PtrIx;
					current->next = PtrIx;
				}
				else { // Обновление предыдущего, если хвост
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
			if (k) { // Если не в голову
				for (size_t i = 0; current->next && i < k - 1; current = current->next, i++); // Поиск k - 1 элемента
				if (current->next) { // Обновление следующего и предыдущего, если не хвост
					PtrIx->next = current->next;
					PtrIx->prev = current;
					current->next->prev = PtrIx;
					current->next = PtrIx;
				}
				else { // Обновление предыдущего, если хвост
					current->next = PtrIx;
					PtrIx->prev = current;
				}
			}
			else { // Обновление головы
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
		*list = (*list)->next; // Обновление головы
		if (*list) { // Если не пустой список обновление указателя prev для головы
			(*list)->prev = NULL;
		}
		free(PtrIx);
		PtrIx = NULL;
	}
}

void del_tail(struct point** list) {
	if (list && *list) {
		struct point* current = *list;
		for (current = *list; current->next; current = current->next); // Поиск хвоста
		if (current->prev) { // Обновление указателя next для предыдущего или обновление головы
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
		for (current = *list; current && (current->x != x || current->y != y); current = current->next); // Поиск нужного элемента
		if (current) { // Удаление текущей позиции
			if (current->prev) { // Обновление указателя next для предыдущего или обновление головы
				current->prev->next = current->next;
			}
			else {
				*list = (*list)->next;
			}
			if (current->next) { // Если можно, обновление указателя prev для следующего
				current->next->prev = current->prev;
			}
			free(current);
			current = NULL;
		}
	}
}

void del_at_pos(struct point** list, size_t k) {
	if (list && *list) {
		struct point* current = *list;
		for (size_t i = 0; current && i < k; current = current->next, i++); // Поиск k позиции
		if (current) { // Удаление текущей позиции
			if (current->prev) { // Обновление указателя next для предыдущего или обновление головы
				current->prev->next = current->next;
			}
			else {
				*list = (*list)->next;
			}
			if (current->next) { // Если можно, обновление указателя prev для следующего
				current->next->prev = current->prev;
			}
		}
		free(current);
		current = NULL;
	}
}

void clear_list(struct point** list) {
	while (*list) {
		del_head(list); // Удаление головы пока не пустой список
	}
}

void print_list(struct point* list) {
	struct point* current = list;
	for (size_t i = 0; current; current = current->next, i++) { // Вывод списка поэлементно с номером и через || адреса и указатели на соседей
		printf("N = %2zu, x = %2d, y = %2d   ||   adress = %p, prev = %p, next = %p\n", i, current->x, current->y, current, current->prev, current->next);
	}
}