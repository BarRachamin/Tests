
#include "Take_One_SnapShot.h"

TO_Count_SnapShot = 1;
T_One_SnapShot* SnapShot_HeadList =NULL;
T_One_SnapShot* SnapShot_EndList=NULL;


void Add_One_SnapShot()
{
	LogEvent("Add_One_SnapShot");

	T_One_SnapShot* Current_SnapShot = (T_One_SnapShot*)malloc(sizeof(T_One_SnapShot));


	GetProcessesInfo();   // created Processes List that include Dlls list

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
	LogEvent("Finish_Add_One_SnapShot");
	
}



