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
	// �׷����� ������ �־��� �׷����� ����Ѵ�. ������ ������� ǥ�⸦ �� ����.
	prshortf("\n                       <Kruskal �˰���>                         \n");
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
		prshortf("\t%d��° ���� \t(V%d , V%d)\n", i + 1, F[0][i], F[1][i]);
	}
}

void kruskal(short n, short *X, short *F[2], short su)
{
	short *sortededge[2];
	short e1, e2;
	short i, j;
	short num_selected = 0;
	short so_flag;                //���μ����� Ȯ���ϴ� flag

	sortededge[0] = (short *)malloc(sizeof(short)*su);
	sortededge[1] = (short *)malloc(sizeof(short)*su);
	sort(X, sortededge, su);
	prshortf("\n");
	prshortf("<kruskal�˰����� ���� ����>\n");
	//���� ������ �̹� ���õ� �������� ���տ�
	//�߰��϶� ����Ŭ�� �����ϴ� ���� üũ �ϴ°��Դϴ�.
	prshortf("\n");
	for (i = 0; i<su; i++)
	{
		e1 = sortededge[0][i];
		e2 = sortededge[1][i];           //���μ����� Ȯ���մϴ�.                                  
		so_flag = 0;                     //�� ���� �����ϴ��� Ȯ���ϴ� �̴ϴ�.
										 //���μ��̸� =1, ���μҰ� �ƴϸ� =0
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

			prshortf("(V%d , V%d)  ����\n", e1, e2);

		}
		if (so_flag == 1)
		{
			F[0][num_selected] = e1;
			F[1][num_selected] = e2;
			num_selected++;

			prshortf("(V%d ,V%d)�� �̹� �ٸ� ��ο� ���� ����Ǿ� �ִ� �����Դϴ�.\n", e1, e2);
			prshortf("\t����Ŭ ����->�������� ����\n");
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
	//���� ���� ���մϴ�.
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
	prshortf("��� �������� ����ġ�� ������������ ����\n");
	prshortf("\t<sorted result>\n");

	for (j = 0; j<su; j++)
	{
		prshortf("\t(V%d , V%d) ����ġ= %d\n", sortededge[0][j], sortededge[1][j], weight[j]);
	}
	prshortf("\n");
}
