#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int my_strcmp(const char *pstr1, const char *pstr2);
void bubbleSort(char **str, size_t size);

int main()
{

    // const char* str[] = {"My uncle, man of firm convictions*…",
    //                     "By falling gravely ill, he's won",
    //                     "A due respect for his afflictions-",
    //                     "The only clever thing he's done.",
    //                     "May his example profit others;",
    //                     "But God, what deadly boredom, brothers,",
    //                     "To tend a sick man night and day,",
    //                     "Not daring once to steal away!",
    //                     "And, oh, how base to pamper grossly",
    //                     "And entertain the nearly dead,",
    //                     "To fluff the pillows for his head,",
    //                     "And pass him medicines morosely-",
    //                     "While thinking under every sigh:",
    //                     "The devil take you, Uncle. Die!"};
    // const size_t SIZE = sizeof(str) / sizeof(str[0]);
    //printf("<<size = %zu>>\n", SIZE);
    FILE * file = fopen("onegin.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Ошибка открытия файла\n");
        return 1;
    }

    const size_t MAX_LENGHT_STRING = 100;
    char buffer[MAX_LENGHT_STRING] = {};
    size_t SIZE = 0;
    size_t row_count = 10;

    char **str = (char**)calloc(row_count, sizeof(char*));

    while (fgets(buffer, MAX_LENGHT_STRING, file) != NULL)
    {
        size_t len = strlen(buffer);
        //printf("strlen(buffer = %zu)\n", len);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';

        printf("Прочитанная строка: %s\n", buffer);

        str[SIZE] = (char*)calloc((len + 1), sizeof(char));
        strcpy(str[SIZE], buffer);
        SIZE++;

        if (SIZE >= row_count)
        {
            row_count *= 2;
            str = (char**)realloc(str, row_count * sizeof(char*));
        }
    }
    fclose(file);

    printf("<<%zu>>\n", SIZE);

    for (size_t j = 0; j < SIZE; j++)
    {
        printf("---%s \n", str[j]);
    }
    putchar('\n');

    bubbleSort(str, SIZE);
    for (size_t j = 0; j < SIZE; j++)
    {
        printf(" %s \n", str[j]);
        free(str[j]);
    }
    free(str);
    return 0;
}

int my_strcmp(const char *pstr1, const char *pstr2)
{
    int i = 0, j = 0;
    while(1)
    {
        while(pstr1[i] != '\0' && !isalnum((unsigned char)pstr1[i]))
            i++;
        while(pstr2[j] != '\0' && !isalnum((unsigned char)pstr2[j]))
            j++;

        char ch1 = (pstr1[i] != '\0') ? (char)tolower((unsigned char)pstr1[i]) : '\0';
        char ch2 = (pstr2[j] != '\0') ? (char)tolower((unsigned char)pstr2[j]) : '\0';

        if (ch1 == ch2)
        {
            if(ch1 == '\0')
                return 0;
            i++;
            j++;
        }
        else
            return ch1 - ch2;
    }
}
void bubbleSort(char **str, size_t SIZE)
{
    for (size_t i = 0; i < SIZE - 1; i++)
    {
        for (size_t j = 0; j < SIZE - i - 1; j++)
        {
            if (str[j] == NULL || str[j + 1] == NULL)
            {
                continue;
            }
            int res = my_strcmp(str[j], str[j + 1]);
            if (res > 0)
            {
                char* buffer = str[j];
                str[j] = str[j + 1];
                str[j + 1] = buffer;
            }
        }
    }
}
