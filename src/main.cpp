#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "LinearRegression.h"

// ==========================================================
// Function to read a CSV file and split into X (features) and y (target)
// ==========================================================
std::pair<std::vector<std::vector<double>>, std::vector<double>> readCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<double>> X;
    std::vector<double> y;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return {X, y};
    }

    // Skip the header line (column names)
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        std::vector<double> row;

        while (std::getline(ss, value, ',')) {
            row.push_back(std::stod(value));
        }

        // Last column = dependent variable (y)
        y.push_back(row.back());
        row.pop_back();
        X.push_back(row);
    }

    return {X, y};
}

// ==========================================================
// Main program
// ==========================================================
int main() {
    std::cout << "=== Linear Regression with Real CSV Data ===\n";

    // ----------------------------------------------------------
    // SIMPLE LINEAR REGRESSION (Ice Cream Data)
    // ----------------------------------------------------------
    auto [X_simple, y_simple] = readCSV("data/Ice_cream_selling_data.csv");

    if (X_simple.empty()) {
        std::cerr << "Error reading Ice_cream_selling_data.csv\n";
        return 1;
    }

    LinearRegression model_simple;
    model_simple.scaleData(X_simple);
    model_simple.fit(X_simple, y_simple);

    std::cout << "\n[Simple Regression: Ice Cream Sales]\n";
    std::cout << "Weights: ";
    for (double w : model_simple.getWeights()) std::cout << w << " ";
    std::cout << "\nBias: " << model_simple.getBias();
    std::cout << "\nScore (R²): " << model_simple.score(X_simple, y_simple) << "\n";

    // ----------------------------------------------------------
    // MULTIPLE LINEAR REGRESSION (Student Exam Scores)
    // ----------------------------------------------------------
    auto [X_multi, y_multi] = readCSV("data/student_exam_scores.csv");

    if (X_multi.empty()) {
        std::cerr << "Error reading student_exam_scores.csv\n";
        return 1;
    }

    LinearRegression model_multi;
    model_multi.scaleData(X_multi);
    model_multi.fit(X_multi, y_multi);

    std::cout << "\n[Multiple Regression: Student Exam Scores]\n";
    std::cout << "Weights: ";
    for (double w : model_multi.getWeights()) std::cout << w << " ";
    std::cout << "\nBias: " << model_multi.getBias();
    std::cout << "\nScore (R²): " << model_multi.score(X_multi, y_multi) << "\n";

    std::cout << "\n=== End of program ===\n";
    return 0;
}
