#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int start, finish;
void input(int a, int* x);
void add(int n, int* x);
int del(int* x);
void view(int* x);

int main(void) {
	int n, z;
	printf("Size ");
	scanf("%d", &n);
	if (n < 1) return 0;
	int* x = (int*)calloc(sizeof(int), n-1);
	start = n-1;
	finish = n-1;
	printf("\n");
	printf("1) add element\n");
	printf("2) delete\n");
	printf("3) view queue\n");
	printf("4) quit\n");

	while (1) {
		printf("\n\n");
		printf("> ");
		scanf("%d", &z);
		switch (z) {
		case 1:
			add(n, x);
			break;
		case 2:
			printf("%d\n", del(x));
			break;
		case 3:
			view(x);
			break;
		case 4:
			return 0;
			break;
		}
	}
}

void add(int n, int* x) {
	int a;
	printf("Add: ");
	scanf("%d", &a);
	input(a, x);
}

void input(int a, int* x) {
	if (finish < 0) {
		printf("Full\n");
	}
	else {
		x[finish] = a;
		finish--;
	}
}

int del(int* x) {
	if (start == finish) {
		printf("Empty\n");
		return 0;
	}
	start--;
	return x[start + 1];
}

void view(int* x) {
	for (int i = start; i > finish; i--) {
		printf("%d ", x[i]);
	}
	putchar('\n');
}
