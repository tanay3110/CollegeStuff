
#include<iostream>
using namespace std;
void print1(int n){
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=i; j++){
            cout << "* " << " ";
        }
        cout << endl;
    }
}
void print2(int n){
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <=n-i; j++){
            cout << "* " << " ";
        }
        cout << endl;
    }
}
void print3(int n){
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void print4(int n){
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
}
void print5(int n){
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=n-i; j++){
            cout << j<< " ";
        }
        cout << endl;
    }
}
void print6(int n){
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=i; j++){
            cout << (char)(j + 64) << " ";
        }
        cout << endl;
    }
}
void print7(int n){
    for(int i = 0; i <= n ;i++) {
        for(int j = 1; j <=n-i-1; j++){
            cout << " " ;
        }
         for(int j = 0; j <=2*i+1; j++){
            cout << "*" ;
        }
         for(int j = 0; j <=n-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
}
int main() {
    print7(5);
    return 0;
}