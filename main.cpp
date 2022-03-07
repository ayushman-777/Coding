#include<bits/stdc++.h>

using namespace std;

string reverseWord(string str) {
    auto end = str.size() - 1;
    auto start = 0;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return str;
}

int kthSmallest(int arr[], int l, int r, int k) {
    sort(arr, arr + r + 1);
    return arr[k - 1];
}

void sort012(int a[], int n) {
    multiset<int> ms;
    for (int i = 0; i < n; ++i) {
        ms.insert(a[i]);
    }
    int j = 0;
    for (int m: ms) {
        a[j] = m;
        j++;
    }
}

void rearrange(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            int j = i + 1;
            while (j < n) {
                if (arr[j] < 0) {
                    swap(arr[i], arr[j]);
                    break;
                }
                j++;
            }
            if (j == n) {
                break;
            }
        }
    }
}

int doUnion(int a[], int n, int b[], int m) {
    int big = n < m ? m : n;
    set<int> s;
    for (int i = 0; i < big; i++) {
        if (i < n) {
            s.insert(a[i]);
        }
        if (i < m) {
            s.insert(b[i]);
        }
    }
    return s.size();
}

void rotate(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        swap(arr[i], arr[i - 1]);
    }
}

int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr + n);
    int result = arr[n - 1] - arr[0] - (2 * k);
    int minEle, maxEle;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= k) {
            maxEle = max(arr[n - 1] - k, arr[i] + k);
            minEle = min(arr[0] + k, arr[i] - k);
            result = min(result, maxEle - minEle);
        }
    }
    return result;
}

int minJumps(int arr[], int n) {
    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;
    int maxJump = arr[0];
    int step = arr[0];
    int jumpCounter = 1;
    int i;
    for (i = 1; i < n; i++) {
        if (i == n - 1)
            return jumpCounter;
        maxJump = max(maxJump, i + arr[i]);
        step--;
        if (step == 0) {
            jumpCounter++;
            if (i >= maxJump)
                return -1;
            step = maxJump - i;
        }
    }
    return -1;
}

int findDuplicate(vector<int> &nums) {
    auto count_less_equal = [&](int i) {
        int count = 0;
        for (auto &num: nums) {
            if (num <= i) {
                count++;
            }
        }
        return count;
    };
    int low = 0, high = nums.size();
    int duplicate = -1;
    while (low <= high) {
        int cur = (low + high) / 2;
        if (count_less_equal(cur) > cur) {
            duplicate = cur;
            high = cur - 1;
        } else {
            low = cur + 1;
        }
    }
    return duplicate;
}

//void merge(int arr1[], int arr2[], int n, int m) {
//    int i = 0;
//    while (arr1[n - 1] > arr2[0]) {
//        if (arr1[i] > arr2[0]) {
//            swap(arr1[i], arr2[0]);
//            sort(arr2, arr2 + n);
//        }
//        i++;
//    }
//}

void merge(long long arr1[], long long arr2[], int m, int n) {
    for (int i = n - 1; i >= 0; i--) {
        int j;
        long long last = arr1[m - 1];
        for (j = m - 2; j >= 0 && arr1[j] > arr2[i]; j--) {
            arr1[j + 1] = arr1[j];
        }
        if (j != m - 2 || last > arr2[i]) {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
    }
}

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    for (auto interval: intervals) {
        if (res.empty() || res.back()[1] < interval[0]) {
            res.push_back(interval);
        } else {
            res.back()[1] = max(res.back()[1], interval[1]);
        }
    }
    return res;
}

void nextPermutation(vector<int> &nums) {
    if (nums.size() == 1) {
        return;
    }
    int idx1 = -1;
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i + 1] > nums[i]) {
            idx1 = i;
            break;
        }
    }
    if (idx1 == -1) {
        reverse(nums.begin(), nums.end());
    } else {
        int idx2 = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[idx1] < nums[i]) {
                idx2 = i;
                break;
            }
        }
        swap(nums[idx1], nums[idx2]);
        sort(nums.begin() + idx1 + 1, nums.end());
    }
}

long long int inversionCount(long long arr[], long long n) {
    vector<long long> temp;
    copy(arr, arr + n, back_inserter(temp));
    sort(temp.begin(), temp.end());
    long long int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > temp[i]) {
            for (int j = i; j < n; ++j) {
                if (arr[i] == temp[j]) {
                    break;
                } else {
                    count++;
                }
            }
        }
    }
    return count;
}

int maxProfit(vector<int> &prices) {
    int maxP = 0;
    auto temp = max_element(prices.begin(), prices.end());
    for (int i = 0; i < prices.size() - 1; ++i) {
        if (*temp == prices[i] && prices[i] != 0) {
            temp = max_element(prices.begin() + i + 1, prices.end());
        }
        maxP = max(maxP, *temp - prices[i]);
    }
    return maxP;
}

int getPairsCount(int arr[], int n, int k) {
    unordered_map<int, int> set1;
    for (int i = 0; i < n; ++i) {
        set1[arr[i]]++;
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        count += set1[k - arr[i]];
        if (k - arr[i] == arr[i]) {
            count--;
        }
    }
    return count / 2;
}

struct present {
    bool first = false, second = false, third = false;
};

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
    map<int, present> mp;
    int n = max(n1, max(n2, n3));
    for (int i = 0; i < n; ++i) {
        if (i < n1) {
            mp[A[i]].first = true;
        }
        if (i < n2) {
            mp[B[i]].second = true;
        }
        if (i < n3) {
            mp[C[i]].third = true;
        }
    }
    vector<int> res;
    for (auto m: mp) {
        if (m.second.first && m.second.second && m.second.third) {
            res.push_back(m.first);
        }
    }
    return res;
}

vector<int> commonElements2(int A[], int B[], int C[], int n1, int n2, int n3) {
    int i, j, k;
    int temp1, temp2, temp3;
    vector<int> ans;
    temp1 = temp2 = temp3 = INT_MIN;
    while (i < n1 && j < n2 && k < n3) {
        while (A[i] == temp1 && i < n1) {
            i++;
        }
        while (B[j] == temp2 && i < n2) {
            j++;
        }
        while (C[k] == temp3 && k < n3) {
            k++;
        }
        if (A[i] == B[j] && B[j] == C[k]) {
            ans.push_back(A[i]);
            temp1 = A[i];
            temp2 = B[j];
            temp3 = C[k];
            i++;
            j++;
            k++;

        } else if (A[i] < B[j]) {
            temp1 = A[i];
            i++;
        } else if (B[j] < C[k]) {
            temp2 = B[j];
            j++;
        } else {
            temp3 = C[k];
            k++;
        }
    }
    return ans;
}

bool subArrayExists(int arr[], int n) {
    unordered_set<int> us;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (arr[i] == 0 || us.find(sum) != us.end()) return true;
        us.insert(sum);
    }
    return false;
}

int multiply(int x, int res[], int res_size) {
    int carry = 0;
    for (int i = 0; i < res_size; i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry) {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

vector<int> factorial(int n) {
    int res[7000];
    res[0] = 1;
    int res_size = 1;
    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);
    vector<int> vec;
    for (int i = res_size - 1; i >= 0; i--)
        vec.push_back(res[i]);
    return vec;
}

long long maxProduct(vector<int> arr, int n) {
    long long min_ending_here = 1, max_ending_here = 1, max_so_far = 0;
    for (int i = 0; i < n; ++i) {
        long long temp = max({(long long) arr[i], max_ending_here * arr[i], min_ending_here * arr[i]});
        min_ending_here = min({(long long) arr[i], max_ending_here * arr[i], min_ending_here * arr[i]});
        max_ending_here = temp;
        max_so_far = max(max_ending_here, max_so_far);
    }
    return max_so_far;
}

int findLongestConseqSubseq(int arr[], int n) {
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s.find(arr[i] - 1) == s.end()) {
            int j = arr[i];
            while (s.find(j) != s.end()) {
                j++;
            }
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}

int maxProfit2(int price[], int n) {
    vector<int> profit(n, 0);
    int maxPrice = price[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        if (price[i] > maxPrice) {
            maxPrice = price[i];
        }
        profit[i] = max(profit[i + 1], maxPrice - price[i]);
    }
    int minPrice = price[0];
    for (int i = 1; i < n; ++i) {
        if (price[i] < minPrice) {
            minPrice = price[i - 1];
        }
        profit[i] = max(profit[i - 1], profit[i] + (price[i] - minPrice));
    }
    return profit[n - 1];
}

int maxProfit(int price[], int n) {
    vector<int> profit(n, 0);
    int max_profit = price[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (price[i] > max_profit) {
            max_profit = price[i];
        }
        profit[i] = max(profit[i + 1], max_profit - price[i]);
    }
    int min_price = price[0];
    for (int i = 1; i < n; ++i) {
        if (price[i] < min_price) {
            min_price = price[i];
        }
        profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_price));
    }
    return profit[n - 1];
}

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(a1[i]);
    }
    for (int i = 0; i < m; ++i) {
        if (s.find(a2[i]) != s.end()) {
        } else {
            return "No";
        }
    }
    return "Yes";
}

bool find3Numbers(int A[], int n, int X) {

    sort(A, A + n);

    int l, r;

    for (int i = 0; i < n; ++i) {
        l = i + 1;
        r = n - 1;
        while (l < r) {
            if (A[l] + A[r] + A[i] == X) {
                return true;
            } else if (A[l] + A[r] + A[i] < X) {
                l++;
            } else {
                r--;
            }
        }
    }
    return false;
}

long long trappingWater3(int arr[], int n) {
    long long water = 0;
    int leftMax = 0, rightMax = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (arr[l] < arr[r]) {
            water += max(0, leftMax - arr[l]);
            leftMax = max(leftMax, arr[l]);
            l++;
        } else {
            water += max(0, rightMax - arr[r]);
            rightMax = max(rightMax, arr[r]);
            r--;
        }
    }
    return water;
}

long long trappingWater2(int arr[], int n) {
    long long water = 0;
    int leftMax = 0, rightMax = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (arr[l] < arr[r]) {
            if (arr[l] > leftMax) {
                leftMax = arr[l];
            } else {
                water += leftMax - arr[l];
            }
            l++;
        } else {
            if (arr[r] > rightMax) {
                rightMax = arr[r];
            } else {
                water += rightMax - arr[r];
            }
            r--;
        }
    }
    return water;
}

long long trappingWater(int arr[], int n) {
    int left[n], right[n], water = 0;

    left[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        left[i] = max(left[i - 1], arr[i]);
    }

    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        water += min(left[i], right[i]) - arr[i];
    }
    return water;
}

long long findMinDiff(vector<long long> a, long long n, long long m) {
    sort(a.begin(), a.end());
    long long minDiff = a[m - 1] - a[0];
    for (long long i = 1; i <= n - m; ++i) {
        minDiff = min(minDiff, a[i + m - 1] - a[i]);
        cout << minDiff << endl;
    }
    return minDiff;
}

int smallestSubWithSum(int arr[], int n, int x) {
    int sum = 0, i = -1, ans = INT_MAX;
    for (int j = 0; j < n; ++j) {
        while (sum <= x && i < n - 1) {
            i++;
            sum += arr[i];
        }
        if (sum > x) ans = min(ans, i - j + 1);
        sum -= arr[j];
    }
    return ans > n - 1 ? -1 : ans;
}

void threeWayPartition(vector<int> &array, int a, int b) {
    if (b >= a) {
        sort(array.begin(), array.end());
    } else {
        reverse(array.begin(), array.end());
    }
}

int minSwap(int arr[], int n, int k) {
    int count = 0, bad = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] <= k) {
            count++;
        }
    }
    for (int i = 0; i < count; ++i) {
        if (arr[i] > k) {
            bad++;
        }
    }
    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j) {
        if (arr[i] > k) {
            --bad;
        }
        if (arr[j] > k) {
            ++bad;
        }
        ans = min(ans, bad);
    }
    return ans;
}

bool isPalin(int n) {
    vector<int> no;
    int temp = n;
    while (temp) {
        no.push_back(temp % 10);
        temp = temp / 10;
    }
    int l = 0, r = no.size() - 1;
    while (l < r) {
        if (no[l] != no[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int find_median(vector<int> v) {
    sort(v.begin(), v.end());
    int n = v.size();
    if (v.size() % 2 == 0) {
        return ((v[(n - 1) / 2] + v[n / 2]) / 2);
    }
    return v[n / 2];
}

int PalinArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (!isPalin(a[i])) {
            return 0;
        }
    }
    return 1;
}

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) {
    vector<int> ans;
    int i = 0, j = 0;
    int val = 0;
    while (true) {
        if (val == 0) {
            int k;
            for (k = i; k < c && matrix[i][k] != -1; ++k) {
                ans.push_back(matrix[i][k]);
                matrix[i][k] = -1;
            }
            val = 1;
            i++;
            j = k - 1;
        } else if (val == 1) {
            int k;
            for (k = i; k < r && matrix[k][j] != -1; ++k) {
                ans.push_back(matrix[k][j]);
                matrix[k][j] = -1;
            }
            val = 2;
            j--;
            i = k - 1;
        } else if (val == 2) {
            int k;
            for (k = j; k >= 0 && matrix[i][k] != -1; --k) {
                ans.push_back(matrix[i][k]);
                matrix[i][k] = -1;
            }
            val = 3;
            i--;
            j = k + 1;
        } else {
            int k;
            for (k = i; i >= 0 && matrix[k][j] != -1; k--) {
                ans.push_back(matrix[k][j]);
                matrix[k][j] = -1;
            }
            val = 0;
            j++;
            i = k + 1;
        }
        if (i >= (r) || j >= (c) || matrix[i][j] == -1) {
            break;
        }
    }
    return ans;
}

int matSearch(vector<vector<int>> &mat, int n, int m, int x) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (mat[i][m - 1] >= x) {
            ans = binary_search(mat[i].begin(), mat[i].end(), x);
        }
        if (ans != 0) {
            return 1;
        }
    }
    return 0;
}

int median(vector<vector<int>> &matrix, int r, int c) {
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < r; ++i) {
        if (matrix[i][0] < min) {
            min = matrix[i][0];
        }
        if (matrix[i][c - 1] > max) {
            max = matrix[i][c - 1];
        }
    }
    int desired = (r * c + 1) / 2, place, mid;
    while (min < max) {
        mid = min + (max - min) / 2;
        place = 0;
        for (int i = 0; i < r; ++i)
            place += (upper_bound(matrix[i].begin(), matrix[i].end(), mid)) - (matrix[i].begin());
        if (place < desired) {
            min = mid + 1;
        } else {
            max = mid;
        }
    }
    return min;
}
//
//int median(vector<vector<int>> &matrix, int r, int c){
//    long long int  l=1,h=1e18;
//    while(l<=h)
//    {
//        long long int mid=l+(h-l)/2,t=0;
//
//        for(int i=0;i<r;i++)
//        {
//            auto it=upper_bound(matrix[i].begin(),matrix[i].end(),mid);
//            t=t+it-matrix[i].begin();
//        }
//        if(t<=(r*c)/2) l=mid+1;
//        else h=mid-1;
//    }
//    return l;
//}

int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
    int countZero = 0, ans, minZeros = INT_MAX;
    for (int i = 0; i < n; ++i) {
        countZero = upper_bound(arr[i].begin(), arr[i].end(), 0) - arr[i].begin();
        if (countZero < minZeros) {
            minZeros = countZero;
            ans = i;
        }
    }
    if (minZeros == m) {
        return -1;
    }
    return ans;
}

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
    vector<int> rix;
    for (auto m: Mat) {
        for (auto v: m) {
            rix.push_back(v);
        }
    }
    sort(rix.begin(), rix.end());
    int i = 0, j = 0;
    for (auto ele: rix) {
        Mat[i][j] = ele;
        if (j == N - 1) {
            i++;
            j = 0;
        } else {
            j++;
        }
    }
    return Mat;
}

void printArray(vector<int> arr) {
    int size = arr.size();
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void printArray(vector<string> arr) {
    int size = arr.size();
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void mergeArrays(vector<int> &vector1, vector<int> &vector2, unsigned int size1, unsigned int size2, vector<int> &vector3) {
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (vector1[i] < vector2[j]) {
            vector3.push_back(vector1[i]);
            i++;
        } else {
            vector3.push_back(vector2[j]);
            j++;
        }
    }
    while (i < size1) {
        vector3.push_back(vector1[i]);
        i++;
    }
    while (j < size2) {
        vector3.push_back(vector2[j]);
        j++;
    }
}

void mergeKArrays(vector<vector<int>> &arr, int i, int j, vector<int> &output) {
    if (i == j) {
        for (int k = 0; k < arr[i].size(); ++k) {
            output.push_back(arr[i][k]);
        }
        return;
    }
    if (j - i == 1) {
        mergeArrays(arr[i], arr[j], arr[i].size(), arr[j].size(), output);
        return;
    }

    vector<int> out1, out2;

    mergeKArrays(arr, i, (i + j) / 2, out1);
    mergeKArrays(arr, ((i + j) / 2) + 1, j, out2);

    mergeArrays(out1, out2, out1.size(), out2.size(), output);
}

vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
    vector<int> res;
    mergeKArrays(arr, 0, k - 1, res);
    return res;
}

int getMaxArea(int arr[], int n) {
    int ans = 0;
    int left[n], right[n];
    stack<int> st1, st2;
    st1.push(0);
    left[0] = 0;
    st2.push(n - 1);
    right[n - 1] = n - 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] <= arr[st1.top()]) {
            while (!st1.empty() && arr[i] <= arr[st1.top()]) {
                st1.pop();
            }
            if (st1.empty()) {
                left[i] = 0;
                st1.push(i);
            } else {
                left[i] = st1.top() + 1;
                st1.push(i);
            }
        } else {
            left[i] = st1.top() + 1;
            st1.push(i);
        }
        if (arr[n - 1 - i] <= arr[st2.top()]) {
            while (!st2.empty() && arr[n - 1 - i] <= arr[st2.top()]) {
                st2.pop();
            }
            if (st2.empty()) {
                right[n - 1 - i] = n - 1;
                st2.push(n - 1 - i);
            } else {
                right[n - 1 - i] = st2.top() - 1;
                st2.push(n - 1 - i);
            }
        } else {
            right[n - 1 - i] = st2.top() - 1;
            st2.push(n - 1 - i);
        }
    }
    long long cal;
    for (int i = 0; i < n; ++i) {
        cal = (right[i] - left[i] + 1) * arr[i];
        if (ans < cal) {
            ans = cal;
        }
    }
    return ans;
}

int maxArea(int M[4][4], int n, int m) {
    int ans = 0;
    ans = max(ans, getMaxArea(M[0], m));
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M[i][j] != 0) { M[i][j] += M[i - 1][j]; }
        }
        ans = max(ans, getMaxArea(M[i], m));
    }
    return ans;
}

int isPalindrome(string S) {
    int n = S.length();
    for (int i = 0; i < n / 2; ++i) {
        if (S[i] != S[n - i - 1]) {
            return 0;
        }
    }
    return 1;
}

string countAndSay(int n) {
    if (n == 1) {
        return "1";
    }
    if (n == 2) {
        return "11";
    }
    string old = countAndSay(n - 1), res;
    int count = 1;
    int i;
    for (i = 1; i < old.length(); ++i) {
        if (old[i - 1] == old[i]) {
            count++;
        } else {
            res += to_string(count);
            res += old[i - 1];
            count = 1;
        }
    }
    res += to_string(count);
    res += old[i - 1];
    return res;
}

string longestPalin(string s) {
    string ans;
     if (s[0] == s[1]) ans = s.substr(0, 2);
     else ans += s[0];
    int count, temp;
    for (int i = 1; i < s.length() - 1; ++i) {
        temp = i;
        count = 1;
        while (temp-- && (i + count + 1) < s.length() && s[i - count] == s[i + count + 1]) {
            count++;
        }
        if (ans.length() < ((2 * (count - 1)) + 2)) {
            ans = s.substr((i - (count - 1)), ((2 * (count - 1)) + 2));
        }
        temp = i;
        count = 1;
        while (temp-- && (i + count) < s.length() && s[i - count] == s[i + count]) {
            count++;
        }
        if (ans.length() < ((2 * (count - 1)) + 1)) {
            ans = s.substr((i - (count - 1)), (2 * (count - 1)) + 1);
        }
    }
    return ans;
}

void printSubsequence(string input, string output)
{
    if (input.empty()) {
        cout << output << endl;
        return;
    }

    printSubsequence(input.substr(1), output + input[0]);
    printSubsequence(input.substr(1), output);
}



void printSubsequence2(string input, string output, int ind)
{
    if (ind == input.size()) {
        cout << output << endl;
        return;
    }
    output.push_back(input[ind]);
    printSubsequence2(input, output, ind+1);
    output.pop_back();
    printSubsequence2(input, output, ind+1);
}

void permutation(string s, string answer, vector<string> &ans) {
    if (s.length() == 0) {
        ans.push_back(answer);
        return;
    }
    for (int i = 0; i < s.length(); ++i) {
        char ch = s[i];
        string left_substr = s.substr(0,i);
        string right_substr = s.substr(i+1);
        string rest = left_substr + right_substr;
        permutation(rest , answer+ch, ans);
    }
}

vector<string> find_permutation(string s) {
    vector<string> ans;
    permutation(s, "", ans);
    sort(s.begin(), s.end());
    return ans;
}

int lca(string a, string b, int i, int j) {
    if (i == a.length() || j == b.length()) {
        return 0;
    } else if (a[i] == b[j]) {
        return 1 + lca(a, b, i + 1, j + 1);
    } else {
        return max(lca(a, b, i + 1, j), lca(a, b, i, j + 1));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[4][4] = {{0, 1, 1, 0},
                     {1, 1, 1, 1},
                     {1, 1, 1, 1},
                     {1, 1, 0, 0}};

    int ar1[] = {2, 3, 5, 8};
    int ar2[] = {10, 12, 14, 16, 18, 20};
    vector<string> res1 = find_permutation("abc");
    printArray(res1);
    return 0;
}
