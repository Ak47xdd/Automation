/*
    Copyright (c) 2026 Akshay_Babu, All rights reserved.
    This is : Build v1.3.3(beta), since its open source and under MIT Licence any edits or
    alterations are allowed by the author for code resusablility
    and workflow automation, please feel free to edit or report any
    issues.

    Use this code to debug or test new features, otherwise to use as it is
    go to :
    ../Automation/App/MLAuto.exe to use it as a CLI APP
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <direct.h>
#include <errno.h>
#include <string.h>

#include "../structure/utils.h"
#include "../check/libcheck.h"

int cli();

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        system("cls");
        title();
        printf("\n>> Welcome to MLAuto CLI!\n");
        printf("\n>> Usage : \t./MLAuto [-flag]\n");
        printf("\n>> For Flag info, use [-h] flag.\n");

        return EXIT_SUCCESS;
    }
    else if (strcmp(argv[1], "-h") == 0)
    {
        system("cls");
        title();
        printf("\n>> Welcome to MLAuto CLI!\n");
        printf("\n>> Help :\n");
        printf("\n>> [-h]\t\tShow this help section\n");
        printf("\n>> [-v]\t\tShow version info\n");
        printf("\n>> [-d]\t\tDebug mode\n");
        printf("\n>> [-w]\t\tWrite output to file\n");
        printf("\n>> [-c]\t\tConsole Mode\n");

        return EXIT_SUCCESS;
    }
    else if (strcmp(argv[1], "-v") == 0)
    {
        system("cls");
        title();
        printf("\n>> Welcome to MLAuto CLI!\n");
        printf("\n>> MLAuto Version : %s\n", VER);
        printf("\n>> Copyright (c) Akshay_Babu, All rights reserved!\n");

        return EXIT_SUCCESS;
    }
    else if (strcmp(argv[1], "-d") == 0)
    {
        system("cls");
        title();
        printf("\n>> Welcome to MLAuto CLI!\n");
        printf("\n>> Debug mode activated!\n");
        debug();

        return EXIT_SUCCESS;
    }
    else if (strcmp(argv[1], "-w") == 0)
    {
        system("cls");
        cli();

        return EXIT_SUCCESS;
    }
    else if (strcmp(argv[1], "-c") == 0)
    {
        system("cls");

        system("cd ../console && python MLang.py");

        return EXIT_SUCCESS;
    }
    else
    {
        system("cls");
        title();
        printf("\n>> Invalid flag! Use [-h] for help.\n");

        return EXIT_FAILURE;
    }

    return 0;
}

int cli()
{
    start_prog();

    dir_check();

    if (fp == NULL)
    {
        printf("\nError opening file with relative path: %s\n", strerror(errno));
        printf("\n");

        return EXIT_FAILURE;
    }
    else
    {
        m_libs();

        base_imports();
        ask_torch();
        ask_model();

        m_read_csv();

        read_csv_file();
        drop();

        m_plot();

        hist();
        corr();
        heatmap();
        pairplot();

        log_transform();

        m_feature_scaling();

        std_scaler();

        m_model_build();

        model_build();

        m_model_evaluation();

        model_eval();

        printf("\nFile written successfully at %s\n", relative_path);

        fclose(fp);

        return EXIT_SUCCESS;
    }
    return 0;
}