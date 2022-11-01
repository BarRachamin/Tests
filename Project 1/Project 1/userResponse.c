#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <windows.h>
#include <psapi.h>
#include "Struct_Lib.h"
#pragma warning(disable:4996)



main()
{
    Log_Init("Project_1");
    LogEvent("Start The Program");

    char UserResponse = '0';
    // To Quit
    while (UserResponse != 'Q')
    {
        printf("hello USer\n welcome to A program that monitors the programs currently running on the computer, outputs data about them and generates reports for the browser in HTML\n To take One SnapShot write-O\n To take 20 SnapShot write-T\n To start Long SnapShot write-S\n to end long SnapShot PRESS-E\n To GenerateHTML report write-G\n To Reset Collection write-R\n To Save in File write-F\n To Load from File write-L\n To Quit write-Q\n ");

        scanf(" %c",&UserResponse);

        switch (UserResponse)
        {
            //One Snap Shot
        case'O': 
            LogEvent("ONE SnapShot");
            Add_One_SnapShot();
            printf("One Snap Shot Taken\n");
            break;
            // 20 Snap Shot
        case 'T':
            LogEvent("Twenty SnapShot");
            Add_Twenty_SnapShot();
            printf("Twenty Snap Shot Taken\n");

            break;
            //start Long SnapShot
        case 'S':
            LogEvent("Strat Long SnapShot");
             Start_End_Long_SnapShot();
             printf("stop the long SnapShot\n");
            break;
            //Generate HTML Report
        case 'G':
            LogEvent("GenrerateHTML");
            bubbleSort();
            Generate_Html_Home();
            Generate_Html_About_me();
            Generate_Html_SnapShot();
            Generate_Html_DllPage();
            Generate_Html_PROCESS_DllList();
             printf("The generate is done\n");
            break;
            //Reset Collection
        case 'R':
            LogEvent("Reset Collaction");
            ResetCollection();
            printf("finish to reset\n");
            break;
            // Save in File
        case'F':
            LogEvent("Save IN File");
            Write_InFile();
            printf("Finish To Save In File Project_File.bin");
            break;
            // Load from File
        case'L':
            LogEvent("Load From File");
             Load_From_File();
             printf("Finish to load From File");
                 break;
        case'Q': 
            LogEvent("Quit The Program");
            break;
        default: printf("Wrong selection. Try be more sharp\n");
            break;
        }

        
    }
    printf("Thank you for using our program");
    LogEvent("finish the program");
}