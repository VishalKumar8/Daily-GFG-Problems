class Solution
{
public:
    unsigned int getFirstSetBit(int n)
    {
        int cnt = 0;
        while(n){
            cnt++;
            if(n&1)
                break;
            n >>= 1;
        }
        return cnt;
    }
};
