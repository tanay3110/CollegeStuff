
#include <iostream>
using namespace std;
// void print1(int n){
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <=i; j++){
//             cout << "* " << " ";
//         }
//         cout << endl;
//     }
// }
// void print2(int n){
//     for(int i = 1; i <= n; i++) {
//         for(int j = 0; j <=n-i; j++){
//             cout << "* " << " ";
//         }
//         cout << endl;
//     }
// }
// void print3(int n){
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <=i; j++){
//             cout << j << " ";
//         }
//         cout << endl;
//     }
// }
// void print4(int n){
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= i; j++){
//             cout << i << " ";
//         }
//         cout << endl;
//     }
// }
// void print5(int n){
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <=n-i; j++){
//             cout << j<< " ";
//         }
//         cout << endl;
//     }
// }
// void print6(int n){
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <=i; j++){
//             cout << (char)(j + 64) << " ";
//         }
//         cout << endl;
//     }
// }
// void print7(int n){
//     for(int i = 0; i <= n ;i++) {
//         for(int j = 0; j <=n-i-1; j++){
//             cout << " " ;
//         }
//          for(int j = 1; j <=2*i+1; j++){
//             cout << "*" ;
//         }
//          for(int j = 0; j <=n-i-1; j++){
//             cout << " ";
//         }
//         cout << endl;
//     }
// }
// void print8(int n){
//     for(int i = 0; i <= n ;i++) {
//          for(int j = 0; j <=i; j++){
//             cout << " " ;
//         }
//          for(int j = 1; j <=2*(n-i)-1; j++){
//             cout << "*";
//         }
//          for(int j = 0; j <=i; j++){
//             cout << " " ;}
//         cout << endl;
//     }
// }
// void print9(int n){
//      for(int i = 0; i <= n ;i++) {
//         for(int j = 0; j <=n-i-1; j++){
//             cout << " " ;
//         }
//          for(int j = 1; j <=2*i+1; j++){
//             cout << "*" ;
//         }
//          for(int j = 0; j <=n-i-1; j++){
//             cout << " ";
//         }
//         cout << endl;
//     }
//     for(int i = 0; i <= n ;i++) {
//          for(int j = 0; j <=i; j++){
//             cout << " " ;
//         }
//          for(int j = 1; j <=2*(n-i)-1; j++){
//             cout << "*";
//         }
//          for(int j = 0; j <=i; j++){
//             cout << " " ;}
//         cout << endl;
//     }
// }

void print10(int n)
{
    int fnum;
    for (int i = 0; i <= n; i++)
    {

        if (i == 0)fnum = 1;
        else fnum =0;

            for (int j = 0; j <= i; j++)
            {cout << fnum << " ";
                fnum =1 - fnum;
            }
        cout << endl;
    }
}

int main()
{
    print10(5);
    return 0;
}
