#include<iostream>
using namespace std;

/// i denotes the current index.
void printPermuation(char *a,int i){
    ///Base Case
    if(a[i]=='\0'){
        cout<<a<<endl;
        return;
    }

    ///Rec Case
    for(int j=i;a[j]!='\0';j++){
        swap(a[i],a[j]);
        printPermuation(a,i+1);

        ///Undo the swap to restore the original array
        swap(a[i],a[j]);
    }
}

int main(){
    char input[10] = "npabc";
    printPermuation(input,0);



return 0;
}
