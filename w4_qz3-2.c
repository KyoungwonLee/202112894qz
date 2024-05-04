//202112894 이경원 4주차 qz3-2: 특정 값을 탐색하는 함수 추가

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* remove_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* remove_pre(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;

	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data == x) return p;
	}

	return NULL;  
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main() {
	ListNode* head = NULL;
	for (int i = 10; i < 40; i += 10) {
		head = insert_first(head, i);
		print_list(head);
	}

	int searchvalue = 30;
	ListNode* foundnode = search_list(head, searchvalue);
	if (foundnode != NULL)
		printf("리스트에서 %d을 찾았습니다.\n", foundnode->data);
	else
		printf("리스트에 %d이 없습니다.\n", searchvalue);

	return 0;
}

