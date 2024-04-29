
#include "Matrix.h"
#include <exception>
using namespace std;
//#include "MatrixIterator.h"
Matrix::Matrix(int nrLines, int nrCols) {
    this->nrLine = nrLines;
    this->nrCols = nrCols;
    this->capacity = nrLines*nrCols;
    this->head = -1;
    this->firstEmpty = 0;
    this->elements = new Node[this->capacity];

    for (int i = 0; i < this->capacity - 1; i++) {
        this->elements[i].next = i + 1;
    }
    this->elements[this->capacity - 1].next = -1;
}

Matrix::~Matrix() {
    delete[] this->elements;
}

int Matrix::nrLines() const {
    return this->nrLine;
}

int Matrix::nrColumns() const {
    return this->nrCols;
}

TElem Matrix::element(int i, int j) const {
    if (i < 0 || i >= this->nrLine || j < 0 || j >= this->nrCols) {
        throw std::exception();
    }

    int current = this->head;
    while (current != -1) {
        if (this->elements[current].line == i && this->elements[current].column == j) {
            return this->elements[current].value;
        }
        current = this->elements[current].next;
    }

    return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
    if (i < 0 || i >= this->nrLine || j < 0 || j >= this->nrCols) {
        throw std::exception();
    }

    int current = this->head;
    int prev = -1;
    while (current != -1) {
        if (this->elements[current].line == i && this->elements[current].column == j) {
            TElem oldValue = this->elements[current].value;
            this->elements[current].value = e;
            return oldValue;
        }
        prev = current;
        current = this->elements[current].next;
    }

    if (this->firstEmpty == -1) {
        this->resize();
    }

    int newElemPos = this->firstEmpty;
    this->firstEmpty = this->elements[this->firstEmpty].next;
    this->elements[newElemPos].line = i;
    this->elements[newElemPos].column = j;
    this->elements[newElemPos].value = e;
    this->elements[newElemPos].next = -1;

    if (prev == -1) {
        this->head = newElemPos;
    } else {
        this->elements[prev].next = newElemPos;
    }

    return NULL_TELEM;
}

void Matrix::resize() {
    Node* newElements = new Node[this->capacity * 2];
    for (int i = 0; i < this->capacity; i++) {
        newElements[i] = this->elements[i];
    }
    for (int i = this->capacity; i < this->capacity * 2 - 1; i++) {
        newElements[i].next = i + 1;
    }
    newElements[this->capacity * 2 - 1].next = -1;

    this->firstEmpty = this->capacity;
    this->capacity *= 2;

    delete[] this->elements;
    this->elements = newElements;
}
//MatrixIterator Matrix::iterator(){
//    return MatrixIterator(*this);
//}