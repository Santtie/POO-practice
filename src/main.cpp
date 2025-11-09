#include <iostream>
#include <vector>
#include "LinearRegression.h"

int main() {
    std::cout << "=== Multiple Linear Regression (C++) ===\n";

    // Example training data (2 features)
    std::vector<std::vector<double>> X_train = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };
    std::vector<double> y_train = {4, 6, 8, 10};

    LinearRegression model;
    model.scaleData(X_train);
    model.fit(X_train, y_train);

    std::cout << "Weights: ";
    for (double w : model.getWeights()) std::cout << w << " ";
    std::cout << "\nBias: " << model.getBias() << "\n";

    std::vector<std::vector<double>> X_test = {
        {5, 6},
        {6, 7}
    };
    model.scaleData(X_test);
    std::vector<double> preds = model.predict(X_test);

    std::cout << "Predictions: ";
    for (double p : preds) std::cout << p << " ";
    std::cout << "\nScore: " << model.score(X_train, y_train) << "\n";

    return 0;
}
