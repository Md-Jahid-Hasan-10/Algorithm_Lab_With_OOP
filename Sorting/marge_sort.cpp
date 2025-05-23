#include<bits/stdc++.h>
using namespace std;
int ar[30];
void marge(int l,int mid,int r)
{
    //cout << "marge " << l <<" "<< mid <<" "<< r << endl;
    /// 5 7 2 4 5
    /// 6 7 8 9 10
    /// l = 6, mid = 8, r = 10
    int n1 = (mid - l + 1);
    int n2 = (r - mid);
    int L[n1+3];
    int R[n2+3];
    for(int i = 1; i <= n1; i++)
    {
        L[i] = ar[l+i-1];
    }
    for(int i = 1; i <= n2; i++)
    {
        R[i] = ar[mid + i];
    }
    L[n1+1] = 1e9;
    R[n2+1] = 1e9;
    int i = 1,j = 1;
    for(int k = l; k <= r; k++)
    {
        if(L[i] <= R[j])
        {
            ar[k] = L[i];
            i++;
        }
        else
        {
            ar[k] = R[j];
            j++;
        }
    }
}
void margeSort(int l,int r)
{
    if(l < r)
    {
        int mid = (l + r)/2;
        //cout << "marge sort " << l <<" "<< r << endl;
        margeSort(l,mid);///
        margeSort(mid+1,r);///
        marge(l,mid,r);/// 1-1-2
    }
}
int main()
{
    int n;
    cout<<"enter total elements:"<<endl;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> ar[i];
    }
    margeSort(1,n);
    for(int i = 1; i <= n; i++)
    {
        cout << ar[i] <<" ";
    }
}
