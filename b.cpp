# include <bits/stdc++.h>

using namespace std;
const int N = 100005, MAX = 1002;

int a[N];
int freq[1111];

int main()
{
    int tt;
    scanf("%d", &tt);
    while(tt--) {
     int n;
     scanf("%d", &n);
     for (int i=0;i < MAX; i++) {
        freq[i] = 0;
     }
     for (int i=0;i < n;i++) {
        scanf("%d",&a[i]);
        freq[a[i]]++;
     }
     int Q;
     scanf("%d",&Q);
     while (Q--) {
        int C;
        scanf("%d", &C);
        long long  ans = 0;
        for (int i=0;i <= C;i++) {
            if (C-i>MAX) continue;
            if (i + i == C) ans += 1LL*(freq[i]-1)*freq[i];
            else ans += 1LL*freq[i]*freq[C-i];
        }
        cout << ans << '\n';
     }
    }
    return 0;
}
