
int getMid(int s, int e) {  return s + (e -s)/2;  }

int constructSTUtil(vector<int> &arr, int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

vector<int> constructST(vector<int> &arr, int n)
{
    int x = (int)(ceil(log2(n)));

    int max_size = 2*(int)pow(2, x) - 1;

    vector<int> st(max_size);

    constructSTUtil(arr, 0, n-1, st, 0);

    return st;
}

/*int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> st;

    // Build segment tree from given array
    st = constructST(arr, n);

    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %dn",
            getSum(st, n, 1, 3));

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    updateValue(arr, st, n, 1, 10);

    // Find sum after the value is updated
    printf("Updated sum of values in given range = %dn",
             getSum(st, n, 1, 3));
    return 0;
}*/
