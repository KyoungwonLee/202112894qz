//202112894 이경원 4주차 qz3-1: 단어를 저장할 수 있는 링크드리스트 만들기

#define _crt_secure_no_warnings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[100];
} element;

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

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL \n");
}

int main() {
	ListNode* head = NULL;
	element data;

	strcpy(data.name, "apple");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "kiwi");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "banana");
	head = insert_first(head, data);
	print_list(head);

	return 0;
}

