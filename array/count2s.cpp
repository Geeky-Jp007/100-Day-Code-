long long int count2sinRangeAtDigit(long long int number, long long int d)
{
    long long int power10 = (long long int)pow(10, d);
    long long int nxtpower10 = power10*10;
    
    long long int roundDown = number - number % nxtpower10;
    long long int roundUp = roundDown + nxtpower10;
    long long int right = number % power10;
    long long int digit = (number / power10) % 10;
    
    if(digit<2) return roundDown/10;
    if(digit==2) return roundDown/10 + right +1;
    return roundUp/10;
}

/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number)
{
    stringstream st;
    st << number;
    string s = st.str();
    long long int n = s.length();
    
    long long int count = 0;
    for(long long int i=0 ; i<n ; i++){
        count += count2sinRangeAtDigit(number, i);
    }
    return count;
}

