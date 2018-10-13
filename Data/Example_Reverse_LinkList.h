/*
*头插法实现单链表逆置
*/
#pragma once
#include "SingleLinkedList.h"

inline void Reverse_LinkList(LinkList H)
{
	LinkList p, q;
	if (H->next&&H->next->next) {
		p = H->next;
		//printf("%d\n", p->data);
		q = p->next;
		//printf("%d\n", q->data);
		p->next = NULL;
		while (q) {
			p = q;
			//printf("%d\n", p->data);
			q = q->next;
			//printf("%d\n", q->data);
			p->next = H->next;
			//printf("%d\n", q->data);
			H->next = p;
			//printf("%d\n", H->data);
		}
	}
}