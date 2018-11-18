#include <stdio.h>

#define SYM 0xe2

int main() {
         unsigned char buffer[] = {
                7,7,7,         // Выдаем 3 раза звуковой сигнал.

                '1','2','3',0x0a,0x0d,

                0x1b, ':', 0, 0, 0,

                '2','3','4',0x0a,0x0d,

                0x1b, '%', 1, 0,

                '3','4','5',0x0a,0x0d,

// Определяем вместо "@" новый символ:
                0x1b, '&', 0, SYM, SYM,
                128,
                0, 255, 145, 145, 145, 145, 145, 145, 142, 0, 0,

                '4','5','6',0x0a,0x0d,
// Выдаем строку символов, используем начертание,
// заданное в ПЗУ принтера.

                SYM, SYM, SYM, SYM, SYM, 0x0a, 0x0d,

                '6','7','8',0x0a,0x0d,
// Используем новое начертание:

                0x1b, '%', 0,
                SYM, SYM, SYM, SYM, SYM, 0x0a, 0x0d,

                '9','9','9',0x0a,0x0d,
// Возвращаемся опять к старому начертанию:

                0x1b, '%', 1,
                SYM, SYM, SYM, SYM, SYM, 0x0a, 0x0d,

                7,7,7,   // Выдаем 3 раза звуковой сигнал.
                '$'      // Признак конца массива данных
        };
        unsigned char *p;

// Выводим строку символов на принтер
        for(p = buffer; *p != '$'; p++)
            fputc(*p, stdout);
}
