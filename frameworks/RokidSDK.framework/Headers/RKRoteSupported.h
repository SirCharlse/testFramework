//
//  RKRoteSupported.h
//  RokidSDK
//
//  Created by 杨朝  on 2022/2/16.
//

#import <UIKit/UIKit.h>
//#import "Aspects.h"

NS_ASSUME_NONNULL_BEGIN

@interface RKRoteSupported : NSObject

+ (instancetype)shared;

@property (nonatomic, assign) UIInterfaceOrientationMask interfaceOrientationMask;

@end

NS_ASSUME_NONNULL_END
