#include "string.h"


void zip_win(string *rle_ciphered, string *rle_deciphered, string *original)
{
    assert(rle_ciphered != NULL);
    assert(rle_deciphered != NULL);
    assert(original != NULL);

    size_t orig_size = my_strlen((const char *)original->mas);

    rle_printer(rle_ciphered);
    printf("%s\n", rle_deciphered->mas);
    printf("%s\n", original->mas);
    printf("zip in %lf times", (double)orig_size / (double) rle_ciphered->size);
}

void rle_decipher(string *rle, string *str)
{
    assert(rle != NULL);
    assert(str != NULL);

    size_t pointer = 0;
    int similar = 0;

    while(pointer < rle->size)
    {
        if (is_liter(rle->mas[pointer]))
        {
            for (int i = 1; i < similar; i ++)
            {
                str_push(str, rle->mas[pointer]);
            }
            similar = 0;
            str_push(str, rle->mas[pointer++]);
        }
        else
        {
            similar = rle->mas[pointer++];
            if (similar < 0) similar = 0;
        }
    }
    printf("\n");
}

bool is_liter(signed char a)
{
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
}

void rle_printer(string *str)
{
    assert(str != NULL);

    size_t pointer = 0;

    while(pointer < str->pointer)
    {
        if (is_liter(str->mas[pointer]))
        {
            printf("%c", str->mas[pointer++]);
        }
        else
        {
            printf("%d", str->mas[pointer++]);
        }
    }
    printf("\n");
}

void rle_cipher(string *vessel, string *str)
{
    assert(vessel != NULL);
    assert(str != NULL);

    size_t str_size = str->size;

    if (str_size == 1)
    {
        str_push(vessel, 1);
        str_push(vessel, str->mas[0]);
        return;
    }

    size_t left = 0, right = 0;
    size_t different = 0, similar = 0;

    while (str_size > right + 1)
    {
        while (right + 1 < str_size and str->mas[right] != str->mas[right+1] and is_liter(str->mas[right]))
        {
            ++different;
            ++right;
        }
        if (different > 0)
        {
            str_push(vessel, (signed char) -different);

            for (size_t i = left; i < right; ++i)
            {
                str_push(vessel, str->mas[i]);
            }

            left = right;
        }

        while (right + 1 < str_size and str->mas[right] == str->mas[right+1] and is_liter(str->mas[right]))
        {
            similar += 1;
            ++right;
        }
        if (similar > 0)
        {
            ++right;
            ++similar;

            str_push(vessel, (signed char) similar);
            str_push(vessel, str->mas[right - 1]);

            left = right;
        }

        different = 0;
        similar = 0;
    }
}

void str_create(string *ans, const char *str)
{
    assert(ans != NULL);
    assert(str != NULL);

    size_t str_size = my_strlen(str);
    ans->mas = (signed char *) calloc(str_size + 1, sizeof(signed char));
    for (size_t i = 0; i < str_size; ++i)
    {
        ans->mas[i] = str[i];
    }
    ans->capacity = str_size + 1;
    ans->size = str_size;
}

void str_push(string *str, signed char value)
{
    assert(str != NULL);

    if (str->capacity <= str->size)
    {
        str->capacity *= 2;
        str->mas = (signed char *) _recalloc(str->mas, str->capacity, sizeof(signed char));
    }

    str->mas[str->pointer++] = value;
    str->size = max(str->pointer, str->size);
}

size_t my_getline(char **lineptr, size_t n, FILE *stream)
{
    *lineptr = (char *) malloc(n);
    if (stream == NULL or feof(stream))
    {
        return -1;
    }

    int file_c = fgetc(stream);

    size_t count_of_symbols = 0;
    while(!feof(stream) and file_c != '\0' and file_c != '\n')
    {
        ++count_of_symbols;

        if (count_of_symbols >= n)
        {
            n *= 2;
            *lineptr = (char *) realloc(*lineptr, n);
        }
        (*lineptr)[count_of_symbols - 1] = (char)file_c;
        file_c = fgetc(stream);
    }
    (*lineptr)[count_of_symbols] = '\0';
    return count_of_symbols;
}

char *my_strdup(const char *str)
{
    char *new_str = (char *)malloc(my_strlen(str));
    char *start_new_str = new_str;

    while (*str != '\0')
        *new_str++ = *str++;

    *new_str = '\0';

    return start_new_str;
}

char *my_fgets(char *str, size_t num, FILE *stream)
{
    if (stream == NULL or feof(stream))
    {
        return NULL;
    }

    int file_c = fgetc(stream);

    size_t str_size = 0;
    for (size_t i = 0; i < num + 1; ++i)
    {
        if (!feof(stream) and file_c != EOF and file_c != '\n')
            str[str_size++] = (char)file_c;

        file_c = fgetc(stream);
    }

    *str = '\0';

    return str;
}

int my_puts(const char *str)
{
    if (printf("%s", str) > 0)
        return '\n';

    return EOF;
}

char *my_strchr(char *str, int symbol)
{
    while (*(str++) != '\0')
    {
        if (*str == symbol)
            return (char *)str;
    }

    return NULL;
}

size_t my_strlen(const char *str)
{
    size_t str_size = 0;
    while (*str++ != '\0')
        str_size++;

    return str_size;
}

char *my_strcpy(char *destination, const char *source)
{
    char *start_destination = destination;
    while (*source != '\0')
    {
        *destination++ = *source++;
    }

    return start_destination;
}

char *my_strncpy(char *destination, const char *source, size_t num)
{
    size_t destination_size = 0;

    for (size_t i = 0; i < num; ++i)
    {
        if (*source == '\0')
        {
            *destination++ = '\0';
        }
        else
        {
            destination[destination_size++] = *source++;
        }
    }

    return destination;
}

char *my_strcat(char *destination, const char *source)
{
    size_t destination_size = 0;

    while (destination[destination_size] != '\0')
        ++destination_size;

    while (*source != '\0')
        destination[destination_size++] = *source++;

    destination[destination_size] = '\0';

    return destination;
}

char *my_strncat(char *destination, const char *source, size_t num)
{
    size_t destination_size = 0;

    while (destination[destination_size] != '\0')
        ++destination_size;

    for (size_t i = 0; i < num; ++i)
    {
        if (*source == '\0')
        {
            destination[destination_size] = *source;
            break;
        }

        destination[destination_size++] = *source++;
    }

    return destination;
}
