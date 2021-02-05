#import <Foundation/Foundation.h>
#import "SWGError.h"
#import "SWGNewOrder.h"
#import "SWGOrder.h"
#import "SWGOrderChance.h"
#import "SWGOrderInfo.h"
#import "SWGOrderbook.h"
#import "SWGApi.h"

/**
* Upbit Open API
* ## REST API for Upbit Exchange - Base URL: [https://api.upbit.com] - Official Upbit API Documents: [https://docs.upbit.com] - Official Support email: [open-api@upbit.com] 
*
* OpenAPI spec version: 1.0.0
* Contact: ujhin942@gmail.com
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
* Do not edit the class manually.
*/



@interface SWGOrderApi: NSObject <SWGApi>

extern NSString* kSWGOrderApiErrorDomain;
extern NSInteger kSWGOrderApiMissingParamErrorCode;

-(instancetype) initWithApiClient:(SWGApiClient *)apiClient NS_DESIGNATED_INITIALIZER;

/// 주문 취소 접수
/// ## 주문 UUID를 통해 해당 주문에 대한 취소 접수를 한다.  **NOTE**: `uuid` 혹은 `identifier` 둘 중 하나의 값이 반드시 포함되어야 합니다. 
///
/// @param uuid 취소할 주문의 UUID  (optional)
/// @param identifier 조회용 사용자 지정 값  (optional)
/// 
///  code:200 message:"OK",
///  code:400 message:"Bad Request",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found",
///  code:429 message:"Too Many Requests",
///  code:500 message:"Internal Server Error"
///
/// @return SWGOrder*
-(NSURLSessionTask*) orderCancelWithUuid: (NSString*) uuid
    identifier: (NSString*) identifier
    completionHandler: (void (^)(SWGOrder* output, NSError* error)) handler;


/// 주문 가능 정보
/// ## 마켓별 주문 가능 정보를 확인한다. 
///
/// @param market Market ID 
/// 
///  code:200 message:"OK",
///  code:400 message:"Bad Request",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found",
///  code:429 message:"Too Many Requests",
///  code:500 message:"Internal Server Error"
///
/// @return SWGOrderChance*
-(NSURLSessionTask*) orderChanceWithMarket: (NSString*) market
    completionHandler: (void (^)(SWGOrderChance* output, NSError* error)) handler;


/// 개별 주문 조회
/// ## 주문 UUID를 통해 개별 주문건을 조회한다.  **NOTE**: `uuid` 혹은 `identifier` 둘 중 하나의 값이 반드시 포함되어야 합니다. 
///
/// @param uuid 주문 UUID  (optional)
/// @param identifier 조회용 사용자 지정 값  (optional)
/// 
///  code:200 message:"OK",
///  code:400 message:"Bad Request",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found",
///  code:429 message:"Too Many Requests",
///  code:500 message:"Internal Server Error"
///
/// @return SWGOrderInfo*
-(NSURLSessionTask*) orderInfoWithUuid: (NSString*) uuid
    identifier: (NSString*) identifier
    completionHandler: (void (^)(SWGOrderInfo* output, NSError* error)) handler;


/// 주문 리스트 조회
/// ## 주문 리스트를 조회한다. 
///
/// @param market 마켓 아이디  (optional)
/// @param state 주문 상태   - wait : 체결 대기 (default)   - done : 전체 체결 완료   - cancel : 주문 취소  (optional)
/// @param states 주문 상태의 목록  (optional)
/// @param uuids 주문 UUID의 목록  (optional)
/// @param identifiers 주문 identifier의 목록  (optional)
/// @param page 페이지 수, default: 1  (optional)
/// @param limit 요청 개수, default: 100  (optional)
/// @param orderBy 정렬 방식 - asc : 오름차순 - desc : 내림차순 (default)  (optional)
/// 
///  code:200 message:"OK",
///  code:400 message:"Bad Request",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found",
///  code:429 message:"Too Many Requests",
///  code:500 message:"Internal Server Error"
///
/// @return NSArray<SWGOrder>*
-(NSURLSessionTask*) orderInfoAllWithMarket: (NSString*) market
    state: (NSString*) state
    states: (NSArray<NSString*>*) states
    uuids: (NSArray<NSString*>*) uuids
    identifiers: (NSArray<NSString*>*) identifiers
    page: (NSNumber*) page
    limit: (NSNumber*) limit
    orderBy: (NSString*) orderBy
    completionHandler: (void (^)(NSArray<SWGOrder>* output, NSError* error)) handler;


/// 주문하기
/// ## 주문 요청을 한다.  **NOTE**: 원화 마켓 가격 단위를 확인하세요.  원화 마켓에서 주문을 요청 할 경우, [원화 마켓 주문 가격 단위](https://docs.upbit.com/docs/market-info-trade-price-detail)를 확인하여 값을 입력해주세요.  **NOTE**: identifier 파라미터 사용  `identifier`는 서비스에서 발급하는 `uuid`가 아닌 이용자가 직접 발급하는 키값으로, 주문을 조회하기 위해 할당하는 값입니다. 해당 값은 사용자의 전체 주문 내 유일한 값을 전달해야하며, 비록 주문 요청시 오류가 발생하더라도 같은 값으로 다시 요청을 보낼 수 없습니다.  주문의 성공 / 실패 여부와 관계없이 중복해서 들어온 `identifier` 값에서는 중복 오류가 발생하니, 매 요청시 새로운 값을 생성해주세요.  **NOTE**: 시장가 주문  시장가 주문은 `ord_type` 필드를 `price` or `market` 으로 설정해야됩니다. 매수 주문의 경우 `ord_type`을 `price`로 설정하고 `volume`을 `null` 혹은 제외해야됩니다. 매도 주문의 경우 `ord_type`을 `market`로 설정하고 `price`을 `null` 혹은 제외해야됩니다. 
///
/// @param market 마켓 ID (필수) 
/// @param side 주문 종류 (필수) - bid : 매수 - ask : 매도 
/// @param ordType 주문 타입 (필수) - limit : 지정가 주문 - price : 시장가 주문(매수) - market : 시장가 주문(매도) 
/// @param volume 주문량 (지정가, 시장가 매도 시 필수)  (optional) (default to null)
/// @param price 주문 가격. (지정가, 시장가 매수 시 필수)  ex) KRW-BTC 마켓에서 1BTC당 1,000 KRW로 거래할 경우, 값은 1000 이 된다. ex) KRW-BTC 마켓에서 1BTC당 매도 1호가가 500 KRW 인 경우, 시장가 매수 시 값을 1000으로 세팅하면 2BTC가 매수된다. (수수료가 존재하거나 매도 1호가의 수량에 따라 상이할 수 있음)  (optional) (default to null)
/// @param identifier 조회용 사용자 지정값 (선택)  (optional)
/// 
///  code:200 message:"OK",
///  code:201 message:"Create",
///  code:400 message:"Bad Request",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found",
///  code:429 message:"Too Many Requests",
///  code:500 message:"Internal Server Error"
///
/// @return SWGNewOrder*
-(NSURLSessionTask*) orderNewWithMarket: (NSString*) market
    side: (NSString*) side
    ordType: (NSString*) ordType
    volume: (NSString*) volume
    price: (NSString*) price
    identifier: (NSString*) identifier
    completionHandler: (void (^)(SWGNewOrder* output, NSError* error)) handler;


/// 시세 호가 정보(Orderbook) 조회
/// ## 호가 정보 조회 
///
/// @param markets 마켓 코드 목록 (ex. KRW-BTC,KRW-ADA) 
/// 
///  code:200 message:"OK",
///  code:400 message:"Bad Request",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found",
///  code:429 message:"Too Many Requests",
///  code:500 message:"Internal Server Error"
///
/// @return NSArray<SWGOrderbook>*
-(NSURLSessionTask*) orderOrderbookWithMarkets: (NSArray<NSString*>*) markets
    completionHandler: (void (^)(NSArray<SWGOrderbook>* output, NSError* error)) handler;



@end
