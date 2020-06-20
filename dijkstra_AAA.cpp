#include <iostream>
#include <vector>
#include <queue>
#define MAX 1<<30 ///2 на 30-та
using namespace std;
///Структура
struct node
{
    int ver, w;
    node () {};
    node (int _ver, int _w)
    {
        ver=_ver;
        w=_w;
    }
    bool operator<(const node &p) const
    {
        return w>p.w;
    }
};

///Край на структура

vector <node> gr[100]; /// Граф
bool used[1000];
int par[1000], dist[1000];
priority_queue <node> pq;
int a, b,weight; ///ред 27
int stp1; ///начална точка
///Начало на функцията
int vn,wn; ///Брой върхове + брой тегла/ребра

void dijkstra(int stp)
{
    for (int i=1; i<=vn; i++) dist[i]=MAX;
    dist[stp]=0;
    par[stp]=-1;
    pq.push(node(stp, 0));
    while(!pq.empty())
    {
        stp=pq.top().ver;
        pq.pop();

        if ( used[stp] ) continue;

        used[stp]=1;
        for (int i=0; i<gr[stp].size(); i++)
        {
            int vt=gr[stp][i].ver;
            int wt=gr[stp][i].w;

            if ( used[vt] ) continue;

            if ( dist[stp] + wt<dist[vt] )
            {
                dist[vt]=dist[stp]+wt;
                par[vt]=stp;
                pq.push(node(vt,dist[vt]));
            }
        }
    }
    return;

}

///Край на функцията
int main ()
{
    cout<<"Enter the number of vertexes and weights and the start point"<<endl;
    cin>>vn>>wn>>stp1;
    for (int i=0; i<wn; i++)
    {
        cout<<"Point 1, Point 2, weight"<<endl;

        cin>>a>>b>>weight;
        gr[a].push_back(node(b,weight));
        gr[b].push_back(node(a,weight));
    }
    dijkstra (stp1);
    for (int i=1; i<=vn; i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }
    return 0;
}


/*
6 7 1
1 2 9
1 3 2
1 6 7
2 4 3
2 3 2
3 5 1
5 6 2
*/
