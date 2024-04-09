#include<iostream>
using namespace std;

void inputGraph(bool*[], int);
void process(bool*[], int, int);



int main()
{
	int v, e, n; //v: số đỉnh, e: số cạnh, n: số thao tác
	cin >> v >> e >> n;

	bool **G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được
G = new bool *[v];
    for (int i = 0; i < v ; i++)
    {
        G[i] = new bool [v];
        for (int j = 0; j < v ; j++)
        {
            G[i][j] = false;
        }
    }
    inputGraph (G,e);
    process(G,v,n);
}
void inputGraph(bool *G[], int e)
{
    int u,v;
    for (int i = 0 ; i < e ;i++)
    {
        cin>>u>>v;
        G[u-1][v-1] = true;
        G[v-1][v-1] = true;
    }
}
void process(bool *G[], int v , int n)
{
    int choice;
    for (int i = 0; i < n ; i++)
    {
        cin>>choice;
        if (choice == 1)
        {
            int x,y;
            cin>>x>>y;
            if (G[x-1][y-1]) cout<<"TRUE"<<endl;
            else cout<<"FALSE"<<endl;
        }
        else if (choice == 2)
        {
            int dem = 0;
            int x;
            cin>>x;
            for (int i = 0 ; i < v ; i++)
            {
                if (G[x-1][i] )
                {
                    cout<<i+1<<" ";
                    dem++;
                }
            }
            if (dem != 0) cout<<"NONE";
            cout<<endl;

        }
    }
}
