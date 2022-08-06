# 文档编辑

## Git

### Git中文件四个状态👍

1. Untracked:未跟踪，不在git管辖之内，执行```git add```进入下一步
2. Staged：进入暂存区，git能看到它，在.git/index中，又叫index区 ，执行```git commit```进入下一步
3. Unmodify： 提交到本地库后，无修改
4. Modified：本地修改后变为Modified

### Git 结构👌

1. 我们写代码是在工作区中写的
2. 执行```git add```命令会把修改的文件放到本地暂存区，临时存储
3. 执行```git commit```命令会把暂存区的文件放到本地库中
4. 执行```git push```命令会把本地库中的东西推到github上
5. 与他人合作项目时，别人修改github文件，你想更新，就要执行```git pull```
6. 克隆别人的项目就执行```git clone```

### 本地配置命令😎

1. 本地库初始化：```git init```
2. 设置签名--项目级别：

    ```bash
    git config user.name 'xxx'
    git config user.email 'xxx@xxx.com'
    ```

    - 用于区分不同开发人员的身份
    - 信息保存在./git/config
    - 想设置成系统级别的签名，中间加上```--global```
3. 查看工作区、暂存区状态：```git status```
4. 将所有修改的文件添加到暂存区:

    ```bash
    git add .
    ```

5. 将暂存区内容提交到本地库：

    ```bash
    git commit -m "commit_message" file_name_optional
    ```

6. 将本地库推送到远程库Github：

    ```bash
    git push origin master
    ```

7. 克隆远程库：

    ```bash
    git clone url.git
    ```

添加库的合作伙伴😍：
xxx库->settings->collaborators->add people->friend_name->copy invite link->给friend

## markdown

### 表格

1. 单元格之间以 | 间隔可以构成表格
2. 单元格后面是空的,默认和当前的合并
3. 单元格后面是>,默认和后面的合并
4. 单元格中是^, 和上面的合并

### 代码块

1. 语言后面可以接{.highlight=number},高亮代码行数
2. 接{.line-numbers}显示代码行数

### 任务列表

- [x] 观察源码
- [ ]

脚注[^]+缩写*[]+警告!!!
