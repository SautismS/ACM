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

//czq很喜欢lowbit函数，这个函数可以计算n二进制下的最低一位1的值 
int lowbit(int n)
{
	return n & -n;
}

//这是最朴素的试除法判断素数 
bool checkprime1(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	return true;
}

//试除法的一种改进 
bool checkprime2(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

//递归求解调和级数前n项和 
double f(int n)
{
	if (n == 0)
		return 0;
	else
		return f(n - 1) + 1 / (double)n;
}

//统计n二进制下1的个数 
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

//这个递归函数用于对数组求和 
int getsum(int a[], int l, int r)
{
	if (l == r)
		return a[l];
	int mid = (l + r) >> 1;
	return getsum(a, l, mid) + getsum(a, mid + 1, r);
}

//排序函数。。。然而为什么有点慢？这里认为sort函数只使用快速排序且复杂度为平均复杂度。 
void mysort(int a[], int l, int r)
{
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	mysort(a, l, mid);
	mysort(a, mid + 1, r);
	sort(a + l, a + r + 1);
}


//这个代码出自寒域爷闲暇时候用来测试Node.js语言和C语言的速度差距。该函数用于求斐波那契数列的第x项
long long int fibonacci(int _Xx) {
	if (_Xx <= 2) return 1;
	return fibonacci(_Xx - 1) + fibonacci(_Xx - 2);
}

//输出时间复杂度
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