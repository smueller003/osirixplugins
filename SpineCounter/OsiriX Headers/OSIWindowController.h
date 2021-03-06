/*=========================================================================
  Program:   OsiriX

  Copyright (c) OsiriX Team
  All rights reserved.
  Distributed under GNU - GPL
  
  See http://www.osirix-viewer.com/copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.
=========================================================================*/

/** \brief base class for Window Controllers in OsiriX
*
*Root class for the Viewer Window Controllers such as ViewerController
*and Window3DController
*/

#import <Cocoa/Cocoa.h>


enum OsiriXBlendingTypes {BlendingPlugin = -1, BlendingFusion = 1, BlendingSubtraction, BlendingMultiplication, BlendingRed, BlendingGreen, BlendingBlue, Blending2DRegistration, Blending3DRegistration, BlendingLL};


@interface OSIWindowController : NSWindowController {
	int _blendingType;
}

- (NSMutableArray*) pixList;
- (void)windowWillClose:(NSNotification *)notification;
- (void) addToUndoQueue:(NSString*) what;
- (int)blendingType;

- (IBAction) redo:(id) sender;
- (IBAction) undo:(id) sender;

- (void) applyShading:(id) sender;

#pragma mark-
#pragma mark current Core Data Objects
- (NSManagedObject *)currentStudy;
- (NSManagedObject *)currentSeries;
- (NSManagedObject *)currentImage;

- (float)curWW;
- (float)curWL;
@end
