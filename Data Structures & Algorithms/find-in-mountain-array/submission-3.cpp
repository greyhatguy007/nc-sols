/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int lo = 0, hi = arr.length()-1, mid, peak, midv;
        while(lo<=hi) {
            mid = lo + (hi-lo)/2;
            peak = arr.get(mid);
            if(peak<arr.get(mid-1)) hi = mid - 1;
            else if(peak<arr.get(mid+1)) lo = mid + 1;
            else{
                peak = mid;
                break;
            }
        }
        cout << peak;
        lo = 0, hi = peak;
        while(lo<=hi) {
            mid = lo + (hi-lo)/2;
            midv = arr.get(mid);
            if(midv>target) hi = mid - 1;
            else if(midv<target) lo = mid + 1;
            else return mid;
        } 
        
        lo = peak+1, hi = arr.length()-1;
        while(lo<=hi) {
            mid = lo + (hi-lo)/2;
            midv = arr.get(mid);
            if(midv>target) lo = mid + 1;
            else if(midv<target) hi = mid - 1;
            else return mid;
        }
        return -1;
    }
};