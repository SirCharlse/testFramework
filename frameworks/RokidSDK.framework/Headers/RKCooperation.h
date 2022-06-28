//
//  RKCooperation.h
//  RokidSDK
//
//  Created by 杨朝  on 2022/2/15.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "RKCooperationDefine.h"
#import "RKCooperationModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol RKCooperationDelegate <NSObject>

///创建会议成功
/// @param meetingId 会议ID
- (void)createChannel:(NSString *)meetingId;

/// 收到来电
/// @param meetingId 会议ID
/// @param userId 用户ID
- (void)onReceiveCall:(NSString *)meetingId
               userId:(NSString *)userId;

/// 接听会议
/// @param meetingId 会议ID
/// @param userId 用户ID
- (void)onCallAccept:(NSString *)meetingId
              userId:(NSString *)userId;

/// 拒接会议
/// @param meetingId 会议ID
/// @param userId 用户ID
- (void)onCallRejected:(NSString *)meetingId
                userId:(NSString *)userId;

/// 主动挂断
/// @param meetingId 会议ID
/// @param userId 用户ID
- (void)onCallCanceled:(NSString *)meetingId
                userId:(NSString *)userId;

/// 用户忙
/// @param meetingId 会议ID
/// @param userId 用户ID
- (void)onCallBusy:(NSString *)meetingId
            userId:(NSString *)userId;


/// 自己取消呼叫
/// @param meetingId 会议ID
- (void)onUserCallCanceled:(NSString *)meetingId;


/// 呼叫超时（60s）
/// @param meetingId 会议ID
/// @param userId 用户ID
- (void)onCallTimeout:(NSString *)meetingId
               userId:(NSString *)userId;

/// 加入会议成功
/// @param meetingId 会议ID
- (void)onJoined:(NSString *)meetingId;

/// 离开会议
/// @param meetingId 会议ID
/// @param serverId IM serverID
/// @param userIds  会议中剩下的用户（不包含自己）
- (void)onLeavedMeeting:(NSString *)meetingId
               serverId:(nullable NSString *)serverId
         meetingUserIds:(NSArray <NSString *> *)userIds;

/// 会议内邀请用户
/// @param meetingId 会议ID
/// @param currentUserCount 当前会议成员 包含自己
/// @param maxUserCount 最大支持的人数
///  执行邀请 返回YES，拦截邀请 返回NO
- (BOOL)onInviteUser:(NSString *)meetingId
    currentUserCount:(NSInteger)currentUserCount
        maxUserCount:(NSInteger)maxUserCount;

@optional

/// 视频录制保存文件回调接口   <SDK内部进行上传，不在对外暴露>
/// @param meetingId 会议ID
/// @param fileName 云录制文件信息
- (void)onMeetingRecordEvent:(NSString *)meetingId
                    fileName:(NSString *)fileName;

/// 冻屏保存事件
/// @param meetingId 会议ID
/// @param filePath 冻屏文件保存路径
- (void)onScreenshotEvent:(NSString *)meetingId
                 filePath:(NSString *)filePath;

/// 会议异常情况。<SDK 2.1.0 弃用接口>
/// @param meetingId 会议ID
/// @param errorCode 异常code @RKErrorCode
- (void)onMeetingError:(nullable NSString *)meetingId
                reason:(RKErrCode)errorCode;

/// 有新加入会议用户
/// @param meetingId 会议ID
/// @param userId 用户ID
- (void)onUserJoinedWithMeetingId:(NSString *)meetingId
                           userId:(NSString *)userId;

/// 会议状态发生改变
/// @param meetingId 会议ID
/// @param status @RKErrorCode
- (void)onMeetingStateChangedWithMeetingId:(NSString *)meetingId
                                    status:(RKErrCode)status;

/// 呼叫设置页点击返回
/// @param meetingId 会议ID
/// @param serverId 群聊ID，会议内IM需要，如果不传，则会议内无群聊功能
- (void)onCallCancelButtonAction:(nullable NSString *)meetingId
                        serverId:(nullable NSString *)serverId;

@end

#pragma mark - APP配置协议
@protocol AppRotationInterface <NSObject>

/// 横竖屏切换
/// @param interfaceOrientation 方向
//- (void)setNewOrientation:(UIInterfaceOrientationMask)interfaceOrientation;

@end

//IM回调
@protocol RKChatEventCallback <NSObject>

/// IM触发选人动作，RKChatInfo内部包含当前会议的所有参与成员列表
/// 选择完成调用 - inviteMembersWithId: 方法
/// @param chatInfo 群聊信息
- (void)onCollaborationEvent:(RKChatInfo *)chatInfo;

/// IM内发起协作事件回调， 需要调用  - createMeeting: 创建会议
/// @param chatInfo 群聊信息
- (void)onCreateMeetingEvent:(RKChatInfo *)chatInfo;

/// IM内发起会议事件回调，执行完绑定操作需要调用 - startMeeting: 方法发起会议
/// @param chatInfo 群聊信息
- (void)onStartMeetingEvent:(RKChatInfo *)chatInfo;

/// IM添加成员完成回调 ， 调用 - inviteMembersWithId: 的回调
/// @param chatInfo 群聊信息
- (void)onInviteEvent:(RKChatInfo *)chatInfo;

/// IM总未读消息更新回调
/// @param count 未读消息数
- (void)onUnreadMsgCountChangedEvent:(int)count;


@end


@interface RKCooperation : NSObject

/// 返回 RKCooperation 单例
+ (instancetype)shareInstance;

/// 会议回调
@property (nonatomic, weak) id <RKCooperationDelegate> meetingDelegate;

// 设置屏幕共享Extension的bundleId
@property (nonatomic, strong) NSString *screenShareExtenId;


/// 不要调用对象构造方法创建
/// 调用shareInstance方法获取对象
+ (instancetype)new NS_UNAVAILABLE;

+ (instancetype)init NS_UNAVAILABLE;

/// 获取SDK 版本号
- (NSString *)getRKSDKVersion;

/// 获取SDK build号
- (NSString *)getRKSDKBuildNumber;

/// SDK日志控制
/// @param logLevel @RKLogLevel 默认关闭
- (void)setLogLevel:(RKLogLevel)logLevel;

/// 设置会议模式
/// @param meetingMode @RKMeetingMode
//- (void)setMeetingMode:(RKMeetingMode)meetingMode;

///  设置会议回调
/// @param delegate @RKCooperationDelegate
- (void)setCooperationDelegate:(id <RKCooperationDelegate>)delegate;

/// 初始化IMSDK数据库
- (void)initWithSDKIMDB;

/// 初始化SDK  <若使用RTC+IM使用该方法>
/// @param sdkInfo 初始化SDK必要参数
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)initWithSDKInfo:(RKSDKInfo *)sdkInfo
              onSuccess:(nullable OnSuccess)onSuccess
               onFailed:(nullable OnFailed)onFailed;


///RTC SDK 初始化
/// @param sdkInfo 初始化SDK必要参数
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)initWithRTC:(RKSDKInfo *)sdkInfo
          onSuccess:(nullable OnSuccess)onSuccess
           onFailed:(nullable OnFailed)onFailed;


///初始化IM SDK
/// @param sdkInfo 初始化SDK必要参数
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)initWithIMSDK:(RKSDKInfo *)sdkInfo
            onSuccess:(nullable OnSuccess)onSuccess
             onFailed:(nullable OnFailed)onFailed;


/// 注销SDK
- (void)deInitSDK;

/// 更新用户token
/// @param token token
- (void)refreshToken:(NSString *)token;

/// 配置用户类型
/// @param role 1:技师，2:专家 ，3:外部专家
- (void)configUserRole:(int)role;

///// 创建会议
///// @param meetingName  会议名字，姓名+公司+VIM号后8位
///// @param users 邀请的用户
///// @param onSuccess 成功回调 meetingId
///// @param onFailed 失败回调
- (void)createMeeting:(NSString *)meetingName
          inviteUsers:(NSArray <NSString *> *)users
            onSuccess:(nullable OnSuccess)onSuccess
             onFailed:(nullable OnFailed)onFailed;

///// 发起会议
///// @param meetingName  会议名字，姓名+公司+VIM号后8位
///// @param meetingId  会议ID，需要先调用 createMeeting 获取
///// @param serverId  群聊ID，会议内IM需要，如果不传，则会议内无群聊功能
///// @param isBackCamera  是否默认后置摄像头， default is front camera
///// @param users 邀请的用户
- (void)startMeeting:(NSString *)meetingName
           meetingId:(NSString *)meetingId
            serverId:(nullable NSString *)serverId
          backCamera:(BOOL)isBackCamera
         inviteUsers:(NSArray <RKContactInfo *> *)users;


/// 加入会议
/// @param meetingId 会议ID
/// @param serverId 群聊ID，会议内IM需要，如果不传，则会议内无群聊功能
- (void)joinMeeting:(NSString *)meetingId
           serverId:(NSString *)serverId;

/// 加入会议
/// @param meetingId 会议ID
/// @param meetingName 会议名字
/// @param serverId 群聊ID，会议内IM需要，如果不传，则会议内无群聊功能
- (void)joinMeeting:(NSString *)meetingId
        meetingName:(NSString *)meetingName
           serverId:(NSString *)serverId
          onSuccess:(nullable OnSuccess)onSuccess
           onFailed:(nullable OnFailed)onFailed;

/// 结束会议
- (void)stopMeeting;

/// 邀请人参加会议
/// @param meetingId 会议ID，创建会议默认为 空字符串 即可，
/// @param users 邀请的用户
- (void)inviteUser:(NSString *)meetingId
       inviteUsers:(NSArray <RKContactInfo *> *)users;

/// 透传SDK需要的推送消息
/// @param msg 推送消息"RKMessage"字段
- (void)receiveMsg:(NSString *)msg;

/**
 * 屏幕共享功能相关
 */
///上传屏幕共享采集流推送
- (void)uploadSharePixelBuffer:(CVPixelBufferRef __nonnull)sampleBuffer;

///结束屏幕共享
- (void)endShareScreen;



///chat代理
@property(nonatomic, weak) id<RKChatEventCallback> chatDelegate;

/**
 * 获取聊天记录列表
 */
- (UIView *)getChatListView;

/// 发起群聊，成功自动跳转聊天页面
/// @param chatInfo 群聊需要的信息  serverId 传""即可
/// @param navi 如果需要跳转传入导航控制器
/// @param onSuccess 成功回调 serverId
/// @param onFailed 失败回调
- (void)startChatWithChatInfo:(RKChatInfo *)chatInfo
     withNavigationController:(nullable UINavigationController *)navi
                    onSuccess:(OnSuccess)onSuccess
                     onFailed:(OnFailed)onFailed;
/**
 * 通过群聊id跳转到聊天页面
 */
- (void)startChatWithServerId:(NSString *)serverId
     withNavigationController:(UINavigationController *)navi;

/**
 * 选择要邀请的成员后调用
 *
 * serverId: 群聊id
 */
- (void)inviteMembersWithId:(NSString *)serverId chatMembers:(NSArray<RKChatMember *> *)chatMembers;

/// 跳转选择IM成员页面
/// @param chatInfo chatInfo
- (void)inviteChatMembers:(RKChatInfo *)chatInfo;

/// 获取所有未读消息总数，另外需要提供未读消息总数更新回调
/// @param onSuccess 回调未读消息数 NSNumber
- (void)getUnreadMsgCount:(OnSuccess)onSuccess;


/**
 * 解散群聊
 *
 * serverId: 群聊id
 */
- (void)dissolutionGroup:(NSString *)serverId
               onSuccess:(OnSuccess)onSuccess
                onFailed:(OnFailed)onFailed;

/// 发送IM消息
/// @param serverId 群聊ID
/// @param text 文本消息内容
- (void)sendGroupMessage:(NSString *)serverId
                    text:(NSString *)text;




///获取联系人列表
- (void)getContactListonSuccess:(OnSuccess)onSuccess
                       onFailed:(OnFailed)onFailed;


@end

NS_ASSUME_NONNULL_END
