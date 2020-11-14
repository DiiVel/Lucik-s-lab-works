#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void strrch(char* str, char symb);

int main()
{
	setlocale(LC_ALL, "russian");

	char* str;
	int n;

	printf_s("Введите количество элементов строки: ");
	scanf_s("%d", &n);

	n++;  //увеличение коичества элементов под ноль-символ
	str = (char*)malloc(n*sizeof(char));  //выделание памяти под строку

	rewind(stdin);
	gets(str);

	printf_s("Первоначальная строка:\n%s\n", str);

	char symb = '*';
	strrch(str, symb);

	for (int i = 0; i < n; i++)
	{
		str = str + str[i];
	}
	printf_s("Измененная строка:\n %s", str);

	free(str);

	return 0;
}


void strrch(char* str, char symb)
{
	char* tmp = str;

	while (*tmp != '\0')
	{
		if (*tmp != symb)
		{
			*str++ = *tmp;
		}

		++tmp;
	}

	*str = '\0';

	return;
}
