#include<bits/stdc++.h>


int main()
{
  int n;
  while(std::cin >> n)
  {
    if(n <= 5)
    {
      std::cout << -1 << std::endl;
    }
    else 
    {
      std::cout << 1 << " " << 2 << std::endl;
      std::cout << 2 << " " << 3 << std::endl;
      std::cout << 2 << " " << 4 << std::endl;
      for(int i = 5;i <= n;i ++)
        std::cout << 1 << " " << i << std::endl;
    }
    for(int i = 1;i < n;i ++)
      std::cout << i << " " << i + 1 << std::endl;
  }

}