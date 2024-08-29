#ifndef MATRIX
#define MATRIX

#include<stdio.h>
#include<assert.h>
#include <math.h>
#include <ctime>

/*!
Рисует ромб
Заполняет ромб случайныи значениями
\param[in] romb ромб
\param[in] diametr диаметр ромба
*/
void romb_printer(int *romb, size_t diametr);

/*!
Выдает размер ромба по его диаметру
\param[in] diametr диаметр ромба
\return возвращает количество элементов в ромбе
*/
size_t romb_size(size_t diametr);

/*!
Заполняет ромб случайныи значениями
\param[in] romb ромб
\param[in] diametr диаметр ромба
\return созданный ромб
*/
void romb_rand(int *romb, size_t diametr);

/*!
Создает ромб по диаметру
\param[in] diametr диаметр ромба
\return созданный ромб
*/
int *romb_create(size_t diametr);

/*!
Рисует треугольник
\param[in] trig данный треугольник
\param[in] size длина треугольника
*/
void print_triangle(int *trig, size_t size);

/*!
Выдает элемент массива по координатам его в матрице
\param[in] trig данный треугольник
\param[in] size длина треугольника
\param[in] row нужная строка таблицы
\param[in] column нужная колонка таблицы
*/
int triangle_get(int *trig, size_t size, size_t row, size_t column);

/*!
Выдает номер элемента массива по координатам его в матрице
\param[in] trig данный треугольник
\param[in] size длина треугольника
\param[in] row нужная строка таблицы
\param[in] column нужная колонка таблицы
*/
size_t triangle_pointer(size_t size, size_t row, size_t column);

/*!
Обновляет значение треугольника по указанной строке и столбцу
\param[in] trig данный треугольник
\param[in] size длина треугольника
\param[in] row нужная строка таблицы
\param[in] column нужная колонка таблицы
*/
void triangle_update(int *trig, size_t size, size_t row, size_t column, int new_value);

/*!
Создает нижнюю часть квадратного массива размеров size * size
\param[in] size длина матрицы
\return возвращает полученный треугольник
*/
int *triangle(size_t size);

/*!
Создает массив rows * columns и заполняет его случайными числами
\param[in] rows число строк
\param[in] columns число колонок
\return указатель на начало созданного массива
*/
int **matrix_rand(size_t rows, size_t columns);

/*!
Заменяет все значения массива новым значением
\param[in] data матрица, где меняются значения
\param[in] rows число строк
\param[in] columns число колонок
\param[in] new_value значение для заполнения
\return указатель на начало созданного массива
*/
void matrix_override(int **data, size_t rows, size_t columns, int new_value);

/*!
Печатает произвольную матрицу int-ов с указанием на её первый элемент и её размеров
\param[in] data указатель на первый элемент
\param[in] rows число строк
\param[in] columns число колонок
*/
void matrix_printer(int **data, size_t rows, size_t columns);

/*!
Записывает в новую матрицу сумму исходных, если их размеры одинаковы
\param[in] A указатель на первый элемент матрицы B
\param[in] rows_A число строк A
\param[in] columns_A число колонок A
\param[in] B указатель на первый элемент матрицы B
\param[in] rows_B число строк B
\param[in] columns_B число колонок B
*/
int **matrix_sum(int **A, int **B, size_t rows_A, size_t columns_A, size_t rows_B, size_t columns_B);

/*!
Записывает в новую матрицу поэлементное произведение матриц, если их размеры одинаковы
\param[in] A указатель на первый элемент матрицы B
\param[in] rows_A число строк A
\param[in] columns_A число колонок A
\param[in] B указатель на первый элемент матрицы B
\param[in] rows_B число строк B
\param[in] columns_B число колонок B
*/
int **matrix_element_prov(int **A, int **B, size_t rows_A, size_t columns_A, size_t rows_B, size_t columns_B);

/*!
Записывает в новую матрицу произведение матриц, если их columns_A равно rows_B
\param[in] A указатель на первый элемент матрицы B
\param[in] rows_A число строк A
\param[in] columns_A число колонок A
\param[in] B указатель на первый элемент матрицы B
\param[in] rows_B число строк B
\param[in] columns_B число колонок B
*/
int **matrix_multiply(int **A, int **B, size_t rows_A, size_t columns_A, size_t rows_B, size_t columns_B);

#endif
