
#include <stdio.h>
#include <stdlib.h>

void rle_compress(const char *input_filename, const char *output_filename) {
    FILE *in = fopen(input_filename, "r");
    if (!in) {
        printf("Error opening input file.\n");
        return;
    }
    FILE *out = fopen(output_filename, "w");
    if (!out) {
        printf("Error opening output file.\n");
        fclose(in);
        return;
    }
    char prev = fgetc(in);
    if (prev == EOF) {
        fclose(in);
        fclose(out);
        printf("Input file is empty.\n");
        return;
    }
    int count = 1;
    char curr;
    while ((curr = fgetc(in)) != EOF) {
        if (curr == prev) {
            count++;
        } else {
            fprintf(out, "%c%d", prev, count);
            prev = curr;
            count = 1;
        }
    }
    fprintf(out, "%c%d", prev, count); 
    fclose(in);
    fclose(out);
    printf("Compression complete. Output written to %s\n", output_filename);
}

void rle_decompress(const char *input_filename, const char *output_filename) {
    FILE *in = fopen(input_filename, "r");
    if (!in) {
        printf("Error opening compressed file.\n");
        return;
    }
    FILE *out = fopen(output_filename, "w");
    if (!out) {
        printf("Error opening output file.\n");
        fclose(in);
        return;
    }
    char ch;
    while ((ch = fgetc(in)) != EOF) {
        if (isalpha(ch) || ispunct(ch) || ch == ' ') {
            // Read the count
            char count_str[20];
            int i = 0;
            char c;
            while ((c = fgetc(in)) != EOF && isdigit(c)) {
                count_str[i++] = c;
            }
            count_str[i] = '\0';
            int count = atoi(count_str);
            for (int j = 0; j < count; j++) {
                fputc(ch, out);
            }
            if (c != EOF) {
                ungetc(c, in);
            }
        }
    }
    fclose(in);
    fclose(out);
    printf("Decompression complete. Output written to %s\n", output_filename);
}

int main() {
    int choice;
    char input_file[100], output_file[100];
    printf("Run-Length Encoding Tool\n");
    printf("1. Compress a text file\n");
    printf("2. Decompress a file\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter input file name: ");
        scanf("%99s", input_file);
        printf("Enter output (compressed) file name: ");
        scanf("%99s", output_file);
        rle_compress(input_file, output_file);
    } else if (choice == 2) {
        printf("Enter compressed file name: ");
        scanf("%99s", input_file);
        printf("Enter output (decompressed) file name: ");
        scanf("%99s", output_file);
        rle_decompress(input_file, output_file);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}
