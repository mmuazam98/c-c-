#include <bits/stdc++.h>
using namespace std;
//finding minimum number of operations required
int convert(int m, int n){
   if (m == n)
      return 0;
   if (m > n)
   return m - n;
   //can't convert in this situation
   if (m <= 0 && n > 0)
      return -1;
   //when n is greater and n is odd
   if (n % 2 == 1)
   //performing '-1' on m
      return 1 + convert(m, n + 1);
   //when n is even
   else
   //performing '*2' on m
      return 1 + convert(m, n / 2);
}
int main(){
   int m = 3, n = 0;
   cout << "Minimum number of operations : " << convert(m, n);
   return 0;
}