#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 255;
char lisa[MAX_SIZE][MAX_SIZE];

//���У�Trial�������������Ƚ�����ʤ��������ʤ��
//��ά����ȫ����ʼ��ΪX���Ƚϵ�ʱ���൱������Ȧ��һȦX����ά��������ȦԪ�����жϵ�ʱ�������X�Ƚϣ�ֱ�ӷ��� 
char Trial(char player1, char player2){
	//���ѡ�ֳ�ȭ�Ƿ�淶 
	if( (player1 != 'R' && player1 != 'S' && player1 != 'P') || 
		(player2 != 'R' && player2 != 'S' && player2 != 'P' && player2 != 'X') ) {
			cout << "ѡ�ֳ�ȭΥ����" << endl;
		}
	//�ж�ʤ��
	if( player1 == player2) return player1; 	//ƽ��draw
	 
	if( (player1=='R' && player2=='S') ||
		(player1=='S' && player2=='P') ||
		(player1=='P' && player2=='R') ||
		 player2=='X') {
			return player1;
		} else {
			return player2;
		}
}

int main(){
	int r,c,n;	//����������������
	cin >> r >> c >> n; 
	//��lisaȫ����ʼ��ΪX 
	for(int i=0; i<MAX_SIZE; i++){
		for(int j=0 ; j<MAX_SIZE; j++){
			lisa[i][j] = 'X';
		}
	}
	//�����ά���� 
	for(int i=1; i<=r; i++){
		for(int j=1 ; j<=c; j++){
			cin >> lisa[i][j];
		}
	}
	
	for(int d=1; d<=n; d++){
		for(int i=1; i<=r; i++){
			for(int j=1 ; j<=c; j++){
				lisa[i-1][j] = Trial(lisa[i][j], lisa[i-1][j]);	//���Ϸ����ֱ�
				lisa[i+1][j] = Trial(lisa[i][j], lisa[i+1][j]);	//���·����ֱ�
				lisa[i][j-1] = Trial(lisa[i][j], lisa[i][j-1]);	//���󷽶��ֱ�
				lisa[i][j+1] = Trial(lisa[i][j], lisa[i][j+1]);	//���ҷ����ֱ� 
			}
		}
	}
	
	for(int i=1; i<=r; i++){
		for(int j=1 ; j<=c; j++){
			cout << lisa[i][j];
		}
		cout << endl;
	}
	
	return 0;
} 
