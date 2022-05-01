
void   func(char*, char, int, float);

int   main(void)
{
       char   c = 'c';
       int    d = 10;
       float  f = 10.0F;

       func("a string", c, d, f);
       printf("%c %d\n", c, d, f, f);
       printf("%d %d\n");
}

void   func(char* s, char x, int i, float fl)
{
       x  = 'g';
       i  = 20;
       fl = 14.1;
}
