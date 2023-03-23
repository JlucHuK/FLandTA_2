#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 128

int main() {
    FILE *inputfile;
    FILE *outputfile;
    int j;
    char string[MAXSIZE];
    char matrix[sizeof(string)][sizeof(string)];
    int first, second;
    inputfile = fopen("C:/Project/C/input.txt", "r");
    outputfile = fopen("C:/Project/C/forgraph.dot", "w");
    fprintf(outputfile, "graph{\n");
    char sep[10] = " ";
    char *p;
    int i = 0;
    while (fgets(string, sizeof(string), inputfile)) {
        j = 0;
        int s;
        p = strtok(string, sep);
        s = atoi(p);
        while (p != NULL) {
            if (s != 0) {
                matrix[i][j] = s;
                p = strtok(0, sep);
                s = atoi(p);
                printf("%d %d\n", i, j);
                j++;
            } else {
                matrix[i][j] = 0;
                p = strtok(0, sep);
                s = atoi(p);
                j++;
            }
        }
        i++;
    }
    first = i+1;
    second = j+1;
    for(int i = 0; i < first; i++) {
        for (int j = 0; j < second; j++) {
            if (matrix[i][j] != 0 && (i < j || i == j)) {
                for (int h = 0; h < matrix[i][j]; h++) {
                        fprintf(outputfile, "%d -- %d;\n", i+1, j+1);
                    }
                }
            }
        }
    fprintf(outputfile, "}\n");
    fclose(inputfile);
    fclose(outputfile);
    system("dot -Tpng -O C:/Project/C/forgraph.dot");
    system("C:/Project/C/forgraph.dot.png");

    return 0;
}
