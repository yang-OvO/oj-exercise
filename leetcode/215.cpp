class Solution {
public:
    // 返回值为pivot_idx,分成小于集合[l, p-1]，pivot和大于集合[p+1, r]
    size_t lomuto_partition(size_t left, size_t right, vector<int>& nums)
    {
        int pivot = nums[left];
        size_t to_place = left;
        for (size_t i = left+1; i <= right; i++) {
            if (nums[i] < pivot) {
                to_place++;
                swap(nums[to_place], nums[i]);
            }
        }
        swap(nums[to_place], nums[left]);
        return to_place;
    }

    // 返回值为分界点p，分成小于集合[l, p-1]和大于等于集合[p, r]
    size_t lomuto_partition2(size_t left, size_t right, vector<int>& nums)
    {
        int pivot = nums[left];
        for (size_t i = left+1; i <= right; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[left]);
                left++;
            }
        }
        return left;
    }

    // 返回值为分界点p，分成小于等于集合[l, p]和大于等于集合[p+1, r]
    // 并且返回的p有个特点，永远不等于right
    size_t hoare_partition(size_t left, size_t right, vector<int>& nums)
    {
        int pivot = nums[left];
        size_t i = left-1;
        size_t j = right+1;
        while (1) {
            do {
                j--;
            } while(nums[j] > pivot);
            do {
                i++;
            } while(nums[i] < pivot);
            if (i < j) {
                swap(nums[i], nums[j]);
            } else {
                return j;
            }
        }
    }

    // 荷兰旗分区，返回值为分界点{lt, gt}，分为三个集合小于集合[l, lt-1]，等于集合[lt, gt]，和大于集合[gt+1, r]
    pair<size_t, size_t> dijkstra_partition(size_t left, size_t right, vector<int>& nums)
    {
        int pivot = nums[left];
        size_t lt = left, i = lt+1, gt = right;
        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[lt]);
                i++;
                lt++;
            } else if (nums[i] == pivot) {
                i++;
            } else {
                swap(nums[i], nums[gt]);
                gt--;
            }
        }
        return {lt, gt};
    }

    int findKthLargestImplHoare(size_t left, size_t right, vector<int>& nums, int k)
    {
        int len = right+1-left;
        if (len <= 0 || k > len) {
            return -0x3fffffff;
        }
        if (len == 1 && k == 1) {
            return nums[left];
        }
        size_t partition_point = hoare_partition(left, right, nums);
        size_t ge_len = right-partition_point;
        if (k <= (int)ge_len) {
            // 在更大的里面找
            return findKthLargestImplHoare(partition_point+1, right, nums, k);
        } else {
            // 在更小的里面找
            return findKthLargestImplHoare(left, partition_point, nums, k-ge_len);
        }
    }

    int findKthLargestImplLomuto(size_t left, size_t right, vector<int>& nums, int k)
    {
        int len = right+1-left;
        if (len <= 0 || k > len) {
            return -0x3fffffff;
        }
        size_t pivot_idx = lomuto_partition(left, right, nums);
        size_t ge_len = right+1-pivot_idx;
        if (k == (int)ge_len) {
            return nums[pivot_idx];
        } else if (k < (int)ge_len) {
            // 在更大的里面找
            return findKthLargestImplLomuto(pivot_idx+1, right, nums, k);
        } else {
            // 在更小的里面找
            return findKthLargestImplLomuto(left, pivot_idx-1, nums, k-ge_len);
        }
    }

    int findKthLargestImplDijkstra(size_t left, size_t right, vector<int>& nums, int k)
    {
        int len = right+1-left;
        if (len <= 0 || k > len) {
            return -0x3fffffff;
        }
        int pivot = nums[left];
        auto [lt, gt] = dijkstra_partition(left, right, nums);
        size_t gt_len = right-gt;
        size_t eq_len = gt+1-lt;
        if (k <= gt_len) {
            return findKthLargestImplDijkstra(gt+1, right, nums, k);
        } else if (k <= gt_len+eq_len) {
            return pivot;
        } else {
            return findKthLargestImplDijkstra(left, lt-1, nums, k-gt_len-eq_len);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargestImplHoare(0, nums.size()-1, nums, k);
    }
};