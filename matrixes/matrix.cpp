#include "matrix.h"

void print_triangle(int *trig, size_t size)
{
    size_t row_counter = 1;
    const size_t rows = size - 1;

    int trig_pointer = 0;

    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < row_counter; ++j)
        {
            printf("%d ", trig[trig_pointer++]);
        }

        ++row_counter;

        printf("\n");
    }
}

size_t romb_size(size_t diametr)
{
    return 2 * (diametr / 2) * (diametr / 2) + diametr + 1;
}

int *romb_create(size_t diametr)
{
    int *romb = (int *) calloc(romb_size(diametr) * sizeof(int), sizeof(int));

    return romb;
}

void romb_rand(int *romb, size_t diametr)
{
    size_t size = romb_size(diametr);

    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < size; ++i)
    {
        romb[i] = rand() % 10;
    }
}

void romb_printer(int *romb, size_t diametr)
{
    size_t indent = (diametr - 1) * 2;
    size_t print_amount = 1;
    const size_t half_diam = diametr / 2;
    size_t romb_pointer = 0;

    for (size_t i = 0; i < half_diam + 1; ++i)
    {
        for (size_t j = 0; j < indent; ++j) printf(" ");
        for (size_t j = 0; j < print_amount; ++j) printf("%d ", romb[romb_pointer++]);
        printf("\n");
        print_amount += 2;
        indent -= 2;
    }
    indent += 4;
    print_amount -= 4;
    for (size_t i = 0; i < half_diam; ++i)
    {
        for (size_t j = 0; j < indent; ++j) printf(" ");
        for (size_t j = 0; j < print_amount; ++j) printf("%d ", romb[romb_pointer++]);
        printf("\n");
        print_amount -= 2;
        indent += 2;
    }
}

int *triangle(size_t size)
{
    int *data = (int *) calloc(size * (size-1) * sizeof(int) / 2, sizeof(int));
    return data;
}

size_t triangle_pointer(size_t size, size_t row, size_t column)
{
    assert(row <= size);
    assert(column <= size);
    assert(row != column);

    if (column > row)
    {
        size_t temp = row;
        row = column;
        column = temp;
    }

    return (row - 1) * (row - 2) / 2 + column - 1;
}

void triangle_update(int *trig, size_t size, size_t row, size_t column, int new_value)
{
    size_t input_place = triangle_pointer(size, row, column);

    trig[input_place] = new_value;
}

int triangle_get(int *trig, size_t size, size_t row, size_t column)
{
    size_t input_place = triangle_pointer(size, row, column);

    return trig[input_place];
}

void matrix_override(int **data, size_t rows, size_t columns, int new_value)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            *((int *) data + i * columns + j) = new_value;
        }
    }
}

int **matrix_rand(size_t rows, size_t columns)
{
    int **ans = (int **) malloc(rows * columns * sizeof(int) + columns * sizeof(int));

    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            *((int *) ans + i * columns + j) = rand() % 20000 - 10000;
        }
    }

    return ans;
}

void matrix_printer(int **data, size_t rows, size_t columns)
{
    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < columns; ++j)
        {
            printf("%d ",
            *(int *)(((char *) data + i * columns * sizeof(int)) + j * sizeof(int)));
        }
        printf("\n");
    }
    printf("\n");
}

int **matrix_sum(int **A, int **B, size_t rows_A, size_t columns_A, size_t rows_B, size_t columns_B)
{
    assert(rows_A == rows_B);
    assert(columns_A == columns_B);

    int **ans = (int ** ) malloc(rows_A * columns_A * sizeof(int) + columns_A * sizeof(int));

    for (size_t i = 0; i < rows_A; ++i)
    {
        for (size_t j = 0; j < columns_A; ++j)
        {
            *((int *) ans + i * columns_A + j) =
            *((int *) A +   i * columns_A + j) +
            *((int *) B +   i * columns_A + j);
        }
    }
    return (int **) ans;
}

int **matrix_element_prov(int **A, int **B, size_t rows_A, size_t columns_A, size_t rows_B, size_t columns_B)
{
    assert(rows_A == rows_B);
    assert(columns_A == columns_B);

    int **ans = (int ** ) malloc(rows_A * columns_A * sizeof(int) + columns_A * sizeof(int));

    for (size_t i = 0; i < rows_A; ++i)
    {
        for (size_t j = 0; j < columns_A; ++j)
        {
            *((int *) ans + i * columns_A + j) =
            *((int *) A +   i * columns_A + j) *
            *((int *) B +   i * columns_A + j);
        }
    }
    return (int **) ans;
}

int **matrix_multiply(int **A, int **B, size_t rows_A, size_t columns_A, size_t rows_B, size_t columns_B)
{
    assert(columns_A == rows_B);

    int **ans = (int ** ) calloc(rows_A * columns_B * sizeof(int) + columns_B * sizeof(int), sizeof(int));

    for (size_t i = 0; i < rows_A; ++i)
    {
        for (size_t j = 0; j < columns_B; ++j)
        {
            for (size_t m = 0; m < rows_B; ++m)
            {
                *((int *) ans + i * columns_B + j) +=
                *((int *) A +   i * columns_A + m) *
                *((int *) B +   m * columns_B + j);
            }
        }
    }

    return (int **) ans;
}
