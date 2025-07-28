#include<bits/stdc++.h>
using namespace std;

const int o=21; //6 + 6C2

void cauA(){
    cout<<"=== Cau a:";
    int dSame=0, dDiff=0;
    for(int i=1; i<=6; i++) {
        for(int j=i; j<=6; j++) {
            if (i==j) dSame++;
            else dDiff++;
        }
    }
    cout<<"\nXac suat 2 mat co cung so cham: "<<dSame<<"/"<<o;
    cout<<"\nXac suat 2 mat co khac so cham: "<<dDiff<<"/"<<o;
}

void cauB() {
    cout<<"\n\n=== Cau b:";
    int dSame=0, dDiff=0;
    for(int i=1; i<=6; i++) {
        for(int j=i; j<=6; j++) {
            if ((i%2)==(j%2)) dSame++;
            else dDiff++;
        }
    }
    cout<<"\nXac suat 2 mat cung tinh chan le: "<<dSame<<"/"<<o;
    cout<<"\nXac suat 2 mat khac tinh chan le: "<<dDiff<<"/"<<o;
}

bool snt(int x) {
    if (x==2||x==3||x==5) return true;
    return false;
}

bool hopso(int x) {
    if(x==4||x==6) return true;
    return false;
}

void cauC() {
    cout<<"\n\n=== Cau c:";
    int dS=0, dH=0, dLS=0, dLH=0;
    for(int i=1; i<=6; i++) {
        for(int j=i; j<=6; j++) {
            if (snt(i)&&snt(j)) dS++;
            if (hopso(i)&&hopso(j)) dH++;
            if (snt(i)||snt(j)) dLS++;
            if (hopso(i)||hopso(j)) dLH++;
        }
    }
    cout<<"\nXac suat 2 mat cung la snt: "<<dS<<"/"<<o;
    cout<<"\nXac suat 2 mat cung la hop so: "<<dH<<"/"<<o;
    cout<<"\nXac suat co it nhat 1 mat la snt: "<<dLS<<"/"<<o;
    cout<<"\nXac suat co it nhat 1 mat la hop so: "<<dLH<<"/"<<o;
}

void cauD() {
    cout<<"\n\n=== Cau d:";
    int d=0;
    for(int i=1; i<=6; i++) {
        for(int j=i; j<=6; j++) {
            if (i%j==0||j%i==0) d++;
        }
    }
    cout<<"\nXac suat 1 mat la uoc hoac boi cua mat con lai: "<<d<<"/"<<o;
}

void cauE() {
    cout<<"\n\n=== Cau e:";
    for(int n=2; n<=12; n++) {
        int d=0;
        for(int i=1; i<=6; i++) {
            for(int j=i; j<=6; j++) {
                if(i+j==n) d++;
            }
        }
        cout<<"\nXac suat tong so cham 2 mat = "<<n<<" : "<<d<<"/"<<o;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cauA();
    cauB();
    cauC();
    cauD();
    cauE();
}
