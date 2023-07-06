#pragma once

#define FluSetObjectName(objectName) setObjectName(#objectName);

enum class FluAwesomeType {
	GlobalNavButton = 0xe700,
	Wifi = 0xe701,
	Bluetooth = 0xe702,
	Connect = 0xe703,
	InternetSharing = 0xe704,
	VPN = 0xe705,
	Brightness = 0xe706,
	MapPin = 0xe707,
	QuietHours = 0xe708,
	Airplane = 0xe709,
	Tablet = 0xe70a,
	QuickNote = 0xe70b,
	RememberedDevice = 0xe70c,
	ChevronDown = 0xe70d,
	ChevronUp = 0xe70e,
	Edit = 0xe70f,
	Add = 0xe710,
	Cancel = 0xe711,
	More = 0xe712,
	Settings = 0xe713,
	Video = 0xe714,
	Mail = 0xe715,
	People = 0xe716,
	Phone = 0xe717,
	Pin = 0xe718,
	Shop = 0xe719,
	Stop = 0xe71a,
	Link = 0xe71b,
	Filter = 0xe71c,
	AllApps = 0xe71d,
	Zoom = 0xe71e,
	ZoomOut = 0xe71f,
	Microphone = 0xe720,
	Search = 0xe721,
	Camera = 0xe722,
	Attach = 0xe723,
	Send = 0xe724,
	SendFill = 0xe725,
	WalkSolid = 0xe726,
	InPrivate = 0xe727,
	FavoriteList = 0xe728,
	PageSolid = 0xe729,
	Forward = 0xe72a,
	Back = 0xe72b,
	Refresh = 0xe72c,
	Share = 0xe72d,
	Lock = 0xe72e,
	ReportHacked = 0xe730,
	EMI = 0xe731,
	FavoriteStar = 0xe734,
	FavoriteStarFill = 0xe735,
	ReadingMode = 0xe736,
	Favicon = 0xe737,
	Remove = 0xe738,
	Checkbox = 0xe739,
	CheckboxComposite = 0xe73a,
	CheckboxFill = 0xe73b,
	CheckboxIndeterminate = 0xe73c,
	CheckboxCompositeReversed = 0xe73d,
	CheckMark = 0xe73e,
	BackToWindow = 0xe73f,
	FullScreen = 0xe740,
	ResizeTouchLarger = 0xe741,
	ResizeTouchSmaller = 0xe742,
	ResizeMouseSmall = 0xe743,
	ResizeMouseMedium = 0xe744,
	ResizeMouseWide = 0xe745,
	ResizeMouseTall = 0xe746,
	ResizeMouseLarge = 0xe747,
	SwitchUser = 0xe748,
	Print = 0xe749,
	Up = 0xe74a,
	Down = 0xe74b,
	OEM = 0xe74c,
	Delete = 0xe74d,
	Save = 0xe74e,
	Mute = 0xe74f,
	BackSpaceQWERTY = 0xe750,
	ReturnKey = 0xe751,
	UpArrowShiftKey = 0xe752,
	Cloud = 0xe753,
	Flashlight = 0xe754,
	RotationLock = 0xe755,
	CommandPrompt = 0xe756,
	SIPMove = 0xe759,
	SIPUndock = 0xe75a,
	SIPRedock = 0xe75b,
	EraseTool = 0xe75c,
	UnderscoreSpace = 0xe75d,
	GripperTool = 0xe75e,
	Dialpad = 0xe75f,
	PageLeft = 0xe760,
	PageRight = 0xe761,
	MultiSelect = 0xe762,
	KeyboardLeftHanded = 0xe763,
	KeyboardRightHanded = 0xe764,
	KeyboardClassic = 0xe765,
	KeyboardSplit = 0xe766,
	Volume = 0xe767,
	Play = 0xe768,
	Pause = 0xe769,
	ChevronLeft = 0xe76b,
	ChevronRight = 0xe76c,
	InkingTool = 0xe76d,
	Emoji2 = 0xe76e,
	GripperBarHorizontal = 0xe76f,
	System = 0xe770,
	Personalize = 0xe771,
	Devices = 0xe772,
	SearchAndApps = 0xe773,
	Globe = 0xe774,
	TimeLanguage = 0xe775,
	EaseOfAccess = 0xe776,
	UpdateRestore = 0xe777,
	HangUp = 0xe778,
	ContactInfo = 0xe779,
	Unpin = 0xe77a,
	Contact = 0xe77b,
	Memo = 0xe77c,
	IncomingCall = 0xe77e,
	Paste = 0xe77f,
	PhoneBook = 0xe780,
	LEDLight = 0xe781,
	Error = 0xe783,
	GripperBarVertical = 0xe784,
	Unlock = 0xe785,
	Slideshow = 0xe786,
	Calendar = 0xe787,
	GripperResize = 0xe788,
	Megaphone = 0xe789,
	Trim = 0xe78a,
	NewWindow = 0xe78b,
	SaveLocal = 0xe78c,
	Color = 0xe790,
	DataSense = 0xe791,
	SaveAs = 0xe792,
	Light = 0xe793,
	AspectRatio = 0xe799,
	DataSenseBar = 0xe7a5,
	Redo = 0xe7a6,
	Undo = 0xe7a7,
	Crop = 0xe7a8,
	OpenWith = 0xe7ac,
	Rotate = 0xe7ad,
	RedEye = 0xe7b3,
	SetlockScreen = 0xe7b5,
	MapPin2 = 0xe7b7,
	Package = 0xe7b8,
	Warning = 0xe7ba,
	ReadingList = 0xe7bc,
	Education = 0xe7be,
	ShoppingCart = 0xe7bf,
	Train = 0xe7c0,
	Flag = 0xe7c1,
	Move = 0xe7c2,
	Page = 0xe7c3,
	TaskView = 0xe7c4,
	BrowsePhotos = 0xe7c5,
	HalfStarLeft = 0xe7c6,
	HalfStarRight = 0xe7c7,
	Record = 0xe7c8,
	TouchPointer = 0xe7c9,
	LangJPN = 0xe7de,
	Ferry = 0xe7e3,
	Highlight = 0xe7e6,
	ActionCenterNotification = 0xe7e7,
	PowerButton = 0xe7e8,
	ResizeTouchNarrower = 0xe7ea,
	ResizeTouchShorter = 0xe7eb,
	DrivingMode = 0xe7ec,
	RingerSilent = 0xe7ed,
	OtherUser = 0xe7ee,
	Admin = 0xe7ef,
	CC = 0xe7f0,
	SDCard = 0xe7f1,
	CallForwarding = 0xe7f2,
	SettingsDisplaySound = 0xe7f3,
	TVMonitor = 0xe7f4,
	Speakers = 0xe7f5,
	Headphone = 0xe7f6,
	DeviceLaptopPic = 0xe7f7,
	DeviceLaptopNoPic = 0xe7f8,
	DeviceMonitorRightPic = 0xe7f9,
	DeviceMonitorLeftPic = 0xe7fa,
	DeviceMonitorNoPic = 0xe7fb,
	Game = 0xe7fc,
	HorizontalTabKey = 0xe7fd,
	StreetsideSplitMinimize = 0xe802,
	StreetsideSplitExpand = 0xe803,
	Car = 0xe804,
	Walk = 0xe805,
	Bus = 0xe806,
	TiltUp = 0xe809,
	TiltDown = 0xe80a,
	CallControl = 0xe80b,
	RotateMapRight = 0xe80c,
	RotateMapLeft = 0xe80d,
	Home = 0xe80f,
	ParkingLocation = 0xe811,
	MapCompassTop = 0xe812,
	MapCompassBottom = 0xe813,
	IncidentTriangle = 0xe814,
	Touch = 0xe815,
	MapDirections = 0xe816,
	StartPoint = 0xe819,
	StopPoint = 0xe81a,
	EndPoint = 0xe81b,
	History = 0xe81c,
	Location = 0xe81d,
	MapLayers = 0xe81e,
	Accident = 0xe81f,
	Work = 0xe821,
	Construction = 0xe822,
	Recent = 0xe823,
	Bank = 0xe825,
	DownloadMap = 0xe826,
	InkingToolFill2 = 0xe829,
	HighlightFill2 = 0xe82a,
	EraseToolFill = 0xe82b,
	EraseToolFill2 = 0xe82c,
	Dictionary = 0xe82d,
	DictionaryAdd = 0xe82e,
	ToolTip = 0xe82f,
	ChromeBack = 0xe830,
	ProvisioningPackage = 0xe835,
	AddRemoteDevice = 0xe836,
	FolderOpen = 0xe838,
	Ethernet = 0xe839,
	ShareBroadband = 0xe83a,
	DirectAccess = 0xe83b,
	DialUp = 0xe83c,
	DefenderApp = 0xe83d,
	BatteryCharging9 = 0xe83e,
	Battery10 = 0xe83f,
	Pinned = 0xe840,
	PinFill = 0xe841,
	PinnedFill = 0xe842,
	PeriodKey = 0xe843,
	PuncKey = 0xe844,
	RevToggleKey = 0xe845,
	RightArrowKeyTime1 = 0xe846,
	RightArrowKeyTime2 = 0xe847,
	LeftQuote = 0xe848,
	RightQuote = 0xe849,
	DownShiftKey = 0xe84a,
	UpShiftKey = 0xe84b,
	PuncKey0 = 0xe84c,
	PuncKeyLeftBottom = 0xe84d,
	RightArrowKeyTime3 = 0xe84e,
	RightArrowKeyTime4 = 0xe84f,
	Battery0 = 0xe850,
	Battery1 = 0xe851,
	Battery2 = 0xe852,
	Battery3 = 0xe853,
	Battery4 = 0xe854,
	Battery5 = 0xe855,
	Battery6 = 0xe856,
	Battery7 = 0xe857,
	Battery8 = 0xe858,
	Battery9 = 0xe859,
	BatteryCharging0 = 0xe85a,
	BatteryCharging1 = 0xe85b,
	BatteryCharging2 = 0xe85c,
	BatteryCharging3 = 0xe85d,
	BatteryCharging4 = 0xe85e,
	BatteryCharging5 = 0xe85f,
	BatteryCharging6 = 0xe860,
	BatteryCharging7 = 0xe861,
	BatteryCharging8 = 0xe862,
	BatterySaver0 = 0xe863,
	BatterySaver1 = 0xe864,
	BatterySaver2 = 0xe865,
	BatterySaver3 = 0xe866,
	BatterySaver4 = 0xe867,
	BatterySaver5 = 0xe868,
	BatterySaver6 = 0xe869,
	BatterySaver7 = 0xe86a,
	BatterySaver8 = 0xe86b,
	SignalBars1 = 0xe86c,
	SignalBars2 = 0xe86d,
	SignalBars3 = 0xe86e,
	SignalBars4 = 0xe86f,
	SignalBars5 = 0xe870,
	SignalNotConnected = 0xe871,
	Wifi1 = 0xe872,
	Wifi2 = 0xe873,
	Wifi3 = 0xe874,
	MobSIMLock = 0xe875,
	MobSIMMissing = 0xe876,
	Vibrate = 0xe877,
	RoamingInternational = 0xe878,
	RoamingDomestic = 0xe879,
	CallForwardInternational = 0xe87a,
	CallForwardRoaming = 0xe87b,
	JpnRomanji = 0xe87c,
	JpnRomanjiLock = 0xe87d,
	JpnRomanjiShift = 0xe87e,
	JpnRomanjiShiftLock = 0xe87f,
	StatusDataTransfer = 0xe880,
	StatusDataTransferVPN = 0xe881,
	StatusDualSIM2 = 0xe882,
	StatusDualSIM2VPN = 0xe883,
	StatusDualSIM1 = 0xe884,
	StatusDualSIM1VPN = 0xe885,
	StatusSGLTE = 0xe886,
	StatusSGLTECell = 0xe887,
	StatusSGLTEDataVPN = 0xe888,
	StatusVPN = 0xe889,
	WifiHotspot = 0xe88a,
	LanguageKor = 0xe88b,
	LanguageCht = 0xe88c,
	LanguageChs = 0xe88d,
	USB = 0xe88e,
	InkingToolFill = 0xe88f,
	View = 0xe890,
	HighlightFill = 0xe891,
	Previous = 0xe892,
	Next = 0xe893,
	Clear = 0xe894,
	Sync = 0xe895,
	Download = 0xe896,
	Help = 0xe897,
	Upload = 0xe898,
	Emoji = 0xe899,
	TwoPage = 0xe89a,
	LeaveChat = 0xe89b,
	MailForward = 0xe89c,
	RotateCamera = 0xe89e,
	ClosePane = 0xe89f,
	OpenPane = 0xe8a0,
	PreviewLink = 0xe8a1,
	AttachCamera = 0xe8a2,
	ZoomIn = 0xe8a3,
	Bookmarks = 0xe8a4,
	Document = 0xe8a5,
	ProtectedDocument = 0xe8a6,
	OpenInNewWindow = 0xe8a7,
	MailFill = 0xe8a8,
	ViewAll = 0xe8a9,
	VideoChat = 0xe8aa,
	Switch = 0xe8ab,
	Rename = 0xe8ac,
	Go = 0xe8ad,
	SurfaceHub = 0xe8ae,
	Remote = 0xe8af,
	Click = 0xe8b0,
	Shuffle = 0xe8b1,
	Movies = 0xe8b2,
	SelectAll = 0xe8b3,
	Orientation = 0xe8b4,
	Import = 0xe8b5,
	ImportAll = 0xe8b6,
	Folder = 0xe8b7,
	Webcam = 0xe8b8,
	Picture = 0xe8b9,
	Caption = 0xe8ba,
	ChromeClose = 0xe8bb,
	ShowResults = 0xe8bc,
	Message = 0xe8bd,
	Leaf = 0xe8be,
	CalendarDay = 0xe8bf,
	CalendarWeek = 0xe8c0,
	Characters = 0xe8c1,
	MailReplyAll = 0xe8c2,
	Read = 0xe8c3,
	ShowBcc = 0xe8c4,
	HideBcc = 0xe8c5,
	Cut = 0xe8c6,
	PaymentCard = 0xe8c7,
	Copy = 0xe8c8,
	Important = 0xe8c9,
	MailReply = 0xe8ca,
	Sort = 0xe8cb,
	MobileTablet = 0xe8cc,
	DisconnectDrive = 0xe8cd,
	MapDrive = 0xe8ce,
	ContactPresence = 0xe8cf,
	Priority = 0xe8d0,
	GotoToday = 0xe8d1,
	Font = 0xe8d2,
	FontColor = 0xe8d3,
	Contact2 = 0xe8d4,
	FolderFill = 0xe8d5,
	Audio = 0xe8d6,
	Permissions = 0xe8d7,
	DisableUpdates = 0xe8d8,
	Unfavorite = 0xe8d9,
	OpenLocal = 0xe8da,
	Italic = 0xe8db,
	Underline = 0xe8dc,
	Bold = 0xe8dd,
	MoveToFolder = 0xe8de,
	LikeDislike = 0xe8df,
	Dislike = 0xe8e0,
	Like = 0xe8e1,
	AlignRight = 0xe8e2,
	AlignCenter = 0xe8e3,
	AlignLeft = 0xe8e4,
	OpenFile = 0xe8e5,
	ClearSelection = 0xe8e6,
	FontDecrease = 0xe8e7,
	FontIncrease = 0xe8e8,
	FontSize = 0xe8e9,
	CellPhone = 0xe8ea,
	Reshare = 0xe8eb,
	Tag = 0xe8ec,
	RepeatOne = 0xe8ed,
	RepeatAll = 0xe8ee,
	Calculator = 0xe8ef,
	Directions = 0xe8f0,
	Library = 0xe8f1,
	ChatBubbles = 0xe8f2,
	PostUpdate = 0xe8f3,
	NewFolder = 0xe8f4,
	CalendarReply = 0xe8f5,
	UnsyncFolder = 0xe8f6,
	SyncFolder = 0xe8f7,
	BlockContact = 0xe8f8,
	SwitchApps = 0xe8f9,
	AddFriend = 0xe8fa,
	Accept = 0xe8fb,
	GoToStart = 0xe8fc,
	BulletedList = 0xe8fd,
	Scan = 0xe8fe,
	Preview = 0xe8ff,
	Group = 0xe902,
	ZeroBars = 0xe904,
	OneBar = 0xe905,
	TwoBars = 0xe906,
	ThreeBars = 0xe907,
	FourBars = 0xe908,
	World = 0xe909,
	Comment = 0xe90a,
	MusicInfo = 0xe90b,
	DockLeft = 0xe90c,
	DockRight = 0xe90d,
	DockBottom = 0xe90e,
	Repair = 0xe90f,
	Accounts = 0xe910,
	DullSound = 0xe911,
	Manage = 0xe912,
	Street = 0xe913,
	Printer3D = 0xe914,
	RadioBullet = 0xe915,
	Stopwatch = 0xe916,
	Photo = 0xe91b,
	ActionCenter = 0xe91c,
	FullCircleMask = 0xe91f,
	ChromeMinimize = 0xe921,
	ChromeMaximize = 0xe922,
	ChromeRestore = 0xe923,
	Annotation = 0xe924,
	BackSpaceQWERTYSm = 0xe925,
	BackSpaceQWERTYMd = 0xe926,
	Swipe = 0xe927,
	Fingerprint = 0xe928,
	Handwriting = 0xe929,
	ChromeBackToWindow = 0xe92c,
	ChromeFullScreen = 0xe92d,
	KeyboardStandard = 0xe92e,
	KeyboardDismiss = 0xe92f,
	Completed = 0xe930,
	ChromeAnnotate = 0xe931,
	Label = 0xe932,
	IBeam = 0xe933,
	IBeamOutline = 0xe934,
	FlickDown = 0xe935,
	FlickUp = 0xe936,
	FlickLeft = 0xe937,
	FlickRight = 0xe938,
	FeedbackApp = 0xe939,
	MusicAlbum = 0xe93c,
	Streaming = 0xe93e,
	Code = 0xe943,
	ReturnToWindow = 0xe944,
	LightningBolt = 0xe945,
	Info = 0xe946,
	CalculatorMultiply = 0xe947,
	CalculatorAddition = 0xe948,
	CalculatorSubtract = 0xe949,
	CalculatorDivide = 0xe94a,
	CalculatorSquareroot = 0xe94b,
	CalculatorPercentage = 0xe94c,
	CalculatorNegate = 0xe94d,
	CalculatorEqualTo = 0xe94e,
	CalculatorBackspace = 0xe94f,
	Component = 0xe950,
	DMC = 0xe951,
	Dock = 0xe952,
	MultimediaDMS = 0xe953,
	MultimediaDVR = 0xe954,
	MultimediaPMP = 0xe955,
	PrintfaxPrinterFile = 0xe956,
	Sensor = 0xe957,
	StorageOptical = 0xe958,
	Communications = 0xe95a,
	Headset = 0xe95b,
	Projector = 0xe95d,
	Health = 0xe95e,
	Wire = 0xe95f,
	Webcam2 = 0xe960,
	Input = 0xe961,
	Mouse = 0xe962,
	Smartcard = 0xe963,
	SmartcardVirtual = 0xe964,
	MediaStorageTower = 0xe965,
	ReturnKeySm = 0xe966,
	GameConsole = 0xe967,
	Network = 0xe968,
	StorageNetworkWireless = 0xe969,
	StorageTape = 0xe96a,
	ChevronUpSmall = 0xe96d,
	ChevronDownSmall = 0xe96e,
	ChevronLeftSmall = 0xe96f,
	ChevronRightSmall = 0xe970,
	ChevronUpMed = 0xe971,
	ChevronDownMed = 0xe972,
	ChevronLeftMed = 0xe973,
	ChevronRightMed = 0xe974,
	Devices2 = 0xe975,
	ExpandTile = 0xe976,
	PC1 = 0xe977,
	PresenceChicklet = 0xe978,
	PresenceChickletVideo = 0xe979,
	Reply = 0xe97a,
	SetTile = 0xe97b,
	Type = 0xe97c,
	Korean = 0xe97d,
	HalfAlpha = 0xe97e,
	FullAlpha = 0xe97f,
	Key12On = 0xe980,
	ChineseChangjie = 0xe981,
	QWERTYOn = 0xe982,
	QWERTYOff = 0xe983,
	ChineseQuick = 0xe984,
	Japanese = 0xe985,
	FullHiragana = 0xe986,
	FullKatakana = 0xe987,
	HalfKatakana = 0xe988,
	ChineseBoPoMoFo = 0xe989,
	ChinesePinyin = 0xe98a,
	ConstructionCone = 0xe98f,
	XboxOneConsole = 0xe990,
	Volume0 = 0xe992,
	Volume1 = 0xe993,
	Volume2 = 0xe994,
	Volume3 = 0xe995,
	BatteryUnknown = 0xe996,
	WifiAttentionOverlay = 0xe998,
	Robot = 0xe99a,
	TapAndSend = 0xe9a1,
	FitPage = 0xe9a6,
	PasswordKeyShow = 0xe9a8,
	PasswordKeyHide = 0xe9a9,
	BidiLtr = 0xe9aa,
	BidiRtl = 0xe9ab,
	ForwardSm = 0xe9ac,
	CommaKey = 0xe9ad,
	DashKey = 0xe9ae,
	DullSoundKey = 0xe9af,
	HalfDullSound = 0xe9b0,
	RightDoubleQuote = 0xe9b1,
	LeftDoubleQuote = 0xe9b2,
	PuncKeyRightBottom = 0xe9b3,
	PuncKey1 = 0xe9b4,
	PuncKey2 = 0xe9b5,
	PuncKey3 = 0xe9b6,
	PuncKey4 = 0xe9b7,
	PuncKey5 = 0xe9b8,
	PuncKey6 = 0xe9b9,
	PuncKey9 = 0xe9ba,
	PuncKey7 = 0xe9bb,
	PuncKey8 = 0xe9bc,
	Frigid = 0xe9ca,
	Unknown = 0xe9ce,
	AreaChart = 0xe9d2,
	CheckList = 0xe9d5,
	Diagnostic = 0xe9d9,
	Equalizer = 0xe9e9,
	Process = 0xe9f3,
	Processing = 0xe9f5,
	ReportDocument = 0xe9f9,
	VideoSolid = 0xea0c,
	MixedMediaBadge = 0xea0d,
	DisconnectDisplay = 0xea14,
	Shield = 0xea18,
	Info2 = 0xea1f,
	ActionCenterAsterisk = 0xea21,
	Beta = 0xea24,
	SaveCopy = 0xea35,
	List = 0xea37,
	Asterisk = 0xea38,
	ErrorBadge = 0xea39,
	CircleRing = 0xea3a,
	CircleFill = 0xea3b,
	MergeCall = 0xea3c,
	PrivateCall = 0xea3d,
	Record2 = 0xea3f,
	AllAppsMirrored = 0xea40,
	BookmarksMirrored = 0xea41,
	BulletedListMirrored = 0xea42,
	CallForwardInternationalMirrored = 0xea43,
	CallForwardRoamingMirrored = 0xea44,
	ChromeBackMirrored = 0xea47,
	ClearSelectionMirrored = 0xea48,
	ClosePaneMirrored = 0xea49,
	ContactInfoMirrored = 0xea4a,
	DockRightMirrored = 0xea4b,
	DockLeftMirrored = 0xea4c,
	ExpandTileMirrored = 0xea4e,
	GoMirrored = 0xea4f,
	GripperResizeMirrored = 0xea50,
	HelpMirrored = 0xea51,
	ImportMirrored = 0xea52,
	ImportAllMirrored = 0xea53,
	LeaveChatMirrored = 0xea54,
	ListMirrored = 0xea55,
	MailForwardMirrored = 0xea56,
	MailReplyMirrored = 0xea57,
	MailReplyAllMirrored = 0xea58,
	OpenPaneMirrored = 0xea5b,
	OpenWithMirrored = 0xea5c,
	ParkingLocationMirrored = 0xea5e,
	ResizeMouseMediumMirrored = 0xea5f,
	ResizeMouseSmallMirrored = 0xea60,
	ResizeMouseTallMirrored = 0xea61,
	ResizeTouchNarrowerMirrored = 0xea62,
	SendMirrored = 0xea63,
	SendFillMirrored = 0xea64,
	ShowResultsMirrored = 0xea65,
	Media = 0xea69,
	SyncError = 0xea6a,
	Devices3 = 0xea6c,
	SlowMotionOn = 0xea79,
	Lightbulb = 0xea80,
	StatusCircle = 0xea81,
	StatusTriangle = 0xea82,
	StatusError = 0xea83,
	StatusWarning = 0xea84,
	Puzzle = 0xea86,
	CalendarSolid = 0xea89,
	HomeSolid = 0xea8a,
	ParkingLocationSolid = 0xea8b,
	ContactSolid = 0xea8c,
	ConstructionSolid = 0xea8d,
	AccidentSolid = 0xea8e,
	Ringer = 0xea8f,
	PDF = 0xea90,
	ThoughtBubble = 0xea91,
	HeartBroken = 0xea92,
	BatteryCharging10 = 0xea93,
	BatterySaver9 = 0xea94,
	BatterySaver10 = 0xea95,
	CallForwardingMirrored = 0xea97,
	MultiSelectMirrored = 0xea98,
	Broom = 0xea99,
	ForwardCall = 0xeac2,
	Trackers = 0xeadf,
	Market = 0xeafc,
	PieSingle = 0xeb05,
	StockUp = 0xeb0f,
	StockDown = 0xeb11,
	Design = 0xeb3c,
	Website = 0xeb41,
	Drop = 0xeb42,
	Radar = 0xeb44,
	BusSolid = 0xeb47,
	FerrySolid = 0xeb48,
	StartPointSolid = 0xeb49,
	StopPointSolid = 0xeb4a,
	EndPointSolid = 0xeb4b,
	AirplaneSolid = 0xeb4c,
	TrainSolid = 0xeb4d,
	WorkSolid = 0xeb4e,
	ReminderFill = 0xeb4f,
	Reminder = 0xeb50,
	Heart = 0xeb51,
	HeartFill = 0xeb52,
	EthernetError = 0xeb55,
	EthernetWarning = 0xeb56,
	StatusConnecting1 = 0xeb57,
	StatusConnecting2 = 0xeb58,
	StatusUnsecure = 0xeb59,
	WifiError0 = 0xeb5a,
	WifiError1 = 0xeb5b,
	WifiError2 = 0xeb5c,
	WifiError3 = 0xeb5d,
	WifiError4 = 0xeb5e,
	WifiWarning0 = 0xeb5f,
	WifiWarning1 = 0xeb60,
	WifiWarning2 = 0xeb61,
	WifiWarning3 = 0xeb62,
	WifiWarning4 = 0xeb63,
	Devices4 = 0xeb66,
	NUIIris = 0xeb67,
	NUIFace = 0xeb68,
	GatewayRouter = 0xeb77,
	EditMirrored = 0xeb7e,
	NUIFPStartSlideHand = 0xeb82,
	NUIFPStartSlideAction = 0xeb83,
	NUIFPContinueSlideHand = 0xeb84,
	NUIFPContinueSlideAction = 0xeb85,
	NUIFPRollRightHand = 0xeb86,
	NUIFPRollRightHandAction = 0xeb87,
	NUIFPRollLeftHand = 0xeb88,
	NUIFPRollLeftAction = 0xeb89,
	NUIFPPressHand = 0xeb8a,
	NUIFPPressAction = 0xeb8b,
	NUIFPPressRepeatHand = 0xeb8c,
	NUIFPPressRepeatAction = 0xeb8d,
	StatusErrorFull = 0xeb90,
	TaskViewExpanded = 0xeb91,
	Certificate = 0xeb95,
	BackSpaceQWERTYLg = 0xeb96,
	ReturnKeyLg = 0xeb97,
	FastForward = 0xeb9d,
	Rewind = 0xeb9e,
	Photo2 = 0xeb9f,
	MobBattery0 = 0xeba0,
	MobBattery1 = 0xeba1,
	MobBattery2 = 0xeba2,
	MobBattery3 = 0xeba3,
	MobBattery4 = 0xeba4,
	MobBattery5 = 0xeba5,
	MobBattery6 = 0xeba6,
	MobBattery7 = 0xeba7,
	MobBattery8 = 0xeba8,
	MobBattery9 = 0xeba9,
	MobBattery10 = 0xebaa,
	MobBatteryCharging0 = 0xebab,
	MobBatteryCharging1 = 0xebac,
	MobBatteryCharging2 = 0xebad,
	MobBatteryCharging3 = 0xebae,
	MobBatteryCharging4 = 0xebaf,
	MobBatteryCharging5 = 0xebb0,
	MobBatteryCharging6 = 0xebb1,
	MobBatteryCharging7 = 0xebb2,
	MobBatteryCharging8 = 0xebb3,
	MobBatteryCharging9 = 0xebb4,
	MobBatteryCharging10 = 0xebb5,
	MobBatterySaver0 = 0xebb6,
	MobBatterySaver1 = 0xebb7,
	MobBatterySaver2 = 0xebb8,
	MobBatterySaver3 = 0xebb9,
	MobBatterySaver4 = 0xebba,
	MobBatterySaver5 = 0xebbb,
	MobBatterySaver6 = 0xebbc,
	MobBatterySaver7 = 0xebbd,
	MobBatterySaver8 = 0xebbe,
	MobBatterySaver9 = 0xebbf,
	MobBatterySaver10 = 0xebc0,
	DictionaryCloud = 0xebc3,
	ResetDrive = 0xebc4,
	VolumeBars = 0xebc5,
	Project = 0xebc6,
	AdjustHologram = 0xebd2,
	CloudDownload = 0xebd3,
	MobWifiCallBars = 0xebd4,
	MobWifiCall0 = 0xebd5,
	MobWifiCall1 = 0xebd6,
	MobWifiCall2 = 0xebd7,
	MobWifiCall3 = 0xebd8,
	MobWifiCall4 = 0xebd9,
	Family = 0xebda,
	LockFeedback = 0xebdb,
	DeviceDiscovery = 0xebde,
	WindDirection = 0xebe6,
	RightArrowKeyTime0 = 0xebe7,
	Bug = 0xebe8,
	TabletMode = 0xebfc,
	StatusCircleLeft = 0xebfd,
	StatusTriangleLeft = 0xebfe,
	StatusErrorLeft = 0xebff,
	StatusWarningLeft = 0xec00,
	MobBatteryUnknown = 0xec02,
	NetworkTower = 0xec05,
	CityNext = 0xec06,
	CityNext2 = 0xec07,
	Courthouse = 0xec08,
	Groceries = 0xec09,
	Sustainable = 0xec0a,
	BuildingEnergy = 0xec0b,
	ToggleFilled = 0xec11,
	ToggleBorder = 0xec12,
	SliderThumb = 0xec13,
	ToggleThumb = 0xec14,
	MiracastLogoSmall = 0xec15,
	MiracastLogoLarge = 0xec16,
	PLAP = 0xec19,
	Badge = 0xec1b,
	SignalRoaming = 0xec1e,
	MobileLocked = 0xec20,
	InsiderHubApp = 0xec24,
	PersonalFolder = 0xec25,
	HomeGroup = 0xec26,
	MyNetwork = 0xec27,
	KeyboardFull = 0xec31,
	Cafe = 0xec32,
	MobSignal1 = 0xec37,
	MobSignal2 = 0xec38,
	MobSignal3 = 0xec39,
	MobSignal4 = 0xec3a,
	MobSignal5 = 0xec3b,
	MobWifi1 = 0xec3c,
	MobWifi2 = 0xec3d,
	MobWifi3 = 0xec3e,
	MobWifi4 = 0xec3f,
	MobAirplane = 0xec40,
	MobBluetooth = 0xec41,
	MobActionCenter = 0xec42,
	MobLocation = 0xec43,
	MobWifiHotspot = 0xec44,
	LanguageJpn = 0xec45,
	MobQuietHours = 0xec46,
	MobDrivingMode = 0xec47,
	SpeedOff = 0xec48,
	SpeedMedium = 0xec49,
	SpeedHigh = 0xec4a,
	ThisPC = 0xec4e,
	MusicNote = 0xec4f,
	FileExplorer = 0xec50,
	FileExplorerApp = 0xec51,
	LeftArrowKeyTime0 = 0xec52,
	MicOff = 0xec54,
	MicSleep = 0xec55,
	MicError = 0xec56,
	PlaybackRate1x = 0xec57,
	PlaybackRateOther = 0xec58,
	CashDrawer = 0xec59,
	BarcodeScanner = 0xec5a,
	ReceiptPrinter = 0xec5b,
	MagStripeReader = 0xec5c,
	CompletedSolid = 0xec61,
	CompanionApp = 0xec64,
	Favicon2 = 0xec6c,
	SwipeRevealArt = 0xec6d,
	MicOn = 0xec71,
	MicClipping = 0xec72,
	TabletSelected = 0xec74,
	MobileSelected = 0xec75,
	LaptopSelected = 0xec76,
	TVMonitorSelected = 0xec77,
	DeveloperTools = 0xec7a,
	MobCallForwarding = 0xec7e,
	MobCallForwardingMirrored = 0xec7f,
	BodyCam = 0xec80,
	PoliceCar = 0xec81,
	Draw = 0xec87,
	DrawSolid = 0xec88,
	LowerBrightness = 0xec8a,
	ScrollUpDown = 0xec8f,
	DateTime = 0xec92,
	HoloLens = 0xec94,
	Tiles = 0xeca5,
	PartyLeader = 0xeca7,
	AppIconDefault = 0xecaa,
	Calories = 0xecad,
	POI = 0xecaf,
	BandBattery0 = 0xecb9,
	BandBattery1 = 0xecba,
	BandBattery2 = 0xecbb,
	BandBattery3 = 0xecbc,
	BandBattery4 = 0xecbd,
	BandBattery5 = 0xecbe,
	BandBattery6 = 0xecbf,
	AddSurfaceHub = 0xecc4,
	DevUpdate = 0xecc5,
	Unit = 0xecc6,
	AddTo = 0xecc8,
	RemoveFrom = 0xecc9,
	RadioBtnOff = 0xecca,
	RadioBtnOn = 0xeccb,
	RadioBullet2 = 0xeccc,
	ExploreContent = 0xeccd,
	Blocked2 = 0xece4,
	ScrollMode = 0xece7,
	ZoomMode = 0xece8,
	PanMode = 0xece9,
	WiredUSB = 0xecf0,
	WirelessUSB = 0xecf1,
	USBSafeConnect = 0xecf3,
	ActionCenterNotificationMirrored = 0xed0c,
	ActionCenterMirrored = 0xed0d,
	SubscriptionAdd = 0xed0e,
	ResetDevice = 0xed10,
	SubscriptionAddMirrored = 0xed11,
	QRCode = 0xed14,
	Feedback = 0xed15,
	Hide = 0xed1a,
	Subtitles = 0xed1e,
	SubtitlesAudio = 0xed1f,
	OpenFolderHorizontal = 0xed25,
	CalendarMirrored = 0xed28,
	MobeSIM = 0xed2a,
	MobeSIMNoProfile = 0xed2b,
	MobeSIMLocked = 0xed2c,
	MobeSIMBusy = 0xed2d,
	SignalError = 0xed2e,
	StreamingEnterprise = 0xed2f,
	Headphone0 = 0xed30,
	Headphone1 = 0xed31,
	Headphone2 = 0xed32,
	Headphone3 = 0xed33,
	Apps = 0xed35,
	KeyboardBrightness = 0xed39,
	KeyboardLowerBrightness = 0xed3a,
	SkipBack10 = 0xed3c,
	SkipForward30 = 0xed3d,
	TreeFolderFolder = 0xed41,
	TreeFolderFolderFill = 0xed42,
	TreeFolderFolderOpen = 0xed43,
	TreeFolderFolderOpenFill = 0xed44,
	MultimediaDMP = 0xed47,
	KeyboardOneHanded = 0xed4c,
	Narrator = 0xed4d,
	EmojiTabPeople = 0xed53,
	EmojiTabSmilesAnimals = 0xed54,
	EmojiTabCelebrationObjects = 0xed55,
	EmojiTabFoodPlants = 0xed56,
	EmojiTabTransitPlaces = 0xed57,
	EmojiTabSymbols = 0xed58,
	EmojiTabTextSmiles = 0xed59,
	EmojiTabFavorites = 0xed5a,
	EmojiSwatch = 0xed5b,
	ConnectApp = 0xed5c,
	CompanionDeviceFramework = 0xed5d,
	Ruler = 0xed5e,
	FingerInking = 0xed5f,
	StrokeErase = 0xed60,
	PointErase = 0xed61,
	ClearAllInk = 0xed62,
	Pencil = 0xed63,
	Marker = 0xed64,
	InkingCaret = 0xed65,
	InkingColorOutline = 0xed66,
	InkingColorFill = 0xed67,
	HardDrive = 0xeda2,
	NetworkAdapter = 0xeda3,
	Touchscreen = 0xeda4,
	NetworkPrinter = 0xeda5,
	CloudPrinter = 0xeda6,
	KeyboardShortcut = 0xeda7,
	BrushSize = 0xeda8,
	NarratorForward = 0xeda9,
	NarratorForwardMirrored = 0xedaa,
	SyncBadge12 = 0xedab,
	RingerBadge12 = 0xedac,
	AsteriskBadge12 = 0xedad,
	ErrorBadge12 = 0xedae,
	CircleRingBadge12 = 0xedaf,
	CircleFillBadge12 = 0xedb0,
	ImportantBadge12 = 0xedb1,
	MailBadge12 = 0xedb3,
	PauseBadge12 = 0xedb4,
	PlayBadge12 = 0xedb5,
	PenWorkspace = 0xedc6,
	CaretLeft8 = 0xedd5,
	CaretRight8 = 0xedd6,
	CaretUp8 = 0xedd7,
	CaretDown8 = 0xedd8,
	CaretLeftSolid8 = 0xedd9,
	CaretRightSolid8 = 0xedda,
	CaretUpSolid8 = 0xeddb,
	CaretDownSolid8 = 0xeddc,
	Strikethrough = 0xede0,
	Export = 0xede1,
	ExportMirrored = 0xede2,
	ButtonMenu = 0xede3,
	CloudSearch = 0xede4,
	PinyinIMELogo = 0xede5,
	CalligraphyPen = 0xedfb,
	ReplyMirrored = 0xee35,
	LockscreenDesktop = 0xee3f,
	TaskViewSettings = 0xee40,
	MiniExpand2Mirrored = 0xee47,
	MiniContract2Mirrored = 0xee49,
	Play36 = 0xee4a,
	PenPalette = 0xee56,
	GuestUser = 0xee57,
	SettingsBattery = 0xee63,
	TaskbarPhone = 0xee64,
	LockScreenGlance = 0xee65,
	GenericScan = 0xee6f,
	ImageExport = 0xee71,
	WifiEthernet = 0xee77,
	ActionCenterQuiet = 0xee79,
	ActionCenterQuietNotification = 0xee7a,
	TrackersMirrored = 0xee92,
	DateTimeMirrored = 0xee93,
	Wheel = 0xee94,
	VirtualMachineGroup = 0xeea3,
	ButtonView2 = 0xeeca,
	PenWorkspaceMirrored = 0xef15,
	PenPaletteMirrored = 0xef16,
	StrokeEraseMirrored = 0xef17,
	PointEraseMirrored = 0xef18,
	ClearAllInkMirrored = 0xef19,
	BackgroundToggle = 0xef1f,
	Marquee = 0xef20,
	ChromeCloseContrast = 0xef2c,
	ChromeMinimizeContrast = 0xef2d,
	ChromeMaximizeContrast = 0xef2e,
	ChromeRestoreContrast = 0xef2f,
	TrafficLight = 0xef31,
	Replay = 0xef3b,
	Eyedropper = 0xef3c,
	LineDisplay = 0xef3d,
	PINPad = 0xef3e,
	SignatureCapture = 0xef3f,
	ChipCardCreditCardReader = 0xef40,
	MarketDown = 0xef42,
	PlayerSettings = 0xef58,
	LandscapeOrientation = 0xef6b,
	Flow = 0xef90,
	Touchpad = 0xefa5,
	Speech = 0xefa9,
	KnowledgeArticle = 0xf000,
	Relationship = 0xf003,
	ZipFolder = 0xf012,
	DefaultAPN = 0xf080,
	UserAPN = 0xf081,
	DoublePinyin = 0xf085,
	BlueLight = 0xf08c,
	CaretSolidLeft = 0xf08d,
	CaretSolidDown = 0xf08e,
	CaretSolidRight = 0xf08f,
	CaretSolidUp = 0xf090,
	ButtonA = 0xf093,
	ButtonB = 0xf094,
	ButtonY = 0xf095,
	ButtonX = 0xf096,
	ArrowUp8 = 0xf0ad,
	ArrowDown8 = 0xf0ae,
	ArrowRight8 = 0xf0af,
	ArrowLeft8 = 0xf0b0,
	QuarentinedItems = 0xf0b2,
	QuarentinedItemsMirrored = 0xf0b3,
	Protractor = 0xf0b4,
	ChecklistMirrored = 0xf0b5,
	StatusCircle7 = 0xf0b6,
	StatusCheckmark7 = 0xf0b7,
	StatusErrorCircle7 = 0xf0b8,
	Connected = 0xf0b9,
	PencilFill = 0xf0c6,
	CalligraphyFill = 0xf0c7,
	QuarterStarLeft = 0xf0ca,
	QuarterStarRight = 0xf0cb,
	ThreeQuarterStarLeft = 0xf0cc,
	ThreeQuarterStarRight = 0xf0cd,
	QuietHoursBadge12 = 0xf0ce,
	BackMirrored = 0xf0d2,
	ForwardMirrored = 0xf0d3,
	ChromeBackContrast = 0xf0d5,
	ChromeBackContrastMirrored = 0xf0d6,
	ChromeBackToWindowContrast = 0xf0d7,
	ChromeFullScreenContrast = 0xf0d8,
	GridView = 0xf0e2,
	ClipboardList = 0xf0e3,
	ClipboardListMirrored = 0xf0e4,
	OutlineQuarterStarLeft = 0xf0e5,
	OutlineQuarterStarRight = 0xf0e6,
	OutlineHalfStarLeft = 0xf0e7,
	OutlineHalfStarRight = 0xf0e8,
	OutlineThreeQuarterStarLeft = 0xf0e9,
	OutlineThreeQuarterStarRight = 0xf0ea,
	SpatialVolume0 = 0xf0eb,
	SpatialVolume1 = 0xf0ec,
	SpatialVolume2 = 0xf0ed,
	SpatialVolume3 = 0xf0ee,
	ApplicationGuard = 0xf0ef,
	OutlineStarLeftHalf = 0xf0f7,
	OutlineStarRightHalf = 0xf0f8,
	ChromeAnnotateContrast = 0xf0f9,
	DefenderBadge12 = 0xf0fb,
	DetachablePC = 0xf103,
	LeftStick = 0xf108,
	RightStick = 0xf109,
	TriggerLeft = 0xf10a,
	TriggerRight = 0xf10b,
	BumperLeft = 0xf10c,
	BumperRight = 0xf10d,
	Dpad = 0xf10e,
	EnglishPunctuation = 0xf110,
	ChinesePunctuation = 0xf111,
	HMD = 0xf119,
	CtrlSpatialRight = 0xf11b,
	PaginationDotOutline10 = 0xf126,
	PaginationDotSolid10 = 0xf127,
	StrokeErase2 = 0xf128,
	SmallErase = 0xf129,
	LargeErase = 0xf12a,
	FolderHorizontal = 0xf12b,
	MicrophoneListening = 0xf12e,
	StatusExclamationCircle7 = 0xf12f,
	Video360 = 0xf131,
	GiftboxOpen = 0xf133,
	StatusCircleOuter = 0xf136,
	StatusCircleInner = 0xf137,
	StatusCircleRing = 0xf138,
	StatusTriangleOuter = 0xf139,
	StatusTriangleInner = 0xf13a,
	StatusTriangleExclamation = 0xf13b,
	StatusCircleExclamation = 0xf13c,
	StatusCircleErrorX = 0xf13d,
	StatusCircleCheckmark = 0xf13e,
	StatusCircleInfo = 0xf13f,
	StatusCircleBlock = 0xf140,
	StatusCircleBlock2 = 0xf141,
	StatusCircleQuestionMark = 0xf142,
	StatusCircleSync = 0xf143,
	Dial1 = 0xf146,
	Dial2 = 0xf147,
	Dial3 = 0xf148,
	Dial4 = 0xf149,
	Dial5 = 0xf14a,
	Dial6 = 0xf14b,
	Dial7 = 0xf14c,
	Dial8 = 0xf14d,
	Dial9 = 0xf14e,
	Dial10 = 0xf14f,
	Dial11 = 0xf150,
	Dial12 = 0xf151,
	Dial13 = 0xf152,
	Dial14 = 0xf153,
	Dial15 = 0xf154,
	Dial16 = 0xf155,
	DialShape1 = 0xf156,
	DialShape2 = 0xf157,
	DialShape3 = 0xf158,
	DialShape4 = 0xf159,
	ClosedCaptionsInternational = 0xf15f,
	TollSolid = 0xf161,
	TrafficCongestionSolid = 0xf163,
	ExploreContentSingle = 0xf164,
	CollapseContent = 0xf165,
	CollapseContentSingle = 0xf166,
	InfoSolid = 0xf167,
	GroupList = 0xf168,
	CaretBottomRightSolidCenter8 = 0xf169,
	ProgressRingDots = 0xf16a,
	Checkbox14 = 0xf16b,
	CheckboxComposite14 = 0xf16c,
	CheckboxIndeterminateCombo14 = 0xf16d,
	CheckboxIndeterminateCombo = 0xf16e,
	StatusPause7 = 0xf175,
	CharacterAppearance = 0xf17f,
	Lexicon = 0xf180,
	ScreenTime = 0xf182,
	HeadlessDevice = 0xf191,
	NetworkSharing = 0xf193,
	EyeGaze = 0xf19d,
	ToggleLeft = 0xf19e,
	ToggleRight = 0xf19f,
	WindowsInsider = 0xf1ad,
	ChromeSwitch = 0xf1cb,
	ChromeSwitchContast = 0xf1cc,
	StatusCheckmark = 0xf1d8,
	StatusCheckmarkLeft = 0xf1d9,
	KeyboardLeftAligned = 0xf20c,
	KeyboardRightAligned = 0xf20d,
	KeyboardSettings = 0xf210,
	NetworkPhysical = 0xf211,
	IOT = 0xf22c,
	UnknownMirrored = 0xf22e,
	ViewDashboard = 0xf246,
	ExploitProtectionSettings = 0xf259,
	KeyboardNarrow = 0xf260,
	Keyboard12Key = 0xf261,
	KeyboardDock = 0xf26b,
	KeyboardUndock = 0xf26c,
	KeyboardLeftDock = 0xf26d,
	KeyboardRightDock = 0xf26e,
	Ear = 0xf270,
	PointerHand = 0xf271,
	Bullseye = 0xf272,
	DocumentApproval = 0xf28b,
	LocaleLanguage = 0xf2b7,
	PassiveAuthentication = 0xf32a,
	ColorSolid = 0xf354,
	NetworkOffline = 0xf384,
	NetworkConnected = 0xf385,
	NetworkConnectedCheckmark = 0xf386,
	SignOut = 0xf3b1,
	StatusInfo = 0xf3cc,
	StatusInfoLeft = 0xf3cd,
	NearbySharing = 0xf3e2,
	CtrlSpatialLeft = 0xf3e7,
	InteractiveDashboard = 0xf404,
	DeclineCall = 0xf405,
	ClippingTool = 0xf406,
	RectangularClipping = 0xf407,
	FreeFormClipping = 0xf408,
	CopyTo = 0xf413,
	IDBadge = 0xf427,
	DynamicLock = 0xf439,
	PenTips = 0xf45e,
	PenTipsMirrored = 0xf45f,
	HWPJoin = 0xf460,
	HWPInsert = 0xf461,
	HWPStrikeThrough = 0xf462,
	HWPScratchOut = 0xf463,
	HWPSplit = 0xf464,
	HWPNewLine = 0xf465,
	HWPOverwrite = 0xf466,
	MobWifiWarning1 = 0xf473,
	MobWifiWarning2 = 0xf474,
	MobWifiWarning3 = 0xf475,
	MobWifiWarning4 = 0xf476,
	MicLocationCombo = 0xf47f,
	Globe2 = 0xf49a,
	SpecialEffectSize = 0xf4a5,
	GIF = 0xf4a9,
	Sticker2 = 0xf4aa,
	SurfaceHubSelected = 0xf4be,
	HoloLensSelected = 0xf4bf,
	Earbud = 0xf4c0,
	MixVolumes = 0xf4c3,
	Safe = 0xf540,
	LaptopSecure = 0xf552,
	PrintDefault = 0xf56d,
	PageMirrored = 0xf56e,
	LandscapeOrientationMirrored = 0xf56f,
	ColorOff = 0xf570,
	PrintAllPages = 0xf571,
	PrintCustomRange = 0xf572,
	PageMarginPortraitNarrow = 0xf573,
	PageMarginPortraitNormal = 0xf574,
	PageMarginPortraitModerate = 0xf575,
	PageMarginPortraitWide = 0xf576,
	PageMarginLandscapeNarrow = 0xf577,
	PageMarginLandscapeNormal = 0xf578,
	PageMarginLandscapeModerate = 0xf579,
	PageMarginLandscapeWide = 0xf57a,
	CollateLandscape = 0xf57b,
	CollatePortrait = 0xf57c,
	CollatePortraitSeparated = 0xf57d,
	DuplexLandscapeOneSided = 0xf57e,
	DuplexLandscapeOneSidedMirrored = 0xf57f,
	DuplexLandscapeTwoSidedLongEdge = 0xf580,
	DuplexLandscapeTwoSidedLongEdgeMirrored = 0xf581,
	DuplexLandscapeTwoSidedShortEdge = 0xf582,
	DuplexLandscapeTwoSidedShortEdgeMirrored = 0xf583,
	DuplexPortraitOneSided = 0xf584,
	DuplexPortraitOneSidedMirrored = 0xf585,
	DuplexPortraitTwoSidedLongEdge = 0xf586,
	DuplexPortraitTwoSidedLongEdgeMirrored = 0xf587,
	DuplexPortraitTwoSidedShortEdge = 0xf588,
	DuplexPortraitTwoSidedShortEdgeMirrored = 0xf589,
	PPSOneLandscape = 0xf58a,
	PPSTwoLandscape = 0xf58b,
	PPSTwoPortrait = 0xf58c,
	PPSFourLandscape = 0xf58d,
	PPSFourPortrait = 0xf58e,
	HolePunchOff = 0xf58f,
	HolePunchPortraitLeft = 0xf590,
	HolePunchPortraitRight = 0xf591,
	HolePunchPortraitTop = 0xf592,
	HolePunchPortraitBottom = 0xf593,
	HolePunchLandscapeLeft = 0xf594,
	HolePunchLandscapeRight = 0xf595,
	HolePunchLandscapeTop = 0xf596,
	HolePunchLandscapeBottom = 0xf597,
	StaplingOff = 0xf598,
	StaplingPortraitTopLeft = 0xf599,
	StaplingPortraitTopRight = 0xf59a,
	StaplingPortraitBottomRight = 0xf59b,
	StaplingPortraitTwoLeft = 0xf59c,
	StaplingPortraitTwoRight = 0xf59d,
	StaplingPortraitTwoTop = 0xf59e,
	StaplingPortraitTwoBottom = 0xf59f,
	StaplingPortraitBookBinding = 0xf5a0,
	StaplingLandscapeTopLeft = 0xf5a1,
	StaplingLandscapeTopRight = 0xf5a2,
	StaplingLandscapeBottomLeft = 0xf5a3,
	StaplingLandscapeBottomRight = 0xf5a4,
	StaplingLandscapeTwoLeft = 0xf5a5,
	StaplingLandscapeTwoRight = 0xf5a6,
	StaplingLandscapeTwoTop = 0xf5a7,
	StaplingLandscapeTwoBottom = 0xf5a8,
	StaplingLandscapeBookBinding = 0xf5a9,
	StatusDataTransferRoaming = 0xf5aa,
	MobSIMError = 0xf5ab,
	CollateLandscapeSeparated = 0xf5ac,
	PPSOnePortrait = 0xf5ad,
	StaplingPortraitBottomLeft = 0xf5ae,
	PlaySolid = 0xf5b0,
	RepeatOff = 0xf5e7,
	Set = 0xf5ed,
	SetSolid = 0xf5ee,
	FuzzyReading = 0xf5ef,
	VerticalBattery0 = 0xf5f2,
	VerticalBattery1 = 0xf5f3,
	VerticalBattery2 = 0xf5f4,
	VerticalBattery3 = 0xf5f5,
	VerticalBattery4 = 0xf5f6,
	VerticalBattery5 = 0xf5f7,
	VerticalBattery6 = 0xf5f8,
	VerticalBattery7 = 0xf5f9,
	VerticalBattery8 = 0xf5fa,
	VerticalBattery9 = 0xf5fb,
	VerticalBattery10 = 0xf5fc,
	VerticalBatteryCharging0 = 0xf5fd,
	VerticalBatteryCharging1 = 0xf5fe,
	VerticalBatteryCharging2 = 0xf5ff,
	VerticalBatteryCharging3 = 0xf600,
	VerticalBatteryCharging4 = 0xf601,
	VerticalBatteryCharging5 = 0xf602,
	VerticalBatteryCharging6 = 0xf603,
	VerticalBatteryCharging7 = 0xf604,
	VerticalBatteryCharging8 = 0xf605,
	VerticalBatteryCharging9 = 0xf606,
	VerticalBatteryCharging10 = 0xf607,
	VerticalBatteryUnknown = 0xf608,
	SIMError = 0xf618,
	SIMMissing = 0xf619,
	SIMLock = 0xf61a,
	eSIM = 0xf61b,
	eSIMNoProfile = 0xf61c,
	eSIMLocked = 0xf61d,
	eSIMBusy = 0xf61e,
	NoiseCancelation = 0xf61f,
	NoiseCancelationOff = 0xf620,
	MusicSharing = 0xf623,
	MusicSharingOff = 0xf624,
	CircleShapeSolid = 0xf63c,
	WifiCallBars = 0xf657,
	WifiCall0 = 0xf658,
	WifiCall1 = 0xf659,
	WifiCall2 = 0xf65a,
	WifiCall3 = 0xf65b,
	WifiCall4 = 0xf65c,
	CHTLanguageBar = 0xf69e,
	ComposeMode = 0xf6a9,
	ExpressiveInputEntry = 0xf6b8,
	EmojiTabMoreSymbols = 0xf6ba,
	WebSearch = 0xf6fa,
	Kiosk = 0xf712,
	RTTLogo = 0xf714,
	VoiceCall = 0xf715,
	GoToMessage = 0xf716,
	ReturnToCall = 0xf71a,
	StartPresenting = 0xf71c,
	StopPresenting = 0xf71d,
	ProductivityMode = 0xf71e,
	SetHistoryStatus = 0xf738,
	SetHistoryStatus2 = 0xf739,
	Keyboardsettings20 = 0xf73d,
	OneHandedRight20 = 0xf73e,
	OneHandedLeft20 = 0xf73f,
	Split20 = 0xf740,
	Full20 = 0xf741,
	Handwriting20 = 0xf742,
	ChevronLeft20 = 0xf743,
	ChevronLeft32 = 0xf744,
	ChevronRight20 = 0xf745,
	ChevronRight32 = 0xf746,
	Event12 = 0xf763,
	MicOff2 = 0xf781,
	DeliveryOptimization = 0xf785,
	CancelMedium = 0xf78a,
	SearchMedium = 0xf78b,
	AcceptMedium = 0xf78c,
	RevealPasswordMedium = 0xf78d,
	DeleteWord = 0xf7ad,
	DeleteWordFill = 0xf7ae,
	DeleteLines = 0xf7af,
	DeleteLinesFill = 0xf7b0,
	InstertWords = 0xf7b1,
	InstertWordsFill = 0xf7b2,
	JoinWords = 0xf7b3,
	JoinWordsFill = 0xf7b4,
	OverwriteWords = 0xf7b5,
	OverwriteWordsFill = 0xf7b6,
	AddNewLine = 0xf7b7,
	AddNewLineFill = 0xf7b8,
	OverwriteWordsKorean = 0xf7b9,
	OverwriteWordsFillKorean = 0xf7ba,
	EducationIcon = 0xf7bb,
	WindowSnipping = 0xf7ed,
	VideoCapture = 0xf7ee,
	StatusSecured = 0xf809,
	NarratorApp = 0xf83b,
	PowerButtonUpdate = 0xf83d,
	RestartUpdate = 0xf83e,
	UpdateStatusDot = 0xf83f,
	Eject = 0xf847,
	Spelling = 0xf87b,
	SpellingKorean = 0xf87c,
	SpellingSerbian = 0xf87d,
	SpellingChinese = 0xf87e,
	FolderSelect = 0xf89a,
	SmartScreen = 0xf8a5,
	ExploitProtection = 0xf8a6,
	AddBold = 0xf8aa,
	SubtractBold = 0xf8ab,
	BackSolidBold = 0xf8ac,
	ForwardSolidBold = 0xf8ad,
	PauseBold = 0xf8ae,
	ClickSolid = 0xf8af,
	SettingsSolid = 0xf8b0,
	MicrophoneSolidBold = 0xf8b1,
	SpeechSolidBold = 0xf8b2,
	ClickedOutLoudSolidBold = 0xf8b3,
};