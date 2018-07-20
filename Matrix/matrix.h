#ifndef MATRIX_H_
#define MATRIX_H_
#include<iostream>
#include<cassert>
using namespace std;

class Matrix {
public:
    // constructors
    Matrix(int = 0, int = 0);
    Matrix(const Matrix &);
    // Destructor
    ~Matrix();

    Matrix & operator=(const Matrix &);
    // Binary operators for addition, multiplication and subtraction

    Matrix operator+(const Matrix &);
    Matrix operator-(const Matrix &);
    Matrix operator*(const Matrix &); // point-wise matrix multiplication

    // Unary -ve operator
    Matrix operator-(); // unary -ve

    // Operators for scalar addition, subtraction and mutliplication
    Matrix operator+(const float &) const; // scalar addition
    Matrix operator-(const float &); // scalar subtraction
    Matrix operator*(const float &); // scalar multiplication

    // Overloading the function call operator for accessing indiviual matrix elements

    float operator()(int, int) const; // for rhs of an expression
    float& operator()(int, int); // for lhs of an expression

    // Scalar addition for case x + M
    friend Matrix operator+(const float &, const Matrix & M); // for scalar addition with operator as caller

    // overloaded stream insertion and extraction operators
    friend ostream & operator<<(ostream&, const Matrix&);
    friend istream & operator>>(istream&, const Matrix&);
private:
    int nr, nc; // number of rows and columns;
    float **mat; // 2D pointer to store the values
    // utility functions
    // for allocating memory
    void Initialize();
    // for deallocating
    void Destroy();
};
#endif
