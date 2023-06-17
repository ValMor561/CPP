int PopularNumber(int*arr,size_t size)
{ 
int mas[1001]={};
for(int i=0;i<size;i++)
{ 
mas[arr[i]]++;
}
int max =0;
int ans =0;
for(int i=0;i<1000;i++)
{
if(mas[i]>max)
{
max=mas[i];
ans = i;
}
}
return ans;
}