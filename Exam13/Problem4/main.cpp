#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <queue>
using namespace std;
class Graph
{
private:
    int v,n;
    vector <string> v_list;
    vector <vector<int>> matrix;
    map <string, int> v_index;
    priority_queue <pair<int , int> , vector <pair<int , int>> , greater<pair<int , int>>> open;
    map <string , string > parent;
    vector <bool> close;
    int dem;
public:
    void Init ()
    {
        v_list = vector<string> (v,"");
        matrix = vector<vector<int>> (v,vector<int>(v,0));
        close = vector<bool> (v,0);
    }
    void TinhLenght(string s, string g)
    {
        int Lenght = 0;
        vector<string> path;
        while (g != s)
        {
            path.push_back(g);
            Lenght += matrix[v_index[parent[g]]][v_index[g]];
            g = parent[g];
        }
        path.push_back(g);
        for (int i = path.size() - 1; i >= 0 ; i--)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl<<dem + 1<<" "<<Lenght<<endl;
    }
    void DFS (int s , int g )
    {
        int tmp = 1000000;
        vector <int > d (v,10000000);
        dem = 0;
        bool found = false;
        d[s] = 0;
        open.push({0,s});
        close = vector<bool> (v,0);
        while (!open.empty())
        {
            pair<int , int> p = open.top();
            open.pop();
            if (p.second == g)
            {
                found = true;
                break;
            }
            if (close[p.second] == 1) continue;
            else
            {
                close[p.second] = 1;
                dem++;
                for (int i = 0 ; i < v ; i++)
                {
                    if (matrix[p.second][i] != 0)
                    {
                        string q = v_list[i];
                        int kc = matrix[p.second][i] + d[p.second];
                        if (close[i] == 0)
                        {
                            if (d[i] > kc)
                            {
                                if (i == g) tmp = kc;
                                d[i] = kc;
                                open.push({kc,i});
                                parent[q] = v_list[p.second];
                            }
                        }
                    }
                }
            }
        }
        if (found)
        {
            TinhLenght (v_list[s], v_list[g]);
            while (!open.empty())
            {
                open.pop();
            }
        }
        else
        {
            cout<<"-unreachable-"<<endl;
            cout<<dem<<" "<<0<<endl;
            while (!open.empty())
            {
                open.pop();
            }
        }

    }
    void input()
    {
        cin>>v>>n;
        Init();
        string x,y;
        for (int i = 0 ; i < v ; i++)
        {
            cin>>x;
            v_list[i] = x;
            v_index[x] = i;
        }
        for (int i = 0 ; i < v ; i++)
        {
            for (int j = 0 ; j < v ; j++)
            {
                cin>>matrix[i][j];
            }
        }
        for (int i = 0 ; i < n ; i++)
        {
            cin>>x>>y;
            DFS(v_index[x],v_index[y]);
        }
    }
};
int main()
{
    Graph A;
    A.input();
    return 0;
}
