//
//  UIImage+QRCode.h
//  RokidSDK
//
//  Created by 小饼 on 2021/4/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (QRCode)
+ (UIImage *)createQRCodeWithTargetString:(NSString *)targetString;
+ (UIImage *)createQRCodeWithTargetString:(NSString *)targetString logoImage:(nullable UIImage *)logoImage;
@end

NS_ASSUME_NONNULL_END
