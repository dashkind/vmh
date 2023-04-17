#include <stdio.h>
#include <string.h>

int main() {
    int number_of_strings;
    printf("Введите количество строк: ");
    scanf("%d", &number_of_strings);
    while(getchar() != '\n');
//проверка на не превышение количества строк
    if (number_of_strings > 10) {
        printf("Количество строк не должно превышать 10.\n");
        return 1;
    }
//вводим заданное количество строк и делаем проверку на корректное количество вводимых символов
    char array[number_of_strings][79];
    for(int i=0; i<number_of_strings; i++)
    {
        printf("Введите строку %d: ", i+1);
        fgets(array[i], 79, stdin);
        if (strchr(array[i], '\n') == NULL)
        {
            int ch;
            while ((ch = getchar()) != '\n');
            printf("Введенная строка превышает допустимую длину. Пожалуйста, введите строку не более 78 символов.\n");
            return 1;
        }
    }
//ищем длину самой длинной строки
    int max = 0;
    int current = 0;
    for (int i = 0; i < number_of_strings; i++)
    {
        current = strlen(array[i]);
        if (current > max)
        {
            max = current;
        }
    }
//открываем цикл по обработке каждой строки
    for (int i = 0; i < number_of_strings; i++)
    {
        // считаем количество доступных проусков в строке
        int space_count = 0;
        for (int j = 0; array[i][j] != '\0'; j++) {
            if (array[i][j] == ' ') {
                space_count++;
            }
        }
        //сколько пробелов нужно вставить в строку
        int curr_len = strlen(array[i]) - 1;
        int ness_spaces = max - curr_len - 1;
        //если попалась самая длинная строка, то переазписываем в том виде, в каком она есть
        if (curr_len == max - 1)
        {
            printf("%s", array[i]);
        }
        //все остальные строки:
        else
        {
            //перебирает каждую строку до конца (нулевой символ)
            for (int j = 0; array[i][j] != '\0'; j++)
            {
                //если встречает пробел, и количество необходимых для вставки пробелов не ноль
                //и количетсво текущих пробелов не ноль
                if (array[i][j] == ' ' && ness_spaces > 0 && space_count > 0)
                {
                    //считаем количество пробелов, необходимых для вставки в конкретно попавшийся пробел в текущей строке
                    int sp = (ness_spaces + space_count - 1) / space_count;
                    //последовательно выводим эти пробелы
                    for (int s = 0; s < sp; s++)
                    {
                        printf(" ");
                    }
                    //из количества необходимых для вставки пробелов вычитаем количество вставленных
                    ness_spaces -= sp;
                    //количество пробелов в текущей строке уменьшаем на 1
                    space_count--;
                }
                //печатает букву
                if (array[i][j] != '\n') {
                    printf("%c", array[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
