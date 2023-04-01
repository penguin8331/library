#pragma once
#include "../../template/template.hpp"

template <class T>
struct Matrix {
    vector<vector<T>> val;
    size_t height, width;

    Matrix(int n = 1, int m = 1, T v = 0) : val(n, vector<T>(m, v)), height(n), width(m) {}
    void init(int n, int m, T v = 0) {
        val.assign(n, vector<T>(m, v));
        height = n;
        width = m;
    }
    void resize(int n, int m) {
        val.resize(n);
        for (int i = 0; i < n; ++i) val[i].resize(m);
        height = n;
        width = m;
    }
    vector<T> &operator[](int i) { return val[i]; }
    const vector<T> &operator[](int i) const { return val[i]; }
    Matrix &operator=(const Matrix &A) {
        val = A.val;
        return *this;
    }
    Matrix &operator+=(const Matrix &r) {
        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                (*this)[i][j] += r[i][j];
        return (*this);
    }
    Matrix &operator-=(const Matrix &r) {
        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                (*this)[i][j] -= r[i][j];
        return (*this);
    }
    Matrix &operator*=(const Matrix &r) {
        vector<vector<T>> res(height, vector<T>(r.width));
        for (int i = 0; i < height; ++i)
            for (int j = 0; j < r.width; ++j)
                for (int k = 0; k < width; ++k)
                    res[i][j] += (*this)[i][k] * r[k][j];
        val.swap(res);
        return (*this);
    }
    Matrix operator+(const Matrix &r) { return Matrix(*this) += r; }
    Matrix operator-(const Matrix &r) { return Matrix(*this) -= r; }
    Matrix operator*(const Matrix &r) { return Matrix(*this) *= r; }
    friend Matrix<T> pow(const Matrix<T> &A, long long n) {
        Matrix<T> R(A.height, A.height);
        Matrix<T> B = A;
        for (int i = 0; i < A.height; ++i) R[i][i] = 1;
        while (n > 0) {
            if (n & 1) R = R * B;
            B = B * B;
            n >>= 1;
        }
        return R;
    }
    friend T det(Matrix<T> A) {
        T ret = 1;
        for (int i = 0; i < A.width; i++) {
            int idx = -1;
            for (int j = i; j < A.width; j++) {
                if (A[j][i] != 0) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1) return T(0);
            if (i != idx) {
                ret *= T(-1);
                swap(A[i], A[idx]);
            }
            ret *= A[i][i];
            T tmp = A[i][i];
            for (int j = 0; j < A.width; j++) A[i][j] /= tmp;
            for (int j = i + 1; j < A.width; j++) {
                T now = A[j][i];
                for (int k = 0; k < A.width; k++) A[j][k] -= A[i][k] * now;
            }
        }
        return ret;
    }
};
