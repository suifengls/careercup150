int **My2DAlloc(int rows, int cols)
{
    int **array = (int **)malloc(rows*sizeof(int*));
    for(int i = 0; i < rows; ++i)
	array[i] = (int*)malloc(cols*sizeof(int));
    return array;
}

void My2DDealloc(int **array, int rows)
{
    for(int i = 0; i < rows; ++i)
	free(array[i]);
    free(array);
}

int **My2DArray(int rows, int cols)
{
    int header = rows * sizeof(int*);
    int data = rows * cols * sizeof(int);
    int **array = (int **)malloc(header + data);
    int *buf = (int *)(array + rows);
    for(int i = 0; i < rows; ++i)
	array[i] = buf + i * cols;
    return array;
}
