using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Rextester
{
    public class Program
    {
        static int[] Getarray(int[] arr, int low, int high) {
            var result = new int[high-low+1]; 
            for (int i = low; i <= high; ++i) {
                result[i-low] = arr[i];
            }
            return result;
        }
        
        static int[] Maxcross(int[] arr, int low, int mid, int high) {
            int index1 = mid;
            int index2 = mid + 1;
            int leftsum = arr[mid];
            int rightsum = arr[mid+1];
            int tem1 = 0;
            int tem2 = 0;
            for (int i = mid; i >= 0; --i) {
                tem1 += arr[i];
                if (tem1 > leftsum) {
                    leftsum = tem1;
                    index1 = i;
                }
            }
            for (int i = mid + 1; i <= high; ++i) {
                tem2 += arr[i];
                if (tem2 > rightsum) {
                    rightsum = tem2;
                    index2 = i;
                }
            }
            var result = new int[] {leftsum+rightsum,index1, index2};
            return result;
        }
            
        static int[] Maxsubarray (int[] arr, int low, int high) {
            var result = new int[3];
            if (low == high) {
                result[0] = arr[0];
                result[1] = low;
                result[2] = high;
                return result;
            }
            else {
                int mid = (arr.Length)/2 - 1;
                //Console.WriteLine($"MID {mid} LOW {low} High {high}");
                var maxleft = Maxsubarray(Getarray(arr,low,mid),0,mid-low);
                var maxright = Maxsubarray(Getarray(arr,mid+1,high),0,high-mid-1);
                var maxcross = Maxcross(arr,low,mid,high);
                if ((maxleft[0] >= maxright[0]) && (maxleft[0] >= maxcross[0])) {
                    result[0] = maxleft[0];
                    result[1] = maxleft[1];
                    result[2] = maxleft[2];
                }
                else if ((maxright[0] >= maxleft[0]) && (maxright[0] >= maxcross[0])) {
                    result[0] = maxright[0];
                    result[1] = maxright[1];
                    result[2] = maxright[2];
                }
                else {
                    result[0] = maxcross[0];
                    result[1] = maxcross[1];
                    result[2] = maxcross[2];
                }
                return result;
            }
        }
        
        public static void Main(string[] args)
        {
            int[] arr = {13,3,25,20,3,-6,-23,-18,-20,-7,-12,-5,-22,15,-4,7};
            foreach (int r in Maxsubarray(arr,0,arr.Length-1)) {
                Console.WriteLine(r);
            }
        }
    }
}

//C++ Linear Runtime 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestsum = nums[0];
        int currsum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            currsum += nums[i];
            bestsum = max(bestsum,currsum);
            currsum = max(0, currsum);
        }
        return bestsum;
    }
};
