# MLeaksFinderDeom

每次发现有内存泄漏都好繁琐，不管你是Instruments工具查找还是手动在delloc方法一步一步寻找都是很不方便的。

最近看到了微信开源库：MLeaksFinder和facebook开源库：FBMemoryProfiler，

这两个开源三方，在编写过程中就可以检测内存泄露，实在不要太好用了！

**一、微信 MLeaksFiner**
如有不懂可自行点击了解==&gt;[MLeaksFiner介绍](http://wereadteam.github.io/2016/07/20/MLeaksFinder2/)

1.创建demo项目MLeaksFinderDeom引入MLeaksFiner开源文件夹
![图片描述](/data/attachment/album/201811/12/204828ee0u9frzeempu07e.png)

2.导入这个文件夹就默认在debug模式下开启了，下面我举个例子检验：

2.1在AppDelegate加入以下代码


```
self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
self.window.backgroundColor = [UIColor whiteColor];
[self.window makeKeyAndVisible];  
UINavigationController *nav = [[UINavigationController alloc]initWithRootViewController:[ViewController new]];
self.window.rootViewController = nav;
```

新建ViewControllerDeom控制器并添加如下代码


```
@interface ViewControllerDeom ()
@property (nonatomic,strong) NSTimer *timer;
@end

@implementation ViewControllerDeom

- (void)viewDidLoad {
    [super viewDidLoad];
    NSTimer *timer = [[NSTimer alloc] initWithFireDate:[NSDate date] interval:1 target:self selector:@selector(timerFire) userInfo:nil repeats:YES];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSDefaultRunLoopMode];
    self.timer = timer;
    
}

- (void)timerFire {
    NSLog(@"启动");
}
```


内存泄露： ViewController=&gt;push=&gt;ViewControllerDeom=&gt;pop=&gt; ViewController

但是NSTimer没有置为nil，所以造成内存泄漏
![图片描述](/data/attachment/album/201811/13/143824ouzcjl89ailksbs0.37)
如图内存泄漏精准定位到了ViewControllerDeom内，但是如若vc比较复杂的逻辑还是很难精准的定位到是哪一个对象造成的！

不要慌张~~~ 接着往下走........

**二、 MLeakFinder +  FBRetainCycleDetector的结合**

2.1查看MLeaksFinder.h文件
![图片描述](/data/attachment/album/201811/13/144953g6jo6lcql6fqc9c4.png)

2.2  添加cocopod ，然后 Pod 添加FBRetainCycleDetector

最后再看结果~~~~~~
![图片描述](/data/attachment/album/201811/13/145241rgwgx112nfngn4nh.png)
![图片描述](/data/attachment/album/201811/13/145251l7qz2u0qxd2ld752.52)

精准定位到是NSTimer造成的


deom地址=&gt;[github](https://github.com/dongpeng66/MLeaksFinderDeom.git)
