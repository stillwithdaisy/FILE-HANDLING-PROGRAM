#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file.\n");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(fp);
}

void writeFile(const char *filename) {
    FILE *fp = fopen(filename, "w");  // overwrite mode
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(fp, "This is the first line written to the file.\n");
    fprintf(fp, "This is the second line.\n");
    printf("Data written to '%s' successfully.\n", filename);
    fclose(fp);
}

void appendFile(const char *filename) {
    FILE *fp = fopen(filename, "a");  // append mode
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }
    fprintf(fp, "This line is appended to the file.\n");
    printf("Data appended to '%s' successfully.\n", filename);
    fclose(fp);
}

void readFile(const char *filename) {
    char ch;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    printf("Contents of '%s':\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

int main() {
    const char *filename = "myfile.txt";

    // Create file
    createFile(filename);

    // Write data
    writeFile(filename);

    // Append data
    appendFile(filename);

    // Read file content
    readFile(filename);

    return 0;
}
