
#include "GetProcessesInfo.h"
//Process
void Add_Process(T_Process* ProcessBuild);

T_Process* Process_HeadList = NULL;
T_Process* Process_EndList = NULL;
 TO_Count_Process = 1;

//DLL
void Add_DLL(char DLLName[]);

T_DLL* DLL_HeadList = NULL;
T_DLL* DLL_EndList = NULL;

TO_Count_DLL = 1;

processNotExist = 0;
ExistsDLL = 0;

void PrintMemoryInfo(DWORD processID)
{
	LogEvent("PrintMemoryInfo");
	T_Process* build_Process_List = (T_Process*)malloc(sizeof(T_Process));


	HANDLE hProcess;
	PROCESS_MEMORY_COUNTERS pmc;

	// Open process in order to receive information
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);
	if (NULL == hProcess)
	{
		LogError("Error in OPen Process");     // Write to log a warning
		return;
	}

	HMODULE hMods[1024];
	DWORD cbNeeded;
	TCHAR FoundProcessName[MAX_PATH];
	TCHAR wDllName[MAX_PATH];
	char regularCharArr[MAX_PATH];
	
	if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
	{
		build_Process_List->THE_P_M_C.PageFaultCount = pmc.PageFaultCount;
		build_Process_List->THE_P_M_C.WorkingSetSize = pmc.WorkingSetSize;
		build_Process_List->THE_P_M_C.QuotaPagedPoolUsage = pmc.QuotaPagedPoolUsage;
		build_Process_List->THE_P_M_C.QuotaPeakPagedPoolUsage = pmc.QuotaPeakPagedPoolUsage;
		build_Process_List->THE_P_M_C.PagefileUsage = pmc.PagefileUsage;
		build_Process_List->ProcessID = processID;
	}
	
	// Get Process Name
	if (GetModuleFileNameEx(hProcess, 0, FoundProcessName, MAX_PATH))
	{
     char ProcessName[MAX_PATH];
	  size_t numConverted;
	 wcstombs_s(&numConverted, ProcessName, MAX_PATH, FoundProcessName, MAX_PATH);

	 strcpy(build_Process_List->Nameof_Process, ProcessName); //strcpy

	
	
	}
	else
	{
		// You better call GetLastError() here
		// Write To log
	}

	


	// Get Dlls List

	if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
	{
		for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			// Get the full path to the module's file.

			if (GetModuleFileNameEx(hProcess, hMods[i], wDllName, MAX_PATH))
			{
			

				// Convert wChar to regular char array (string)
				char dllName[MAX_PATH];
				size_t numConverted;
				wcstombs_s(&numConverted, dllName, MAX_PATH, wDllName, MAX_PATH);

				Add_DLL(dllName);
				int tmp = 0;
				tmp++;

			}
		}
	}
	build_Process_List->Count_Process = TO_Count_Process;

	build_Process_List->DLL = DLL_HeadList;
	build_Process_List->Numbersof_DLL = TO_Count_DLL;
	TO_Count_Process++;

	CloseHandle(hProcess);
	Add_Process(build_Process_List);
	
	LogEvent("Finish_PrintMemoryInfo");

}
void GetProcessesInfo()
{
	LogEvent(" GetProcessesInfo");
	// Get Processes

	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;

	// * Receive all process ID and put in aProcesses Array
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		// Error. Write to log
		return 1;
	}

	// Calculate how many process identifiers were returned.
	cProcesses = cbNeeded / sizeof(DWORD);

	// Print the memory usage for each process
	// *Loop of all processes
	for (i = 0; i < cProcesses; i++)
	{
		PrintMemoryInfo(aProcesses[i]);
	}



	
	LogEvent("Finish_GetProcessesInfo");

}

/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Add_Process(T_Process* ProcessBuild)
{
	LogEvent("Add_Process");
	DLL_HeadList = NULL;
	TO_Count_DLL = 1;

	if (First_ListProcess > 0)
	{
		checkListProcess(ProcessBuild);

		if (processNotExist == 1)
		{
			processNotExist = 0;
			return;
		}
	}


	T_Process* Current_Process = (T_Process*)malloc(sizeof(T_Process));
	strcpy(Current_Process->Nameof_Process, ProcessBuild->Nameof_Process);
	Current_Process->Count_Process = ProcessBuild->Count_Process;
	Current_Process->ProcessID = ProcessBuild->ProcessID;
	Current_Process->THE_P_M_C.PageFaultCount = ProcessBuild->THE_P_M_C.PageFaultCount;
	Current_Process->THE_P_M_C.WorkingSetSize = ProcessBuild->THE_P_M_C.WorkingSetSize;
	Current_Process->THE_P_M_C.QuotaPagedPoolUsage = ProcessBuild->THE_P_M_C.QuotaPagedPoolUsage;
	Current_Process->THE_P_M_C.PagefileUsage = ProcessBuild->THE_P_M_C.PagefileUsage;
	Current_Process->THE_P_M_C.QuotaPeakPagedPoolUsage = ProcessBuild->THE_P_M_C.QuotaPeakPagedPoolUsage;
	Current_Process->DLL = ProcessBuild->DLL;
	Current_Process->Numbersof_DLL = ProcessBuild->Numbersof_DLL;
	
	
	if (Process_HeadList == NULL)
	{
		Process_HeadList = Current_Process;
		Process_EndList = Current_Process;
		
		Current_Process->next = NULL;
		Current_Process->prev = NULL;

	}
	else
	{
		Current_Process->prev = Process_EndList;
		
		Current_Process->next = NULL;
		Process_EndList->next = Current_Process;
		Process_EndList = Current_Process;
	}

	LogEvent("Finish_Add_Process");

}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Add_DLL(char DLLName[])
{
	LogEvent("Add_DLL");

	T_DLL* Current_DLL = (T_DLL*)malloc(sizeof(T_DLL));

	strcpy(Current_DLL->Nameof_DLL, DLLName);

	if (DLL_HeadList == NULL)
	{
		DLL_HeadList = Current_DLL;
		DLL_EndList = Current_DLL;
		Current_DLL->Count_DLL= TO_Count_DLL;
		Current_DLL->next = NULL;
		Current_DLL->prev = NULL;

	}
	else
	{
		Current_DLL->prev = DLL_EndList;
		Current_DLL->Count_DLL = TO_Count_DLL;
		Current_DLL->next = NULL;
		DLL_EndList->next = Current_DLL;
		DLL_EndList = Current_DLL;
	}
	TO_Count_DLL++;
	LogEvent("Finish_Add_DLL");

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void checkListProcess(T_Process* CheckProcess)
{
	LogEvent("checkListProcess");

	T_Process* currentProcess = Process_HeadList;

	while (currentProcess != NULL)
	{
		if ((strcmp(currentProcess->Nameof_Process, CheckProcess->Nameof_Process) == 0) && currentProcess->ProcessID == CheckProcess->ProcessID)
		{
			currentProcess->THE_P_M_C.PageFaultCount += CheckProcess->THE_P_M_C.PageFaultCount;
			currentProcess->THE_P_M_C.WorkingSetSize += CheckProcess->THE_P_M_C.WorkingSetSize;
			currentProcess->THE_P_M_C.QuotaPeakPagedPoolUsage += CheckProcess->THE_P_M_C.QuotaPeakPagedPoolUsage;
			currentProcess->THE_P_M_C.QuotaPagedPoolUsage += CheckProcess->THE_P_M_C.QuotaPagedPoolUsage;
			currentProcess->THE_P_M_C.PagefileUsage += CheckProcess->THE_P_M_C.PagefileUsage;

			checkListDLL(currentProcess, CheckProcess->DLL);

			processNotExist = 1;
			return;

		}


		currentProcess = currentProcess->next;
	}



	LogEvent("Finish_checkListProcess");

}


T_DLL* addDLLToExistList(T_DLL* TailOfExistDLL ,T_DLL* newList)
{
	LogEvent("addDLLToExistList");

	newList->Count_DLL = (TailOfExistDLL->Count_DLL + 1);
	newList->next = NULL;

	TailOfExistDLL->next = newList;
	newList->prev = TailOfExistDLL;
	TailOfExistDLL = newList;

	
	return TailOfExistDLL;
	LogEvent("Finish_addDLLToExistList");

}


void checkListDLL(T_Process* currentProcess, T_DLL* CheckDLL)
{
	LogEvent("checkListDLL");

	T_DLL* currentDLL = currentProcess->DLL;
	T_DLL* currentCheckDLL = CheckDLL;
	while (currentCheckDLL != NULL)//new 
	{
		currentDLL = currentProcess->DLL;

		while (currentDLL != NULL)//origin
		{

			if (strcmp(currentCheckDLL->Nameof_DLL, currentDLL->Nameof_DLL) != 0)//checking if the dlls are  NOTequal
			{
				currentDLL = DLL_EndList;
				T_DLL* dllTailProcessCurrent;
				dllTailProcessCurrent = addDLLToExistList(currentProcess->DLL, currentCheckDLL);
				currentProcess->DLL->Count_DLL = dllTailProcessCurrent;
				currentProcess->Numbersof_DLL = dllTailProcessCurrent->Count_DLL;
			}
			


			
			currentDLL = currentDLL->next;
			
		}
		currentCheckDLL = currentCheckDLL->next;

	}
	LogEvent("Finish_checkListDLL");

}






