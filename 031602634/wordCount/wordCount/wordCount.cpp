#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;


typedef struct
{
	char word[20];
	int count;
}w;


int mycmpstruct(w a, w b);//结构体排序


int main(int argc, char *argv[])
{
	w s;
	w str[20000];
	int n = 0, j, i;
	int charr = 0, liness = 1;
	int x;
	char ch;
	FILE *inf;
	FILE *writef;
	fopen_s(&inf, argv[1], "r");
	fstream File("output.txt", ios::in | ios::out);
	if (inf == NULL) {
		cout << "error" << endl;
		system("pause");
		return 0;
	}

	while (!feof(inf))//统计字符数
	{
		ch = getc(inf);
		if (ch >= 0 && ch <= 255) charr++;
	}

	File << "characters: " << charr << endl;
	rewind(inf);
	while (!feof(inf))
	{
		ch = getc(inf);
		if (ch == ' ' || ch == 10) continue;
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			int k = 0;
			x = 0;
			s.count = 1;
			while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
			{
				s.word[k++] = tolower(ch);
				ch = getc(inf);
				x++;
			}
			if (x <= 3)
			{
				k = k - x;
				continue;
			}
			s.word[k++] = '\0';
			j = n;
			for (i = 0; i < j; i++)
			{
				if (strcmp(s.word, str[i].word) == 0)
				{
					str[i].count++;
					break;
				}
			}

			if (n == 0 || i == j)
			{
				str[n++] = s;
			}
		}
	}

	File << "words: " << n << endl;
	rewind(inf);

	while (!feof(inf))//
	{
		ch = getc(inf);
		if (ch == '\n') liness++;
	}
	File << "lines: " << liness << endl;

	sort(str, str + n, mycmpstruct);

	for (i = 0; i < n; i++)
	{
		File << str[i].word << ": " << str[i].count << endl;
	}
	return 0;
}



int mycmpstruct(w a, w b)
{
	if (a.count != b.count) return a.count > b.count;
	if (a.count = b.count)
	{
		string aa = a.word;
		string bb = b.word;
		return aa < bb;
	}
}