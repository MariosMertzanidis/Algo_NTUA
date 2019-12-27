#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;


bool is_good(int depo, int stops[], int K, int T, int Ts, int Cs, int Tf, int Cf){
	int turbo = depo/Cf, echo = depo/Cs, prev=0, dist;
	double timeSofar=0,dTurbo,dEcho;

	for(int i=0; i<K+1; i++){
		dist=stops[i]-prev;
		prev=stops[i];
		if(dist>echo) return false;
		if(dist<=turbo){
			timeSofar+=Tf*dist;
		}
		else{
			dTurbo = (depo-dist*Cs)/(Cf-Cs);
			dEcho = (dist*Cf-depo)/(Cf-Cs);
			timeSofar+=Tf*dTurbo+Ts*dEcho;
		}
	}

	if(timeSofar<=T) return true;
	else return false;
}

pair <int,int> find(pair <int,int> cars[], int stops[], int N, int K, int T, int Ts, int Cs, int Tf, int Cf){

	int left=-1,right=N,point, prev=N, test, tempSol=N;
	bool good;

	if(!is_good(cars[N-1].first, stops, K, T, Ts, Cs, Tf, Cf)) return make_pair(-1,-1);


	if(is_good(cars[0].first, stops, K, T, Ts, Cs, Tf, Cf)) return cars[0];

	while((right-left)!=1){
		point=(right+left)/2;
		good=is_good(cars[point].first, stops, K, T, Ts, Cs, Tf, Cf);
		if(good){
			right=point;
			tempSol=point;
		}
		else{
			left=point;
		}
	}
	return cars[tempSol];

}


int main(){
	int N,K,D,T,p,c,d,Cs,Cf,Ts,Tf,sTemp;
	cin >> N >> K >> D >> T;
	pair <int,int> cars[N],smallest;
	int stops[K+1];
	stops[K]=D;

	for(int i=0; i<N; i++){
		cin >> p >> c;
		cars[i] = make_pair(c,p);
	}

	for(int i=0; i<K; i++){
		cin >> d;
		stops[i] = d;
	}

	cin >> Ts >> Cs >> Tf >> Cf;

	sort(stops,stops+K+1);
	sort(cars,cars+N);



	smallest = find(cars, stops, N, K, T, Ts, Cs, Tf, Cf);

	sTemp = smallest.second;

	if(sTemp==-1){
		cout << -1 << endl;
	}
	else{
		for(int i=0; i<N; i++){
			if(cars[i].first >= smallest.first && cars[i].second < sTemp) sTemp=cars[i].second;
		}

		cout << sTemp << endl;
	}
}
