### BFS template

```text
bfs(start_state) {
  // 起始状态入队
  queue.push(start_state)
  metadata[start_state] = {
    visited: true,
    pre_state: NULL,
    pre_action: NULL
  }
  // 队列不为空
  while (!queue.empty()) {
    current_state = queue.top()
    queue.pop()
    // 结束条件满足
    if (is_terminate(current_state)) {
      // 从当前状态追溯出路径
      path = get_path_from(metadata[current_state])
      solutions.push_back(path)
      return
    }
    // 对当前状态进行BFS
    for (next_state, action/edge in transition(current_state)) {
      if (metadata[next_state].visited) {
        continue
      }
      // 当前状态的其中一个下一状态入队
      queue.push(next_state)
      metadata[next_state] = {
        visited: true,
        pre_state: current_state,
        pre_action: action/edge
      }
    }
  }
}
```
