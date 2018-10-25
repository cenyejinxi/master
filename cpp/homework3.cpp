#include<bits/stdc++.h>
using namespace std;
class farm{
	public:
		int plate[4]={4,1,2,3}/*Bessie, Elsie, and Mildred*/,curmax=7,modified=0,data[4]={0,7,7,7};
		void refresh(int modifier){
			if(plate[0]==2 && plate[1]==modifier && curmax>data[modifier]){
				curmax=max(data[1],max(data[2],data[3]));
			}
			else if(curmax<data[modifier]){
				curmax=data[modifier];
			}
			int tempplate[4]={1};
			for(int i=1;i<=3;i++){
				if(curmax==data[i]){
					tempplate[tempplate[0]]=i;
					tempplate[0]++;
				}
			}
			if(plate[0]==tempplate[0]&&plate[1]==tempplate[1]&&plate[2]==tempplate[2]&&plate[3]==tempplate[3]){
				return;
			}
			modified++;
			plate[0]=tempplate[0];
			plate[1]=tempplate[1];
			plate[2]=tempplate[2];
			plate[3]=tempplate[3]; 
			return;
		}
		void modify(int no,int num){
			data[no]+=num;
			refresh(no);
		}
		int get(void){
			return modified;
		}
};
struct mod{
	int date,no,num;
};
struct cmp{
	bool operator()(mod &a,mod &b){
		return a.date>b.date;
	}
};
int main(){
	freopen("measurement.in","r",stdin);
	freopen("measurement.out","w",stdout);
	priority_queue< mod , vector < mod > , cmp > f;
	int n,t1,t2;
	string name;
	farm e;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t1>>name>>t2;
		int sl;
		if(name=="Bessie"){
			sl=1;
			}
		else if(name=="Elsie"){
			sl=2;
		}
		else{
			sl=3;
		}
		f.push({t1,sl,t2});
	}
	mod temper;
	for(int i=0;i<n;i++){
		temper=f.top();
		f.pop();
		e.modify(temper.no,temper.num);
	}
	cout<<e.get();
	return 0;
}
