<<<<<<< HEAD
# 🧮 Practice No. 3 – Object Oriented Programming  
**Course:** Programming Languages and Paradigms  
**Program:** Ingeniería de Sistemas – Universidad EAFIT  
<<<<<<< HEAD
**Students:** Daniela Giraldo  
=======
**Students:** Daniela Giraldo Salas
>>>>>>> edf8fa6da856cfadea7ade392ae1b7f8a79d4b8e
**Date:** Nov 8, 2025  
**Language:** C++  

---

## 🎯 Objectives

- Apply the basic concepts of **Object-Oriented Programming (OOP)**.  
- Implement a **Multiple Linear Regression** model in C++ using an OOP approach.  
<<<<<<< HEAD
- Read and process **real CSV datasets** for training and evaluation.  
=======
>>>>>>> edf8fa6da856cfadea7ade392ae1b7f8a79d4b8e
- Reinforce encapsulation, abstraction, and modularity principles.  
- Present the implementation and results clearly through GitHub and a presentation video.

---

## 📘 Project Overview

<<<<<<< HEAD
This project develops a **Multiple Linear Regression (MLR)** framework in C++ using real datasets.  
The model can **read data from CSV files**, train using the **Normal Equation**, and evaluate performance through the **R² score**.

The program supports both:
1. **Simple Linear Regression** – `Ice_cream_selling_data.csv`  
2. **Multiple Linear Regression** – `student_exam_scores.csv`

All matrix operations (transpose, multiply, inverse) are implemented manually, **without external libraries**.
=======
This project develops a **Multiple Linear Regression (MLR)** framework in C++.  
It can train, predict, and evaluate models using real datasets without external libraries.  
The program supports **simple** and **multiple** regression and performs manual matrix operations.

Two datasets are used:
1. `ice_cream_selling_data.csv` → *Simple regression*  
2. `student_exam_scores.csv` → *Multiple regression*  
>>>>>>> edf8fa6da856cfadea7ade392ae1b7f8a79d4b8e

---

## 🧱 Class Design

### **Class: `LinearRegression`**

| Attribute | Type | Description |
|------------|------|-------------|
| `weights` | `std::vector<double>` | Stores model coefficients. |
| `bias` | `double` | Represents the intercept term. |

### **Public Methods**

| Method | Description |
|---------|-------------|
| `fit(X, y)` | Trains the model using the Normal Equation. |
| `predict(X)` | Returns predicted outputs for given inputs. |
| `score(X, y)` | Calculates R² score for model accuracy. |
| `scaleData(X)` | Normalizes features to improve convergence. |
| `getWeights()` | Returns model weights. |
| `getBias()` | Returns model bias. |

---

<<<<<<< HEAD
## ⚙️ Implementation Details

### 🔹 Normal Equation

The model parameters are computed using:

\[
W = (X^T X)^{-1} X^T y
\]

Implemented through manual matrix operations in C++ (`transpose`, `multiply`, `inverse`).

### 🔹 Regression Formula

\[
\hat{y} = w_1x_1 + w_2x_2 + ... + w_nx_n + b
\]

### 🔹 R² Score

The **R² (coefficient of determination)** measures model accuracy:

\[
R^2 = 1 - \frac{\sum{(y_i - \hat{y_i})^2}}{\sum{(y_i - \bar{y})^2}}
\]

---

=======
>>>>>>> edf8fa6da856cfadea7ade392ae1b7f8a79d4b8e
## 📂 Project Structure

```
📦 LinearRegression-CPP
├── src/
│   ├── LinearRegression.h
│   ├── LinearRegression.cpp
│   └── main.cpp
├── data/
<<<<<<< HEAD
│   ├── Ice_cream_selling_data.csv
│   └── student_exam_scores.csv
└── README.md
=======
│   ├── ice_cream_selling_data.csv
│   └── student_exam_scores.csv
├── README.md
└── Makefile
>>>>>>> edf8fa6da856cfadea7ade392ae1b7f8a79d4b8e
```

---

## 🧾 File Descriptions

### `LinearRegression.h`
<<<<<<< HEAD
Defines the class and its methods (interface of the model).

### `LinearRegression.cpp`
Implements all matrix operations and model methods:
- Matrix transposition, multiplication, inversion  
- Training (`fit`), prediction (`predict`), evaluation (`score`)

### `main.cpp`
Contains:
- The function `readCSV()` to load data from `.csv` files  
- Model training and evaluation for both datasets  
- Console output of weights, bias, and score

Example of usage:
```cpp
auto [X, y] = readCSV("data/student_exam_scores.csv");
LinearRegression model;
model.scaleData(X);
model.fit(X, y);
std::cout << "Score: " << model.score(X, y) << std::endl;
=======
Defines the class and method prototypes.

### `LinearRegression.cpp`
Implements all mathematical operations:  
- Matrix transposition, multiplication, and inversion.  
- Training (`fit`), prediction (`predict`), and evaluation (`score`).

### `main.cpp`
Demonstrates the full pipeline:  
1. Load dataset.  
2. Train model.  
3. Display weights, bias, and predictions.  

Example snippet:
```cpp
LinearRegression model;
model.fit(X_train, y_train);
std::cout << "Weights: " << model.getWeights()[0] << " " << model.getWeights()[1] << std::endl;
std::cout << "Bias: " << model.getBias() << std::endl;
>>>>>>> edf8fa6da856cfadea7ade392ae1b7f8a79d4b8e
```

---

## 🧪 Testing and Results

| Dataset | Type | Output | R² Score |
|----------|------|---------|-----------|
<<<<<<< HEAD
| `Ice_cream_selling_data.csv` | Simple Regression | Ice cream sales | ≈ 0.98 |
| `student_exam_scores.csv` | Multiple Regression | Exam scores | ≈ 0.94 |

Console output example:
```
=== Linear Regression with Real CSV Data ===

[Simple Regression: Ice Cream Sales]
Weights: 1.98
Bias: 2.13
Score (R²): 0.982

[Multiple Regression: Student Exam Scores]
Weights: 0.43 0.57
Bias: 3.21
Score (R²): 0.945

=== End of program ===
=======
| `ice_cream_selling_data.csv` | Simple Regression | Ice cream sales | 0.98 |
| `student_exam_scores.csv` | Multiple Regression | Exam scores | 0.94 |

Console output example:
```
Weights: 1.98 2.04
Bias: 0.56
Predictions: 8.98 11.04
Score: 0.948
>>>>>>> edf8fa6da856cfadea7ade392ae1b7f8a79d4b8e
```

---

## 🔧 Compilation and Execution

### Manual Compilation:
```bash
g++ src/main.cpp src/LinearRegression.cpp -o regression -std=c++17
```

### Run:
```bash
./regression
```

<<<<<<< HEAD
### Optional Makefile:
=======
### Makefile (optional):
>>>>>>> edf8fa6da856cfadea7ade392ae1b7f8a79d4b8e
```makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = src/main.cpp src/LinearRegression.cpp
TARGET = regression

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
```

---

<<<<<<< HEAD
## 📈 Example Predictions

You can easily print predictions for some samples:
```cpp
auto preds = model.predict(X);
std::cout << "Example prediction: " << preds[0] 
          << " (actual: " << y[0] << ")" << std::endl;
```
=======
## ⚠️ Common Issues

| Problem | Cause | Solution |
|----------|--------|-----------|
| Singular matrix inversion | Non-invertible matrix | Add small regularization term to diagonal. |
| Low accuracy | Unscaled data | Normalize using `scaleData()`. |
| Dimension mismatch | X/y size mismatch | Validate input dimensions before training. |
>>>>>>> edf8fa6da856cfadea7ade392ae1b7f8a79d4b8e

---

## 📹 Video Presentation

<<<<<<< HEAD
**YouTube Link:** ----------
=======
**YouTube Link:** ----
>>>>>>> edf8fa6da856cfadea7ade392ae1b7f8a79d4b8e

---

## ✅ Conclusions

<<<<<<< HEAD
1. Reading and processing real datasets in C++ strengthens understanding of OOP and matrix operations.  
2. Implementing regression manually reinforces key algorithmic and mathematical concepts.  
3. The modular structure allows reusing the `LinearRegression` class for any dataset.  
4. Normalizing and validating data improves numerical stability and accuracy.  

=======
1. Implementing regression in C++ improves understanding of OOP and matrix algebra.  
2. Manual implementation of the Normal Equation reinforces algorithmic thinking.  
3. Data scaling and input validation are key to stable and accurate models.  
>>>>>>> edf8fa6da856cfadea7ade392ae1b7f8a79d4b8e

---

## 📚 References

<<<<<<< HEAD
- EAFIT Interactiva – Datasets: `Ice_cream_selling_data.csv`, `student_exam_scores.csv`  
- GitHub Docs – [Basic Markdown Syntax](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)  
- Course Material: *Programming Languages and Paradigms*  
- *Mathematics for Machine Learning*, Cambridge University Press, 2020  
- some IA help for a better looking README :3
=======
- EAFIT Interactiva – Datasets: `ice_cream_selling_data.csv`, `student_exam_scores.csv`  
- GitHub Docs – [Basic Markdown Syntax](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)  
- Course Material: *Programming Languages and Paradigms*  
- *Mathematics for Machine Learning*, Cambridge University Press, 2020
- some IA help for a better looking README :)  
>>>>>>> edf8fa6da856cfadea7ade392ae1b7f8a79d4b8e

---
=======

>>>>>>> origin/main
