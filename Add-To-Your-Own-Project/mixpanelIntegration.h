//
//  mixpanel.h
//  buildanempire
//
//  Created by Sergey Buravtsov on 21/03/14.
//
//

#ifndef buildanempire_mixpanel_h
#define buildanempire_mixpanel_h

static void mixpanelSharedInstanceWithToken(const char * token);
static void mixpanelIdentify(const char * distinctId);
static void mixpanelCreateAliasForDistinctID(const char *alias, const char *distinctID);
static void mixpanelTrackEvent(const char *event);
static void mixpanelTrackEventWithProperties(const char *event, cocos2d::CCDictionary * properties);
static void mixpanelRegisterSuperProperties(cocos2d::CCDictionary * superProperties);
static void mixpanelReset();
static void mixpanelFlush();

#endif
