#include "Load_From_File.h"

void Load_From_File()
{
	LogEvent("Load_From_File");
	FILE* f;

	f = fopen("Project_File.bin", "rb");
	T_One_SnapShot* Load_FromFile = NULL; // = SnapShot_HeadList;

	if (f == NULL)
	{
		//error
	}
	else
	{

		while (Load_FromFile == NULL)
		{

			fread(&Load_FromFile, sizeof(T_One_SnapShot), 1, f);

			while (Load_FromFile->Process == NULL)
			{

				fread(&Load_FromFile->Process, sizeof(T_Process), 1, f);

				while (Load_FromFile->Process->DLL == NULL)
				{

					fread(&Load_FromFile->Process->DLL, sizeof(T_DLL), 1, f);

					Load_FromFile->Process->DLL = Load_FromFile->Process->DLL->next;
				}

				Load_FromFile->Process = Load_FromFile->Process->next;
			}
			Load_FromFile = Load_FromFile->next;
		}
	}

	fclose(f);
	LogEvent("Finish_Load_From_File");

}