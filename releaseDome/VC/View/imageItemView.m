////————————————————————————————————————————————————————————————
//                       .::::.             imageItemView.m
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

#import "imageItemView.h"
#import "Config.h"
//使用前需要导入头文件
#import"UIImage+ImageEffects.h"

@interface imageItemView ()

@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (nonatomic, strong) UIImage *hiddenImg;
@property (weak, nonatomic) IBOutlet UIButton *optionBtn;
@property (weak, nonatomic) IBOutlet UIButton *hiddenBtn;
@property (nonatomic, strong) NSTimer *timers;

@end
@implementation imageItemView

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

- (UIImage *)hiddenImg{
    if(!_hiddenImg){
       /// 耗时间 放到子线程处理
        dispatch_queue_t queue = dispatch_queue_create("queue", DISPATCH_QUEUE_CONCURRENT);
        dispatch_async(queue, ^{
            self->_hiddenImg = [self.image blurImageWithRadius:10.0];
        });
       /// 模拟监控 _hiddenImg
        _timers = [NSTimer scheduledTimerWithTimeInterval:0.1 target:self selector:@selector(observeHiddenimaage) userInfo:nil repeats:YES
                   ];
       
    }
    return _hiddenImg?_hiddenImg:self.image;
}
- (void)observeHiddenimaage{
    if(_hiddenImg){
        if(self.isVisible){
          self.imageView.image = _hiddenImg;
        }
        [_timers invalidate];
    }
    
}
- (void)dealloc{
    [_timers invalidate];
}
-(void)awakeFromNib
{
    [super awakeFromNib];
    self.imageView.layer.cornerRadius = 3.0;
    self.imageView.layer.borderColor = ColorWithLineSecondary.CGColor;
    self.imageView.layer.borderWidth = 0.5;
    self.imageView.layer.masksToBounds = YES;
}
- (IBAction)action_clickImg:(UIButton *)sender {
    
    if(self.imgBlock){
        self.imgBlock(self.tag,sender.tag);
    }
   
}
- (UIImageView *)contentView{
    
    return self.imageView;
}
- (void)setImage:(UIImage *)image{
    _image = image;
    self.imageView.image = _image;
}
- (void)setIsVideo:(BOOL)isVideo{
    
    _isVideo = isVideo;
    if(_isVideo){
        [self.optionBtn setImage:[UIImage imageNamed:@"player"] forState:UIControlStateNormal];
         self.optionBtn.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.3];
    }else{
        [self.optionBtn setImage:[UIImage imageNamed:@""] forState:UIControlStateNormal];
    }
}
- (void)setIsVisible:(BOOL)isVisible{
    _isVisible = isVisible;
    if(_isVisible){
      
       self.imageView.image = self.hiddenImg;
        [self.hiddenBtn setTitle:@"隐藏" forState:UIControlStateNormal];
    }else{
        self.imageView.image = self.image;
        [self.hiddenBtn setTitle:@"显示" forState:UIControlStateNormal];
    }
    
}
- (IBAction)action_hidden:(id)sender {
    if(self.imgBlock){
        self.imgBlock(self.tag,3);
    }
    self.isVisible = !self.isVisible;
}



@end
