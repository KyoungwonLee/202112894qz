//202112894 이경원 4주차 qz3-4: 역순의 리스트를 리턴하는 함수 추가

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

ListNode* reverse(ListNode* head) {
	ListNode* p, * q, * r;

	p = head;  
	q = NULL;  

	while (p != NULL) {
		r = q;  
		q = p;
		p = p->link;
		q->link = r;  
	}
	return q;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	for (int i = 4; i >= 1; i--) {
		head1 = insert_first(head1, i * 10);
	}
	print_list(head1);

	head2 = reverse(head1);
	print_list(head2);

	return 0;
}

