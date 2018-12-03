////————————————————————————————————————————————————————————————
//                       .::::.             Config.h
//                     .::::::::.
//                    :::::::::::           releaseDome
//                 ..:::::::::::'
//              '::::::::::::'               Created by Mr.Qing on 2018/11/13.
//                .::::::::::
//           '::::::::::::::..              Copyright © 2018年 KESHANGE. All rights reserved.
//                ..::::::::::::.
//              ``::::::::::::::::
//               ::::``:::::::::'        .:::.
//              ::::'   ':::::'       .::::::::.
//            .::::'      ::::     .:::::::'::::.
//           .:::'       :::::  .:::::::::' ':::::.
//          .::'        :::::.:::::::::'      ':::::.
//         .::'         ::::::::::::::'         ``::::.
//     ...:::           ::::::::::::'              ``::.
//    ```` ':.          ':::::::::'                  ::::..
//                       '.:::::'                    ':'````..
//——————————————————————————————————————————————————————————————

#import "UIColor+HexString.h"
#ifndef Config_h
#define Config_h

/**
 公共尺寸
 */
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height

#define SCREEN_LINE 1/[UIScreen mainScreen].scale

/**
 判断是否是iphonex
 */
#define isiPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)


/// 延迟执行
#define GCD_AFTER(TIME,Block) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(TIME* NSEC_PER_SEC)), dispatch_get_main_queue(),Block);
//颜色
#define ColorWithMain [UIColor colorWithHexString:@"fc7595"] //主色调
#define ColorWithNoSelect [UIColor colorWithHexString:@"999999"] //文本为选中颜色
#define ColorWithLine [UIColor colorWithHexString:@"cccccc"]
#define ColorWithLineSecondary     [UIColor colorWithHexString:@"#e7e7e7"]//次要分隔线
#define colorWithSecondTextColor6   [UIColor colorWithHexString:@"#666666"]//次要文字颜色
#define colorWithSecondTextColor9   [UIColor colorWithHexString:@"#999999"]//次要文字颜色
#define colorWithBackground   [UIColor colorWithHexString:@"#f8f8f8"]


//字体
#define FontSizeWith15         [UIFont systemFontOfSize:15]//用于详情页tab\卡片列表等
#define FontSizeWith14         [UIFont systemFontOfSize:14]//用于部分次要信息
#define FontSizeWith13         [UIFont systemFontOfSize:13]

/* ======================================== 间距 ======================================== */
#define GapWithRound 15//    环绕间距（元素之间）：15pt
#define GapWithHorizontal 12//  元素与屏幕左/右的距离：12
#define GapWithOneLevel 20//    一级间距：20pt
#define GapWithTwoLevel 15//    二级间距：15pt
#define GapWithThreeLevel 10//    三级间距：10pt
#define GapWithOneLevelModule 15//    一级模块间距：15pt
#define GapWithTwoLevelModule 12//    二级模块间距：12pt

//固定跳转
#define GoLogin   LoginViewController *loginVC = [[LoginViewController alloc] init]; [self presentViewController:loginVC animated:YES completion:nil];


//配置宏
#define WS(weakSelf) __weak __typeof(&*self)weakSelf = self;

//请求域名 链接
#define APPDomain @""

#endif /* Config_h */
