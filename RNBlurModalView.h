/*
 * RNBlurModal
 *
 * Created by Ryan Nystrom on 10/2/12.
 * Copyright (c) 2012 Ryan Nystrom. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

extern NSString * const kRNBlurDidShowNotification;
extern NSString * const kRNBlurDidHidewNotification;

/**
 * Enum for the alignment of the content.
 * The view can be aligned to the borders (top, bottom, left or right),
 * or can be centered (horizontally or vertically, or both)
 */
typedef NS_ENUM(NSUInteger, RNBlurModalViewAlignment){
    RNBlurModalViewAlignmentLeft        = 0,
    RNBlurModalViewAlignmentTop         = 0,
    RNBlurModalViewAlignmentCenter      = 1,
    RNBlurModalViewAlignmentRight       = 2,
    RNBlurModalViewAlignmentBottom      = 2,
};

@interface RNBlurModalView : UIView

@property (assign, readonly) BOOL isVisible;

@property (assign) CGFloat animationDuration;
@property (assign) CGFloat animationDelay;
@property (assign) UIViewAnimationOptions animationOptions;
@property (assign) BOOL dismissButtonRight;
@property (nonatomic, copy) void (^defaultHideBlock)(void);
/** Alignment of the content view (left, center or right) */
@property (assign, nonatomic) RNBlurModalViewAlignment horizontalAlignment;
/** Alignment of the content view (top, center or bottom) */
@property (assign, nonatomic) RNBlurModalViewAlignment verticalAlignment;
/** Space between the content view and the screen border.
 * if horizontalAlignment == NSBlurModalViewAlignmentCenter it will be ignored */
@property (assign, nonatomic) CGFloat horizontalSpacing;
/** Space between the content view and the screen border.
 * if VerticalAlignment == NSBlurModalViewAlignmentCenter it will be ignored */
@property (assign, nonatomic) CGFloat verticalSpacing;

- (id)initWithViewController:(UIViewController*)viewController view:(UIView*)view;
- (id)initWithViewController:(UIViewController*)viewController title:(NSString*)title message:(NSString*)message;
- (id)initWithParentView:(UIView*)parentView view:(UIView*)view;
- (id)initWithParentView:(UIView*)parentView title:(NSString*)title message:(NSString*)message;
- (id)initWithView:(UIView*)view;
- (id)initWithTitle:(NSString*)title message:(NSString*)message;

- (void)show;
- (void)showWithDuration:(CGFloat)duration delay:(NSTimeInterval)delay options:(UIViewAnimationOptions)options completion:(void (^)(void))completion;

- (void)hide;
- (void)hideWithDuration:(CGFloat)duration delay:(NSTimeInterval)delay options:(UIViewAnimationOptions)options completion:(void (^)(void))completion;

-(void)hideCloseButton:(BOOL)hide;


@end