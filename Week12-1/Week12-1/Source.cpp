#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct A {
	char name[1000];
	int v;
};
A a[1000];
int ch[1000];
void check(char *ptr,int y,int amount) {
	for (int i = 0;i < amount;i++) {
		if (!strcmp(a[i].name, ptr) && y >= a[i].v && ch[i] == 0) {
			ch[i] = 1;
		}
	}
}
int main() {
	int n=0,m=0,ans=0;
	char x[1000];
	int y=0;
	int len = 0;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf(" %s %d", a[i].name, &a[i].v);
		for (int j = 0;j < strlen(a[i].name);j++) {
			a[i].name[j] = tolower(a[i].name[j]);
		}
	}
	scanf("%d", &m);
	for (int i = 0;i < m;i++) {
		scanf(" %s %d", x, &y);
		for (int j = 0;j < strlen(x);j++) {
			x[j] = tolower(x[j]);
		}
		check(x, y, n);
	}
	for (int i = 0;i < n;i++) {
		if (ch[i] == 1) {
			ans++;
		}
	}
	if (ans == n) {
		printf("Make it\n");
	}
	else printf("Not Enough\n");
	return 0;
}