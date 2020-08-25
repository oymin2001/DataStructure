template<class T>
void swapValues(T& var1, T& var2)
{
	T tmp;

	tmp = var1;
	var1 = var2;
	var2 = tmp;
}

template<class T>
int idxOfSmallest(const T a[], int startIdx, int numUsed)
{
	T min = a[startIdx];
	int idxOfMin = startIdx;

	for (int idx = startIdx + 1; idx < numUsed; idx++)
	{
		if (a[idx] < min)
		{
			min = a[idx];
			idxOfMin = idx;
		}
	}
	return idxOfMin;
}

template<class T>
void sort(T a[], int numberUsed)
{
	int idxOfNextSmallest;
	for (int idx = 0; idx < numberUsed-1; idx++)
	{
		idxOfNextSmallest = idxOfSmallest(a, idx, numberUsed);
		swapValues(a[idx], a[idxOfNextSmallest]);
	}
}

