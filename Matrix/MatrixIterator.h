// MatrixIterator.h
#pragma once
#include "Matrix.h"

class MatrixIterator {

private:
    const Matrix& mat;
    int current; // Tracks the current position in the list of elements

public:
    // Constructor initializes the iterator with the matrix
    MatrixIterator(const Matrix& matrix);

    // Resets the iterator to the beginning
    int first();

    // Moves the iterator to the next element
    void next();

    // Checks if there is a current element
    bool valid() const;

    // Returns the current element
    TElem getCurrent() const;
};