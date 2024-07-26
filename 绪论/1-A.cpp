#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

//czq��ϲ��lowbit����������������Լ���n�������µ����һλ1��ֵ 
int lowbit(int n)
{
	return n & -n;
}

//���������ص��Գ����ж����� 
bool checkprime1(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	return true;
}

//�Գ�����һ�ָĽ� 
bool checkprime2(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

//�ݹ������ͼ���ǰn��� 
double f(int n)
{
	if (n == 0)
		return 0;
	else
		return f(n - 1) + 1 / (double)n;
}

//ͳ��n��������1�ĸ��� 
int bitcount(int n)
{
	int ans = 0;
	while (n)
	{
		ans += (n & 1);
		n >>= 1;
	}
	return ans;
}

//����ݹ麯�����ڶ�������� 
int getsum(int a[], int l, int r)
{
	if (l == r)
		return a[l];
	int mid = (l + r) >> 1;
	return getsum(a, l, mid) + getsum(a, mid + 1, r);
}

//������������Ȼ��Ϊʲô�е�����������Ϊsort����ֻʹ�ÿ��������Ҹ��Ӷ�Ϊƽ�����Ӷȡ� 
void mysort(int a[], int l, int r)
{
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	mysort(a, l, mid);
	mysort(a, mid + 1, r);
	sort(a + l, a + r + 1);
}


//���������Ժ���ү��Ͼʱ����������Node.js���Ժ�C���Ե��ٶȲ�ࡣ�ú���������쳲��������еĵ�x��
long long int fibonacci(int _Xx) {
	if (_Xx <= 2) return 1;
	return fibonacci(_Xx - 1) + fibonacci(_Xx - 2);
}

//���ʱ�临�Ӷ�
int main()
{
	printf("1\n");
	printf("n\n");
	printf("sqrt(n)\n");
	printf("n\n");
	printf("logn\n");
	printf("n\n");
	printf("nlog2n\n");
	printf("2n\n");
	return ~~(0 ^ _ ^ 0);
}