#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <windows.h>
#include <psapi.h>
#include <conio.h>
#include "Log.h"





#pragma warning(disable:4996)





//DLL
typedef struct s_Header
{
	int COUNT_DLL;
	int COUNT_PROCESS;
	int COUNT_SNAPSHOT;
}t_Header;

typedef struct S_DLL
{
	//data
    char  Nameof_DLL[MAX_PATH];   // Name of the Dll: chrom,word,paint,
	//metadata
	unsigned int Count_DLL;    // Numbers the amount of DLL
	struct S_DLL* next;    //poiner to the next dll
	struct S_DLL* prev;   //poiner to the previous dll

}T_DLL;
int TO_Count_DLL;
T_DLL* DLL_HeadList;
T_DLL* DLL_EndList;
typedef struct S_Process
{
	//data
	
	char Nameof_Process[MAX_PATH]; //The name of the PROCESS that contains the DLLS
	PROCESS_MEMORY_COUNTERS THE_P_M_C; // STRUCT in which the memory of the Process
    DWORD ProcessID; // Id of the process that you put on the function  PrintMemoryInfo
	T_DLL* DLL;  //the dll list
	unsigned int Numbersof_DLL; // how much dll i have
	//metadata
	int Count_Process;           // Numbers the amount of Process
	struct S_Process* next;     //poiner to the next process
	struct S_Process* prev;    //poiner to the previous process


}T_Process;

int TO_Count_Process;


T_Process* Process_HeadList ;
T_Process* Process_EndList ;

typedef struct S_One_SnapShot
{    
      //data
	T_Process* Process; //Process list
	unsigned int Numberofall_Process;
	//metadata
	int Count_SnapShot;  // Numbers the amount of SnapShot
	struct S_One_SnapShot* next;
	struct S_One_SnapShot* prev;
}T_One_SnapShot;

T_One_SnapShot* SnapShot_HeadList;
T_One_SnapShot* SnapShot_EndList;
int TO_Count_SnapShot;


