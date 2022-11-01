
#include"Log.h"
time_t t;
struct tm* timeinfo;

char Log_File[10000];
void Log_Init(char Filename[10000])
{
	strcpy(Log_File, Filename);
}
void Log_Write(char Messege[1000])
{
	time(&t);
	timeinfo = localtime(&t);
	FILE* f = fopen(Log_File, "a");
	char str[1000];
	sprintf(str, "%d.%d.%d/%d:%d:%d-%s", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, Messege);
	fputs(str, f);
	fputs("\n", f);
	fclose(f);
}



void LogError(char messege[1000])
{
	char newMessege[1000];
	sprintf(newMessege, "ERROR -%s", messege);
	Log_Write(newMessege);

}

void LogEvent(char messege[1000])
{
	char newMessege[1000];
	sprintf(newMessege, "Event -%s", messege);
	Log_Write(newMessege);


}

void LogWarning(char messege[1000])
{
	char newMessege[1000];
	sprintf(newMessege, "Warning -%s", messege);
	Log_Write(newMessege);


}

