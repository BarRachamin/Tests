#include"Start_End_Long_SnapShot.h"




void Start_End_Long_SnapShot()
{
	LogEvent("Start_End_Long_SnapShot");
	DWORD aProcesses[1024], cbNeeded, c_Processes;
	unsigned int i;
	First_ListProcess = 0;
	char stop = 'S';

	while (stop != 'E')
	{

		// * Receive all process ID and put in aProcesses Array
		if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
		{
			LogError("Start_End_Long_SnapShot");
			return 1;
		}

		// Calculate how many process identifiers were returned.
		c_Processes = cbNeeded / sizeof(DWORD);

		for (i = 0; i < c_Processes; i++)
		{
			PrintMemoryInfo(aProcesses[i]);
		}


		First_ListProcess++;
		if (kbhit())
		{
			stop = getch();
		}

			
	}





	T_One_SnapShot* Current_SnapShot = (T_One_SnapShot*)malloc(sizeof(T_One_SnapShot));

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
	LogEvent("Finish_Start_End_Long_SnapShot");

}