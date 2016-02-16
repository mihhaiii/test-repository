# include <bits/stdc++.h>

using namespace std;

int a[4][4];
const int startx[10]={0,0,0,0,1,1,1,2,2,2};
const int starty[10]={0,0,1,2,0,1,2,0,1,2};

int inplace(int val, int px, int py)
{
    int stx = startx[val];
    int sty = starty[val];

    for (int x=stx;x<=stx+1;x++)
        for (int y=sty;y<=sty+1;y++)
         if (x == px && y == py)  return 1;
     return 0;
}

int check(int val)
{
    int stx = startx[val];
    int sty = starty[val];

    for (int x=stx;x<=stx+1;x++)
        for (int y=sty;y<=sty+1;y++)
          if (a[x][y]!=0 && a[x][y]!=val) return 0;
     return 1;
}

void goleste(int val)
{
    int stx = startx[val];
    int sty = starty[val];

    for (int x=stx;x<=stx+1;x++)
        for (int y=sty;y<=sty+1;y++)
          a[x][y]=0;
}

int read()
{
    string s;
    cin>>s;
    if (s=="ENDOFINPUT") return 0;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++) cin >> a[i][j];
    cin>>s;
    return 1;
}

int main()
{
    while (read()) {
            int ok = 1;

            while (1)
            {

                int did = 0;

                for (int i=0;i<4 && ok;i++)
                for (int j=0;j<4 && ok;j++)
                    if (a[i][j])
                {
                    if (!inplace(a[i][j],i,j)) {
                        ok = 0;
                    } else {
                        if (check(a[i][j])) {
                               // cout << "am golit " << a[i][j] << '\n';
                                goleste(a[i][j]);
                                did = 1;
                                }
                    }

                }

                if (did == 0) break;
            }

            for (int i=0;i<4;i++)
                for(int j=0;j<4;j++) ok &= (a[i][j]==0);
            cout << (ok ? "THESE WINDOWS ARE CLEAN" :  "THESE WINDOWS ARE BROKEN") << '\n';
    }


}
