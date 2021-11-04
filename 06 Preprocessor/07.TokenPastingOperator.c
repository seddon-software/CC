// paste two tokens together with ##

#define DEFINE_CUBE(TYPE)                \
    TYPE CubeOf##TYPE (TYPE number)      \
    {                                    \
        return number * number * number; \
    }


DEFINE_CUBE(int);
DEFINE_CUBE(double);

int main (void)
{
     int    n;
     double x;
          
     n = CubeOfint(2);
     x = CubeOfdouble(2.5);
}
