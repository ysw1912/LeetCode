### 3. Longest Substring Without Repeating Characters

-----

&emsp;&emsp;给定一个字符串，找出其中不含有重复字符的最长子串的长度。

-----

#### 正解一

&emsp;&emsp;滑动窗口/双指针 + set。

&emsp;&emsp;遍历 i，通过 set 找到 s[i...j] 不含重复字符，且 s[j + 1] 是重复字符。

&emsp;&emsp;进入 i + 1 时，从 set 中剔除 s[i]，可知 s[i+1...j] 也一定不含重复字符，因此另一个指针继续从 j + 1 不断往后扫，使得 s[i...k] 不含重复字符。

#### 正解二

&emsp;&emsp;对于 char，set/map 可用 std::array<int, 256> 代替。

&emsp;&emsp;map 的每个元素表示该字符在 s[0...i] 中最后出现的下标位置，初始值为 -1，因为还没有开始遍历。

&emsp;&emsp;start = -1，遍历 i。

- 若 map[s[i]] > start，则 start = map[s[i]]，此时 s[start] = s[i] 并且 start 是该字符在 s[0...i] 中最后出现的下标位置。

&emsp;&emsp;为 map[s[i]] 赋值为当前的 i，可知 s 在 (start, i] 范围内一定没有重复元素，i - start 是一种可能的 max length 取值。
