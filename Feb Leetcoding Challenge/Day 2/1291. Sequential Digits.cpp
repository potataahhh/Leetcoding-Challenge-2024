
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        vector<int> res;

        for(int i=2;i<=str.length();i++){
            for(int start = 0;start<= str.length()-i;start++){
                string str2 = str.substr(start,i);
                int temp = stoi(str2);

                if(temp>=low && temp<=high)
                res.push_back(temp);
            }
        }
        return res;
    }
};
