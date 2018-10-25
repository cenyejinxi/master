#include<iostream>
using namespace std;
int main() {
int n, i, j, x, y, nx, ny;
int a[40][40];
for (i = 0; i< 40; i++)
     for (j = 0;j< 40; j++)
                 a[i][j]= 0;
cin >> n;
y = 0; x = n-1;
n = 2*n-1;
for (i = 1; i <= n*n; i++){
     a[y][x] =i;
     ny = (y-1+n)%n;
     nx = (x+1)%n;
if ((y == 0 && x == n-1) || a[ny][nx] !=0)
          y= y+1;
else {y = ny; x = nx;}
            }
            for (j = 0; j < n; j++)
                        cout << a[0][j]<<"";
cout << endl;
return 0;
}
