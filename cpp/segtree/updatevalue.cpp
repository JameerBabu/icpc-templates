int getMid(int s, int e) {  return s + (e -s)/2;  }

void updateValueUtil(vector<int> &st, int ss, int se, int i, int diff, int si)
{
    if (i < ss || i > se)
        return;

    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
    }
}

void updateValue(vector<int> &arr, int *st, int n, int i, int new_val)
{
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }

    int diff = new_val - arr[i];
    arr[i] = new_val;

    updateValueUtil(st, 0, n-1, i, diff, 0);
}
