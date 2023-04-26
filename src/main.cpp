
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    string file(argv[1]);
    bool eop = false;
    int stack = 0;
    vector <char> bytes;
    int lines = 0;

    FILE* in_file = fopen(file.c_str(), "r");

    if (in_file == nullptr) {
        fprintf(stderr, "aritl: file [%s] not found\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (file.substr(file.find_first_of(".") +1) != "al") {
        fprintf(stderr, "artil: [%s] wrong file exstension\n", argv[1]);
        return EXIT_FAILURE;
    }

    int c;
    while ((c = fgetc(in_file)) != EOF)
    {

        if (eop == true)
            break;

        if (c == '\n') {
            lines++;
            continue;
        }

        // Ignore indents
        if (c == '\t') {
            lines++;
            continue;
        }

        // Skip comments
        if (c == '#') {
            lines++;
            continue;
        }

        // Multi-line comment
        if (c == '[') {
            while ((c = fgetc(in_file)) != EOF) {
                if (c == '\n')
                    lines++;
                if (c == ']') {
                    lines++;
                    break;
                }
            }
            continue;
        }

        // Add one (1) from the stack
        if (c == '+') {
            stack++;
            continue;
        }

        // Remove one (1) from the stack
        if (c == '-') {
            stack--;
            continue;
        }

        // Multiply the stack by itself
        if (c == '*') {
            stack = stack * stack;
            continue;
        }

        // Devide the stack by itself
        if (c == '/') {
            stack = stack / stack;
            continue;
        }

        // Display character (no newline)
        if (c == '!') {
            printf("%c", stack);
            continue;
        }

        // Display character (w/ newline)
        if (c == '\\') {
            printf("%c\n", stack);
            continue;
        }

        // End of program
        if (c == '@') {
            eop = true;
            break;
        }
    }

    if (eop == false) {
        fprintf(stderr, "aritl: [%s] no end of program char.\n", argv[1]);
        return EXIT_FAILURE;
    }

    cout << "STACK : " << stack << endl;
    cout << "LINES : " << lines << endl;
    fclose(in_file);

    return EXIT_SUCCESS;
}

