int longestPalindromeSubseq(string s) {
    int len = s.size();
    int array [len][len];
    memset( array, 0, len*len*sizeof(int));
    int i,j;
    for (i= 0; i<len; i++){
                array[i][i] =1;
                if (i!=len-1)
                array[i][i+1]= 1;
    }
    for (i=2; i<=len; i++){
        for (j=0; j<len-i+1; j++){
           int k=i+j-1;
           if (s[j]==s[k] && i==2){
                array[j][k] = 2;
           }
            if(s[j]==s[k]) array[j][k]= array[j+1][k-1]+2;
            else array[j][k] = max(array[j+1][k], array[j][k-1]);

        }
    }
    return array[0][len-1];
}
