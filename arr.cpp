#include <iostream>
#include <vector>
using namespace std;

int main()
{  
    
    int a;
    cout<<"Input a integer:";
    cin>>a;
    int* arr= new int[a] ();//堆区数组声明
        for(int i=0;i<a;i++){
            cout << "Value: " << arr[i] << " Address: " << (long long) &arr[i] << endl;
        }
    delete []arr;//堆区数组释放
    
    
    vector <float> v (a);
    v.push_back(5);//在最后一位增加内容，自动扩充5
    cout<<v.size()<<endl;
        for(int i=0;i<a;i++){
            cout << "Value: " << v[i] << " Address: " << (long long) &v[i] << endl;
        }
        
    cout<<v[a]<<endl;
        
        for (auto c :v)
            cout<<c<<"";//遍历整个数组
            
    

    return 0;
}