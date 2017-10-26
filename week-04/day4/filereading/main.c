#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Create a file with content with specific pattern (number+tab+string)
 */
void create_file(char* file_path) {
    FILE *fh = fopen(file_path, "w+");
    if (fh == NULL) {
        printf("Could not create file: %s", file_path);
        return;
    }

    fprintf(fh, "10\tthis is the multi-word string");
    fclose(fh);
}

/**
 * Read the file with fgets
 */
void read_file_fgets(char* file_path) {
    FILE *fh = fopen(file_path, "r");
    if (fh == NULL) {
        printf("The file %s does not exist!", file_path);
        return;
    }

    char line[255];
    fgets(line, 255, fh);
    printf("read_file_fgets() - line: %s\n",  line);
    fclose(fh);

    // get a pointer to the separator character
    char* p = strchr(line, '\t');

    // replace the separator to string ending character (\0)
    *p = '\0';

    // this way we will get "10\0", so we can convert this string to integer
    int number = atoi(line);

    // increasing the pointer with 1, there is where the string part begins: "this is the multi-word string\0"
    char* remaining = p+1;


    printf("read_file_fgets() - number: %d, string: %s\n", number, remaining);
}

/**
 * Read the file with fscanf
 */
void read_file_fscanf(char* file_path) {
    FILE *fh = fopen(file_path, "r");
    if (fh == NULL) {
        printf("The file %s does not exist!", file_path);
        return;
    }

    int num = 0;
    char str[255];

    fscanf(fh, "%d\t%s", &num, str);
    printf("read_file_fscanf() - number: %d, string: %s\n", num, str);
    fclose(fh);
}

/**
 * Read the file with fscanf using regex for string
 */
void read_file_fscanf_tricky(char* file_path) {
    FILE *fh = fopen(file_path, "r");
    if (fh == NULL) {
        printf("The file %s does not exist!", file_path);
        return;
    }

    int num = 0;
    char str[255];

    /*
     * Tricky read of string, which accepts whitespaces as well
     * note: the %s reads string without whitespace characters
     */
    fscanf(fh, "%d\t%[^\t\n]", &num, str);
    printf("read_file_fscanf_tricky() - number: %d, string: %s\n", num, str);
    fclose(fh);
}

int main(int argc, char** argv) {
    char file_name[] = "test.txt";

    create_file(file_name);
    read_file_fgets(file_name);
    read_file_fscanf(file_name);
    read_file_fscanf_tricky(file_name);
}
