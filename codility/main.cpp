#include "stdio.h"
#include "stdlib.h"

#include "L1_Iterations.h"
#include "L2_Arrays.h"
#include "L3_TimeComplexity.h"
#include "L4_CountingElements.h"
#include "L5_PrefixSums.h"

void usage(char *name);
void wrong_params();

#define TEST(name) \
{\
  printf("Test " #name ":\n");\
int result = name;\
  printf("Test result: %d\n", result);\
}

int main(int argc, char** argv)
{
  if (argc < 3) {
    usage(*argv);
    return 1;
  }

  int test = atoi(argv[1]);
  if (0 == test) {
    printf("Wrong test number.\n");
    usage(*argv);
    return 2;
  }

  switch (test) {
  case 1:
    TEST(L1_Iterations(atoi(argv[2])));
    break;

  case 2:
  {
    int N = atoi(argv[2]);
    if ((N < 1) || (N > 1000000) || (N != argc - 3) || (N % 2 == 0)) {
      wrong_params();
      usage(*argv);
      return 3; 
    }
    int A[1000000]; //Yeah
    for (int i = 0; i < N; ++i)
      A[i] = atoi(argv[i + 3]);

    TEST(L2_Arrays(A, N));
  } break;

  case 31:
  {
    int N = atoi(argv[2]);
    if ((N < 1) || (N > 100000) || (N != argc - 3) || (N < 2)) {
      wrong_params();
      usage(*argv);
      return 3; 
    }
    int A[100000]; //Yeah
    for (int i = 0; i < N; ++i)
      A[i] = atoi(argv[i + 3]);

    TEST(L3_TapeEquilibrium(A, N));
  } break;

  case 32:
  {
    if (argc == 5) {
      int X = atoi(argv[2]);
      int Y = atoi(argv[3]);
      int D = atoi(argv[4]);
      if (X <= Y && X > 0 && Y > 0 && D > 0) {
        TEST(L3_FrogJmp(X, Y, D));
      } else {
        wrong_params();
        usage(*argv);
        return 3; 
      }
    } else {
      wrong_params();
      usage(*argv);
      return 3; 
    }
  } break;

  case 33:
  {
    int N = atoi(argv[2]);
    if ((N < 0) || (100000 < N) || (N != argc - 3)) {
      wrong_params();
      usage(*argv);
      return 3; 
    }
    int A[100000]; //Yeah
    for (int i = 0; i < N; ++i)
      A[i] = atoi(argv[i + 3]);

    TEST(L3_PermMissingElem(A, N));
  } break;

  case 41:
  {
    int X = atoi(argv[2]);
    if ((X < 0) || (100000 < X) || (argc < 5))  {
      wrong_params();
      usage(*argv);
      return 3; 
    }

    int N = atoi(argv[3]);
    if (N != argc - 4) {
      wrong_params();
      usage(*argv);
      return 3;
    }

    int A[100000]; //Yeah
    for (int i = 0; i < N; ++i)
      A[i] = atoi(argv[i + 4]);

    TEST(L4_FrogRiverOne(X, A, N));
  } break;

  case 42:
  {
    int N = atoi(argv[2]);
    if ((N < 1) || (100000 < N) || (N != argc - 3)) {
      wrong_params();
      usage(*argv);
      return 3; 
    }
    int A[100000]; //Yeah
    for (int i = 0; i < N; ++i)
      A[i] = atoi(argv[i + 3]);

    TEST(L4_MissingInteger(A, N));
  } break;

  case 43:
  {
    int N = atoi(argv[2]);
    if ((N < 1) || (100000 < N) || (N != argc - 3)) {
        wrong_params();
        usage(*argv);
        return 3;
    }
    int A[100000]; //Yeah
    for (int i = 0; i < N; ++i)
        A[i] = atoi(argv[i + 3]);

    TEST(L4_PermCheck(A, N));
  } break;

  case 44:
  {
    int M = atoi(argv[2]);
    if ((M < 1) || (100000 < M) || (M != argc - 4)) {
      wrong_params();
      usage(*argv);
      return 3; 
    }
    int N = atoi(argv[3]);
    int A[100000]; //Yeah
    for (int i = 0; i < M; ++i)
      A[i] = atoi(argv[i + 4]);

    printf("Test L4_MaxCounters:\n");
    struct Results results = L4_MaxCounters(N, A, M);
    printf("Test results: %d\n", results.L);
    printf("counters:");
    for (int i = 0; i < N; ++i)
      printf(" %d", results.C[i]);
    printf("\n");
  } break;
  
  case 51:
  {
    if (argc == 5) {
      int A = atoi(argv[2]);
      int B = atoi(argv[3]);
      int K = atoi(argv[4]);
      if (A <= B && K > 0 && K <= 2000000000 && A > 0 && B > 0 && A <= 2000000000 && B <= 2000000000) {
        TEST(L5_CountDiv(A, B, K));
      } else {
        wrong_params();
        usage(*argv);
        return 3; 
      }
    } else {
      wrong_params();
      usage(*argv);
      return 3; 
    }
  } break;

  case 52:
  {
    int N = atoi(argv[2]);
    if ((N < 0) || (100000 < N) || (N != argc - 3)) {
      wrong_params();
      usage(*argv);
      return 3; 
    }
    int A[100000]; //Yeah
    for (int i = 0; i < N; ++i)
      A[i] = atoi(argv[i + 3]);

    TEST(L5_PassingCars(A, N));
  } break;
  
  case 53:
  {
    int M = atoi(argv[2]);
    if ((M < 1) || (50000 < M) || (M * 2 != argc - 4)) {
      wrong_params();
      usage(*argv);
      return 3; 
    }
    char *S = argv[3];
    int P[50000]; //Yeah
    for (int i = 0; i < M; ++i)
      P[i] = atoi(argv[i + 4]);
    int Q[50000]; //Yeah
    for (int i = 0; i < M; ++i)
      Q[i] = atoi(argv[M + i + 4]);

    printf("Test L5_GenomicRangeQuery:\n");
    struct L5_Results results = L5_GenomicRangeQuery(S, P, Q, M);
    printf("Test results: %d factors:", results.M);
    for (int i = 0; i < results.M; ++i)
      printf(" %d", results.A[i]);
    printf("\n");
  } break;

  default:
    printf("No such test.\n");
    usage(*argv);
    return 2;
  }
}

void wrong_params()
{
  printf("Wrong params\n");
}

void usage(char *name)
{
  printf("Usage: %s <test num> [params]\n", name);
}

