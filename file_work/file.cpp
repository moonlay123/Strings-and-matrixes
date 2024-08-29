#include "file.h"

void byte_file_open(FILE **fp, const char *file_name)
{
    assert(fp != NULL);

    if ((*fp = fopen(file_name, "rb")) == NULL)
    {
        perror("File open error");
    }
}

void file_close(FILE *fp)
{
    assert(fp != NULL);

    if (fclose(fp) != 0)
        perror("File close error");
}

size_t get_file_size(FILE *fp)
{
    assert(fp != NULL);

    size_t file_size = 0;

    if(fp == NULL){
		file_size = -1;
	} else{
		fseek(fp, 0, SEEK_END);
		file_size = ftello(fp);
        fseek(fp, 0, SEEK_SET);
	}

    return file_size;
}
