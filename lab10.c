#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int kl_slov(char* str, int m)
{
    unsigned int a, i;
    a = 0;
    for (i = 0; i < m; i++)
    {
        if ((str[i] == ' ') && (str[i + 1] != ' '))
        {
            a = a + 1;
        }
    }
    if (str[0] != ' ')
        a = a + 1;
    printf("В строке: %d слов.\n", a);
    return a;
}

int amount_AA_words(char* str, int m);

int main()
{
    setlocale(LC_ALL, "rus");

    char* str;
    int m, kl = 0;


    printf("Введите количество символов в строке: ");
    while (scanf_s("%d", &m) == 0)
    {
        printf("Вы ввели не число. Попробуйте еще раз:"); //проверка на правильность ввода и ввод
        rewind(stdin);
    }

    m++; //увеличение для нуль-символа

    str = (char*)calloc(m + 1, sizeof(char));

    printf("Введите строку длинной не более %3d символов:\n", m);

    rewind(stdin);
    fgets(str, m, stdin);


    kl_slov(str, m);
    amount_AA_words(str, m);


    return 0;
}




int amount_AA_words(char* str, int m)
{
    int AA = 0, a = 1, b = 0;

    for (int i = 0; i < m; i++)
    {
        if (str[i] >= 33 && str[i] <= 126 && (!(str[i - 1] >= 33 && str[i - 1] <= 126 || (i == 1))))
        {
            a = str[i];
        }

        if ((str[i] >= 33 && str[i] <= 126) && !(str[i + 1] >= 33 && str[i + 1] <= 126) || str[i + 1] == '\n')
        {
            b = str[i];
        }

        if (a == b)
        {
            AA++;
            a = 1;
            b = 0;
        }
    }


    printf("Количество слов, у которых первый и последний символы совпадают: %d", AA);
    return AA;
}
