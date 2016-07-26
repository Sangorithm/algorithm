#include <stdio.h>
#include <malloc.h>

void kruskal(short n, short *X, short *F[2], short su);
void sort(short *X, short *sortededge[2], short su);

short *weight;

void main()
{


	short i;
	short X[25] =
	{
		0,1,2,0,0,
		1,0,2,3,0,
		2,2,0,6,4,
		0,3,6,0,1,
		0,0,4,1,0,
	};

	short *F[2];
	short su = 7;

	F[0] = (short *)malloc(sizeof(short)*su);
	F[1] = (short *)malloc(sizeof(short)*su);
	// 그래프는 사전에 주어진 그래프를 사용한다. 지금은 예를들어 표기를 한 것임.
	prshortf("\n                       <Kruskal 알고리즘>                         \n");
	prshortf("\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	prshortf("\n +                                                                 +");
	prshortf("\n +                         [0]-------2-------[2]                   +");
	prshortf("\n +                          |              ( /|                    +");
	prshortf("\n +                          |    ___ 2 ___( / |                    +");
	prshortf("\n +                          1   (          3  |                    +");
	prshortf("\n +                          | (           /   |                    +");
	prshortf("\n +                          |(          /     |                    +");
	prshortf("\n +                         [1]---3--- [3]     |                    +");
	prshortf("\n +                                    (       4                    +");
	prshortf("\n +                                     (      |                    +");
	prshortf("\n +                                       1    |                    +");
	prshortf("\n +                                        (   |                    +");
	prshortf("\n +                                         (  |                    +");
	prshortf("\n +                                           [4]                   +");
	prshortf("\n +                                                                 +");
	prshortf("\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	////////////////////////////////////////////////////////////////////////////////////
	kruskal(5, X, F, su);
	prshortf("\n");
	prshortf("\t<kruskal's result>\n");

	for (i = 0; i<4; i++)
	{
		prshortf("\t%d번째 선택 \t(V%d , V%d)\n", i + 1, F[0][i], F[1][i]);
	}
}

void kruskal(short n, short *X, short *F[2], short su)
{
	short *sortededge[2];
	short e1, e2;
	short i, j;
	short num_selected = 0;
	short so_flag;                //서로소인지 확인하는 flag

	sortededge[0] = (short *)malloc(sizeof(short)*su);
	sortededge[1] = (short *)malloc(sizeof(short)*su);
	sort(X, sortededge, su);
	prshortf("\n");
	prshortf("<kruskal알고리즘의 선택 과정>\n");
	//다음 간선을 이미 선택된 간선들의 집합에
	//추가하때 사이클이 생성하는 지를 체크 하는것입니다.
	prshortf("\n");
	for (i = 0; i<su; i++)
	{
		e1 = sortededge[0][i];
		e2 = sortededge[1][i];           //서로소인지 확인합니다.                                  
		so_flag = 0;                     //즉 마디를 공유하는지 확인하는 겁니다.
										 //서로소이면 =1, 서로소가 아니면 =0
		for (j = 0; j<num_selected; j++)
		{
			if ((X[e1 * 5 + F[0][j]])>0 && (X[e2 * 5 + F[0][j]]>0))
			{
				so_flag = 1;
				break;
			}

		}

		if (so_flag == 0)
		{
			F[0][num_selected] = e1;
			F[1][num_selected] = e2;
			num_selected++;

			prshortf("(V%d , V%d)  선택\n", e1, e2);

		}
		if (so_flag == 1)
		{
			F[0][num_selected] = e1;
			F[1][num_selected] = e2;
			num_selected++;

			prshortf("(V%d ,V%d)은 이미 다른 경로에 의해 연결되어 있는 정점입니다.\n", e1, e2);
			prshortf("\t싸이클 형성->다음간선 선택\n");
		}

	}
}

void sort(short *X, short *sortededge[2], short su)
{
	short j, k;

	short num = 0;
	short start, end;
	short temp;

	weight = (short *)malloc(sizeof(short)*su);
	//먼저 변을 구합니다.
	for (j = 0; j<5; j++)
	{
		for (k = j; k<5; k++)
		{
			if (X[j * 5 + k]>0)
			{
				sortededge[0][num] = j;
				sortededge[1][num] = k;
				weight[num] = X[j * 5 + k];
				num++;
			}
		}
	}

	for (j = 0; j<su - 1; j++)
	{
		for (k = 0; k<su - 1; k++)
		{
			if (weight[k]>weight[k + 1])
			{
				temp = weight[k];
				weight[k] = weight[k + 1];
				weight[k + 1] = temp;

				start = sortededge[0][k];
				sortededge[0][k] = sortededge[0][k + 1];
				sortededge[0][k + 1] = start;

				end = sortededge[1][k];

				sortededge[1][k] = sortededge[1][k + 1];
				sortededge[1][k + 1] = end;
			}
		}
	}
	prshortf("\n");
	prshortf("모든 간선들을 가중치의 오름차순으로 정렬\n");
	prshortf("\t<sorted result>\n");

	for (j = 0; j<su; j++)
	{
		prshortf("\t(V%d , V%d) 가중치= %d\n", sortededge[0][j], sortededge[1][j], weight[j]);
	}
	prshortf("\n");
}
