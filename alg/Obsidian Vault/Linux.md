删除文件夹
```shell
rm -rf ./文件夹名
```
 ---
 `.bashrc`是home目录下的一个shell文件，用于储存用户的个性化设置。在bash每次启动时都会加载`.bashrc`文件中的内容，并根据内容定制当前bash的配置和环境。
- 设置环境变量
```shell
PATH="$PATH:$HOME/.local/bin:$HOME"
export PATH
```
对 `.bashrc` 所做的任何修改将在下一次启动终端时生效，如果想立刻生效的话，运行下面的命令：
```shell
source ~/.bashrc
```
---
卸载miniconda3:
- 删除miniconda的安装目录
```shell
rm -rf ./miniconda3/
```
- 注释`.bashrc`文件中的`conda initialize`代码
- 删除.conda相关文件
```shell
rm -rf ./.condarc
rm -rf ./.conda
```
- 刷新环境
```shell
source ./.bashrc
```
---
安装Python:
- 下载源码包
```shell
wget https://www.python.org/ftp/python/3.11.2/Python-3.11.2.tar.xz
```
- 解压源码包
```shell
tar xvJf Python-3.11.2.tar.xz
```
- 进入解压目录，进行手动编译
```shell
cd Python-3.11.2
./configure prefix=/usr/local/python3
make && make install
```
- 将原来链接备份
```shell
mv /usr/bin/python3 /usr/bin/python3.bak
```
- 添加python3的软连接
```shell
ln -s /usr/local/python3/bin/python3.11 /usr/bin/python3
```
- 测试是否安装成功

---
安装anaconda更容易些
- 添加下载源
```shell
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
```
