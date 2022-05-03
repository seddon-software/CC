// 4.1	Which of the following code fragments compile and for those that do, write down the final values of the all variables used:

void a()
{
    // int x = 100;
    // int* p = &x;
    // (*p)--;
} 

void b()
{
    // int x = 100;
    // int y = 200;
    // int* p1 = &x;
    // int* p2 = &y;
    // p1 = p2;
    // (*p1)--;
}

void c()
{
    // int* p1;
    // int* p2;
    // x = 100;
    // p1 = &x;
    // p2 = 200;
}

void d()
{
    // int x = 50;
    // int* p1 = &x;
    // int** p2 = &x;
}

void e()
{
    // int* p = &x;
    // x = 99;
    // (*p)++;
}

void f()
{
    // int x = 50;
    // int* p = &x;
    // int** q = &p;
    // **q = *p + x;
}

void g()
{
    // int x = 50;
    // int* p = &x;
    // x = &p + x;
}

void h()
{
    // double x = 50;
    // int* p = &x;
    // (*p)++;
}

// 4.2	Which of the following code fragments compile?
void A()
{  
    // int x = 100;
    // const int* p = &x;
	// (*p)--;
}

void B()
{
    // int x = 100;
    // int* const p = &x;
	// *p--;
}

void C()
{
    // int x = 100;
    // const int* const p = &x;
	// x = (*p)--;
}

void D()
{
    // int x = 100;
    // const int** p = &x;
	// x = *p;
}

// 4.3	What do the following code fragments do?
void aa()
{
    // int x = 100;
    // int* p = &x;
    // *p = x++;
}

void bb()
{
    // int x = 100;
    // int* p = &x;
    // x = *p++;
}

void cc()
{
    // int x = 100;
    // int* p = &x;
    // *p++;
}


int main()
{
    a();
    b();
    c();
    d();
    e();
    f();
    g();
    h();
    A();
    B();
    C();
    D();
    aa();
    bb();
    cc();
}
