
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <bitset>
#include <vector>

#include "h/types.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    string file(argv[1]);
    bool eop = false;

    /* Stack */
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

        switch(c)
        {
            case NWL:
                lines++;
                continue;

            case TAB:
                lines++;
                continue;

            case COP:
                while ((c = fgetc(in_file)) != EOF) {
                    if (c == NWL)
                        lines++;
                    if (c == CCL)
                        lines++;
                        break;
                }
                continue;

            case ADD:
                stack++;
                continue;

            case SUB:
                stack--;
                continue;
            
            case MUL:
                stack = stack * stack;
                continue;

            case DIV:
                stack = stack / stack;
                continue;
            
            case IN:
                cout << "?"; cin >> stack;
                continue;

            case OUT:
                printf("%c", stack);
                continue;

            case ONL:
                printf("%c\n", stack);
                continue;
            
            case CLR:
                stack = 0;
                continue;

            case EOP:
                eop = true;
                continue;

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
