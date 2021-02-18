pair<int,int> slope(int x1,int y1,int x2,int y2)
{
    int den = x2 - x1;
    int num = y2 - y1;
    int z = __gcd(num,den);
    den /= z;
    num /= z;
    if(den < 0)
    {
        den = -den;
        num = -num;
    }
    return {num,den};
}

pair<int,int> incpt(int x1,int y1,int x2,int y2)
{
    int den = x2 - x1;
    int num = -x1 * (y2 - y1) + y1 * (x2 - x1); 
    if(den == 0) {
        num = x1;
    }  
    else {
        int z = __gcd(num,den);
        den /= z;
        num /= z;
    }
    if(den < 0)
    {
        den = -den;
        num = -num;
    }
    return {num,den};
}