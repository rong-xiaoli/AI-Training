#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.AI.MachineLearning.h>
#include <Windows.h>

#define JSON_File_Path_Raw_Data "%APPDATA%\\..\\Local\\AI_Testing_File\\Data\\Raw\\JSON\\raw.json"
char init_statement[];

typedef int COLOR;

void SetColor(HANDLE Command_Handle,COLOR Color_Code)
{
	SetConsoleTextAttribute(Command_Handle, 0x0008 | 0x0002);
}


int json_check()
{
	/*

	Useage:
	1.	No param: ensure that raw json data exist.
	2.	1 Param: json_check(const char file_address)
			ensure that a json file exist in the "file_address"
	3.	2 Param: json_check(const char file_address, char access)
			ensure that you have the right access (read/write mode) to interact a json file
			access: the mode you check a file
				r:read
				w:write
				m(not official):mixed read & write

	*/
	printf("JSON Checking...");
	FILE *fp = NULL;
	fp = fopen(JSON_File_Path_Raw_Data, "rw");
	if (NULL == fp)
	{
		return -1;/*File not exist*/
	}
	else
	{
		fp = NULL;
		return 0;
	}
}
int json_check(char *file_address)
{
	printf("JSON Checking...");
	//one param func.
	FILE *fp;
	fp = fopen(file_address, "rw");
	if (NULL == fp)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int json_check(char *file_address, char *mode)
{

	printf("JSON Checking...");
	FILE *fp;
	fp = fopen(file_address, mode);
	if (NULL == fp)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//json_check func end

//init_check func

void system_init()
{
	int json_check_status = 0;
	printf("Basic init mode\n");
	json_check_status = json_check();
	printf("JSON Module Checked OK! \n");

	strcpy(init_statement, "All done");
	printf("%s\n", init_statement);
}
void system_init(const char *init_mode, bool more_info)
{
	if (more_info == true)
	{
		printf("More Info mode: on \n");
	}
	int json_check_status = 0;
	if (init_mode == "safe")
	{
		printf("Safe mode: on \n");
		printf("Checking JSON...\n");
		FILE *fp;
		fp = NULL;
		printf("Checking if JSON in default address...\n");
		fp = fopen(JSON_File_Path_Raw_Data, "r");
		if (fp = NULL)
		{
			printf("JSON check error: No such file or not enough access to execute:\n");
			printf("fp = fopen(JSON_File_Path_Raw_Data, \"r\");");
		}
	}
}

int main()
{
	printf("fp = fopen(JSON_File_Path_Raw_Data, \"r\");");
	return 0;
}