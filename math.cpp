#include <cstdio>
#include <string>
#include <string.h>

#include "calculate.cpp"

using namespace std;

void displayCommands(){
    fprintf(stderr, "You can use one of the commands listed below:\t");
    fprintf(stderr, "<> is mandatory argument, [] is optional\r\n");
    fprintf(stderr, "\tquad - <a>x^2 + <b>x + [c] = 0\tsolves quadratic function\r\n");
    fprintf(stderr, "\tequ - followed by sets of <a>x + <b>y = <c>\tsolves system of equations\r\n");
    fprintf(stderr, "\tdist - <x1> <y1> [z1] <x2> <y2> [z2]\tcalculates distance between points\r\n");
    fprintf(stderr, "\tdist - <x1> <y1> [z1] <x2> <y2> [z2]\tcalculates point-point distance\r\n");
    fprintf(stderr, "\t(pp)dist - <A>x + <B>y + <C>z + <D> = 0 (<x>, <y>, <z>)\tcalculates point-plane distance\r\n");
    fprintf(stderr, "\tvec - <x1> <y1> [z1] <x2> <y2> [z2]\tcalculates vector between points\r\n");
    fprintf(stderr, "\tcrossprod - <x1> <y1> [z1] <x2> <y2> [z2]\tcalculates cross product of vectors\r\n");    
    fprintf(stderr, "\tplane - <x1> <y1> [z1] <x2> <y2> [z2]\tcalculates plane equation\r\n");    

    fprintf(stderr, "\thelp - displays this message\r\n\r\n");
    fprintf(stderr, "\tWrite help, h or ? after any command to gain more info.\r\n");
}

bool checkForHelp(int argc, char const *argv[]){
    return (argc == 2 || strcmp(argv[2], "help") == 0 || strcmp(argv[2], "h") == 0 || strcmp(argv[2], "?") == 0);
}

int main(int argc, char const *argv[]){

    if(argc < 2){
        displayCommands();
        return 0;
    }

    if(strcmp(argv[1], "quad") == 0 || strcmp(argv[1], "quadratic") == 0){

        if(checkForHelp(argc, argv)){
            fprintf(stderr, "Invalid number of arguments!\r\n");
            fprintf(stderr, "Please follow one of patterns listed below:\r\n");
            fprintf(stderr, "\t3 arguments for <a>x^2 + <b>x + <c> = 0\r\n");
            fprintf(stderr, "\t2 arguments for <a>x^2 + <b>x = 0\r\n");
        }else if(argc == 3){
            fprintf(stderr, "\tx = 0\r\n");
        }else if(argc == 4){
            quadtaticFunction(stod(argv[2]), stod(argv[3]));
        }else if(argc == 5){
            quadtaticFunction(stod(argv[2]), stod(argv[3]), stod(argv[4]));
        }else{
            fprintf(stderr, "Invalid arguments!\r\n");
        }

    }else if(strcmp(argv[1], "equ") == 0 || strcmp(argv[1], "equations") == 0){

        if(checkForHelp(argc, argv)){
            fprintf(stderr, "Invalid number of arguments!\r\n");
            fprintf(stderr, "Repeat this pattern:\r\n");
            fprintf(stderr, "\t- <a>x + <b>y = <c> \r\n");
        }else 
        if(argc == 8){        // made infinite arguments handling argc % == 2
            solveEquations(stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]), stod(argv[6]), stod(argv[7]));
        }else{
            fprintf(stderr, "Invalid arguments!\r\n");
        }

    }else if(strcmp(argv[1], "dist") == 0 || strcmp(argv[1], "distance") == 0 || strcmp(argv[1], "ppdist") == 0){
        
        if(checkForHelp(argc, argv)){
            fprintf(stderr, "Invalid number of arguments!\r\n");
            fprintf(stderr, "Please follow one of patterns lsited below:\r\n");
            fprintf(stderr, "\t4 arguments - (<x1>, <y1>) (<x2>, <y2>)\r\n");
            fprintf(stderr, "\t6 arguments - (<x1>, <y1>, <z1>) (<x2>, <y2>, <z2>)\r\n");
            fprintf(stderr, "\t7 arguments -  <A>x + <B>y + <C>z + <D> = 0 (<x>, <y>, <z>) - point to plane distance\r\n");
        }else if(argc == 6){
            calculateDistance(stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]));
        }else if(argc == 8){
            calculateDistance(stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]), stod(argv[6]), stod(argv[7]));   
        }else if(argc == 9){
            pointToPlaneDistance(stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]), stod(argv[6]), stod(argv[7]), stod(argv[8]));   
        }else{
            fprintf(stderr, "Invalid number of arguments!\r\n");
        }
        
    }else if(strcmp(argv[1], "vec") == 0 || strcmp(argv[1], "vector") == 0){

        if(checkForHelp(argc, argv)){
            fprintf(stderr, "Invalid number of arguments!\r\n");
            fprintf(stderr, "Please follow one of patterns lsited below:\r\n");
            fprintf(stderr, "\t4 arguments - |(<x1>, <y1>) (<x2>, <y2>)|\r\n");
            fprintf(stderr, "\t6 arguments - |(<x1>, <y1>, <z1>) (<x2>, <y2>, <z2>)|\r\n");
        }else if(argc == 6){
            calculateVector(stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]));
        }else if(argc == 8){
            calculateVector(stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]), stod(argv[6]), stod(argv[7]));   
        }else{
            fprintf(stderr, "Invalid number of arguments!\r\n");
        }

    }else if(strcmp(argv[1], "veccross") == 0 || strcmp(argv[1], "crossprod") == 0){

        if(checkForHelp(argc, argv)){
            fprintf(stderr, "Invalid number of arguments!\r\n");
            fprintf(stderr, "\t6 arguments - [<x1>, <y1>, <z1>] [<x2>, <y2>, <z2>]\r\n");
            fprintf(stderr, "\t9 arguments - (<x1>, <y1>, <z1>) (<x2>, <y2>, <z2>) (<x3>, <y3>, <z3>)\r\n");
        }else if(argc == 8){
            vectorCrossProduct(stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]), stod(argv[6]), stod(argv[7]));
        }else if(argc == 10){
            vectorCrossProduct(stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]), stod(argv[6]), stod(argv[7]), stod(argv[8]), stod(argv[9]), stod(argv[10]));   
        }else{
            fprintf(stderr, "Invalid number of arguments!\r\n");
        }

    }else if(strcmp(argv[1], "plane") == 0 ){

        if(checkForHelp(argc, argv)){
            fprintf(stderr, "Invalid number of arguments!\r\n");
            fprintf(stderr, "Please follow one of patterns lsited below:\r\n");
            fprintf(stderr, "\t9 arguments - (<x1>, <y1>, <z1>) (<x2>, <y2>, <z2>) (<x3>, <y3>, <z3>)\r\n");
        }else if(argc == 8){
            planeEquation(stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]), stod(argv[6]), stod(argv[7]));   
        }else if(argc == 11){
            planeEquation(stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]), stod(argv[6]), stod(argv[7]), stod(argv[8]), stod(argv[9]), stod(argv[10]));   
        }else{
            fprintf(stderr, "Invalid number of arguments!\r\n");
        }

    // }else if(strcmp(argv[1], "normvec") == 0 || strcmp(argv[1], "normalvector")){
        // if(checkForHelp(argc, argv)){
        //     fprintf(stderr, "Invalid number of arguments!\r\n");
        //     fprintf(stderr, "Please follow one of patterns lsited below:\r\n");
        //     fprintf(stderr, "\t4 arguments - <A>x + <B>y + <C>z + <D> = 0\tdefults to (0, 0, 0)\r\n");
        //     fprintf(stderr, "\t7 arguments - <A>x + <B>y + <C>z + <D> = 0\t(<x>, <y>, <z>) - point through which vector goes\r\n");
        // }else if(argc == 6){
        //     normalVector(stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]));
        // }else if(argc == 9){
        //     normalVector(stod(argv[2]), stod(argv[3]), stod(argv[4]), stod(argv[5]), stod(argv[6]), stod(argv[7]), stod(argv[8]));   
        // }else{
        //     fprintf(stderr, "Invalid number of arguments!\r\n");
        // }

    }else if(false){


    }else if(false){
    

    }else{

        if(strcmp(argv[1], "help") == 0 || strcmp(argv[1], "h") == 0 || strcmp(argv[1], "?") == 0){
            fprintf(stderr, "\r\nThis app was made for calculating. It aims for simple inputs, to speed up usage process.\r\n\r\n");
        }else{
            fprintf(stderr, "Invalid arguments!\r\n");
        }
        displayCommands();

    }


    return 0;
}