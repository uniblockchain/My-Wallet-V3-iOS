//
//  TabControllerManager.h
//  Blockchain
//
//  Created by kevinwu on 8/21/17.
//  Copyright © 2017 Blockchain Luxembourg S.A. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TabViewController.h"
#import "Assets.h"
#import "TransactionsBitcoinViewController.h"
#import "SendBitcoinViewController.h"
#import "ReceiveCoinsViewController.h"
#import "DashboardViewController.h"
#import "SendEtherViewController.h"
#import "TransactionsEtherViewController.h"
#import "ReceiveEtherViewController.h"
#import "ExchangeOverviewViewController.h"

@protocol TabControllerDelegate
- (void)toggleSideMenu;
@end

@interface TabControllerManager : NSObject <AssetDelegate>
@property (nonatomic) AssetType assetType;
@property (nonatomic) NSDecimalNumber *latestEthExchangeRate;

@property (weak, nonatomic) id <TabControllerDelegate> delegate;

@property (strong, nonatomic) TabViewcontroller *tabViewController;

@property (strong, nonatomic) DashboardViewController *dashboardViewController;
@property (strong, nonatomic) TransactionsBitcoinViewController *transactionsBitcoinViewController;
@property (strong, nonatomic) ReceiveCoinsViewController *receiveBitcoinViewController;
@property (strong, nonatomic) SendBitcoinViewController *sendBitcoinViewController;

@property (strong, nonatomic) SendEtherViewController *sendEtherViewController;
@property (strong, nonatomic) TransactionsEtherViewController *transactionsEtherViewController;
@property (strong, nonatomic) ReceiveEtherViewController *receiveEtherViewController;

@property (strong, nonatomic) ExchangeOverviewViewController *exchangeOverviewViewController;

- (void)reload;
- (void)reloadAfterMultiAddressResponse;
- (void)reloadMessageViews;
- (void)didSetLatestBlock:(LatestBlock *)block;
- (void)didGetMessagesOnFirstLoad;

- (void)logout;
- (void)forgetWallet;

- (void)didFetchEthExchangeRate:(NSNumber *)rate;

// Navigation
- (void)dashBoardClicked:(UITabBarItem *)sender;
- (void)receiveCoinClicked:(UITabBarItem *)sender;
- (void)transactionsClicked:(UITabBarItem *)sender;
- (void)sendCoinsClicked:(UITabBarItem *)sender;
- (void)qrCodeButtonClicked;

- (void)showReceiveEther;

// Send Bitcoin View Controller
- (BOOL)isSending;
- (void)showSendCoins;
- (void)setupTransferAllFunds;
- (void)hideSendKeyboard;
- (void)reloadSendController;
- (void)clearSendToAddressAndAmountFields;
- (BOOL)isSendViewControllerTransferringAll;
- (void)enableSendPaymentButtons;
- (void)setupBitcoinPaymentFromURLHandlerWithAmountString:(NSString *)amountString address:(NSString *)address;
- (void)transferFundsToDefaultAccountFromAddress:(NSString *)address;
- (void)sendFromWatchOnlyAddress;
- (void)didCheckForOverSpending:(NSNumber *)amount fee:(NSNumber *)fee;
- (void)didGetMaxFee:(NSNumber *)fee amount:(NSNumber *)amount dust:(NSNumber *)dust willConfirm:(BOOL)willConfirm;
- (void)didUpdateTotalAvailable:(NSNumber *)sweepAmount finalFee:(NSNumber *)finalFee;
- (void)didGetFee:(NSNumber *)fee dust:(NSNumber *)dust txSize:(NSNumber *)txSize;
- (void)didChangeSatoshiPerByte:(NSNumber *)sweepAmount fee:(NSNumber *)fee dust:(NSNumber *)dust updateType:(FeeUpdateType)updateType;
- (void)didGetSurgeStatus:(BOOL)surgeStatus;
- (void)updateSendBalance:(NSNumber *)balance fees:(NSDictionary *)fees;
- (void)updateTransferAllAmount:(NSNumber *)amount fee:(NSNumber *)fee addressesUsed:(NSArray *)addressesUsed;
- (void)showSummaryForTransferAll;
- (void)sendDuringTransferAll:(NSString *)secondPassword;
- (void)didErrorDuringTransferAll:(NSString *)error secondPassword:(NSString *)secondPassword;
- (void)updateLoadedAllTransactions:(NSNumber *)loadedAll;
- (void)receivedTransactionMessage;
- (DestinationAddressSource)getSendAddressSource;
- (void)setupPaymentRequest:(ContactTransaction *)transaction;
- (void)setupSendToAddress:(NSString *)address;

// Send Eth View Controller
- (void)didUpdateEthPayment:(NSDictionary *)ethPayment;
- (void)didSendEther;
- (void)didErrorDuringEtherSend:(NSString *)error;

// Receive View Controller
- (void)didGetEtherAddressWithSecondPassword;
- (void)clearReceiveAmounts;
- (void)didSetDefaultAccount;
- (void)paymentReceived:(NSDecimalNumber *)amount showBackupReminder:(BOOL)showBackupReminder;

// Transactions View Controller
- (void)updateTransactionsViewControllerData:(MultiAddressResponse *)data;
- (void)filterTransactionsByAccount:(int)accountIndex filterLabel:(NSString *)filterLabel;
- (NSInteger)getFilterIndex;
- (void)filterTransactionsByImportedAddresses;
- (void)selectPayment:(NSString *)payment;
- (void)showTransactionDetailForHash:(NSString *)hash;
- (void)setTransactionsViewControllerMessageIdentifier:(NSString *)identifier;

- (void)removeTransactionsFilter;
- (void)showFilterResults;
- (void)reloadSymbols;
- (void)didChangeLocalCurrency;

- (void)didRejectContactTransaction;

- (void)hideSendAndReceiveKeyboards;

- (void)showTransactions;

- (void)updateBadgeNumber:(NSInteger)number forSelectedIndex:(int)index;

- (void)exchangeClicked;
- (void)didCreateEthAccountForExchange;
- (void)didGetExchangeTrades:(NSArray *)trades;
- (void)didGetExchangeRate:(NSDictionary *)result;
- (void)didGetAvailableBtcBalance:(NSDictionary *)result;
- (void)didGetAvailableEthBalance:(NSDictionary *)result;
- (void)didBuildExchangeTrade:(NSDictionary *)tradeInfo;
- (void)didShiftPayment:(NSDictionary *)info;
- (void)showGetAssetsAlert;
@end
