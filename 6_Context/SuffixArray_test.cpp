    #include"SuffixArray.h"

    int main(){
        string test = "aacaagtttacaagc";
        string longReaptedStr = "";
        SuffixArray* sfa = new SuffixArray(test);

    //    for(auto i : sfa->getSuffix())
    //        cout<<i<<endl;

        //输出最长重复的子字符串
        cout<<sfa->getLRS()<<endl;
    }
