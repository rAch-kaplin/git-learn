#include <stdio.h>
#include <TXLib.h>
#include <stdbool.h>
#include <ctype.h>

#define STOP '|'

int main(void) {
    char c;
    long sim = 0L;
    int lines = 0;
    int words = 0;

    bool inword = false;
    printf("¬ведите текст дл€ анализа или | дл€ завершени€.\n ");

    while ((c = getchar()) != STOP){
        sim++;       // считает символы
        if (c == '\n')
            lines++;
        if (!isspace(c) && !inword)
        {
            words++;
            inword = true;
        }
        if (isspace(c) && inword)
            inword = false;
    }
    printf("sim = %ld - lines = %d - words = %d",sim, lines, words );
    return 0;
}
