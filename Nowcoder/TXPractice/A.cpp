#include<bits/stdc++.h>

const double eps = 1e-6;

struct Point
{
    static int id;
    int x,y;
    int my_id;
    Point(int _x,int _y) : x(_x), y(_y){ my_id = id ++;}
    bool operator < (const Point &rhs) const 
    {
        return my_id < rhs.my_id;
    }
};

int Point::id = 0;

struct Vec
{
    int x,y;
    Vec(Point a,Point b) : x(a.x - b.x), y(a.y - b.y){}
};

long long get_dis(Point a,Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool judge_angle(Vec a,Vec b)
{
    return ((a.x * b.x) + (a.y * b.y)) == 0;
}

bool judge(const std::vector<Point>& vec_point)
{
    long long dis = get_dis(vec_point[3],vec_point[0]);
    for(int i = 0;i < 3;i ++)
        if(dis != get_dis(vec_point[i],vec_point[i + 1]))
            return false;
    std::vector<Vec> vec_vec;
    vec_vec.push_back(Vec(vec_point[3],vec_point[0]));
    for(int i = 0;i < 3;i ++)
        vec_vec.push_back(Vec(vec_point[i],vec_point[i + 1]));
    for(int i = 0;i < 4;i ++)
        if(!judge_angle(vec_vec[i],vec_vec[(i + 1) % 4]))
            return false;
    return true;
}

int main()
{
    int T;
    std::cin >> T;
    while(T--)
    {
        std::vector<int> vec_x,vec_y;
        for(int i = 0;i < 4;i ++)
        {
            int x;
            std::cin >> x;
            vec_x.push_back(x);
        }
        for(int i = 0;i < 4;i ++)
        {
            int y;
            std::cin >> y;
            vec_y.push_back(y);
        }
        std::vector<Point>vec_point;
        for(int i = 0;i < 4;i ++)
            vec_point.emplace_back(Point(vec_x[i],vec_y[i]));
        bool flag = false;
        do
        {
            if(judge(vec_point))
            {
                flag = true;
                break;
            }
        }while(std::next_permutation(vec_point.begin(),vec_point.end()));
        if(flag)
            std::cout << "Yes" << std::endl;
        else std::cout << "No" << std::endl;
    }
}