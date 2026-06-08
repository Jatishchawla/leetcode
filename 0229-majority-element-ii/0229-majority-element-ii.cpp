class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // MOORE'S VOTING ALGO
        int n = nums.size();
        // note the below variables does not contain the actual count of ele. in the nums
        int cnt1 = 0; // vote for element 1
        int cnt2 = 0; // vote for element 2

        int el1 = INT_MIN;
        int el2 = INT_MIN;  
        for(int i = 0 ; i<n ; i++ ){
            if(cnt1 == 0 && el2 != nums[i]){
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0 && el1 != nums[i]){
                cnt2=1;
                el2=nums[i];
            }
            else if(el1 == nums[i]  ){
                cnt1++; // vote ++
            }
            else if(el2 == nums[i]){
                cnt2++; // vote ++
            }
            // now below else will carry an indirect condition i.e  
            else{
                // if nums[i] is not equal to any of element , count of both will reduce
                cnt1--; // vote --
                cnt2--; // vote --
            }
        }
        // above loop has given us the two majors only till now 
         

        vector<int> ans;
        int min_cnt = (int) (n/3)+1;
        cnt1=0, cnt2=0;
        for(int i : nums){
            if(el1 == i) {cnt1++;}
            if(el2 == i) {cnt2++;}
        }
        if(cnt1 >= min_cnt ){ans.push_back(el1);};
        if(cnt2 >= min_cnt ){ans.push_back(el2);};
        return ans;


        // ------ MY APPROACH -------
        // sort(nums.begin(),nums.end());
        // vector<int> majors;
        // majors.push_back(INT_MIN); //  adding int min just because check majors.back in empty vector
        // int curr = nums[0]; // current element
        // int curr_count=0; // to store current's occurece count
        // int n = nums.size()/3;
        // for(int i : nums){
        //     if(curr == i){
        //         curr_count++;     
        //     }
        //     else{
        //         curr=i;
        //         curr_count=1;

        //     }
        //     if(curr_count > n && curr != majors.back() ){            
        //         majors.push_back(curr);
        //     }
        // }
        // majors.erase(majors.begin() + 0);
    
        // return majors;
    }
};