//
//  ViewControllerDeom.m
//  MLeaksFinderDeom
//
//  Created by jxchain on 2018/11/12.
//  Copyright © 2018 jxchain. All rights reserved.
//

#import "ViewControllerDeom.h"

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
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
