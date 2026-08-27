class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); ++i){
            int left = i + 1;
            int right = numbers.size() - 1;
            int tmp = target - numbers[i];
            //Binary search to look fo target
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(numbers[mid] == tmp){
                    return {i + 1, mid + 1};
                }
                else if (numbers[mid] < tmp){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return {};
    }
};
