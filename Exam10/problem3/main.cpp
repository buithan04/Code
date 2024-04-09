#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
using namespace std;
class Graph
{
private:
    int v,n;
    vector <string> v_list;
    vector <vector<int>> matrix;
    map <string, int> v_index;
    stack <string> open;
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
    void DFS (string s , string g )
    {
        dem = 0;
        bool found = false;
        open.push(s);
        close = vector<bool> (v,0);
        while (!open.empty())
        {
            string p = open.top();
            open.pop();
            if (p == g)
            {
                found = true;
                break;
            }
            if (close[v_index[p]]) continue;
            else
            {
                close[v_index[p]] = 1;
                dem++;
                for (int i = 0 ; i < v ; i++)
                {
                    if (matrix[v_index[p]][i] != 0)
                    {
                        string q = v_list[i];
                        if (close[i] == 0)
                        {
                            open.push(q);
                            parent[q] = p;
                        }
                    }
                }
            }
        }
        if (found)
        {
            TinhLenght (s,g);
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
            DFS(x,y);
        }
    }
};
int main()
{
    Graph A;
    A.input();
    return 0;
}

