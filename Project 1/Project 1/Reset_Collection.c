#include"Reset_Collection.h"

void ResetCollection()
{
	LogEvent("start-Free");
	T_One_SnapShot* remover_s = SnapShot_HeadList;
	T_Process* remover_p = Process_HeadList;
	T_DLL* remover_d = DLL_HeadList;

	while (DLL_HeadList != NULL)
	{
		DLL_HeadList = DLL_HeadList->next;
		free(remover_d);
		remover_d = DLL_HeadList;
	}
	DLL_HeadList = NULL;
	DLL_EndList = NULL;

	while(Process_HeadList != NULL)
	{
		Process_HeadList = Process_HeadList->next;
		free(remover_p);
		remover_p = Process_HeadList;
	}
    
	Process_HeadList = NULL;
	Process_EndList = NULL;






	while (SnapShot_HeadList != NULL)
	{
		SnapShot_HeadList = SnapShot_HeadList->next;
		free(remover_s);
		remover_s = SnapShot_HeadList;
	}
	SnapShot_HeadList = NULL;
	SnapShot_EndList = NULL;

	 TO_Count_DLL = 1;
     TO_Count_Process = 1;
     TO_Count_SnapShot = 1;

	LogEvent("End to Free");
}
