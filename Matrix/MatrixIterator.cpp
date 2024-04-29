#include "MatrixIterator.h"

MatrixIterator::MatrixIterator(const Matrix& matrix) : mat(matrix), current(matrix.head) {
    // Starts the iterator at the head of the linked elements
}

int MatrixIterator::first() {
    current = mat.head; // Reset the current position to the head
}

void MatrixIterator::next() {
    if (current != -1) {
        current = mat.elements[current].next; // Move to the next element in the list
    }
    throw std::exception();
}

bool MatrixIterator::valid() const {
    return current != -1; // Checks if the current position is valid (not -1)
}

TElem MatrixIterator::getCurrent() const {
    if (!valid()) {
        throw std::exception();
    }
    return mat.elements[current].value; // Returns the value at the current position
}