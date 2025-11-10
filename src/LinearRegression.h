#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include <vector>
#include <iostream>
#include <cmath>

class LinearRegression {
private:
    std::vector<double> weights;
    double bias;

    // --- Helper matrix functions ---
    std::vector<std::vector<double>> transpose(const std::vector<std::vector<double>>& A);
    std::vector<std::vector<double>> multiply(const std::vector<std::vector<double>>& A, const std::vector<std::vector<double>>& B);
    std::vector<std::vector<double>> inverse(const std::vector<std::vector<double>>& A);
    std::vector<std::vector<double>> multiplyByVector(const std::vector<std::vector<double>>& A, const std::vector<double>& v);

public:
    LinearRegression();
    void fit(const std::vector<std::vector<double>>& X, const std::vector<double>& y);
    std::vector<double> predict(const std::vector<std::vector<double>>& X) const;
    double score(const std::vector<std::vector<double>>& X, const std::vector<double>& y) const;
    void scaleData(std::vector<std::vector<double>>& X);
    std::vector<double> getWeights() const;
    double getBias() const;
};

#endif
