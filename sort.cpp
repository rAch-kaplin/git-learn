#include <stdio.h>
#include <ctype.h>

void transString(const char* src, char* dest);
int my_strcmp(const char *pstr1, const char *pstr2);
void bubbleSort(const char **str, size_t size);

int main()
{

    const char* str[] = {"My uncle, man of firm convictions*…",
                        "By falling gravely ill, he's won",
                        "A due respect for his afflictions-",
                        "The only clever thing he's done.",
                        "May his example profit others;",
                        "But God, what deadly boredom, brothers,",
                        "To tend a sick man night and day,",
                        "Not daring once to steal away!",
                        "And, oh, how base to pamper grossly",
                        "And entertain the nearly dead,",
                        "To fluff the pillows for his head,",
                        "And pass him medicines morosely-",
                        "While thinking under every sigh:",
                        "The devil take you, Uncle. Die!"};
    const size_t SIZE = sizeof(str) / sizeof(str[0]);

    printf("size = %zu\n", SIZE);
    bubbleSort(str, SIZE);
    for (size_t j = 0; j < SIZE; j++)
        printf("%s \n", str[j]);
    return 0;
}

// void transString(const char* src, char * dest)
// {
//     int i = 0, j = 0;
//     while(src[i] != '\0')
//     {
//         if(isalnum((unsigned char)src[i]))
//         {
//             dest[j] = (char)tolower((unsigned char)src[i]);
//             j++;
//         }
//         i++;
//     }
//     dest[j] = '\0';
// }
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
void bubbleSort(const char **str, size_t SIZE)
{
    for (size_t i = 0; i < SIZE - 1; i++)
    {
        for (size_t j = 0; j < SIZE - i - 1; j++)
        {
            int res = my_strcmp(str[j], str[j + 1]);
            if (res > 0)
            {
                const char* buffer = str[j];
                str[j] = str[j + 1];
                str[j + 1] = buffer;
            }
        }
    }
}
