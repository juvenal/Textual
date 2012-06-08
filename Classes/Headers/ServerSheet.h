// Created by Satoshi Nakagawa <psychs AT limechat DOT net> <http://github.com/psychs/limechat>
// Modifications by Codeux Software <support AT codeux DOT com> <https://github.com/codeux/Textual>
// You can redistribute it and/or modify it under the new BSD license.

@interface ServerSheet : SheetBase
{
	NSInteger uid;
	
	IRCClient *__weak client;
	IRCClientConfig *config;
	
	NSDictionary *serverList;
	NSMutableArray *tabViewList;
	
	IBOutlet NSView *contentView;
	IBOutlet NSView *generalView;
	IBOutlet NSView *identityView;
	IBOutlet NSView *messagesView;
	IBOutlet NSView *encodingView;
	IBOutlet NSView *autojoinView;
	IBOutlet NSView *ignoresView;
	IBOutlet NSView *commandsView;
    IBOutlet NSView *floodControlView;
    IBOutlet NSView *floodControlToolView;
	IBOutlet NSView *proxyServerView;
    
    IBOutlet NSButton *outgoingFloodControl;
    IBOutlet NSSlider *floodControlMessageCount;
    IBOutlet NSSlider *floodControlDelayTimer;
	
	IBOutlet ListView *tabView;
	
	IBOutlet NSTextField *nameText;
	IBOutlet NSButton *autoReconnectCheck;
	IBOutlet NSButton *autoConnectCheck;
	IBOutlet NSButton *bouncerModeCheck;
    IBOutlet NSButton *prefersIPv6Check;
	
	IBOutlet NSComboBox *hostCombo;
	IBOutlet NSTextField *portText;
	IBOutlet NSButton *sslCheck;
	
	IBOutlet NSTextField *nickText;
	IBOutlet NSTextField *passwordText;
	IBOutlet NSTextField *usernameText;
	IBOutlet NSTextField *realNameText;
	IBOutlet NSTextField *nickPasswordText;
	IBOutlet NSTextField *altNicksText;
	
	IBOutlet NSTextView *sleepQuitMessageText;
	IBOutlet NSTextView *leavingCommentText;
	
	IBOutlet NSPopUpButton *encodingCombo;
	IBOutlet NSPopUpButton *fallbackEncodingCombo;
	
	IBOutlet NSPopUpButton *proxyCombo;
	IBOutlet NSTextField *proxyHostText;
	IBOutlet NSTextField *proxyPortText;
	IBOutlet NSTextField *proxyUserText;
	IBOutlet NSTextField *proxyPasswordText;
	
	IBOutlet ListView *channelTable;
	IBOutlet NSButton *addChannelButton;
	IBOutlet NSButton *editChannelButton;
	IBOutlet NSButton *deleteChannelButton;
	
	IBOutlet NSTextView *loginCommandsText;
	IBOutlet NSButton *invisibleCheck;
	
	IBOutlet ListView *ignoreTable;
	IBOutlet NSButton *addIgnoreButton;
	IBOutlet NSButton *editIgnoreButton;
	IBOutlet NSButton *deleteIgnoreButton;
	IBOutlet NSMenu *addIgnoreMenu;
	
	ChannelSheet *channelSheet;
	AddressBookSheet *ignoreSheet;
}

@property (nonatomic, assign) NSInteger uid;
@property (nonatomic, strong) IRCClientConfig *config;
@property (nonatomic, weak) IRCClient *client;
@property (nonatomic, strong) NSView *contentView;
@property (nonatomic, strong) NSView *generalView;
@property (nonatomic, strong) NSView *identityView;
@property (nonatomic, strong) NSView *messagesView;
@property (nonatomic, strong) NSView *encodingView;
@property (nonatomic, strong) NSView *autojoinView;
@property (nonatomic, strong) NSView *ignoresView;
@property (nonatomic, strong) NSView *commandsView;
@property (nonatomic, strong) NSView *floodControlView;
@property (nonatomic, strong) NSView *floodControlToolView;
@property (nonatomic, strong) NSView *proxyServerView;
@property (nonatomic, strong) NSButton *outgoingFloodControl;
@property (nonatomic, strong) NSSlider *floodControlMessageCount;
@property (nonatomic, strong) NSSlider *floodControlDelayTimer;
@property (nonatomic, strong) ListView *tabView;
@property (nonatomic, strong) NSTextField *nameText;
@property (nonatomic, strong) NSButton *prefersIPv6Check;
@property (nonatomic, strong) NSButton *autoReconnectCheck;
@property (nonatomic, strong) NSButton *autoConnectCheck;
@property (nonatomic, strong) NSComboBox *hostCombo;
@property (nonatomic, strong) NSButton *sslCheck;
@property (nonatomic, strong) NSTextField *portText;
@property (nonatomic, strong) NSTextField *nickText;
@property (nonatomic, strong) NSTextField *passwordText;
@property (nonatomic, strong) NSTextField *usernameText;
@property (nonatomic, strong) NSTextField *realNameText;
@property (nonatomic, strong) NSTextField *nickPasswordText;
@property (nonatomic, strong) NSTextField *altNicksText;
@property (nonatomic, strong) NSTextView *sleepQuitMessageText;
@property (nonatomic, strong) NSTextView *leavingCommentText;
@property (nonatomic, strong) NSPopUpButton *encodingCombo;
@property (nonatomic, strong) NSPopUpButton *fallbackEncodingCombo;
@property (nonatomic, strong) NSPopUpButton *proxyCombo;
@property (nonatomic, strong) NSTextField *proxyHostText;
@property (nonatomic, strong) NSTextField *proxyPortText;
@property (nonatomic, strong) NSTextField *proxyUserText;
@property (nonatomic, strong) NSTextField *proxyPasswordText;
@property (nonatomic, strong) ListView *channelTable;
@property (nonatomic, strong) NSButton *addChannelButton;
@property (nonatomic, strong) NSButton *editChannelButton;
@property (nonatomic, strong) NSButton *deleteChannelButton;
@property (nonatomic, strong) NSTextView *loginCommandsText;
@property (nonatomic, strong) NSButton *invisibleCheck;
@property (nonatomic, strong) ListView *ignoreTable;
@property (nonatomic, strong) NSButton *addIgnoreButton;
@property (nonatomic, strong) NSButton *editIgnoreButton;
@property (nonatomic, strong) NSButton *deleteIgnoreButton;
@property (nonatomic, strong) NSMenu *addIgnoreMenu;
@property (nonatomic, strong) ChannelSheet *channelSheet;
@property (nonatomic, strong) AddressBookSheet *ignoreSheet;

- (void)startWithIgnoreTab:(NSString *)imask;

- (void)show;
- (void)showWithDefaultView:(NSView *)view andSegment:(NSInteger)segment;

- (void)close;

- (void)ok:(id)sender;
- (void)cancel:(id)sender;

- (void)hostComboChanged:(id)sender;
- (void)encodingChanged:(id)sender;
- (void)proxyChanged:(id)sender;
- (void)bouncerModeChanged:(id)sender;
- (void)floodControlChanged:(id)sender;

- (void)addChannel:(id)sender;
- (void)editChannel:(id)sender;
- (void)deleteChannel:(id)sender;

- (void)addIgnore:(id)sender;
- (void)editIgnore:(id)sender;
- (void)deleteIgnore:(id)sender;
- (void)showAddIgnoreMenu:(id)sender;
@end

@interface NSObject (ServerSheetDelegate)
- (void)ServerSheetOnOK:(ServerSheet *)sender;
- (void)ServerSheetWillClose:(ServerSheet *)sender;
@end
