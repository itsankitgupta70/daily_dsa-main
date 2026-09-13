class Solution {
public:
    bool isPalindrome(int x) {
        double rev=0;
        int temp=x;
        if (x<0) return false;
            while(temp!=0){
                double rem=temp%10;
                rev=rev*10+rem;
                temp=temp/10;
            }
        return rev==x;
    }
};