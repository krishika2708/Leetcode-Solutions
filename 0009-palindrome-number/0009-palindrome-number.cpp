class Solution {
public:
  
       bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;

        int rev = 0;
//half number reverse kr rhe hai overflow avoid krne ke liye
        while(x > rev) {
            int rem = x % 10;
            rev = rev * 10 + rem;
            x = x / 10;
        }

        return (x == rev || x == rev / 10);
    }
};