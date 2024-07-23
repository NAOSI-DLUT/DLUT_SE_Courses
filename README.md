# 大连理工大学软件学院（软件工程、网络工程）课程攻略

> [!important]
> 如果您发现我们使用了您的资料的话，您可以及时通知我们，我们将对您的资料署名，并再次询问您是否愿意公开。
> 
> 如果曾经的公开对您造成的困扰的话，我们十分抱歉，并承诺立即删除并更改 git_cached 中的内容，我们将尽我们所能弥补您。
> 
> 同时希望上传资料的同好们，可以把自己的资料标注上作者，十分感谢
>
> 个人的作业实现推荐通过添加 README 链接和简介或通过 [git submodule](https://git-scm.com/book/en/v2/Git-Tools-Submodules) 的方式提交到仓库，由您个人保留项目的所有权

Github 使用请自行查阅CSDN，或参考 [官方教程](https://guides.github.com/activities/hello-world/)。如果想对项目进行贡献，推荐学习 Git 工具 bash 命令行的使用 - [ProGit](https://www.progit.cn/)

## 文件下载

我们为同学们提供了可靠的下载方式，有以下方式可以选择。
* [DownGit](http://zhoudaxiaa.gitee.io/downgit/#/home) - 复制文件/夹 网址，粘贴并download即可
* [GitZip](https://chrome.google.com/webstore/detail/gitzip-for-github/ffabmkklhbepgcgfonabamgnfafbdlkn?hl=en) - 浏览器扩展，需要安装，自行学习
* 或者使用 git sparse checkout 方式单独下载某一部分文件或文件夹（需 git 版本高于 1.7.0 Feb. 2012）
  ```bash
  mkdir DLUT_SE_Courses
  cd DLUT_SE_Courses
  git init
  git remote add -f origin git@github.com:NAOSI-DLUT/DLUT_SE_Courses.git
  
  git config core.sparseCheckout true

  echo "some/dir/" >> .git/info/sparse-checkout
  echo "another/sub/tree" >> .git/info/sparse-checkout

  git pull origin master
  ```
* 校内资料库已挂，请有想法的同学或组织联系 NAOSI 协会

## 感谢-欢迎贡献！！ 欢迎贡献！！ 欢迎贡献！！

> [!important]
> 感谢对本项目贡献的同学（无论排名）：[徐志](https://github.com/1999John)、[张恩泽](https://github.com/FrancisGrace)、崔良睍、武文轩、方念华、[于汛](https://github.com/JFJ-yx)、[王琪瑞](https://github.com/ChrisWang13)、[张亦弛](https://github.com/Augists)……以及电脑前的您！

## 前言

**情报**和**资料**永远都是学业成功的重要基石，望着可爱的，接受大学摧残的新生们和学弟们（老腹黑怪了），身为学长不由生出一种母性（淦）。

* 有些是学长学姐亲传的资料

* 有些是你寻找很久的电子参考书
* 有些是前人细心雕琢出的大作业，放在个人的GitHub仓库中，渐渐被遗忘；

* 有些是历年真题，前人费尽心思收集，善良的将他公开，却需要在摸索中下载
* 有些是上完一门课才恍然领悟的技巧。

我也曾很努力地收集各种课程资料，但到最后，某些重要信息的得到却往往依然是纯属偶然。这种状态时常令我感到后怕与不安。我也曾在课程结束后终于有了些许方法与总结，但这些想法无处诉说，最终只能把花费时间与精力才换来的经验耗散在了漫漫的遗忘之中。

我为这一年一年，这么多人孤军奋战的重复劳动感到不平。

本项目希望能够将这些隐晦的、不确定的、口口相传的资料和经验，变为公开的、易于获取的和大家能够共同完善、积累的共享资料。

**消除大部分你需要走的没必要的弯路，同时让大家的学业至少在资料方面是平等的**。这就是我的信念，也是我建立这个项目的原因。

## 上传及阅读指南

本项目的文件命名格式：

- 课程攻略：README.md
- 电子版参考教材：ebook_ [教学年份]_[老师姓名]/（因版权产生问题，请及时issue提醒我）
- 电子版课件 ppt_ [教学年份]_[老师姓名]/
- 平时作业答案与大作业资料：hw/[学号]/ （为保证大家的隐私）
- 历年试卷和复习资料：exam_ [年份]_ [后缀]/
- 其他请标明用处：  比如编程练习 Excersize/[学号]/

希望大家遵守命名，给予他人良好的使用体验。

比如我是2020年上单世民老师的数据库，想上传一下老师的PPT，即在数据库系统文件夹下新建文件夹`PPT_2020_单世民`，如果有双语课，则为 `PPT_2020_单世民_双语`，然后往里面上传即可

>  当然，欢迎往对应的`readme.md`里面放自己的GitHub对应仓库链接 :kissing_closed_eyes:

**PS：** 由于本仓库未启用`git-lfs`，因此==请不要上传单个超过100M的文件==，否则commit无效。

同时请尽量不要上传二进制文件例如 `.exe`  ,这会为`github`带来错误

## 参与我们的项目

电脑前的您请不要吝啬，对于您的任何提交我们十分欢迎，您的作品一旦被合并至该仓库中，有可能会被无数学弟仰慕。我们需要您的PR！

如果你关于学校或者课程有很多疑问，请多向我们提 issue ，力所能及的范围我们都是会回答你的，但提问前请先参阅  [怎样提出一个好问题](https://github.com/ryanhanwu/How-To-Ask-Questions-The-Smart-Way/blob/master/README-zh_CN.md) 十分感谢！！

我们会尽可能将你们所提的issue整合成 Q&A ，并整理为一个文件，这项工作有待完善，欢迎大家参与！！ :smile: 

## 许可

由贡献者编写部分的许可如下：

[(Creative Commons BY-SA 4.0) 知识共享署名 - 相同方式共享 4.0 国际许可协议](https://creativecommons.org/licenses/by-nc-sa/4.0/deed.zh)

[The Star And Thank Author License](https://github.com/zTrix/sata-license)

真正版权归属于其各自的作者。资料仅供参考，请自己判断其适用性。

## 参考

[清华大学](https://github.com/Salensoft/thu-cst-cracker) | [浙江大学](https://github.com/QSCTech/zju-icicles) | [上海交通大学](https://github.com/c-hj/SJTU-Courses) | [北京大学](https://github.com/lib-pku/libpku) | [同济大学](https://github.com/TJ-CSCCG/TJCS-Course)

大家也可借鉴参阅
