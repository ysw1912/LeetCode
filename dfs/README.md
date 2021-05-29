### DFS template

```text
dfs(current_state, path, constants) {
  visited[current_state] = true
  // 当前状态满足结束条件，则将路径加入结果集
  if (is_terminate(current_state)) {
    solutions.push_back(path)
    return
  }
  // 对当前状态进行DFS
  for (next_state, action/edge in transition(current_state)) {
    if (visited[next_state]) {
      continue
    }
    // 将一条边加入路径后dfs，dfs返回时需要pop掉该边
    path.push_back(action/edge)
    dfs(next_state, path, constants)
    path.pop_back()
  }
}
```
