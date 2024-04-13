#include<iostream>

using namespace std;

/*
��һ����СΪ N*M ��԰�ӣ���������ˮ������ͨ�Ļ�ˮ����Ϊ��������һ��ġ������
԰�����ܹ��ж���ˮ�ݣ�������ָͨ������ͼ����� W ��*�Ĳ��֣�

    ***
    *W*
    ***

��������

 N, M �� 100

 ����:

 ����
    N=10, M=12

԰������ͼ��'W'��ʾ��ˮ�� '.'��ʾû�л�ˮ��

W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.....W...W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

���

    4

 */


const int N = 1e2+10;
const int M = 1e2+10;



int n, m;

//    https://blog.csdn.net/weixin_43946167/article/details/105412508 

void dfs(char a[N][M], int i, int j) {
	a[i][j] = '.'; 
    for (int k = -1; k < 2; k++) {//-1,0,1   k, i �Ƕ����� 
      for (int l = -1; l < 2; l++) {//-1,0,1   j, l �Ƕ����� 
        if (k == 0 && l == 0) continue;

        if (i + k >= 0 && i + k <= n - 1 && j + l >= 0 && j + l <= m - 1) {
          if (a[i + k][j + l] == 'W')
            dfs(a, i + k, j + l);
        }
      }
    //�Ƿ���Ҫ���ݣ����������⣬�������˼·������
    }
}

int main() {

	cin >> n >> m;
	char str[N][M];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> str[i][j];
		} 
	}
	
   int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (str[i][j] == 'W') {
		    cnt++; 
            dfs(str, i, j);//���һ��ˮ��
        }
      }
    }
	cout << cnt << endl;
	return 0;
} 
