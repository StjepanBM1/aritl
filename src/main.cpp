
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
    float stack = 0;
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

        if (c == '\n')
            lines++;

        if (c == '\t')
            lines++;

        if (c == '#') {
            lines++;
            continue;
        }

        if (c == '+') {
            stack++;
            continue;
        }

        if (c == '-') {
            stack--;
            continue;
        }

        if (c == '*') {
            stack = stack * stack;
            continue;
        }

        if (c == '/') {
            stack = stack / stack;
            continue;
        }

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

