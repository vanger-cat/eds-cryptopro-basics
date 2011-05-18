//
//  PaneViewController.h
//  Pane
//
//  Created by Кондакова Татьяна Андреевна on 06.12.10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ModalViewControllerDelegate<NSObject>

-(void) didDismissModalView;

@end

@interface PaneViewController : UIViewController<ModalViewControllerDelegate, UINavigationControllerDelegate> {
		id<ModalViewControllerDelegate> delegate;
}
@property (nonatomic, retain) NSString * UIURL;
@property (nonatomic, retain) NSString * tokenID;
@property (nonatomic, retain) NSString * password;
@property (nonatomic, retain) NSMutableArray * req_ids;
	
	@property (nonatomic, retain) IBOutlet UILabel *button;
	@property (nonatomic, retain) id<ModalViewControllerDelegate> delegate;
	
	-(IBAction)startGettingCertificate:(id)sender;
	-(IBAction)startDeletingContainer:(id)sender;
	-(IBAction) dismissView:(id)sender;
	-(void)deleteContainer;
	-(void)didDismissModalView;
@end
