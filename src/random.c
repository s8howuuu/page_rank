 #include "random.h"
double reDoublely(){
    double re = 0.00;
    unsigned int a = randu(1000001);
    double b = (double) a;
    re = b/1000000;
    return re;
}