#include<iostream>
#include"AdjGraph.h"
#include"Prim.h"
#include"Kruskal.h"
#include"Dijkstra.h"
#include"Floyd.h"
#include"TopologySort.h"
#include"ModifyTopSort.h"
#include"CriticalPath.h"
using namespace std;
int main(){
	//AdjGraph是Graph的实现类，采用数组表示的邻接矩阵存储权值，书上的定义我觉得并不完善，测试的时候
	//我添加了一些新的代码完善定义，这里没有给出，仅仅检验所有算法的正确性
	//例4.8 采用书上图4-15(a)的图  (b)为结果	
	AdjGraph<int> adjGWei(6, true, false);//无向无权，第二个参数表示有无权重，第三个参数表示有向无向，下面的例子同理
	adjGWei.Vertex[0] = '1';	adjGWei.Vertex[1] = '2';	adjGWei.Vertex[2] = '3';	adjGWei.Vertex[3] = '4';
	adjGWei.Vertex[4] = '5';	adjGWei.Vertex[5] = '6';
	adjGWei.setEdge(0, 0, AFFINITY); adjGWei.setEdge(0, 1, 6); adjGWei.setEdge(0, 2, 1); adjGWei.setEdge(0, 3, 5); adjGWei.setEdge(0, 4, AFFINITY); adjGWei.setEdge(0, 5, AFFINITY);
	adjGWei.setEdge(1, 0, 6); adjGWei.setEdge(1, 1, AFFINITY); adjGWei.setEdge(1, 2, 5); adjGWei.setEdge(1, 3, AFFINITY); adjGWei.setEdge(1, 4, 3); adjGWei.setEdge(1, 5, AFFINITY);
	adjGWei.setEdge(2, 0, 1); adjGWei.setEdge(2, 1, 5); adjGWei.setEdge(2, 2, AFFINITY); adjGWei.setEdge(2, 3, 5); adjGWei.setEdge(2, 4, 6); adjGWei.setEdge(2, 5, 4);
	adjGWei.setEdge(3, 0, 5); adjGWei.setEdge(3, 1, AFFINITY); adjGWei.setEdge(3, 2, 5); adjGWei.setEdge(3, 3, AFFINITY); adjGWei.setEdge(3, 4, AFFINITY); adjGWei.setEdge(3, 5, 2);
	adjGWei.setEdge(4, 0, AFFINITY); adjGWei.setEdge(4, 1, 3); adjGWei.setEdge(4, 2, 6); adjGWei.setEdge(4, 3, AFFINITY); adjGWei.setEdge(4, 4, AFFINITY); adjGWei.setEdge(4, 5, 6);
	adjGWei.setEdge(5, 0, AFFINITY); adjGWei.setEdge(5, 1, AFFINITY); adjGWei.setEdge(5, 2, 4); adjGWei.setEdge(5, 3, 2); adjGWei.setEdge(5, 4, 6); adjGWei.setEdge(5, 5, AFFINITY);
	Edge<int>*  edge;
	int n = adjGWei.vertexNum - 1;
	edge = Prim(adjGWei, 0);
	cout << "prim算法:" << endl;
	for (int j = 0; j < n; j++){
		cout << "边的起点是:" << edge[j].start + 1 << "   终点是:" << edge[j].end + 1 << "    权值是:" << edge[j].weight << endl;
	}

	//例4.9  4.10 采用书上图4-15(a)的图  (b)为结果		
	edge = Kruskal(adjGWei);
	cout << "kruskal算法:" << endl;
	for (int j = 0; j < n; j++){
		cout << "边的起点是:" << edge[j].start + 1 << "   终点是:" << edge[j].end + 1 << "    权值是:" << edge[j].weight << endl;
	}

	//例4.11 采用书上图4-18的图	
	AdjGraph<int> adjGWeiDi(6, true, true);
	adjGWeiDi.Vertex[0] = '0';	adjGWeiDi.Vertex[1] = '1';	adjGWeiDi.Vertex[2] = '2';	adjGWeiDi.Vertex[3] = '3';
	adjGWeiDi.Vertex[4] = '4';	adjGWeiDi.Vertex[5] = '5';
	adjGWeiDi.setEdge(0, 0, AFFINITY); adjGWeiDi.setEdge(0, 1, 12); adjGWeiDi.setEdge(0, 2, 10); adjGWeiDi.setEdge(0, 3, AFFINITY); adjGWeiDi.setEdge(0, 4, 30); adjGWeiDi.setEdge(0, 5, 100);
	adjGWeiDi.setEdge(1, 0, AFFINITY); adjGWeiDi.setEdge(1, 1, AFFINITY); adjGWeiDi.setEdge(1, 2, 5); adjGWeiDi.setEdge(1, 3, AFFINITY); adjGWeiDi.setEdge(1, 4, AFFINITY); adjGWeiDi.setEdge(1, 5, AFFINITY);
	adjGWeiDi.setEdge(2, 0, AFFINITY); adjGWeiDi.setEdge(2, 1, AFFINITY); adjGWeiDi.setEdge(2, 2, AFFINITY); adjGWeiDi.setEdge(2, 3, 50); adjGWeiDi.setEdge(2, 4, AFFINITY); adjGWeiDi.setEdge(2, 5, AFFINITY);
	adjGWeiDi.setEdge(3, 0, AFFINITY); adjGWeiDi.setEdge(3, 1, AFFINITY); adjGWeiDi.setEdge(3, 2, AFFINITY); adjGWeiDi.setEdge(3, 3, AFFINITY); adjGWeiDi.setEdge(3, 4, AFFINITY); adjGWeiDi.setEdge(3, 5, 10);
	adjGWeiDi.setEdge(4, 0, AFFINITY); adjGWeiDi.setEdge(4, 1, AFFINITY); adjGWeiDi.setEdge(4, 2, AFFINITY); adjGWeiDi.setEdge(4, 3, 20); adjGWeiDi.setEdge(4, 4, AFFINITY); adjGWeiDi.setEdge(4, 5, 60);
	adjGWeiDi.setEdge(5, 0, AFFINITY); adjGWeiDi.setEdge(5, 1, AFFINITY); adjGWeiDi.setEdge(5, 2, AFFINITY); adjGWeiDi.setEdge(5, 3, AFFINITY); adjGWeiDi.setEdge(5, 4, AFFINITY); adjGWeiDi.setEdge(5, 5, AFFINITY);
	cout << "Dijkstra算法:" << endl;
	int* D = new int[6];
	int* P = new int[6];
	Dijkstra(adjGWeiDi, 0, D, P);
	PrintDj(adjGWeiDi, 0, D, P);

	//例4.12 采用书上图4-20的图
	cout << "Floyd算法:" << endl;
	int **adjArray = new int*[n];
	for (int i = 0; i < n; i++){
		adjArray[i] = new int[n];
	}
	int **Path = new int*[n];
	for (int j = 0; j < n; j++){
		Path[j] = new int[n];
	}
	AdjGraph<int> adjGWeiDiTwo(3, true, true);
	adjGWeiDiTwo.Vertex[0] = '0';
	adjGWeiDiTwo.Vertex[1] = '1';
	adjGWeiDiTwo.Vertex[2] = '2';
	adjGWeiDiTwo.setEdge(0, 0, AFFINITY); adjGWeiDiTwo.setEdge(0, 1, 5); adjGWeiDiTwo.setEdge(0, 2, 10);
	adjGWeiDiTwo.setEdge(1, 0, 2); adjGWeiDiTwo.setEdge(1, 1, AFFINITY); adjGWeiDiTwo.setEdge(1, 2, 13);
	adjGWeiDiTwo.setEdge(2, 0, 9); adjGWeiDiTwo.setEdge(2, 1, 6); adjGWeiDiTwo.setEdge(2, 2, AFFINITY);
	Floyd(adjGWeiDiTwo, adjArray, Path);
	PrintFloyd(adjGWeiDiTwo, adjArray, Path);
	
	//例4.13 采用书上图4-22的图
	cout << "拓扑排序:" << endl;
	AdjGraph<int>  eventGraph(6, false, true);
	int *sortArray = new int[6];
	eventGraph.Vertex[0] = '1'; eventGraph.Vertex[1] = '2'; eventGraph.Vertex[2] = '3'; eventGraph.Vertex[3] = '4'; eventGraph.Vertex[4] = '5'; eventGraph.Vertex[5] = '6';
	eventGraph.setEdge(0, 0, 0);	eventGraph.setEdge(0, 1, 1);	eventGraph.setEdge(0, 2, 1);	eventGraph.setEdge(0, 3, 0);	eventGraph.setEdge(0, 4, 0);	eventGraph.setEdge(0, 5, 0);
	eventGraph.setEdge(1, 0, 0);	eventGraph.setEdge(1, 1, 0);	eventGraph.setEdge(1, 2, 0);	eventGraph.setEdge(1, 3, 0);	eventGraph.setEdge(1, 4, 0);	eventGraph.setEdge(1, 5, 0);
	eventGraph.setEdge(2, 0, 0);	eventGraph.setEdge(2, 1, 0);	eventGraph.setEdge(2, 2, 0);	eventGraph.setEdge(2, 3, 0);	eventGraph.setEdge(2, 4, 1);	eventGraph.setEdge(2, 5, 1);
	eventGraph.setEdge(3, 0, 0);	eventGraph.setEdge(3, 1, 0);	eventGraph.setEdge(3, 2, 0);	eventGraph.setEdge(3, 3, 0);	eventGraph.setEdge(3, 4, 0);	eventGraph.setEdge(3, 5, 1);
	eventGraph.setEdge(4, 0, 0);	eventGraph.setEdge(4, 1, 0);	eventGraph.setEdge(4, 2, 0);	eventGraph.setEdge(4, 3, 0);	eventGraph.setEdge(4, 4, 0);	eventGraph.setEdge(4, 5, 0);
	eventGraph.setEdge(5, 0, 0);	eventGraph.setEdge(5, 1, 0);	eventGraph.setEdge(5, 2, 0);	eventGraph.setEdge(5, 3, 0);	eventGraph.setEdge(5, 4, 0);	eventGraph.setEdge(5, 5, 0);
	cout << "能否排序:" << TopologySort(eventGraph, sortArray) << endl;
	for (int i = 0; i < 6; i++){
		cout << sortArray[i] << "   ";
	}
	//例4.13 采用书上图4-24(b)的图
	AdjGraph<int>  adjTuoPo(4, false, true);
	int *sort = new int[4];
	adjTuoPo.Vertex[0] = 'a';
	adjTuoPo.Vertex[1] = 'b';
	adjTuoPo.Vertex[2] = 'c';
	adjTuoPo.Vertex[3] = 'd';
	adjTuoPo.setEdge(0, 0, 0); adjTuoPo.setEdge(0, 1, 1); adjTuoPo.setEdge(0, 2, 1); adjTuoPo.setEdge(0, 3, 0);
	adjTuoPo.setEdge(1, 0, 0); adjTuoPo.setEdge(1, 1, 0); adjTuoPo.setEdge(1, 2, 0); adjTuoPo.setEdge(1, 3, 1);
	adjTuoPo.setEdge(2, 0, 0); adjTuoPo.setEdge(2, 1, 1); adjTuoPo.setEdge(2, 2, 0); adjTuoPo.setEdge(2, 3, 0);
	adjTuoPo.setEdge(3, 0, 0); adjTuoPo.setEdge(3, 1, 0); adjTuoPo.setEdge(3, 2, 1); adjTuoPo.setEdge(3, 3, 0);
	cout << endl;
	cout << "能否拓扑排序:" << TopologySort(adjTuoPo, sort) << endl;

	//例4.14 采用书上图4-25的图
	cout << "计算各个顶点事件的最早发生时间:" << endl;
	AdjGraph<int>  eventGraph2(7, true, true);
	int *sortArray2 = new int[7];
	int *AE = new int[7];
	eventGraph2.Vertex[0] = '1'; eventGraph2.Vertex[1] = '2'; eventGraph2.Vertex[2] = '3'; eventGraph2.Vertex[3] = '4'; eventGraph2.Vertex[4] = '5';
	eventGraph2.Vertex[5] = '6'; eventGraph2.Vertex[6] = '7';
	eventGraph2.setEdge(0, 0, AFFINITY);	eventGraph2.setEdge(0, 1, 6);	eventGraph2.setEdge(0, 2, 3);	eventGraph2.setEdge(0, 3, AFFINITY);	eventGraph2.setEdge(0, 4, AFFINITY);	eventGraph2.setEdge(0, 5, AFFINITY); eventGraph2.setEdge(0, 6, AFFINITY);
	eventGraph2.setEdge(1, 0, AFFINITY);	eventGraph2.setEdge(1, 1, AFFINITY);	eventGraph2.setEdge(1, 2, AFFINITY);	eventGraph2.setEdge(1, 3, 1);	eventGraph2.setEdge(1, 4, AFFINITY);	eventGraph2.setEdge(1, 5, AFFINITY); eventGraph2.setEdge(1, 6, AFFINITY);
	eventGraph2.setEdge(2, 0, AFFINITY);	eventGraph2.setEdge(2, 1, AFFINITY);	eventGraph2.setEdge(2, 2, AFFINITY);	eventGraph2.setEdge(2, 3, 1);	eventGraph2.setEdge(2, 4, AFFINITY);	eventGraph2.setEdge(2, 5, AFFINITY); eventGraph2.setEdge(2, 6, AFFINITY);
	eventGraph2.setEdge(3, 0, AFFINITY);	eventGraph2.setEdge(3, 1, AFFINITY);	eventGraph2.setEdge(3, 2, AFFINITY);	eventGraph2.setEdge(3, 3, AFFINITY);	eventGraph2.setEdge(3, 4, 9);	eventGraph2.setEdge(3, 5, 6); eventGraph2.setEdge(3, 6, AFFINITY);
	eventGraph2.setEdge(4, 0, AFFINITY);	eventGraph2.setEdge(4, 1, AFFINITY);	eventGraph2.setEdge(4, 2, AFFINITY);	eventGraph2.setEdge(4, 3, AFFINITY);	eventGraph2.setEdge(4, 4, AFFINITY);	eventGraph2.setEdge(4, 5, AFFINITY); eventGraph2.setEdge(4, 6, 2);
	eventGraph2.setEdge(5, 0, AFFINITY);	eventGraph2.setEdge(5, 1, AFFINITY);	eventGraph2.setEdge(5, 2, AFFINITY);	eventGraph2.setEdge(5, 3, AFFINITY);	eventGraph2.setEdge(5, 4, AFFINITY);	eventGraph2.setEdge(5, 5, AFFINITY); eventGraph2.setEdge(5, 6, 3);
	eventGraph2.setEdge(6, 0, AFFINITY);	eventGraph2.setEdge(6, 1, AFFINITY);	eventGraph2.setEdge(6, 2, AFFINITY);	eventGraph2.setEdge(6, 3, AFFINITY);	eventGraph2.setEdge(6, 4, AFFINITY);	eventGraph2.setEdge(6, 5, AFFINITY); eventGraph2.setEdge(6, 6, AFFINITY);
	cout << "能否排序:" << ModifyTopSort(eventGraph2, AE, sortArray2) << endl;
	for (int i = 0; i < 7; i++){
		cout << sortArray2[i]+1 << "   ";
	}
	cout << endl;
	cout << "事件的最早发生时间:" << endl;
	for (int i = 0; i < 7; i++){
		cout << "事件" << i+1 << "  AE：" << AE[i] << "   " << endl;
	}

	//例4.15 采用书上图4-25的图
	cout << "确定关键活动:" << endl;
	int* VE = new int[n];    //记录各个顶点事件的最早发生时间
	int* VL = new int[n];    //记录各个顶点事件的最迟发生时间
	int* TopOrder = new int[n];  //记录拓扑序列
	cout << "能否排序:" << CriticalPath(eventGraph2, VE, VL, TopOrder) << endl;
	for (int i = 0; i < 7; i++){
		cout << TopOrder[i] + 1 << "   ";
	}
	cout << endl;
	cout << "事件的最早发生时间:" << endl;
	for (int i = 0; i < 7; i++){
		cout << "事件" << i + 1 << "  AE：" << VE[i] << "   " << endl;
	}
	cout << "事件的最晚发生时间:" << endl;
	for (int i = 0; i < 7; i++){
		cout << "事件" << i + 1 << "  AE：" << VL[i] << "   " << endl;
	}
	system("pause");
	return 0;
}