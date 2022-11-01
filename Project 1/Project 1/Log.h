#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#pragma warning (disable:4996)

time_t t;
struct tm* timeinfo;


void Log_Init(char Filename[10000]);

void Log_Write(char Messege[1000]);

void LogError(char messege[1000]);

void LogEvent(char messege[1000]);

void LogWarning(char messege[1000]);