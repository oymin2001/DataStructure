#include"ExpandableArray.cpp"


ExpandableArray::ExpandableArray(const char eArr_name[])
{
	capa = 1;
	n = 0;
	strcpy(name, eArr_name);
	dA = (double*)malloc(capa * sizeof(double));
	if (dA == NULL) {
		cout << "Error in allocating memory" << "\n";
	}
}

ExpandableArray::~ExpandableArray()
{
 /*	if (dA != NULL)
		free(dA);    */
}

void ExpandableArray::set(int index, double elem)
{
	if ((index < 0) || (index >= capa)) {
		indexError(index);
	}
	else {
		dA[index] = elem;
	}
}

void ExpandableArray::indexError(int wrongIndex) 
{
	cout << "Index (" << wrongIndex << " ) is out of range" << '\n';
}

double& ExpandableArray::at(int index)
{
	if ((index < 0) || (index >= capa))
		indexError(index);
	else
		return dA[index];
}

void ExpandableArray::reserve(int N)
{
	if (N >= capa) {
		double* newDA;
		newDA = (double*)malloc(N * sizeof(double));
		if (newDA == NULL) {
			cout << "Error in allocating memory" << '\n';
		}
		else {
			for (int i = 0; i < n; i++)
				newDA[i] = dA[i];
			free(dA);
			dA = newDA;
		}
		capa = N;
	}
}

void ExpandableArray::insert(int index, double elem)
{
	if (n >= capa) //overflow 
	{ 
		int cap;
		cap = ((2 * capa) > 1) ? 2 * capa : 1;
		reserve(cap);
	}

	for (int i = n - 1; i >= index; i--)
		dA[i + 1] = dA[i];
	dA[index] = elem;
	n++;
}

void ExpandableArray::erase(int index)
{
	if ((index < 0) || (index >= capa))
		indexError(index);
	else
	{
		for (int i = index; i < n - 1; i++)
			dA[i] = dA[i + 1];
		n--;
	}
}

void ExpandableArray::print(ostream& fout)
{
	if (n <= 0)
		fout << "ExpandableArray is emppty" << '\n';
	else
	{
		fout << "Current size = " << n << '\n';
		for (int i = 0; i < n; i++)
		{
			fout << dA[i] << " ";
		}
		fout << '\n';
	}
}

const ExpandableArray ExpandableArray::operator=(const ExpandableArray rightSide)
{
	double data;
	if (capa != rightSide.capa)
	{
		free(dA);
		capa = rightSide.capa;
		dA = (double*)malloc(capa * sizeof(double));
	}

	n = rightSide.n;
	for (int i = 0; i < n; i++)
	{
		data = rightSide.dA[i];
		dA[i] = data;
	}
	return *this; // 자기자신을 리턴
}
double& ExpandableArray::operator[](int index)
{
	if ((index < 0) || (index >= n))
		indexError(index);
	else
		return dA[index];
}