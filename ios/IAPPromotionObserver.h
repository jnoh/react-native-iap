#import <StoreKit/StoreKit.h>

#define RNIAP_LOG(__FORMAT__,...) NSLog((@"%s line %d%s $ " __FORMAT__), \
__PRETTY_FUNCTION__, __LINE__, \
([NSThread isMainThread] ? " (main thread)" : ""), \
##__VA_ARGS__)

@protocol IAPPromotionObserverDelegate;

@interface IAPPromotionObserver: NSObject <SKPaymentTransactionObserver>

@property (strong, nonatomic, readonly) SKPayment *payment;
@property (strong, nonatomic, readonly) SKProduct *product;
@property (weak, nonatomic) id<IAPPromotionObserverDelegate> delegate;

+ (instancetype)sharedObserver;
+ (void)startObserving;

@end

@protocol IAPPromotionObserverDelegate <NSObject>

@required
- (BOOL)shouldAddStorePayment:(SKPayment *)payment forProduct:(SKProduct *)product;

@end
