//
//  ViewController.m
//  MLeaksFinderDeom
//
//  Created by jxchain on 2018/11/12.
//  Copyright © 2018 jxchain. All rights reserved.
//

#import "ViewController.h"
#import "ViewControllerDeom.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}
-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    ViewControllerDeom *vc=[[ViewControllerDeom alloc]init];
    [self.navigationController pushViewController:[ViewControllerDeom new] animated:YES];
}
-(void)aaa{
    
}
@end
