#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE=11;
//������������ 
int originalMatrix[MAX_SIZE][MAX_SIZE];
int targetMatrix[MAX_SIZE][MAX_SIZE];
//transitionMT����ֱ�ӱ任�����飬�����ԭʼ�����޸� 
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

//������˳ʱ��90�ȣ��������μ�Ϊ���ĶԳƣ��������μ�Ϊ��ʱ��90�� 
void clockWise(){
	int tempMT[N+1][N+1];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			//��ת�þ���,ת�����ÿ�е�Ԫ����β���� 
			tempMT[i][j] = transitionMT[j][i];
		}
	//��ÿ��Ԫ�ؽ�����β����
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N/2;j++){
			swap(tempMT[i][j], tempMT[i][N+1-j]);
		}
	//��˳ʱ��90�Ⱥ�ľ���ֵ��transitionMT,����
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			transitionMT[i][j] = tempMT[i][j];
		} 
}
 
int compareMatrix(){
	//��ſ��ܵķ���ֵ,[1]Ϊ1��ʾ���1��[2]Ϊ1��ʾ���2... 
	int values[5] = {0,0,0,0,0};
	int res;
	//�����orgMT�޸ģ�����һ����ά����
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++){
			transitionMT[i][j] = originalMatrix[i][j];
	} 
	//4.���ж�orgMT��tarMT���������Ƿ���ͬ
	if(checkMtSame())
		values[4]=1;
	//1.��orgMT˳ʱ��ת90���һ�Σ����жϱ任��ľ�����tarMT�Ƿ���ͬ Clockwise
	clockWise();
	if(checkMtSame())
		values[1]=1;
	//3.��orgMT˳ʱ��ת90��ڶ��Σ�������Ԫ��Ϊ���Ļ����������жϱ任��ľ�����tarMT�Ƿ���ͬ Counterclockwise
	clockWise();
	if(checkMtSame())
		values[3]=1;
	//2.��orgMT˳ʱ��ת90������Σ�����ʱ��ת90�㣩�����жϱ任��ľ�����tarMT�Ƿ���ͬ
	clockWise();
	if(checkMtSame())
		values[2]=1;
	
	res = values[1] * pow(10,3) + values[2] * pow(10,2) + values[3] * pow(10,1) + values[4] * pow(10,0);
	return res;
}

int main(){
	int res;
	cin >> N;
	//�������ȡԭʼ����
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++){
			cin >> originalMatrix[i][j];
	}
	//�������ȡĿ����� 
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++){
			cin >> targetMatrix[i][j];
	}
	
	res = compareMatrix();
	switch(res){
		case 1000:
			cout << '1' << ":����˳ʱ�뷽����ת90��" << endl;
			break;
		case 100:
			cout << '2' << ":������ʱ�뷽����ת90��" << endl;
			break;
		case 10:
			cout << '3' << ":������Ԫ��Ϊ���ĵĶ�ӦԪ�ػ���" << endl;
			break;
		case 1:
			cout << '4' << ":����ԭʼ����,�����" << endl;
			break;
		default:
			cout << '5' << ":��ԭʼ����Ŀ�����ı��,�������κ��������" << endl;
			break;
		}
	return 0;
} 
