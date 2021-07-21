int factorial(int n)
{
    //int k;
    if(n == 1) return 1;
    else return n * factorial(n-1);
}
void main()
{
    int n,f;
    read(n);
    write(n);
    f = factorial(n);
    write(f);
}

