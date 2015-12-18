#include <iostream>
#include <stack>
#include "Array.h"

using namespace std;

void printStack(stack <Array <int>> st) {
	stack <Array <int>> temp = st;
	while (!temp.empty()) {
		cout << temp.top();
		temp.pop();
	}
	cout << endl;
}

void main() {
	cout << "\nCREATE STACK\n";
	stack <Array<int>> st;
	for (int i = 0; i < 10; i++) {
		Array <int> temp(rand() % 6);
		st.push(temp);
	}
	printStack(st);

	cout << "\nDELETE ALL ZERO-ARRAYS\n";
	{
		stack <Array<int>> temp;
		while (!st.empty()) {
			Array<int> ch = st.top();
			st.pop();
			if (ch.GetSize() != 0) {
				temp.push(ch);
			}
		}
		st = temp;
	}
	printStack(st);

	cout << "\nCHANGE ARRAY(3) TO ARRAY(0)\n";
	{
		stack <Array<int>> temp;
		while (!st.empty()) {
			Array <int> ch = st.top();
			st.pop();
			if (ch.GetSize() == 3) {
				Array <int> zero(0);
				temp.push(zero);
			}
			else {
				temp.push(ch);
			}
		}
		st = temp;
	}
	printStack(st);

	{
		int n = 3;
		cout << "\nDELETE " << n << " ARRAYS AFTER FIRST ZERO-ARRAY\n";
		stack <Array<int>> temp;
		bool b = true;
		while (!st.empty()) {
			Array <int> ch = st.top();
			st.pop();
			if (b) {
				if (ch.GetSize() == 0) {
					b = false;
				}
				temp.push(ch);
			}
			else if (n > 0) {
				n--;
			}
			else {
				temp.push(ch);
			}
		}
		st = temp;
	}
	printStack(st);

	cout << "\nCREATE SECOND STACK\n";
	stack <Array<int>> st2;
	for (int i = 0; i < 10; i++) {
		Array <int> temp(rand() % 6);
		st2.push(temp);
	}
	printStack(st2);

	cout << "\nCOPY ELEMENTS FROM SECOND STACK INTO FIRST\n";
	while (!st2.empty()) {
		st.emplace(st2.top());
		st2.pop();
	}
	printStack(st);
	cout << endl;
}