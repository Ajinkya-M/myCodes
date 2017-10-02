vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {

    vector< vector <int> > v;
    vector<int> r;
    int n = A.size()*2 - 1;
    //cout<<n<<endl;
    int cols = A.size();
    int j = 0,k = 0,ji = 0,ki = -1;
    for(int i=0;i<n;i++){
        if(i < cols){
            ki++;
        }
        else{
            ji++;
        }
        j = ji;
        k = ki;
        r.clear();
        for(;j>=0 && j<cols && k>=0 && k<cols;j++,k--){
            //cout<<A[j][k]<<"pushed into r "<<endl;
            r.push_back(A[j][k]);
        }
        v.push_back(r);
    }
    
    return v;
}
