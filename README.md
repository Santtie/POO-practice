# 🧮 Practice No. 3 – Object Oriented Programming  
**Course:** Programming Languages and Paradigms  
**Program:** Ingeniería de Sistemas – Universidad EAFIT  
**Students:** Laura Santamaria and Simon Dìaz
**Language:** C++  

---

## 🎯 Objectives

- Apply the basic concepts of **Object-Oriented Programming (OOP)**.  
- Implement a **Multiple Linear Regression** model in C++ using an OOP approach.  
- Read and process **real CSV datasets** for training and evaluation.  
- Reinforce encapsulation, abstraction, and modularity principles.  
- Present the implementation and results clearly through GitHub and a presentation video.

---

## 📘 Project Overview

This project develops a **Multiple Linear Regression (MLR)** framework in C++ using real datasets.  
The model can **read data from CSV files**, train using the **Normal Equation**, and evaluate performance through the **R² score**.

The program supports both:
1. **Simple Linear Regression** – `Ice_cream_selling_data.csv`  
2. **Multiple Linear Regression** – `student_exam_scores.csv`

All matrix operations (transpose, multiply, inverse) are implemented manually, **without external libraries**.

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

## 📂 Project Structure

```
📦 LinearRegression-CPP
├── src/
│   ├── LinearRegression.h
│   ├── LinearRegression.cpp
│   └── main.cpp
├── data/
│   ├── Ice_cream_selling_data.csv
│   └── student_exam_scores.csv
└── README.md
```

---

## 🧾 File Descriptions

### `LinearRegression.h`
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
```

---

## 🧪 Testing and Results

| Dataset | Type | Output | R² Score |
|----------|------|---------|-----------|
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

### Optional Makefile:
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

## 📈 Example Predictions

You can easily print predictions for some samples:
```cpp
auto preds = model.predict(X);
std::cout << "Example prediction: " << preds[0] 
          << " (actual: " << y[0] << ")" << std::endl;
```

---

## 📹 Video Presentation

**YouTube Link:** ----------

---

## ✅ Conclusions

1. Reading and processing real datasets in C++ strengthens understanding of OOP and matrix operations.  
2. Implementing regression manually reinforces key algorithmic and mathematical concepts.  
3. The modular structure allows reusing the `LinearRegression` class for any dataset.  
4. Normalizing and validating data improves numerical stability and accuracy.  


---

## 📚 References

- EAFIT Interactiva – Datasets: `Ice_cream_selling_data.csv`, `student_exam_scores.csv`  
- GitHub Docs – [Basic Markdown Syntax](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)  
- Course Material: *Programming Languages and Paradigms*  
- *Mathematics for Machine Learning*, Cambridge University Press, 2020  
- some IA help for a better looking README :3

---
