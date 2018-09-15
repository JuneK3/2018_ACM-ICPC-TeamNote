// LIS : 최장증가수열
// O(N^2)
// O(NlogN)으로 교체가능(http://mygumi.tistory.com/303 참고)

// 백준 11053, 11055 참고
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
    int ans = 0;
	vector<int> a(n); // 값을 입력받을 배열
    // 최장증가수열의 최대길이를 구하는 경우
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	vector<int> d(n); // 값을 저장할 배열
	for(int i=0; i<n; i++)
	{
		d[i]=1; // 처음에는 모두 길이를 1로 초기화
		for(int j=0; j<i; j++)
		{
			if(a[j]<a[i] && d[i]<d[j]+1)
			{
				d[i]=d[j]+1;
			}
		}
		// 최댓값 저장
		if(ans<d[i])
		{
		    ans=d[i];
		}
	}
    /*
    // 최장증가수열의 최대합을 구하는 경우
    for (int i=0; i<n; i++)
	{
    	d[i] = a[i];
    	for (int j=0; j<i; j++)
		{
		    if (a[j] < a[i] && d[j]+a[i] > d[i])
		    {
			    d[i] = d[j]+a[i];
		    }
    	}
    	// 최댓값 저장
    	if(ans<d[i])
    	{
           	 ans=d[i];
    	}
    }
    */
    // max_element함수는 배열의 최대값의 이터레이터를 반환하므로 값을 참조하기 위해서는 *를 붙여서 사용
    // #include <algorithm> 필요
    // cout << *max_element(d.begin(), d.end()) << '\n'; // 최대길이 or 최대합 출력
    cout << ans << '\n'; // 최대길이 or 최대합 출력
	return 0;
}
