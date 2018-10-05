#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[];
int binary_search(int num) {
    int l = 0;
    int r = n-1;
    // 이분 탐색
    while (l <= r) {
        int mid = (l+r)/2;
        if (a[mid] == num) {
            return 1;
        } else if (a[mid] > num) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return 0;
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    scanf("%d",&m); // 탐색 횟수 입력
    while (m--) {
        int num;
        scanf("%d",&num);
        printf("%d ",binary_search(num));
    }
    printf("\n");
    return 0;
}

// 공유기 설치 문제
// 인접한 공유기 사이의 거리를 최대로
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool possible(vector<int> &a, int c, int x) {
    int cnt = 1;
    int last = a[0];
    for (int house : a) {
        if (house - last >= x) {
            cnt += 1;
            last = house;
        }
    }
    return cnt >= c;
}
int main() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 1;
    int r = a[n-1] - a[0];
    int ans = l;
    while(l <= r) {
        int mid = (l+r)/2;
        if (possible(a, c, mid)) {
            if (ans < mid) {
                ans = mid;
            }
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}