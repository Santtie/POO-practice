
#include "LinearRegression.h"
#include <stdexcept>
#include <cassert>

// --- Constructor ---
LinearRegression::LinearRegression() : bias(0.0) {}

// --- Matrix transpose ---
std::vector<std::vector<double>> LinearRegression::transpose(const std::vector<std::vector<double>>& A) {
    size_t rows = A.size(), cols = A[0].size();
    std::vector<std::vector<double>> T(cols, std::vector<double>(rows, 0.0));
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            T[j][i] = A[i][j];
    return T;
}

// --- Matrix multiplication ---
std::vector<std::vector<double>> LinearRegression::multiply(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B) {
    size_t rowsA = A.size(), colsA = A[0].size(), colsB = B[0].size();
    std::vector<std::vector<double>> result(rowsA, std::vector<double>(colsB, 0.0));
    for (size_t i = 0; i < rowsA; ++i)
        for (size_t j = 0; j < colsB; ++j)
            for (size_t k = 0; k < colsA; ++k)
                result[i][j] += A[i][k] * B[k][j];
    return result;
}

// --- Matrix * vector multiplication ---
std::vector<std::vector<double>> LinearRegression::multiplyByVector(const std::vector<std::vector<double>>& A, const std::vector<double>& v) {
    size_t rows = A.size(), cols = A[0].size();
    assert(cols == v.size());
    std::vector<std::vector<double>> result(rows, std::vector<double>(1, 0.0));
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            result[i][0] += A[i][j] * v[j];
    return result;
}

// --- Matrix inversion using Gaussian elimination ---
std::vector<std::vector<double>> LinearRegression::inverse(const std::vector<std::vector<double>>& A) {
    int n = A.size();
    std::vector<std::vector<double>> aug(n, std::vector<double>(2 * n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            aug[i][j] = A[i][j];
        aug[i][n + i] = 1.0;
    }

    for (int i = 0; i < n; ++i) {
        double diag = aug[i][i];
        if (fabs(diag) < 1e-12) throw std::runtime_error("Matrix not invertible");
        for (int j = 0; j < 2 * n; ++j)
            aug[i][j] /= diag;
        for (int k = 0; k < n; ++k) {
            if (k == i) continue;
            double factor = aug[k][i];
            for (int j = 0; j < 2 * n; ++j)
                aug[k][j] -= factor * aug[i][j];
        }
    }

    std::vector<std::vector<double>> inv(n, std::vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            inv[i][j] = aug[i][j + n];

    return inv;
}

// --- Data scaling (0 to 1 normalization) ---
void LinearRegression::scaleData(std::vector<std::vector<double>>& X) {
    if (X.empty()) return;
    size_t features = X[0].size();
    for (size_t j = 0; j < features; ++j) {
        double minVal = X[0][j], maxVal = X[0][j];
        for (size_t i = 1; i < X.size(); ++i) {
            minVal = std::min(minVal, X[i][j]);
            maxVal = std::max(maxVal, X[i][j]);
        }
        double range = maxVal - minVal;
        if (range == 0) continue;
        for (size_t i = 0; i < X.size(); ++i)
            X[i][j] = (X[i][j] - minVal) / range;
    }
}

// --- Fit model using normal equation ---
void LinearRegression::fit(const std::vector<std::vector<double>>& X, const std::vector<double>& y) {
    if (X.empty() || y.empty()) throw std::invalid_argument("Empty data");
    size_t n_samples = X.size();
    size_t n_features = X[0].size();

    // Build X_aug with bias term
    std::vector<std::vector<double>> X_aug(n_samples, std::vector<double>(n_features + 1, 1.0));
    for (size_t i = 0; i < n_samples; ++i)
        for (size_t j = 0; j < n_features; ++j)
            X_aug[i][j + 1] = X[i][j];

    auto Xt = transpose(X_aug);
    auto XtX = multiply(Xt, X_aug);
    auto XtX_inv = inverse(XtX);
    auto XtY = multiplyByVector(Xt, y);
    auto W = multiply(XtX_inv, XtY);

    weights.clear();
    for (size_t i = 1; i < W.size(); ++i)
        weights.push_back(W[i][0]);
    bias = W[0][0];
}

// --- Predict ---
std::vector<double> LinearRegression::predict(const std::vector<std::vector<double>>& X) const {
    std::vector<double> preds(X.size(), 0.0);
    for (size_t i = 0; i < X.size(); ++i) {
        double val = bias;
        for (size_t j = 0; j < weights.size(); ++j)
            val += X[i][j] * weights[j];
        preds[i] = val;
    }
    return preds;
}

// --- R² score ---
double LinearRegression::score(const std::vector<std::vector<double>>& X, const std::vector<double>& y) const {
    auto y_pred = predict(X);
    double ss_res = 0.0, ss_tot = 0.0, mean_y = 0.0;
    for (double v : y) mean_y += v;
    mean_y /= y.size();
    for (size_t i = 0; i < y.size(); ++i) {
        ss_res += pow(y[i] - y_pred[i], 2);
        ss_tot += pow(y[i] - mean_y, 2);
    }
    return 1 - (ss_res / ss_tot);
}

// --- Getters ---
std::vector<double> LinearRegression::getWeights() const { return weights; }
double LinearRegression::getBias() const { return bias; }
