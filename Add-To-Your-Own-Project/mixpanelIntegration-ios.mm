#include "AnalyticX.h"
#import "Mixpanel.h"
#import "AnalyticXStringUtil.h"

void AnalyticX::mixpanelSharedInstanceWithToken(const char * token) {

	NSString *tokenString = [AnalyticXStringUtil nsstringFromCString:token];
    [Mixpanel sharedInstanceWithToken: tokenString];
}

void AnalyticX::mixpanelIdentify(const char * distinctId) {
	
}

void AnalyticX::mixpanelTrackEvent(const char *event) {
	
}

void AnalyticX::mixpanelTrackEventWithProperties(const char *event, cocos2d::CCDictionary * properties) {
	
}

void AnalyticX::mixpanelRegisterSuperProperties(cocos2d::CCDictionary * superProperties) {
	
}

void AnalyticX::mixpanelReset() {
	
}

void AnalyticX::mixpanelFlush() {
	
}
