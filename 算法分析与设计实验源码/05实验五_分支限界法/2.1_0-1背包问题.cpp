#include<stdio.h>
#include<iostream>
#include<queue>          //优先队列头文件 
using namespace std;
typedef struct Node
{
	int ub;
	int w;
	int v;
	int index;
    bool operator < (const Node &p)const     //大根堆 
    {
    	p.ub>ub;
	}
 }Node;
#define maxNum 10        //物品最大值 
 int w[maxNum];          //存放物品 
 int v[maxNum];          //存放价值 
 int w_v[maxNum];        //存放性价比 
 priority_queue<Node> pp;     
 int W;                  //背包容量 
 int up;                 //上界 
 int down;               //下界 
 int n;                  //物品数 
void sort(int i,int j)     //对存储数组由大到小排序，此处采用快速排序 
{
	int start=i;
	int end=j;
	if(start>=end)
	{
		return;	
	}
	while(start!=end)
	{
		int temp;
		int temp1;
		int temp2;
		while(start<end&&w_v[start]>w_v[end])
		{
		end--;
		}
		if(start==end)
		break;
		temp=w_v[start];
		temp1=w[start];
		temp2=v[start];
		w_v[start]=w_v[end];
		w[start]=w[end];
		v[start]=v[end];
		w_v[end]=temp;
		w[end]=temp1;
		v[end]=temp2;
		start++;
		if(start==end)
		break;
		while(start<end&&w_v[start]>w_v[end])
		{
			start++;
		}
		if(start==end)
		break;
		temp=w_v[start];
		temp1=w[start];
		temp2=v[start];
		w_v[start]=w_v[end];
		w[start]=w[end];
		v[start]=v[end];
		w_v[end]=temp;
		w[end]=temp1;
		v[end]=temp2;
		end--;
	}
	sort(i,start-1);
	sort(end+1,j);
	return;
}
void get_down()        //获取下界 
{
	down=0;
	int wight=0;
	for(int i=0;i<n;i++)
	{
		wight=wight+w[i];
		if(wight<=W)
		{
			down=down+v[i];
		}
		else
		break;
	} 
	return;
}
void get_up()            //获取上界 
{
	up=w_v[0]*n;
	return;
}
int get_ub(Node node)        //获取目标函数值 
{
  	node.ub=node.v+w_v[node.index+1]*(W-node.w);
  	return node.ub;
}
void solve()
{
	get_down();
	get_up();
	Node first;      //定义起点 
	first.index=-1;
	first.ub=up;
	first.v=0;
	first.w=0;
	pp.push(first);
	int ret=0;
	while(pp.size())
	{
		
		Node tmp=pp.top();
		pp.pop();
		if(tmp.index==n-2)
		{
			int ans=tmp.v;
			if(tmp.w+w[tmp.index+1]<=W)
			ans=ans+v[tmp.index+1];
			if(ans>=tmp.ub)      //价值大于全部目标函数值，直接得出最优解 
			{
				ret=ans;
				break;
			}
			else
			{
				if(ans>down)           //更新下界 
				down=ans;
				if(ans>ret)
				ret=ans;
				continue;
			}
		}
		Node next;
		for(int i=0;i<2;i++)
		{
			next.index=tmp.index+1;
			next.v=tmp.v+i*v[tmp.index+1];
			next.w=tmp.w+i*w[tmp.index+1];
			next.ub=get_ub(next);
			if(next.w<=W&&next.ub>=down)      //大于下界且容量小于背包容量入队列 
					pp.push(next);
		}
	}
  printf("最优解为：%d\n",ret);
}
main()
{
	printf("请输入背包容量：");
	scanf("%d",&W);
	printf("请输入物品数量：");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("请输入物品重量和价值（格式如 1 2 ）：");
		scanf("%d %d",&w[i],&v[i]);
		w_v[i]=v[i]/w[i];
		if(v[i]%w[i]!=0)
		w_v[i]+=1;
	 } 
	 sort(0,n-1);
	 solve();
}
#include<stdio.h>
#include<iostream>
#include<queue>          //优先队列头文件 
using namespace std;
typedef struct Node
{
	int ub;
	int w;
	int v;
	int index;
    bool operator < (const Node &p)const     //大根堆 
    {
    	p.ub>ub;
	}
 }Node;
#define maxNum 10        //物品最大值 
 int w[maxNum];          //存放物品 
 int v[maxNum];          //存放价值 
 int w_v[maxNum];        //存放性价比 
 priority_queue<Node> pp;     
 int W;                  //背包容量 
 int up;                 //上界 
 int down;               //下界 
 int n;                  //物品数 
void sort(int i,int j)     //对存储数组由大到小排序，此处采用快速排序 
{
	int start=i;
	int end=j;
	if(start>=end)
	{
		return;	
	}
	while(start!=end)
	{
		int temp;
		int temp1;
		int temp2;
		while(start<end&&w_v[start]>w_v[end])
		{
		end--;
		}
		if(start==end)
		break;
		temp=w_v[start];
		temp1=w[start];
		temp2=v[start];
		w_v[start]=w_v[end];
		w[start]=w[end];
		v[start]=v[end];
		w_v[end]=temp;
		w[end]=temp1;
		v[end]=temp2;
		start++;
		if(start==end)
		break;
		while(start<end&&w_v[start]>w_v[end])
		{
			start++;
		}
		if(start==end)
		break;
		temp=w_v[start];
		temp1=w[start];
		temp2=v[start];
		w_v[start]=w_v[end];
		w[start]=w[end];
		v[start]=v[end];
		w_v[end]=temp;
		w[end]=temp1;
		v[end]=temp2;
		end--;
	}
	sort(i,start-1);
	sort(end+1,j);
	return;
}
void get_down()        //获取下界 
{
	down=0;
	int wight=0;
	for(int i=0;i<n;i++)
	{
		wight=wight+w[i];
		if(wight<=W)
		{
			down=down+v[i];
		}
		else
		break;
	} 
	return;
}
void get_up()            //获取上界 
{
	up=w_v[0]*n;
	return;
}
int get_ub(Node node)        //获取目标函数值 
{
  	node.ub=node.v+w_v[node.index+1]*(W-node.w);
  	return node.ub;
}
void solve()
{
	get_down();
	get_up();
	Node first;      //定义起点 
	first.index=-1;
	first.ub=up;
	first.v=0;
	first.w=0;
	pp.push(first);
	int ret=0;
	while(pp.size())
	{
		
		Node tmp=pp.top();
		pp.pop();
		if(tmp.index==n-2)
		{
			int ans=tmp.v;
			if(tmp.w+w[tmp.index+1]<=W)
			ans=ans+v[tmp.index+1];
			if(ans>=tmp.ub)      //价值大于全部目标函数值，直接得出最优解 
			{
				ret=ans;
				break;
			}
			else
			{
				if(ans>down)           //更新下界 
				down=ans;
				if(ans>ret)
				ret=ans;
				continue;
			}
		}
		Node next;
		for(int i=0;i<2;i++)
		{
			next.index=tmp.index+1;
			next.v=tmp.v+i*v[tmp.index+1];
			next.w=tmp.w+i*w[tmp.index+1];
			next.ub=get_ub(next);
			if(next.w<=W&&next.ub>=down)      //大于下界且容量小于背包容量入队列 
					pp.push(next);
		}
	}
  printf("最优解为：%d\n",ret);
}
main()
{
	printf("请输入背包容量：");
	scanf("%d",&W);
	printf("请输入物品数量：");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("请输入物品重量和价值（格式如 1 2 ）：");
		scanf("%d %d",&w[i],&v[i]);
		w_v[i]=v[i]/w[i];
		if(v[i]%w[i]!=0)
		w_v[i]+=1;
	 } 
	 sort(0,n-1);
	 solve();
}
