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

#import "RNViewController.h"
#import "RNBlurModalView.h"
#import <QuartzCore/QuartzCore.h>

@interface RNViewController ()
@property (weak, nonatomic) IBOutlet UIImageView *imageView;

@end

@implementation RNViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onDemoButton:(id)sender {
#warning Change this to see a custom view
    BOOL useCustomView = NO;
        
    RNBlurModalView *modal;
    if (useCustomView) {
        UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 100, 100)];
        view.backgroundColor = [UIColor redColor];
        view.layer.cornerRadius = 5.f;
        view.layer.borderColor = [UIColor blackColor].CGColor;
        view.layer.borderWidth = 5.f;
        
        modal = [[RNBlurModalView alloc] initWithView:view];
    }
    else {
        modal = [[RNBlurModalView alloc] initWithTitle:@"Hello world! Hello world! Hello world! Hello world! Hello world! Hello world! Hello world!" message:@"This is the default modal for RNBlurModalView. Feel free to pass any UIView to it as you wish!"];
        modal.defaultHideBlock = ^{
            NSLog(@"Code called after the modal view is hidden");
        };
    }
//    modal.dismissButtonRight = YES;
    [modal show];
}


@end
