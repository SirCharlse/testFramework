//
//  RKCooperationDefine.h
//  iOSRokid
//
//  Created by 张小饼 on 2021/4/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RKFileInfo;

/// 会议模式
typedef NS_ENUM(NSUInteger, RKMeetingMode) {
    // 标准产品模式
    RKMeetingDefaultMode = 0,
    // 主持人模式
    RKMeetingModeratorMode = 1,
};

/// SDK状态
typedef NS_ENUM(NSInteger, RKErrCode) {
    /// 正常状态
    RKAuthOK = 1,
    /// 调用次数过于频繁
    RKAuthReasonTooManyRequests = 10001,
    /// token未传或已过期
    RKAuthReasonTokenExpired = 10002,
    /// API未授权
    RKAuthReasonAccessDenied = 10003,
    /// 会议创建失败
    RKMeetingCreateFailed = 11001,
    /// 加入会议失败
    RKMeetingJoinFailed = 11002,
    /// 登录超时
    RKAuthReasonTimeOut = 20005,
    /// appkey 错误
    RKAuthReasonAppKey = 20007,
    /// JC账号密码错误
    RKAuthReasonAuth = 20008,
    /// 无该用户
    RKAuthReasonNoUser = 20009,
    /// 被强制登出
    RKAuthReasonServerLogout = 20010,
    /// 登录其他设备
    RKAuthReasonAnotherDeviceLogined = 20011,
    /// 服务器忙
    RKAuthReasonServerBusy = 20019,
    /// 初始化失败
    RKAuthReasonJCInitFailed = 20099,
    /// 其他错误
    RKAuthReasonOther = 20100,
};

/// 会议模式
typedef NS_ENUM(NSUInteger, RKLogLevel) {
    // 默认关
    RKLogLevelNone,
    RKLogLevelError,
    RKLogLevelWarning,
    RKLogLevelInfo,
    RKLogLevelVerbose
};


typedef void(^OnSuccess)(_Nullable id data);
typedef void(^RKROnSuccess)(id data);
typedef void(^OnFailed)(RKErrCode errCode,  NSString * _Nullable errMsg);

typedef void(^RKRequestFileUrlCallback)(NSArray<RKFileInfo *> *);


#define RKJCAuthReasonBaseCode 20000

NS_ASSUME_NONNULL_END

