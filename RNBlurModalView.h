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

/** The string for the NSNotificationCenter. Will be called when the window is shown */
extern NSString * const kRNBlurDidShowNotification;
/** The string for the NSNotificationCenter. Will be called when the window is hidden */
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

/**
 * A Modal view to hold content, blurring all the background
 */
@interface RNBlurModalView : UIView

/** Tells the user if the window is showing. */
@property (assign, readonly) BOOL isVisible;
/** Specifies the duration of the animation. */
@property (assign) CGFloat animationDuration;
/** Specifies the delay before the animation starts. */
@property (assign) CGFloat animationDelay;
/** Animation options */
@property (assign) UIViewAnimationOptions animationOptions;
/** Changes the position of the button from the left (FALSE) to the right (TRUE) */
@property (assign) BOOL dismissButtonRight;
/** Block called when the view is hidden */
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

/**
 * Constructor with parent view controller and custom content
 * @param viewController The parent view controller
 * @param view The content to show
 * @return self or nil if something went wrong
 */
- (id)initWithViewController:(UIViewController*)viewController view:(UIView*)view;

/**
 * Constructor with parent view controller. It creates a view with text.
 * @param viewController The parent view controller
 * @param title The title of the window
 * @param message The message to show to the user
 * @return self or nil if something went wrong
 */
- (id)initWithViewController:(UIViewController*)viewController title:(NSString*)title message:(NSString*)message;

/**
 * Constructor with parent view and custom content
 * @param parentView The parent view
 * @param view The content to show
 * @return self or nil if something went wrong
 */
- (id)initWithParentView:(UIView*)parentView view:(UIView*)view;

/**
 * Constructor with parent view. It creates a view with text.
 * @param parentView The parent view
 * @param title The title of the window
 * @param message The message to show to the user
 * @return self or nil if something went wrong
 */
- (id)initWithParentView:(UIView*)parentView title:(NSString*)title message:(NSString*)message;

/**
 * Constructor with custom content
 * @param view The content to show
 * @return self or nil if something went wrong
 */
- (id)initWithView:(UIView*)view;

/**
 * Constructor with strings. It will create a view with a message
 * @param title The title of the window
 * @param message The message to show to the user
 * @return self or nil if something went wrong
 */
- (id)initWithTitle:(NSString*)title message:(NSString*)message;

/**
 * Shows the window
 */
- (void)show;

/**
 * Shows the window with a certain animation configuration
 * @param duration The duration of the animation
 * @param delay The delay of the animation
 * @param options The animation options
 * @param completion The action to perform at the end of the animation
 */
- (void)showWithDuration:(CGFloat)duration delay:(NSTimeInterval)delay options:(UIViewAnimationOptions)options completion:(void (^)(void))completion;

/**
 * Hides the window
 */
- (void)hide;

/**
 * Hides the control with a certain animation configuration
 * @param duration The duration of the animation
 * @param delay The delay of the animation
 * @param options The animation options
 * @param completion The action to perform at the end of the animation
 */
- (void)hideWithDuration:(CGFloat)duration delay:(NSTimeInterval)delay options:(UIViewAnimationOptions)options completion:(void (^)(void))completion;

/**
 * Hides the close button in the top corner
 * @param hide TRUE if you want to hide the close button, or FALSE if you want to unhide it.
 */
-(void)hideCloseButton:(BOOL)hide;

@end