// C Code Snippet for Palindrome
bool isPalindrome(int x) {
    long num=0,y=x;
    if(x<0)return false;
    while(y)
    {
        num=(num*10)+(y%10);
        y/=10;
    }
    return (x==num)?true:false;
}
