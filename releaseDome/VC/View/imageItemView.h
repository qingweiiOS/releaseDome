////————————————————————————————————————————————————————————————
//                       .::::.             imageItemView.h
//                     .::::::::.
//                    :::::::::::           FriendsWithBenefits
//                 ..:::::::::::'
//              '::::::::::::'               Created by Mr.Qing on 2018/11/12.
//                .::::::::::
//           '::::::::::::::..              Copyright © 2018年 NG. All rights reserved.
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

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^clickBtnBlock)(NSInteger index,NSInteger type);//type 1点击查看大图，2、删除 3、显示，于，隐藏
@interface imageItemView : UIView
@property (nonatomic,strong) UIImage *image;
@property (nonatomic, assign) BOOL isVideo;
@property (nonatomic, assign) BOOL isVisible;// 对外是否可见
@property (nonatomic, copy) clickBtnBlock imgBlock;
- (UIImageView *)contentView;
@end

NS_ASSUME_NONNULL_END
