#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MOD = 1e4;

struct Matrix
{
  long long mat[2][2];
  Matrix()
  {
    mat[0][0] = 1,mat[0][1] = 1;
    mat[1][0] = 1,mat[1][1] = 0;
  }
  Matrix operator* (Matrix m)
  {
    Matrix temp;
    memset(temp.mat,0,sizeof(temp.mat));
    for(int i = 0;i < 2;i ++)
    {
      for(int j = 0;j < 2;j ++)
      {
        for(int k = 0;k < 2;k ++)
        {
          temp.mat[i][j] += mat[i][k] * m.mat[k][j];
          temp.mat[i][j] %= MOD;
        }
      }
    }
    return temp;
  }
};

Matrix pow_mod(Matrix mat,long long x)
{
  if(x == 1)
    return mat;
  Matrix temp = pow_mod(mat,x / 2);
  temp = temp * temp;
  if(x % 2)
    temp = temp * mat;
  return temp;
}

int main()
{
  int n;
  while(std::cin >> n)
  {
    if(n == -1)
      break;
    Matrix init_mat;
    if(n == 0)
      std::cout << 0 << std::endl;
    else if(n == 1)
      std::cout << 1 << std::endl;
    else if(n == 2)
      std::cout << 1 << std::endl;
    else 
    {
      init_mat = pow_mod(init_mat,n - 2);
      std::cout << (init_mat.mat[0][1] + init_mat.mat[0][0]) % MOD << std::endl;
    }
  }
}