# NEWorld

NEWorld是一个开放源代码的模仿Minecraft游戏规则的游戏。

请下载`libraries`并放到NEWorld项目根目录[lib](http://pan.baidu.com/s/1jHz7rAe)

Font.ttf在此处下载：[Font.ttf](http://pan.baidu.com/s/1hr5TQjM)

最新进度在`0.5.0`分支。

# NEWorld 多人协作开发规范(试行)

## 总则

编写此多人协作开发规范的目的，是考虑到NEWorld的开发过程中，存在的各种严重的问题。各位开发人员，为了工作效率、正确的Git使用方式、统一的代码缩进风格、不必要的麻烦，也为了给予开发者足够的尊重，必须要遵守此规范的条款。

## 第一节 代码规范

0. 所有代码使用UTF-8编码。

0. 所有代码使用4个空格缩进(可在Visual Studio中设置)。

0. 每个人对自己写的代码负责。

0. 确保你使用的库都是可以跨平台的。

0. 不要擅自修改许可证。

## 第二节 Git使用及GitHub使用规范

0. 严禁上传编译后的二进制文件，包括但不仅限于`.exe`、`.obj`、`.dll`、`.lib`。抓到后施以严厉处罚。

0. 所有分支都应该可以(或计划可以)合并到`master`分支。

0. 不要擅自修改`.gitignore`文件。

0. 所有人必须通过git水平技能测试才能拥有write权限，否则请使用Pull Request提交代码。

0. 经常浏览issues，解决属于你范围的issues。

0. 如果没有必要，不要使用`git revert`回滚别人的代码。回滚他人代码，必须满足

- 经开发组超过2/3人员同意

- 通知原作者，并获得原作者正式的(包括但不限于电子邮件、GitHub留言)许可回复

中的任意一个或两个条件时，才能回滚。否则，施以严厉处罚。


## 第三节 合作开发规范

0. 确保主要开发人知晓并同意你要做的大修改(包括但不限于重构，加入新库)。

## 第四节 C/C++代码规范

1. 不允许在成熟的代码中出现引用计数<=1的宏/函数/变量以及没有作为过右值的变量。

2. 一个成熟的头文件至少要被包含两次及以上。

3. 一个文件中声明的其它文件里的内容总长度不允许超过20行。

4. 一个函数不允许只有复杂性较低一行代码。

5. 新增代码中不允许有连续至少4行的极其相似代码。

