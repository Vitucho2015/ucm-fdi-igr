#include "matrix.h"

inline
Matrix::Matrix(unsigned rows, unsigned cols)
  : rows_ (rows)
  , cols_ (cols)
  //data_ <--initialized below (after the 'if/throw' statement)
{
  data_ = new double[rows * cols];
}

inline
Matrix::~Matrix()
{
  delete[] data_;
}

inline
double& Matrix::operator() (unsigned row, unsigned col)
{
  return data_[cols_*row + col];
}

inline
double Matrix::operator() (unsigned row, unsigned col) const
{
  return data_[cols_*row + col];
}