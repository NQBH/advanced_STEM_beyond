#include <bits/stdc++.h>
using namespace std;

//hàm đệ quy sinh phân hoạch k phần tử >=1, tổng n
//cur: index hiện tại
//nRemain: tổng còn lại cần phân phối
//part: phân hoạch hiện tại
//res: tất cả phân hoạch

//có xét thứ tự
void genOrderedPartitions(int cur, int k, int nRemain, vector<int>& part, vector<vector<int>>& res) {
    if (cur==k) {
        if (nRemain==0) res.push_back(part);
        return;
    }
    //vì mỗi phần tử >= 1, nên phần tử tại cur có thể nhận giá trị từ 1 đến (nRemain - số phần tử còn lại)
    int minVal=1;
    int maxVal=nRemain - (k-cur-1);
    for (int val=minVal; val<=maxVal; ++val) {
        part[cur]=val;
        genOrderedPartitions(cur+1, k, nRemain-val, part, res);
    }
}

//không xét thứ tự
void genPartitions(int cur, int k, int nRemain, vector<int>& part, vector<vector<int>>& res) {
    if (cur==k) {
        if (nRemain==0) res.push_back(part);
        return;
    }
    int startVal=(cur==0) ? nRemain : min(nRemain, part[cur-1]);
    int endVal=1;
    for (int val=startVal; val>=endVal; --val) {
        part[cur] = val;
        genPartitions(cur + 1, k, nRemain-val, part, res);
    }
}

void ferrers(const vector<int>& part) {
    for (int val:part) {
        for (int i=0; i<val; ++i) cout<<'*';
        cout<<'\n';
    }
}

void ferrersTranspose(const vector<int>& part) {
    int maxHeight=*max_element(part.begin(), part.end());
    int k=part.size();

    for (int i=1; i<=maxHeight; ++i) {
        for (int j=0; j<k; ++j) {
            if (part[j]>=i) cout<<'*';
            else cout<<' ';
        }
        cout<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,k;
    cin>>n>>k;
    if (k>n || k<=0 || n<=0) {
        cout<<"Khong co phan khoach";
        return 0;
    }

    vector<vector<int>>partitions;
    vector<int>part(k);

    genPartitions(0, k, n, part, partitions);
    //genOrderedPartitions(0, k, n, part, partitions);

    cout<<"Co p_"<<k<<"("<<n<<") = "<<partitions.size()<<" phan khoach cua "<<n<<" co "<<k<<" phan tu:\n\n";

    int cnt=1;
    for (const auto& p : partitions) {
        cout<<"Phan khoach "<<cnt++<<": (";
        for (size_t i=0; i<p.size(); ++i) {
            cout<<p[i];
            if (i!=p.size()-1) cout<<", ";
        }
        cout<<")\n\n";

        cout<<"Bieu do Ferrers:\n";
        ferrers(p);
        cout<<'\n';

        cout<<"Bieu do Ferrers chuyen vi:\n";
        ferrersTranspose(p);
        cout << "\n---------------------\n\n";
    }
    return 0;
}
