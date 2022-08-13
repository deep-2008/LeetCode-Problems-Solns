class Solution {
public:
    string convert(string str, int numRows) {
        
        int n = str.size();
        
        // edge case
        
        if(numRows == 1)
            return str;
      
        bool down = false;
        
        vector<string> arr(numRows, "");
        
        int curr_row = 0;
        
        for(int i = 0; i < n; i++)
        {
            // push into the corresponding row
            
            arr[curr_row].push_back(str[i]);
            
            // change the direction
            
            if(curr_row == 0 || curr_row == numRows - 1)
            {
                down = !down;
            }
            
            // if down == true, move downward
            
            if(down)
            {
                curr_row++;
            }
            
            // if down == false, move upward
            
            else
            {
                curr_row--;
            }     
        }
        
        string res = ""; 
        
        for(int i = 0; i < numRows; i++)
        {
            res += arr[i];
        }
        
        return res;
    }
};