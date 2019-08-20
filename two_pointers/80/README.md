### 80. Remove Duplicates from Sorted Array II

-----

&emsp;&emsp;给定一个排序数组，在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

**Example**

    Input: nums = [0, 0, 1, 1, 1, 1, 2, 3, 3]
    Output: 
    len = 7
    nums = [0, 0, 1, 1, 2, 3, 3]

-----

&emsp;&emsp;我使用了 3 个 index，而答案只使用了 2 个。