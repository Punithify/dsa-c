
int n;

int  linearSearch(int *a,int searchElement)
{
    int eleCmp = 0, indexCmp = 0;
    for (int i = 0; i < n; i++)
    {
        indexCmp++;

        if (a[i] == searchElement)
        {
            eleCmp++;

            // printf("Element found is %d at %d\n", a[i], i);
            // printf("Number of index and element comparisons %d  %d\n", indexCmp + 1, eleCmp);
            return a[i],i,indexCmp+1,eleCmp;
        }
    }
}