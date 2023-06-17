int GetAreaPerimeter(const bool* const* arr, int a, int b)
{
  int sum = 0;

  for (size_t i = 0; i < a; i++)
  {
    for (size_t j = 0; j < b; j++)
    {
      if ((arr[i][j] == 1) && (arr[i][j + 1] == 0)) sum++;
      if ((arr[i][j] == 1) && (arr[i][j - 1] == 0)) sum++;
    
    }
  }

  for (size_t i = 0; i < a; i++)
  {
    for (size_t j = 0; j < b; j++)
    {
      if ((arr[j][i] == 1) && (arr[j+1][i] == 0)) sum++;
      if ((arr[j][i] == 1) && (arr[j-1][i] == 0)) sum++;

    }
  }
  return sum;
}