## NEWorld 多人协作开发规范(试行)

### 前言

编写此多人协作开发规范的目的，是考虑到NEWorld的开发过程中存在的各种严重的问题。
为了提高工作效率、避免不必要的麻烦，也为了给予开发者足够的尊重，我们需要采取包括正确地使用Git、统一代码缩进风格的措施。
各位开发人员必须要遵守此规范的条款。

### 第一节 代码规范

0. 所有代码使用UTF-8编码。

0. 所有代码使用4个空格缩进(可在Visual Studio中设置)。

0. 每个人对自己写的代码负责。

0. 确保你使用的库都是可以跨平台的。

0. 不要擅自修改许可证。

### 第二节 Git使用及GitHub使用规范

0. 严禁上传编译后的二进制文件，包括但不仅限于`.exe`、`.obj`、`.dll`、`.lib`。抓到后施以严厉处罚。

0. 所有分支都应该可以(或计划可以)合并到`master`分支。

0. 不要擅自修改`.gitignore`文件。

0. 所有人必须通过git水平技能测试才能拥有write权限，否则请使用Pull Request提交代码。

0. 经常浏览issues，解决属于你范围的issues。

0. 如果没有必要，不要使用`git revert`回滚别人的代码。回滚他人代码，必须满足

- 经开发组超过2/3人员同意

- 通知原作者，并获得原作者正式的(包括但不限于电子邮件、GitHub留言)许可回复

中的任意一个。否则，施以严厉处罚。

### 第三节 合作开发规范

0. 确保主要开发人知晓并同意你要做的大修改(包括但不限于重构，加入新库)。

### 第四节 C/C++代码规范

0. 不允许在成熟的代码中出现引用计数<=1的宏/函数/变量以及没有作为过右值的变量。

0. 一个成熟的头文件至少要被包含两次。

0. 一个文件中声明的其它文件里的内容总长度不允许超过20行。

0. 在优先考虑其他规范和代码可读性的情况下，尽量不要写只有复杂性较低的一行代码的函数。

0. 新增代码中不允许有连续至少4行的极其相似代码。

0. 局部变量至少要作为右值被引用一次，并且总共被引用至少两次。

### 第五节 C/C++附加代码规范

0. 使用Allman/BSD标准缩进。

0. 如果不是性能需要，尽量使用智能指针代替裸指针。

0. 不要把类型声明中实现的函数加`inline`说明符。

0. 局部变量要使用尽量简短的名称。

0. 不要将可以放在内层代码块中的变量放在外层代码块中。

0. 对于自动在传递参数时进行深拷贝的类型（比如`std::string`），尽量使用const引用。

0. 对于执行过程中不修改类型内部数据的函数，加const说明符。

0. 确保类型只公开必要的成员。

0. 类名使用大驼峰，函数名/变量名使用小驼峰，原则上变量名为名词短语（函数指针除外），函数名为动词短语。

### 第六节 处罚条例

0. 每个有`write`权限的人有三次机会。

0. 每上传一次二进制文件，立即取消`write`权限，回滚代码，并且减少一次机会。

0. 每未经他人同意回滚代码或加入新库，由全体开发者决定处理方式。

0. 若机会数量降为0，则永不恢复`write`权限。

0. `write`权限被取消后，可以随时提出恢复权限的申请，由全体开发者决定是否同意。