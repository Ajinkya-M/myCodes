vector<vector<int> > Solution::generateMatrix(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A;
    vector< vector<int> > a;
    vector<int> v;
     
    int s = n*n;
    int dir = 1;//1-r,2-d,3-l,4-u
    for(int i=0;i<n;i++){
        v.clear();
        for(int j=0;j<n;j++){
            v.push_back(0);
        }
        a.push_back(v);
    }
    
    int cnt = 0;
    int i=0,j=0;
    while(cnt<s){
        if(dir == 1){
            if(j<n && a[i][j] == 0){
                a[i][j] = ++cnt;
                j++;
                continue;
            }else{
                i++;
                j--;
                dir = 2;
                continue;
            }
        }
        
        if(dir == 2){
            if(i<n && a[i][j] == 0){
                a[i][j] = ++cnt;
                i++;
                continue;
            }else{
                i--;
                j--;
                dir = 3;
                continue;
            }
        }
        
        if(dir == 3){
            if(j>=0 && a[i][j] == 0){
                a[i][j] = ++cnt;
                j--;
                continue;
            }else{
                i--;
                j++;
                dir = 4;
                continue;
            }
        }
        
        if(dir == 4){
            if(i>=0 && a[i][j] == 0){
                a[i][j] = ++cnt;
                i--;
                continue;
            }else{
                i++;
                j++;
                dir = 1;
                continue;
            }
        }
    }
   
    
    return a;
}
