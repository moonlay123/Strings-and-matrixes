#ifndef FILES
#define FILES

#include <stdio.h>
#include <assert.h>

/*!
Открывает файл, если открытие произошло неуспешно, в fp записывает NULL
\param[in] fp указатель на файл
\param[in] file_name путь до нужного файла
*/
void byte_file_open(FILE **fp, const char *file_name);

/*!
Закрывает файл. Если он не закрывается, выдает ошибку
\param[in] fp указатель на файл
*/
void file_close(FILE *fp);

/*!
Получает размер файла
\param[in] fp указатель на файл
\return размер файла
*/
size_t get_file_size(FILE *fp);

#endif
