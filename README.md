# vector_db_demo

向量数据库的展示demo

## 安装环境

### bazel 构建工具

bazel 版本 大于6.0

### 安装基础依赖库

安装依赖

`sudo apt-get install -y git g++ make libssl-dev libgflags-dev libprotobuf-dev libprotoc-dev protobuf-compiler libleveldb-dev`

静态链接leveldb

`sudo apt-get install -y libsnappy-dev`

启用cpu/heap的prifiler

`sudo apt-get install -y libgoogle-perftools-dev`

如果你要运行测试，那么要安装并编译libgtest-dev（它没有被默认编译）：

`sudo apt-get install -y cmake libgtest-dev && cd /usr/src/gtest && sudo cmake . && sudo make && sudo mv lib/libgtest* /usr/lib/ && cd -`


## 构建步骤

`bazel  build //:all`

## 运行

首先运行server
`
./bazel-bin/db_server
`

然后运行client测试

`
./bazel-bin/db_client
`