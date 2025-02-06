#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 255;
char lisa[MAX_SIZE][MAX_SIZE];

//裁判（Trial）函数，用来比较两者胜负，返回胜者
//二维数组全部初始化为X，比较的时候相当于在外圈加一圈X，二维数组最外圈元素做判断的时候可以与X比较，直接返回 
char Trial(char player1, char player2){
	//检查选手出拳是否规范 
	if( (player1 != 'R' && player1 != 'S' && player1 != 'P') || 
		(player2 != 'R' && player2 != 'S' && player2 != 'P' && player2 != 'X') ) {
			cout << "选手出拳违例！" << endl;
		}
	//判断胜负
	if( player1 == player2) return player1; 	//平局draw
	 
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
	int r,c,n;	//行数、列数、天数
	cin >> r >> c >> n; 
	//将lisa全部初始化为X 
	for(int i=0; i<MAX_SIZE; i++){
		for(int j=0 ; j<MAX_SIZE; j++){
			lisa[i][j] = 'X';
		}
	}
	//输入二维矩阵 
	for(int i=1; i<=r; i++){
		for(int j=1 ; j<=c; j++){
			cin >> lisa[i][j];
		}
	}
	
	for(int d=1; d<=n; d++){
		for(int i=1; i<=r; i++){
			for(int j=1 ; j<=c; j++){
				lisa[i-1][j] = Trial(lisa[i][j], lisa[i-1][j]);	//与上方对手比
				lisa[i+1][j] = Trial(lisa[i][j], lisa[i+1][j]);	//与下方对手比
				lisa[i][j-1] = Trial(lisa[i][j], lisa[i][j-1]);	//与左方对手比
				lisa[i][j+1] = Trial(lisa[i][j], lisa[i][j+1]);	//与右方对手比 
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
