#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string d;
    string id;
    // int id;
    double t;
};


int main()
{
    int n;
    while(cin >> n)
    {
        vector<Node> v;
        for(int i = 0; i < n; i ++)
        {
            string d, id;
            // string d;
            // int id;
            double t;
            cin >> d >> id >> t;
            if(t >= 38.0)
                v.push_back({d, id, t});
        }
        sort(v.begin(), v.end(), [](Node&a ,Node& b) {
            if(a.d != b.d)
                return a.d > b.d;
            if (a.t != b.t)
                return a.t > b.t;
            return a.id < b.id;
        });
        cout << v.size() << endl;
        for(auto e : v)
        {
            printf("%s %s %.1lf\n", e.d.c_str(), e.id.c_str(), e.t);
            // printf("%s %d %.1lf\n", e.d.c_str(), e.id, e.t);

        }
    }
}