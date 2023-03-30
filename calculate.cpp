#include <cstdio>
#include <math.h>
#include <string>



void planeEquation(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3){      // 3 points
    fprintf(stderr, "\tlane = A*%f + B*%f + C*%f + D = 0\r\n", 1,2,3);
}
void planeEquation(double a, double b, double c, double x0, double y0, double z0){      // vector and point
    fprintf(stderr, "\tlane = A*%f + B*%f + C*%f + %f = 0\r\n", a, b, c, -(a * x0 + b * y0 + c * z0));
}

void calculateVector(double x1, double y1, double x2, double y2){       // 2D points
    fprintf(stderr, "\tvector = [%f, %f]\r\n", (x2 - x1), (y2 - y1));
}
void calculateVector(double x1, double y1, double z1, double x2, double y2, double z2){     // 3D points
    fprintf(stderr, "\tvector = [%f, %f, %f]\r\n", (x2 - x1), (y2 - y1), (z2 - z1));
}

void vectorCrossProduct(double x1, double y1, double z1, double x2, double y2, double z2){      // 2 vectors given
    fprintf(stderr, "\tcross product = [%f, %f, %f]\r\n", (y1*z2 - z1*y2), (z1*x1 - x1*z2), (y2*x1 - x1*y2));
}
void vectorCrossProduct(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3){     // 3 points given

}

void calculateDistance(double x1, double y1, double x2, double y2){     // 2D points
    fprintf(stderr, "\tdistance = %f\r\n", sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) ));
}
void calculateDistance(double x1, double y1, double z1, double x2, double y2, double z2){       // 3D points
    fprintf(stderr, "\tdistance = %f\r\n", sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) + (z2 - z1)*(z2 - z1) ));
}
void pointToPlaneDistance(double a, double b, double c, double d, double x, double y, double z){       // plane, point
    fprintf(stderr, "\tdistance = %f\r\n", abs( (a*x + b*y + c*z + d)/sqrt(a*a + b*b + c*c)) );
}

void quadtaticFunction(double a, double b, double c){
    double delta = b*b - 4 * a * c;
    
    if(delta < 0){
        fprintf(stderr, "\tNo solution.\r\n");
        return;
    }
    
    if(delta >= 0){
        fprintf(stderr, "\tx1 = %f\r\n", (sqrt(delta) - b) / 2 / a);
    }

    if (delta > 0){
        fprintf(stderr, "\tx2 = %f\r\n", (-sqrt(delta) - b) / 2 / a);
    }
}

void quadtaticFunction(double a, double b){
    if(a == 0){
        fprintf(stderr, "\tx = 0\r\n");
    }else if(b == 0){
        fprintf(stderr, "\tx = 0\r\n");
    }else{
        fprintf(stderr, "\tx1 = 0\r\n");
        fprintf(stderr, "\tx2 = %f\r\n", (-b / a));
    }
}

void solveEquations(double a1, double b1, double c1, double a2, double b2, double c2){
    double w = a1 * b2 - a2 * b1;
    double wx = c1 * b2 - c2 * b1;
    double wy = c2 * a1 - c1 * a2;

    if(w == 0){
        if(wx == 0 && wy == 0){
            fprintf(stderr, "\tInfinite sulutions.\r\n");
        }else{
            fprintf(stderr, "\tNo sulution.\r\n");
        } 
    }else{
        fprintf(stderr, "\tx = %f\r\n", wx/w);
        fprintf(stderr, "\ty = %f\r\n", wy/w);
    }
}
