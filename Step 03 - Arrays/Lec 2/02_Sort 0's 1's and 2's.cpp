// Question Link - https://leetcode.com/problems/sort-colors/
// Sort Colors


// Method - 1
// T.C = O(N) + O(N)
// S.C = O(1)
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int cnt_0 = 0, cnt_1=0;
        for (int i=0; i<arr.size(); i++) {
            if(arr[i] == 0) {
                cnt_0++;
            } else if(arr[i] == 1) {
                cnt_1++;
            }
        }

        for(int i=0; i<arr.size(); i++) {
            if(cnt_0 > 0) {
                arr[i]=0;
                cnt_0--;
            }
            else if(cnt_1 > 0) {
                arr[i]=1;
                cnt_1--;
            }
            else {
                arr[i]=2;
            }

        }
    }
};




// Mehtod - 2 (Dutch National Flag Algorithm)
// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size()-1;
        while(mid <= high) {
            if(arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid] == 1) {
                mid++;
            }
            else {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};
