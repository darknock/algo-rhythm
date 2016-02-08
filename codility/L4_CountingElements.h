int L4_FrogRiverOne(int X, int A[], int N)
{
  int *x = 0;
  x = (int*)malloc(X * sizeof(int));
  for (int i = 0; i < X; ++i) {
    x[i] = 0;
  }
  int r = 0, i = 0;
  for (; i < N; ++i) {
    if(!x[A[i] - 1]) {
      x[A[i] - 1] = 1;
      ++r;
    }

    if (X == r) {
      break;
    }
  }

  return X == r ? i : -1;
}

int L4_MissingInteger(int A[], int N)
{
  int *m = 0;
  m = (int*)malloc(N * sizeof(int));
  for (int i = 0; i < N; ++i) {
    m[i] = 0;
  }

  for (int i = 0; i < N; ++i) {
    if (0 < A[i] && A[i] <= N && m[A[i] - 1] == 0) {
      m[A[i] - 1] = 1;
    }
  }

  int i = 0;
  for (; i < N; ++i) {
    if (!m[i])
      break;
  }

  return i + 1;
}

int L4_PermCheck(int A[], int N)
{
    int *m = 0;
    m = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        m[i] = 0;
    }

    for (int i = 0; i < N; ++i) {
        if (i <= A[i] && A[i] <= N && m[A[i] - 1] == 0) {
            m[A[i] - 1] = 1;
        }
    }

    for (int i = 0; i < N; ++i) {
        printf("%d ", m[i]);
    }

    int i = 0;
    for (; i < N; ++i) {
        if (!m[i])
            break;
    }

    return i + 1 < N ? 0 : 1;
}

struct Results {
  int * C;
  int L;
};

struct Results L4_MaxCounters(int N, int A[], int M)
{
  struct Results results = {0, 0};

  int *C = 0, *D = 0, *Y = 0;
  C = (int*)malloc(N * sizeof(int));
  for (int i = 0; i < N; ++i) {
    C[i] = 0;
  }
  results.C = C;
  results.L = N;
  int max = 0, max_c = 0;

  for (int K = 0; K < M; ++K) {
    int X = A[K];
    if (1 <= X && X <= N) {
      int &c = C[X - 1];
      if (c < max_c)
        c = max_c;
      if (++c > max)
        max = c;
    } else if (X == N + 1) {
      max_c = max;
    }
  }

  for (int i = 0; i < N; ++i)
    if (C[i] < max_c)
     C[i] = max_c;
  return results;
}

