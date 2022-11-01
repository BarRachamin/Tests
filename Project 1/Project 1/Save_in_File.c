#include "Save_in_File.h"

void  Write_InFile()
{
	LogEvent("Write_InFile");
	FILE* f;

	f = fopen("Project_File.bin","wb");
	T_One_SnapShot* Save_InFile = SnapShot_HeadList;

	if (f == NULL)
	{
		//error
	}
	else
	{

	    while (Save_InFile != NULL)
	    {
		
            fwrite(&Save_InFile, sizeof(T_One_SnapShot), 1, f);

			while(Save_InFile->Process !=NULL)
			{ 

			  fwrite(&Save_InFile->Process, sizeof(T_Process), 1, f);

			  while(Save_InFile->Process->DLL != NULL)
			  {

			  fwrite(&Save_InFile->Process->DLL, sizeof(T_DLL), 1, f);

			  Save_InFile->Process->DLL = Save_InFile->Process->DLL->next;
			  }

			  Save_InFile->Process = Save_InFile->Process->next;
			}
         Save_InFile = Save_InFile->next;
		}
	}

	fclose(f);
	LogEvent("Finish_Write_InFile");

}


