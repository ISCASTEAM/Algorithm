#include"Insertion.h"

int main(){
    vector<int> test={5,4,-1,2,7};
    Insertion::insort(test);
    for(auto i:test)
        cout<<i<<" "<<endl;
}
