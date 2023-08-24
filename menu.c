#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void main_menu()
{
    int op;

    do
    {
        printf(
            "------------------------------\n"
            "|         MAIN MENU          |\n"
            "------------------------------\n"
            "| 1 - Copy WAV file          |\n"
            "| 2 - Invert Y axis WAV file |\n"
            "| 3 - Invert X axis WAV file |\n"
            "| 4 - Frame selector         |\n"
            "| 0 - Exit                   |\n"
            "------------------------------\n"
            "\nChoose an option:\n");
        scanf("%d", &op);

        clear_screen();
        switch (op)
        {
        case 0:
            printf("\nOPTION 0 CHOOSEN.\nClosing program...\n");
            exit(0);
            break;
        case 1:
            printf("\nOPTION 1 CHOOSEN.\n\n");
            copy_wav();
            break;
        case 2:
            printf("\nOPTION 2 CHOOSEN.\n\n");
            invert_y_axis_wav();
            break;
        case 3:
            printf("\nOPTION 3 CHOOSEN.\n\n");
            invert_x_axis_wav();
            break;
        case 4:
            printf("\nOPTION 4 CHOOSEN.\n\n");
            frame_selector();
        default:
            printf("\nERROR: INVALID CODE\n\n");
            break;
        }
    } while (op != 0);
}