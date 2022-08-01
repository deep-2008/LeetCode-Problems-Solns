class Solution {
    void mergeSort(vector<int>& nums,int l,int h,int mid){
       int n1=mid-l+1;
        int n2=h-mid;
        
        int a[n1],b[n2];
        
        for(int i=0;i<n1;i++){
            a[i]=nums[l+i];
        }
         
        for(int i=0;i<n2;i++){
            b[i]=nums[mid+1+i];
        }
        
        int i=0,j=0,k=l;
        
        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                nums[k++]=a[i++];
            }
            
            else
                nums[k++]=b[j++];
        }
        
        while(i<n1)
            nums[k++]=a[i++];
        
        while(j<n2)
            nums[k++]=b[j++];
    }
    
    void sortedArray(vector<int>& nums,int head,int tail){
        if(head>=tail){
            return ;
        }
        
        int mid=head+(tail-head)/2;
        
        sortedArray(nums,head,mid);
        sortedArray(nums,mid+1,tail);
        
         mergeSort(nums,head,tail,mid);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        //Selection sort
//         for(int i=0;i<nums.size()-1;i++){
//             int min=i;
            
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[j]<nums[min]){
//                     min=j;
//                 }
//             }
//             swap(nums[i],nums[min]);
//         }
//         return nums;
        
        //merge sort
         sortedArray(nums,0,nums.size()-1);
        return nums;
    }
};
        
        
//         //Insertion sort
        
//         for(int i=1;i<nums.size();i++){
//             for(int j=i-1;j>=0;j--){
//                 if(nums[j]>nums[j+1])
//                     swap(nums[j+1],nums[j]);
//                 else
//                     break;
//             }
//         }
//         return nums;
//     }
// };


//QUICKSORT
// class Solution{
//     int partition(vector<int>& nums,int l,int h,int pivot){
//         int j=l;
        
//         while(l<=h){
//             if(nums[l]>pivot)
//                 l++;
            
//             else{
//                 swap(nums[l],nums[j]);
//                 l++;
//                 j++;
//             }
//         }
//         return j-1;
//     }
    
//     void quickSort(vector<int>& nums,int l,int h){
//         if(l>=h)
//             return;
        
//         int pivot=nums[h];
        
//         int pi=partition(nums,l,h,pivot);
//         quickSort(nums,l,pi-1);
//         quickSort(nums,pi+1,h);
//     }
//     public:
//      vector<int> sortArray(vector<int>& nums){
//          int h=nums.size()-1;
         
//          quickSort(nums,0,h);
//          return nums;
//      }

// };