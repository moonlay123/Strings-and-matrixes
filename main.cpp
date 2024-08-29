#include "matrixes/matrix.h"
#include <stdio.h>
#include "strings/string.h"
#include "file_work/file.h"
int main()
{
    string ans = {};
    str_create(&ans, "");

    full_zip_analise("pictures/cat2.jpg");

    rle_printer(&ans);
}

/*int mas1[5][4] =
    {
    {1, 2, 2, 1},
    {3, 1, 5, 1},
    {4, 4, 1, 1},
    {1, 8, 2, 2},
    {1, 1, 5, 1}
    };

    int mas2[4][6] =
    {
    {1, 3, 2, 1, 2, 3},
    {4, 1, 2, 3, 5, 1},
    {8, 6, 1, 3, 1, 1},
    {1, 8, 3, 2, 3, 2},
    };

    int mas_mult1[3][4] =
    {
    {1, 2, 3, 4},
    {4, 5, 3, 4},
    {6, 2, 1, 2}
    };

    int mas_mult2[2][3] =
    {
    {1, 2, 3},
    {4, 5, 6}
    };

    int **multi2 = matrix_multiply((int **) mas1, (int **) mas2, 5, 4, 4, 6);
    int **multi1 = matrix_multiply((int **) mas_mult2, (int **) mas_mult1, 2, 3, 3, 4);

    matrix_printer(multi1, 2, 4);
    matrix_printer(multi2, 5, 6);

    free(multi2);
    free(multi1);

    int *trig = triangle(6);

    int n = 1;
    for (int i = 1; i <= 6; ++i)
    {
        for (int j = i + 1; j <= 6; ++j)
        {
            triangle_update(trig, 6, i, j, n++);
        }
    }

    print_triangle(trig, 6);

    int *rb = romb_create(5);
    romb_rand(rb, 5);
    romb_printer(rb, 5);

    free(trig);*/

    /*string ans = {};
    str_create(&ans, "");

    string str1 = {};
    str_create(&str1, "rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrggggaaaapppwwwwtttttssssllllsleleeeqoooo");


    printf("aboba");
    rle_cipher(&ans, &str1);
    rle_printer(&ans);

    string str2 = {};
    str_create(&str2, "");

    rle_decipher(&ans, &str2);

    zip_win(&ans, &str2, &str1);*/
