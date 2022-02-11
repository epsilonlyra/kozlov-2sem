#include <iostream>
using namespace std;

int main()
{
long long int  n;
cin >> n;
for(long long int i = n - 2; i * i >= n; i--){
    if(n % (n - i) == 0){
        cout << n / (n - i)<<" ";
    }
}
cout<<endl;
return 0;
}
