#include"Quick3way.h"

int main(){
    vector<int> test={5,4,4,4,44,-1,2,7};
    Quick3way::q3sort(test);
    for(auto i:test)
        cout<<i<<" "<<endl;
}
