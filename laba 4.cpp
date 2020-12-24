#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <math.h>
#include <stack>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

bool palindrom(stack<char> st1, stack<char> st2);
void stack_clearing(stack <char> st);
bool brackets(char* s);
char set_Brackets(char s);

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("<===== Стандартные библиотеки шаблонов =====>\n");

	stack <char> st1;
	stack <char> st2;
	char s[255] = { '\0' };

	printf("\nЗадание 1.1\n");

	printf("Введите строку : ");
	cin.getline(s, 255);

	int lange = strlen(s);
	for (int i = 0; i < lange; i++)
	{
		st1.push(s[i]);
		st2.push(s[lange - i - 1]);
	}

	if (palindrom(st1, st2))
		printf("\nСтрока - палиндром\n");
	else
		printf("\nСтрока - не палиндром\n");

	stack_clearing(st1);
	stack_clearing(st2);

	s[0] = { '\0' };

	//-------------------------------------------//

	printf("\nЗадание 1.2\n");

	printf("Введите строку : ");
	cin.getline(s, 255);

	if (brackets(s))
		printf("Скобки сбалансированы");
	else
		printf("Скобки не сбалансированы");

	//-------------------------------------------//

	printf("\nЗадание 2.1\n");

	return 0;
}

void stack_clearing(stack <char> st)
{
	for (int i = 0; !st.empty(); i++)
		st.pop();
}

bool palindrom(stack<char> st1, stack<char> st2)
{
	if (st1 == st2)
		return true;
	else
		return false;
}

bool brackets(char* s)
{
	stack<char> st;
	int lange = strlen(s);
	int cnt = 0;
	char a;

	for (int i = 0; i < lange; i++)
	{
		if (s[i] == '(' || s[i] == '{')
			st.push(s[i]);
		else if (s[i] == ')' || s[i] == '}')
		{
			if (st.empty() || st.top() != set_Brackets(s[i]))
				return false;
			else
				st.pop();
		}
	}

	stack_clearing(st);

	return st.empty();
}

char set_Brackets(char s)
{
	if (s == ')')
		return '(';
	else if (s == '}')
		return '{';
	else return 0;
}