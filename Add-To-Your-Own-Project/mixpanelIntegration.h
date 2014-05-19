//
//  mixpanel.h
//  buildanempire
//
//  Created by Sergey Buravtsov on 21/03/14.
//
//

static void mixpanelSharedInstanceWithToken(const char * token);
static const char *mixpanelGetDistinctID();
static void mixpanelIdentify(const char * distinctId);
static void mixpanelCreateAliasForDistinctID(const char *alias, const char *distinctID);
static void mixpanelTrackEvent(const char *event);
static void mixpanelTrackEventWithProperties(const char *event, cocos2d::CCDictionary * properties);
static void mixpanelRegisterSuperProperties(cocos2d::CCDictionary * superProperties);
static void mixpanelFlush();
static void mixpanelTrackCharge(double amount, cocos2d::CCDictionary *properties);
