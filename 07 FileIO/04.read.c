#include <stdio.h>

int main()
{
    FILE* fp;
    char buffer[32];
    fp = fopen("myfile.txt", "r");
    while(!feof(fp))
    {
        fscanf(fp, "%[^\n]\n", buffer);
        printf("%s\n", buffer);
    }
    fclose(fp);
}
