#include "math.h"
#include <limits>

double add(double a, double b){
    return a+b;
}
double subtract(double a, double b){
    return a-b;
}
double multiply(double a, double b){
    return a*b;
}
double divide(double a, double b){
    if(b==0){
        return std::numeric_limits<double>::min();
    }
    return a/b;
}
