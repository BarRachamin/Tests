#include "Bubblesort.h"







T_Process* replace(T_Process* ptr)
{
	LogEvent("start replace");
	if (ptr == NULL) {
		LogError("didnt work!!");
	}
	else if (ptr == Process_HeadList && ptr->next == Process_EndList)
	{
		ptr->next = NULL;
		ptr->prev = Process_EndList;
		Process_EndList->prev = NULL;
		Process_EndList->next = ptr;
		Process_EndList = ptr;
		Process_HeadList = ptr->prev;
	}
	else if (ptr->next == Process_EndList) {

		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		ptr->next->next = ptr;
		ptr->prev = ptr->next;
		ptr->next = NULL;

		Process_EndList = ptr;
	}
	else if (ptr == Process_HeadList) {

		ptr->prev = ptr->next;
		ptr->next = ptr->next->next;
		ptr->prev->next = ptr;
		ptr->prev->prev = NULL;
		ptr->next->prev = ptr;

		Process_HeadList = ptr->prev;

	}
	else
	{

		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		ptr->next->next->prev = ptr;
		ptr->prev = ptr->next;
		ptr->next = ptr->next->next;
		ptr->prev->next = ptr;

	}
	LogEvent("End to replace");
}


void bubbleSort()
{
	LogEvent("start to bubble");
	T_Process* Bubble = Process_HeadList;
	T_Process* BubbleTonext = Bubble;
	int count = 1;
	
		while (BubbleTonext != NULL)
		{
			if (BubbleTonext->next == NULL)
			{
				//log warnning
			}
			else if (BubbleTonext->Numbersof_DLL > BubbleTonext->next->Numbersof_DLL)
			{
				replace(BubbleTonext);

				

			}
			BubbleTonext = BubbleTonext->next;

		}
	
	
	
	LogEvent("End to bubble");
}