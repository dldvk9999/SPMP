#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#define DEF_STRING_GROUP 1
#define DEF_INTEGER_GROUP 1

#if DEF_INTEGER_GROUP
	#define	TMPLEN 	300
	#define	MAX 	200
	#define	MIN 	100
	#define	ONELINE	140
#endif
#if DEF_STRING_GROUP
	#define N_README_TXT	"\"README.txt\" 파일을 열 수 없습니다!"
	#define README_TXT		"README.txt"
	#define N_REG_TXT		"\"reg.txt\" 파일을 열 수 없습니다!"
	#define REG_TXT			"reg.txt"
	#define N_RESULT_TXT	"\"result.txt\" 파일을 열 수 없습니다!"
	#define RESULT_TXT		"result.txt"
	#define N_CMD_BAT		"\"cmd.bat\" 파일을 열 수 없습니다!"
	#define CMD_BAT			"cmd.bat"
	#define CMD_BAT_NUL		"cmd.bat > nul"
	#define NO_SEC_PROG		"보안프로그램이 탐지 되지 않았습니다."
	#define NO_VAC_PROG		"백신프로그램이 탐지 되지 않았습니다!!!\n백신프로그램 설치를 권장합니다!!"
	#define TITLE			"SPMP_Made By. ParkJG"
	#define CMD_TITLE		"title SPMP"
	#define DET_VAC_N_PROG	" 개의 백신프로그램이 탐지되었습니다!!!\n프로그램 충돌 방지를 위해 하나만 사용할 것을 권합니다!!"
	#define CONFIRM_PROG	" 개의 프로그램이 확인되었습니다."
	#define CMP_PROG		"설치 프로그램 비교중....\n\n"
	#define CMF_PROG		"프로그램 정보 확인중...\n"
	#define INSP_COMPLETE	"\n\n검사 완료!\n\n\n"
	#define NEW_RESULT_TXT	"fsutil file createnew result.txt 0 > nul"
	#define NEW_CMD_BAT		"fsutil file createnew cmd.bat 0 > nul"
	#define OPT_PROG		"프로그램을 최적화 하시겠습니까?"
	#define CAN_PROG		"프로그램을 취소합니다."
	#define EXTR_PROG_LIST	"프로그램 목록 추출중...\n"
	#define REG64			"reg query \"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\" /s /reg:64 > reg.txt"
	#define REG32			"reg query \"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\" /s /reg:32 >> reg.txt"
	#define REG_PRODUCTS	"reg query \"HKCR\\Installer\\Products\" /s >> reg.txt"
	#define DEL_RESULT_TXT	"del result.txt > nul"
	#define DEL_REG_TXT		"del reg.txt > nul"
	#define DEL_CMD_BAT		"del cmd.bat > nul"
	#define FIND_STR		"    DisplayName    REG_SZ    "
	#define CHG_BEFORE		"    DisplayName"
	#define CHG_AFTER		" - ProgramName : "
	#define PROG_LIST		"프로그램 리스트"
	#define UNINS			"UninstallString    REG_SZ"
	#define QUNINS			"QuietUninstallString    REG_SZ"
	#define CONFIRM_N_PROG	"\n%d개의 프로그램이 확인 됨.\n"
	#define DETECT_SEC_PROG	"보안프로그램 탐지 : %s\n"
	#define DETECT_VAC_PROG	"백신프로그램 탐지 : %s\n"
#endif

int  FindLength(int n);
int	 HowTo();
void Intro();

char list [TMPLEN][MIN] = {
	"Cabsoft CertMailJ",
	"ReportExpress ProPlus Type2",
	"rxCert",
	"Safe Updator for IE9",
	"한국사이버결제통합결제 UX",
	"ACE 생명 BarcodeWriter 설치",
	"AEGIS AGSWallet Plugin",
	"AEGIS AGSWallet Plugin Vista",
	"AGSPay V1.0 for Win32",
	"AGSWalletforVista",
	"AhnLab MyFirewall",
	"AhnLab MyKeyDefense",
	"AhnLab Online Security",
	"AhnLab Safe Transaction",
	"AnySign4PC",
	"AxSignGATE",
	"BankPayEFT",
	"BCQRE_RD 연동모듈 설치프로그램",
	"BCQRE_RX 연동모듈 설치프로그램",
	"BCURE_RD 연동모듈 설치프로그램",
	"Bizcomponent for SHINHAN BANK",
	"ClientKeeper Key pro for Application",
	"ClientKeeper KeyPro with E2E for 32bit",
	"Conkeeper",
	"ContentSAFER",
	"Crosscert",
	"CROSSCERT UniCRSV3",
	"CrossCertWeb",
	"Crownix Report 6.0 OCX Viewer",
	"Crownix Report 6.0 Plugin Viewer",
	"D'Amo WebCrypto",
	"DAEGU BANK Real IP 보안프로그램",
	"Delfino G3 (x86)",
	"Delfino-x86",
	"DRDesigner WebViewer",
	"EasyKeytec",
	"EasyPayPlugin",
	"egiroFileDown ActiveX Control",
	"eISP",
	"eiSP",
	"EPKI Center",
	"EPKI Center EPKIWCtl",
	"EPKI Center EPKIWCtl Control",
	"EPKIWCtl Control",
	"EPOSTBANK Roaming",
	"EzPlatformSetting",
	"FWGridClient (X86)",
	"GPKISecureWebX",
	"GPKISecureWebXPlugin",
	"HrdKorea PrintManager",
	"HSRoamingKeyCert",
	"I-Defense Control",
	"IBSheet",
	"IBSheetPro",
	"INICIS61",
	"iniLINE",
	"iniLINE CrossEX Service",
	"iniLINE CrossWarpEX",
	"INISAFE Cert Client",
	"INISAFE CrossWeb Ex",
	"INISAFE Mail",
	"INISAFE MoaSign EX",
	"INISAFE MoaSign S",
	"INISAFE SandBox",
	"INISAFE SFilter",
	"INISAFE SmartManager",
	"INISAFE SmartManagerEx",
	"INISAFE Web",
	"INISAFE Web EX Client",
	"INISAFE Web",
	"INITECH",
	"Interezen",
	"IPInside Agent",
	"IPInside LWS Agent",
	"IPinside Non-p Agent",
	"IPinside_LWS",
	"IRSTInstallPackage",
	"ISiCastAgent",
	"ISign+ Web Crypto",
	"ISP Life",
	"IssacWebProCms",
	"IssacWebProCMS",
	"IssacWebProCMS_DE",
	"IssacWebProCMS_LG_UPLUS",
	"IssacWebSE",
	"IWKeyRelayClient",
	"Juniper Networks Network Connect",
	"Juniper Networks, Inc. Setup Client",
	"Juniper Networks, Inc. Setup Client 64-bit Activex Control",
	"JX-CEAL G2 Client version",
	"JX-Mail ActiveX",
	"JX-Mail EnterPrise plugin",
	"K-Defense8 Control",
	"K-Defense R6",
	"K-Defense R6 : Anti-Keylogger",
	"KcLep",
	"KCP CrossBrowsing Version",
	"KCP 크로스브라우징 ActiveX 버전",
	"KCP 크로스브라우징 HUB 버전",
	"KCPPayUX",
	"KeySharp CertRelay",
	"KeySharp CertRelay(T)",
	"KeySharp CertRelay(W)",
	"KeySharpBiz",
	"keysharpbiz (x86)",
	"KeySharpBiz-x86",
	"keysharpnxbiz (x86)",
	"KICA SecuXML Toolkit v7.0 for Korea Customs Service",
	"KicaSafe2",
	"Kings Online Security",
	"KJBank",
	"KOBUS",
	"KoreaUniv PrintManager",
	"KSignHIRA",
	"MaDownloadRD",
	"MaDownloadRD_SI4N",
	"MAePageSaferHometaxActiveX",
	"MAePageSaferSTDActiveX",
	"MaFtImagePrinter",
	"MagicLine4NP",
	"MagicLine4NPIZ",
	"MagicLineMBX",
	"MagicPass Client",
	"MAGICXML",
	"MAOnMultiWebSafer_STD",
	"MaPrinterLister",
	"MaPrintModule_BCCard",
	"MaPrintModule_PPS",
	"MarkAny e-PageSAFER",
	"MarkAny EPSBroker",
	"MarkAny Inc. e-PageSafer NoAX",
	"MarkAny Inc. e-Pagesafer",
	"MarkAny Plugin for Multi Browser",
	"MarkAny WebDRM NoAX",
	"MarkAny WebSafer Plugin for Multi Browser(KERIS)",
	"MaSecureClient",
	"MaWebSAFER_KERIS",
	"MaWebSAFER_NPS",
	"MaWebSafer_SCx86",
	"MaWebSAFER_STDEP",
	"MAWS09_SCOURT",
	"MAWS_CUBANK",
	"MAWS_HANA",
	"MAWS_HKLifeUMS",
	"MAWS_KBSTAR_MAIL",
	"MAWS_KYWA",
	"MAWS_LHRex2",
	"MAWS_MMAA",
	"MAWS_MMASJ",
	"MAWS_NARA",
	"MAWS_NewKECA",
	"MAWS_NPS",
	"MAWS_NTSRex",
	"MAWS_PhiMW",
	"MAWS_POLICEOz",
	"MAWS_POLICEPortal",
	"MAWS_PPS",
	"MAWS_SAFE",
	"MAWS_SCIENCE",
	"MAWS_SNU",
	"MAWS_WORK",
	"MediaShell",
	"NicePay NP Plugin",
	"npAllatPayRE",
	"npEfdsWCtrl",
	"NPKI",
	"npPCStatus",
	"nProtect GameGuard Personal",
	"nProtect KeyCrypt",
	"nProtect Netizen5",
	"nProtect Netizen SVC",
	"nProtect Netizen",
	"nProtect Online Security",
	"nProtect OnlineScan",
	"nProtect X-Guard",
	"NTSMagicLine",
	"NTSMagicLineMBX",
	"OZ Viewer - kpicviewer",
	"OZ Viewer - nts_hometax_win8",
	"OZ Viewer - scourt_hojuck",
	"Papyrus for MSHometax Setup",
	"Papyrus-Plugin",
	"Papyrus-PlugIn-ntas",
	"PapyrusKats",
	"ProWorksGrid",
	"PunkBuster Services",
	"RaonSecure",
	"rdbarcode10",
	"REDBC NX_PRNMAN",
	"RedBC TrustPKI KCUE",
	"Report Designer",
	"Reportshop5.1C",
	"REPORTX",
	"Rexpert30 Viewer",
	"SamSungCard SafeOn Setup",
	"SCORE DTI for OpenWeb",
	"SCORE PKI for OpenWeb",
	"SecuKit NX",
	"SecuKit NXS",
	"Secure Holic PNP Plugin",
	"Secure KeyStroke",
	"SECUREWORKS TRUIN Client",
	"SECUREWORKS TruinSafe",
	"SGA TrustUD",
	"SGA TrustWeb Control",
	"SGSecuTax Client",
	"SideSync",
	"SignGATE EWS",
	"SignKorea Certificate Toolkit",
	"SignKorea NA Certification Toolkit",
	"SoftCamp Secure KeyStroke",
	"Softcamp Secure KeyStroke Extension",
	"SoftCamp Secure KeyStroke",
	"SoftCamp WebClientSecurity",
	"SoftForum",
	"taxFileCryptoX",
	"TouchEn firewall",
	"TouchEn firewall32",
	"TouchEn Key for Application",
	"TouchEn key with E2E for 32bit",
	"TouchEn nxFirewall32",
	"TouchEn nxKey with E2E for 32bit",
	"TouchEn nxWeb",
	"TouchEn safe",
	"TouchEn web (web Page Protector)",
	"TradeSign",
	"TrustNET Npruntime Plugin MetLife",
	"TrustNET Web Toolkit for SecuiSFNCOM",
	"TrustNet_Cert_WEBCLIENT",
	"TrustPKI EnterpriseNon-ActiveX Client",
	"TrustPKI KCUE",
	"TrustPKI KCUEN on-ActiveX Client",
	"TSToolkit",
	"TSXMLToolkit",
	"UniSign-스마트폰 인증서 이동",
	"UniSignWebToolkit",
	"USIM 스마트인증",
	"Verain(Wizvera Mozilia Plugin)",
	"VeraPort",
	"Veraport",
	"VestCert",
	"VISA Shared Components",
	"VISA.NET Shared Components",
	"WebCube",
	"WebPri2.0 Cmpact Module",
	"WiseGrid ActiveX",
	"WiseGrid ActiveX (Unicode)",
	"WIZVERA Process Manager",
	"x-INIpay Plugin",
	"Xecure Mobile Relay",
	"XecureExpress",
	"XecureExpressII",
	"XecureExtension Control",
	"XecureHSM",
	"XecureOutMail",
	"XecureWeb Control",
	"XecureWeb UnifiedPlugin",
	"XecureWeb-Multi FCMS",
	"yessign7 ActiveX Control",
	"국세청 연말정산 증명서발급",
	"대구은행 보안 로그 수집기",
	"대한적십자사",
	"민원24 민원발급프로그램",
	"본인확인 CERT-PIN",
	"상호저축은행 보안 로그 수집기",
	"스마트 모바일 사인",
	"스마트공인인증",
	"스마트폰 인증서 이동 프로그램",
	"웹리포팅(ReportExpress ProPlus Type2 9X)",
	"웹리포팅(ReportExpress ProPlus) 수동 설치",
	"유니사인(Unisign)한국전자인증 스마트폰 인증서 이동",
	"인증서 로밍 클라이언트",
	"인증서 로밍 클라이언트 오픈뱅킹",
	"저축은행 보안 로그 수집기",
	"전자신고작성2005",
	"증명서발급 ActiveX",
	"한국관세무역개발원 증명서 발급 프로그램",
	"한국교육과정평가원 발급 프로그램",
	"홈택스버전관리",
	"휴대폰인증서(보관)서비스"
};
char Vlist[TMPLEN][MIN] = {
	"V3 Lite",
	"알약",
	"ALYac",
	"바이러스체이서",
	"VirusChaser",
	"에브리존",
	"everyzone",
	"Everyzone",
	"EveryZone",
	"nProtect",
	"하우리",
	"Hauri",
	"엑소스피어",
	"Exosphere",
	"Avira",
	"avast",
	"AVG",
	"비트디펜더",
	"Bitdefender",
	"Comodo Antivirus",
	"Panda Cloud Antivirus",
	"맥아피",
	"Mcafee",
	"McAfee",
	"카스퍼스키",
	"Kaspersky",
	"digital defender",
	"preventon",
	"ZoneAlarm Free Antivirus",
	"Ad-Aware Free Antivirus",
	"Sophos Home",
	"Comodo cleaning essentials",
	"ClamAV",
	"Trendmicro House call",
	"ESET(nod32)",
	"dr.web",
	"Sophos Virus Removal Tool",
	"Kaspersky Virus Removal Tool",
	"비트디펜더 Online Scanner",
	"Bitdefender Online Scanner",
	"F-Secure Free Online Scanner",
	"Malware Zero",
	"앱체크",
	"AppCheck"
};

int main(int argc, char *argv[]) {
	FILE	*fp, *fp2, *fp3;						// 파일 포인터 변수
	char	buff[MAX], buff2[MAX], buff3[MAX];		// 입력받을 버퍼 배열
	char	cmd[MIN];								// cmd 명령어 저장할 배열
	char	uninstall[MAX] = "\0";					// uninstall 파일 주소 받을 배열
	char	answer;									// 최적화 여부 물어볼때 받을 문자
	char 	*pch;									// 문자열 치환할때 쓸 변수
	int		line	= 0;							// 기타 count 및 flag 관련 변수
	int		flag	= 0;							// 
	int		flag_A	= 0;							// 
	int		list_n	= 0;							// 
	int 	check	= 0;							// 메시지박스 체크 변수
	
	// 인자값 체크
	if (argc == 2) {
		if		(strcmp(argv[1], "-s") == 0) list_n = 1;
		else if	(strcmp(argv[1], "-v") == 0) list_n = 2;
		else	{ HowTo(); return 0; }
	} else if	(argc == 1 || argc >= 3) { HowTo(); return 0; }
	
	// 레지스트리값 토대로 리스트 추출. 이때 system함수로 나오는 결과값은 모두 nul로 보냄.
	printf(EXTR_PROG_LIST);
	system(CMD_TITLE);
	system(REG64);
	system(REG32);
	system(REG_PRODUCTS);
	fp2	= fopen(REG_TXT, "r");
	// result.txt 파일을 빈 값으로 만듬. 리눅스에서 touch와 같지만 파일 존재시 0바이트로 만듬.
	system(NEW_RESULT_TXT);
	fp	= fopen(RESULT_TXT,"wt");
	if		(fp2 == NULL) { 
		MessageBox(NULL, N_REG_TXT, TITLE, MB_OK | MB_ICONHAND); 
		fclose(fp); system(DEL_RESULT_TXT); return 0; 
	} 
	else if	(fp  == NULL) { MessageBox(NULL, N_RESULT_TXT, TITLE, MB_OK | MB_ICONHAND); fclose(fp2); system(DEL_REG_TXT); return 0; } 
	else	{
		// result.txt에다 프로그램 이름들만 크롤링
		while(fgets(buff, ONELINE, fp2)){
			if 		(strstr(buff, FIND_STR)) fprintf(fp, buff);
			else	continue;
		}
	}
	fclose(fp);
	
	// 설치된 프로그램 리스트 파일 불러오기
	printf(CMF_PROG);
	fp	= fopen(RESULT_TXT,"r");
	
	// result파일 출력
	if		(fp == NULL) { MessageBox(NULL, N_REG_TXT, TITLE, MB_OK | MB_ICONHAND); fclose(fp2); return 0; } 
	else	{
		if (argc != 1) {
			if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "-v") == 0) {
				for (int i = 0; i < 50; i++) printf("="); printf(PROG_LIST);
				for (int i = 0; i < 50; i++) printf("="); printf("\n");
				
				// 프로그램 목록 띄우기
				while (fgets(buff, MAX, fp)) {
					pch	= strstr(buff, CHG_BEFORE);						// "DisplayName" 을
					strncpy(pch, CHG_AFTER, 17);						// " - ProgramName : "으로 바꿈
					for (int i = 17; i < MAX; i++) buff[i] = buff[i+10];		// 글자 당겨오는 부분. (ex. "123program" -> "program")
					printf("%s", buff); line++;
				}
				printf(CONFIRM_N_PROG, line);
			}
		}
		
		// list와 result파일 비교해서 보안프로그램 추출
		printf(CMP_PROG);
		for (int i = -1; i < FindLength(list_n); i++) {
			while (fgets(buff, MAX, fp)) {
				
				// -s 옵션시 보안프로그램 탐지 및 최적화 여부를 물어봄.
				if (strcmp(argv[1], "-s") == 0) {
					
					//printf("%s와 %s 비교\n",buff, buff2);
					if (strstr(buff, list[i]) != NULL) {
						printf(DETECT_SEC_PROG, list[i]); flag++;
						char pro[MIN]; strcpy(pro, list[i]);				// 문자열을 만들어서 거기다 출력할 메시지를 만듬. 먼저 보안프로그램 이름을 넣어놓음.
						char sentence[MIN] = { OPT_PROG };					// "프로그램을 최적화 하시겠습니까?" 문자열을 만듬
						strcat(pro, "\n"); strcat(pro, sentence);			// 출력할 문자열에 엔터와 "프로그램을 최적화 하시겠습니까?"를 추가로 넣음.
						check = MessageBox(NULL, pro, TITLE, MB_YESNOCANCEL | MB_ICONQUESTION);
							if		(check == IDCANCEL)	{ 
								MessageBox(NULL, CAN_PROG, TITLE, MB_OK | MB_ICONASTERISK); 
								fclose(fp); fclose(fp2); system(DEL_RESULT_TXT); system(DEL_REG_TXT); return 0;
							}
							else if (check == IDYES)	{
								
								// uninstall 배열 초기화. 이거 안하면 uninstallString 긴거 나왔을때 다음 프로그램까지 영향 미침.
								for (int i = 0; i < MAX; i++) uninstall[i] = '\0';
								
								// 최적화 하길 원하면 레지스트리값에서 uninstallString(삭제프로그램 경로)을 찾음
								rewind(fp2);
								while 	(fgets(buff2, ONELINE, fp2)) {
									if	(strstr(buff2, list[i]) != NULL) {
										while	(fgets(buff3, ONELINE, fp2)) {
											if	(strstr(buff3, UNINS) != NULL && strstr(buff3, QUNINS) == NULL) {
												for(int i = 0; buff3[i+33] != 0; i++) uninstall[i] = buff3[i+33]; break;
											}
											else if (strstr(buff3, QUNINS) != NULL) {
												for(int i = 0; buff3[i+38] != 0; i++) uninstall[i] = buff3[i+38]; break;
											}
										}
									}
								}
								// uninstall 경로에 "" 맞춰주고 인자값까지 잘 들어가게 하는 부분
								for	(int i = 0; i < MAX; i++)	{
									if	(uninstall[0] != '\"')	{
										if	(i >= 5 && uninstall[i-4] == '.' && uninstall[i-3] == 'e' && uninstall[i-2] == 'x' && uninstall[i-1] == 'e') {
											memmove(uninstall+i+1, uninstall+i, sizeof(uninstall)-i);
											uninstall[i] = '"'; i++;
										}
										
									// flag_A로 uninstallString 맨 앞에 "가 있는지 없는지 여부 확인. 있으면 flag_A = 1.
									} else { flag_A = 1; break; }
								}
								
								// cmd.bat에 삭제할 명령어들 fprintf로 넣고 실행.
								system(NEW_CMD_BAT);
								fp3 = fopen(CMD_BAT, "w");
								if 		(fp3 == NULL) { printf(N_CMD_BAT); return 0; } 
								else	{
									if	(flag_A != 1) fprintf(fp3, "\"");
									fprintf(fp3, uninstall);
									
									/*  레지스트리, 서비스, 시작프로그램 제어는 개발 예정.
									fprintf(fp2,"sc config \"%s\" start= demand\nsc stop \"%s\"\n", program, program);
									fprintf(fp2,"reg delete HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v \"%s\" /f\n", program);
									fprintf(fp2,"Taskkill /IM \"%s\" /F\n", program);
									*/
									
									fclose(fp3); flag_A = 0; system(CMD_BAT_NUL);
								}
							} else continue;
					} else continue;
				
				// -v 옵션시 백신프로그램 탐지.
				} else if (strcmp(argv[1], "-v") == 0)
					if (strstr(buff, Vlist[i]) != NULL) { printf(DETECT_VAC_PROG, Vlist[i]); flag++; }
			}
			
			// fp 커서를 제일 처음으로 돌림. 그래야 프로그램끼리 비교할 수 있음.
			rewind(fp);
		}
	}
	fclose(fp);
	if (fp2 != NULL) fclose(fp2);
	printf(INSP_COMPLETE);
	
	if		(strcmp(argv[1], "-s") == 0 && flag == 0) MessageBox(NULL, NO_SEC_PROG, TITLE, MB_OK | MB_ICONASTERISK);
	else if	(strcmp(argv[1], "-v") == 0 && flag == 0) MessageBox(NULL, NO_VAC_PROG, TITLE, MB_OK | MB_ICONEXCLAMATION);
	else if	(strcmp(argv[1], "-v") == 0 && flag >  1) {
		// 여러개의 백신프로그램이 탐지되었을때 메시지박스 세팅.
		char 		result[MIN] = { DET_VAC_N_PROG };
		char 		Result[MIN];
		itoa		(flag, Result, 10);		// flag값을 문자로 바꾸어서 Result 문자열에 저장하고
		strcat		(Result, result);		// 이어서 result 문자열을 이어붙임.
		MessageBox	(NULL, Result, TITLE, MB_OK | MB_ICONHAND);
	}
	else {
		char		result[MIN] = { CONFIRM_PROG };
		char		Result[MIN];
		itoa		(flag, Result, 10);
		strcat		(Result, result);
		MessageBox	(NULL, Result, TITLE, MB_OK | MB_ICONASTERISK);
	}
	
	// 필요없는 파일들 삭제
	if (uninstall[0] != '\0') system(DEL_CMD_BAT);
	system(DEL_RESULT_TXT); system(DEL_REG_TXT);
	return 0;
}

// 배열의 길이 찾아주는 함수. 보안프로그램 리스트나 백신프로그램 리스트는 길이가 기나 내용을 추가 할 수도 있으므로 동적으로 구현.
int FindLength(int n){
	if		(n == 1) for (int i = 0; i < TMPLEN; i++) { if(strcmp(list[i], "\0") == 0)	return i; }
	else if	(n == 2) for (int i = 0; i < TMPLEN; i++) { if(strcmp(Vlist[i], "\0") == 0)	return i; }
}

// 사용법대로 올바르게 입력하지 않았을때 README.txt를 띄워주는 함수.
int HowTo() {
	FILE *fp;
	char buff[MAX];
	fp = fopen(README_TXT,"r");
	if (fp == NULL) {
		Intro();
		printf(N_README_TXT);
		fclose(fp); return 0;
	}
	Intro();
	while(fgets(buff, ONELINE, fp)) {
		if	 (strcmp(buff, "\0") == 0) break;
		else printf("%s", buff);
	}
	fclose(fp); return 0;
}

// README.txt 띄우기 전에 띄우는 프로그램 네임
void Intro() {
	printf("\n");
	for (int i = 0; i < 99; i++) printf("/"); printf("\n");
	printf("//         ┌─────────┐         ┌──────────┐         ┌──────────────┐         ┌─────────┐         //\n");
	printf("//         │  ┌───┐  │         │  ┌────┐  │         │  ┌──┐  ┌──┐  │         │  ┌───┐  │         //\n");
	printf("//         │  │   └──┘         │  │    │  │         │  │  │  │  │  │         │  │   └──┘         //\n");
	printf("//         │  └──────┐         │  └────┘  │         │  │  │  │  │  │         │  └──────┐         //\n");
	printf("//         └──────┐  │         │  ┌───────┘         │  │  │  │  │  │         └──────┐  │         //\n");
	printf("//         ┌──┐   │  │         │  │                 │  │  │  │  │  │         ┌──┐   │  │         //\n");
	printf("//         │  └───┘  │         │  │                 │  │  │  │  │  │         │  └───┘  │         //\n");
	printf("//         └─────────┘         └──┘                 └──┘  └──┘  └──┘         └─────────┘         //\n");
	for (int i = 0; i < 99; i++) printf("/"); printf("\n\n");
}

