#include <stdio.h>

int main()
{
    FILE* fp;
    fp = fopen("myfile.txt", "w");
    fprintf(fp, "%s\n", "line 1");
    fprintf(fp, "%s\n", "line 2");
    fprintf(fp, "%s\n", "line 3");
    fclose(fp);
}