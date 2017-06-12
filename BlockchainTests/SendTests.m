//
//  SendTests.m
//  Blockchain
//
//  Created by kevinwu on 2/28/17.
//  Copyright © 2017 Blockchain Luxembourg S.A. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "KIFUITestActor+Login.h"
#import "LocalizationConstants.h"
#import "Blockchain-Prefix.pch"
#import "TestAccounts.h"

@interface SendTests : XCTestCase

@end

@implementation SendTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
    
    if ([[[UIApplication sharedApplication] keyWindow] accessibilityElementWithLabel:ACCESSIBILITY_LABEL_CREATE_NEW_WALLET] != nil) {
    } else if ([[[UIApplication sharedApplication] keyWindow] accessibilityElementWithLabel:ACCESSIBILITY_LABEL_FORGET_WALLET] != nil) {
        [tester forgetWallet];
    } else {
        [tester enterPIN];
        [tester logoutAndForgetWallet];
    }
         
    [tester manualPairWithGUID:GUID_SEND_WALLET password:PASSWORD_SEND_WALLET];
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testSendAmounts {
    
    [tester goToSend];
    [tester typeInAddress];
    
    [tester confirmSendAmountNoDecimal];
    [tester confirmSendAmountArabicNumeralsNoDecimal];
    
    [tester confirmSendAmountDecimalPeriodDecimalFirst];
    [tester confirmSendAmountDecimalPeriodZeroThenDecimal];
    [tester confirmSendAmountDecimalPeriodNumberThenDecimal];
    [tester confirmSendAmountDecimalPeriodArabicTextDecimalFirst];
    [tester confirmSendAmountDecimalPeriodArabicTextZeroThenDecimal];
    [tester confirmSendAmountDecimalPeriodArabicTextNumberThenDecimal];
    
    [tester confirmSendAmountDecimalCommaDecimalFirst];
    [tester confirmSendAmountDecimalCommaZeroThenDecimal];
    [tester confirmSendAmountDecimalCommaNumberThenDecimal];
    [tester confirmSendAmountDecimalCommaArabicTextDecimalFirst];
    [tester confirmSendAmountDecimalCommaArabicTextZeroThenDecimal];
    [tester confirmSendAmountDecimalCommaArabicTextNumberThenDecimal];
    
    [tester confirmSendAmountDecimalArabicCommaDecimalFirst];
    [tester confirmSendAmountDecimalArabicCommaZeroThenDecimal];
    [tester confirmSendAmountDecimalArabicCommaNumberThenDecimal];
    [tester confirmSendAmountDecimalArabicCommaAndTextDecimalFirst];
    [tester confirmSendAmountDecimalArabicCommaAndTextZeroThenDecimal];
    [tester confirmSendAmountDecimalArabicCommaAndTextNumberThenDecimal];
}

@end