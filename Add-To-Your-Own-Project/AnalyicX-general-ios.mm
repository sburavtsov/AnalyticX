#include "AnalyticX.h"
#import "AnalyticXStringUtil.h"

const char * AnalyticX::getCountryCode() {
	
	NSLocale *locale = [NSLocale currentLocale];
	NSString *countryCode = [locale objectForKey: NSLocaleCountryCode];
	return [AnalyticXStringUtil cstringFromNSString:countryCode];
}

const char * AnalyticX::getCurrentDateWithFormat(const char *dateStringFormat) {
	
	NSDate *date = [NSDate date];
	NSDateFormatter *dateFormatter = [[[NSDateFormatter alloc] init] autorelease];
	[dateFormatter setDateFormat:[AnalyticXStringUtil nsstringFromCString:dateStringFormat]];
	NSString *formattedDateString = [dateFormatter stringFromDate:date];
	return [AnalyticXStringUtil cstringFromNSString:formattedDateString];
}

const char * AnalyticX::generateUniqueUserID() {
	
	CFUUIDRef uuidRef = CFUUIDCreate(NULL);
	CFStringRef uuidStringRef = CFUUIDCreateString(NULL, uuidRef);
	CFRelease(uuidRef);
	NSString *ident = [NSString stringWithString:(NSString *)uuidStringRef];
	CFRelease(uuidStringRef);
	return [AnalyticXStringUtil cstringFromNSString:ident];
}