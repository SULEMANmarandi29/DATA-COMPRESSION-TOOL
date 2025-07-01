# DATA-COMPRESSION-TOOL

COMPANY: CODTECH IT SOLUTIONS

NAME: AMAN SULEMAN MARANDI

INTERN ID: CT04DF2337

DOMAIN: C PROGRAMMING

DURATION: 4 WEEKS

MENTOR: NEELA SANTHOSH KUMAR



# Data Compression in C Using Run-Length Encoding (RLE)

# INTRODUCTION

In a world increasingly overwhelmed by data, compression techniques play a vital role in reducing file sizes, improving storage efficiency, and speeding up transmission. One of the simplest and most widely used lossless compression techniques is Run-Length Encoding (RLE). It is particularly effective for data that contains many consecutive repeating elements, such as black-and-white images or simple text patterns.
In this write-up, we'll explore the concept of RLE, how it can be implemented in the C language, and its practical applications.

# What is Run-Length Encoding?

RLE is a lossless data compression algorithm that replaces consecutive duplicate values (runs) with a single value and its count. It transforms data from a verbose form into a compact representation.
Example:
Original string:
AAAABBBCCDAA


Compressed using RLE:
4A3B2C1D2A


Here, four A’s are represented as 4A, three B’s as 3B, and so on.

# Implementation in C Language
The C programming language, being close to the hardware and highly efficient, is a great candidate for implementing such algorithms. Below is a simplified version of an RLE encoder:
#Sample Code
#include <stdio.h>
#include <string.h>

void runLengthEncode(char *input) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        // Count occurrences of the current character
        int count = 1;
        while (i < length - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        printf("%d%c", count, input[i]);
    }
    printf("\n");
}

int main() {
    char str[] = "AAAABBBCCDAA";
    printf("Original: %s\n", str);
    printf("Encoded: ");
    runLengthEncode(str);
    return 0;
}


 Output
Original: AAAABBBCCDAA  
Encoded: 4A3B2C1D2A


This implementation uses a simple loop to scan characters and count their frequencies. The encoded data is printed in the format <count><character>.

# Use Cases
- Bitmap images with large blocks of a single color (e.g., black-and-white icons)
- Text compression for repetitive data patterns
- Sensor data where values might not vary frequently
However, RLE is not effective if the input data has very few runs (high randomness), as the output might even become larger than the original.

# Advantages and Limitations Pros
- Simple to implement
- Fast compression and decompression
- Lossless (original data can be perfectly reconstructed)
* Cons
- Not efficient for complex or non-repetitive data
- Output size may increase if data doesn’t contain long runs

# Enhancements and Variations
In a real-world application, the basic RLE can be extended with optimizations such as:
- Using markers or flags for encoded sequences
- Combining with other compression methods like Huffman coding
- Encoding binary data instead of characters

# Conclusion
Run-Length Encoding stands out due to its simplicity and effectiveness for specific types of data. While it doesn't suit every scenario, its implementation in C demonstrates both the power of basic algorithms and the efficiency of low-level programming. Whether you're compressing image data or simplifying text streams, RLE offers a clear introduction to the world of data compression and is a perfect starting point for learning more complex algorithms.

#OUTPUT


![Image](https://github.com/user-attachments/assets/be86daac-261a-47c2-8085-a36d131a2817
