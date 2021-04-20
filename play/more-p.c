
int main(void) {
    int x = 100;
    double* p;
    int* q;
    void* v;   // unknown pointer types
    v = &x;    // only a place holder
    // v++;       // doesn't work
    // *v;       // doesn't work
    
    q = (double*) v;      // compiler now knows we are working with int*
    q = &x;
    p = &x;  // wrong
}