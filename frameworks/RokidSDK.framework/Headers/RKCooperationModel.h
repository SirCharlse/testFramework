//
//  RKCooperationModel.h
//  iOSRokid
//
//  Created by 张小饼 on 2021/4/19.
//

#import <Foundation/Foundation.h>
#import <RKCooperationCore/RKCooperationCore-swift.h>

NS_ASSUME_NONNULL_BEGIN

//@class RKIMUser;
@interface RKSDKInfo: NSObject
/// 商户服务器地址 （默认使用标准产品host）
@property(nonatomic, copy, nullable) NSString *apiHost;
/// 用户token
@property(nonatomic, copy) NSString *token;
///个人信息
@property(nonatomic, strong) RKUser *user;
/// IM
/// IMURL
@property(nonatomic, copy, nullable) NSString *imURL;
///IMsocket
@property(nonatomic, copy, nullable) NSString *socketUrl;


///鉴权参数
///appId
@property(nonatomic, copy) NSString *appId;
///apiServer
@property(nonatomic, copy) NSString *apiServer;

@end


@interface RKContactInfo: NSObject
/// 用户id
@property(nonatomic, copy) NSString *userId;
/// JC授权码
@property(nonatomic, copy) NSString *licenseCode;
/// 真实名字
@property(nonatomic, copy) NSString *realName;
/// 头像
@property(nonatomic, copy, nullable) NSString *headUrl;
/// 0-离线 1-在线
@property (nonatomic, assign) NSInteger status;

@end


@interface RKFileInfo : NSObject
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *fileName;
@end

/**
 IM数据
 */

//用户信息
@interface RKChatMember : NSObject

/// 用户id
@property (nonatomic, copy) NSString *userId;
///用户名
@property (nonatomic, copy) NSString *username;
///真实名字
@property (nonatomic, copy) NSString *realName;
///岗位信息
@property (nonatomic, copy) NSString *postName;
///头像URL
@property (nonatomic, copy) NSString *headPortrait;
///部门
@property (nonatomic, copy) NSString *unitName;

@property (nonatomic, copy) NSString *licenseCode;
@property (nonatomic, copy) NSString *displayName;

@end

//群聊信息
@interface RKChatInfo : NSObject
//群聊ID
@property (nonatomic, copy) NSString *groupId;
//群聊名称
@property (nonatomic, copy) NSString *groupName;
//群聊成员
@property (nonatomic, strong) NSArray<NSString *> *userList;
@property (nonatomic, strong) NSArray<RKChatMember *> *chatMembers;
//群聊任务主题名称
@property (nonatomic, copy) NSString *subjectName;
////群聊任务主题内容
@property (nonatomic, copy) NSString *subjectContent;

//时间戳
@property (nonatomic, assign)NSInteger tms;
//群总人数
@property (nonatomic, assign)NSInteger totalAccountNum;
//群内最后一条消息

//群消息未读数
@property (nonatomic, assign)NSInteger unReadCount;
//群头像
@property (nonatomic, copy) NSString *groupAvatars;
//群主ID
@property (nonatomic, copy) NSString *ownerId;
//群公告
@property (nonatomic, copy) NSString *groupConfig;
@end


NS_ASSUME_NONNULL_END

