#include"Huffman.h"

int main(){
    string test = "ABRACADABRA!";
    cout<<"test string= "<<test<<endl<<endl;

    Huffman* hf = new Huffman();
    hf->compress(test);
    cout<<"after compressing:"<<endl;
    cout<<hf->encodeStr(test)<<endl;
    cout<<endl;

    cout<<"Trie Tree:"<<endl;
    for(int i=0;i<hf->getR();i++)
        if(hf->st[i]!="")
        cout<<(char)i<<" "<<hf->st[i]<<endl;

}
