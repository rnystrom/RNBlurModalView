RNBlurModalView
====

RNBlurModal adds *depth* to the traditional modal/alert view. Calling the view is incredibly similar to setting up and showing a UIAlertView. You can also setup your own custom views and display them with a blurry background. The goal is to truly draw the user's focus directly to your alert using natural effects. This project works on all iOS devices at all orientations with ARC.

<img src="https://github.com/rnystrom/RNBlurModalView/raw/master/images/image.jpg" />

## Installation

Super simple. Just drag & drop RNBlurModalView.h/.m into your project. In your Project, find the Build Phases tab and expand Link Binary With Libraries. Add the following frameworks to your project: 

* QuartzCore.framework
* Accelerate.framework

Additionally in your project, under the Build Phases tab, expand Compile Sources and add RNBlurModalView.m.

## Usage

The simplest way to get up and running with RNBlurModalView is to display a default view. Inside of your view controller, write the following code:

``` objective-c
RNBlurModalView *modal = [[RNBlurModalView alloc] initWithViewController:self title:@"Hello world!" message:@"Pur your message here."];
[modal show];
```

You can also create a modal view with your own custom UIViews:

``` objective-c
RNBlurModalView *modal = [[RNBlurModalView alloc] initWithViewController:self view:view];
[modal show];
```

## Caveat

The only thing I'll warn users about is that animations beneath the modal will be "paused". When it comes down to it, I am overlaying a UIImage on top of your controller. I've tried messing with some hacky <code>CADisplayLink</code> methods, but I can't seem to get a screenshot of the present *state* of the controller, just the configuration.

## Configuration

Set a couple of different properties of your modal view to change how it appears:

``` objective-c
@property (assign) CGFloat animationDuration;
@property (assign) CGFloat animationDelay;
@property (assign) UIViewAnimationOptions animationOptions;
```

For brevity, you can instead set these properties in the <code>show:</code> and <code>hide:</code> methods.

``` objective-c
// show
- (void)show;
- (void)showWithDuration:(CGFloat)duration delay:(NSTimeInterval)delay options:(UIViewAnimationOptions)options completion:(void (^)(void))completion;
// hide
- (void)hide;
- (void)hideWithDuration:(CGFloat)duration delay:(NSTimeInterval)delay options:(UIViewAnimationOptions)options completion:(void (^)(void))completion;
```

## KVO & Notifications

As always, I try to include some helpers in case there are other objects that need to be notified of custom events.

##### NSNotifications

``` objective-c
extern NSString * const kRNBlurDidShowNotification;
extern NSString * const kRNBlurDidHidewNotification;
```

##### KVO

``` objective-c
@property (assign, readonly) BOOL isVisible;
```

## Contributions

The drawing for the dismiss button comes from [David Keegan's](http://davidkeegan.com/) awesome [KGModal](https://github.com/kgn/KGModal) project.

The blurring algorithm is applied from this [awesome blog post](http://indieambitions.com/idevblogaday/perform-blur-vimage-accelerate-framework-tutorial/?utm_source=feedburner&utm_medium=feed&utm_campaign=Feed%3A+IndieAmbitions+%28Indie+Ambitions%29).

## Contact

* [@nystrorm](https://twitter.com/nystrorm) on Twitter
* [@rnystrom](https://github.com/rnystrom) on Github
* <a href="mailTo:rnystrom@whoisryannystrom.com">rnystrom [at] whoisryannystrom [dot] com</a>

## License

Copyright (c) 2012 Ryan Nystrom (http://whoisryannystrom.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.