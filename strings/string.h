// puts, strnchr, strlen, strcpy, strncpy, strcat, strncat, fgets, strdup, getline
#ifndef STRINGS
#define STRINGS

#include <stdio.h>
#include <cstdlib>
#include <assert.h>

#define max(x, y) x > y ? x : y

struct string
{
    signed char *mas;
    size_t capacity;
    size_t size;
    size_t pointer;
};

/*!
Проводит полный анализ сжатия файла
\param[in] file_name имя анализируемого файла
*/
void full_zip_analise(char *file_name);

/*!
Создает бинарную строку по пути файла
\param[in] file_name имя файла
\return бинарную строку
*/
char *create_bin_string(char *file_name);

/*!
Zip файл с помощью lre
\param[out] zipped где хранить сжатый файл
\param[in] file_name имя файла, который надо сжать
*/
void zip_file(string *zipped, char *file_name);

/*!
Проверяет, что char является буквой
\param[in] a проверяемый символ
\return true если английская буква и false иначе
*/
bool is_liter(signed char a);

/*!
Выводит исходный масси, зашифрованный и дешифрованный, а также выигрыш при шифровании\
\param[in] rle_ciphered зашифрованная строка
\param[in] rle_deciphered дешифрованная rle
\param[in] original оригинальная строка
*/
void zip_win(string *rle_ciphered, string *rle_deciphered, string *original);

/*!
Печатает сжатую rle строку
\param[in] str печатает сжатую строку
*/
void rle_printer(string *str);

/*!
Дешифрует rle строку в обычную
\param[in]  rle строка, кторая дешифруется
\param[out] str место, куда запишется дешифрованная строка
*/
void rle_decipher(string *str, string *rle);

/*!
Делает rle сжатие строки
\param[out] vessel строка, куда запишется ответ
\param[in]  str исходная строка
*/
void rle_cipher(string *vessel, string *str);

/*!
Создает строку
\param[out] ans структура, где создадется строка
\param[in]  str изначальная строка
*/
void str_create(string *ans, const char *str);

/*!
Вставляет значение в конец строки
\param[in] str указатель на строку
\param[in] value вставляемое значение
*/
void str_push(string *str, signed char value);

/*!
Выводит строку из str на стандартное устройство вывода
\param[in] str строка
\return символ новой строки в случае успеха, иначе EOF
*/
int my_puts(const char *str);

/*!
Находит первое вхождение символа в строке
\param[in] str строка, где происходит поиск
\param[in] symbol символ, который ищется
\return указатель на найденный символ или нулевой указатель
*/
char *my_strchr(char *str, int symbol);

/*!
Находит количество символов до символа конца строки
\param[in] str исследуемая строка
\return возвращает полученную длину
*/
size_t my_strlen(const char *str);

/*!
Копирует данные из строки source в строку destination пока не встретится символ конца строки
\param[out] destination указатель на строку, в которую копируются данные
\param[in] source указатель на строку, из которой копируется строка
\return возвращает указатель на строку, куда копировались данные
*/
char *my_strcpy(char *destination, const char *source);

/*!
Копирует n символов из строки source в строку destination, если конец окажется раньше, то скопируется меньше элементов
\param[out] destination указатель на строку, в которую копируются данные
\param[in] source указатель на строку, из которой копируется строка
\return возвращает указатель на строку, куда копировались данные
*/
char *my_strncpy(char *destination, const char *source, size_t num);

/*!
Добавляет содержимое sorce в конец destination и сдвигает \0
\param[out] destination строку, в которую копируется
\param[in] source строка, откуда копируется
\return указатель на начало destination
*/
char *my_strcat(char *destination, const char *source);

/*!
Добавляет содержимое sorce в конец destination и сдвигает \0
\param[out] destination строку, в которую копируется
\param[in] source строка, откуда копируется
\param[in] num максимальная длина добавления строки
\return указатель на начало destination
*/
char *my_strncat(char *destination, const char *source, size_t num);

/*!
Считывает до num символов из файла и записывает их в строку str
\param[out] str строка, куда записываются данные из файла
\param[in] num сколько символов взять
\param[in] stream файл, откуда будет вестись запись
*/
char *my_fgets(char *str, size_t num, FILE *stream);

/*!
Дублирует строку и возвращает указатель на сдублированную
\param[in] str строка, которую нужно продублировать
\return возвращает указатель на продублированную строку
*/
char *my_strdup(const char *str);

/*!
Считывает целую строку из файла и записывает в *lineptr
\param[out] lineptr указатель на строку
\param[in]  n размер, который будет выдаваться с помощью malloc
\param[in]  stream файл, с которого выписываются строки
\return при успешном прохождении возвращает число считанный символов, иначе -1
*/
size_t my_getline(char **lineptr, size_t n, FILE *stream);

/*!
Сравниваем строки и указывает позиции, на которых они не равны
\param[in] str1 первая сравниваемая строка
\param[in] str2 вторая сравниваемая строка
*/
void string_compare(char *str1, char *str2);

#endif
