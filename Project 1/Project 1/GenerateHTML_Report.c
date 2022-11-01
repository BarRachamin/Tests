#include "GenerateHTML_Report.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>






void Generate_Html_Home()
{
	LogEvent("Generate_Html_Home");

	char NUmintoARR[MAX_PATH];
	T_One_SnapShot* generate_snapH = SnapShot_HeadList;
	T_Process* generate_processE = Process_EndList;
	T_Process* generate_processH = Process_HeadList;
	T_DLL* generate_DllList = generate_processH->DLL;
	T_DLL* generate_dllE = DLL_EndList;

	unsigned int counterLinkS = 1;
	unsigned int counterLinkD = 1;
	FILE* Generate = fopen("Home.html", "w");

	if (!Generate)
	{
		LogError("Generate_Html_Home");
	}

	fputs("<!DOCTYPE html>\n<html lang='en'>\n<head>\n<meta charset='UTF-8'/>\n<meta http-equiv='X-UA-Compatible' content='IE=edge'/>\n<meta name='viewport' content='width=device-width,initial-scale=1.0'/>\n<title>Home page</title>\n<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/5.2.x/css/bootstrap.min.css'/>\n<link rel='stylesheet' href='./css folder/home.css'/>\n</head>\n<body>\n<div>\n<header class='header'>\n<div class='header_div'>Dll Count:", Generate);

	sprintf(NUmintoARR, "%d", generate_dllE->Count_DLL);

	fputs(NUmintoARR, Generate);

	fputs("</div>\n<div class='header_div'>Process Count:", Generate);

	sprintf(NUmintoARR, "%d", generate_processE->Count_Process);

	fputs(NUmintoARR, Generate);

	fputs("</div>\n<div class='header_div'>Memory avg: ", Generate);

	sprintf(NUmintoARR, "%d", generate_processE->THE_P_M_C.WorkingSetSize);

	fputs(NUmintoARR, Generate);

	fputs("</div>\n<a href='./home.html' class='header_div'>Home</a>\n<a href='./aboutMe.html' class='header_div'>About Me</a>\n</header>\n</div>\n<div class='grid-container'>\n<div class='table grid-item'>\n<h3>Snapshot list</h3>\n<table>\n<tr>\n<th class='th'>id</th>\n<th class='th'>link</th><th class='th'>Dll Cnt</th>\n<th class='th'>Memory avg</th>\n</tr>", Generate);

	//build table of snapshot information
	while (generate_snapH != NULL)
	{
		fputs("<tr>\n<td>", Generate);
		sprintf(NUmintoARR, "%d", generate_snapH->Count_SnapShot);
		fputs(NUmintoARR, Generate);
		sprintf(NUmintoARR, "</td>\n<td>\n<a href='./snapshotPage%d.html'>Snapshot%d</a></td>\n<td>", counterLinkS, counterLinkS);
		counterLinkS++;
		fputs(NUmintoARR, Generate);
		sprintf(NUmintoARR, "%d", generate_snapH->Process->Numbersof_DLL);
		fputs(NUmintoARR, Generate);
		fputs("</td>\n<td>", Generate);
		sprintf(NUmintoARR, "%d", generate_snapH->Process->THE_P_M_C.WorkingSetSize);
		fputs(NUmintoARR, Generate);
		fputs("</td>\n", Generate);

		generate_snapH = generate_snapH->next;
	}

	fputs(" </tr>\n</table>\n</div>\n", Generate);
	fputs(" <div class='grid-item'>\n<h3>Dll list</h3>\n<table class='dll-table'>\n<tr>\n<th class='th'>Dll Name</th>\n<th class='th'>link</th>\n</tr>\n", Generate);


	//bulid table of Dll list

	while (generate_DllList != NULL)
	{
		fputs("<tr>\n<td>", Generate);
		strcpy(NUmintoARR, generate_DllList->Nameof_DLL);
		fputs(NUmintoARR, Generate);
		sprintf(NUmintoARR, "</td>\n<td><a href='./dllPage%d.html'>Dll%d</a></td>\n", counterLinkD, counterLinkD);
		counterLinkD++;
		fputs(NUmintoARR, Generate);
		generate_DllList = generate_DllList->next;
	}

	fputs("</tr>\n</table>\n</div>\n</div>\n</body>\n</html>", Generate);

	fclose(Generate);
	LogEvent("Finish_Generate_Html_Home");

}





void Generate_Html_SnapShot()
{
	LogEvent("Generate_Html_Snapshot");

	unsigned char NUmintoARR[500];
	char file[MAX_PATH];
	
	T_One_SnapShot* generate_snapH = SnapShot_HeadList;
	T_Process* generate_Process;
	unsigned int counterLinkD ;
	unsigned int counterLinkS = 1;
	unsigned int counterLinkp = 1;
	while (generate_snapH != NULL)
	{
		counterLinkD = 1;
		generate_Process = generate_snapH->Process;
		sprintf(file, "SnapshotPage%d.html", counterLinkS);

		FILE* Generate = fopen(file, "w");

		if (!Generate)
		{
			LogError("Generate_Html_SnapShot()");
		}

		fputs("<!DOCTYPE html>\n<html lang='en'>\n<head>\n<meta charset='UTF-8'/>\n<meta http-equiv='X-UA-Compatible' content='IE=edge'/>\n<meta name='viewport' content='width=device-width,initial-scale=1.0'/>\n", Generate);
		sprintf(NUmintoARR, "<title>SnapShot_Page%d</title>\n<link rel='stylesheet' href='./css folder/page.css'/>\n</head>\n<body>\n<header>\n<a href='./home.html' class='header_div'>Home</a>\n<a href='./aboutMe.html' class='header_div'>About Me</a>\n</header>\n", counterLinkS);
		fputs(NUmintoARR, Generate);
		counterLinkS++;
		fputs("<div class='list-div'>\n<h3> Snapshot list</h3>\n<table>\n<tr>\n<th>Proces Name</th>\n<th>Process ID</th>\n<th>PageFaultCount</th>\n<th>WorkingSetSize</th>\n<th>QuotaPagedPoolUsage</th>\n<th>QuotaPeakPagedPoolUsage</th>\n<th>PagefileUsage</th>\n<th>Dll Cnt</th>\n<th>Process's Dll list</th>\n</tr>\n", Generate);

		//build the Process List

		while (generate_Process!= NULL)
		{
			fputs("<tr>\n<td>", Generate);
			strcpy(NUmintoARR, generate_Process->Nameof_Process);
			fputs(NUmintoARR, Generate);
			fputs("</td>\n<td>", Generate);
			sprintf(NUmintoARR,"%lu", generate_Process->ProcessID);
			fputs(NUmintoARR, Generate);
			fputs("</td>\n<td>", Generate);
			sprintf(NUmintoARR, "%d", generate_Process->THE_P_M_C.PageFaultCount);
			fputs(NUmintoARR, Generate);
			fputs("</td>\n<td>", Generate);
			sprintf(NUmintoARR, "%d", generate_Process->THE_P_M_C.WorkingSetSize);
			fputs(NUmintoARR, Generate);
			fputs("</td>\n<td>", Generate);
			sprintf(NUmintoARR, "%d", generate_Process->THE_P_M_C.QuotaPagedPoolUsage);
			fputs(NUmintoARR, Generate);
			fputs("</td>\n<td>", Generate);
			sprintf(NUmintoARR, "%d", generate_Process->THE_P_M_C.QuotaPeakPagedPoolUsage);
			fputs(NUmintoARR, Generate);
			fputs("</td>\n<td>", Generate);
			sprintf(NUmintoARR, "%d", generate_Process->THE_P_M_C.PagefileUsage);
			fputs(NUmintoARR, Generate);
			fputs("</td>\n<td>", Generate);
			sprintf(NUmintoARR, "%d", generate_Process->Numbersof_DLL);
			fputs(NUmintoARR, Generate);
			sprintf(NUmintoARR, "</td>\n<td>\n<a href='./SNAP_%dprocessDllList%d.html'>Click</a></td>\n",counterLinkp ,counterLinkD);
			fputs(NUmintoARR, Generate);

		generate_Process = generate_Process->next;
			counterLinkD++;
		}

		fputs("</tr>\n</table>\n</div>\n</body>\n</html>", Generate);
		counterLinkp++;

		fclose(Generate);
		generate_snapH = generate_snapH->next;
		
	}

	LogEvent("Finish_Generate_Html_Snapshot");

}



void Generate_Html_PROCESS_DllList()
{
	LogEvent("Generate_Process_DllList");

	unsigned char NUMintoARR[500];
	char file[MAX_PATH];

	T_One_SnapShot* generate_snapHe = SnapShot_HeadList;
	T_Process* generate_process;
	T_DLL* generate_DLL;

	unsigned int counterLinkS;
	unsigned int counterLinkP=1 ;

	while (generate_snapHe != NULL)
	{
		generate_process = generate_snapHe->Process;
		counterLinkS = 1;
		while (generate_process != NULL)
		{
			generate_DLL = generate_process->DLL;
			sprintf(file, "SNAP_%dProcessDllList%d.html",counterLinkP ,counterLinkS);

			FILE* Generate = fopen(file, "w");

			if (!Generate)
			{
				LogError("Generate_Html_PROCESS_DllList");
			}

			fputs("<!DOCTYPE html>\n<html lang='en'>\n<head>\n<meta charset='UTF-8'/>\n<meta http-equiv='X-UA-Compatible' content='IE=edge'/>\n<meta name='viewport' content='width=device-width,initial-scale=1.0'/>\n", Generate);
			sprintf(NUMintoARR, "<title>ProcessDllList%d</title>\n<link rel='stylesheet' href='./css folder/page.css'/>\n</head>\n<body>\n<header>\n<a href='./home.html' class='header_div'>Home</a>\n<a href='./aboutMe.html' class='header_div'>About Me</a>\n<a href='./snapshotPage%d.html' class='header_div'>Back to snapshot page</a>\n</header>\n", counterLinkS, counterLinkP);
			fputs(NUMintoARR, Generate);
			fputs("<div class='list-div'>\n<h3>DLL list</h3>\n<table>\n<tr>\n<th>Dll ID</th>\n<th>Dll NAME</th>\n</tr>\n", Generate);

			//Build the Dll List

			while (generate_DLL != NULL)
			{
				fputs("<tr>\n<td>", Generate);
				sprintf(NUMintoARR, "%d", generate_DLL->Count_DLL);
				fputs(NUMintoARR, Generate);
				fputs("</td>\n<td>", Generate);
				strcpy(NUMintoARR, generate_DLL->Nameof_DLL);
				fputs(NUMintoARR, Generate);
				fputs("</td>\n", Generate);

				generate_DLL = generate_DLL->next;
			}

			fputs("</tr>\n</table>\n</div>\n</body>\n</html>", Generate);

			fclose(Generate);
			generate_process = generate_process->next;
			counterLinkS++;
		}
		generate_snapHe = generate_snapHe->next;
		counterLinkP++;
	}
	
	LogEvent("Finish_Generate_Process_DllList");

}


void Generate_Html_DllPage()
{
	LogEvent("Generate_DllPage");
	unsigned char NUMintoARR[500];
	char file[MAX_PATH];

	T_Process* generatePListD = Process_HeadList;
	T_DLL* generate_DLLlIST ;

	unsigned int counterLinkS = 1;

	while (generatePListD != NULL)
	{
	 
		generate_DLLlIST = generatePListD->DLL;
		sprintf(file, "dllPage%d.html", counterLinkS);

		FILE* Generate = fopen(file, "w");


		if (!Generate)
		{
			LogError("Generate_Html_DllPage");
		}

		fputs("<!DOCTYPE html>\n<html lang='en'>\n<head>\n<meta charset='UTF-8'/>\n<meta http-equiv='X-UA-Compatible' content='IE=edge'/>\n<meta name='viewport' content='width=device-width,initial-scale=1.0'/>\n", Generate);
		sprintf(NUMintoARR, "<title>ProcessList%d</title>\n<link rel='stylesheet' href='./css folder/page.css'/>\n</head>\n<body>\n<header>\n<a href='./home.html' class='header_div'>Home</a>\n<a href='./aboutMe.html' class='header_div'>About Me</a>\n</header>\n", counterLinkS, counterLinkS);
		fputs(NUMintoARR, Generate);
		fputs("<div class='list-div'>\n<table>\n<tr>\n<th>DLL Name</th>\n<th>DLL Name</th>\n</tr>\n", Generate);
		
		while (generate_DLLlIST != NULL)
		{
	     fputs("<tr>\n<td>", Generate);
		 sprintf(NUMintoARR, "%d", generate_DLLlIST->Count_DLL);
		 fputs(NUMintoARR, Generate);
		 fputs("</td>\n<td>", Generate);
		 strcpy(NUMintoARR, generate_DLLlIST->Nameof_DLL);
		 fputs(NUMintoARR, Generate);
		 fputs("</td>\n", Generate);

		 generate_DLLlIST = generate_DLLlIST->next;
		}
		fputs("</tr>\n</table>\n</div>\n</body>\n</html>", Generate);
		fclose(Generate);
	    generatePListD= generatePListD->next;
	
        counterLinkS++;

	}


	LogEvent("Finish_Generate_DllPage");


}


void Generate_Html_About_me()
{
	LogEvent("Generate_Html_About_me");
	FILE* Generate = fopen("aboutMe.html", "w");
	if (!Generate)
	{
		LogError("Generate_Html_About_me");
	}
	fputs("<!DOCTYPE html>\n<html lang='en'>\n<head>\n<meta charset='UTF-8'/>\n<meta http-equiv='X-UA-Compatible' content='IE = edge'/>\n<meta name='viewport' content='width=device-width, initial-scale=1.0'/>\n<title>About me</title>\n<link rel='stylesheet' href='./css folder/aboutme.css'/>\n</head>\n", Generate);
	fputs("<body>\n<div>\n<header>\n<a href='./home.html' class='header_div'>Home</a>\n</header>\n</div>\n<div>\n<main class='header'>\n<h1>I will talk a little about me</h1>\n</main>\n</div>\n<div class='myname'>\n<h3>\n hello my name is Bar Rachamin i live in Tel Aviv and im 23 years old\n</h3>\n</div>\n", Generate);
	fputs("<div class='container'>\n<h1>my hobbies< / h1>\n<h2>\n play on the computer, solve puzzles, hanging out with friends Being at\n home and watching TV with my girlfriend.\n</h2>\n</div>\n", Generate);
	fputs("<div class='image'>\n<img class='pic1' src='images projet C about me/computer.jfif'/>\n<img class='pic1' src='images projet C about me/images.jfif'/>\n<img class='pic1' src='images projet C about me/friends.jfif'/>\n<img class='pic1' src='images projet C about me/netflix&chil.jfif'/>\n</div>\n</body>\n</html>", Generate);
	fclose(Generate);

	LogEvent("Finish_Generate_Html_About_me");

}
