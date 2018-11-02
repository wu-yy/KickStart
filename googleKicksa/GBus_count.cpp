#include <iostream>
#include <fstream>
#include<vector>
using namespace std;

struct layer{
	int begin;
	int end;
};

int countIn(vector<layer>all,int city){
	int count = 0;
	for(auto i : all){
		cout<<i.begin<<" "<<i.end<<endl;
		if(i.begin <= city && city <=i.end){
			count++;
		}
	}
	return count;
}
void main2()
{
	ifstream file_in =ifstream("A-large-practice.in");
	ofstream out=ofstream("index.txt");
	int number_all;
	file_in>>number_all;
	cout<<number_all<<endl;
	for(int i=1;i<=number_all;i++)
	{
		int bus_N = 0;
		file_in>>bus_N;
		vector<layer> all;
		for(int j=0;j<2*bus_N;j=j+2){
			layer a;
			file_in>>a.begin;
			file_in>>a.end;
			all.push_back(a);
		}
		int case_iters=0;
		file_in>>case_iters;
		for(int j=0;j<case_iters;j++){
			int city;
			file_in>>city;
			int count=countIn(all,city);
			if(j==0){
				out<<"Case #"<<i<<": ";
				out<<count<<" ";
			}else if(j==case_iters-1){
				out<<count<<"\n";
			}else{
				out<<count<<" ";
			}
		}
	}

	system("pause");
	//return 0;

}