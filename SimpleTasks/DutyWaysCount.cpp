int DutyWaysCount(int N, int A, int B)
{
    if (A < N && B > N)
        return A + 1;
    if (B < N && A > N)
        return B + 1;
    if (A + B == N)
        return 1;
    if (A < N && B < N)
    {
        int count = 0;
        if (A < B)
        {
            while (A != 0)
            {
                --A;
                ++count;
            }
        }
        else
        {
            while (B != 0)
            {
                --A;
                ++count;
            }
        }
        return count;
    }
    if (A > N && B > N)
    {
     	if (A < B)
            return A + 1;
        else
            return B + 1;
    }
}
