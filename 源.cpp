#include<stdio.h>
#include<stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*Linklist;

void delx(Linklist &L,int x) {
	LNode* p = L->next, * pre = L;
	while (p->next) {
		if (p->data == x) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}
//β�巨
Linklist CreateList(Linklist& L) {
	int x;
	L = (Linklist)malloc(sizeof(LNode));
	LNode* s, * r = L; 
	printf("��������������ֵ:\n");
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf_s("%d", &x);
	}
	r->next = NULL;
	return L;
}
void ShowList(Linklist& L) {
	LNode* p = L->next;
	while (p) {
		printf("%d\t", p->data);
		p = p->next;
	}
}
void ReverseShow(Linklist L) {
	LNode* p = L->next, * r;
	L->next = nullptr;
	while (p) {
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}

	LNode* s = L->next;
	printf("��������Ľ��Ϊ��\n");
	while (s) {
		printf("%d", s->data);
		s = s->next;
	}
}
void SortList(Linklist& L) {
	LNode* p = L->next, * pre;
	LNode* r = p->next;
	p->next = NULL;
	p = r;
	while (p) {
		r = p->next;
		pre = L;
		while (pre->next && pre->next->data < p->data)pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}
//ɾ��ָ����������
void DeleteAtoB(Linklist& L, int a, int b)
{
	LNode* p = L->next,*pre=L;
	while (p!=nullptr) {
		if (p->data >= a && p->data <= b) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}
//�������Ϊ�����к�ż����
Linklist DivideA(Linklist& A) {
	LNode* B = (LNode*)malloc(sizeof(LNode));
	LNode* p = A->next,*pre=A,*pb;
	B->next = nullptr;
	pb = B;
	while (p) {
		if (p->data % 2 == 0) {
			pre->next = p->next;
			p->next = pb->next;
			pb->next = p;
			p = pre->next;
			pb = pb->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
	return B;
}
//�������Ϊ����
Linklist DivideB(Linklist& L) {
	LNode* B = new LNode;
	LNode* p = L->next,*pre=L,*pb=B;
	int k = 1;
	B->next = nullptr;
	while (p) {
		if (k % 2 == 0) {
			pre->next = p->next;
			p->next = pb->next;
			pb->next = p;
			p = pre->next;
			k++;
		}
		else {
			pre = p;
			p = p->next;
			k++;
		}
	}
	return B;
}
//ɾ��������ظ�ֵ
void DeleteRipite(Linklist& L) {
	LNode* p = L->next->next,*pre=L->next;
	while (p) {
		if (p->data == pre->data) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}
//�ϲ�������������
Linklist MergeList(Linklist L1, Linklist L2) {
	LNode* B = new LNode;
	LNode* p1=L1->next, * p2=L2->next, * pb = B, * pre1=L1, * pre2=L2;
	B->next = nullptr;
	while (p1 && p2) {
		if (p1->data <= p2->data) {
			pre1->next = p1->next;
			p1->next = pb->next;
			pb->next = p1;
			p1 = pre1->next;
		}
		else {
			pre2->next = p2->next;
			p2->next = pb->next;
			pb->next = p2;
			p2 = pre2->next;
		}
	}
	while(p1) {
		pre1->next = p1->next;
		p1->next = pb->next;
		pb->next = p1;
		p1 = pre1->next;
	}
	while (p2) {
		pre2->next = p2->next;
		p2->next = pb->next;
		pb->next = p2;
		p2 = pre2->next;
	}
	return B;
}
//������Ĺ���Ԫ��
Linklist CommonElem(Linklist A, Linklist B) {
	LNode* C = new LNode;
	C->next = nullptr;
	LNode* pa = A->next, * pb = B->next, * pc = C;
	while (pa && pb) {
		if (pa->data == pb->data) {
			LNode* s = new LNode;
			s->data = pa->data;
			s->next = pc->next;
			pc->next = s;
			pc = pc->next;
			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->data < pb->data) {
			pa = pa->next;
		}
		else {
			pb = pb->next;
		}
	}
	return C;
}
//��������Ľ���
void CrossElem(Linklist& A, Linklist B) {
	LNode* pa = A->next, * pb = B->next,*prea=A,*r=A;
	while (pa && pb) {
		if (pa->data == pb->data) {
			prea->next = pa->next;
			pa->next = r->next;
			r->next = pa;
			r = r->next;
			pa = prea->next;
			pb = pb->next;
		}
		else if (pa->data < pb->data) {
			prea = pa;
			pa = pa->next;
		}
		else {
			pb = pb->next;
		}
	}
	r->next = nullptr;
}
//�����ж�
bool IsSub(Linklist A, Linklist B) {
	LNode* pa = A->next, * pb = B->next;
	while (pa&&pb){
		while (pa->data == pb->data) {
			pa = pa->next;
			pb = pb->next;
			if (pb == nullptr)break;
		}
		if(pa)pa = pa->next;
		
	}
	return pb==nullptr;
}
void main() {
	Linklist L,L1; int x,a, b;
	LNode* B;
	printf("1.ɾ��ָ��ֵ\n2.�����������\n3.����\n4.ɾ��ָ��������\n"
		"5.��ż����\n6.����\n7.ɾ��������ظ�ֵ\n8.�ϲ����������\n"
		"9.������Ĺ���Ԫ��\n10.��������Ľ���\n11.�����ж�");
	scanf_s("%d", &a);
	switch (a)
	{
	case 1:
		CreateList(L);
		printf("������Ҫɾ����ֵ:\n");
		scanf_s("%d", &x);
		delx(L, x);
		ShowList(L);
		break;
	case 2:
		CreateList(L);
		ReverseShow(L);
		break;
	case 3:
		CreateList(L);
		SortList(L);
		ShowList(L);
		break;
	case 4:
		CreateList(L);
		printf("������Ҫɾ������:\n");
		scanf_s("%d", &a);
		scanf_s("%d", &b);
		DeleteAtoB(L,a,b);
		ShowList(L);
	case 5:
		CreateList(L);
		B = DivideA(L);
		printf("�����У�\t");
		ShowList(L);
		printf("ż���У�\t");
		ShowList(B);
		break;
	case 6:
		CreateList(L);
		B = DivideB(L);
		printf("A�У�\t");
		ShowList(L);
		printf("B�У�\t");
		ShowList(B);
		break;
	case 7:
		printf("!(�����������)\n");
		CreateList(L);
		DeleteRipite(L);
		ShowList(L); 
		break;
	case 8:
		printf("!(�����������)\n");
		printf("�������1��\n");
		CreateList(L);
		printf("�������2��\n");
		CreateList(L1);
		B=MergeList(L, L1);
		ShowList(B);
		break;
	case 9:
		printf("!(�����������)\n");
		printf("�������1��\n");
		CreateList(L);
		printf("�������2��\n");
		CreateList(L1);
		B = CommonElem(L, L1);
		ShowList(B);
		break;
	case 10:
		printf("!(�����������)\n");
		printf("�������1��\n");
		CreateList(L);
		printf("�������2��\n");
		CreateList(L1);
		CrossElem(L, L1);
		ShowList(L);
		break;
	case 11:
		printf("�������1��\n");
		CreateList(L);
		printf("�������2��\n");
		CreateList(L1);
		a=IsSub(L, L1);
		printf("%d", a);
	}

}