#include "AnalyticX.h"
#import "Mixpanel.h"
#import "AnalyticXStringUtil.h"

void AnalyticX::mixpanelSharedInstanceWithToken(const char * token) {

	NSString *tokenString = [AnalyticXStringUtil nsstringFromCString:token];
    [Mixpanel sharedInstanceWithToken: tokenString];
}

const char *AnalyticX::mixpanelGetDistinctID() {

	return [AnalyticXStringUtil cstringFromNSString:[Mixpanel sharedInstance].distinctId];
}

void AnalyticX::mixpanelIdentify(const char * distinctId) {
	
	[[Mixpanel sharedInstance] identify:[AnalyticXStringUtil nsstringFromCString:distinctId]];
}

void AnalyticX::mixpanelCreateAliasForDistinctID(const char *alias, const char *distinctID) {
	
	[[Mixpanel sharedInstance] createAlias:[AnalyticXStringUtil nsstringFromCString:alias]
							 forDistinctID:[AnalyticXStringUtil nsstringFromCString:distinctID]];
}

void AnalyticX::mixpanelTrackEvent(const char *event) {
	
	[[Mixpanel sharedInstance] track:[AnalyticXStringUtil nsstringFromCString:event]];
}

void AnalyticX::mixpanelTrackEventWithProperties(const char *event, cocos2d::CCDictionary * properties) {
	
	[[Mixpanel sharedInstance] track:[AnalyticXStringUtil nsstringFromCString:event]
						  properties:[AnalyticXStringUtil nsDictionaryFromCCDictionary:properties]];
}

void AnalyticX::mixpanelRegisterSuperProperties(cocos2d::CCDictionary * superProperties) {
	
	[[Mixpanel sharedInstance] registerSuperProperties:[AnalyticXStringUtil nsDictionaryFromCCDictionary:superProperties]];
}

void AnalyticX::mixpanelFlush() {
	
	[[Mixpanel sharedInstance] flush];
}

void AnalyticX::mixpanelTrackCharge(double amount, cocos2d::CCDictionary * properties) {
	
	[[Mixpanel sharedInstance] identify:[Mixpanel sharedInstance].distinctId];
	[[[Mixpanel sharedInstance] people] trackCharge:[NSNumber numberWithDouble:amount]
									 withProperties:[AnalyticXStringUtil nsDictionaryFromCCDictionary:properties]];
}