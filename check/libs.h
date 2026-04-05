/*
   This file consists of all the macros for the file paths essential for the libcheck.h file, add new file paths
   if you add any new files
*/

#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <direct.h>
#include <errno.h>
#include <string.h>

#include "../scikit/sk_imports.h"
#include "../structure/cells.h"
#include "../structure/PyList.h"
#include "../structure/utils.h"

// ../App files
#define app_c "../App/app.c"
#define app_dll "../App/app.dll"
#define dll_h "../App/dll.h"
#define main_so "../App/main.so"
#define MLAuto_exe "../App/MLAuto.exe"
#define MLAuto_c "../App/MLAuto.c"
#define MLAuto_py "../App/MLAuto.py"

// ../check files
#define libs_h "../check/libs.h"

// ../py_torch files
#define torch_imports_h "../py_torch/torch_imports.h"
#define models_pytorch_h "../py_torch/models_pytorch.h"

// ../scikit files
#define sk_imports_h "../scikit/sk_imports.h"
#define sk_models_h "../scikit/sk_models.h"

// ../structure files
#define cells_h "../structure/cells.h"
#define markdown_h "../structure/markdown.h"
#define PyList_h "../structure/PyList.h"
#define start_prog_h "../structure/start_prog.h"
#define utils_h "../structure/utils.h"
