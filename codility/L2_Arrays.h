int L2_Arrays(int A[], int N)
{
  int sum = 0;
  // Hacky solution from the ass
  /*for (int i = 0; i < N; ++i) {
    sum ^= A[i];
  }*/
  
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (A[i] != 0 && A[i] == A[j]) {
        A[i] = A[j] = 0;
        break;
      }
    }
    sum += A[i];
  }

  return sum;
}

