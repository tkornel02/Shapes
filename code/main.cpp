#include <iostream>
#include "point.h"
#include "line.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"
#include "shapeList.h"
#include "memtrace.h"
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>



int main()
{


    ///write teszt
    Circle c0;
    Square s0;
    Triangle t0;
    std::stringstream ss;
    c0.write(ss);
    s0.write(ss);
    t0.write(ss);
    std::string beolvasott;
    while(ss >> beolvasott)
    std::cout << beolvasott << std::endl;
    std::cout << std::endl;
    //Megprobalunk olvasni koroket a haromszoges fájlból
    Handler HibasKezeloKor;
    HibasKezeloKor.readCircles("triangles.txt");
    HibasKezeloKor.readCircles("kevesAdat.txt"); // Olyan fajlbol olvasunk, amelyben nincs eleg adat
    std::cout<< std::endl;

    //Megprobalunk negyzeteket olvasni a korok kozul majd egy hibas parameterut
    Handler HibasKezeloNegyzet;
    HibasKezeloNegyzet.readSquares("circles.txt");
    HibasKezeloNegyzet.readSquares("squaresError.txt");
    std::cout<< std::endl;

    //Megprobalunk haromszogeket olvasni a negyzetek kozul majd egy hibas parameterut
    Handler HibasKezeloHaromszog;
    HibasKezeloHaromszog.readTriangles("squares.txt");
    HibasKezeloHaromszog.readTriangles("trianglesError.txt");
    std::cout<< std::endl;


    std::cout<< "Hibasak eddig."<<std::endl << std::endl;
    Handler Kezelo;
    Kezelo.readAllShapes("circles.txt","squares.txt","triangles.txt");
    int cont; /**Folytat valtozo*/
    Kezelo.displayAll();

    do{
    cont = 0;

    Kezelo.displayContains();
    std::cout << "Folytat? (1-igen /0-nem) ";
    std::cin >> cont;
    }
    while (cont == 1);

    std::cout << "\nteszt vege." << std::endl;

    return 0;
}


