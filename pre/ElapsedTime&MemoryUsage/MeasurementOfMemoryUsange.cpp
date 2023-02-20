#include<iostream>
#include<Windows.h>
#include<Psapi.h>

int main() {
	MEMORYSTATUSEX mss;
	PROCESS_MEMORY_COUNTERS pmc;
	DWORD pProcessIds[200];
	HANDLE process;
	int pid;
	char* alloc[10];
	memset(&mss, 0, sizeof(MEMORYSTATUSEX));
	memset(&pmc, 0, sizeof(PROCESS_MEMORY_COUNTERS));

	mss.dwLength = sizeof(_MEMORYSTATUSEX);
	pmc.cb = sizeof(PROCESS_MEMORY_COUNTERS);
	pid = GetCurrentProcessId();

	if (GlobalMemoryStatusEx(&mss) == 0) {
		printf("GlobalMemoryStatusEx() Fail\n");
		return 0;
	}
	process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (process == NULL) {
		printf("OpenProcess failed\n");
		return 0;
	}
	if (!GetProcessMemoryInfo(process, &pmc, sizeof(PROCESS_MEMORY_COUNTERS))) {
		printf("GetProcessMemoryInfo fail\n");
		return 0;
	}
	printf("Total Phys : %IId\n", (long long)mss.ullTotalPhys);
	printf("Avail Phys : % IId\n", (long long)mss.ullAvailPhys);
	printf(" Process Peak      WorkingSetSize : %10Id\n", pmc.PeakWorkingSetSize);
	printf(" Process Currently WorkingSetSize : %10Id\n", pmc.WorkingSetSize);

	for (int i = 0; i < 10; i++)
	{
		alloc[i] = (char*)malloc(sizeof(char) * 10000000);
		if (!GetProcessMemoryInfo(process, &pmc, sizeof(PROCESS_MEMORY_COUNTERS))) {
			printf("GetProcessMemoryInfo fail\n");
			return 0;
		}
		printf("\nAfter %d-th allocated\n", i);
		printf(" Process Peak      WorkingSetSize : %10Id\n", pmc.PeakWorkingSetSize);
		printf(" Process Currently WorkingSetSize : % 10Id\n", pmc.WorkingSetSize);
	}
	for (int i = 0; i < 10; i++)
	{
		free(alloc[i]);
		if (!GetProcessMemoryInfo(process, &pmc, sizeof(PROCESS_MEMORY_COUNTERS))) {
			printf("GetProcessMemoryInfo fail\n");
			return 0;
		}
		printf("\nAfter %d-th free\n", i);
		printf(" Process Peak      WorkingSetSize : %10Id\n", pmc.PeakWorkingSetSize);
		printf(" Process Currently WorkingSetSize : % 10Id\n", pmc.WorkingSetSize);

	}

	if (GlobalMemoryStatusEx(&mss) == 0) {
		printf("GlobalMemoryStatusEx() Fail\n");
		return 0;
	}
	process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (process == NULL) {
		printf("OpenProcess failed\n");
		return 0;
	}
	if (!GetProcessMemoryInfo(process, &pmc, sizeof(PROCESS_MEMORY_COUNTERS))) {
		printf("GetProcessMemoryInfo fail\n");
		return 0;
	}
	printf("\n\nTotal Phys : %IId\n", (long long)mss.ullTotalPhys);
	printf("Avail Phys : % IId\n", (long long)mss.ullAvailPhys);
	printf(" Process Peak      WorkingSetSize : %10Id\n", pmc.PeakWorkingSetSize);
	printf(" Process Currently WorkingSetSize : %10Id\n", pmc.WorkingSetSize);

}
