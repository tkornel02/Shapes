#ifndef SHAPELIST_H_INCLUDED
#define SHAPELIST_H_INCLUDED
#include "shape.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"
#include "serializable.h"
#include "memtrace.h"
#include <fstream>
#include <string>
#include <iostream>

int howManyObj(const char* filename);

/**Megszamolja egy fájlban hány sor van*/

/**std::vector-szeru egyszeru tarolo */
template<typename TIPUS>
class Vektor {
    TIPUS* adat;
    size_t meret;
public:
    ///Constr
    explicit Vektor(size_t meret = 0) :
            adat(nullptr),
            meret(meret) {
    }
    ///Copy
    Vektor(Vektor const& masik){
        meret=masik.meret;
        adat=new TIPUS[meret];
        for(size_t i=0;i<meret;i++)
            adat[i]=(masik.adat)[i];
    }
    ///Assign
    Vektor& operator=(Vektor const & masik){
        if(this!=&masik){
            delete [] adat;
            adat=new TIPUS[meret];
            for(size_t i=0;i<meret;i++)
                adat[i]=(masik.adat)[i];
        }
        return *this;
    }
    ///Size
    size_t size() const {
        return meret;
    }
    /** Indexelőoperátor (nem végez határellenőrzést) */
    TIPUS& operator[](size_t index) {
        return adat[index];
    }

    TIPUS const& operator[](size_t index) const {
        return adat[index];
    }
    ///Uj elem hozzaadasa a vektorhoz
    void push_back(TIPUS const& uj_ertek) {
        auto *uj_adat = new TIPUS[meret + 1];
        for(size_t i = 0; i < meret; ++i)
            uj_adat[i] = adat[i];
        uj_adat[meret] = uj_ertek;
        if (meret > 0) delete[] adat;
        adat = uj_adat;
        ++meret;
    }

    ///Vektor adatainak felszabadítása
    void clear(){
        for (size_t i = 0; i < meret; i++)
            delete adat[i];
        meret=0;
        delete[] adat;
    }
};

/**Foprogramban a kezelo*/
class Handler{
    Vektor<Shape*> shapes;
public:
    Handler(){
        std::cout << "Kezelo megnyitva."<< std::endl;
    }
    void readAllShapes(std::string circleFileName,std::string squareFileName,std::string triangleFileName);

    void displayContains();

    void displayAll(){
        for (size_t i = 0; i<shapes.size(); i++){
                    shapes[i]->display();
            }
    }

    void readCircles(std::string circleFileName);
    void readSquares(std::string squareFileName);
    void readTriangles(std::string triangleFileName);

    ~Handler(){
        shapes.clear();
    }

};




#endif // SHAPELIST_H_INCLUDED
