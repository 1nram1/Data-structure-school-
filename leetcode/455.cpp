#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findContentChildren(vector<int>& children,vector<int>& cookies)
{
	sort(children.begin(),children.end());
	sort(cookies.begin(),cookies.end());
	size_t child=0,cookie=0;
	while(child < children.size() && cookie < cookies.size())
	{
		if(children[child]<=cookies[cookie])
		{
			++child;
		}
		++cookie;
	}
		return child;
	
}
int main()
{
	vector<int> a,b;
	for(int i=0;i<5;i++)
	{
		a.push_back(i+3);
	}
	b.push_back(1);
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	b.push_back(9);
	cout<<findContentChildren(a,b)<<endl;
	system("pause");
	return 0;
} 
