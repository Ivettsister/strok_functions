#include <stdio.h>
#include <string.h>

/*!
 *\brief puts_func - outputs a string to the standard output stream
 *\param[in] string a string, which the program outputs
 */
int puts_func(const char* string);

/*!
 *\brief strlen_func - calculates the number of characters in a string
 *\param[in] string a string, which the program works with
 */
int strlen_func(const char* string);

/*!
 *\brief strchar_func - searches the first occurrence of the character in the argument
 *\param[in] string a string, which the program works with
 *\param[in] c a character, which the programm is looking for in the string
 */
const char* strchr_func(const char* string, int c);

/*!
 *\brief strcpy_func - returns a pointer to the string to which the data is copied
 *\param[in] string_1 a string, from which the data is copied
 *\param[in] string_2 a srting, to which the data is copied
 */
char* strcpy_func(const char* string_1, char* string_2);

/*!
 *\brief strncpy_func - returns a pointer to the row to which the data is copied
 *\param[in] string_1 pointer to the string source of the copied data
 *\param[in] string_2 returns a pointer to the row to which the data is copied
 *\param[in] n copy length limit
 */
char* strncpy_func(const char* string_1, char* string_2, int n);

/*!
 *\brief strncpy_func - returns a pointer to the array to which the string has been added
 *\param[in] destination a pointer to the array to which the string will be added
 *\param[in] append a pointer to the array from which the string will be copied
 */
char* strcat_func(char* destination, const char* append);

/*!
 *\brief strncpy_func - returns a pointer to the array to which the string has been added
 *\param[in] destination a pointer to the array to which the string will be added
 *\param[in] append a pointer to the array from which the string will be copied
 *\param[in] n maximum length of the added string
 */
char *strncat (char *destination, const char *append, int n);

//=============================================================================================

int main() {
    const char string[] = "Test text";
    const char text[] = "12345";
    const char some_text[] = "Hello, warld!";
    const char string_1[] = "Hello, wor\0ld!";
    char string_2[] = "aaaaa";
    int c = 'a';
    int n = 17;
    const char str_1[] = "Copy to the seventeenth symbol";
    char str_2[80] = "";
    const char from[] = "Second string";
    char to[80] = "First string";
    const char append[] = "append me";
    char destination[80] = "to this strok";
    int m = 4;

    puts_func(string);
    printf("Переменная string содержит текст длины %d\n", strlen_func(text));
    printf("Первое вхождение c в переменную string: %ld\n", strchr_func(some_text, c) - some_text);
    printf("Копирование переменной string_1 в переменную string_2: %s\n", strcpy_func(string_1, string_2));
    printf("Копирование переменной string_1 в переменную string_2: %s\n", strncpy_func(str_1, str_2, n));
    printf("%s\n", strcat_func(to, from));
    printf("Копирование первых %d элементов прошло успешно: %s\n", m, strncat(destination, append, m));
}

int puts_func(const char* string) {
    int res = 0;
    while (*string != '\0'){
        res = putc(*(string++), stdout);
        if (res == EOF) {
            return res;
        }
    }
    res = putc('\n', stdout);
    return res;
}

int strlen_func(const char* string) {
    int i = 0;
    for (; string[i] != '\0'; i++);
    return i;
}

const char* strchr_func(const char* string, int c) {
    int i = 0;
    for (i = 0; string[i] != '\0'; i++)
        if (string[i] == c) {
            return string + i;
        }
    return NULL;
}

char* strcpy_func(const char* source, char* destination) {
    int i = 0;
    for (; source[i] != '\0'; i++) {
        destination[i] = source[i];
    }
    destination[i] = '\0';
    return destination;
}

char* strncpy_func(const char* string_1, char* string_2, int n) {
    int i = 0;
    while ((string_1[i] != '\0') && (i < n)) {
        string_2[i] = string_1[i];
        i++;
    }
    string_2[i] = '\0';
    return string_2;
}

char* strcat_func(char* destination, const char* string)
{
    char* start_destination = destination;
    for (; *destination; destination++);
    for (; *string; destination++, string++) {
        *destination = *string;
    }
    *destination = '\0';
    return start_destination;
}

char *strncat (char *destination, const char *append, int n) {
    char* start = destination;
    for(; *destination; destination++);
    int i = 0;
    while ((i < n) && (*append)) {
        *destination = *append;
        destination++;
        append++;
        i++;
    }
    *destination = '\0';
    return start;
}
