#include <iostream>
using namespace std;

int number[]={2,7,11,15};
int sum,target;

int main(){
    
    
    cout<<"please enter an int"<<endl;
    cin>> target;
    
    int i = 0,j = 3;
    
    
    while(i<j){
        sum = number[i] + number[j];
        if (sum == target){
            cout<<i+1<<"&"<<j+1;
            return 0;
        }
        else if(sum < target){
            i=i+1;
        }
        else{
            j=j-1;
        }
    }
    cout<<"no finding"<<endl;
    return 0;
}
