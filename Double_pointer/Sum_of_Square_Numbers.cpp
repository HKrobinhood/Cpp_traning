#include <iostream>
using namespace std;

int sum, target;

int main(){
    cout<<"Please enter an int number"<<endl;
    cin>>target;


    int i=0,j=target;
    while (i<j){
        sum = i*i + j*j;
        if(sum == target){
            cout<<i<<"&"<<j;
            return 0;
        }
        else if(sum < target){
            i = i + 1;
        }
        else{
            j = j - 1;
        }
    }
    cout<<"This number cannot form the sum of squares of two numbers "<<endl;
    return 0;
}