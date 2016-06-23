#include <iostream>
#include <climits>

using namespace std;
//单源最短路径Dijktra算法
template<class Type>
void Dijkstra(int n, int v, Type dist[], int prev[], Type (*c)[5])
{
    bool status[INT_MAX];
    for(int i = 1; i < n; i++)//初始化距离、状态、和前驱点
    {
        dist[i] = c[v][i];
        status[i] = false;
        if(dist[i] == INT_MAX){prev[i] = 0;}
        else prev[i] = v;
    }
    dist[v] = 0;
    status[v] = true;

    for(int i = 1; i < n; i++)
    {
        int u;
        int temp = INT_MAX;
        for(int j = 1; j < n; j++)//找到和集合S（已经找过的点的集合）中的点相距最短的点，并把该点归到集合S之中
        {
            if(status[j] == false && dist[j] < temp)
            {
                temp = dist[j];
                u = j;
            }
        }
        status[u] = true;
        for(int j = 1; j < n; j++)//每归入S一个新点，更新一次dist
        {
            if(status[j] == false && dist[u] + c[u][j] < dist[j])//如果归入新点后dist比原来小了，更新表中dist
            {
                dist[j] = dist[u] + c[u][j];
                prev[j] = u;
            }
        }
    }
}

int main()
{
    int dist[10];
    int pre[10];
    int c[5][5] = {{0, 10, INT_MAX, 30, 100}, {INT_MAX, 0 , 50, INT_MAX, INT_MAX}, {INT_MAX, INT_MAX, 0, INT_MAX, 10}, {INT_MAX, INT_MAX, 20, 0, 60}, {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}};
    Dijkstra(5, 0, dist, pre, c);
    for(int i = 0; i < 5; i++)
    {
        cout<<"dist["<<i + 1<<"]:"<<dist[i]<<endl;
        cout<<"点1到点5的最短路径打印："<<pre[i + 1]<<","<<endl;
    }
}
