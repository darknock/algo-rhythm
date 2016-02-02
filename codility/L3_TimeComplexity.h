int L3_TapeEquilibrium(int A[], int N)
{
  // Calculate right sums
  for (int i = N - 2; i >= 0; --i) {
    A[i] += A[i + 1];
  }

  int left_sum = 0, min_diff = 2147483647;
  for (int i = 1; i < N; ++i) {
    left_sum += A[i - 1] - A[i];
    int d = abs(left_sum - A[i]);
    if (d < min_diff)
      min_diff = d;
  }

  return min_diff;
}

int L3_FrogJmp(int X, int Y, int D)
{
  return (Y - X) / D + ((Y - X) % D != 0);
}

int L3_PermMissingElem(int A[], int N)
{
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < N; ++i) {
      sum1 += A[i];
      sum2 += i + 1;
  }
  sum2 += N + 1;
  return sum2 - sum1;
}

