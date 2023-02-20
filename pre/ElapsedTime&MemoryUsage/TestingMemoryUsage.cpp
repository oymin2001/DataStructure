#include<iostream>
#include<Windows.h>
#include<ctime>
#include<Psapi.h>

int globar_var;
#define ARRAY_SIZE 100
void recursive_call(int depth);
#define MAX_RECURSIVE_DEPTH 1000
#define PRINT_LEVEL 10
SIZE_T mem_usage = 0, old_usage = 0;
void recursive_call(int level);

SIZE_T GetProcessWorkingSetSize() {
	PROCESS_MEMORY_COUNTERS pmc;

	if (!GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc)))
		return 0;
	
	return pmc.PagefileUsage;
}

int main(int argc, char* argv[]) {
	int local_x;
	static int static_local;

	printf("argc: %d\n", argc);
	for (int i = 0; i < argc; i++)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	printf("Address of main() fuction: %p\n", main);
	printf("Address of globar var: %p\n", &globar_var);
	printf("Address of local var in main(): %p\n", &local_x);
	printf("Address of static local variavle: %p\n", &static_local);
	mem_usage = GetProcessWorkingSetSize();
	printf("Memory usage at main() function level: %p\n", mem_usage);
	old_usage = mem_usage;
	recursive_call(0);

}

void recursive_call(int depth) {

	int auto_y;
	static int static_y;
	int array[ARRAY_SIZE];
	int* dynamicArray;

	if (depth >= MAX_RECURSIVE_DEPTH)
		return;
	dynamicArray = (int*)malloc(sizeof(int) * ARRAY_SIZE);
	if (dynamicArray == NULL)
		printf("Error in dynamic memory allocation at level (%d)\n", depth);

	mem_usage = GetProcessWorkingSetSize();
	if (depth % PRINT_LEVEL == 0){
		printf("Addr of variables (depth%3d): auto_y:%p, static_y:%p, dynamicArray:%p:memory usage(%7d), memory increment(%7d)\n",
			depth, &auto_y, &static_y, dynamicArray, mem_usage, mem_usage - old_usage);
		fflush(stdout);
		old_usage = mem_usage;
	}
	recursive_call(depth + 1);
	free(dynamicArray);

}
