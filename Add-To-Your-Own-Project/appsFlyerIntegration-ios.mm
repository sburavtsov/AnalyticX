#include "AnalyticX.h"
#import "AppsFlyerTracker.h"
#import "AnalyticXStringUtil.h"

void AnalyticX::appsFlyerStartSession(const char *appID, const char * devKey) {
	
	[AppsFlyerTracker sharedTracker].appsFlyerDevKey = [AnalyticXStringUtil nsstringFromCString:devKey];
	[AppsFlyerTracker sharedTracker].appleAppID = [AnalyticXStringUtil nsstringFromCString:appID];
}

void AnalyticX::appsFlyerSetCustomerUserID(const char *customerUserID) {
	
	[AppsFlyerTracker sharedTracker].customerUserID = [AnalyticXStringUtil nsstringFromCString:customerUserID];
}

/*
void AnalyticX::appsFlyerTrackAppLaunch() {

	[[AppsFlyerTracker sharedTracker] trackAppLaunch];
}
*/
void AnalyticX::appsFlyerSetCurrencyCode(const char *currencyCode) {
	
	[AppsFlyerTracker sharedTracker].currencyCode = [AnalyticXStringUtil nsstringFromCString:currencyCode];
}

void AnalyticX::appsFlyerTrackEventWithValue(const char *eventName, const char *eventValue) {
	
	[[AppsFlyerTracker sharedTracker] trackEvent:[AnalyticXStringUtil nsstringFromCString:eventName]
									  withValue:[AnalyticXStringUtil nsstringFromCString:eventValue]];
}
