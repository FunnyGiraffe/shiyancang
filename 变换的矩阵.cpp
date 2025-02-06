#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE=11;
//定义两个矩阵 
int originalMatrix[MAX_SIZE][MAX_SIZE];
int targetMatrix[MAX_SIZE][MAX_SIZE];
//transitionMT用于直接变换的数组，避免对原始数组修改 
int transitionMT[MAX_SIZE][MAX_SIZE];
int N;

bool checkMtSame(){
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++){
			if(targetMatrix[i][j] != transitionMT[i][j]){
				return false;
			}
		}
	return true;
}

//将矩阵顺时针90度，调用两次即为中心对称，调用三次即为逆时针90度 
void clockWise(){
	int tempMT[N+1][N+1];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			//先转置矩阵,转置完后将每行的元素收尾交换 
			tempMT[i][j] = transitionMT[j][i];
		}
	//将每行元素进行首尾交换
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N/2;j++){
			swap(tempMT[i][j], tempMT[i][N+1-j]);
		}
	//将顺时针90度后的矩阵赋值给transitionMT,返回
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			transitionMT[i][j] = tempMT[i][j];
		} 
}
 
int compareMatrix(){
	//存放可能的返回值,[1]为1表示情况1，[2]为1表示情况2... 
	int values[5] = {0,0,0,0,0};
	int res;
	//避免对orgMT修改，复制一个二维数组
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++){
			transitionMT[i][j] = originalMatrix[i][j];
	} 
	//4.先判断orgMT和tarMT两个矩阵是否相同
	if(checkMtSame())
		values[4]=1;
	//1.将orgMT顺时针转90°第一次，并判断变换后的矩阵与tarMT是否相同 Clockwise
	clockWise();
	if(checkMtSame())
		values[1]=1;
	//3.将orgMT顺时针转90°第二次（以中央元素为中心互换），并判断变换后的矩阵与tarMT是否相同 Counterclockwise
	clockWise();
	if(checkMtSame())
		values[3]=1;
	//2.将orgMT顺时针转90°第三次（即逆时针转90°），并判断变换后的矩阵与tarMT是否相同
	clockWise();
	if(checkMtSame())
		values[2]=1;
	
	res = values[1] * pow(10,3) + values[2] * pow(10,2) + values[3] * pow(10,1) + values[4] * pow(10,0);
	return res;
}

int main(){
	int res;
	cin >> N;
	//从输入读取原始矩阵
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++){
			cin >> originalMatrix[i][j];
	}
	//从输入读取目标矩阵 
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++){
			cin >> targetMatrix[i][j];
	}
	
	res = compareMatrix();
	switch(res){
		case 1000:
			cout << '1' << ":按照顺时针方向旋转90度" << endl;
			break;
		case 100:
			cout << '2' << ":按照逆时针方向旋转90度" << endl;
			break;
		case 10:
			cout << '3' << ":以中央元素为中心的对应元素互换" << endl;
			break;
		case 1:
			cout << '4' << ":保持原始矩阵,不变幻" << endl;
			break;
		default:
			cout << '5' << ":从原始矩阵到目标矩阵的变幻,不符合任何上述变幻" << endl;
			break;
		}
	return 0;
} 
