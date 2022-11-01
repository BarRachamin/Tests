
#include"Take_twenty_SnapShot.h"

void checkListDLL(T_Process* currentProcess, T_DLL* CheckDLL);

T_DLL* addDLLToExistList(T_DLL* TailOfExistDLL, T_DLL* newList);

void checkListProcess(T_Process* CheckProcess);

void Add_Twenty_SnapShot()
{
	LogEvent(" Add_Twenty_SnapShot");
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;
	First_ListProcess = 0;

	// * Receive all process ID and put in aProcesses Array
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		LogError("Add_Twenty_SnapShot");
		return 1;
	}

	// Calculate how many process identifiers were returned.
	cProcesses = cbNeeded / sizeof(DWORD);

	for (int loop = 0; loop < 20; loop++)
	{
		
		for (i = 0; i < cProcesses; i++)
		{
			PrintMemoryInfo(aProcesses[i]);
		}
		First_ListProcess++;
        Sleep(1000);



	}

	T_One_SnapShot* Current_SnapShot = (T_One_SnapShot*)malloc(sizeof(T_One_SnapShot));
	Current_SnapShot->Numberofall_Process = TO_Count_Process;
	Current_SnapShot->Process = Process_HeadList;  //The process list created in the function GetProcessesInfo
	Current_SnapShot->Count_SnapShot = TO_Count_SnapShot;
	TO_Count_SnapShot++;
	Current_SnapShot->next = NULL;

	if (SnapShot_HeadList == NULL)
	{
		SnapShot_HeadList = Current_SnapShot;
		SnapShot_EndList = Current_SnapShot;
		Current_SnapShot->prev = NULL;
	}
	else
	{
		SnapShot_EndList->next = Current_SnapShot;
		Current_SnapShot->prev = SnapShot_EndList;
		SnapShot_EndList = Current_SnapShot;

	}
	LogEvent("Finish_Add_Twenty_SnapShot");

}










