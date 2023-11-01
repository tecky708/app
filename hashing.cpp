#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

bool has[MAX + 1][2];

bool search(int X)
{
	if (X >= 0) {
		if (has[X][0] == 1)
			return true;
		else
			return false;
	}

	X = abs(X);
	if (has[X][1] == 1)
		return true;

	return false;
}

void insert(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) 
			has[a[i]][0] = 1;
	else
			has[abs(a[i])][1] = 1;
	}
}

int main()
{
	int a[] = { -1, 9, -5, -8, -5, -2 };
	int n = sizeof(a)/sizeof(a[0]);
	insert(a, n);
	int X = -5;
	if (search(X) == true)
	cout << "Present"; 
	else
	cout << "Not Present";
	return 0;
}
