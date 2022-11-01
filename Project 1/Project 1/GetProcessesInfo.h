#include  "Struct_Lib.h"


void Add_Process(T_Process* ProcessBuild);
void Add_DLL(char DLLName[]);
void PrintMemoryInfo(DWORD processID);
void GetProcessesInfo();
 int First_ListProcess;
int processNotExist;
int ExistsDLL;

void checkListProcess(T_Process* CheckProcess);
T_DLL* addDLLToExistList(T_DLL* TailOfExistDLL, T_DLL* newList);
void checkListDLL(T_Process* currentProcess, T_DLL* CheckDLL);