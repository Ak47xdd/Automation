/*
    This file contains all the necessary imports and functions for the program to run
*/

#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <direct.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#define SIZE 250
#define BUFF 100
#define VER "1.3.5 (beta)"
#define VER_STRT "1.3.5"

FILE *fp = NULL;

int ans_reg;
int ans_class;
char model[5];
char ans_pytorch[4];

#include "markdown.h"
#include "../scikit/sk_imports.h"
#include "../scikit/sk_models.h"
#include "../py_torch/torch_imports.h"
#include "start_prog.h"

extern void str_lower(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}

#include "cells.h"
#include "PyList.h"

char dir_name[25] = "python_automation";
char relative_path[50] = "python_automation/model.py";

extern void dir_check();
extern void base_imports();
extern void ask_torch();
extern void ask_sns();
extern void ask_model();
extern void scaler();

extern void dir_check()
{
    int result = _mkdir(dir_name);

    if (result == 0)
    {
        printf("\n>> Directory '%s' created successfully.\n", dir_name);
        printf("\n");
    }
    else
    {
        if (errno == EEXIST)
        {
            printf("\n>> Directory '%s' already exists.\n", dir_name);
            printf("\n");
        }
        else
        {
            perror("\n>> Error creating directory");
            printf("\n");
        }
    }

    fp = fopen(relative_path, "w");
}

extern void base_imports()
{
    fprintf(fp, pd);
    fprintf(fp, "\n");
    fprintf(fp, np);
    fprintf(fp, "\n");
    fprintf(fp, plt);
    fprintf(fp, "\n");
    fprintf(fp, sns);
    fprintf(fp, "\n");
    fprintf(fp, tts);
    fprintf(fp, "\n");
    fprintf(fp, as);
    fprintf(fp, "\n");
    fprintf(fp, sc);
    fprintf(fp, "\n");

    if (strcmp(ans_pytorch, "yes") == 0)
    {
        fprintf(fp, torch);
        fprintf(fp, "\n");
        fprintf(fp, torch_nn);
        fprintf(fp, "\n");
    }
}

extern void ask_torch()
{
    printf("\n>> Do you want PyTorch? (yes/no) : \n-- ");
    scanf("%s", ans_pytorch);

    str_lower(ans_pytorch);

    if (strcmp(ans_pytorch, "yes") == 0)
    {
        fprintf(fp, torch);
        fprintf(fp, "\n");
        fprintf(fp, torch_nn);
        fprintf(fp, "\n");
    }
    else if (strcmp(ans_pytorch, "no") == 0)
    {
        printf("\n>> PyTorch has not been imported!\n");
    }
    else if (strcmp(ans_pytorch, "exit") == 0)
    {
        printf("\n>> Program Terminated!\n");
        exit(1);
    }
    else
    {
        system("cls");
        start_prog();
        printf("\n>> Invalid, PyTorch not imported : select again\n");
        ask_torch();
    }
}

extern void ask_model()
{
    if (strcmp(ans_pytorch, "no") == 0)
    {
        printf("\n>> What kind of model are you gonna use : \n");
        printf(">> Regression (1)\n>> Classification (2)\n");
        printf(">> Choose : \n-- ");
        scanf("%s", &model);

        if (strcmp(model, "1") == 0)
        {
            printf("\n>> What regression model are you planning to use : \n");
            printf(">> Linear Regresssion (1)\n>> Logistic Regression (2)\n>> Decision Tree regressor (3)\n>> XGBoost regressor (4)\n>> Ridge regressor (5)\n>> Random Forest regressor (6)\n>> K nearest regressor (7)\n>> Lasso regression (8)\n>> Elastic Net regression (9)\n>> Support Vector Regression (10)\n");
            printf(">> Choose : \n-- ");
            scanf("%d", &ans_reg);

            switch (ans_reg)
            {
            case 1:
                fprintf(fp, sk_lin);
                fprintf(fp, "\n");
                fprintf(fp, mse_r2);
                fprintf(fp, "\n");
                break;

            case 2:
                fprintf(fp, sk_log);
                fprintf(fp, "\n");
                fprintf(fp, mse_r2);
                fprintf(fp, "\n");
                break;

            case 3:
                fprintf(fp, sk_dec_reg);
                fprintf(fp, "\n");
                fprintf(fp, mse_r2);
                fprintf(fp, "\n");
                break;

            case 4:
                fprintf(fp, xgboost);
                fprintf(fp, "\n");
                fprintf(fp, mse_r2);
                fprintf(fp, "\n");
                break;

            case 5:
                fprintf(fp, sk_lin_ridge);
                fprintf(fp, "\n");
                fprintf(fp, mse_r2);
                fprintf(fp, "\n");
                break;

            case 6:
                fprintf(fp, ran_for_reg);
                fprintf(fp, "\n");
                fprintf(fp, mse_r2);
                fprintf(fp, "\n");
                break;

            case 7:
                fprintf(fp, k_near_reg);
                fprintf(fp, "\n");
                fprintf(fp, mse_r2);
                fprintf(fp, "\n");
                break;

            case 8:
                fprintf(fp, lasso);
                fprintf(fp, "\n");
                fprintf(fp, mse_r2);
                fprintf(fp, "\n");
                break;

            case 9:
                fprintf(fp, elastic);
                fprintf(fp, "\n");
                fprintf(fp, mse_r2);
                fprintf(fp, "\n");
                break;

            case 10:
                fprintf(fp, svr);
                fprintf(fp, "\n");
                fprintf(fp, mse_r2);
                fprintf(fp, "\n");
                break;

            default:
                system("cls");
                start_prog();
                printf(">> Invalid, please enter again\n");
                ask_model();
            }
        }
        else if (strcmp(model, "2") == 0)
        {
            printf("\n>> What classification model are you planning to use : \n");
            printf(">> Support Vector Machines (1)\n>> Decision tree classifier (2)\n>> Random forest classifier (3)\n>> K nearest neighbors (4)\n>> XGBoost classifier (5)\n>> Neural networks MLP (6)\n>> Isolation Forest (7)\n");
            printf(">> Choose : \n-- ");
            scanf("%d", &ans_class);

            switch (ans_class)
            {
            case 1:
                fprintf(fp, svm);
                fprintf(fp, "\n");
                break;

            case 2:
                fprintf(fp, sk_dec_class);
                fprintf(fp, "\n");
                break;

            case 3:
                fprintf(fp, ran_for_class);
                fprintf(fp, "\n");
                break;

            case 4:
                fprintf(fp, k_near_class);
                fprintf(fp, "\n");
                break;

            case 5:
                fprintf(fp, xgboost);
                fprintf(fp, "\n");
                break;

            case 6:
                fprintf(fp, mlp);
                fprintf(fp, "\n");
                break;

            case 7:
                fprintf(fp, iso_forest);
                fprintf(fp, "\n");
                break;

            default:
                system("cls");
                start_prog();
                printf(">> Invalid, please enter again\n");
                ask_model();
            }
        }
        else if (strcmp(model, "exit") == 0)
        {
            printf("\n>> Program Terminated!\n");
            exit(1);
        }
        else
        {
            system("cls");
            start_prog();
            printf(">> Invalid input, please select again\n");
            ask_model();
        }
    }
}

extern void scaler()
{
    fprintf(fp, CELL);
    fprintf(fp, "\n");
    fprintf(fp, "scaled_X_train = \n");
    fprintf(fp, "scaled_y_train = \n");
    fprintf(fp, "\n");
}
