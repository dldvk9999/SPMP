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
	#define N_README_TXT	"\"README.txt\" ������ �� �� �����ϴ�!"
	#define README_TXT		"README.txt"
	#define N_REG_TXT		"\"reg.txt\" ������ �� �� �����ϴ�!"
	#define REG_TXT			"reg.txt"
	#define N_RESULT_TXT	"\"result.txt\" ������ �� �� �����ϴ�!"
	#define RESULT_TXT		"result.txt"
	#define N_CMD_BAT		"\"cmd.bat\" ������ �� �� �����ϴ�!"
	#define CMD_BAT			"cmd.bat"
	#define CMD_BAT_NUL		"cmd.bat > nul"
	#define NO_SEC_PROG		"�������α׷��� Ž�� ���� �ʾҽ��ϴ�."
	#define NO_VAC_PROG		"������α׷��� Ž�� ���� �ʾҽ��ϴ�!!!\n������α׷� ��ġ�� �����մϴ�!!"
	#define TITLE			"SPMP_Made By. ParkJG"
	#define CMD_TITLE		"title SPMP"
	#define DET_VAC_N_PROG	" ���� ������α׷��� Ž���Ǿ����ϴ�!!!\n���α׷� �浹 ������ ���� �ϳ��� ����� ���� ���մϴ�!!"
	#define CONFIRM_PROG	" ���� ���α׷��� Ȯ�εǾ����ϴ�."
	#define CMP_PROG		"��ġ ���α׷� ����....\n\n"
	#define CMF_PROG		"���α׷� ���� Ȯ����...\n"
	#define INSP_COMPLETE	"\n\n�˻� �Ϸ�!\n\n\n"
	#define NEW_RESULT_TXT	"fsutil file createnew result.txt 0 > nul"
	#define NEW_CMD_BAT		"fsutil file createnew cmd.bat 0 > nul"
	#define OPT_PROG		"���α׷��� ����ȭ �Ͻðڽ��ϱ�?"
	#define CAN_PROG		"���α׷��� ����մϴ�."
	#define EXTR_PROG_LIST	"���α׷� ��� ������...\n"
	#define REG64			"reg query \"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\" /s /reg:64 > reg.txt"
	#define REG32			"reg query \"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\" /s /reg:32 >> reg.txt"
	#define REG_PRODUCTS	"reg query \"HKCR\\Installer\\Products\" /s >> reg.txt"
	#define DEL_RESULT_TXT	"del result.txt > nul"
	#define DEL_REG_TXT		"del reg.txt > nul"
	#define DEL_CMD_BAT		"del cmd.bat > nul"
	#define FIND_STR		"    DisplayName    REG_SZ    "
	#define CHG_BEFORE		"    DisplayName"
	#define CHG_AFTER		" - ProgramName : "
	#define PROG_LIST		"���α׷� ����Ʈ"
	#define UNINS			"UninstallString    REG_SZ"
	#define QUNINS			"QuietUninstallString    REG_SZ"
	#define CONFIRM_N_PROG	"\n%d���� ���α׷��� Ȯ�� ��.\n"
	#define DETECT_SEC_PROG	"�������α׷� Ž�� : %s\n"
	#define DETECT_VAC_PROG	"������α׷� Ž�� : %s\n"
#endif

int  FindLength(int n);
int	 HowTo();
void Intro();

char list [TMPLEN][MIN] = {
	"Cabsoft CertMailJ",
	"ReportExpress ProPlus Type2",
	"rxCert",
	"Safe Updator for IE9",
	"�ѱ����̹��������հ��� UX",
	"ACE ���� BarcodeWriter ��ġ",
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
	"BCQRE_RD ������� ��ġ���α׷�",
	"BCQRE_RX ������� ��ġ���α׷�",
	"BCURE_RD ������� ��ġ���α׷�",
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
	"DAEGU BANK Real IP �������α׷�",
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
	"KCP ũ�ν�����¡ ActiveX ����",
	"KCP ũ�ν�����¡ HUB ����",
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
	"UniSign-����Ʈ�� ������ �̵�",
	"UniSignWebToolkit",
	"USIM ����Ʈ����",
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
	"����û �������� �����߱�",
	"�뱸���� ���� �α� ������",
	"���������ڻ�",
	"�ο�24 �ο��߱����α׷�",
	"����Ȯ�� CERT-PIN",
	"��ȣ�������� ���� �α� ������",
	"����Ʈ ����� ����",
	"����Ʈ��������",
	"����Ʈ�� ������ �̵� ���α׷�",
	"��������(ReportExpress ProPlus Type2 9X)",
	"��������(ReportExpress ProPlus) ���� ��ġ",
	"���ϻ���(Unisign)�ѱ��������� ����Ʈ�� ������ �̵�",
	"������ �ι� Ŭ���̾�Ʈ",
	"������ �ι� Ŭ���̾�Ʈ ���¹�ŷ",
	"�������� ���� �α� ������",
	"���ڽŰ��ۼ�2005",
	"�����߱� ActiveX",
	"�ѱ������������߿� ���� �߱� ���α׷�",
	"�ѱ����������򰡿� �߱� ���α׷�",
	"Ȩ�ý���������",
	"�޴���������(����)����"
};
char Vlist[TMPLEN][MIN] = {
	"V3 Lite",
	"�˾�",
	"ALYac",
	"���̷���ü�̼�",
	"VirusChaser",
	"���긮��",
	"everyzone",
	"Everyzone",
	"EveryZone",
	"nProtect",
	"�Ͽ츮",
	"Hauri",
	"���ҽ��Ǿ�",
	"Exosphere",
	"Avira",
	"avast",
	"AVG",
	"��Ʈ�����",
	"Bitdefender",
	"Comodo Antivirus",
	"Panda Cloud Antivirus",
	"�ƾ���",
	"Mcafee",
	"McAfee",
	"ī���۽�Ű",
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
	"��Ʈ����� Online Scanner",
	"Bitdefender Online Scanner",
	"F-Secure Free Online Scanner",
	"Malware Zero",
	"��üũ",
	"AppCheck"
};

int main(int argc, char *argv[]) {
	FILE	*fp, *fp2, *fp3;						// ���� ������ ����
	char	buff[MAX], buff2[MAX], buff3[MAX];		// �Է¹��� ���� �迭
	char	cmd[MIN];								// cmd ��ɾ� ������ �迭
	char	uninstall[MAX] = "\0";					// uninstall ���� �ּ� ���� �迭
	char	answer;									// ����ȭ ���� ����� ���� ����
	char 	*pch;									// ���ڿ� ġȯ�Ҷ� �� ����
	int		line	= 0;							// ��Ÿ count �� flag ���� ����
	int		flag	= 0;							// 
	int		flag_A	= 0;							// 
	int		list_n	= 0;							// 
	int 	check	= 0;							// �޽����ڽ� üũ ����
	
	// ���ڰ� üũ
	if (argc == 2) {
		if		(strcmp(argv[1], "-s") == 0) list_n = 1;
		else if	(strcmp(argv[1], "-v") == 0) list_n = 2;
		else	{ HowTo(); return 0; }
	} else if	(argc == 1 || argc >= 3) { HowTo(); return 0; }
	
	// ������Ʈ���� ���� ����Ʈ ����. �̶� system�Լ��� ������ ������� ��� nul�� ����.
	printf(EXTR_PROG_LIST);
	system(CMD_TITLE);
	system(REG64);
	system(REG32);
	system(REG_PRODUCTS);
	fp2	= fopen(REG_TXT, "r");
	// result.txt ������ �� ������ ����. ���������� touch�� ������ ���� ����� 0����Ʈ�� ����.
	system(NEW_RESULT_TXT);
	fp	= fopen(RESULT_TXT,"wt");
	if		(fp2 == NULL) { 
		MessageBox(NULL, N_REG_TXT, TITLE, MB_OK | MB_ICONHAND); 
		fclose(fp); system(DEL_RESULT_TXT); return 0; 
	} 
	else if	(fp  == NULL) { MessageBox(NULL, N_RESULT_TXT, TITLE, MB_OK | MB_ICONHAND); fclose(fp2); system(DEL_REG_TXT); return 0; } 
	else	{
		// result.txt���� ���α׷� �̸��鸸 ũ�Ѹ�
		while(fgets(buff, ONELINE, fp2)){
			if 		(strstr(buff, FIND_STR)) fprintf(fp, buff);
			else	continue;
		}
	}
	fclose(fp);
	
	// ��ġ�� ���α׷� ����Ʈ ���� �ҷ�����
	printf(CMF_PROG);
	fp	= fopen(RESULT_TXT,"r");
	
	// result���� ���
	if		(fp == NULL) { MessageBox(NULL, N_REG_TXT, TITLE, MB_OK | MB_ICONHAND); fclose(fp2); return 0; } 
	else	{
		if (argc != 1) {
			if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "-v") == 0) {
				for (int i = 0; i < 50; i++) printf("="); printf(PROG_LIST);
				for (int i = 0; i < 50; i++) printf("="); printf("\n");
				
				// ���α׷� ��� ����
				while (fgets(buff, MAX, fp)) {
					pch	= strstr(buff, CHG_BEFORE);						// "DisplayName" ��
					strncpy(pch, CHG_AFTER, 17);						// " - ProgramName : "���� �ٲ�
					for (int i = 17; i < MAX; i++) buff[i] = buff[i+10];		// ���� ��ܿ��� �κ�. (ex. "123program" -> "program")
					printf("%s", buff); line++;
				}
				printf(CONFIRM_N_PROG, line);
			}
		}
		
		// list�� result���� ���ؼ� �������α׷� ����
		printf(CMP_PROG);
		for (int i = -1; i < FindLength(list_n); i++) {
			while (fgets(buff, MAX, fp)) {
				
				// -s �ɼǽ� �������α׷� Ž�� �� ����ȭ ���θ� ���.
				if (strcmp(argv[1], "-s") == 0) {
					
					//printf("%s�� %s ��\n",buff, buff2);
					if (strstr(buff, list[i]) != NULL) {
						printf(DETECT_SEC_PROG, list[i]); flag++;
						char pro[MIN]; strcpy(pro, list[i]);				// ���ڿ��� ���� �ű�� ����� �޽����� ����. ���� �������α׷� �̸��� �־����.
						char sentence[MIN] = { OPT_PROG };					// "���α׷��� ����ȭ �Ͻðڽ��ϱ�?" ���ڿ��� ����
						strcat(pro, "\n"); strcat(pro, sentence);			// ����� ���ڿ��� ���Ϳ� "���α׷��� ����ȭ �Ͻðڽ��ϱ�?"�� �߰��� ����.
						check = MessageBox(NULL, pro, TITLE, MB_YESNOCANCEL | MB_ICONQUESTION);
							if		(check == IDCANCEL)	{ 
								MessageBox(NULL, CAN_PROG, TITLE, MB_OK | MB_ICONASTERISK); 
								fclose(fp); fclose(fp2); system(DEL_RESULT_TXT); system(DEL_REG_TXT); return 0;
							}
							else if (check == IDYES)	{
								
								// uninstall �迭 �ʱ�ȭ. �̰� ���ϸ� uninstallString ��� �������� ���� ���α׷����� ���� ��ħ.
								for (int i = 0; i < MAX; i++) uninstall[i] = '\0';
								
								// ����ȭ �ϱ� ���ϸ� ������Ʈ�������� uninstallString(�������α׷� ���)�� ã��
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
								// uninstall ��ο� "" �����ְ� ���ڰ����� �� ���� �ϴ� �κ�
								for	(int i = 0; i < MAX; i++)	{
									if	(uninstall[0] != '\"')	{
										if	(i >= 5 && uninstall[i-4] == '.' && uninstall[i-3] == 'e' && uninstall[i-2] == 'x' && uninstall[i-1] == 'e') {
											memmove(uninstall+i+1, uninstall+i, sizeof(uninstall)-i);
											uninstall[i] = '"'; i++;
										}
										
									// flag_A�� uninstallString �� �տ� "�� �ִ��� ������ ���� Ȯ��. ������ flag_A = 1.
									} else { flag_A = 1; break; }
								}
								
								// cmd.bat�� ������ ��ɾ�� fprintf�� �ְ� ����.
								system(NEW_CMD_BAT);
								fp3 = fopen(CMD_BAT, "w");
								if 		(fp3 == NULL) { printf(N_CMD_BAT); return 0; } 
								else	{
									if	(flag_A != 1) fprintf(fp3, "\"");
									fprintf(fp3, uninstall);
									
									/*  ������Ʈ��, ����, �������α׷� ����� ���� ����.
									fprintf(fp2,"sc config \"%s\" start= demand\nsc stop \"%s\"\n", program, program);
									fprintf(fp2,"reg delete HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v \"%s\" /f\n", program);
									fprintf(fp2,"Taskkill /IM \"%s\" /F\n", program);
									*/
									
									fclose(fp3); flag_A = 0; system(CMD_BAT_NUL);
								}
							} else continue;
					} else continue;
				
				// -v �ɼǽ� ������α׷� Ž��.
				} else if (strcmp(argv[1], "-v") == 0)
					if (strstr(buff, Vlist[i]) != NULL) { printf(DETECT_VAC_PROG, Vlist[i]); flag++; }
			}
			
			// fp Ŀ���� ���� ó������ ����. �׷��� ���α׷����� ���� �� ����.
			rewind(fp);
		}
	}
	fclose(fp);
	if (fp2 != NULL) fclose(fp2);
	printf(INSP_COMPLETE);
	
	if		(strcmp(argv[1], "-s") == 0 && flag == 0) MessageBox(NULL, NO_SEC_PROG, TITLE, MB_OK | MB_ICONASTERISK);
	else if	(strcmp(argv[1], "-v") == 0 && flag == 0) MessageBox(NULL, NO_VAC_PROG, TITLE, MB_OK | MB_ICONEXCLAMATION);
	else if	(strcmp(argv[1], "-v") == 0 && flag >  1) {
		// �������� ������α׷��� Ž���Ǿ����� �޽����ڽ� ����.
		char 		result[MIN] = { DET_VAC_N_PROG };
		char 		Result[MIN];
		itoa		(flag, Result, 10);		// flag���� ���ڷ� �ٲپ Result ���ڿ��� �����ϰ�
		strcat		(Result, result);		// �̾ result ���ڿ��� �̾����.
		MessageBox	(NULL, Result, TITLE, MB_OK | MB_ICONHAND);
	}
	else {
		char		result[MIN] = { CONFIRM_PROG };
		char		Result[MIN];
		itoa		(flag, Result, 10);
		strcat		(Result, result);
		MessageBox	(NULL, Result, TITLE, MB_OK | MB_ICONASTERISK);
	}
	
	// �ʿ���� ���ϵ� ����
	if (uninstall[0] != '\0') system(DEL_CMD_BAT);
	system(DEL_RESULT_TXT); system(DEL_REG_TXT);
	return 0;
}

// �迭�� ���� ã���ִ� �Լ�. �������α׷� ����Ʈ�� ������α׷� ����Ʈ�� ���̰� �⳪ ������ �߰� �� ���� �����Ƿ� �������� ����.
int FindLength(int n){
	if		(n == 1) for (int i = 0; i < TMPLEN; i++) { if(strcmp(list[i], "\0") == 0)	return i; }
	else if	(n == 2) for (int i = 0; i < TMPLEN; i++) { if(strcmp(Vlist[i], "\0") == 0)	return i; }
}

// ������� �ùٸ��� �Է����� �ʾ����� README.txt�� ����ִ� �Լ�.
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

// README.txt ���� ���� ���� ���α׷� ����
void Intro() {
	printf("\n");
	for (int i = 0; i < 99; i++) printf("/"); printf("\n");
	printf("//         ����������������������         ������������������������         ��������������������������������         ����������������������         //\n");
	printf("//         ��  ����������  ��         ��  ������������  ��         ��  ��������  ��������  ��         ��  ����������  ��         //\n");
	printf("//         ��  ��   ��������         ��  ��    ��  ��         ��  ��  ��  ��  ��  ��         ��  ��   ��������         //\n");
	printf("//         ��  ����������������         ��  ������������  ��         ��  ��  ��  ��  ��  ��         ��  ����������������         //\n");
	printf("//         ����������������  ��         ��  ������������������         ��  ��  ��  ��  ��  ��         ����������������  ��         //\n");
	printf("//         ��������   ��  ��         ��  ��                 ��  ��  ��  ��  ��  ��         ��������   ��  ��         //\n");
	printf("//         ��  ����������  ��         ��  ��                 ��  ��  ��  ��  ��  ��         ��  ����������  ��         //\n");
	printf("//         ����������������������         ��������                 ��������  ��������  ��������         ����������������������         //\n");
	for (int i = 0; i < 99; i++) printf("/"); printf("\n\n");
}

