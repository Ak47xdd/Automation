# Machine Learning Pipeline Automator (MLAuto)

![Version](https://img.shields.io/badge/version-1.3.3_beta-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Language](https://img.shields.io/badge/language-C/Python-orange)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-lightgrey)

A powerful C-based command-line tool that automates the creation of complete Python machine learning pipelines. MLAuto generates production-ready ML code with interactive prompts, supporting both scikit-learn and PyTorch frameworks.

**Copyright (c) Akshay Babu 2026, All rights reserved.**

---

## Table of Contents

1. [What MLAuto Does](#what-mlauto-does)
2. [Features](#features)
3. [Project Structure](#project-structure)
4. [Installation](#installation)
   - [Prerequisites](#prerequisites)
   - [Building from Source](#building-from-source)
   - [Pre-built Executable](#pre-built-executable)
5. [Usage](#usage)
   - [Command-Line Flags](#command-line-flags)
   - [Interactive Mode](#interactive-mode)
   - [Generated Output](#generated-output)
6. [Supported ML Models](#supported-ml-models)
   - [Regression Models](#regression-models)
   - [Classification Models](#classification-models)
7. [Output Format](#output-format)
8. [Converting to Jupyter Notebook](#converting-to-jupyter-notebook)
9. [Contributing](#contributing)
   - [How to Contribute](#how-to-contribute)
   - [Code Style](#code-style)
   - [Adding New Models](#adding-new-models)
   - [Reporting Issues](#reporting-issues)
10. [License](#license)
11. [Acknowledgments](#acknowledgments)

---

## What MLAuto Does

MLAuto is a **C-based code generator** that creates complete Python machine learning pipelines through an interactive CLI. Instead of manually writing ML code, users answer prompts about their data and model preferences, and MLAuto generates a fully functional Python script.

### Workflow

```
┌─────────────┐     ┌──────────────┐     ┌─────────────────┐
│  User Input │ ──► │  MLAuto CLI  │ ──► │  Python Script  │
│  (CLI)       │     │  (Pure C)    │     │  (.py file)     │
└─────────────┘     └──────────────┘     └─────────────────┘
                                                  │
                                                  ▼
                                         ┌─────────────────┐
                                         │ ML Pipeline     │
                                         │ (Model Training │
                                         │  & Evaluation)  │
                                         └─────────────────┘
```

### Example Use Cases

- **Quick Prototyping:** Rapidly generate ML pipeline templates
- **Learning Tool:** Understand ML workflow structure
- **Production Starters:** Generate boilerplate code for projects
- **Automation:** Integrate into ML workflow pipelines

---

## Features

### Core Features

- **Interactive CLI** - User-friendly prompts for pipeline configuration
- **Multiple ML Frameworks** - Support for scikit-learn and PyTorch
- **Comprehensive EDA** - Automatic generation of visualizations
- **Feature Scaling** - StandardScaler integration
- **Log Transformation** - Apply log transformations to features
- **Model Evaluation** - MSE, R² Score, Accuracy metrics

### Supported Operations

- 📊 **Data Loading** - CSV file loading with pandas
- 📈 **Visualizations** - Histograms, correlation matrices, heatmaps, pairplots
- 🔧 **Preprocessing** - Column dropping, feature scaling, log transforms
- 🤖 **Model Training** - Multiple regression and classification algorithms
- 📉 **Evaluation** - Performance metrics and model assessment

---

## Project Structure

```
Automation/
├── App/                      # Main application directory
│   ├── app.c                 # Main CLI application source
│   ├── app.dll               # Windows DLL library
│   ├── app.exe               # Windows executable
│   ├── dll.h                 # DLL header definitions
│   ├── main.so               # Linux shared object
│   ├── MLAuto.c              # Alternative entry point
│   ├── MLAuto.exe            # Alternative executable
│   └── MLAuto.py             # Ctypes python entry
├── check/                    # Debug and validation modules
│   ├── libcheck.h            # File existence checker
│   └── libs.h                # Library path definitions
├── debug/                    # Debug build and testing
│   └── main.c                # Debug entry point
├── py_torch/                 # PyTorch integration
│   ├── models_pytorch.h      # PyTorch model definitions
│   └── torch_imports.h       # PyTorch import statements
├── scikit/                   # Scikit-learn integration
│   ├── sk_imports.h          # Scikit-learn imports
│   └── sk_models.h           # Model implementations
├── structure/                # Core utility modules
│   ├── cells.h               # Jupyter cell generation
│   ├── markdown.h            # Markdown formatting
│   ├── PyList.h              # Python list generation
│   ├── start_prog.h          # Program title screens
│   └── utils.h               # Utility functions
└── README.md                 # This file
```

---

## Installation

### Prerequisites

#### Windows

- **C Compiler:** MinGW-w64 or Visual Studio Build Tools
- **Python 3.8+:** For running generated scripts
- **Required Python Packages:**
  ```bash
  pip install pandas numpy matplotlib seaborn scikit-learn xgboost
  ```

#### Linux/macOS

- **C Compiler:** GCC or Clang
- **Python 3.8+:** For running generated scripts
- **Required Python Packages:**
  ```bash
  pip install pandas numpy matplotlib seaborn scikit-learn xgboost
  ```

### Building from Source

#### Windows (MinGW)

```bash
# Navigate to App directory
cd App

# Compile the executable
gcc -o MLAuto.exe MLAuto.c -I../structure -I../check -I../scikit -I../py_torch

# Run the application
./MLAuto.exe
```

#### Windows (Visual Studio)

```cmd
cd App
cl /I..\structure /I..\check /I..\scikit /I..\py_torch MLAuto.c /Fe:MLAuto.exe
MLAuto.exe
```

#### Linux/macOS

```bash
# Navigate to App directory
cd App

# Compile
gcc -o MLAuto MLAuto.c -I../structure -I../check -I../scikit -I../py_torch

# Make executable
chmod +x MLAuto

# Run
./MLAuto
```

### Pre-built Executable

If you have the pre-built executable:

```bash
# Windows
App\MLAuto.exe

# Or with flags
App\MLAuto.exe -w (write flag, use -h for help or to know of other flags!)
```

---

## Usage

### Command-Line Flags

| Flag | Description                                     |
| ---- | ----------------------------------------------- |
| `-h` | Show help information and available options     |
| `-v` | Display version information - current version   |
| `-d` | Run debug mode - verify all library files exist |
| `-w` | Write mode - generate ML pipeline (interactive) |
| `-c` | Console mode - Console scripting interpreter    |

### Interactive Mode

Run the application in write mode to start the interactive pipeline generator:

```bash
# Windows
App\MLAuto.exe -w

# Linux/macOS
./App/MLAuto -w
```

#### Interactive Session Example

```
>> Welcome to MLAuto CLI!
>> Do you want PyTorch? (yes/no) : no
>> What kind of model are you gonna use :
>> Regression (1)
>> Classification (2)
>> Choose : 1
>> What regression model are you planning to use :
>> Linear Regresssion (1)
>> Logistic Regression (2)
>> Decision Tree regressor (3)
...
>> Choose : 1
>> Enter the directory of the CSV file :
-- C:\data\my_dataset.csv
>> Enter the no of columns to drop (type 0 if none):
-- 0
...
```

### Generated Output

The generated Python script includes:

1. **Library Imports** - All required dependencies
2. **Data Loading** - CSV reading with pandas
3. **EDA Section** - Data info, statistics, visualizations
4. **Preprocessing** - Column handling, transformations
5. **Model Building** - Train/test split, model training
6. **Evaluation** - Performance metrics

---

## Supported ML Models

### Regression Models

| Model                     | Option | Description                   |
| ------------------------- | ------ | ----------------------------- |
| Linear Regression         | 1      | Basic linear regression       |
| Logistic Regression       | 2      | Classification via regression |
| Decision Tree Regressor   | 3      | Tree-based regression         |
| XGBoost Regressor         | 4      | Gradient boosting             |
| Ridge Regressor           | 5      | L2 regularized regression     |
| Random Forest Regressor   | 6      | Ensemble tree regression      |
| K-Nearest Regressor       | 7      | KNN regression                |
| Lasso Regression          | 8      | L1 regularized regression     |
| Elastic Net               | 9      | Combined L1/L2 regression     |
| Support Vector Regression | 10     | SVR regression                |

### Classification Models

| Model                    | Option | Description                      |
| ------------------------ | ------ | -------------------------------- |
| Support Vector Machines  | 1      | SVM classification               |
| Decision Tree Classifier | 2      | Tree-based classification        |
| Random Forest Classifier | 3      | Ensemble tree classification     |
| K-Nearest Neighbors      | 4      | KNN classification               |
| XGBoost Classifier       | 5      | Gradient boosting classification |
| Neural Networks (MLP)    | 6      | Multi-layer perceptron           |

---

## Output Format

The generated `python_automation/model.py` file contains:

```python
# %%%[markdown]
# ## **Importing Libraries/Frameworks**
# %%%
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
...

# %%%[markdown]
# ## **Reading CSV file**
# %%%
df = pd.read_csv(r"path/to/data.csv")
...

# %%%[markdown]
# ## **Plotting And EDA**
# %%%
# Visualizations here
...

# %%%[markdown]
# ## **Feature Scaling**
# %%%
scaler = StandardScaler()
...

# %%%[markdown]
# ## **Building Model**
# %%%
X_train, X_test, y_train, y_test = train_test_split(...)
model = LinearRegression()
...

# %%%[markdown]
# ## **Evaluating model**
# %%%
train_mse = mean_squared_error(...)
```

---

## Converting to Jupyter Notebook

The generated file is a `.py` script. To convert it to a Jupyter Notebook:

### Method 1: VS Code (Recommended)

1. Open the generated `python_automation/model.py` file
2. Install the **Jupyter extension** for VS Code
3. Press `Ctrl + Shift + P` to open Command Palette
4. Type: `Jupyter: Export Current Python File as Jupyter Notebook`
5. Save the resulting `.ipynb` file

### Method 2: Using nbformat (Python)

```python
import nbformat
from nbformat.v4 import new_code_cell, new_markdown_cell

# Read the .py file and convert to notebook
# (Requires custom parsing logic based on # %%% markers)
```

---

## Contributing

Contributions are welcome! This project is open-source under the MIT License.

### How to Contribute

1. **Fork the Repository**
   Click the "Fork" button on the GitHub repository page.

2. **Clone Your Fork**

   ```bash
   git clone https://github.com/YOUR_USERNAME/Automation.git
   cd Automation
   ```

3. **Create a Feature Branch**

   ```bash
   git checkout -b feature/your-feature-name
   ```

4. **Make Your Changes**
   Edit the relevant source files:
   - Add new models in `scikit/sk_models.h`
   - Add new imports in `scikit/sk_imports.h`
   - Add new utilities in `structure/`
   - Update documentation in `README.md`

5. **Test Your Changes**

   ```bash
   cd App
   gcc -o MLAuto.exe MLAuto.c -I../structure -I../check -I../scikit -I../py_torch
   ./MLAuto.exe -d  # Run debug mode to verify files
   ```

6. **Commit and Push**

   ```bash
   git add .
   git commit -m "Add: Description of your changes"
   git push origin feature/your-feature-name
   ```

7. **Create a Pull Request**
   Open a pull request on the original repository.

### Code Style

- **C Code:** Follow K&R style with 4-space indentation
- **Naming Conventions:**
  - Functions: `function_name()` or `m_function_name()` for markdown
  - Variables: `lowercase_with_underscores`
  - Constants: `UPPERCASE_WITH_UNDERSCORES`
- **Comments:** Use `//` for single-line, `/* */` for multi-line
- **Header Guards:** Use `#pragma once`

### Adding New Models

To add a new scikit-learn model:

1. **Add Import Statement** in `scikit/sk_imports.h`:

   ```c
   const char new_model[50] = "from sklearn.module import NewModel";
   ```

2. **Add Model Function** in `scikit/sk_models.h`:

   ```c
   extern void c_new_model_class()
   {
       fprintf(fp, CELL);
       fprintf(fp, "\n");
       fprintf(fp, "model = NewModel()\n");
       fprintf(fp, "model.fit(X_train, y_train)\n");
       fprintf(fp, "y_pred = model.predict(X_test)\n");
   }
   ```

3. **Add Menu Option** in `structure/utils.h`:
   - Add the case in the appropriate switch statement
   - Update the help text in `App/app.c`

4. **Test the Addition**
   ```bash
   cd App
   gcc -o MLAuto.exe MLAuto.c -I../structure -I../check -I../scikit -I../py_torch
   ./MLAuto.exe -w  # Select new model option
   ```

### Reporting Issues

If you find a bug or have a suggestion:

1. Check existing issues to avoid duplicates
2. Create a new issue with:
   - Clear title
   - Detailed description
   - Steps to reproduce (for bugs)
   - Expected vs actual behavior
   - Your environment (OS, compiler version)

---

## License

This project is licensed under the **MIT License**.

```
MIT License

Copyright (c) 2026 Akshay Babu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

---

## Acknowledgments

- **Author:** Akshay Babu
- **Built with:** Pure C (no external C dependencies)
- **Generated Code:** Python with scikit-learn, PyTorch, pandas, matplotlib, seaborn

---

## Version History

| Version      | Date | Changes                           |
| ------------ | ---- | --------------------------------- |
| 1.3.3 (Beta) | 2026 | Current development version       |
| 1.3.2 (Beta) | 2026 | Stable release with core features |
| 1.3.1 (Beta) | 2025 | Added PyTorch support             |
| 1.3.0 (Beta) | 2025 | Initial release (GitHub release)  |

---

Current Codebase length : 2100+ lines of code (2108 lines total)
_For questions or support, please open an issue on the project repository._
