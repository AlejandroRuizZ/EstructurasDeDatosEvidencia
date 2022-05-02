// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include "heap.h"
using namespace std;

int main(int argc, char* argv[]) {
	int n,acum,val; //numero de lista

	cin >> n;
	Heap<int> miHeap(n);

	for (int i = 0; i < n; i++){
		cin >> val;
		miHeap.add(val);
	}
	acum = 0;
	while (miHeap.length() > 1){
		val = miHeap.remove() + miHeap.remove();
		miHeap.add(val);
		acum = acum +(val -1);
	}
	cout << acum << endl;
	return 0;
}
