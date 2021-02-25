// Copyright 2021 DimaZzZz101

#include "matrix.hpp"

#include <algorithm>

void Construct(Matrix& out, size_t n, size_t m) {
  out.m_ = m;
  out.n_ = n;

  out.data_ = new int*[m];

  for (size_t i = 0; i < m; ++i) {
    out.data_[i] = new int[n]();
  }
}

void Destruct(Matrix& in) {
  for (size_t i = 0; i < in.m_; ++i) {
    delete[] in.data_[i];
  }

  delete[] in.data_;

  in.data_ = nullptr;
}

Matrix Copy(const Matrix& matrix) {
  Matrix copied_matrix;

  Construct(copied_matrix, matrix.n_, matrix.m_);

  for (size_t i = 0; i < copied_matrix.m_; ++i) {
    std::copy(matrix.data_[i], matrix.data_[i] + copied_matrix.n_,
              copied_matrix.data_[i]);
  }

  return copied_matrix;
}

Matrix Add(const Matrix& a, const Matrix& b) {
  Matrix new_matrix;

  if ((a.m_ == b.m_) && (a.n_ == b.n_)) {
    Construct(new_matrix, a.n_, a.m_);
    for (size_t i = 0; i < a.m_; ++i) {
      for (size_t j = 0; j < a.n_; ++j) {
        new_matrix.data_[i][j] = a.data_[i][j] + b.data_[i][j];
      }
    }
  }

  return new_matrix;
}

Matrix Sub(const Matrix& a, const Matrix& b) {
  Matrix new_matrix;

  if ((a.m_ == b.m_) && (a.n_ == b.n_)) {
    Construct(new_matrix, a.n_, a.m_);
    for (size_t i = 0; i < a.m_; ++i) {
      for (size_t j = 0; j < a.n_; ++j) {
        new_matrix.data_[i][j] = a.data_[i][j] - b.data_[i][j];
      }
    }
  }

  return new_matrix;
}

Matrix Mult(const Matrix& a, const Matrix& b) {
  Matrix new_matrix;

  if (a.n_ == b.m_) {
    Construct(new_matrix, a.n_, a.m_);
    for (size_t i = 0; i < a.m_; ++i) {
      for (size_t j = 0; j < b.n_; ++j) {
        for (size_t k = 0; k < a.n_; ++k) {
          new_matrix.data_[i][j] += a.data_[i][k] * b.data_[k][j];
        }
      }
    }
  }

  return new_matrix;
}

void Transposition(Matrix& matrix) {
  Matrix new_matrix = Copy(matrix);

  matrix.m_ = new_matrix.n_;
  matrix.n_ = new_matrix.m_;

  for (size_t i = 0; i < matrix.n_; ++i) {
    for (size_t j = 0; j < matrix.m_; ++j) {
      matrix.data_[i][j] = new_matrix.data_[j][i];
    }
  }

  Destruct(new_matrix);
}

bool operator==(const Matrix& a, const Matrix& b) {
  if ((a.m_ == b.m_) and (a.n_ == b.n_)) {
    for (size_t i = 0; i < a.m_; ++i) {
      for (size_t j = 0; j < a.n_; ++j) {
        if (a.data_[i][j] != b.data_[i][j]) {
          return false;
        }
      }
    }
    return true;

  } else
    return false;
}