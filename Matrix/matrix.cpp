#include "matrix.h"

Matrix::Matrix(int r, int c) {
    nr = r;
    nc = c;
    mat = NULL;
    if (nr != 0 && nc != 0)
        Initialize();
}
Matrix::Matrix(const Matrix & rhs) {
    nr = nc = 0;
    mat=NULL;
    *this = rhs;
}

// Destructor
Matrix::~Matrix() {
    Destroy();
}

Matrix & Matrix::operator=(const Matrix &rhs) {

    if (this == &rhs) // checking for self copying
        return *this;
    if (nr != 0 && nc != 0) // first Deallocate the existing memory of the current object
        Destroy();
    nr = rhs.nr;
    nc = rhs.nc;
    Initialize();
    // Now perform deep copying...
    for (int i = 0; i < nr; ++i)
        for (int j = 0; j < nc; ++j) {
            mat[i][j] = rhs.mat[i][j];
        }
    return *this;
}
Matrix Matrix::operator+(const Matrix &rhs) {
    assert(rhs.nr == nr && rhs.nc == nc);

    Matrix lhs(rhs.nr, rhs.nc);

    for (int i = 0; i < nr; ++i)
        for (int j = 0; j < nc; ++j) {
            lhs.mat[i][j] = mat[i][j] + rhs.mat[i][j];
        }
    return lhs;
}

Matrix Matrix::operator+(const float &f) const {

    Matrix lhs(nr, nc);
    for (int i = 0; i < nr; ++i)
        for (int j = 0; j < nc; ++j) {
            lhs.mat[i][j] = mat[i][j] + f;
        }
    return lhs;
}

Matrix Matrix::operator-(const Matrix &rhs) {
    assert(rhs.nr == nr && rhs.nc == nc);

    Matrix lhs(rhs.nr, rhs.nc);

    for (int i = 0; i < nr; ++i)
        for (int j = 0; j < nc; ++j) {
            lhs.mat[i][j] = mat[i][j] - rhs.mat[i][j];
        }
    return lhs;
}

Matrix Matrix::operator-() {
    Matrix lhs(nr, nc);

    for (int i = 0; i < nr; ++i)
        for (int j = 0; j < nc; ++j) {
            lhs.mat[i][j] = -mat[i][j];
        }
    return lhs;
}

Matrix Matrix::operator-(const float &f) {

    Matrix lhs(nr, nc);

    for (int i = 0; i < nr; ++i)
        for (int j = 0; j < nc; ++j) {
            lhs.mat[i][j] = mat[i][j] - f;
        }
    return lhs;
}

Matrix Matrix::operator*(const Matrix &rhs) {
    assert(rhs.nr == nr && rhs.nc == nc);

    Matrix lhs(rhs.nr, rhs.nc);

    for (int i = 0; i < nr; ++i)
        for (int j = 0; j < nc; ++j) {
            lhs.mat[i][j] = mat[i][j] * rhs.mat[i][j];
        }
    return lhs;
}

Matrix Matrix::operator*(const float &f) {

    Matrix lhs(nr, nc);

    for (int i = 0; i < nr; ++i)
        for (int j = 0; j < nc; ++j) {
            lhs.mat[i][j] = mat[i][j] * f;
        }
    return lhs;
}

float Matrix::operator()(int i, int j) const {
    assert(i < nr && j < nc);
    return mat[i][j];
}
float &Matrix::operator()(int i, int j) {
    assert(i < nr && j < nc);
    return mat[i][j];
}

Matrix operator+(const float &f, const Matrix & M) // for scalar addition with operator as caller
        {
    return M + f;
}
ostream & operator<<(ostream& out, const Matrix&rhs) {
    out << "\n----------------------------------- \n";
    for (int i = 0; i < rhs.nr; ++i) {
        for (int j = 0; j < rhs.nc; ++j) {
            out << rhs.mat[i][j] << " ";
        }
        out << endl;
    }
    out << "\n+++++++++++++++++++++++++++++++++++ \n";
    return out;
}

istream & operator>>(istream& in, const/*note constant over here*/Matrix& rhs) {
    // This constant over here works because we are chaning the value pointed by the
    // pointer not the address in the pointer
    // Note i am not allowed to write " in >> rhs.nc;" it will give syntax error
    // because rhs is constant
    cout << " Please enter " << rhs.nr * rhs.nc << " elements: ";
    for (int i = 0; i < rhs.nr; ++i)
        for (int j = 0; j < rhs.nc; ++j) {
            cout << " Row " << i << " Column " << j << ": ";
            in >> rhs.mat[i][j];
        }
    return in;
}

void Matrix::Initialize() {
    assert(nr != 0 && nc != 0);
    mat = new float*[nr];
    for (int i = 0; i < nr; ++i) {
        mat[i] = new float[nc];
        for (int j = 0; j < nc; ++j) {
            mat[i][j] = 0;
        }
    }

}

void Matrix::Destroy() {

    if (nr == 0 || nc == 0)
        return;

    for (int i = 0; i < nr; ++i) {
        delete[] mat[i];
    }
    delete[] mat;

}



