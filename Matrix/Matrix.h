#pragma once

#include <exception>
typedef int TElem;
#define NULL_TELEM 0

//class MatrixIterator;

class Matrix {
//    friend class MatrixIterator;


private:
    struct Node {
        int line;
        int column;
        TElem value;
        int next;
    };
    Node* elements;
    int nrLine;
    int nrCols;
    int capacity;
    int head;
    int firstEmpty;

    void resize();


public:
    Matrix(int nrLines, int nrCols);
    ~Matrix();

    int nrLines() const;
    int nrColumns() const;
    TElem element(int i, int j) const;
    TElem modify(int i, int j, TElem e);
//    MatrixIterator iterator() ;
};