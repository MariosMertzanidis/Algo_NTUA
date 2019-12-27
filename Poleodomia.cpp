#include <iostream>
#include <tuple>
#include <stack>

using namespace std;

int * traverseRight(int hight[],int N){

	stack <tuple <int,int,int>> myStack;
	int costs[N];
	tuple <int,int,int> top;
	myStack.push(make_tuple(hight[0],0,hight[0]));
	cost[0]=hight[0];

	for(int i=1; i<N; i++){

		while(!stack.empty() && get<0>(myStack.top()) <= hight[i]) ){
			myStack.pop();
		}

		if(stack.empty()){
			cost[i]=(i+1)*height[i];
			myStack.push(make_tuple(hight[i],i,cost[i]));
		}
		else{
			top = myStack.top();
			cost[i]= get<2>(top)+(i-get<1>(top))*hight[i];
			myStack.push(make_tuple(hight[i],i,cost[i]));
		}
	}

	return cost;
}


int traverseLeft(int cost[],int hight[],int N){

	stack <tuple <int,int,int>> myStack;
	tuple <int,int,int> top;

	myStack.push(make_tuple(hight[N-1],N-1,hight[N-1]));
	cost[N-1]+=hight[N-1];
	int min=cost[N-1];

	for(int i=N-2; i>-1; i--){

		while(!stack.empty() && get<0>(myStack.top()) <= hight[i])){
			myStack.pop();
		}

		if(stack.empty()){
			cost[i]+=(N-i)*height[i];
			myStack.push(make_tuple(hight[i],i,cost[i]));
		}
		else{
			top = myStack.top();
			cost[i]+= get<2>(top)+(get<1>(top)-i)*hight[i];
			myStack.push(make_tuple(hight[i],i,cost[i]));
		}

		if(min>cost[i]) min=cost[i];
	}

	return min;

}


int main(){

	int N,res;

	cin >> N;

	int hight[N],cost[N];

	for(int i=0; i<N; i++){
		cin >> hight[i];
	}

	cost = traversRight(hight,N);

	res = traversLeft(cost,hight,N)

	cout << res << endl;

}
