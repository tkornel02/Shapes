#include <iostream>
#include "shapeList.h"
int howManyObj(const char* filename){
FILE *file = fopen(filename, "r");
	char ch;
	int count = 0;

    while ((ch=getc(file))!=EOF)
        {
		if (ch=='\n')
        count++;
    }
    try{
    if (count % 3 != 0) throw std::runtime_error("Number of objects invalid in file.\n");}
    catch (std::runtime_error& msg){std::cout << msg.what();}
    fclose(file);
    return count/3;
}

void Handler::readAllShapes(std::string circleFileName,std::string squareFileName,std::string triangleFileName){

        /*Korok beolvasasa*/
        readCircles(circleFileName);
        /*Negyzetek beolvasasa*/
        readSquares(squareFileName);
        /*Haromszogek beolvasasa*/
        readTriangles(triangleFileName);
}
/**Ker egy pontot es kiirja melyik alakzatok tartalmazzak azt */
void Handler::displayContains(){
    Point p0;
    std::cout << "Melyik pont? [(x,y)] " << std::endl;
    std::cin >> p0;
        std::cout << "A kovetkezo alakzatok tartalmazzak a "<< p0 <<" pontot: " << std::endl;
        for (size_t i = 0; i<shapes.size(); i++){
            if(shapes[i]->contains(p0))
                shapes[i]->display();
        }
    std::cout << std::endl;
}
void Handler::readCircles(std::string circleFileName){
    std::fstream cir;
    cir.open(circleFileName.c_str());
    int howManyCircles = howManyObj(circleFileName.c_str()); /*Sorok megszamolasa*/
    /*Korok beolvasasa*/
    Circle tempCircle; /*Ideiglenesen ebbe töltjük az adatot majd onnan a tárolóba*/
    try{
        for (int i = 0; i<howManyCircles; i++){
            cir >> tempCircle;
            Circle teszt(tempCircle);
            if (!teszt.isInCircle(1)){ /**< csak azokat tároljuk amelyek az egységkörön kívül vannak   */
                shapes.push_back(new Circle(teszt));}
        }
    }
    catch (std::out_of_range& orr){std::cerr << orr.what();}
    cir.close();
}
void Handler::readSquares(std::string squareFileName){
    std::fstream sqr;
    sqr.open(squareFileName.c_str());
    int howManySquares = howManyObj(squareFileName.c_str());     /*Sorok megszamolasa*/
    /*Negyzetek beolvasasa*/
    Square tempSquare;   /*Ideiglenesen ebbe töltjük az adatot majd onnan a tárolóba*/
    try{
        for (int i = 0; i<howManySquares; i++){
            sqr >> tempSquare;
            Square teszt(tempSquare);
            if (!teszt.isInCircle(1)){ /**< csak azokat tároljuk amelyek az egységkörön kívül vannak   */
                shapes.push_back(new Square(tempSquare));}
        }
    }
    catch (const char* msg){std::cerr<<msg;}
    catch (std::out_of_range& orr){std::cerr << orr.what();}
    sqr.close();
}

void Handler::readTriangles(std::string triangleFileName){
            std::fstream tri;
        tri.open(triangleFileName.c_str());

        int howManyTriangles = howManyObj(triangleFileName.c_str()); /*Sorok megszamolasa*/

        Triangle tempTriangle;          /*Ideiglenesen ebbe töltjük az adatot majd onnan a tárolóba*/
    try{
        /*Haromszogek beolvasasa*/
        for (int i = 0; i<howManyTriangles; i++){
            tri >> tempTriangle;
            Triangle teszt(tempTriangle);
            if (!teszt.isInCircle(1)){ /**< csak azokat tároljuk amelyek az egységkörön kívül vannak   */
                shapes.push_back(new Triangle(teszt));}
            }
    }
    catch (const char* msg){std::cerr<<msg;}
    catch (std::out_of_range& orr){std::cerr << orr.what();}

        tri.close();

}



