class Solution {
public:
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

    void QuickSortImplLomuto(size_t left, size_t right, vector<int>& nums)
    {
        if (left >= right) {
            return;
        }
        auto p = lomuto_partition(left, right, nums);
        if (p > left) QuickSortImplLomuto(left, p-1, nums); // 避免underflow
        QuickSortImplLomuto(p+1, right, nums);
    }

    void QuickSortImplHoare(size_t left, size_t right ,vector<int>& nums)
    {
        if (left >= right) {
            return;
        }
        auto p = hoare_partition(left, right, nums);
        QuickSortImplHoare(left, p, nums);
        QuickSortImplHoare(p+1, right, nums);
    }

    void QuickSortImplDijkstra(size_t left, size_t right, vector<int>& nums)
    {
        if (left >= right) {
            return;
        }
        auto [lt, gt] = dijkstra_partition(left, right, nums);
        if (lt > left) QuickSortImplDijkstra(left, lt-1, nums);
        QuickSortImplDijkstra(gt+1, right, nums);
    }

    void QuickSortImplYan(size_t left, size_t right, vector<int>& nums)
    {
        if (left >= right) {
            return;
        }
        int pivot = nums[left];
        size_t l = left, r = right;
        while (l < r) {
            while (l < r && nums[r] >= pivot) r--;
            nums[l] = nums[r];
            while (l < r && nums[l] <= pivot) l++;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        if (l > left) QuickSortImplYan(left, l-1, nums);
        QuickSortImplYan(l+1, right, nums);
    }

    vector<int> sortArray(vector<int>& nums) 
    {
        QuickSortImplDijkstra(0, nums.size()-1, nums);
        return nums;
    }
};