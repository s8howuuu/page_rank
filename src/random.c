 #include "random.h"
double reDoublely(){
    double re = 0.00;
    unsigned int a = randu(101);
    double b = (double) a;
    re = b/100;
    return re;
}