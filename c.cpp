# include <bits/stdc++.h>
using namespace std;

int cnt[5000005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    int tt;
    cin >> tt;
    while (tt--) {
      int n;
      cin >> n;
      for (int i=0;i<=n;i++) cnt[i]=0;
      for (int i=1;i<=2*n-2;i++) {
        int x;
        cin>>x;
        cnt[x]++;
      }
      int found1=0;
      for (int i=1;i<=n;i++) {
       if (cnt[i]==0) cout << i << ' ' << i;
       else if (cnt[i]==1) {
        if (found1) cout << i ;
        else  {
            found1 = 1;
            cout << i << ' ';
        }
       }
      }
        cout << '\n';
    }

    return 0;
}
